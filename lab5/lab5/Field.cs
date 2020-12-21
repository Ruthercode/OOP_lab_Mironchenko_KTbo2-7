using System;
using System.Collections.Generic;

namespace lab5
{
    public class Field : Figure
    {
        
        public Field(int rows, int columns)
        {
            for (int i = 1; i <= rows; ++i)
            {
                for (int j = 1; j <= columns; ++j)
                {
                    _figure.Add(new Point(i, j, '0', ConsoleColor.Gray));
                }
            }
        }

        public override void AddPoint()
        {
            throw new NotImplementedException();
        }

        public override void Move(Direction direction)
        {
            throw new NotImplementedException();
        }
    }
}
