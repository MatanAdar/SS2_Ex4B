#include "OldNinja.hpp"


namespace ariel{

    OldNinja::OldNinja(const string& name, const Point& location) : Ninja(name,location,150,8) {

    }  


    string OldNinja::print() const{

        return "Hii OldNinja";
    }
}