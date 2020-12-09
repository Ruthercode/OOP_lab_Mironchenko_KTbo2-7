using System;
namespace lab5
{
    public class GameOverException : Exception
    {
        public GameOverException()
        {
        }

        public GameOverException(string message) : base(message)
        {
        }

        public GameOverException(string message, Exception inner)
            : base(message, inner)
        {
        }
    }
}
