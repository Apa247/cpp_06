/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:57:40 by daparici          #+#    #+#             */
/*   Updated: 2024/11/12 11:52:59 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Converter.hpp"

int main(int argc, char **argv) {

    if (argc != 2) {
        std::cerr << "Error: Invalid number of arguments." << std::endl;
        return 1;
    }

    std::string str = argv[1];
    Converter::convert(str);


    // Empty string
    std::cout << "Test with empty string:" << std::endl;
    Converter::convert("");
    std::cout << std::endl;

    // Single character
    std::cout << "Test with single character 'a':" << std::endl;
    Converter::convert("a");
    std::cout << std::endl;

    std::cout << "Test with single character '1':" << std::endl;
    Converter::convert("1");
    std::cout << std::endl;

    // Integer strings
    std::cout << "Test with integer string '123':" << std::endl;
    Converter::convert("123");
    std::cout << std::endl;

    std::cout << "Test with invalid integer string '12a3':" << std::endl;
    Converter::convert("12a3");
    std::cout << std::endl;

    // Float strings
    std::cout << "Test with float string '123.45':" << std::endl;
    Converter::convert("123.45");
    std::cout << std::endl;

    std::cout << "Test with invalid float string '123.45.67':" << std::endl;
    Converter::convert("123.45.67");
    std::cout << std::endl;

    // Double strings
    std::cout << "Test with double string '123.456789':" << std::endl;
    Converter::convert("123.456789");
    std::cout << std::endl;

    std::cout << "Test with invalid double string '123.456.789':" << std::endl;
    Converter::convert("123.456.789");
    std::cout << std::endl;

    // Special literals
    std::cout << "Test with special literal 'nan':" << std::endl;
    Converter::convert("nan");
    std::cout << std::endl;

    std::cout << "Test with special literal 'inf':" << std::endl;
    Converter::convert("inf");
    std::cout << std::endl;

    std::cout << "Test with special literal '-inf':" << std::endl;
    Converter::convert("-inf");
    std::cout << std::endl;

    return 0;
}