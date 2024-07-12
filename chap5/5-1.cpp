#include <iostream>
#include <vector>

using namespace std;

class Stack{
    public:
        virtual ~Stack(){};

        virtual bool pop(int &elem) = 0;
        virtual bool push(const int &elem) = 0;
        virtual int size() = 0;
        bool empty() { return size() == 0;}
        virtual bool full() = 0;
        virtual bool peek(int &elem) = 0;
        virtual void print(ostream &os = cout) = 0;
};

class LIFO_Stack : public Stack {
    public:
        LIFO_Stack(){
            _top = -1;
        }

        virtual int size() { return _elems.size(); }

        virtual bool full() { return _elems.size() == max_size; }

        

    protected:
        vector<int> _elems;
        int _top;
        const static int max_size = 1024;
};