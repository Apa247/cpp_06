/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:00:58 by daparici          #+#    #+#             */
/*   Updated: 2024/11/12 20:11:45 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

//--------------------- Constructors ---------------------//

Serializer::Serializer()
{
    std::cout << "Serializer default constructor called" << std::endl;
}


Serializer::Serializer(const Serializer &src)
{
    (void)src;
    std::cout << "Serializer copy constructor called" << std::endl;
}

//--------------------- Operators ---------------------//

Serializer &Serializer::operator=(const Serializer &rhs)
{
    (void)rhs;
    std::cout << "Serializer assignation operator called" << std::endl;
    return *this;
}

//--------------------- Destructor ---------------------//

Serializer::~Serializer()
{
    std::cout << "Serializer destructor called" << std::endl;
}  

//--------------------- Member functions ---------------------//

uintptr_t    Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data    *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}


