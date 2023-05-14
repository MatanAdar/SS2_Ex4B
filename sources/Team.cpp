#include "Team.hpp"

#include <cmath>
#include <stdexcept>




namespace ariel{

    Team::Team(Character* leader) : team_leader(leader) {

        //checking if player is already in any team
        if(leader->getInTeam() == true){
            throw std::runtime_error(leader->getName() +" is already in a team");
        }
        
        // if(checking_player_in_team_already(leader) == true){
        //     throw std::runtime_error(leader->getName() +" is already in the team");
        // }

        team.push_back(leader);
        leader->setInTeam(true);

    }

    void Team::add(Character* player){

        if(team.size() < 10){
            team.push_back(player);
            player->setInTeam(true);
        }
        else{
            throw std::runtime_error("Team is Max capacity!");
        }
    }


    void Team::attack(Team* other_team){

    }

    int Team::stillAlive() const{
        
        int count = 0;
        for(size_t i=0; i<team.size(); i++){
            if(team[i]->isAlive() == true){
                count++;
            }

        }

        return count;
    }
            
    void Team::print() const{

    }

    bool Team::checking_player_in_team_already(Character* player){

        for(size_t i=0; i<team.size(); i++){
            if(team[i] == player){
                return true;
            }
        }

        return false;

    }

    Team::~Team(){
        for (auto player : team) {
            delete player;
        }
    }

}