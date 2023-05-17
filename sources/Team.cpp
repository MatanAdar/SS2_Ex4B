#include "Team.hpp"

#include <cmath>
#include <stdexcept>
#include <iostream>
#include <numeric>
#include <limits> 





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

        if(other_team  == nullptr){
            throw std::invalid_argument("There is no team to attack");
        }
        if(this->stillAlive() == 0 || other_team->stillAlive() == 0){
            throw std::runtime_error("Game over");
        }
        
        if(this->getLeader()->isAlive() == false){
            find_new_leader();
        }

        //checking who is the most closes to the leader to be the victim
        Character* victim = nullptr;
        if(other_team->stillAlive() > 0){
            victim = findVictim(other_team);
        }
        else
            return;

        for(Character* attacker : team){
            if(attacker != nullptr && attacker->isAlive()){

                if(victim != nullptr && victim->isAlive()){
                    attacker->attack(victim);
                }
                else{
                    victim = findVictim(other_team);
                    if (victim != nullptr && victim->isAlive())
                    {
                        attacker->attack(victim);
                        //victim->print();
                    }
                }
            }
        }
    }

    void Team::find_new_leader(){

        double shortest_distance = numeric_limits<double>::max();

        for(Character* player : team){
            double check_dis = this->getLeader()->distance(player);
            if(check_dis < shortest_distance && player->isAlive()){
                shortest_distance = check_dis;
                this->setLeader(player);
            }
        }
    }

    Character* Team::findVictim(Team* other_team){
        Character* victim;
        double minDistance = numeric_limits<double>::max();

        for (auto player : other_team->getTeam()){

            if (player != nullptr && player->isAlive()){

                double distance = other_team->getLeader()->distance(player);
                if (distance <= minDistance)
                {
                    minDistance = distance;
                    victim = player;
                }
            }
        }

        return victim;
    }
    

    int Team::stillAlive() const{
        
        int count = 0;
        for(Character* player : team){
            if(player != nullptr && player->isAlive()){
                count++;
            }
        }
        return count;
    }
            
    void Team::print() const{
        cout << "players details:" << endl;
        for(Character* player : team){
            cout << player->print() << endl;
        }
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