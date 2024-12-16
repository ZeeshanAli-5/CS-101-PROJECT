#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

const char* countries[20] = {"argentina", "australia", "brazil", "canada", "china", "france", "germany", "india", "indonesia", "italy", "japan", "mexico", "russia", "saudiarabia", "southafrica", "southkorea", "turkey", "unitedkingdom", "usa", "europeanunion"};

const char* chosenCountry(const char* array[], int size) {
    int temp = rand() % size;
    return array[temp];
}

void clearScreen() {
#ifdef _WIN32
    system("cls"); // For Windows
#else
    system("clear"); // For Linux and macOS
#endif
}

void hangMan(int incorrectGuess) {
    switch (incorrectGuess) {
        case 0: cout << "\n\n\n\n\n"; break;
        case 1: cout << "\n\n\n\n\n____\n"; break;
        case 2: cout << "\n |\n |\n |\n |\n____\n"; break;
        case 3: cout << " _______\n |\n |\n |\n |\n____\n"; break;
        case 4: cout << " _______\n |     |\n |\n |\n |\n____\n"; break;
        case 5: cout << " _______\n |     |\n |     O\n |\n |\n____\n"; break;
        case 6: cout << " _______\n |     |\n |     O\n |     |\n |\n____\n"; break;
        case 7: cout << " _______\n |     |\n |     O\n |    /|\n |\n____\n"; break;
        case 8: cout << " _______\n |     |\n |     O\n |    /|\\\n |\n____\n"; break;
        case 9: cout << " _______\n |     |\n |     O\n |    /|\\\n |    /\n____\n"; break;
        case 10: cout << " _______\n |     |\n |     O\n |    /|\\\n |    / \\\n____\n"; break;
    }
}

void update(char userGuess, char arr[], const char* chosen, int& incorrectGuess, int& noOfCorrectGuess) {
    bool found = false;
    for (int i = 0; chosen[i] != '\0'; i++) {
        if (userGuess == chosen[i]) {
            if (arr[i] == '_') {
                arr[i] = chosen[i];
                noOfCorrectGuess++;
            }
            found = true;
        }
    }
    if (!found) {
        incorrectGuess++;
    }
}

void display(int incorrectGuess, char arr[], int length) {
    cout << "INCORRECT GUESSES: " << incorrectGuess << "\n";
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    hangMan(incorrectGuess);
}

int main() {
    srand(time(NULL));
    const char* chosen = chosenCountry(countries, 20);
    int length = strlen(chosen);
    char arr[length + 1];  // Dash display
    char incorrectChar[12] = {'\0'};  // Tracks incorrect guesses
    int incorrectGuess = 0, noOfCorrectGuess = 0;  // Counts no of correct and incorrect entries
    char userGuess = ' ';  // User input

    for (int i = 0; i < length; i++) {
        arr[i] = '_';  // Initialize the word display with dashes
    }
    arr[length] = '\0';

    while (incorrectGuess < 11 && noOfCorrectGuess != length) {
        clearScreen();
        display(incorrectGuess, arr, length);
        cout << "Enter a guess: ";
        cin >> userGuess;

        update(userGuess, arr, chosen, incorrectGuess, noOfCorrectGuess);
    }

    clearScreen();
    if (noOfCorrectGuess == length) {
        cout << "Congratulations! You won!\n";
    } else {
        cout << "You lost! The correct name was: " << chosen << "\n";
    }

    return 0;
}
