#ifndef __RAND_HPP__
#define __RAND_HPP__

#include <random>

#include "../header/base.hpp"
#include "../header/Op.hpp"

#include "../header/iterator.hpp"
#include "../header/visitor.hpp"

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
            return std::to_string(val);
        }

        virtual Iterator* create_iterator() {
            return new NullIterator(this);
        }

        virtual Base* get_left() {
            return nullptr;
        }

        virtual Base* get_right() {
            return nullptr;
        }

        virtual void accept(CountVisitor* visitor) {
            visitor->visit_rand();
        }
};

#endif //__RAND_HPP__

