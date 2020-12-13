using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using System.Windows.Forms;

namespace lab6
{
    class Snake
    {
        private int _widthAndHeight;
        private int _sizeOfSides;
        private int _size;
        private List<PictureBox> _snake;

        public PictureBox this[int index]
        {
            get
            {
                return _snake[index];
            }

            set
            {
                _snake[index] = value;
            }
        }

        public int Size
        {
            get
            {
                return _size;
            }
        }

        public Snake(int widthAndHeight, int sizeOfSides)
        {
            _widthAndHeight = widthAndHeight;
            _sizeOfSides = sizeOfSides;

            _snake = new List<PictureBox>();
            _snake.Add(new PictureBox());
            _snake[0].Location = new Point(_widthAndHeight / 2 + 1, _widthAndHeight / 2 + 1);
            _snake[0].Size = new Size(_sizeOfSides - 1, _sizeOfSides - 1);
            _snake[0].BackColor = Color.Red;

            _size = _snake.Count();
        }

        public void AddNewTail(Direction direction)
        {
            _snake.Add(new PictureBox());
            _snake[_size].Location = new Point(_snake[_size - 1].Location.X, _snake[_size - 1].Location.Y);
            switch (direction)
            {
                case Direction.UP:
                    _snake[_size].Location = new Point(_snake[_size].Location.X, _snake[_size].Location.Y - _sizeOfSides);
                    break;
                case Direction.DOWN:
                    _snake[_size].Location = new Point(_snake[_size].Location.X, _snake[_size].Location.Y + _sizeOfSides);
                    break;
                case Direction.LEFT:
                    _snake[_size].Location = new Point(_snake[_size].Location.X - _sizeOfSides, _snake[_size].Location.Y);
                    break;
                case Direction.RIGHT:
                    _snake[_size].Location = new Point(_snake[_size].Location.X + _sizeOfSides, _snake[_size].Location.Y);
                    break;
            }
            _snake[_size].Size = new Size(_sizeOfSides - 1, _sizeOfSides - 1);
            _snake[_size].BackColor = Color.Red;

            _size++;
        }

        private void _CheckBorders()
        {
            if (_snake[0].Location.X < 1)
            {
                _snake[0].Location = new Point(_widthAndHeight - _sizeOfSides + 1, _snake[0].Location.Y);
            }

            if (_snake[0].Location.Y < 1)
            {
                _snake[0].Location = new Point(_snake[0].Location.X, _widthAndHeight - _sizeOfSides + 1);
            }

            if (_snake[0].Location.Y > _widthAndHeight)
            {
                _snake[0].Location = new Point(_snake[0].Location.X, 1);
            }

            if (_snake[0].Location.X > _widthAndHeight)
            {
                _snake[0].Location = new Point(1, _snake[0].Location.Y);
            }

        }

        private void _CheckTailDamage()
        {
            for (int i = 1; i < _size; ++i)
            {
                if (_snake[i].Location == _snake[0].Location)
                {
                    throw new GameOverException("Game over!");
                }
            }
        }
        public void Move(Direction direction)
        {
            for (int i = _size - 1; i > 0; --i)
            {
                _snake[i].Location = _snake[i - 1].Location;
            }

            switch (direction)
            {
                case Direction.UP:
                    _snake[0].Location = new Point(_snake[0].Location.X, _snake[0].Location.Y - _sizeOfSides);
                    break;
                case Direction.DOWN:
                    _snake[0].Location = new Point(_snake[0].Location.X, _snake[0].Location.Y + _sizeOfSides);
                    break;
                case Direction.LEFT:
                    _snake[0].Location = new Point(_snake[0].Location.X - _sizeOfSides, _snake[0].Location.Y);
                    break;
                case Direction.RIGHT:
                    _snake[0].Location = new Point(_snake[0].Location.X + _sizeOfSides, _snake[0].Location.Y);
                    break;
            }

            _CheckBorders();
            _CheckTailDamage();


        }
    }
}       
