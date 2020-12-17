using System;
namespace lab5
{
    public class Borderline : Figure
    {
        public Borderline(int rows, int columns)
        {
            for (int i = 0; i < columns+2; ++i)
            {
                _figure.Add(new Point(0, i, '#', ConsoleColor.Black));
            }

            for (int i = 1; i <= rows; ++i)
            {
                _figure.Add(new Point(i, 0, '#', ConsoleColor.Black));
                _figure.Add(new Point(i, columns+1, '#', ConsoleColor.Black));
            }

            for (int i = 0; i < columns+2; ++i)
            {
                _figure.Add(new Point(rows+1, i, '#', ConsoleColor.Black));
            }
        }
    }
}
