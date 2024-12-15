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
    switch(incorrectGuess) {
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

int update(char userGuess, char arr[], int length, const char* chosen, int &incorrectGuess,int &noOfCorrectGuess) {
    bool found = false;
    for(int i = 0; chosen[i] != '\0'; i++){
        if(userGuess == chosen[i]){
            arr[i] = chosen[i];
            found = true;
            noOfCorrectGuess++;
        }
        
    }
    if(found == false){
        incorrectGuess++;
    }
    return 0;
}

int display(int incorrectGuess, char arr[], int length, char &userGuess) {
    cout << "INCORRECT GUESSES: " << incorrectGuess << "\n";
    for (int i = 0; i < length; i++) {
        cout << arr[i];
    }
    cout<<"\n";
    hangMan(incorrectGuess);
    
    cout << "Enter a Guess: ";
    cin >> userGuess;

    return userGuess;
}

void checkInput(char userGuess, char arr[], char incorrectChar[], int noOfCorrectGuess){
    for(int i = 0; i < 11; i++){
        if(userGuess == incorrectChar[i] || userGuess == arr[i]){
            noOfCorrectGuess--;
        };
    }
}

int main() {
    srand(time(NULL));
    const char* chosen = chosenCountry(countries, 20);
    int length = strlen(chosen);
    char arr[length + 1];  //  dash display
    char* incorrectChar[12];
    int incorrectGuess = 0 , noOfCorrectGuess = 0;   //counts no of correct and incorrect entries
    char userGuess = ' ';       //user input

    for (int i = 0; i < length; i++) {     //  _ _ _ _ _ display

        arr[i] = '_';
        incorrectChar[i] = "_";
    }
    arr[length] = '\0';
    while(incorrectGuess < 11 && noOfCorrectGuess != length){
    	
		
        clearScreen();
        userGuess = display(incorrectGuess, arr, length, userGuess);
        checkInput(userGuess,arr,*incorrectChar,noOfCorrectGuess);
        update(userGuess, arr, length, chosen, incorrectGuess,noOfCorrectGuess);
        
        if(noOfCorrectGuess == length){
    	clearScreen();
    	cout<<"Congratulations! You won...";
	}else if(incorrectGuess >= 11){
		cout<<"You Lost!  The correct name was "<<chosen;
	}
   
    }
    
    
    return 0;
}
