using System;
namespace lab5
{
    public class FoodCreator
    {
        private Point _food;
        public Point Food
        {
            get { return _food; }
        }

        private int _columns;
        private int _rows;

        
        private Random _generator;

        public FoodCreator(int rows, int columns)
        {
            _generator = new Random();
            _rows = rows;
            _columns = columns;

            _food = new Point(rows / 2, columns / 2, '$', ConsoleColor.Yellow);
        }

        public void GenerateNewFood()
        {
            _food.x = _generator.Next(1, _columns+1);
            _food.y = _generator.Next(1, _rows+1);
        }
    }
}
