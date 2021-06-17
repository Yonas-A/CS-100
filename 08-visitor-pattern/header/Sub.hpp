#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "../header/base.hpp"
#include "../header/Op.hpp"

#include "../header/iterator.hpp"
#include "../header/visitor.hpp"

class Sub : public Base {
    private:
        Base *op1, *op2;

    public:
        Sub(Base* op1, Base* op2) {
            this->op1 = op1;
            this->op2 = op2;
        }

        virtual double evaluate() {
            return op1->evaluate() - op2->evaluate();
        }
      
        virtual std::string stringify() {
            return op1->stringify() + " - " + op2->stringify() ;
        }

        virtual Iterator* create_iterator() {
            return new BinaryIterator(this);
        }

        virtual Base* get_left() {
            return op1;
        }

        virtual Base* get_right() {
            return op2;
        }

        virtual void accept(CountVisitor* visitor) {
            visitor->visit_sub();
        }
};

#endif //__SUB_HPP__

