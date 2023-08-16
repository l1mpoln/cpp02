/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <zxcmasterass@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:55:52 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/08/15 16:45:23 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0)
{
    std::cout << "Constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Desctructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : _fixedPoint(other._fixedPoint)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
    {
        _fixedPoint = other._fixedPoint;
    }
    return (*this);
}

int Fixed::getRawBits() const
{
    std::cout << "Get raw bits function called" << std::endl;
    return _fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "Set raw bits function called" << std::endl;
    _fixedPoint = raw;
}