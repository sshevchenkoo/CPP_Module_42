#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &)
{
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &literal)
{
    char *end;

    if (literal == "nan" || literal == "nanf")
    {
		std::cout << "char: impossible" << std::endl; 
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
        return;
	}
    if (literal == "-inff" || literal == "-inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
        return;
	}
    if (literal == "+inff" || literal == "+inf")
    {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
        return;
	}

    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
    {
        char charValue = literal[1];

        std::cout << "char: '" << charValue << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(charValue) << std::endl;
        std::cout << "float: " << static_cast<float>(charValue) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(charValue) << ".0" << std::endl;
        return;
    }
    if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
    {
        char charValue = literal[0];

        std::cout << "char: '" << charValue << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(charValue) << std::endl;
        std::cout << "float: " << static_cast<float>(charValue) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(charValue) << ".0" << std::endl;
        return;
    }

    long intValue = std::strtol(literal.c_str(), &end, 10);
    if (*end == '\0')
    {
        char charValue = static_cast<char>(intValue);
        float floatValue = static_cast<float>(intValue);
        double doubleValue = static_cast<double>(intValue);

        if (intValue >= 32 && intValue <= 126)
            std::cout << "char: '" << charValue << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;

        std::cout << "int: " << intValue << std::endl;
        std::cout << "float: " << floatValue << ".0f" << std::endl;
        std::cout << "double: " << doubleValue << ".0" << std::endl;
        return;
    }

    double doubleValue = std::strtod(literal.c_str(), &end);
    if ((*end == 'f' && *(end + 1) == '\0') || *end == '\0')
    {
        float floatValue = static_cast<float>(doubleValue);
        int intValue = static_cast<int>(floatValue);
        char charValue = static_cast<char>(intValue);

        if (intValue >= 32 && intValue <= 126)
            std::cout << "char: '" << charValue << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;

        std::cout << "int: " << intValue << std::endl;
        std::cout << "float: " << floatValue << ".0f" << std::endl;
        std::cout << "double: " << doubleValue << ".0" << std::endl;
        return;
    }

    std::cout << "Conversion is impossible." << std::endl;
}