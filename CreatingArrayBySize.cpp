// How to Create array from knowing its size.
#include <iostream>
using namespace std;
int *Func(int size)
{
    int *p;
    int i;
    p = new int(size);
    for (int i = 0; i < size; i++)
        p[i] = i + 1;
    return p;
}
int main()
{
    int *ptr, sz = 5;
    ptr = Func(sz);
    for (int i = 0; i < sz; i++)
    {
        cout << ptr[i] << endl;
    }

    return 0;
}
