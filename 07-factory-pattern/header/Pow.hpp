#ifndef __POW_HPP__
#define __POW_HPP__

#include <math.h>
#include "../header/base.hpp"
#include "../header/Op.hpp"

class Pow : public Base {
    private:
        Base *op1, *op2;
   
    public:
        Pow(Base* op1, Base* op2) {
            this->op1 = op1;
            this->op2 = op2;
        }

        double evaluate() {
            return pow(op1->evaluate(), op2->evaluate());
        }
      
        std::string stringify() {
            return op1->stringify() + " ** " + op2->stringify();
        }
  
};
#endif //__POW_HPP__

