#ifndef __VECTOR_CONTAINER_HPP__
#define __VECTOR_CONTAINER_HPP__
 
#include "../header/container.hpp"

#include <vector>

class SelectionSort;
class BubbleSort;

class VectorContainer: public Container {
public:

    /* Constructors */ 
    VectorContainer();

    VectorContainer( Sort* function );
    // ------------------------------------------------------------------

    // push the top pointer of the tree into container
    virtual void add_element(Base* element) ;

    // iterate through trees and output the expressions (use stringify())
    virtual void print();

    // calls on the previously set sorting-algorithm. Checks if sort_function is not null
    //                         throw exception if otherwise
    virtual void sort();

    // switch tree locations
    virtual void swap(int i, int j);

    // get top ptr of tree at index i
    virtual Base* at(int i);

    // return container size
    virtual int size();

private:
    std::vector<Base* > _container;
};

#endif //__VECTOR_CONTAINER_HPP__
