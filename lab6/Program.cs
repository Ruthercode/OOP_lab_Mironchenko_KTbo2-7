using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lab6
{
    static class Program
    {

        /// <summary>
        /// Главная точка входа для приложения.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);

            GameBuilder builder = new GameBuilder();

            builder.SetWigthAndHeight();
            builder.SetLabelHeight();
            builder.SetSizeOfSizes();
            builder.SetWindowParameters();
            builder.SetDirection();
            builder.SetSnake();
            builder.SetFruit();
            builder.SetScore();
            builder.SetScoreLabel();
            builder.SetField();
            builder.AddItemsToControls();
            Application.Run(builder.Game);
        }
    }
}
