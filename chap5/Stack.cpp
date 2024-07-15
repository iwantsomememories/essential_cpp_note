#include "Stack.h"

bool Stack::pop(int &elem){
    if (empty())
    {
        return false;
    } 

    elem = _elems[_top];
    _top--;
    
    return true;
}

bool Stack::push(const int &elem){
    if (full())
    {
        return false;
    }

    if (_elems.size() == _top+1)
    {
        _elems.push_back(elem);
        _top++;
    } else {
        _top++;
        _elems[_top] = elem;
    }
    
    return true;
}

bool Stack::peek(int &elem) const{
    if (empty())
    {
        return false;
    } 

    elem = _elems[_top];

    return true;
}

void Stack::print(ostream &os /*= cout*/) const{
    if (empty())
    {
        os << "The " << getType() << " is empty." << endl;
        return;
    }

    os << "The content of the " << getType() << " is:" << '\n';
    for (int i = 0; i <= _top; i++)
    {
        os << _elems[i] << ' ';
        if (i % 8 == 0 && i > 0)
        {
            os << '\n';
        }
    }
    if(_top % 8 != 0) os << endl;     
}

string LIFO_Stack::getType() const{
    return "LIFO_Stack";
}

bool Peekback_Stack::peek(int &elem, int index) const {
    if(empty() || index > _top)
        return false;
    
    elem = _elems[index];

    return true;
}

bool Peekback_Stack::peek(int &elem) const{
    return Stack::peek(elem);
}

string Peekback_Stack::getType() const{
    return "Peekback_Stack";
}

ostream &operator<<(ostream &os, const Stack &s){
    s.print(os);
    return os;
}