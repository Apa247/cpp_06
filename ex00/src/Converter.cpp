/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:23:29 by daparici          #+#    #+#             */
/*   Updated: 2024/11/12 12:21:54 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

//------------------------ Constructores ------------------------//

Converter::Converter(void) 
{
    std::cout << "Constructor Error: ScalarConverter is a static class and cannot be instantiated." << std::endl;
}

Converter::Converter(const Converter &src) 
{
    std::cout << "Copy Constructor Error: ScalarConverter is a static class and cannot be instantiated." << std::endl;
    *this = src;
}

//------------------------ Operadores Asignación ------------------------//

Converter &Converter::operator=(const Converter &rhs) 
{
    if (this != &rhs)
        std::cout << "Assignment Operator Error: ScalarConverter is a static class and cannot be instantiated." << std::endl;
    return *this;
}

//------------------------ Destructor ------------------------//

Converter::~Converter(void) 
{
    std::cout << "Destructor Error: ScalarConverter is a static class and cannot be instantiated." << std::endl;
}

//------------------------ Special Literals and Handler Arrays ------------------------//

const std::string Converter::specialLiterals[] = {
    "nan",
    "+inf",
    "-inf",
    "nanf",
    "+inff",
    "-inff"
};

void (*Converter::handlers[])(void) = {
    Converter::handleNan,
    Converter::handlePosInf,
    Converter::handleNegInf,
    Converter::handleNanF,
    Converter::handlePosInfF,
    Converter::handleNegInfF
};

//------------------------ Special Literals Handlers ------------------------//

void Converter::handleNan(void) 
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
}

void Converter::handlePosInf(void) 
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: +inff" << std::endl;
    std::cout << "double: +inf" << std::endl;
}

void Converter::handleNegInf(void) 
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: -inff" << std::endl;
    std::cout << "double: -inf" << std::endl;
}

void Converter::handleNanF(void) 
{
    handleNan();
}

void Converter::handlePosInfF(void) 
{
    handlePosInf();
}

void Converter::handleNegInfF(void) 
{
    handleNegInf();
}

//------------------------ Type Checkers ------------------------//

bool Converter::isChar(const std::string &str) 
{
    if (str.length() == 1 && !std::isdigit(str[0]))
        return true;
    return false;
}

bool Converter::isInt(const std::string &str) 
{
        // Verificar si la cadena está vacía
    if (str.empty())
        return false;

    // Comprobar el primer carácter, que puede ser un signo o un dígito
    size_t start = 0;
    if (str[0] == '-' || str[0] == '+') 
    {
        if (str.length() == 1) 
            return false; // Un solo signo no es un número
        start = 1;
    }

        // Verificar que el resto de los caracteres sean dígitos
    for (size_t i = start; i < str.length(); i++) 
    {
        if (!std::isdigit(str[i])) 
            return false;
    }

        // Convertir la cadena a un número entero largo (`long long`) y comprobar el rango de `int`
    char* end;
    errno = 0; // Reset errno before the call

    long long num = std::strtoll(str.c_str(), &end, 10);

    // Check if the entire string was converted, no range error, and value is within int limits
    if (*end != '\0' || errno == ERANGE)
        return false;

    return num >= std::numeric_limits<int>::min() && num <= std::numeric_limits<int>::max();
}

bool Converter::isFloat(const std::string &str) 
{
    if (str.empty()) return false;

    char* end;
    errno = 0; // Reset errno before the call

    float value = std::strtof(str.c_str(), &end);

    // Check if the entire string was converted and Check for range errors
    if (*end != '\0' || errno == ERANGE) 
        return false;

    // Check for NaN and infinity
    if (std::isnan(value) || std::isinf(value))
        return false;
        
    // Check for range within float limits
    if (value > FLT_MAX || value < -FLT_MAX)
        return false;

    return true;
    }

bool Converter::isDouble(const std::string &str) 
{
    if (str.empty())
        return false;

    char* end;
    errno = 0; // Reset errno before the call

    double value = std::strtod(str.c_str(), &end);

        // Check if the entire string was converted and Check for range errors
    if (*end != '\0' || errno == ERANGE)
        return false;

        // Check for NaN and infinity
    if (std::isnan(value) || std::isinf(value))
        return false;

        // Check for range within double limits
    if (value > DBL_MAX || value < -DBL_MAX)
        return false;

    return true;
    }

//------------------------ Printers ------------------------//

void Converter::printChar(char c) 
{
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

void Converter::printInt(int n) 
{
    std::cout << "int: " << n << std::endl;
}

void Converter::printFloat(float f) 
{
    std::cout << "float: " << f << "f" << std::endl;
}

void Converter::printDouble(double d) 
{
    std::cout << "double: " << d << std::endl;
}

//------------------------ Convert Function ------------------------//

void Converter::convert(const std::string &str) 
{
    if (str.empty()) 
    {
        std::cout << "Error: Empty string." << std::endl;
        return;
    }

    if (str.length() == 1 && !std::isdigit(str[0])) 
    {
        char c = str[0];
        printChar(c);
        printInt(c);
        printFloat(c);
        printDouble(c);
        return;
    }

    for (size_t i = 0; i < 6; i++) 
    {
        if (str == specialLiterals[i]) 
        {
            handlers[i]();
            return;
        }
    }

    if (isChar(str)) 
    {
        char c = str[0];
        printChar(c);
        printInt(c);
        printFloat(c);
        printDouble(c);
        return;
    }

    if (isInt(str)) 
    {
        int n = std::strtol(str.c_str(), NULL, 10);
        printChar(n);
        printInt(n);
        printFloat(n);
        printDouble(n);
        return;
    }

    if (isFloat(str)) 
    {
        float f = std::strtof(str.c_str(), NULL);
        printChar(f);
        printInt(f);
        printFloat(f);
        printDouble(f);
        return;
    }

    if (isDouble(str)) 
    {
        double d = std::strtod(str.c_str(), NULL);
        printChar(d);
        printInt(d);
        printFloat(d);
        printDouble(d);
        return;
    }

    std::cout << "Error: Invalid input." << std::endl;
}

