#include "Stack.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    Stack s;
    string str;

    cout << "Please enter some strings\n";
    while (cin >> str && !s.full())
    {
        s.push(str);
    }

    if (s.empty())
    {
        cout << "\n" << "Oops: no strings were read.\n";
        return 0;
    }

    s.peek(str);
    if(s.size()==1 && str.empty()){
        cout << "\n" << "Oops: no strings were read.\n";
        return 0;
    }
    cout << "\n" << "Read in " << s.size() << "strings.\n"
        << "The strings, in reverse order: \n";

    while (!s.empty())
    {
        if (s.pop(str))
        {
            cout << str << "\n";
        }
    }

    cout << "There are now " << s.size()
        << " elements in the Stack.\n";
    
    return 0;
}

