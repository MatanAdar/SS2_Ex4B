#include "Ninja.hpp"


namespace ariel{

    Ninja::Ninja(const string& name, const Point& location, int health , int speed) : Character(name,location,health), speed(speed){
        
    }

    void Ninja::move(Character* enemy){

        
    }

    void Ninja::slash(Character* enemy){

    }

    // string Ninja::print() const{
    //     return "hii";
    // }

}