#ifndef SMARTTEAM_HPP
#define SMARTTEAM_HPP

#include "Team.hpp"

namespace ariel{
    class SmartTeam : public Team{

        private:


        public:

            SmartTeam(Character* leader);

            void attack(Team* other_team) override;

            // void Algo_Find_victim_and_dmg(Team* other_team , Character* attacker);

            // int find_priority(Character* attacker, Character* enemy_player);

            // int amount_of_ninjas();

            // int calc_hp_from_ninja();

            Character* FindBestPlayerToAttack(Team* other_team, Character* attacker);


    };
}



#endif
