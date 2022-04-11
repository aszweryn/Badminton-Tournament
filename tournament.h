#ifndef MAIN_CPP_TOURNAMENT_H
#define MAIN_CPP_TOURNAMENT_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <random>
#include <deque>
using namespace std;

class Player {
public:
    Player(int id, string Name);
    ~Player() = default;
    void printPlayer();                             //prints single player's data
    string getName();                               //simple getter
    int getId();
    void setDenominatorResult(int result);
private:
    string Name;
    int id;
    int denominatorResult;                          //the phase of the tournament that a certain player got to
};

class Match {
public:
    Match(Player& player1, Player& player2, int PlayerScore1, int PlayerScore2);
    ~Match() = default;
    void printMatch();                                //prints the data of a single match
    Player& passWinner();                             //passes winner to the top of players list
    Player& elimLooser();                             //moves player to looser list
private:
    vector<Player> players;                           //vector containing Player class objects
    int scorePlayer1;                                 //score of a player in one match
    int scorePlayer2;
};

class Matches {
public:
    Matches();
    ~Matches() = default;
    void printMatches();                                    //prints all data from Round class
    void addMatch(Match& match);                            //adds a match between 2 players
    void deleteMatches();                                   //calls destructor of Match class
    vector<vector<Player>>& getOutcome();                   //passes winner, eliminates looser
private:
    vector<Match> matches;                                  //a vector that contains object of Match class
    vector<vector<Player>> roundResults;
};


class BadmintonTournament {
public:
    BadmintonTournament(string name);
    string getTournamentName();
    void addPlayer(Player& player);                    //adds a Player object
    void generateMatches();                            //generates the round
    void deleteMatches();                              //destructor of Matches
    void finishRound();                                //finishes the round
    void clearTournament();                            //clears the whole data of the tournament, useful for testing
    void printPlayer(int id);                          //prints the player with given id
    ~BadmintonTournament() = default;
    void printTournament();                            //prints the outcome of the tournament
    void printRound();                                 //prints every single round
    bool checkNumberOfPlayers();                       //checks if there is a correct amount of players to start a tournament (1-ok, 0-no)
private:
      string tournamentName;
      deque<Player> players;                           //used because list did not work
      list<Player> eliminated;                         //a list that contains players that lost their matches
      Matches matchesModule;                           //private member that allows to access Matches class
      int actualRound;                                 //stores an actual phase of the tournament
};

#endif //MAIN_CPP_TOURNAMENT_H