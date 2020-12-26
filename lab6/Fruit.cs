using System;
using System.Drawing;
using System.Windows.Forms;

namespace lab6
{
    public class Fruit : PictureBox
    {
        public Fruit(int widthAndHeight, int sizeOfSides)
        {
            int rI, rJ;
            this.BackColor = Color.Yellow;
            Random r = new Random();
            rI = r.Next(0, widthAndHeight - sizeOfSides);
            int tempI = rI % sizeOfSides;
            rI -= tempI;
            rJ = r.Next(0, widthAndHeight - sizeOfSides);
            int tempJ = rJ % sizeOfSides;
            rJ -= tempJ;
            rI++;
            rJ++;
            this.Location = new Point(rI, rJ);
            this.Size = new Size(sizeOfSides - 1, sizeOfSides - 1);
        }
    }
}
