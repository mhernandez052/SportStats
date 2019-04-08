#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player
{
  private:
    std::string name;
    int jersey;
    int total_goals;

  public:
    // Overloaded constructor initializes a player with their name and jersey #
    Player(std::string, int);

    // Retrieves the player's name
    std::string get_name();

    // Retrieves the player's jersey number
    int get_jersey();

    // Tallies 1 more goal to the player's total
    void tally_goal();

    // Retrieves the current total number of goals scored by the player
    int get_goals();
};

#endif