/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <zxcmasterass@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 02:49:57 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/08/15 16:45:09 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>
#include "Fixed.hpp"

int main() 
{ 
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << "a: " << a << std::endl;
    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "a++: " << a++ << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;

    Fixed c = a + b;
    std::cout << "a + b: " << c << std::endl;

    Fixed d = a - b;
    std::cout << "a - b: " << d << std::endl;

    Fixed e = a * b;
    std::cout << "a * b: " << e << std::endl;

    Fixed f = a / b;
    std::cout << "a / b: " << f << std::endl;

    std::cout << "a++: " << a++ << std::endl;
    std::cout << "++a: " << ++a << std::endl;

    std::cout << "Min of a and b: " << Fixed::min(a, b) << std::endl;
    std::cout << "Max of a and b: " << Fixed::max(a, b) << std::endl;

    return 0;
}

