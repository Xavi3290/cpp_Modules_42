/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:48:58 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/09/20 12:32:09 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main() {
    Serializer::Data data;
    data.value = 42;
    
    Serializer::Data *dataPtr = &data;
    uintptr_t raw = Serializer::serialize(dataPtr);
    Serializer::Data *deserializedDataPtr = Serializer::deserialize(raw);
    
    std::cout << "Original value: " << data.value << std::endl;
    std::cout << "Serialized value (uintptr_t): " << raw << std::endl;
    std::cout << "Deserialized value: " << deserializedDataPtr->value << std::endl;
    if (dataPtr == deserializedDataPtr) {
        std::cout << "Serialization and deserialization successful!" << std::endl;
    } else {
        std::cout << "Serialization and deserialization failed!" << std::endl;
    }

    return 0;
}

