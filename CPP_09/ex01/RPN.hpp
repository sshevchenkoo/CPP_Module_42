#ifndef RPN_HPP
# define RPN_HPP
#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>

class RPN
{
    private:
        std::string _input;
    public:
        RPN();
        RPN(const std::string &inputStr);
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

        int count_rpn();

        class ErrorFormat : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Error");
				}
		};
};

#endif