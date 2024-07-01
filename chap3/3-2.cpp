#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>

using namespace std;

class StringSort{
public:
    bool operator() (const string &str1, const string &str2) {
        return str1.size() < str2.size();
    }
};

void process_file(vector<string> &, ifstream &, StringSort &);
void display_words(const vector<string> &);

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        cerr << "correct format: ./3-2.o [in_file_name].\n";
        exit(1);
    }

    string in_file_name = argv[1];
    ifstream in_file(in_file_name);
    vector<string> word_vector;
    StringSort strsort;

    if (!in_file)
    {
        cerr << "unable to open the necessary files!\n";
        exit(1); 
    }

    process_file(word_vector, in_file, strsort);
    display_words(word_vector);
    return 0;
}

void process_file(vector<string> &vec, ifstream &ifs, StringSort &ss){
    string word;
    while (ifs >> word)
    {
        vec.push_back(word);
    }
    sort(vec.begin(), vec.end(), ss);
}

void display_words(const vector<string> &vec){
    cout << "words list: ";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "\n" << vec[i] ;
    }
    cout << endl;
}

