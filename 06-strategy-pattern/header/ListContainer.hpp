#ifndef __LIST_CONTAINER_HPP__
#define __LIST_CONTAINER_HPP__
 
#include "../header/container.hpp"
#include "../header/sort.hpp"

#include <list>

class SelectionSort;
class BubbleSort;

class ListContainer: public Container {
public:

    /* Constructors */ 
    ListContainer();

    ListContainer( Sort* function );
    // ------------------------------------------------------------------

    // push the top pointer of the tree into container
    virtual void add_element(Base* element) ;

    // iterate through trees and output the expressions (use stringify())
    virtual void print();

    // calls on the previously set sorting-algorithm. 
    		//Checks if sort_function is not null, throw exception if otherwise
    virtual void sort();

    // switch tree locations
    virtual void swap(int i, int j);

    // get top ptr of tree at index i
    virtual Base* at(int i);

    // return container size
    virtual int size();

private:
    std::list<Base* > _container;
};

#endif //__LIST_CONTAINER_HPP__
