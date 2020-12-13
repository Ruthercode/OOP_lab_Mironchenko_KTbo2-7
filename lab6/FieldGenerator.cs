using System;
using System.Drawing;
using System.Windows.Forms;
using System.Collections.Generic;
namespace lab6
{
    public class FieldGenerator
    {
        private int _widthAndHeight;
        private int _sizeOfSides;
        public FieldGenerator(int widthAndHeight, int sizeOfSides)
        {
            _widthAndHeight = widthAndHeight;
            _sizeOfSides = sizeOfSides;
        }

        public List<PictureBox> GenerateField()
        {
            List<PictureBox> toReturn = new List<PictureBox>();

            for (int i = 0; i < _widthAndHeight / _sizeOfSides + 1; i++)
            {
                PictureBox pic = new PictureBox();
                pic.BackColor = Color.Black;
                pic.Location = new Point(0, _sizeOfSides * i);
                pic.Size = new Size(_widthAndHeight, 1);
                toReturn.Add(pic);
            }
            for (int i = 0; i <= _widthAndHeight / _sizeOfSides; i++)
            {
                PictureBox pic = new PictureBox();
                pic.BackColor = Color.Black;
                pic.Location = new Point(_sizeOfSides * i, 0);
                pic.Size = new Size(1, _widthAndHeight);
                toReturn.Add(pic);
            }

            return toReturn;
        }
    }
}
