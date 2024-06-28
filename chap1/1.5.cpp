#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string user_name;
    cout << "Please enter your name: ";
    cin >> user_name;
    if(user_name.size() > 2){
        cout << "Hello, "
            << user_name
            << ".\n";
    } else
        cout << "Invalid input.\n";
    return 0;
}
