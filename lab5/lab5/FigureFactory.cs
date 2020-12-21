using System;
namespace lab5
{
    public class FigureFactory
    {
        private int _rows;
        private int _columns;

        public FigureFactory(int rows, int columns)
        {
            _rows = rows;
            _columns = columns;
        }

        public Figure CreateSnake()
        {
            return new Snake(_rows, _columns);
        }

        public Figure CreateField()
        {
            return new Field(_rows, _columns);
        }

        public Figure CreateBorderline()
        {
            return new Borderline(_rows, _columns);
        }
    }
}
