#include <iostream>
#include <string>
#include "Game.h"
#include "Player.h"
#include "Score_Summary.h"
#include "Scoreboard.h"

using std::string;
using std::cout;
using std::cin;

const char GOAL_CHOICE = 'g';
const char PERIOD_CHOICE = 'n';
const char QUIT_CHOICE = 'q';

char promptMenu();

int main()
{
  Game *game_data = NULL;
  Scoreboard *board = NULL;
  Score_Summary *summary = NULL;
  string file1 ="", file2="";

  cout<<"Enter two roster files: ";
  cin>>file1>>file2;

  try{
    game_data = new Game(file1,file2);  
  }
  catch(...){
    cout<<"Something went wrong (besides this message).\n";
    exit(1);
  }

  //connect different displays with game data
  board = new Scoreboard(game_data);
  summary = new Score_Summary(game_data);

  char choice = QUIT_CHOICE;
  do{

    choice = promptMenu();
    if( choice == GOAL_CHOICE ){
      string player;
      cout<<"Scoring Player: ";
      cin>>player;
      game_data->add_goal(player);  
    }
    else if( choice == PERIOD_CHOICE ){
      game_data->next_period();
    }
  }while( choice != QUIT_CHOICE );

  cout<<"\n===FINAL SCORE===\n";
  board->display();

  cout<<"\n---By Period---\n";
  summary->display();

  return 0;
}

char promptMenu(){
  char response, choice;
  bool valid = false;
  do{
    cout<<"Menu\n====\n(G)oal\n(N)ext Period\n(Q)uit\n> ";
    cin>>response;
    switch(response){
      case 'G':
      case 'g':
        choice = GOAL_CHOICE;
        valid = true;
        break;

      case 'N':
      case 'n':
        choice = PERIOD_CHOICE;
        valid = true;
        break;

      case 'Q':
      case 'q':
        choice = QUIT_CHOICE;
        valid = true;
        break;

      default:
        cout<<"Choose from G, N, or Q.\n";
        break;
    }
  }while( !valid );
  return choice;
}