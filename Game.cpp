#include "Game.h"
#include "Player.h"
#include <string>
#include <vector>
#include <fstream>

//private helper to open a file and load the roster as Name Number format
std::vector <Player> Game::get_roster_from_file(std::string file){
  std::ifstream read;
  std::vector <Player> list;
  read.open(file, std::ios::in );
  if( read.is_open() ){
    std::string name;
    int number;
    while(read>>name>>number){
      Player current(name,number);
      list.push_back(current);
    }
  }
  read.close();
  return list;
}

// Initiates rosters from the file names provided for team 1 and team 2 and
// begins the game in period 1
Game::Game(std::string team1, std::string team2){
  roster[0] = get_roster_from_file(team1);
  roster[1] = get_roster_from_file(team2);

  if( roster[0].empty() || roster[1].empty()  )
    throw "Team files NOT successfully loaded.\n";
}


// Matches the player by a string match of their name (non-greedy)
Player Game::get_player_by_name(std::string find){
  for(int team=0; team < TEAMS; team++){
    for(int i=0; i<roster[team].size(); i++){
      if( find == roster[team][i].get_name() )
        return roster[team][i];
    }
  }
  return DEFAULT_PLAYER;
}

// Records a player's goal in the current period for the team containing
// the player name provided (or does nothing if no matching names)
void Game::add_goal(std::string player_name){
  for(int team=0; team < TEAMS; team++){
    for(int i=0; i<roster[team].size(); i++){
      if( player_name == roster[team][i].get_name() ){
        roster[team][i].tally_goal();
        goal_t new_goal;
        new_goal.scorer=roster[team][i];
        new_goal.period = current_period;
        new_goal.team = team+1;
        goals.push_back(new_goal);
      }
    }
  }
}

// Progresses the current period to the subsequent period #, with no limit
// for the number of periods
void Game::next_period(){
  current_period++;
}

// Retrieves the list of goal data in chronological order
std::vector <goal_t> Game::get_goals(){
  return goals;
}