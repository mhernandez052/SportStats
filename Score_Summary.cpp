#include "Score_Summary.h"
#include "Game.h"
#include <iostream>
#include <vector>

Score_Summary::Score_Summary(Game* game){
  data = game;
}

/*
 * Displays the scoring summary of a game in the format:
 *  Period 1: 
 *  Player Y, Team 2 scored!
 * for each goal scored in the game provided.
 */
void Score_Summary::display(){
  int period = -1;
  std::vector <goal_t> all_goals = data->get_goals();
  
  for(int event = 0; event < all_goals.size(); event++){
    goal_t current = all_goals[event];
    if( current.period != period ){
      period = current.period;
      std::cout<<"Period "<<period+1<<":\n";
    }
    std::cout<<current.scorer.get_name()<<", Team "<<current.team<<" scored!\n";
  }
}