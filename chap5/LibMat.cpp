#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class LibMat {
public:
	LibMat(){
		cout << "LibMat::LibMat() default constructor!\n";
	}
	
	virtual ~LibMat(){
		cout << "LibMat::~LibMat() destructor!\n";
	}

	virtual void print() const {
		cout << "LibMat::print() -- I am a LibMat object!\n";
	}
};

class Magazine : public LibMat {
public:
    Magazine(const string &title, const int &volume)
    : _title(title), _volume(volume){
        cout << "Magazine::Magazine( " << _title << ", " 
            << _volume << " ) constructor\n";
    }

    virtual ~Magazine(){
        cout << "Magazine::~Magazine() destructor\n";
    }

    virtual void print() const{
        cout << "My title is: " << _title << '\n'
            << "My volume is: " << _volume <<endl;
    }

    const string& title() const { return _title; }
	const int& author() const { return _volume; }

protected:
    string _title;
    int _volume;
};

void print( const LibMat &mat )
{
	cout << "in global print(): about to print mat.print()\n";
	mat.print();
}

int main()
{

	// objects are in local blocks to force destruction
	{   
        cout << "\n" << "Creating a LibMat object to print()\n";
  	    LibMat m;
	    print( m );
	}

	{
        cout << "\n" << "Creating a Magazine object to print()\n";
	    Magazine b( "The Castle", 10 );
	    print( b );
	}

	return 0; // unnecessary but quiets vc++
}