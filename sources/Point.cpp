#include "Point.hpp"
#include <stdio.h>
#include <cmath>
#include <iostream>

using namespace std;




namespace ariel{

    Point::Point() : point_x(0),point_y(0){

    }

    Point::Point(double __x, double __y) : point_x(__x), point_y(__y){


    }

    double Point::getPointX() const{

        return this->point_x;
    }

    double Point::getPointY() const{

        return this->point_y;
    }

    double Point::distance(const Point& other_point) const{

        double dis_x = this->getPointX() - other_point.getPointX();
        double dis_y = this->getPointY() - other_point.getPointY();

        double pow_x = dis_x*dis_x;
        double pow_y = dis_y*dis_y;

        return sqrt(pow_x + pow_y);

    }

    string Point::print() const{

        return "(" + std::to_string(this->getPointX()) + "," + std::to_string(this->getPointY()) + ")";
    }

    Point Point::moveTowards(const Point& destanation, double distance){

        if(distance < 0){
            throw std::runtime_error("cant give negative distance");
        }
        
        if(distance == 0){
            return *this;        
        }

        double distance_this_to_dest = this->distance(destanation);

        if(distance_this_to_dest < distance){
            return destanation;
        }
        else{
            double ratio = distance / distance_this_to_dest;
            double new_x = this->getPointX() + (destanation.getPointX() - this->getPointX()) * ratio;
            double new_y = this->getPointY() + (destanation.getPointY() - this->getPointY()) * ratio;

            return Point(new_x,new_y);

        }
    }
}