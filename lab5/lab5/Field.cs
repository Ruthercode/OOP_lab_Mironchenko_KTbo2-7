using System;
using System.Collections.Generic;

namespace lab5
{
    public class Field
    {
        private int _columns;

        public int Columns
        {
            get
            {
                return _columns;
            }
        }

        private int _rows;

        public int Rows
        {
            get
            {
                return _rows;
            }
        }

        private char[,] _field;

        public char[,] GetField
        {
            get
            {
                return _field;
            }
        }

        private FoodCreator _foodCreator;
        private bool _isFoodEaten;

        
        public Field(int rows, int columns)
        {
            _foodCreator = new FoodCreator(rows,columns);
            _columns = columns;
            _rows = rows;
            _isFoodEaten = true;
            _field = new char[_rows, _columns];
        }

        public void UpdateField(ref Snake snake)
        {
            for (int i = 0; i < _rows; ++i)
            {
                for (int j = 0; j < _columns; ++j)
                {
                    _field[i, j] = '0';
                }
            }

            if (_isFoodEaten)
            {
                _foodCreator.GenerateFood();
                _isFoodEaten = false;
            }

            int XFood = _foodCreator.XFood;
            int YFood = _foodCreator.YFood;

            _field[YFood, XFood] = '$';

            List<Point> snakePoints = snake.GetSnake;

            if (_field[snakePoints[0].y, snakePoints[0].x] == '$')
            {
                _isFoodEaten = true;
                snake.IncreaseTail();
            }

            _field[snakePoints[0].y, snakePoints[0].x] = 'S';

            for (int i = 1; i < snakePoints.Count; ++i)
            {
                _field[snakePoints[i].y, snakePoints[i].x] = 's';
            }
        }

    }
}
