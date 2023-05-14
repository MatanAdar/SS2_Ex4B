#ifndef TEAM_HPP
#define TEAM_HPP



#include "Point.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"

#include <vector>

using namespace ariel;


namespace ariel{

    class Team{

        private:

            vector<Character*> team;

            Character* team_leader;

        public:

            Team(Character* leader);

            Character* getLeader(){
                return team_leader;
            }

            void add(Character* player);

            void attack(Team* other_team);

            int stillAlive() const;
            
            void print() const;

            bool checking_player_in_team_already(Character* player);

            //destructor
            ~Team();

            Team(const Team& other) : team_leader(other.team_leader){
            // Copy the state of the `other` object
            // to the new `Team` object
            // ...
            }

            // Copy assignment operator
            Team& operator=(const Team& other) {
                if (this != &other) {
                    // Copy the state of the `other` object
                    // to the current object
                    // ...
                }
                return *this;
            }

            // Move constructor
            Team(Team&& other) = default;

            // Move assignment operator
            Team& operator=(Team&& other) = default;


    };
}



#endif