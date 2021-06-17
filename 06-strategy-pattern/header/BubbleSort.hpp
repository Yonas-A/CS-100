#ifndef __BUBBLE_SORT_HPP__
#define __BUBBLE_SORT_HPP__

#include "../header/base.hpp"
#include "../header/sort.hpp"

class BubbleSort:public Sort {
    public:
        BubbleSort() : Sort() { };

        virtual void sort(Container* container) {
            int i, j, flag = 1;     // set flag to 1 to start first pass
            int temp;               // holding variable
            int length = container->size();
            for( i = 1; (i <= length) && flag; i++) 
            {
                flag = 0;
                for ( j = 0; j < ( length -1 ); j++ )  
                {
                    if ( container->at(j+1)->evaluate() <  container->at(j)->evaluate() )
                    {
                        container->swap( j, j+1 );
                        flag = 1;               // indicates that a swap occurred.
                    }
                }
            }             
        };
};

#endif //__BUBBLE_SORT_HPP__

