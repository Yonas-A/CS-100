#ifndef ADD_HPP
#define ADD_HPP

#include "base.hpp"

class Add : public Base {
    private:
        Base *op1, *op2;
        
    public:
        Add(Base* op1, Base* op2) {
            this->op1  = op1;
            this->op2  = op2;
        }

        virtual double evaluate() {
            return op1->evaluate() + op2->evaluate();
        }
    
        virtual std::string stringify() {
            return op1->stringify() + " + " +  op2->stringify() + "\n";
        }

};
#endif //ADD_HPP


