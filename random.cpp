#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>

using namespace std;

const int ARRAY_SIZE = 10000;
const int MINIMUM_VALUE = 50;
const int MAXIMUM_VALUE = 1000;
int main()
{
    // Setting random random number every second(time(0))
    int sum = 0;
    int randomValue[ARRAY_SIZE];
    srand(time(0));
    cout << "10,000 random values between 50 and 1000: ";
    
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        randomValue[i] = rand() % (MAXIMUM_VALUE - MINIMUM_VALUE + 1) + MINIMUM_VALUE;
        sum += randomValue[i];
        cout << randomValue[i] << ",";
    }
    int maximum = randomValue[0];
    int minimum = randomValue[0];
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (randomValue[i] > maximum)
        {
            maximum = randomValue[i];
        }
        if (randomValue[i] < minimum)
        {
            minimum = randomValue[i];
        }
    }

    int average = 0;
    average = sum / ARRAY_SIZE;
    cout << "\nMinimum: " << minimum << endl;
    cout << "Maximum: " << maximum << endl;
    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;
}
