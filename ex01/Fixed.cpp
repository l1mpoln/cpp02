/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <zxcmasterass@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 00:06:31 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/08/15 16:45:17 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _fixed_point(0) {}  // Реализация конструктора по умолчанию

Fixed::Fixed(const int value) : _fixed_point(value << _nFractBits) {}  // Реализация конструктора для целого числа

Fixed::Fixed(const float value) : _fixed_point(roundf(value * (1 << _nFractBits))) {}  // Реализация конструктора для числа с плавающей точкой

Fixed::Fixed(const Fixed& other) : _fixed_point(other._fixed_point) {}  // Реализация конструктора копирования

Fixed& Fixed::operator=(const Fixed& other) // Реализация перегрузки оператора присваивания
{ 
    if (this != &other) {
        _fixed_point = other._fixed_point;
    }
    return *this;
}

Fixed::~Fixed() {}  // Реализация деструктора

int Fixed::getRawBits() const // Реализация метода получения сырых битов
{  
    return _fixed_point;
}

void Fixed::setRawBits(int const raw) // Реализация метода установки сырых битов
{  
    _fixed_point = raw;
}

float Fixed::toFloat() const   // Реализация метода преобразования в тип float
{
    return static_cast<float>(_fixed_point) / (1 << _nFractBits);
}

int Fixed::toInt() const // Реализация метода преобразования в тип int
{  
    return _fixed_point >> _nFractBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) // Реализация перегрузки оператора вывода
{  
    os << fixed.toFloat();
    return os;
}
