#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "../header/base.hpp"
#include "../header/Op.hpp"

#include "../header/iterator.hpp"
#include "../header/visitor.hpp"

class Div : public Base {
    private:
        Base *op1, *op2;

    public:
        Div(Base* op1, Base* op2) {
            this->op1 = op1; 
            this->op2 = op2;
        }
            
        double evaluate() {
            return op1->evaluate() / op2->evaluate();
        }

        std::string stringify(){
            return op1->stringify() + " / " + op2->stringify();
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
            visitor->visit_div();
        }
};

#endif //__DIV_HPP__

