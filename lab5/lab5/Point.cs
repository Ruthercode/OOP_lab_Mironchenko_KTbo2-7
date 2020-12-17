using System;
namespace lab5
{
    public class Point
    {
        public int x;
        public int y;
        public char symbol;
        public ConsoleColor color;

        public Point(int _y, int _x, char _symbol, ConsoleColor _color)
        {
            y = _y;
            x = _x;
            symbol = _symbol;
            color = _color;
        }

        public Point GetNextPoint(Direction direction)
        {
            if (direction == Direction.UP)
            {
                return new Point(y - 1, x, symbol, color);
            }
            else if (direction == Direction.DOWN)
            {
                return new Point(y + 1, x, symbol, color);
            }

            else if (direction == Direction.LEFT)
            {
                return new Point(y, x-1, symbol, color);
            }
            else if (direction == Direction.RIGHT)
            {
                return new Point(y, x+1, symbol, color);
            }

            return new Point(y, x, symbol, color);
        }

        public bool isCross(Point other)
        {
            return x == other.x && y == other.y;
        }

        public void Draw()
        {
            Console.BackgroundColor = color;
            Console.SetCursorPosition(x, y);
            Console.Write(symbol);
        }
    }
}
