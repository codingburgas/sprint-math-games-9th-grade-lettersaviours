#include <iostream>
#include <string>
using namespace std;

int main() {

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
            cout << "Well done! You guessed the word!" << endl;
            return 0;
        }
    }

    cout << "Out of attempts! The word was: " << word << endl;
}
