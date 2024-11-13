/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:33:17 by daparici          #+#    #+#             */
/*   Updated: 2024/11/13 12:38:46 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <typeinfo> // For typeid()
#include <cstdlib>  // For rand()
#include <ctime>    // For time()
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

/*
	dynamic_cast es un operador en C++ que se usa para realizar conversiones seguras 
	entre tipos de clases polimórficas en tiempo de ejecución. Se utiliza para convertir 
	un puntero o una referencia de una clase base a una clase derivada, asegurando que 
	la conversión sea válida. Si la conversión no es posible, dynamic_cast devuelve un 
	puntero nulo o lanza una excepción, dependiendo del tipo de conversión que se esté 
	intentando.

	Características principales de dynamic_cast:
	->	Solo funciona con clases polimórficas: La clase base debe tener al menos
		un método virtual, generalmente el destructor virtual, para que dynamic_cast 
		funcione. Esto se debe a que dynamic_cast depende de la información de las 
		tablas de funciones virtuales (vtable) para determinar el tipo real del objeto 
		en tiempo de ejecución.
	->	Verificación en tiempo de ejecución: A diferencia de los casts estáticos 
		(static_cast), que se realizan en tiempo de compilación, dynamic_cast realiza 
		una verificación en tiempo de ejecución para asegurar que la conversión entre 
		tipos sea segura.
	->	Se usa tanto para upcasting como para downcasting:
		-	Upcasting: Convertir de una clase derivada a una clase base. Esto es seguro 
			y puede hacerse sin dynamic_cast, pero en algunas situaciones se puede elegir 
			usarlo explícitamente.
		-	Downcasting: Convertir de una clase base a una clase derivada. Esto puede ser 
			peligroso si el objeto no es del tipo derivado al cual se está convirtiendo, 
			y aquí es donde dynamic_cast es más útil, ya que asegura que la conversión sea 
			válida.
	->	Resultados de dynamic_cast:
		-	Con punteros: Si la conversión tiene éxito, devuelve un puntero al tipo deseado. 
			Si no tiene éxito (es decir, el objeto no es del tipo de clase derivada al que 
			se intenta convertir), devuelve un puntero nulo.
		-	Con referencias: Si la conversión no tiene éxito, lanza una excepción std::bad_cast.
	
	Ventajas de dynamic_cast sobre static_cast:
	->	Verificación en tiempo de ejecución.
	->	Seguridad en el Downcasting: En la conversión de una clase base a una clase derivada 
		(downcasting), dynamic_cast es más seguro porque confirma si el objeto es realmente 
		del tipo derivado antes de permitir la conversión. Si no lo es, la conversión falla 
		de manera segura.
		Esto es especialmente útil cuando no estás seguro del tipo exacto del objeto en 
		tiempo de compilación, ya que dynamic_cast garantiza que la conversión sea segura.
	
	Ventajas de static_cast sobre dynamic_cast:
	->	Mejor rendimiento: static_cast se realiza en tiempo de compilación, lo que lo hace 
		más rápido que dynamic_cast, que realiza verificaciones en tiempo de ejecución. Esto 
		hace que static_cast sea ideal en situaciones donde conoces el tipo del objeto con 
		seguridad y la conversión es segura.
	->	Compatibilidad con tipos básicos: static_cast se puede usar no solo para clases 
		polimórficas, sino también para realizar conversiones entre tipos básicos 
		(como int a float o viceversa), o entre punteros no relacionados. Es más versátil en 
		cuanto a la variedad de conversiones que permite.
	->	Simplicidad: static_cast es más simple cuando las verificaciones de seguridad en 
		tiempo de ejecución no son necesarias. Si conoces el tipo exacto del objeto y no hay 
		riesgo de error, static_cast es la opción más directa y sencilla.
*/

// Función para generar aleatoriamente una instancia de A, B o C

Base* generate(void) {
    srand(static_cast<unsigned int>(time(0))); // Inicializar la semilla de random solo una vez
    int randomValue = rand() % 3; // Generar un número aleatorio entre 0 y 2

    if (randomValue == 0)
        return new A();
    else if (randomValue == 1)
        return new B();
    else
        return new C();
}

// Funcion para identificar el tipo de instancia de A, B o C
/*
    Explicación:
        - La función utiliza dynamic_cast para intentar convertir el puntero p a cada tipo derivado (A, B, o C).
        - Si la conversión es exitosa (es decir, p realmente apunta a una instancia de ese tipo), se imprime
        el nombre del tipo correspondiente.
        - Si ninguna de las conversiones es válida, se imprime "Unknown type", lo cual manejaría cualquier caso no contemplado,
        aunque esto no debería ocurrir si p fue creado usando la función generate.
*/

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "Generated type: A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "Generated type: B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "Generated type: C" << std::endl;
    } else {
        std::cout << "Generated: Unknown type" << std::endl;
    }
}

// Función para identificar el tipo de instancia de A, B o C
/*
    Explicación:
        - Esta función usa dynamic_cast en cada bloque try-catch para intentar convertir p a las referencias A&, B& y C&.
        - Si el dynamic_cast falla (porque p no es del tipo esperado), se lanza una excepción std::bad_cast,
        y el programa pasa al siguiente bloque try-catch.
        - Si la conversión tiene éxito, se imprime el tipo correspondiente.
        - Este enfoque permite determinar el tipo sin usar punteros y garantiza que no se incluya el encabezado typeinfo.
*/
void identify(Base& p) 
{
    try 
    {
        (void)dynamic_cast<A&>(p); // Intentamos convertir p a A
        std::cout << "Identified type (reference): A" << std::endl;
    }
    catch (std::bad_cast&)
    {
        try
        {
            (void)dynamic_cast<B&>(p); // Intentamos convertir p a B
            std::cout << "Identified type (reference): B" << std::endl;
        }
        catch (std::bad_cast&)
        {
            try 
            {
                (void)dynamic_cast<C&>(p); // Intentamos convertir p a C
                std::cout << "Identified type (reference): C" << std::endl;
            } 
            catch (std::bad_cast&)
            {
                std::cout << "Identified (reference): Unknown type" << std::endl; // Manejo de casos inesperados
            }
        }
    }
}

int main(void)
{
    // Generate a random instance of A, B, or C
    Base *basePtr = generate();

    // Identify the type using pointer
    identify(basePtr);

    // Identify the type using reference
    identify(*basePtr);

    delete basePtr;

    return 0;
}