using System;
using System.Collections.Generic;

namespace lab5
{
    public class Snake : Figure
    {
        public Snake(int rows, int columns)
        {
            _figure.Add(new Point(rows / 2, columns / 2, 'S', ConsoleColor.Red));
        }

        public override void AddPoint()
        {
            int idx = _figure.Count - 1;

            int xTail = _figure[idx].x;
            int yTail = _figure[idx].y;


            _figure.Add(new Point(yTail, xTail,'S', ConsoleColor.Red));
        }

        public override void Move(Direction direction)
        {
            _figure.Insert(0, _figure[0].GetNextPoint(direction));
            _figure.Remove(_figure[_figure.Count-1]);

            if (_figure.Count > 2 &&_figure[0].isCross(_figure[2]))
            {
                _figure.Reverse();
            }
            
            for (int i = 3; i < _figure.Count; ++i)
            {
                if (_figure[0].isCross(_figure[i]))
                {
                    throw new GameOverException("Game over!\n");
                }
            }
        }
    }
}
