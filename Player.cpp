#include "Player.h"
#include <string>

Player::Player(std::string person, int number){
    name = person;
    jersey = number;
    total_goals = 0;
}

// Retrieves the player's name
std::string Player::get_name(){
    return name;
}

// Retrieves the player's jersey number
int Player::get_jersey(){
    return jersey;
}

// Tallies 1 more goal to the player's total
void Player::tally_goal(){
    total_goals++;
}

// Retrieves the current total number of goals scored by the player
int Player::get_goals(){
    return total_goals;
}