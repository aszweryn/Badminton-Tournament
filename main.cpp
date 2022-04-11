#include "tournament.h"

int main()
{
    string TournamentName;
    cout << "Welcome to the Badminton Tournament simulation!" << endl;
    cout << "Please insert the name of the Tournament: ";
    cin >> TournamentName;
    BadmintonTournament BT(TournamentName);

    int option = 1;
    do {
        cout << "Select an option:" << endl;
        cout << "1 - Add Player" << endl;
        cout << "2 - Print Player" << endl;
        cout << "3 - Next Round" << endl;
        cout << "4 - Print Tournament Results" << endl;
        cout << "5 - Testing" << endl;
        cout << "0 - Exit" << endl;
        cout << "---------------------------------------" << endl;
        cin >> option;

        switch (option) {
            default:
                continue;
            case 1: {
                int idp;
                string pname;
                cout << "Player's name: ";
                cin >> pname;
                while(cout << "Player's id: " && !(cin >> idp)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input, try again." << endl;
                }
                Player x(idp, pname);
                BT.addPlayer(x);
                cout << endl;
                break;
            }
            case 2: {
                int pid;
                while(cout << "To print a Player please insert Player id:" && !(cin >> pid)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input, try again." << endl;
                }
                BT.printPlayer(pid);
                cout << endl;
                break;
            }
            case 3: {
                if(!BT.checkNumberOfPlayers())
                {
                    cout << "Wrong number of players" << endl;
                    cout << "Add more players or use Print Tournament Outcome option." << endl;
                    break;
                }
                BT.generateMatches();
                BT.printRound();
                BT.finishRound();
                break;
            }
            case 4: {
                BT.printTournament();
                break;
            }
            case 5: {
                BT.clearTournament();
                Player a(1, "John");
                Player b(2, "Wiktor");
                Player c(3, "Roman");
                Player d(4, "Natalia");
                Player e(5, "Marcel");
                Player f(6, "Artur");
                Player g(7, "Igor");
                Player i(9, "Alexandra");
                Player h(8, "Julian");
                Player j(10, "Damian");
                Player k(11, "Nicolas");
                Player l(12, "Duke");
                Player m(13, "Bart");
                Player o(14, "Pablo");
                Player p(15, "Zbigniew");
                Player r(16, "Mike");
                BT.addPlayer(a);
                BT.addPlayer(b);
                BT.addPlayer(c);
                BT.addPlayer(d);
                BT.addPlayer(e);
                BT.addPlayer(f);
                BT.addPlayer(g);
                BT.addPlayer(h);
                BT.addPlayer(i);
                BT.addPlayer(j);
                BT.addPlayer(k);
                BT.addPlayer(l);
                BT.addPlayer(m);
                BT.addPlayer(o);
                BT.addPlayer(p);
                BT.addPlayer(r);
                cout << "Printing player using Player.getId() method" << endl;
                BT.printPlayer(a.getId()); cout << endl;
                cout << "Printing player with id equal to 4" << endl;
                BT.printPlayer(4); cout << endl;
                cout << "Using method checkNumberOfPlayers to check if the tournament can happen" << endl;
                BT.checkNumberOfPlayers();
                cout << "1/8 Round" << endl;
                BT.generateMatches();
                BT.printRound();
                BT.finishRound();
                cout << "Quarterfinal" << endl;
                BT.generateMatches();
                BT.printRound();
                BT.finishRound();
                cout << "Semifinal!" << endl;
                BT.generateMatches();
                BT.printRound();
                BT.finishRound();
                cout << "Final!!!" << endl;
                BT.generateMatches();
                BT.printRound();
                BT.finishRound();
                cout << "Checking what happens if we would want to proceed with just one player left in the players list" << endl;
                BT.generateMatches();
                BT.finishRound();
                BT.printTournament();
                break;
            }
        }

    } while (option != 0);
}