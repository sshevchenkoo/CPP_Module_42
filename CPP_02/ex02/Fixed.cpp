#include "Fixed.hpp"

Fixed::Fixed() : raw(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int rawValue) : raw(rawValue << fractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatValue) : raw(roundf(floatValue * (1 << fractionalBits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->raw = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->raw = other.getRawBits();
    }
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->raw);
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    this->raw = raw;
}

float Fixed::toFloat( void ) const
{
    return (static_cast<float>(raw)/(1 << fractionalBits));
}
int Fixed::toInt( void ) const
{
    return (raw >> fractionalBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
    os << obj.toFloat();
    return os;
}

bool Fixed::operator>(const Fixed& obj) const
{
    return (this->raw > obj.raw);
}

bool Fixed::operator<(const Fixed& obj) const
{
    return (this->raw < obj.raw);
}

bool Fixed::operator>=(const Fixed& obj) const
{
    return (this->raw >= obj.raw);
}

bool Fixed::operator<=(const Fixed& obj) const
{
    return (this->raw <= obj.raw);
}

bool Fixed::operator==(const Fixed& obj) const
{
    return (this->raw == obj.raw);
}

bool Fixed::operator!=(const Fixed& obj) const
{
    return (this->raw != obj.raw);
}

Fixed Fixed::operator+(const Fixed& obj) const
{
    return (Fixed(this->toFloat() + obj.toFloat()));
}

Fixed Fixed::operator-(const Fixed& obj) const
{
    return (Fixed(this->toFloat() - obj.toFloat()));
}

Fixed Fixed::operator*(const Fixed& obj) const
{
    return (Fixed(this->toFloat() * obj.toFloat()));
}

Fixed Fixed::operator/(const Fixed& obj) const
{
    return (Fixed(this->toFloat() / obj.toFloat()));
}

Fixed&  Fixed::max(Fixed &a, Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    else
        return (b);
}

Fixed&  Fixed::min(Fixed &a, Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    else
        return (b);
}

const Fixed&  Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    else
        return (b);
}

const Fixed&  Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    else
        return (b);
}

Fixed&  Fixed::operator++()
{
    this->raw++;
    return (*this);
}

Fixed&  Fixed::operator--()
{
    this->raw--;
    return (*this);
}

Fixed   Fixed::operator++(int)
{
    Fixed   result = *this;
    this->raw++;
    return (result);
}

Fixed   Fixed::operator--(int)
{
    Fixed   result = *this;
    this->raw--;
    return (result);
}
