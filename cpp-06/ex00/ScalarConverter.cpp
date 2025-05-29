/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:41:14 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/05/29 23:31:27 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::Type ScalarConverter::detectType(const std::string &literal) {
    if (literal == "nan" || literal == "nanf" || literal == "+inf" || 
        literal == "+inff" || literal == "-inf" || literal == "-inff")
        return PSEUDO;
    if (literal.size() == 1 && !std::isdigit(literal[0]))
        return CHAR;
    if (!literal.empty() && literal[literal.size() - 1]  == 'f') {
        bool dot = false;
        for (size_t i = 0; i + 1 < literal.size(); ++i) {
            char c = literal[i];
            if (c == '.') {
                if (dot)
                    return UNKNOWN;
                dot = true;
            } else if (!std::isdigit(c) && !(i == 0 && (c == '-' || c == '+'))) {
                return UNKNOWN;
            }
        }
        return FLOAT;
    }
    if (literal.find('.') != std::string::npos) {
        bool dot = false;
        for (size_t i = 0; i < literal.size(); ++i) {
            char c = literal[i];
            if (c == '.') {
                if (dot)
                    return UNKNOWN;
                dot = true;
            } else if (!std::isdigit(c) && !(i == 0 && (c == '-' || c == '+'))) 
                return UNKNOWN;  
        } 
        return DOUBLE;
    }
    for (size_t i = 0; i < literal.size(); ++i) {
        char c = literal[i];
        if (!std::isdigit(c) && !(i == 0 && (c == '-' || c == '+')))
            return UNKNOWN;
    }
    return INT;
}

static void printChar(double v) {
    std::cout << "char: ";
    if (std::isnan(v) || std::isinf(v) || v < std::numeric_limits<char>::min() || v > std::numeric_limits<char>::max()) 
        std::cout << "impossible" << std::endl;
    else {
        char c = static_cast<char>(v);
        if (std::isprint(c))
            std::cout << "'" << c << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    }
}

static void printInt(double v) {
    std::cout << "int: ";
    if (std::isnan(v) || std::isinf(v) || v < std::numeric_limits<int>::min() || v > std::numeric_limits<int>::max()) 
        std::cout << "impossible" << std::endl;
    else 
        std::cout << static_cast<int>(v) << std::endl;
}

static void printFloat(double v) {
    std::cout << "float: ";
    if (std::isnan(v))
        std::cout << "nanf" << std::endl;
    else if (std::isinf(v))
        if (v > 0) 
            std::cout << "+inff" << std::endl;
        else
            std::cout << "-inff" << std::endl;
    else if (v < -std::numeric_limits<float>::max() || v >  std::numeric_limits<float>::max())
          std::cout << "impossible" << std::endl;
    else 
        std::cout << std::fixed << std::setprecision(1) << static_cast<float>(v) << "f" << std::endl;
}

static void printDouble(double v) {
    std::cout << "double: ";
    if (std::isnan(v))
        std::cout << "nan" << std::endl;
    else if (std::isinf(v))
        if (v > 0) 
            std::cout << "+inf" << std::endl;
        else
            std::cout << "-inf" << std::endl;
    else 
        std::cout << std::fixed << std::setprecision(1) << v << std::endl;
}

void ScalarConverter::convert(const std::string &literal) {
    Type t = detectType(literal);
    double value;
    bool ok = true;

    switch(t) {
        case PSEUDO: {
            std::string s = literal;
            if (!s.empty() && s[s.size() - 1] == 'f')
                s.erase(s.size() - 1, 1);
            if (s == "nan")
                value = std::numeric_limits<double>::quiet_NaN();
            else if (s[0] == '-')
                value = -std::numeric_limits<double>::infinity();
            else
                value = std::numeric_limits<double>::infinity();
            break;
        }
        case CHAR: {
            value = static_cast<double>(literal[0]);
            break;
        }
        case FLOAT: {
            std::istringstream iss(literal.substr(0, literal.size() - 1));
            float f;
            ok = !!(iss >> f) && iss.peek() == std::char_traits<char>::eof();
            value = static_cast<double>(f);
            break;
        }
        case DOUBLE: {
            std::istringstream iss(literal);
            double d;
            ok = !!(iss >> d) && iss.peek() == std::char_traits<char>::eof();
            value = d;
            break;        
        }
        case INT: {
            std::istringstream iss(literal);
            long l;
            ok = !!(iss >> l) && iss.peek() == std::char_traits<char>::eof();
            value = static_cast<double>(l);
            break;
        }
        case UNKNOWN:
        default:
            ok = false;
    }

    if (!ok) {
        std::cout << "char: impossible\n" 
                  << "int: impossible\n"
                  << "float: impossible\n"
                  << "double: impossible" << std::endl;  
        return;
    } 
    
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}
