#include "Stack.h"
#include <algorithm>

bool
Stack::pop(std::string &elem){
    if(empty())
        return false;
    
    elem = _stack.back();
    _stack.pop_back();
    return true;
}

bool 
Stack::push(const std::string &elem){
    if(full())
        return false;
    
    _stack.push_back(elem);
    return true;
}

bool
Stack::peek(std::string &elem){
    if(empty())
        return false;
    
    elem = _stack.back();
    return true;
}

bool 
Stack::find(const std::string &elem){
    if(empty())
        return false;

    vector<string>::iterator it = std::find(_stack.begin(), _stack.end(), elem);
    if(it != _stack.end())
        return true;
    return false;
}

int
Stack::count(const string &elem){
    if(empty())
        return 0;
    
    return std::count(_stack.begin(), _stack.end(), elem);
}