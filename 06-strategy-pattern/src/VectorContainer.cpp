#include "../header/VectorContainer.hpp"

#include <iostream>
#include <stdexcept>     // std::out_of_range


using namespace std;
using std::vector;


VectorContainer::VectorContainer():Container() { 
    _container = std::vector< Base* >();
    sort_function = nullptr;
}

VectorContainer::VectorContainer( Sort* function): Container(function) {
    _container = std::vector< Base* >();
    sort_function = function;
}

void VectorContainer::add_element( Base* element ) {
    _container.push_back( element );
}

void VectorContainer:: print() {
    assert( _container.size() > 0 );

    vector<Base*>::iterator _it = _container.begin();
    for ( ; _it != _container.end(); _it++ ) {
        Base* print = *_it;
        cout << print->stringify();
    }
}

void VectorContainer::sort() {
    if( sort_function == nullptr )
        throw std::logic_error("sort_function nullptr");
    
    sort_function->sort(this);
}

void VectorContainer::swap(int i, int j) {
    try{
        vector<Base*>::iterator _it = _container.begin();
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
 //       throw ( 
	 std::cerr << "Out of Range error: " << oor.what() << '\n';
    }
}

Base* VectorContainer::at(int i){
    try{
        std::vector<Base*>::iterator _it = _container.begin();
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

int VectorContainer::size() {
    return _container.size();
}


