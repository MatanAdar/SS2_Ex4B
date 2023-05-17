#ifndef POINT_HPP
#define POINT_HPP


#include <stdio.h>
#include <string>
#include <stdexcept>
#include <numeric>
#include <limits>

using namespace std;

namespace ariel{
    class Point{
        private:
            double point_x;
            double point_y;

        public:

            Point();

            Point(double point_x, double point_y);

            double getPointX() const;

            double getPointY() const;

            double distance(const Point& point) const;

            string print() const;

            Point static moveTowards(const Point &src, const Point &dest, double dist);

    };
}      


#endif