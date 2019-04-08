#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include "Game.h"

class Scoreboard
{
  private:
    // A pointer to the game data that provides the score information including
    // the player, team, and timing of scores
    Game* data;

    /*
     * Displays the team scores game in the format:
     *  Team A: 1
     *  Team B: 0
     * for the current total scores in the game provided.
     */
    void display(Game);

  public:
    /*
     * Overloaded constructor initiates a scoreboard that reflects the
     * total score by team of the provided game pointer, so that it can also be
     * updated whenever there is a new score
     */
    Scoreboard(Game*);
};

#endif