using System;
namespace lab5
{
    public class Point
    {
        public int x;
        public int y;

        public Point(int _y, int _x)
        {
            y = _y;
            x = _x;
        }

        public Point GetNextPoint(Direction direction)
        {
            if (direction == Direction.UP)
            {
                return new Point(y + 1, x);
            }
            else if (direction == Direction.DOWN)
            {
                return new Point(y - 1, x);
            }

            else if (direction == Direction.LEFT)
            {
                return new Point(y, x-1);
            }
            else if (direction == Direction.RIGHT)
            {
                return new Point(y, x+1);
            }

            return new Point(y, x);
        }
    }
}
