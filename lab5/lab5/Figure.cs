using System;
using System.Collections.Generic;
namespace lab5
{
    public class Figure
    {
        protected List<Point> _figure;

        protected Figure()
        {
            _figure = new List<Point>();
        }

        public void Draw()
        {
            foreach (Point p in _figure)
            {
                p.Draw();
            }
        }

        public bool isCross(Figure other)
        {
            foreach (Point p in _figure)
            {
                if (other.isCross(p))
                {
                    return true;
                }
            }
            return false;
        }

        public bool isCross(Point point)
        {
            foreach(Point p in _figure)
            {
                if (p.isCross(point))
                {
                    return true;
                }
            }
            return false;
        }
    }
}
