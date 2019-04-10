#ifndef SCORE_SUMMARY_H
#define SCORE_SUMMARY_H
#include "Game.h"

class Score_Summary
{
  private:
    // A pointer to the game data that provides the score information including
    // the player, team, and timing of scores
    Game* data;

    

  public:
    /*
     * Overloaded constructor initiates a score summary to correspond with a 
     * particular game so it can update whenever a new goal has been scored
     */
    Score_Summary(Game*);

    /*
     * Displays the scoring summary of a game in the format:
     *  Period X: Player Y, Team A 1 - Team B 0
     * for each goal scored in the game provided.
     */
    void display();
};

#endif