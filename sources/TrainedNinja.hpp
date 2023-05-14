#ifndef TRAINEDNINJA_HPP
#define TRAINEDNINJA_HPP

#include "Ninja.hpp"

namespace ariel{

    class TrainedNinja : public Ninja{

        private:

        public:

            TrainedNinja(const string& name,const Point& location);

            string print() const override;

            //~TrainedNinja() = default;

    };
}




#endif