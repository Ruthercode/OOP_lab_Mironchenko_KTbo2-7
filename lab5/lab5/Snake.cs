using System;
using System.Collections.Generic;

namespace lab5
{
    public class Snake
    {
        private List< Point> _snake;
        public List<Point> GetSnake
        {
            get
            {
                return _snake;
            }
        }
        // first y, second x

        private int _columns;
        private int _rows;

        private Direction _direction;
        public Snake(int rows, int columns)
        {
            _rows = rows;
            _columns = columns;

            _snake = new List< Point>();
            _snake.Add(new Point(rows / 2, columns / 2));

            _direction = Direction.LEFT;
        }

        public void ChangeDirection(ConsoleKey key)
        {
            switch (key)
            {
                case ConsoleKey.LeftArrow:
                    _direction = Direction.LEFT;
                    break;
                case ConsoleKey.RightArrow:
                    _direction = Direction.RIGHT;
                    break;
                case ConsoleKey.DownArrow:
                    _direction = Direction.DOWN;
                    break;
                case ConsoleKey.UpArrow:
                    _direction = Direction.UP;
                    break;
            }
            
            
        }

        public void IncreaseTail()
        {
            int idx = _snake.Count - 1;

            int xTail = _snake[idx].x;
            int yTail = _snake[idx].y;

            Move();

            _snake.Add(new Point(yTail, xTail));
        }
        public void Move()
        {
            _snake.Insert(0, _snake[0].GetNextPoint(_direction));
            _snake.Remove(_snake[_snake.Count-1]);

            if (_snake[0].y >= _rows)
            {
                _snake[0].y = 0;
            }

            if (_snake[0].y < 0)
            {
                _snake[0].y = _rows - 1;
            }

            if (_snake[0].x >= _columns)
            {
                _snake[0].x = 0;
            }

            if (_snake[0].x < 0)
            {
                _snake[0].x = _columns - 1;
            }

            for (int i = 1; i < _snake.Count; ++i)
            {
                if ((_snake[i].x == _snake[0].x) &&
                    (_snake[i].y == _snake[0].y))
                {
                    throw new GameOverException("Game over!\n");
                }
            }
        }
    }
}
