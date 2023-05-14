#include "YoungNinja.hpp"


namespace ariel{

    YoungNinja::YoungNinja(const string& name, const Point& location) : Ninja(name,location,100,14){

    }

    string YoungNinja::print() const{

        return "hii YoungNinja";
    }
}