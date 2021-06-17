#include "../header/ListContainer.hpp"

#include <iostream>
#include <stdexcept>

using namespace std;
using std::list;

ListContainer::ListContainer(): Container() { 
    _container = std::list< Base* >();
    sort_function = nullptr;
}

ListContainer::ListContainer(Sort* function):Container() {
    _container = std::list< Base* >();    
    sort_function = function;
}

void ListContainer::add_element( Base* element ) {
    _container.push_back( element);
}

void ListContainer::print() {
    assert( _container.size() > 0 );

    list<Base*>::iterator _it = _container.begin();
    for ( ; _it != _container.end(); _it++ ) {
	Base* print = *_it;
        cout <<  print->stringify();
    }
}

void ListContainer::sort() {
    if( sort_function == nullptr )
        throw std::logic_error("sort_function nullptr");

    sort_function->sort(this);
}

void ListContainer::swap(int i, int j) {

    try{
        list<Base*>::iterator _it = _container.begin();
        Base* temp1;    Base* temp2;
        int counter = 0;

        for( ; _it != _container.end(); _it++ ) {

            if( counter == i )  temp1 = *_it;
            if( counter == j )  temp2 = *_it;
            counter++;
        }

        _it = _container.begin();
	counter = 0;
        for( ; _it != _container.end(); _it++ ) {

            if( counter == i )  *_it = temp2;
            if( counter == j )  *_it = temp1;
            counter++;
        }
    }
    catch (const std::out_of_range& oor) {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
    }
}

Base* ListContainer::at(int i) {
    try{
        list<Base*>::iterator _it = _container.begin();
        int counter = 0;

        for (  ; _it != _container.end();  _it++ ) {

            if ( counter == i )  return *_it;
            counter++;
        }
    }
    catch (const std::out_of_range& oor) {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
    }
}

int ListContainer::size() {
    return _container.size();
}

