#include "Team.hpp"



namespace ariel{

    Team::Team(Character* leader) : team_leader(leader) {

        if(leader == nullptr){
            throw std::runtime_error("cant be null");
        }

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

        if(player == nullptr){
            throw std::runtime_error("cant be null");
        }

        if (player->isAlive() && !player->getInTeam() && team.size() < 10)
        {
            if (Cowboy *cowboy = dynamic_cast<Cowboy*>(player)){
                team.insert(team.begin(), player);
                player->setInTeam(true);
            }
            else{
                team.push_back(player);
                player->setInTeam(true);
            }
        }
        else
        {
            throw runtime_error("Can't add this player");
        }
    }


    void Team::attack(Team* other_team){

        if(other_team  == nullptr|| team_leader == nullptr){
            throw std::invalid_argument("There is no team to attack/ no leader");
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
        else{
            return;
        }

        for(auto attacker : team){
            if(attacker->isAlive()){

                if(victim->isAlive()){
                    attacker->attack(victim);
                }
                else{
                    victim = findVictim(other_team);
                    if (victim->isAlive())
                    {
                        attacker->attack(victim);
                    }
                }
            }
        }

    }

    void Team::find_new_leader(){

        double shortest_distance = numeric_limits<double>::max();

        Character* newLeader = nullptr;

        for(Character* player : team){
            if(player->isAlive()){
                double check_dis = this->getLeader()->distance(player);
                if(check_dis < shortest_distance ){
                    shortest_distance = check_dis;
                    newLeader = player;
                }
            }
        }

        this->setLeader(newLeader);
    }

    Character* Team::findVictim(Team* other_team){

        Character* victim;
        
        double minimumDistance = numeric_limits<double>::max();

        for (auto player : other_team->getTeam()){

            if (player != nullptr && player->isAlive()){

                double distance = this->getLeader()->distance(player);
                if (distance <= minimumDistance)
                {
                    minimumDistance = distance;
                    victim = player;
                }
            }
        }
        //cout << "Victim is: " << victim->getName() << endl;
        return victim;
    }
    

    int Team::stillAlive(){
        
        int count = 0;
        for(Character* player : team){
            if(player != nullptr && player->isAlive()){
                count++;
            }
        }
        return count;
    }
            
    void Team::print() const{
        
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