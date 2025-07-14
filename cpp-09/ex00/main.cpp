/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:27:02 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/07/14 12:30:37 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
       std::cerr << "Error: could not open file." << std::endl;
        return 1; 
    }

    const std::string dbFile = "data.csv";
    const std::string inputFile = argv[1];
    
    BitcoinExchange btc;
    try {
        btc.loadDatabase(dbFile);
        btc.processInput(inputFile);
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}