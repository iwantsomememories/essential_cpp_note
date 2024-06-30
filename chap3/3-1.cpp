#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include <iterator>

using namespace std;

map<string, int> word_count(ifstream&, set<string>);

void initialize_exclusion_set(set<string> &);
void process_file(map<string, int>&, const set<string>&, ifstream& );
void user_query(const map<string, int>& );
void display_word_count(const map<string, int>&, ofstream& );

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        cerr << "correct format: ./3-1.cpp [file_name].\n";
        exit(1);
    }

    string file_name = argv[1];
    ifstream in_file(file_name);

    if (!in_file)
    {
        cerr << "unable to open the necessary files!\n";
        exit(1); 
    }

    set<string> word_exclusion = {"a", "an", "or", "the", "and", "but"};

    map<string, int> words_list = word_count(in_file, word_exclusion);

    map<string, int>::iterator it = words_list.begin();
    for (; it != words_list.end(); it++)
    {
        cout << "word: " << it->first << ", "
            << "count: " << it->second << endl;
    }

    return 0;
}

void initialize_exclusion_set(set<string> &exclusion_set){
    static string _excluded_words[6] = {"a", "an", "or", "the", "and", "but"};
    
}

map<string, int> word_count(ifstream &in_file, set<string> exclude_words){
    istream_iterator<string> is(in_file);
    istream_iterator<string> eof;

    map<string, int> words_list;

    while(is != eof){
        if(exclude_words.count(*is))
            continue;
        words_list[*is]++;
        is++;
    }

    return words_list;
}
