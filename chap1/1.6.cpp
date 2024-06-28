#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vec;
    int num;
    while (cin >> num)
    {
        vec.push_back(num);
    }

    int sum = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        sum += vec[i];
    }

    float average = (float)sum/vec.size();

    cout << "Sum of " << vec.size()
        << " elements: " << sum
        << ". Average: " << average << endl;
    return 0;
}
