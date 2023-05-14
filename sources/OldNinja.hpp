#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP

#include "Ninja.hpp"

namespace ariel{

    class OldNinja : public Ninja{

        private:

        public:

          OldNinja(const string& name, const Point& location);

          string print() const override; 

        //~OldNinja() = default;

    };
}




#endif