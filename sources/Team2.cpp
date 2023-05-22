#include "Team2.hpp"

namespace ariel{
    
    Team2::Team2(Character* leader) : Team(leader){

    }

    //need to change this to work in team2
    void Team2::attack(Team* other_team){

        if(other_team  == nullptr|| getLeader() == nullptr){
            throw std::invalid_argument("There is no team to attack/ no leader");
        }

        if(this->stillAlive() == 0 || other_team->stillAlive() == 0){
            throw std::runtime_error("Game over");
        }
        
        if(this->getLeader()->isAlive() == false){
            find_new_leader();
        }

        //checking who is the most closes to the leader to be the victim
        Character* victim = findVictim(other_team);
        for(auto attacker : getTeam()){
            if (!victim->isAlive())
            {
                if (other_team->stillAlive() == 0)
                    return;
                victim = findVictim(other_team);
            }

            if (attacker->isAlive())
            {
                attacker->player_attack(victim);
            }
        }
    }

       

}