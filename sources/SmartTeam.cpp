#include "SmartTeam.hpp"


namespace ariel{

    SmartTeam::SmartTeam(Character* leader) : Team(leader){
        
    }


    void SmartTeam::attack(Team* other_team){

        if(other_team  == nullptr|| getLeader() == nullptr){
            throw std::invalid_argument("There is no team to attack/ no leader");
        }

        if(this->stillAlive() == 0 || other_team->stillAlive() == 0){
            throw std::runtime_error("Game over");
        }
        
        if(this->getLeader()->isAlive() == false){
            find_new_leader();
        }

        Character* best_enemy_player = nullptr;

        for(auto attacker : getTeam()){
            // find best player to attack
           best_enemy_player = FindBestPlayerToAttack(other_team,attacker);

            if (best_enemy_player == nullptr || !best_enemy_player->isAlive())
            {
                if (other_team->stillAlive() == 0)
                    return;
                best_enemy_player = FindBestPlayerToAttack(other_team,attacker);
            }

            if (attacker->isAlive())
            {
                attacker->player_attack(best_enemy_player);
            }

        }

    }


    Character* SmartTeam::FindBestPlayerToAttack(Team* other_team, Character* attacker) {
        if (attacker == nullptr || other_team == nullptr) {
            throw std::runtime_error("Attacker cannot be null.");
        }

        if (other_team->stillAlive() == 0) {
            return nullptr;
        }

        Character* bestPlayer = nullptr;
        double bestPriority = std::numeric_limits<double>::max();

        for (auto player : other_team->getTeam()) {
            if (player != nullptr && player->isAlive()) {
                if (dynamic_cast<Cowboy*>(attacker) != nullptr) {
                    double priority = player->getHealth() / 10;
                    if (priority < bestPriority) {
                        bestPriority = priority;
                        bestPlayer = player;
                    }
                } else if(dynamic_cast<Ninja*>(attacker) != nullptr) {
                    double distance = attacker->distance(player);
                    if (distance <= 1 && player->getHealth() <= 40) {
                        bestPlayer = player;
                        break;
                    }
                    else if(distance < bestPriority){
                        bestPriority = distance;
                        bestPlayer = player;
                    }
                }
            }
        }

        return bestPlayer;
    }


}