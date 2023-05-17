#include "Ninja.hpp"

#include <iostream>


namespace ariel{

    Ninja::Ninja(const string& name, const Point& location, int health , int speed) : Character(name,location,health), speed(speed){
        
    }

    void Ninja::move(Character* enemy) {
        Point current_location = this->getLocation();
        Point new_position = current_location.moveTowards(current_location, enemy->getLocation(), this->speed);
        this->setLocation(new_position);
    }

    void Ninja::slash(Character* enemy){

        if(this != enemy){
            if((enemy->isAlive() == false) || (this->isAlive() == false)){
                throw std::runtime_error("Cant attack dead player");
            }
            else if((this->isAlive() == true) && (this->distance(enemy) <= 1)){
                // lower hp of enemy by 40 hit points
                enemy->hit(40);
            }
        }
        else{
            throw std::runtime_error("cant harm myself");
        }

    }

    string Ninja::print() const{
        
        if(this->isAlive() == false){
            return " N (" + this->getName() + ") " + this->getLocation().print();
        }

        return " N " + this->getName() + " " + std::to_string(this->getHealth()) + " " + this->getLocation().print();
    }


    void Ninja::attack(Character* enemy) {

        if(enemy == nullptr || !(this->isAlive()) || !(enemy->isAlive()) ){
            throw std::invalid_argument("cant attack null");
        }

        if(this->distance(enemy) > 1 ){
            move(enemy);
        }
        else{
            this->slash(enemy);
        }
    }

}