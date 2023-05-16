#include "Cowboy.hpp"
#include <stdexcept>



namespace ariel{

    // Cowboy::Cowboy(const string& name, const Point& location, int health) : Character(name,location,110), amount_of_bullets(6){

    // }

    Cowboy::Cowboy(const string& name, const Point& location) : Character(name,location,110) , amount_of_bullets(6){


    }

    void Cowboy::shoot(Character* enemy){

        if(this != enemy){
            if(enemy->isAlive() == false || this->isAlive() == false){
                throw std::runtime_error("Cant attack dead player");
            }
            
            if((this->getHealth() > 0) && (this->hasboolets())){

                //lower health of enemy by 10
                enemy->set_Health_Lower(10);

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

        amount_of_bullets = 6;
    }

    string Cowboy::print() const{

        if(this->getHealth() <= 0){
            return "C (" + this->getName() + ") " + this->getLocation().print();
        }

        return "C " + this->getName() + " " + std::to_string(this->getHealth()) + " " + this->getLocation().print();
    }


}