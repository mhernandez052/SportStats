#include "Scoreboard.h"
#include "Game.h"
#include <vector>
#include <iostream>

/*
 * Displays the team scores game in the format:
 *  Team 1: 1
 *  Team 2: 0
 * for the current total scores in the game provided.
 */
void Scoreboard::display(){
  int total_1 = 0;
  int total_2 = 0;
  std::vector <goal_t> all_goals = data->get_goals();

  for(int goal=0; goal < all_goals.size(); goal++){
    if( all_goals[goal].team == 1 ){
      total_1++;
    }
    else if( all_goals[goal].team == 2 ){
      total_2++;
    }
  }
  std::cout<<"Team 1: "<<total_1<<"\nTeam 2: "<<total_2<<std::endl;
}

/*
 * Overloaded constructor initiates a scoreboard that reflects the
 * total score by team of the provided game pointer, so that it can also be
 * updated whenever there is a new score
 */
Scoreboard::Scoreboard(Game* scores){
  data = scores;
}