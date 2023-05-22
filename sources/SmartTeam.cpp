#include "SmartTeam.hpp"


namespace ariel{

    SmartTeam::SmartTeam(Character* leader) : Team(leader){
        
    }

    // bool sortByPower(const Character* c1, const Character* c2) {
    //     return c1->getPower() > c2->getPower();
    // }

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

            // Ninja *ninja = dynamic_cast<Ninja *>(player);

            // if(ninja != nullptr){


            //     //checking location of the victims and if its less then 1 meter away and under 40 hp we will give it priority 10
            //     //checking if location is under 1 meter but has more then 40 hp , and there is no one under 10 health taht cowboy can shot give a priority 9
            //     //checking if there someone with under 40 hp but higher then 10(that cowboy cant kill himself) but distance is higher then 1 meter will give priority 8
            // }
            // else{ //that is a cowboy
            //     //checking if there is a victim under 10 hp will give priority 10
            //     //checking if there someone higher then 10 hp but under 20 to give priority 9
            // }
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
                } else if (dynamic_cast<Ninja*>(attacker) != nullptr) {
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



    // int SmartTeam::find_priority(Character* attacker, Character* enemy_player){
    //     if(dynamic_cast<Cowboy*>(attacker) && enemy_player->getHealth() <=10){
    //         return 10;
    //     }
    //     else if(dynamic_cast<Ninja *>(attacker) && attacker->distance(enemy_player) <=1 && enemy_player->getHealth() <=40){
    //         return 9;
    //     }
    //     else if(dynamic_cast<Ninja *>(attacker) && attacker->distance(enemy_player) <=1 && enemy_player->getHealth() >40){
    //         return 8;
    //     }
    //     else if(dynamic_cast<Ninja *>(attacker) && attacker->distance(enemy_player) >1){
    //         return 7;
    //     }
    //     else if(dynamic_cast<Cowboy *>(attacker)){
    //         return 6;
    //     }
    //     else{
    //         return -1;
    //     }
    // }


    // void SmartTeam::Algo_Find_victim_and_dmg(Team* other_team , Character* attacker){

        // for(auto player : other_team->getTeam()){
        //     //best priority that cowboy will shoot someone that under 10 hp and will kill him
        //     if(player->getHealth() <=10 && dynamic_cast<Cowboy*>(attacker)){
        //         attacker->attack(player);
        //     }

        //     Ninja *ninja = dynamic_cast<Ninja *>(attacker);
        //     if(ninja != nullptr){
        //         //best priority for ninja- hp is under 40 and distance is under 1 meter that will kill the player
        //         if(ninja->distance(player) <= 1 && player->getHealth() <=40){
        //             ninja->slash(player);
        //         }
        //         //second priority- distance is under 1 meter but hp is higher then 40 health so ninja will dmg him but not kill hi
        //         else if(ninja->distance(player) <= 1 && player->getHealth() > 40){
        //             ninja->slash(player);
        //         }
        //         else{ // third priority - if the distance is higher then 1 you need to move towards him
        //             ninja->move(player);
        //         }
        //     }
        //     else{ // attacker is cowboy

        //         attacker->attack(player);
        //     }

        // }
    // }



}