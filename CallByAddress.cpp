
#include <iostream>
using namespace std;
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int a = 10;
    int b = 20;
    swap(&a, &b); // Call by Address to modified actual parameter.
    cout << "a= " << a << endl
         << "b= " << b << endl;

    return 0;
}