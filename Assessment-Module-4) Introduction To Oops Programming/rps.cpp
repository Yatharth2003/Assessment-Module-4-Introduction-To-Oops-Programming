#include <iostream>
#include <cstdlib>   // For rand(), srand()
#include <ctime>     // For time()
using namespace std;

// Class containing game logic
class RPSGame {
public:

    // Function to run the game (called by object)
    void playGame() {

        string name;
        int rounds;

        // Accept player name
        cout << "Enter your Name: ";
        cin >> name;

        // Ask number of rounds
        cout << "Enter number of rounds to play: ";
        cin >> rounds;

        int userChoice, compChoice;
        int userScore = 0, compScore = 0;

        cout << "\n===== Rock Paper Scissors Game =====\n";
        cout << "1. Rock\n2. Paper\n3. Scissor\n";
        cout << "====================================\n";

        // Seed random number generator
        srand(time(0));

        // Loop for each round
        for (int r = 1; r <= rounds; r++) {

            cout << "\nThis is Round " << r << endl;

            // Ask user choice
            cout << "Select your Choice (1 = Rock, 2 = Paper, 3 = Scissor): ";
            cin >> userChoice;

            // Generate computer choice
            compChoice = (rand() % 3) + 1;

            // Display choices
            cout << name << " selected: " << userChoice << endl;
            cout << "Computer selected: " << compChoice << endl;

            // Game logic using conditional statements
            if (userChoice == compChoice) {
                cout << "Result: Draw!" << endl;
            }
            else if ((userChoice == 1 && compChoice == 3) ||
                     (userChoice == 2 && compChoice == 1) ||
                     (userChoice == 3 && compChoice == 2)) {

                cout << "Result: " << name << " Wins this round!" << endl;
                userScore++;
            }
            else {
                cout << "Result: Computer Wins this round!" << endl;
                compScore++;
            }
        }

        // Final Result Summary
        cout << "\n===== Final Score =====\n";
        cout << name << ": " << userScore << endl;
        cout << "Computer: " << compScore << endl;

        if (userScore > compScore)
            cout << "\nOverall Winner: " << name << endl;
        else if (compScore > userScore)
            cout << "\nOverall Winner: Computer" << endl;
        else
            cout << "\nMatch Result: Draw" << endl;
    }
};

int main() {

    // Create object
    RPSGame game;

    // Invoke function using object
    game.playGame();

    return 0;
}
