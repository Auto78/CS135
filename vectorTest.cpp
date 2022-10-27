#include <iostream>
#include <vectors>

using namespace std;

int main()
{
    int value = 0;
    vector<int> fibonnaci;
    cout << "Enter a value";
    cin >> value;

    for (it i = 0; i < value; i++)
    {
        (i == 0 || i == 1) fibonnaci.push_back(1) : fibonnaci.push_back(fibonnaci.at(i - 1) + fibonnaci.at(i - 2))
    }
    for (unsigned i = 0; i < fibonacci.size(); i++)
    {
        cout << " Fibonacci: " << i << ":" << fibonacci.at(i) << endl;
    }
}