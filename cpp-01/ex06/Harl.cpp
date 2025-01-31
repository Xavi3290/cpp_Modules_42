/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xavi <xavi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:55:14 by xavi              #+#    #+#             */
/*   Updated: 2025/01/31 19:07:59 by xavi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug() {
    std::cout << "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info() {
    std::cout << "[INFO] I cannot believe adding extra bacon costs more money. You didn’t put \
enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() {
    std::cout << "[WARNING] I think I deserve to have some extra bacon for free. I’ve been coming for \
years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
    std::cout << "[ERROR] This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;

    while (i < 4 && levels[i] != level)
        i++;
    
    switch(i) {
        case 0: 
            debug(); 
        case 1: 
            info(); 
        case 2:
            warning(); 
        case 3:
            error(); 
            break;
        default: std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}
