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
        private int _widthAndHeight = 600;
        private int _labelHeight = 50;
        private int _sizeOfSides = 30;
        private Fruit _fruit;
        private Direction _direction;
        private Snake _snake;
        private int _score;
        private Label _scoreLabel;
        private Timer timer;
        public Game()
        {
            InitializeComponent();

            this.Text = "Snake";
            this.Width = _widthAndHeight + _widthAndHeight/_sizeOfSides;
            this.Height = this.Width + _labelHeight;

            FieldGenerator generator = new FieldGenerator(_widthAndHeight, _sizeOfSides);
            List<PictureBox> field = generator.GenerateField();

            foreach (PictureBox pic in field)
            {
                this.Controls.Add(pic);
            }

            _fruit = new Fruit(_widthAndHeight, _sizeOfSides);
            this.Controls.Add(_fruit);

            _snake = new Snake(_widthAndHeight, _sizeOfSides);
            this.Controls.Add(_snake[0]);

            _score = 0;

            _scoreLabel = new Label
            {
                Text = "Score: 0",
                Location = new Point(_widthAndHeight/2, _widthAndHeight),
                Size = new Size(_widthAndHeight, _labelHeight)
            };
            this.Controls.Add(_scoreLabel);

            DialogResult result = MessageBox.Show(this, 
                "Do you want to play on heavy difficulty?",
                "Choose level", MessageBoxButtons.YesNo,
            MessageBoxIcon.Question, MessageBoxDefaultButton.Button1,
            MessageBoxOptions.RightAlign);

            timer = new Timer();
            timer.Tick += new EventHandler(_Update);
            if (result == DialogResult.Yes)
            {
                timer.Interval = 50;
            }
            else
            {
                timer.Interval = 200;
            }
            timer.Start();

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
                timer.Stop();
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
