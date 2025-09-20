/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:41:09 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/09/20 12:30:33 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>
#include <cctype>
#include <sstream>
#include <iomanip>
#include <cmath>

class ScalarConverter {
    public:
        static void convert(const std::string &literal);
        enum Type {
            CHAR,
            INT,
            FLOAT,
            DOUBLE,
            PSEUDO,
            UNKNOWN
        };
    
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();

        static Type detectType(const std::string &literal);
};

#endif

