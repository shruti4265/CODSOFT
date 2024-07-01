#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void task(int randomnumber) {
    int usernumber;
    while (true) {
        cout << "Enter your number if you are ready: ";
        cin >> usernumber;
        if (usernumber == randomnumber) {
            cout << "Congratulations, you won!\n";
            return;
        } else if (usernumber > randomnumber) {
            cout << "Your number is more than the original number\n";
        } else {
            cout << "Your number is less than the original number\n";
        }
    }
}

int main() {
    int randomnumber;
    srand(time(NULL));
    randomnumber = rand() % 100 + 1;
    
    cout << "WELCOME TO THE NUMBER GUESSING GAME!\n\n";
    cout << "Rules for the game:\n";
    cout << "1) A number will be generated from our side from 1 to 100 but will not be shown to you.\n";
    cout << "2) Your task is to guess that number.\n";
    cout << "3) If you guess a number less than the original number we would tell you that it is less than the original number.\n";
    cout << "4) If you guess a number more than the original number we would tell you that it is more than the original number.\n";
    cout << "5) If you guess the right number you will win.\n";
    cout << "6) You have unlimited guesses.\n\n";
    cout << "ALL THE BEST!!\n\n";

    task(randomnumber);
    return 0;
}
