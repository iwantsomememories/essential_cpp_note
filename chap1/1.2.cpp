#include <iostream>
#include <string>
using namespace std;

int my_main(int argc, char const *argv[])
{
    string user_name;
    cout << "Please enter your name: ";
    cin >> user_name;
    cout << '\n'
        << "Hello, "
        << user_name
        << ". Calm down.\n";    
    return 0;
}

