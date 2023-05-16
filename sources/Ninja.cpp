#include "Ninja.hpp"

#include <iostream>


namespace ariel{

    Ninja::Ninja(const string& name, const Point& location, int health , int speed) : Character(name,location,health), speed(speed){
        
    }

    void Ninja::move(Character* enemy){
        
        Point new_position = Point::moveTowards(this->getLocation(), enemy->getLocation(), this->speed);

        this->setLocation(new_position);
    }

    void Ninja::slash(Character* enemy){

        if(this != enemy){
            if((enemy->isAlive() == false) || (this->isAlive() == false)){
                throw std::runtime_error("Cant attack dead player");
            }
            else if((this->isAlive() == true) && (this->distance(enemy) < 1)){
                // lower hp of enemy by 40 hit points
                enemy->set_Health_Lower(40);
            }
        }
        else{
            throw std::runtime_error("cant harm myself");
        }

    }

    // string Ninja::print() const{
    //     return "hii";
    // }

}