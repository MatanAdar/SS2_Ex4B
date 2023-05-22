#include "Ninja.hpp"

#include <iostream>


namespace ariel{

    Ninja::Ninja(const string& name, const Point& location, int health , int speed) : Character(name,location,health), speed(speed){
        
    }

    void Ninja::move(Character* enemy){

        if(enemy == nullptr){
            throw std::runtime_error("player cant be null");
        }
        
        Point current_location = this->getLocation();
        Point new_position = current_location.moveTowards(current_location, enemy->getLocation(), this->speed);
        this->setLocation(new_position);
    }

    void Ninja::slash(Character* enemy){

        if(enemy == nullptr){
            throw std::runtime_error("player cant be null");
        }

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
            return " [N] ,Name: (" + this->getName() + ")" + " ,Location: " +this->getLocation().print();
        }

        return " [N] ,Name: " + this->getName() + " ,HP: " + std::to_string(this->getHealth()) + " ,Location: " + this->getLocation().print();
    }


    void Ninja::player_attack(Character* enemy) {

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