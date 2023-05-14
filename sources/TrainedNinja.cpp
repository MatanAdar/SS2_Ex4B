#include "TrainedNinja.hpp"


namespace ariel{

    TrainedNinja::TrainedNinja(const string& name,const Point& location) : Ninja(name,location,120,12) {

    }

    string TrainedNinja::print() const{

        return "Hii TrainedNinja";
    }
}