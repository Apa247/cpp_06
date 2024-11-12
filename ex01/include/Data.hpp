/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:59:48 by daparici          #+#    #+#             */
/*   Updated: 2024/11/12 19:08:40 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

struct Data
{
    std::string     text;
    int             number;
    
    Data();
    Data(const Data &src);
    Data &operator=(const Data &rhs);
    ~Data();
};