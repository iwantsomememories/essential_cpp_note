#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include <iterator>

using namespace std;

void initialize_exclusion_set(set<string> &);
void process_file(map<string, int>&, const set<string>&, ifstream& );
void user_query(const map<string, int>& );
void display_word_count(const map<string, int>&, ofstream& );

int main(int argc, char const *argv[])
{
    if (argc < 3)
    {
        cerr << "correct format: ./3-1.o [in_file_name] [out_file_name].\n";
        exit(1);
    }

    string in_file_name = argv[1];
    string out_file_name = argv[2];
    ifstream in_file(in_file_name);
    ofstream out_file(out_file_name);

    if (!in_file || !out_file)
    {
        cerr << "unable to open the necessary files!\n";
        exit(1); 
    }

    set<string> word_exclusion;
    map<string, int> words_list;

    initialize_exclusion_set(word_exclusion);
    process_file(words_list, word_exclusion, in_file);
    user_query(words_list);
    display_word_count(words_list, out_file);

    return 0;
}

void initialize_exclusion_set(set<string> &exclusion_set){
    static string _excluded_words[6] = {"a", "an", "or", "the", "and", "but"};

    exclusion_set.insert(_excluded_words, _excluded_words+6);
    return;
}

void process_file(map<string, int>& wc, const set<string>& exs, ifstream& ifs){
    string word;
    while (ifs >> word)
    {
        if(exs.count(word))
            continue;
        wc[word]++;
    }
    return;
}

void user_query(const map<string, int>& wc){
    string word;
    cout << "Please enter a word to search: q to quit";
    cin >> word;
    while (word.size() && word != "q")
    {
        map<string, int>::const_iterator it;
        if ((it = wc.find(word)) != wc.end())
        {
            cout << "Found! " << it->first
                << " occurs " << it->second
                << " times.\n";
        } else
        {
            cout << word
                << " was not found in text.\n";
        }
        cout << "Another search?(q to quit)\n";
        cin >> word;
    }
    return;
}

void display_word_count(const map<string, int>& wc, ofstream& ofs){
    map<string, int>::const_iterator it = wc.begin(), end = wc.end();

    while (it != end)
    {
        ofs << "word: " << it->first
            << " , count: " << it->second
            << endl;
        it++;
    }
    return;
}

