#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "Character.hpp"

using namespace std;

namespace ariel{

    class Cowboy : public Character{

        private:
            int amount_of_bullets;

        public:

            Cowboy(const string& name, const Point& location);

            int getBullets() const{
                return amount_of_bullets;
            }

            void shoot(Character* enemy);

            bool hasboolets() const;

            void reload();

            string print() const override;

            void player_attack(Character* enemy) override;

    };
}





#endif