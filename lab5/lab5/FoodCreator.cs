using System;
namespace lab5
{
    public class FoodCreator
    {
        private int _columns;
        private int _rows;

        private int _xFood;
        public int XFood
        {
            get
            {
                return _xFood;
            }
        }

        private int _yFood;
        public int YFood
        {
            get
            {
                return _yFood;
            }
        }

        private Random _generator;

        public FoodCreator(int rows, int columns)
        {
            _generator = new Random();
            _rows = rows;
            _columns = columns;

            _xFood = columns / 2;
            _yFood = rows / 2;
        }

        public void GenerateFood()
        {
            _xFood = _generator.Next(0, _columns);
            _yFood = _generator.Next(0, _rows);
        }
    }
}
