#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "../header/base.hpp"
#include "../header/Op.hpp"

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
            return op1->stringify() + " + " +  op2->stringify();
        }

};
#endif //__ADD_HPP__


