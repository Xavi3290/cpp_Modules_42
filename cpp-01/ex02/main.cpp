/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xavi <xavi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:51:43 by xavi              #+#    #+#             */
/*   Updated: 2025/01/26 20:09:28 by xavi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main () {
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;  // Pointer to str
    std::string& stringREF = str;   // Reference to str

    std::cout << "Adress of str: " << &str << std::endl;
    std::cout << "Adress of stringPTR: " << stringPTR << std::endl;
    std::cout << "Adress of stringREF: " << &stringREF << std::endl << std::endl;
    
    std::cout << "Value of str: " << str << std::endl;
    std::cout << "Value of stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value of stringREF: " << stringREF << std::endl << std::endl;
    
    return 0;
}