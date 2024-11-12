/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:00:44 by daparici          #+#    #+#             */
/*   Updated: 2024/11/12 19:27:58 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : text(""), number(0) 
{
    std::cout << "Data default constructor called" << std::endl;
}

Data::Data(const Data &src) : text(src.text), number(src.number)
{
    std::cout << "Data copy constructor called" << std::endl;
}

Data &Data::operator=(const Data &rhs)
{
    std::cout << "Data assignation operator called" << std::endl;
    if (this != &rhs)
    {
        text = rhs.text;
        number = rhs.number;
    }
    return *this;
}

Data::~Data()
{
    std::cout << "Data destructor called" << std::endl;
}