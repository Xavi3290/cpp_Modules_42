/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 20:50:37 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/06/03 20:55:35 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T const &min(T const &a, T const &b) {
    if (a < b)
        return a;
    return b;
}

template <typename T>
T const &max(T const &a, T const &b) {
    if (a > b)
        return a;
    return b;
}

#endif