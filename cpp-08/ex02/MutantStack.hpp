/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:06:21 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/09/20 15:11:27 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        typedef std::stack<T> stack;
        typedef typename stack::container_type container;
        typedef typename container::iterator iterator;

        MutantStack() : stack() {}

        MutantStack(const MutantStack &other) : stack(other) {}

        MutantStack &operator=(const MutantStack &other) {
            if (this != &other) {
                *this = other;
            }
            return *this;
        }

        ~MutantStack() {}

        iterator begin() {
            return this->c.begin();
        }

        iterator end() {
            return this->c.end();
        }
};

#endif

