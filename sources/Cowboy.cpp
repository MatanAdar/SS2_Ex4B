#include "Cowboy.hpp"
#include <stdexcept>



namespace ariel{

    // Cowboy::Cowboy(const string& name, const Point& location, int health) : Character(name,location,110), amount_of_bullets(6){

    // }

    Cowboy::Cowboy(const string& name, const Point& location) : Character(name,location,110) , amount_of_bullets(6){


    }

    void Cowboy::shoot(Character* enemy){

        if((this->getHealth() > 0) && (this->hasboolets())){

            //lower health of enemy by 10
            enemy->setHealth(10);

            //lower amout of bullets by 1
            this->amount_of_bullets--;
        }
    }

    bool Cowboy::hasboolets() const{

        return amount_of_bullets > 0;
    }

    void Cowboy::reload(){

        if(amount_of_bullets > 0){
            throw std::runtime_error("cant reload when we still have bullets");
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