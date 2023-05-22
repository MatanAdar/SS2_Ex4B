#ifndef SMARTTEAM_HPP
#define SMARTTEAM_HPP

#include "Team.hpp"

namespace ariel{
    class SmartTeam : public Team{

        private:


        public:

            SmartTeam(Character* leader);

            void attack(Team* other_team) override;

            Character* FindBestPlayerToAttack(Team* other_team, Character* attacker);


    };
}



#endif
