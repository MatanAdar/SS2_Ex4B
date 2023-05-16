#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Point.hpp"
#include <stdio.h>
#include <string>

using namespace std;



namespace ariel{

    class  Character{
        private:
            Point c_location;

            int c_health;

            string c_name;

            bool checking_in_team = false;

        public:

            Character(const string& name,const Point& location , int health);

            Character(const string& name,const Point& location);

            bool isAlive() const;

            double distance(const Character* other_c) const;

            void hit(int hits);

            const string& getName() const{
                return c_name;
            }

            const Point& getLocation() const{
                return c_location;
            }

            void setLocation(const Point& new_p){
                this->c_location = new_p;
            }

            int getHealth() const{
                return c_health;
            }

            void set_Health_Lower(int dmg){
                c_health -= dmg;
            }

            bool getInTeam() const{

                return checking_in_team;
            }

            void setInTeam(bool temp){

                checking_in_team = temp;
            }
            
            virtual string print() const = 0;

            //virtual destructor
            virtual ~Character() = default ;

            Character(const Character&) = delete; // delete copy constructor
            Character& operator=(const Character&) = delete; // delete copy assignment operator
            Character(Character&&) = delete; // delete move constructor
            Character& operator=(Character&&) = delete; // delete move assignment operator



    };
}






#endif