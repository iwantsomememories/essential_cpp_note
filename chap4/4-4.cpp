#include <iostream>
#include <string>
#include <map>
#include <cstdlib>

using namespace std;

class UserProfile{
public:    
	enum uLevel { Beginner, Intermediate, Advanced, Guru };

    UserProfile( string login, uLevel = Beginner );
    UserProfile();

    // default memberwise initialization and copy sufficient
    // no explicit copy constructor or copy assignment operator
    // no destructor necessary ...

    bool operator==( const UserProfile& );
    bool operator!=( const UserProfile &rhs );

    // read access functions 
    string login() const { return _login; }
    string user_name() const { return _user_name; }
    int login_count() const { return _times_logged; }
    int guess_count() const { return _guesses; }
    int guess_correct() const { return _correct_guesses; }
    double guess_average() const;
    string level() const;

    // write access functions
    void reset_login( const string &val ){ _login = val; }
    void user_name( const string &val ){ _user_name = val; }

    void reset_level( const string& );
    void reset_level( uLevel newlevel ) { _user_level = newlevel; }

	void reset_login_count( int val ){ _times_logged = val; }
    void reset_guess_count( int val ){ _guesses = val; }
    void reset_guess_correct( int val ){ _correct_guesses = val; }

    void bump_login_count( int cnt=1 ){ _times_logged += cnt; }
    void bump_guess_count( int cnt=1 ){ _guesses += cnt; }
    void bump_guess_correct(int cnt=1){ _correct_guesses += cnt;}

 private:
   
    // static string guest_login();

    string _login;
    string _user_name;
    int    _times_logged;
    int    _guesses;
    int    _correct_guesses;  
    uLevel _user_level;

    static map<string,uLevel> _level_map;
    static void init_level_map();
};

inline UserProfile::UserProfile(string login, uLevel level)
    : _login(login), _user_level( Beginner),
      _times_logged(1), _guesses(0), _correct_guesses(0)
{}

inline UserProfile::UserProfile()
    : _user_level( Beginner),
      _times_logged(1), _guesses(0), _correct_guesses(0)
{
    string login_name = "guest";
    static int id = 0;
    id++;
    login_name += to_string(id);
    _login = login_name;
}

inline bool UserProfile::operator==( const UserProfile &rhs)
{
    return ( _login == rhs._login && _user_name == rhs._user_name);
}

inline bool UserProfile::operator!=( const UserProfile &rhs)
{
    return !(*this == rhs);
}

inline double UserProfile::guess_average() const
{
    return _guesses ? double(_correct_guesses)/_guesses * 100 : 0.0;
}

inline string UserProfile::level() const
{
    static string _level_table[] = {
        "Beginner", "Intermediate", "Advanced", "Guru"
    };
    return _level_table[ _user_level ];
}

ostream& operator<<( ostream &os, const UserProfile &rhs)
{
    os << rhs.login() << ' '
       << rhs.level() << ' '
       << rhs.login_count() << ' '
       << rhs.guess_count() << ' '
       << rhs.guess_correct() << ' '
       << rhs.guess_average() << endl;

    return os;
}

map<string,UserProfile::uLevel> UserProfile::_level_map;

inline void UserProfile::init_level_map(){
    _level_map[ "Beginner" ] = Beginner;
    _level_map[ "Intermediate" ] = Intermediate;
    _level_map[ "Advanced" ] = Advanced;
    _level_map[ "Guru" ] = Guru;
}

inline void UserProfile::reset_level(const string &level)
{
    if (_level_map.empty())
    {
        init_level_map();
    }

    map<string, uLevel>::iterator it;
    _user_level = (( it = _level_map.find(level) ) != _level_map.end()) ?
        it->second : Beginner;
}

istream& operator>>( istream &is, UserProfile &rhs)
{
    string login, level;
    is >> login >> level;

    int lcount, gcount, gcorrect;
    is >> lcount >> gcount >> gcorrect;

    rhs.reset_login( login );
    rhs.reset_level( level );

    rhs.reset_login_count( lcount );
    rhs.reset_guess_count( gcount );
    rhs.reset_guess_correct(gcorrect);

    return is;
}

void test()
{
    UserProfile anon;
	cout << anon;

	UserProfile anon_too;
	cout << anon_too;

	UserProfile anna( "AnnaL", UserProfile::Guru );
	cout << anna;

	anna.bump_guess_count( 27 );
	anna.bump_guess_correct( 25 );
	anna.bump_login_count();

	cout << anna;

	cout << "OK: enter user profile data by hand to see if we can read it\n";
	cin >> anon;
	cout << anon;
}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}




