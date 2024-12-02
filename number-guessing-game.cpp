#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand((unsigned int)time(NULL));
    int num = (rand() % 100) + 1;

    int user_guess;

    while (user_guess != num)
    {
        cout << "Guess a number: (1-100) " << endl;
        cin >> user_guess;

        if (user_guess > num)
        {
            cout << "Your guess is higher, guess a low number." << endl;
        }
        else if (user_guess < num)
        {
            cout << "Your guess is lower, guess a high number." << endl;
        }
        else
        {
            cout << "You got it, You WON!!!" << endl;
        }
    }

    return 0;
}
