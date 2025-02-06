/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:58:00 by xavi              #+#    #+#             */
/*   Updated: 2025/02/06 18:10:19 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main() {
    Point a(0, 0);
    Point b(10, 0);
    Point c(5, 10);
    
    Point inside(5, 5);
    Point outside(30, 5);
    Point onEdge(5, 0);
    Point vertex (0, 0);   
    
    std::cout << "Inside: " << bsp(a, b, c, inside) << std::endl;
    std::cout << "Outside: " << bsp(a, b, c, outside) << std::endl;
    std::cout << "On edge: " << bsp(a, b, c, onEdge) << std::endl;
    std::cout << "Vertex: " << bsp(a, b, c, vertex) << std::endl;

    return 0; 
}