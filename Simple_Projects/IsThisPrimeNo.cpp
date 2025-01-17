
#include <iostream>
using namespace std;

int main()
{
    int number, i = 2;
    cout << "Enter your Number." << endl;
    cin >> number;

    bool isPrime = true; // Assume prime initially

    while (i <= (number / 2))
    { // Only check up to n/2
        if (number % i == 0)
        {
            cout << number << " is Not Prime." << endl;
            isPrime = false; // Set to false if divisor found
            break;           // Exit loop
        }
        i += 1;
    }

    if (isPrime)
    {
        cout << number << " is prime." << endl;
    }
    system("pause");
    return 0;
}
