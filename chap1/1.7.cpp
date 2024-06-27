#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    ifstream infile("words.txt");
    if(!infile){
        cerr << "infile open failed\n";
        return -1;
    }

    ofstream outfile("sorted_words.txt");
    if(!outfile){
        cerr << "outfile open failed\n";
        return -2;
    }

    string word;
    vector<string> vec;
    while(infile >> word)
        vec.push_back(word);
    
    int ix;
    cout << "unsorted text: \n";

    for(ix = 0; ix < vec.size(); ++ix)
        cout << vec[ix] << ' ';
    cout << endl;

    sort(vec.begin(), vec.end());

    outfile << "sorted text: \n";
    for(ix = 0; ix < vec.size(); ++ix)
        outfile << vec[ix] << ' ';
    outfile << endl;

    return 0;
}
