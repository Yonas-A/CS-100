#include "../src/factory.cpp"

int main(int argc, char **argv) {

    Factory* factory = new Factory();
    for( int i = 0; i < argc ;i++ ) {
	std::cout << argv[i] << " "; 
    }
    std::cout << std::endl;
    
   // ++argv accounts for the first input string ./calc .. in  ./calculator 3 + 3
    Base* t = factory->parse(++argv, argc - 1);
    
    if( t != nullptr ) {
        std::cout << t->evaluate() << std::endl;
        std::cout << t->stringify() << std::endl; 
    }
    else {
	std::cout << "Invalid input::returning nullptr. From main_test.cpp" 
		  << std::endl;
    }
}
