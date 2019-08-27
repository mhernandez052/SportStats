/*
  Comments
*/

#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include <string>
#include <vector>

const int TEAMS = 2;
const Player DEFAULT_PLAYER = Player("NA",999);

struct goal_t
{
      Player scorer = DEFAULT_PLAYER;
      int team; // 1-indexed
      int period; // 1-indexed
};

class Game
{
  private:
    int current_period;
    std::vector <Player> roster[TEAMS];
    std::vector <goal_t> goals;

    Player get_player_by_name(std::string);
    std::vector <Player> get_roster_from_file(std::string);

  public:
    // Initiates rosters from the file names provided for team 1 and team 2 and
    // begins the game in period 1
    Game(std::string, std::string);

    // Records a player's goal in the current period for the team containing
    // the player name provided (or does nothing if no matching names)
    void add_goal(std::string);

    // Progresses the current period to the subsequent period #, with no limit
    // for the number of periods
    void next_period();

    // Retrieves the list of goal data in chronological order
    std::vector <goal_t> get_goals();
};

#endif
