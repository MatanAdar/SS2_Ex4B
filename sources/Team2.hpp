#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "Team.hpp"

namespace ariel{
    class Team2 : public Team{

        private:

        public:

            Team2(Character* leader);

            void attack(Team* other_team) override;


    };
}




#endif