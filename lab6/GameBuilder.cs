using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using System.Windows.Forms;
namespace lab6
{
    public class GameBuilder
    {
        private Game _game;
        public Game Game
        {
            get
            {
                return _game;
            }
        }

        public GameBuilder()
        {
            _game = new Game();
        }

        public void SetWigthAndHeight(int widthAndHeight = 600)
        {
            _game.WidthAndHeight = widthAndHeight;
        }

        public void SetLabelHeight(int labelHeight = 50)
        {
            _game.LabelHeight = labelHeight;
        }

        public void SetSizeOfSizes(int sizeOfSizes = 30)
        {
            _game.SizeOfSides = sizeOfSizes;
        }

        public void SetWindowParameters()
        {
            _game.Text = "Snake";
            _game.Width = _game.WidthAndHeight + _game.WidthAndHeight / _game.SizeOfSides;
            _game.Height = _game.Width + _game.LabelHeight;
        }

        public void SetField()
        {
            _game.Field = new Field(_game.WidthAndHeight, _game.SizeOfSides);
        }

        public void SetDirection()
        {
            _game.Direction = Direction.LEFT;
        }

        public void SetSnake()
        {
            _game.Snake = new Snake(_game.WidthAndHeight, _game.SizeOfSides);
        }

        public void SetFruit()
        {
            _game.Fruit = new Fruit(_game.WidthAndHeight, _game.SizeOfSides);
        }

        public void SetScore()
        {
            _game.Score = 0;
        }

        public void SetScoreLabel()
        {
            _game.ScoreLabel = new Label
            {
                Text = "Score: 0",
                Location = new Point(_game.WidthAndHeight / 2, _game.WidthAndHeight + 1),
                Size = new Size(_game.WidthAndHeight, _game.LabelHeight)
            };
        }

        public void AddItemsToControls()
        {
            _game.Controls.Add(_game.Fruit);

            _game.Controls.Add(_game.Snake[0]);

            _game.Controls.Add(_game.ScoreLabel);

            foreach (PictureBox p in _game.Field.GetField)
            {
                _game.Controls.Add(p);
            }
        }
    }
}
