/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:23:15 by daparici          #+#    #+#             */
/*   Updated: 2024/11/12 12:20:54 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <cerrno>
#include <limits>
#include <stdexcept>
#include <cfloat>
#include <cctype>

/*
    Recordatorio: Los métodos estáticos no requieren una instancia de la clase para ser llamados.
    Esto significa que puedes llamar a un método estático directamente usando el nombre de la clase,
    sin necesidad de crear un objeto de esa clase.

    Los constructores son privados; ¡no habrá instancias!

    Recuerda que los métodos estáticos no están asociados a una instancia; son llamados por la clase.

    Un static_cast en C++ es un tipo de conversión utilizado para convertir un tipo de dato a otro
    de forma segura en tiempo de compilación. Realiza una conversión de tipo explícita y se usa comúnmente cuando queremos:

        - Convertir entre tipos relacionados (como de float a int).
        - Llamar a funciones sobrecargadas específicas, especificando el tipo exacto.
        - Convertir punteros o referencias entre tipos en una jerarquía de herencia (siempre que sean compatibles).
    
    Sintaxis:
        static_cast<tipo_nuevo>(expresión);
        
    Por ejemplo:
        int a = 10;
        double b = static_cast<double>(a);  // Convierte 'a' a 'double'
    
    TIPOS DE CONVERSIONES EN C++

        static_cast:
            Convierte entre tipos compatibles en tiempo de compilación.
            Se puede usar para conversiones implícitas (como de int a double) o entre punteros dentro de una jerarquía
            de herencia (de Derived* a Base*).
            No es tan “fuerte” como otros tipos de cast, ya que no permite convertir entre tipos no relacionados,
            asegurando un cierto grado de seguridad.
        
        dynamic_cast:
            Utilizado principalmente para convertir punteros o referencias en una jerarquía de clases polimórficas (es decir, cuando al menos una clase tiene una función virtual).
            Realiza una verificación en tiempo de ejecución para asegurar que la conversión sea segura. Si falla, devuelve nullptr para punteros o lanza una excepción para referencias.
            Esto hace que dynamic_cast sea adecuado para downcasting en la herencia (convertir de Base* a Derived*).
            
        const_cast:
            Usado para agregar o eliminar el calificador const de una variable.
            Solo puede aplicarse a punteros o referencias.
            Este tipo de conversión debe usarse con precaución, ya que eliminar const puede llevar a un comportamiento indefinido si modificas un valor que era inicialmente const.
        
        reinterpret_cast:
            El cast más poderoso y potencialmente peligroso, usado para conversiones de bajo nivel entre tipos no relacionados.
            Se usa típicamente cuando necesitas interpretar el patrón de bits de un valor como otro tipo, como convertir un puntero a un int o viceversa.
            Este cast no realiza ninguna verificación ni conversión y depende del compilador. Usa reinterpret_cast con precaución, ya que puede llevar a un comportamiento indefinido.
           
    Resumen de diferencias:

        static_cast: Seguro para conversiones entre tipos compatibles y dentro de una jerarquía de herencia.
        dynamic_cast: Usado en jerarquías de herencia con verificación de tipo en tiempo de ejecución; útil para downcasting.
        const_cast: Altera los calificadores const o volatile, útil para eliminar const.
        reinterpret_cast: Permite reinterpretar un tipo de bajo nivel, muy arriesgado y, a menudo, específico de la plataforma.

    Estas terminaciones representan valores especiales en programación y matemáticas, que suelen aparecer cuando trabajas con cálculos de punto flotante (números de coma flotante)
    y operaciones matemáticas en C++ u otros lenguajes. Vamos a ver qué significa cada una:

        NaN (Not a Number):
            - Representa un valor que "no es un número".
            - Aparece cuando realizas operaciones matemáticas que no tienen un resultado numérico bien definido, como 0/0 o la raíz cuadrada de un número negativo.
            - Los sistemas de coma flotante IEEE 754 (que muchos lenguajes y sistemas siguen) definen NaN como un valor especial para indicar que una operación matemática no tiene un valor numérico significativo.
        
        +inf y -inf (Infinito positivo y negativo):
            - Representan valores infinitos en cálculos de punto flotante.
            - +inf aparece cuando un cálculo da un resultado que excede el valor máximo que puede representarse en el tipo de dato (por ejemplo, dividir un número positivo por 0).
            - -inf representa el infinito negativo y suele aparecer cuando divides un número negativo entre 0.
            - Estos valores también son parte de la norma IEEE 754 y ayudan a manejar cálculos que, de otro modo, generarían errores.
        
        nanf, +inff, -inff:
            - Las terminaciones con f (nanf, +inff, -inff) indican que el valor corresponde a un tipo de dato float (es decir, un número de coma flotante de precisión simple).
            - Sin la f (nan, +inf, -inf), el valor normalmente se refiere a un tipo de dato double (número de coma flotante de doble precisión).

*/

class Converter
{
    private:
        static bool isChar(const std::string &str);
        static bool isInt(const std::string &str);
        static bool isFloat(const std::string &str);
        static bool isDouble(const std::string &str);

        static void printChar(char c);
        static void printInt(int n);
        static void printFloat(float f);
        static void printDouble(double d);

        static const std::string specialLiterals[]; // Array de strings que contiene los valores especiales de char, int, float y double.
        static void (*handlers[])(void); // Array de punteros a funciones que apuntan a las funciones de impresión de valores especiales.

        static void handleNan(void);
        static void handlePosInf(void);
        static void handleNegInf(void);
        static void handleNanF(void);
        static void handlePosInfF(void);
        static void handleNegInfF(void);

        // Constructor privado para evitar instancias de la clase.
        Converter(void);
        Converter(const Converter &src);
        Converter &operator=(const Converter &rhs);
        ~Converter(void);

    public:
        static void convert(const std::string &str);
};