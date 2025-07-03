#include <iostream>
#include <random>

using namespace std;

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 100);

    int random_num = distrib(gen);

    cout << "-------- Welcome to the Guess Game --------" << endl;
    cout << "-------- Computer will pick a number between 1 to 100 --------" << endl;
    cout << "-------- You have to guess that number in 6 attempts --------" << endl;
    cout << "-------- Let's start the game --------" << endl;

    int attempt = 0;
    int guess;

    while (attempt < 6)
    {
        cout << "Attempt : " << attempt + 1 << endl;
        bool flag = false;

        while (!flag)
        {
            cout << "Enter your guess : ";
            cin >> guess;

            if (guess > 100 || guess < 1)
            {
                cout << "Please enter a valid guess (1-100)" << endl;
            }
            else
                flag = true;
        }

        attempt++;

        if (guess == random_num)
        {
            cout << "You guessed the right number in " << attempt << " attempts!" << endl;
            cout << "Congratulations! You won the game!" << endl;
            return 0;
        }
        else if (guess > random_num)
        {
            cout << "The number is lower than your guess" << endl;
        }
        else
        {
            cout << "The number is higher than your guess" << endl;
        }
    }

    cout << "Attempts Exhausted" << endl;
    cout << "You Lost! The number was: " << random_num << endl;
    cout << "Try Again, Good luck!" << endl;

    return 0;
}