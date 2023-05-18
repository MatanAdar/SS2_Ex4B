#include "Team2.hpp"

namespace ariel{
    
    Team2::Team2(Character* leader) : Team(leader){

    }


    void Team2::add(Character *player){

        if(player == nullptr){
            throw std::runtime_error("cant be null");
        }

        if (player->isAlive() && !player->getInTeam() && getTeam().size() < 10)
        {
            getTeam().push_back(player);
            player->setInTeam(true);
        }
        else
        {
            throw runtime_error("Can't add this player");
        }
    }
       

}