#include "tournament.h"

//PLAYER CLASS
Player::Player (int ID, string name) : id(ID), Name(name), denominatorResult(0) {}

void Player::printPlayer()
{
    cout << "Player ID: " << id << endl;
    cout << "Player's name: " << Name << endl;
    switch(denominatorResult)
    {
        case 8:
        {
            cout << "Player's final round: 1/8 of a final!" << endl;
            break;
        }
        case 4:
        {
            cout << "Player's final round: Quarterfinal!" << endl;
            break;
        }
        case 2:
        {
            cout << "Player's final round: Semifinal!" << endl;
            break;
        }
    }
}

string Player::getName()
{
    return Name;
}

int Player::getId()
{
    return id;
}

void Player::setDenominatorResult(int result)
{
    denominatorResult = result;
}

//MATCH CLASS
Match::Match(Player& player1, Player& player2, int PlayerScore1, int PlayerScore2)
{
    scorePlayer1 = PlayerScore1;
    scorePlayer2 = PlayerScore2;
    players.push_back(player1);
    players.push_back(player2);
}

void Match::printMatch()
{
    cout << players[0].getName() << "(" << scorePlayer1 << ")" << " vs " << players[1].getName() << "(" << scorePlayer2 << ")" << endl;
}

Player& Match::passWinner()
{
    if (scorePlayer1 > scorePlayer2)
        return players.front();
    else
        return players.back();
}

Player& Match::elimLooser()
{
    if (scorePlayer1 > scorePlayer2)
        return players.back();
    else
        return players.front();
}

//MATCHES CLASS
Matches::Matches()
{
    vector<Player> temp1;
    vector<Player> temp2;
    roundResults.push_back(temp1);
    roundResults.push_back(temp2);
}

void Matches::printMatches()
{
    for(Match& m : matches)
    {
        m.printMatch();
    }
}

void Matches::addMatch(Match& match)
{
    matches.push_back(match);
}

void Matches::deleteMatches()
{
    matches.clear();
    roundResults[0].clear();
    roundResults[1].clear();
}

vector<vector<Player>>& Matches::getOutcome()
{
    for (auto& ms : matches) {
        roundResults[0].push_back(ms.passWinner());
        roundResults[1].push_back(ms.elimLooser());
    }
    return roundResults;
}

//BADMINTONTOURNAMENT CLASS

BadmintonTournament::BadmintonTournament(string name)
{
    tournamentName = name;
}

void BadmintonTournament::addPlayer(Player &player)
{
    for(auto& p : players) {
        if(p.getId() == player.getId())
        {
            cout << "We already have a Player with such id." << endl;
            cout << "Please choose another id." << endl;
            return;
        }
    }
    players.push_back(player);
}

void BadmintonTournament::generateMatches()
{
    if(players.size() == 1)
    {
        cout << "We already have a winner!" << endl;
        cout << "Use option Print Tournament Result to see the outcome of the Tournament!" << endl;
        return;
    }

    actualRound = players.size()/2;

    srand(time(NULL));

    auto rng = default_random_engine{};

    shuffle(players.begin(), players.end(), rng);

    int initSize = players.size();
    for(int i = 0; i < (initSize/2); i++)
    {
        auto player1 = players.front();
        players.pop_front();
        auto player2 = players.front();
        players.pop_front();
        int decider = rand() % 101;
        int p1s, p2s;
        if (decider < 50)
        {
            p1s = 21;
            p2s = rand() % 21;
        }
        else
        {
            p1s = rand() % 21;
            p2s = 21;
        }
        Match temp(player1, player2, p1s, p2s);
        matchesModule.addMatch(temp);       //member that allows to access Match class
    }

}

void BadmintonTournament::printRound()
{
    matchesModule.printMatches();
}

void BadmintonTournament::deleteMatches()
{
    matchesModule.deleteMatches();
}

void BadmintonTournament::finishRound() {
    if(players.size() == 1)
    return;

    auto result = matchesModule.getOutcome();
    players.clear();
    for (auto& pw : result[0]) {
        players.push_back(pw);
    }
    for (auto& pl : result[1]) {
        pl.setDenominatorResult(actualRound);
        eliminated.push_front(pl);
    }
    deleteMatches();
}

void BadmintonTournament::printPlayer(int id)
{
    for(Player& p : players) {
        if(p.getId() == id)
        {
            p.printPlayer();
            return;
        }
    }
    cout << "PLAYER NOT FOUND!" << endl;
}

void BadmintonTournament::clearTournament()
{
    players.clear();
    eliminated.clear();
    deleteMatches();
    actualRound = 0;
}

void BadmintonTournament::printTournament()
{
    if (actualRound != 1)
    {
        cout << "THIS TOURNAMENT IS NOT OVER YET!" << endl;
        return;
    }

    cout << endl;
    cout << "Printing the outcome of the " << tournamentName << " Tournament!" << endl;
    cout << "All the contestants competed well and bravely, however The Winner is only one." << endl << endl;
    cout << "THE WINNER IS!!!" << endl;
    players.front().printPlayer(); cout << endl;
    cout << "Second place!" << endl;
    eliminated.front().printPlayer(); cout << endl << endl;
    eliminated.pop_front();
    cout << "Best of the rest!" << endl << endl;
    for (auto& p : eliminated)
    {
        p.printPlayer();
        cout << endl;
    }
}

bool BadmintonTournament::checkNumberOfPlayers()
{
    if (players.size() == 2 || players.size() == 4 || players.size() == 8 || players.size() == 16 || players.size() == 32)
        return true;
    else
        cout << "Function checkNumberOfPlayers: Wrong number of players" << endl << endl;
        return false;
}

string BadmintonTournament::getTournamentName()
{
    return tournamentName;
}