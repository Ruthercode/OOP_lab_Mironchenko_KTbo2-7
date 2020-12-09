using System;
using System.Threading;
namespace lab5
{
    public class Game
    {
        private bool _gameOver;
        private Field _field;
        private Snake _snake;
        
        public Game(int rows, int columns)
        {
            _gameOver = false;
            _field = new Field(rows, columns);
            _snake = new Snake(rows, columns);
        }

        private void _DrawField()
        {
            Console.Clear();

            int m = _field.Columns;

            for (int i = 0; i < m + 2; ++i)
            {
                Console.Write('#');
            }
            Console.WriteLine();

            int n = _field.Rows;
            char[,] field = _field.GetField;

            for (int i = 0; i < n; ++i)
            {
                Console.Write('#');

                for (int j = 0; j < m; ++j)
                {
                    if (field[i, j] == 'S' || field[i, j] == 's')
                    {
                        Console.ForegroundColor = ConsoleColor.White;
                    }
                    else if (field[i, j] == '$')
                    {
                        Console.ForegroundColor = ConsoleColor.Red;
                    }
                    else
                    {
                        Console.ForegroundColor = ConsoleColor.Black;
                    }
                    Console.Write(field[i,j]);
                }

                Console.WriteLine('#');
            }

            for (int i = 0; i < m + 2; ++i)
            {
                Console.Write('#');
            }
            Console.WriteLine();
        }

        private void _ReadDirection()
        {
            if (Console.KeyAvailable)
            {
                ConsoleKeyInfo key = Console.ReadKey();
                _snake.ChangeDirection(key.Key);
            }
        }
        public void Init()
        {
            int levelOfSpeed = -1;
            while (!(levelOfSpeed >= 1 && levelOfSpeed <= 10))
            {
                Console.WriteLine("Choose level of dificult from 1 to 10");
                levelOfSpeed = Convert.ToInt32(Console.ReadLine());
            }


            while (!_gameOver)
            {
                try
                {
                    _field.UpdateField(ref _snake);
                    _DrawField();
                    _ReadDirection();
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
