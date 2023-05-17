#include "Character.hpp"
#include <stdio.h>
#include <iostream>
#include <ostream>

using namespace std;

namespace ariel{

    Character::Character(const string& name,const Point& location , int health) : c_name(name), c_location(location), c_health(health) {
        
    }

    Character::Character(const string& name,const Point& location) : c_name(name) , c_location(location){
        
    }

    bool Character::isAlive() const{

        return c_health > 0;
    }

    double Character::distance( Character* other_c) {
        double ans = this->getLocation().distance(other_c->getLocation());
        return ans;

    }

    void Character::hit(int hits){

        if(hits < 0 ){
            throw std::invalid_argument("cant give negative value");
        }

        c_health -= hits;
    }


    

}


