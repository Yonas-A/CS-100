#include "person.h"
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

Person::Person(char *name, Person* father, Person* mother){
    this->name = new char[strlen(name) + 1];
    // add an extra space to store the null char '\0'
    strcpy(this->name, name);
    this->father = father;
    this->mother = mother;
    capacity = 1;
    numChildren = 0;
    children = new Person*[capacity];
}

Person::~Person(){
    delete [ ] children; // deallocate array of Persons
    delete [ ] name;    // deallocate char* name
}

void Person::addChild(Person *newChild){
    if(numChildren == capacity) expand(&children, &capacity);
    children[numChildren++] = newChild;
}

void Person::printAncestors(){
    cout << endl << "Ancestors of " << name << endl;
    printLineage('u', 0);
}

void Person::printDecendents(){
    cout << endl << "Decendents of " << name << endl;
    printLineage('d', 0);
}

void Person::printLineage(char dir, int level){
    char *temp = compute_relation(level);

    if(dir == 'd'){
        for(int i = 0; i < numChildren; i++){
            cout << temp << "child: " << children[i]->getName() << endl;
            children[i]->printLineage(dir, level + 1);
	}
	 delete[] temp; // deallocate dynamic char* temp  
    } else {
        if(mother){
            cout << temp << "mother: " << mother->getName() << endl;
            mother->printLineage(dir, level + 1);
        }
        if(father){
            cout << temp << "father: " << father->getName() << endl;
            father->printLineage(dir, level + 1);
        } delete[] temp; // deallocate dynamic char* temp 
    }
}

/* helper function to compute the lineage
* if level = 0 then returns the empty string
* if level >= 1 then returns ("great ")^(level - 1) + "grand "
*/
char* Person::compute_relation(int level){
    if(level == 0) return strcpy(new char[1], "");

    char *temp = strcpy(new char[strlen("grand ") + 1], "grand ");;
    
    for(int i = 2; i <= level; i++){
        char *temp2 = new char[strlen("great ") + strlen(temp) + 1];
        strcat(strcpy(temp2, "great "), temp);
	delete [] temp; // deallocate temp before assigning it to the value of temp2
        temp = temp2;
    }
    return temp;
}
/* non-member function which doubles the size of t
 * NOTE: t's type will be a pointer to an array of pointers
 */
void expand(Person ***t, int *MAX){
    Person **temp = new Person*[2 * *MAX];
    for ( int i = 0; i < 2 * *MAX; i++ )
        temp[i] = 0; // initializing each Person in temp array 
    memcpy(temp, *t, *MAX * sizeof(**t));
    *MAX *= 2;
    delete [] *t; // remove *t before assigning another value to *t
    *t = temp;
}
