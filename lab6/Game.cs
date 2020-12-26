using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lab6
{
    public partial class Game : Form
    {
        private int _widthAndHeight;
        public int WidthAndHeight
        {
            get { return _widthAndHeight; }
            set { _widthAndHeight = value; }
        }

        private int _labelHeight;
        public int LabelHeight
        {
            get { return _labelHeight; }
            set { _labelHeight = value; }
        }

        private int _sizeOfSides;
        public int SizeOfSides
        {
            get { return _sizeOfSides; }
            set { _sizeOfSides = value; }
        }

        private Field _field;
        public Field Field
        {
            get { return _field; }
            set { _field = value; }
        }
        private Fruit _fruit;
        public Fruit Fruit
        {
            get { return _fruit; }
            set { _fruit = value; }
        }

        private Direction _direction;
        public Direction Direction
        {
            get { return _direction; }
            set { _direction = value; }
        }

        private Snake _snake;
        public Snake Snake
        {
            get { return _snake; }
            set { _snake = value; }
        }

        private int _score; 
        public int Score
        {
            get { return _score; }
            set { _score = value; }
        }
        private Label _scoreLabel;

        public Label ScoreLabel
        {
            get { return _scoreLabel; }
            set { _scoreLabel = value; }
        }
        private Timer _timer;
        public Game()
        {
            InitializeComponent();

            _timer = new Timer();
            _timer.Tick += new EventHandler(_Update);
            _timer.Interval = 200;
            _timer.Start();

            this.KeyDown += new KeyEventHandler(_ChangeDirection);
        }

        private void _Update(object sender, EventArgs eventsArgs)
        {
            try
            {
                _snake.Move(_direction);
                _EatFruit();
            }
            catch (GameOverException e)
            {
                _timer.Stop();
                MessageBox.Show(e.Message);
                Application.Exit();
            }
        }

        private void _EatFruit()
        {
            if (_snake[0].Location == _fruit.Location)
            {
                this.Controls.Remove(_fruit);
                _fruit = new Fruit(_widthAndHeight, _sizeOfSides);
                this.Controls.Add(_fruit);

                _scoreLabel.Text = "Score: " + ++_score;
                _snake.AddNewTail(_direction);
                this.Controls.Add(_snake[_score]);
            }
        }

        private void _ChangeDirection(object sender, KeyEventArgs e)
        {
            switch (e.KeyCode.ToString())
            {
                case "Right":
                    _direction = Direction.RIGHT;
                    break;
                case "Left":
                    _direction = Direction.LEFT;
                    break;
                case "Up":
                    _direction = Direction.UP;
                    break;
                case "Down":
                    _direction = Direction.DOWN;
                    break;
            }
        }
    }
}
