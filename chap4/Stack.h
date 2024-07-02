#include <string>
#include <vector>

using namespace std;

class Stack
{
private:
    std::vector<std::string> _stack;
public:
    bool push(const std::string &);
    bool pop(std::string &);
    bool peek(std::string &);
    bool find(const std::string &);
    int count(const std::string &);

    bool empty() {return _stack.empty();}
    bool full() {return  _stack.size() == _stack.max_size();}

    int size() {return _stack.size();}
};

