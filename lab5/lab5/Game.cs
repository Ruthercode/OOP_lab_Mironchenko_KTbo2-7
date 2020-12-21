using System;
using System.Threading;
namespace lab5
{
    public class Game
    {
        private bool _gameOver;

        private Figure _borderline;
        private Figure _field;
        private Figure _snake;

        private FoodCreator _foodCreator;
        private Point _food;

        private Direction _direction;

        public Game(int rows, int columns)
        {
            _gameOver = false;

            FigureFactory factory = new FigureFactory(rows, columns);

            _field = factory.CreateField();
            _snake = factory.CreateSnake();
            _borderline = factory.CreateBorderline();

            _foodCreator = new FoodCreator(rows, columns);
            _foodCreator.GenerateNewFood();

            _food = _foodCreator.Food;

            _direction = Direction.LEFT;

            //Console.SetWindowSize(rows, columns);
        }

        private void _UpdateField()
        {
            if (_snake.isCross(_food))
            {
                _foodCreator.GenerateNewFood();
                _food = _foodCreator.Food;
                _snake.AddPoint();
            }

            if (_snake.isCross(_borderline))
            {
                throw new GameOverException();
            }

            _borderline.Draw();
            _field.Draw();
            _food.Draw();
            _snake.Draw();

        }

        private void _ReadDirection()
        {
            if (Console.KeyAvailable)
            {
                ConsoleKeyInfo key = Console.ReadKey();
                switch (key.Key)
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
        }

        public void Play()
        {
            int levelOfSpeed = -1;
            while (!(levelOfSpeed >= 1 && levelOfSpeed <= 10))
            {
                Console.WriteLine("Choose level of dificult from 1 to 10");
                levelOfSpeed = Convert.ToInt32(Console.ReadLine());
            }

            
            Console.Clear();
            
            while (!_gameOver)
            {
                try
                {
                    _ReadDirection();
                    
                    _snake.Move(_direction);
                    _UpdateField();
                    
                    Thread.Sleep(500/levelOfSpeed);
                }
                catch (GameOverException)
                {
                    _gameOver = true;
                    Console.Write("Game over!");
                }
            }
        }
    }
}
