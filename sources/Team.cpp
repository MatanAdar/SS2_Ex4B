#include "Team.hpp"

#include <cmath>
#include <stdexcept>




namespace ariel{

    Team::Team(Character* leader) : team_leader(leader) {

        //checking if player is already in any team
        bool result = checking_player_in_team_already(leader);

        if(result == true){
            throw std::runtime_error(leader->getName() + "is already in a team");
        }
        else{
            team.push_back(leader);
            leader->setInTeam(true);
        }

    }

    void Team::add(Character* player){

        //checking if player is already in any team
        bool result = checking_player_in_team_already(player);

        if(result == true){
            throw std::runtime_error(player->getName() + "is already in a team");
        }

        if(team.size() < 10){
            team.push_back(player);
            player->setInTeam(true);
        }
        else{
            throw std::runtime_error("Team is Max capacity!");
        }
    }


    void Team::attack(Team* other_team){

        if(other_team  == NULL){
            throw std::invalid_argument("There is no team to attack");
        }
        else{

            double shortest_distance; 

            if(this->getLeader()->isAlive() == false){
                Point leader_loc = this->getLeader()->getLocation();

                shortest_distance = this->getLeader()->distance(team[0]);

                for(size_t i = 1; i<team.size(); i++){
                    double check_dis = this->getLeader()->distance(team[i]);
                    if(check_dis < shortest_distance && team[i]->isAlive()){
                        this->setLeader(team[i]);
                    }
                }
            }

            Character* victim;
            shortest_distance = other_team->getLeader()->distance(team[0]);
            for(size_t i = 1;i<other_team->getTeam().size();i++){
                double check_dis = other_team->getLeader()->distance(other_team->getTeam()[i]);
                if(check_dis < shortest_distance && other_team->getTeam()[i]->isAlive()){
                    victim = other_team->getTeam()[i];
                }
            }  
            // for attacker in attackers:
            //     attacker.attack(victim)

            // attack():
            //     if יש כדורים
            //         תירה
            //     else

                


        }
        
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

        if(player->getInTeam() == true){
            return true;
        }
        return false;
    }

    Team::~Team(){
        for (auto player : team) {
            delete player;
        }
    }

}