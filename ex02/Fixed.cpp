/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <zxcmasterass@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 02:49:55 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/08/15 16:45:02 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _fixed_point(0) {}

Fixed::Fixed(const int value) : _fixed_point(value << _nFractBits) {}

Fixed::Fixed(const float value) : _fixed_point(roundf(value * (1 << _nFractBits))) {}

Fixed::Fixed(const Fixed& other) : _fixed_point(other._fixed_point) {}

Fixed& Fixed::operator=(const Fixed& other) 
{
    if (this != &other)
        _fixed_point = other._fixed_point;
    return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const 
{
    return _fixed_point;
}

void Fixed::setRawBits(int const raw) 
{
    _fixed_point = raw;
}

float Fixed::toFloat() const 
{
    return static_cast<float>(_fixed_point) / (1 << _nFractBits);
}

int Fixed::toInt() const 
{
    return _fixed_point >> _nFractBits;
}

bool Fixed::operator>(const Fixed& other) const 
{
    return _fixed_point > other._fixed_point;
}

bool Fixed::operator<(const Fixed& other) const 
{
    return _fixed_point < other._fixed_point;
}

bool Fixed::operator>=(const Fixed& other) const 
{
    return _fixed_point >= other._fixed_point;
}

bool Fixed::operator<=(const Fixed& other) const 
{
    return _fixed_point <= other._fixed_point;
}

bool Fixed::operator==(const Fixed& other) const 
{
    return _fixed_point == other._fixed_point;
}

bool Fixed::operator!=(const Fixed& other) const 
{
    return _fixed_point != other._fixed_point;
}

Fixed Fixed::operator+(const Fixed& other) const 
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const 
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const 
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const 
{
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
    ++_fixed_point;
    return *this;
}

Fixed Fixed::operator++(int) 
{
    Fixed temp(*this);
    ++_fixed_point;
    return temp;
}

Fixed& Fixed::operator--() 
{
    --_fixed_point;
    return *this;
}

Fixed Fixed::operator--(int) 
{
    Fixed temp(*this);
    --_fixed_point;
    return temp;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) 
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) 
{
    return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) 
{
    os << fixed.toFloat();
    return os;
}
