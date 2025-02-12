/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:08:23 by xavi              #+#    #+#             */
/*   Updated: 2025/02/12 18:44:58 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed orientation(Point const a, Point const b, Point const c) {
    return ((a.getX() - c.getX()) * (b.getY() - c.getY()) -
            (b.getX() - c.getX()) * (a.getY() - c.getY()));
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed o1 = orientation(point, a, b);
    Fixed o2 = orientation(point, b, c);
    Fixed o3 = orientation(point, c, a);

    return ((o1 > 0 && o2 > 0 && o3 > 0) || (o1 < 0 && o2 < 0 && o3 < 0));

}
