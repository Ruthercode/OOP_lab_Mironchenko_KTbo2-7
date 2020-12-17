using System;
using System.Collections.Generic;

namespace lab5
{
    public class Snake : Figure
    {
        
        private int _columns;
        private int _rows;

        private Direction _direction;
        public Snake(int rows, int columns)
        {
            _rows = rows;
            _columns = columns;

            _figure.Add(new Point(rows / 2, columns / 2, 'S', ConsoleColor.Red));

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
            int idx = _figure.Count - 1;

            int xTail = _figure[idx].x;
            int yTail = _figure[idx].y;

            Move();

            _figure.Add(new Point(yTail, xTail,'S', ConsoleColor.Red));
        }

        public void Move()
        {
            _figure.Insert(0, _figure[0].GetNextPoint(_direction));
            _figure.Remove(_figure[_figure.Count-1]);

            for (int i = 1; i < _figure.Count; ++i)
            {
                if (_figure[0].isCross(_figure[i]))
                {
                    throw new GameOverException("Game over!\n");
                }
            }
        }
    }
}
