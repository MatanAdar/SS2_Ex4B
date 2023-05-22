#ifndef TEAM_HPP
#define TEAM_HPP

#include "Point.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"

#include <vector>
#include <cmath>
#include <stdexcept>
#include <iostream>
#include <numeric>
#include <limits>
#include <ostream> 

using namespace std;


namespace ariel{

    class Team{

        private:

            vector<Character*> team;

            Character* team_leader;

        public:

            Team(Character* leader);

            vector<Character*>& getTeam(){
                return team;
            }

            Character* getLeader(){
                return team_leader;
            }

            void setLeader(Character* other){
                team_leader = other;
            }

            void add(Character* player);

            virtual void attack(Team* other_team);

            void find_new_leader();

            Character* findVictim(Team* other_team);

            int stillAlive() const;
            
            void print() const;

            bool checking_player_in_team_already(Character* player);

            //destructor
            virtual ~Team();

            Team(const Team& other) : team_leader(other.team_leader){
            
            }

            // Copy assignment operator
            Team& operator=(const Team& other) {
                if (this != &other) {

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