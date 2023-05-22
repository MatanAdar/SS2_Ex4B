#ifndef NINJA_HPP
#define NINJA_HPP

#include "Character.hpp"


namespace ariel{

    class Ninja : public Character{

        private:
            int speed;

        public:

            Ninja(const string& name, const Point& location, int health , int speed);

            // int getPower() const override{
            //     int power = 40;
            //     return power;
            // }

            void move(Character* enemy);

            void slash(Character* enemy);

            //need to check why i cant do here virtual
            string print() const override;

            void player_attack(Character* enemy) override;

    
    };

}




#endif