
#include <iostream>
using namespace std;

int main()
{
    int n, i = 2;
    cout << "Enter your Number." << endl;
    cin >> n;

    bool isPrime = true; // Assume prime initially

    while (i <= (n / 2))
    { // Only check up to n/2
        if (n % i == 0)
        {
            cout << "The Number is Not Prime." << endl;
            isPrime = false; // Set to false if divisor found
            break;           // Exit loop
        }
        i += 1;
    }

    if (isPrime)
    {
        cout << "The Number is prime." << endl;
    }

    return 0;
}
