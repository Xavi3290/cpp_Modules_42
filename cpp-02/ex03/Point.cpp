/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:08:28 by xavi              #+#    #+#             */
/*   Updated: 2025/02/06 18:10:28 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point &point) : _x(point._x), _y(point._y) {}

Point &Point::operator=(const Point &point) {
    (void)point;
    return *this;
}

Point::~Point() {}

Fixed Point::getX() const {
    return _x;
}

Fixed Point::getY() const {
    return _y;
}
