using System;
using System.Threading;
namespace lab5
{
    public class Game
    {
        private bool _gameOver;

        private Borderline _borderline;
        private Field _field;
        private Snake _snake;

        private FoodCreator _foodCreator;
        private Point _food;

        public Game(int rows, int columns)
        {
            _gameOver = false;

            _field = new Field(rows, columns);
            _snake = new Snake(rows, columns);
            _borderline = new Borderline(rows, columns);

            _foodCreator = new FoodCreator(rows, columns);
            _foodCreator.GenerateNewFood();

            _food = _foodCreator.Food;
        }

        private void _UpdateField()
        {
            if (_snake.isCross(_food))
            {
                _foodCreator.GenerateNewFood();
                _food = _foodCreator.Food;
                _snake.IncreaseTail();
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
                _snake.ChangeDirection(key.Key);
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
                    _UpdateField();
                    
                    _snake.Move();
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
