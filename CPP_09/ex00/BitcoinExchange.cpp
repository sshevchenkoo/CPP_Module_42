#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	_readData();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
{
	if (this != &other)
		*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other)
{
	if (this != &other)
		_data = other._data;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

std::map<std::string, float> const &BitcoinExchange::getData() const
{
	return (this->_data);
}

void BitcoinExchange::_readData()
{
       std::ifstream file("data.csv");
        if (!file.is_open())
            throw CouldNotOpenFile();

        std::string line;

        std::getline(file, line);
        if (line != "date,exchange_rate")
            throw InvalidColumnFormat();

        while (std::getline(file, line))
		{
            std::string date;
			std::string price;
            std::istringstream ss(line);
            std::getline(ss, date, ',');
            std::getline(ss, price, ',');

            float priceValue;
            std::istringstream priceStream(price);
            if (!(priceStream >> priceValue))
				throw InvalidPriceFormat();
            _data[date] = priceValue;
        }

        file.close();
}

void BitcoinExchange::execute(char const *fileName)
{
	std::ifstream file(fileName);
	if (!file.is_open())
		throw CouldNotOpenFile();

	std::string line;
	std::getline(file, line);

	if (line != "date | value")
		throw InvalidColumnFormat();

	while (std::getline(file, line))
	{
		std::string date;
		std::string numberStr;
		float numberValue;
		std::istringstream ss(line);
		std::getline(ss, date, '|');
		std::getline(ss, numberStr, '|');

		if (!date.empty())
			date = date.erase(date.length() -1);
		if (_validateDate(date) == false)
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		if(!numberStr.empty())
			numberStr = numberStr.erase(0, 1);
		numberValue = _validateNumber(numberStr);
		if (numberValue != -1)
			_multiplyWithQuote(date, numberValue);
		
	}

	file.close();
}

bool BitcoinExchange::_validateDate(std::string const &date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (isdigit(date[i]) == 0)
			return (false);
	}

	if (date[5] == '0' && date[6] == '0') 
		return (false);
	if ((date[5] == '1' && date[6] > '2') || date[5] > '1')
		return (false);

	if (date[8] == '0' && date[9] == '0')
		return (false);
	if ((date[8] == '3' && date[9] > '1') || date[8] > '3')
		return (false);
	
	return (true);
}

float BitcoinExchange::_validateNumber(std::string const &valueStr)
{
	float priceValue;
	std::istringstream priceStream(valueStr);

	if (!(priceStream >> priceValue))
	{
		std::cout << "Error: bad number input => " << priceValue << std::endl;
		return (-1);
	}

	if (priceValue < 0)
	{
		std::cout << "Error: not a positive number " << std::endl;
		return (-1);
	}
	else if (priceValue > 1000)
	{
		std::cout << "Error: too large number " << std::endl;
		return (-1);
	}
	
	return (priceValue);
}

void BitcoinExchange::_multiplyWithQuote(std::string const &date, double price)
{
	std::map<std::string, float>::iterator it = _data.find(date);
	if (it != _data.end())
		std::cout << date << " => " << price << " = " << price * it->second << std::endl;
	else
	{
		std::map<std::string, float>::iterator it2 = _data.lower_bound(date);
		if (it2 == _data.begin())
			std::cout << date << " => " << price << " = " << price * it2->second << std::endl;
		else
		{
			it2--;
			std::cout << date << " => " << price << " = " << price * it2->second << std::endl;
		}
	}
}