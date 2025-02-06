/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:51:43 by xavi              #+#    #+#             */
/*   Updated: 2025/02/06 18:06:04 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main () {
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "Adress of str: " << &str << std::endl;
    std::cout << "Adress of stringPTR: " << stringPTR << std::endl;
    std::cout << "Adress of stringREF: " << &stringREF << std::endl << std::endl;
    
    std::cout << "Value of str: " << str << std::endl;
    std::cout << "Value of stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value of stringREF: " << stringREF << std::endl << std::endl;
    
    return 0;
}