/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:44:43 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/09/20 15:10:35 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span {
    private:
        std::vector<int> _numbers;
        unsigned int _maxSize;

    public:
        Span();
        Span(unsigned int n);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();
        
        void addNumber(int number);
        int shortestSpan() const;
        int longestSpan() const;

        template <typename T>
        void addNumbers(T begin, T end) {
            unsigned int rangSize = static_cast<unsigned int>(std::distance(begin, end));
            if (_numbers.size() + rangSize > _maxSize) {
                throw std::length_error("Span is full, cannot add more numbers.");
            }
            _numbers.insert(_numbers.end(), begin, end);
        }
};

#endif

