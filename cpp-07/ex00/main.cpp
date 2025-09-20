/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 20:50:40 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/09/20 15:05:25 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

struct t_data {
    float f;
    double d;
};

int main() {
    int a = 42, b = 24;
    char c = 'A', d = 'B';
    std::string e = "Hello", f = "World";
    t_data g = {1.1f, 2.2}, h = {3.3f, 4.4};
    
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    swap(a, b);
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
    std::cout << "Before swap: c = " << c << ", d = " << d << std::endl;
    swap(c, d);
    std::cout << "After swap: c = " << c << ", d = " << d << std::endl;
    std::cout << "Before swap: e = " << e << ", f = " << f << std::endl;
    swap(e, f);
    std::cout << "After swap: e = " << e << ", f = " << f << std::endl;
    std::cout << "Before swap: g = {" << g.f << ", " << g.d << "}, h = {" << h.f << ", " << h.d << "}" << std::endl;
    swap(g, h);
    std::cout << "After swap: g = {" << g.f << ", " << g.d << "}, h = {" << h.f << ", " << h.d << "}" << std::endl;
    
    std::cout << "Min of a and b: " << min(a, b) << std::endl;
    std::cout << "Max of a and b: " << max(a, b) << std::endl;
    std::cout << "Min of c and d: " << min(c, d) << std::endl;
    std::cout << "Max of c and d: " << max(c, d) << std::endl;
    std::cout << "Min of e and f: " << ::min(e, f) << std::endl;
    std::cout << "Max of e and f: " << ::max(e, f) << std::endl;
    
    return 0;
}

