#include "Cowboy.hpp"
#include <stdexcept>



namespace ariel{

    Cowboy::Cowboy(const string& name, const Point& location) : Character(name,location,110) , amount_of_bullets(6){


    }

    void Cowboy::shoot(Character* enemy){

        if(enemy == nullptr){
            throw std::runtime_error("player cant be null");
        }

        if(this != enemy){
            if(enemy->isAlive() == false || this->isAlive() == false){
                throw std::runtime_error("Cant shoot dead player");
            }
            
            if((this->isAlive()) && (this->hasboolets())){

                //lower health of enemy by 10
                enemy->hit(10);

                //lower amout of bullets by 1
                this->amount_of_bullets--;
            }
        }
        else{
            throw std::runtime_error("cant harm myself");
        }

    }

    bool Cowboy::hasboolets() const{

        return amount_of_bullets > 0;
    }

    void Cowboy::reload(){

        if(this->isAlive() == false){
            throw std::runtime_error("dead player cant reload");
        }
        else{
            amount_of_bullets = 6;
        }
    }

    string Cowboy::print() const{

        if(this->isAlive() == false){
            return " [C] ,Name: (" + this->getName() + ") " + "Location: " + this->getLocation().print();
        }

        return " [C] ,Name: " + this->getName() + " ,HP: " + std::to_string(this->getHealth()) + " ,Location: " + this->getLocation().print();
    }


    void Cowboy::player_attack(Character* enemy) {

        if(enemy == nullptr || !(this->isAlive()) || !(enemy->isAlive())){
            throw std::invalid_argument("cant attack null");
        }

        if(!(this->hasboolets())){
            reload();
        }
        else{
            this->shoot(enemy);
        }
    }


}