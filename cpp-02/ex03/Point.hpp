/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:08:31 by xavi              #+#    #+#             */
/*   Updated: 2025/02/06 18:10:33 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
    private:
        const Fixed _x;
        const Fixed _y;

    public:
        Point();
        Point(const float x, const float y);
        Point(const Point &point);
        Point &operator=(const Point &point);
        ~Point();
        
        Fixed getX() const;
        Fixed getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif