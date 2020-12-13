using System;
namespace lab6
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
