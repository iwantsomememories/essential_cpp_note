#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

void initialize_name_map(map<string, vector<string>> &);
void user_query(const map<string, vector<string>> &);

int main(int argc, char const *argv[])
{
    map<string, vector<string>> name;
    initialize_name_map(name);
    user_query(name);
    return 0;
}

void initialize_name_map(map<string, vector<string>> &name_map){
    static vector<string> Smith = {"Alice", "Bob", "Charlie"};
    static vector<string> Johnson = {"Emma", "Liam"};
    static vector<string> Williams = {"Sophia", "Mason", "Mia"};
    static vector<string> Brown = {"Olivia", "Lucas", "Isabella", "Ethan"};
    static vector<string> Jones = {"Ava", "Noah"};
    static vector<string> Davis = {"Emily", "Jacob", "Lily"};

    name_map["Smith"] = Smith;
    name_map["Johnson"] = Johnson;
    name_map["Williams"] = Williams;
    name_map["Brown"] = Brown;
    name_map["Jones"] = Jones;
    name_map["Davis"] = Davis;
}

void user_query(const map<string, vector<string>> &name_map){
    string surname;
    cout << "Please enter a surname to search(q to quit): ";
    cin >> surname;
    while (surname.size() && surname != "q")
    {
        map<string, vector<string>>::const_iterator it;
        if ((it = name_map.find(surname)) != name_map.end())
        {
            vector<string> name = it->second;
            cout << "Found! " << surname << " Family: \n";
            for (int i = 0; i < name.size(); i++)
            {
                cout << name[i] << " ";
            }
            cout << endl;
        } else
        {
            cout << surname
                << " was not found." << endl;
        }
        cout << "Another search?(q to quit): ";
        cin >> surname;
    }
}