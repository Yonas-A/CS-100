#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"

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
            return op1->stringify() + " / " + op2->stringify() + "\n";
        }

};

#endif // __DIV_HPP__

