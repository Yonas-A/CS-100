#ifndef __SELECTION_SORT_HPP__
#define __SELECTION_SORT_HPP__

#include "../header/base.hpp"
#include "../header/sort.hpp"

class SelectionSort:public Sort {
    public:
        SelectionSort():Sort() { };

        virtual void sort(Container* container) {
            int i, j, first;
            int size = container->size();
            for ( i =  0; i < size - 1; i++ ) {
                first = i;                           // initialize first element as min
                for ( j = i+1; j < size ; j++ )      // locate smallest between positions 1 and i.
                {
                    if ( container->at(j)->evaluate() <  container->at(first)->evaluate() )
                        first = j;
                }
                container->swap( first, i );
            }
        };
};

#endif //__SELECTION_SORT_HPP__
