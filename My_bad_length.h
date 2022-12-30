#pragma once
#include <exception> // для наследования от exception
using namespace std;

class My_bad_length : public exception {
    public: 
     virtual const char* what() const noexcept override  {
        return "ERROR: My_bad_length!";
    };
};

