#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include "../header/base.hpp"
#include <iostream>

const std::string NUMBERS = "0123456789.";
const std::string OPERATORS = "*/+-";


class Factory {

    public:
        Factory();

        /**
         * @brief  parse_input: parses the string to a math equation with operands
         * 	    and operations.
         * @param  str: a math expression as a string to be parsed
         * @param  length the length of the char** str
         * @return Base* to a math expression parsed from str or nullptr if str
         *         input was invalid
         */
        Base* parse(char** str, int length);

        /**
         * @brief  parse_input: parses the string to a math equation with operands 
         *	   and operations.
 	 * @param  str: a math expression as a string to be parsed
         * @return Base* to a math expression parsed from str or nullptr if str 
         *         input was invalid
         */
        Base* parse(std::string str);

    private:

        /**
         * @brief  Find: find out if the first letter of str exists inside lookup
         * @param  str: string we are searching for
         * @param  lookup: a look up string to match str with
	 * @return true if first letter of  str was found inside lookup
	 * 	   otherwise false
         */
        bool Find(std::string str, std::string lookup);

        /**
         * @brief  FindNotAny: find the occurence of str inside lookup
         * @param  str: string being parsed
         * @param  lookup: a lookup string to match str with
         * @return last position of letter belonging to string_type or
         *          -1 if str has only one element
         */

        /**
 	 * @brief  FindNotAny: find the occurence of str inside lookup
	 * @param  str: string being checked to find its occurence in lookup
	 * @param  lookup: a lookup string to match str with
	 * @return last position of letter belonging to lookup or -1 if 
         *          str has only one element
	 */                                                       
        int FindNotAny(std::string str, std::string lookup);

        /**
         * @brief  read_input: prompts user to enter a math expression
         * @return the input string from user
         */ 
        std::string read_input();

        /**
         * @brief  remove_spaces: removes any white space character from string str
         * @param  str: string being inspected for white spaces
         * @return the string without any white space characters
         */
        std::string remove_spaces(std::string str);

        /**
         * @brief  remove_escape_char removes the escape character found in str
         * @param  str: string being inspected for scape character
         * @return string without the escape character
         */
        std::string remove_escape_char(std::string str);

        /**
         * @brief  type: cheks if str is number or operator
         * @param  str: string being checked for number or operator  
         * @return 1 for numbers 2 for operators or -1 for invalid inputs 
         */
        int type(std::string str);
};


#endif //__FACTORY_HPP__
