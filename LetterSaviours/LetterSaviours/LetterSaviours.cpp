#include <iostream>
#include <string>
using namespace std;

int main() {

    cout << " __ __   ____  ____    ____  ___ ___   ____  ____  \n";
    cout << "|  |  | /    ||    \\  /    ||   |   | /    ||    \\ \n";
    cout << "|  |  ||  o  ||  _  ||   __|| _   _ ||  o  ||  _  |\n";
    cout << "|  _  ||     ||  |  ||  |  ||  \\_/  ||     ||  |  |\n";
    cout << "|  |  ||  _  ||  |  ||  |_ ||   |   ||  _  ||  |  |\n";
    cout << "|  |  ||  |  ||  |  ||     ||   |   ||  |  ||  |  |\n";
    cout << "|__|__||__|__||__|__||___,_||___|___||__|__||__|__|\n";
    cout << "                                                   \n";
    const string hangman[] = {
        "  +---+\n"
        "  |   |\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "=========\n",

        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "=========\n",

        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        "  |   |\n"
        "      |\n"
        "      |\n"
        "=========\n",

        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|   |\n"
        "      |\n"
        "      |\n"
        "=========\n",

        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|\\  |\n"
        "      |\n"
        "      |\n"
        "=========\n",

        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|\\  |\n"
        " /    |\n"
        "      |\n"
        "=========\n",

        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|\\  |\n"
        " / \\  |\n"
        "      |\n"
        "=========\n"
    };

    string word = "syntax";
    string guessedWord = "_ _ _ _ _ _";
    int fails = 0;
    int maxFails = 6;

    while (fails < maxFails)
    {
        cout << guessedWord << endl;
        char guess;
        cout << "Guess a letter: ";
        cin >> guess;

        bool correct = false;
        for (int i = 0; i < 6; i++)
        {
            if (word[i] == guess)
            {
                guessedWord[i * 2] = guess;
                correct = true;
            }
        }

        if (!correct)
        {
            fails++;
            cout << "Wrong! Attempts left: "
                << maxFails - fails << endl;
            cout << hangman[fails] << endl;
        }

        bool won = true;
        for (char c : guessedWord)
        {
            if (c == '_') {
                won = false;
                break;
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
            return 0;
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
