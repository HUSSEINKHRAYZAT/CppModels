/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:12:27 by hkhrayza          #+#    #+#             */
/*   Updated: 2025/05/25 18:12:27 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../Include/Data.hpp"
#include "../Include/Serializer.hpp"

int main(void) {
    // Create a Data object
    Data* originalData = new Data(42, "Sample Data", 3.14159);

    std::cout << "Original Data object:" << std::endl;
    std::cout << "Address: " << originalData << std::endl;
    std::cout << "ID: " << originalData->getId() << std::endl;
    std::cout << "Name: " << originalData->getName() << std::endl;
    std::cout << "Value: " << originalData->getValue() << std::endl;
    std::cout << "----------------------------" << std::endl;

    // Serialize the pointer
    uintptr_t serialized = Serializer::serialize(originalData);
    std::cout << "Serialized value (uintptr_t): " << serialized << std::endl;

    // Deserialize back to a pointer
    Data* deserializedData = Serializer::deserialize(serialized);

    std::cout << "----------------------------" << std::endl;
    std::cout << "Deserialized Data object:" << std::endl;
    std::cout << "Address: " << deserializedData << std::endl;
    std::cout << "ID: " << deserializedData->getId() << std::endl;
    std::cout << "Name: " << deserializedData->getName() << std::endl;
    std::cout << "Value: " << deserializedData->getValue() << std::endl;

    // Check if the pointers are equal
    std::cout << "----------------------------" << std::endl;
    if (originalData == deserializedData) {
        std::cout << "SUCCESS: Original and deserialized pointers are equal!" << std::endl;
    } else {
        std::cout << "ERROR: Original and deserialized pointers are not equal!" << std::endl;
    }

    // Clean up
    delete originalData;

    return 0;
}
