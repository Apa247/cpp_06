/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:00:11 by daparici          #+#    #+#             */
/*   Updated: 2024/11/12 20:12:02 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data		data;
	Data        *deserializedData;
	uintptr_t	raw;
	
    data.number = 42;
    data.text = "Hello, Serialization!";

    std::cout << "Original Data: " << std::endl;
    std::cout << "Number: " << data.number << std::endl;
    std::cout << "Text: " << data.text << std::endl;

    // Serialize the Data object's address
    raw = Serializer::serialize(&data);
	
	std::cout << "\nSerialized Data: " << std::endl;
	std::cout << "Raw: " << raw << std::endl;

    // Deserialize the uintptr_t back into a Data pointer
    deserializedData = Serializer::deserialize(raw);

    // Verify that the deserialized pointer is the same as the original
    std::cout << "\nDeserialized Data: " << std::endl;
    std::cout << "Number: " << deserializedData->number << std::endl;
    std::cout << "Text: " << deserializedData->text << std::endl;

    // Check if the deserialized pointer matches the original pointer
    if (deserializedData == &data)
        std::cout << "\nSuccess! The deserialized pointer matches the original pointer." << std::endl;
	else
        std::cout << "\nError: The deserialized pointer does not match the original pointer." << std::endl;

    return 0;
}