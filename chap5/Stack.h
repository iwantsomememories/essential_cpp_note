#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Stack{
    public:
        virtual ~Stack(){}

        bool pop(int &elem);
        bool push(const int &elem);
        int size() const { return _top+1; }
        bool empty() const { return size() == 0;}
        bool full() const{ return _elems.size() == max_size; }
        virtual bool peek(int &elem) const;
        virtual void print(ostream &os = cout) const;

        virtual string getType() const = 0;
    
    protected:
        vector<int> _elems;
        int _top;
        const static int max_size = 1024;
};

class LIFO_Stack : public Stack {
    public:
        LIFO_Stack(){
            _top = -1;
        }

        virtual ~LIFO_Stack(){}

        virtual string getType() const;

};

class Peekback_Stack : public Stack {
    public:
        Peekback_Stack(){
            _top = -1;
        }

        virtual ~Peekback_Stack(){}

        virtual bool peek(int &elem, int index) const;

        virtual bool peek(int &elem) const;

        virtual string getType() const;

};

ostream &operator<<(ostream &os, const Stack &s);

#endif