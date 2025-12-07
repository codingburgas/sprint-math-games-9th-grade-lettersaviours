#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << " __ __   ____  ____    ____  ___ ___   ____  ____  \n";
    cout << "|  |  | /    ||    \\  /    ||   |   | /    ||    \\ \n";
    cout << "|  |  ||  o  ||  _  ||   __|| _   _ ||  o  ||  _  |\n";
    cout << "|  _  ||     ||  |  ||  |  ||  \\_/  ||     ||  |  |\n";
    cout << "|  |  ||  _  ||  |  ||  |_ ||   |   ||  _  ||  |  |\n";
    cout << "|  |  ||  |  ||  |  ||     ||   |   ||  |  ||  |  |\n";
    cout << "|__|__||__|__||__|__||___,_||___|___||__|__||__|__|\n";
    cout << "                                                   \n";

    // Hangman states stored in string array
    const string hangman[] = 
    {
    "  .---.\n"
    "  |   |\n"
    "      |\n"
    "      |\n"
    "      |\n"
    "______|\n",

    "  .---.\n"
    "  |   |\n"
    "  O   |\n"
    "      |\n"
    "      |\n"
    "______|\n",

    "  .---.\n"
    "  |   |\n"
    "  O   |\n"
    "  |   |\n"
    "      |\n"
    "______|\n",

    "  .---.\n"
    "  |   |\n"
    "  O   |\n"
    " /|   |\n"
    "      |\n"
    "______|\n",

    "  .---.\n"
    "  |   |\n"
    "  O   |\n"
    " /|\\  |\n"
    "      |\n"
    "______|\n",

    "  .---.\n"
    "  |   |\n"
    "  O   |\n"
    " /|\\  |\n"
    " /    |\n"
    "______|\n",

    "  .---.\n"
    "  |   |\n"
    "  O   |\n"
    " /|\\  |\n"
    " / \\  |\n"
    "______|\n"
    };



    string wordList[30] =
    {
        "syntax",  "puzzle",  "galaxy",
        "castle",  "harbor",  "shadow",
        "planet",  "rocket",  "hunter",
        "forest",  "silver",  "beacon",
        "mirror",  "dragon",  "stream",
        "anchor",  "throne",  "ribbon",
        "temple",  "quartz",  "stormy",
        "spirit",  "summit",  "fabric",
        "valley",  "memory",  "magnet",
        "meadow",  "refuge",  "bright"
    };

    int choice = 0; // Hold the number the player chooses
    while (choice < 1 || choice > 30)
    {
        cout << "Choose a number between (1-30): ";
        cin >> choice;
        if (choice < 1 || choice > 30)
        {
            cout << "You must enter a valid number between 1-30." << endl;
            if (!(cin >> choice)) // Stop if input is not a number
            {
                cout << "Invalid input. You can use only numbers! Program will exit." << endl;
                return 0; // Exit the program to prevent the input loop from repeating endlessly
            }
        }
    }

    string word = wordList[choice - 1];
    string guessedWord = "_ _ _ _ _ _";
    int fails = 0;
    int maxFails = 6;

    // Main game loop
    while (fails < maxFails)
    {
        cout << guessedWord << endl;
        char guess;
        cout << "Guess a letter: ";
        cin >> guess;

        bool correct = false;
        for (int i = 0; i < 6; i++)  // Check each letter to see if it matches the guess
        {
            if (word[i] == guess)
            {
                guessedWord[i * 2] = guess; // Put the guessed letter in the right spot in the display
                correct = true;
            }
        }

        // Increment fail count and display the hangman for a wrong guess
        if (!correct)
        {
            fails++;
            cout << "Wrong! Attempts left: " << maxFails - fails << endl;
            cout << hangman[fails] << endl;
        }

        // Check if player has guessed the full word
        bool won = true;
        for (char c : guessedWord)
        {
            if (c == '_') // If there’s still an unguessed letter
            {
                won = false;
                break; // Stop the game after winning
            }
        }

        if (won)
        {
            cout << guessedWord << endl;
            cout << " __ __   ___   __ __         __    __   ___   ____  \n";
            cout << "|  |  | /   \\ |  |  |       |  |__|  | /   \\ |    \\ \n";
            cout << "|  |  ||     ||  |  |       |  |  |  ||     ||  _  |\n";
            cout << "|     ||  O  ||  |  |       |  |  |  ||  O  ||  |  |\n";
            cout << "|___, ||     ||  :  |       |  `  '  ||     ||  |  |\n";
            cout << "|     ||     ||     |        \\      / |     ||  |  |\n";
            cout << "|____/  \\___/  \\__,_|         \\_/\\_/   \\___/ |__|__|\n";
            cout << "Well done! You guessed the word!" << endl;
        }
    }

    cout << " __ __   ___   __ __         _       ___   _____ ______ \n";
    cout << "|  |  | /   \\ |  |  |       | |     /   \\ / ___/|      |\n";
    cout << "|  |  ||     ||  |  |       | |    |     (   \\_ |      |\n";
    cout << "|     ||  O  ||  |  |       | |___ |  O  |\\__  ||_|  |_|\n";
    cout << "|___, ||     ||  :  |       |     ||     |/  \\ |  |  |  \n";
    cout << "|     ||     ||     |       |     ||     |\\    |  |  |  \n";
    cout << "|____/  \\___/  \\__,_|       |_____| \\___/  \\___|  |__|  \n";
    cout << "Out of attempts! The word was: " << word << endl;
}