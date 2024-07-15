#include <iostream>
#include <vector>
#include "Stack.h"

using namespace std;

int main(int argc, char const *argv[])
{
    LIFO_Stack ls;
    int num;
    cout << ls;
    ls.push(1);
    ls.push(2);
    ls.push(3);
    ls.push(4);
    ls.push(5);

    cout << ls;

    ls.peek(num);

    cout << num << endl;

    cout << ls;

    ls.pop(num);
    cout << num << endl;

    cout << ls;
    return 0;
}
