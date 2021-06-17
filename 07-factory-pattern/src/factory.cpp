#include <iostream>
#include <sstream>
#include <string.h>
#include <queue>
#include <stack>

#include "../header/factory.hpp"
#include "../header/Add.hpp"
#include "../header/Div.hpp"
#include "../header/Mult.hpp"
#include "../header/Op.hpp"
#include "../header/Pow.hpp"
#include "../header/Sub.hpp"


Factory::Factory() {

}

Base* Factory::parse( char** a, int length )
{
    std::queue<Base*> result;
    std::stack<std::string> operation;

    for( int i = 0; i < length; i++ )
    {
        std::string temp = a[i];
        if ( type(temp) == 1 ) {

            if( FindNotAny(temp , NUMBERS ) == -1 )   {
                // temp contains numbers plus other characters
                result.push( new Op(std::stod(temp)) );
            }
            else {
                // temp contains numbers plus other characters
                std::cout << "[Factory::parse():unknown number sequence]"
                             "\n\n" << std::endl;
                return nullptr;
            }

            if ( !operation.empty() ) {
                std::string op = operation.top(); operation.pop();

                if ( op.length() == 1 && op == "*") {
                    Base* lhs = result.front();        result.pop();
                    Base* rhs = result.front();        result.pop();
                    // get the two operands and delete them from queue

                    Base* m = new Mult ( lhs, rhs );
                    result.push( m );
                }
                else if ( op.length() == 1 && op == "/") {
                    Base* lhs = result.front();        result.pop();
                    Base* rhs = result.front();        result.pop();

                    Base* m = new Div ( lhs, rhs );
                    result.push( m );
                }

                else if ( op.length() == 1 && op == "+") {
                    Base* lhs = result.front();        result.pop();
                    Base* rhs = result.front();        result.pop();

                    Base* m = new Add ( lhs, rhs );
                    result.push( m );
                }
                else if ( op.length() == 1 && op == "-") {
                    Base* lhs = result.front();        result.pop();
                    Base* rhs = result.front();        result.pop();

                    Base* m = new Sub ( lhs, rhs );
                    result.push( m );
                }
                else if ( op.length() == 2 && op == "**") {
                    Base* lhs = result.front();        result.pop();
                    Base* rhs = result.front();        result.pop();

                    Base* m = new Pow ( lhs, rhs );
                    result.push( m );
                }
                else {
                    // any other operator is invalid so return nullptr
                    std::cout << "[Factory::parse():unknown operator "
                                 "sequence]\n" << std::endl;
                    return nullptr;
                }
            }
        }
        else if ( type(temp) == 2 ) {
            operation.push(temp);
        }
        else {
            std::cout << "[Factory::parse():Invalid type]\n" << std::endl;
            return nullptr;
        }
    }
    return result.front();
}


Base* Factory::parse(std::string str )
{
    std::queue<Base*> input;
    std::stack<std::string> operation;
    std::string temp = str;

    while( temp.length() > 0 )
    {
        if( type(temp) == 1) /// temp[0] is number
        {
            double value = 0;   // value of string as double
            int str_length = 1; // length of number in the string

            if( FindNotAny(temp , NUMBERS ) == -1 )
                value = std::stod(temp.substr(0, str_length));
            else  {
                str_length = FindNotAny(temp, NUMBERS);
                value = std::stod(temp.substr(0, str_length));
            }

            input.push(new Op(value));
            temp = temp.substr(str_length);
            // remove the extracted string from temp

            if ( !operation.empty()) {
                std::string op = operation.top(); operation.pop();

                if ( op.length() == 1 && op == "*") {
                    Base* lhs = input.front();        input.pop();
                    Base* rhs = input.front();        input.pop();
                    // get the two operands and delete them from queue

                    Base* m = new Mult ( lhs, rhs );
                    input.push( m );
                }
                else if ( op.length() == 1 && op == "/") {
                    Base* lhs = input.front();        input.pop();
                    Base* rhs = input.front();        input.pop();

                    Base* m = new Div ( lhs, rhs );
                    input.push( m );
                }

                else if ( op.length() == 1 && op == "+") {
                    Base* lhs = input.front();        input.pop();
                    Base* rhs = input.front();        input.pop();

                    Base* m = new Add ( lhs, rhs );
                    input.push( m );
                }
                else if ( op.length() == 1 && op == "-") {
                    Base* lhs = input.front();        input.pop();
                    Base* rhs = input.front();        input.pop();

                    Base* m = new Sub ( lhs, rhs );
                    input.push( m );
                }
                else if ( op.length() == 2 && op == "**") {
                    Base* lhs = input.front();        input.pop();
                    Base* rhs = input.front();        input.pop();

                    Base* m = new Pow ( lhs, rhs );
                    input.push( m );
                }

                else { // any other operator is invalid so return nullptr
                   // std::cout << "<parse(std::string)::unknown sequence of operator>" << std::endl;
                    return nullptr;
                }
            }
        }
        else if (type(temp) == 2 ) { // temp[0] is operator
            int str_length = FindNotAny(temp, OPERATORS);
            std::string t = temp.substr(0,str_length);
            operation.push(t);
            temp = temp.substr(str_length);
        }
        else  { /// temp[0] is invalid ( i.e neither number nor operator)
           // std::cout << "parse(std::string) <-1 type>" << std::endl;
            return nullptr;
        }
    }
    return input.front();
}

bool Factory::Find(std::string str, std::string lookup)
{

    for ( unsigned int i = 0; i < lookup.length(); i++)    {
        /// if first letter of str matches any char in lookup
        if( str.front() == lookup[i] )
            return true;
    }
    return false;
}

int Factory::FindNotAny(std::string str, std::string lookup)
{
    /** ---------------------- STEPS ----------------------------
     * iterate through the string str
     * call Find()  to find the occurence of str[i]in lookup
     *
     * \a if the consecutive letters belonge to lookup, continue
     * \b else return position last letter belonging str
     *
     * \c if by chance str has only one element and cant be iterated
     * return -1 to identify that it is the last letter in str;
     * ----------------------------------------------------------
     */

    for( unsigned int i = 0; i < str.length() ; i++) {
        std::string a;   a = str.at(i);
        /// if a exists in lookup, continue iterating
        if( Find( a, lookup) == false )
            return i;
        /// if a does not exit in lookup, end and return i value
        else
            continue;
    }
    return -1;
}

std::string Factory::read_input() {
    std::string equation("");

    /// if no input is given ask again
    while( equation.length() == 0 ) {
        std::cin >> equation;
    }
    return equation;
}

std::string Factory::remove_escape_char(std::string str)
{
    std::string hold("");
    for ( unsigned int i = 0; i < str.length(); i++) {
        if( str[i] != '\\' || str[i] != '"')
            /// if escape char is \ or ", remove it from str
            hold += str[i];
    }
    return hold;
}

std::string Factory::remove_spaces(std::string str)
{
    std::stringstream ss(str);
    std::string hold("");
    std::string temp = str;
    while( ss >> temp)    {
        hold += temp;
    }
    str = hold;
    return str;
}

int Factory::type( std::string str )
{
    if ( Find(str, NUMBERS) == true )
        return 1;
    else if ( Find(str, OPERATORS) == true )
        return 2;
    else /// any unknown character / invalid character
        return -1;
}

