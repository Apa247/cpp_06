/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:00:02 by daparici          #+#    #+#             */
/*   Updated: 2024/11/12 20:10:29 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
/*  uintptr_t es un tipo de dato entero sin signo definido en C y C++ que
    se utiliza para almacenar direcciones de memoria (punteros) como valores enteros. 
    Está definido en el encabezado <cstdint> en C++ y <stdint.h> en C, y su 
    tamaño es suficiente para almacenar cualquier valor de puntero.

    Características principales:

    Tamaño      ->  uintptr_t tiene el mismo tamaño que un puntero (por ejemplo, void*).
                    Esto significa que puede almacenar cualquier dirección de memoria sin perder
                    precisión, lo cual es útil en situaciones donde necesitas
                    convertir un puntero a un entero para manipulación.
    Portabilidad ->  Como parte de la biblioteca estándar, garantiza que el tipo
                    tenga el tamaño adecuado en cualquier plataforma. Esto ayuda a
                    evitar problemas de portabilidad al manejar punteros como enteros.
    Uso          ->  Su uso principal es en operaciones de bajo nivel, tales como
                    manipulación de direcciones de memoria, serialización de punteros, 
                    o interpretar punteros como enteros para operaciones aritméticas con punteros.

    Ejemplo:

    #include <iostream>
    #include <cstdint> // Para uintptr_t

    int main()
    {
        int x = 42;
        int* ptr = &x;

        // Convertir el puntero a uintptr_t
        uintptr_t intPtr = reinterpret_cast<uintptr_t>(ptr);
        std::cout << "Puntero como entero: " << intPtr << std::endl;

        // Convertir el entero de vuelta a un puntero
        int* ptr2 = reinterpret_cast<int*>(intPtr);
        std::cout << "Valor desreferenciado: " << *ptr2 << std::endl;

        return 0;
    }
*/
    private:
        Serializer();
        Serializer(const Serializer &src);
        Serializer &operator=(const Serializer &rhs);
        ~Serializer();

    public:
    
    // Método para serializar un puntero a Data en un uintptr_t
        static uintptr_t    serialize(Data *ptr);
        
    // Método para deserializar un uintptr_t en un puntero a Data
        static Data         *deserialize(uintptr_t raw);
};