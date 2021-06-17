#ifndef __OP_HPP__
#define __OP_HPP__

#include "../header/base.hpp"

#include "../header/iterator.hpp"
#include "../header/visitor.hpp"

class Op : public Base {
    private:
        double val;

    public:
        Op() {
            val = 0;
        }

        Op(double value)  {
            val = value;
        }

        virtual double evaluate() {
            return val;
        }

        virtual std::string stringify() {
            return std::to_string(val);
        }

        virtual Iterator* create_iterator() {
            return new NullIterator( this );
        }

        virtual Base* get_left() {
            return nullptr;
        }

        virtual Base* get_right() {
            return nullptr;
        }

        virtual void accept(CountVisitor* visitor) {
            visitor->visit_op();
        }
};

#endif //__OP_HPP__
