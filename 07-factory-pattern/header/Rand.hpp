#ifndef __RAND_HPP__
#define __RAND_HPP__

#include <random>

#include "../header/base.hpp"
#include "../header/Op.hpp"

class Rand : public Base {
    private:
        double val;

    public:
        Rand() {
            val = rand() % 100;
        }

        double evaluate() { 
            val = rand() % 100;
            return val; 
        }
        
        std::string stringify() {
            return std::to_string(val ); 
        }

};

#endif //__RAND_HPP__

