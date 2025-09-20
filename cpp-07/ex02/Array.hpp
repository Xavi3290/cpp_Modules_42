/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:17:58 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/09/20 15:07:23 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array {
    private:
        unsigned int _size;
        T *_data;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array &other);
        ~Array();
        
        Array &operator=(const Array &other);
        T &operator[](unsigned int index);
        unsigned int size() const;
        
        class OutOfBoundsException : public std::exception {
            public:
                virtual const char* what() const throw();
        };      
};

template <typename T>
Array<T>::Array() : _size(0), _data(NULL) {}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n), _data(new T[n]()) {}

template <typename T>
Array<T>::Array(const Array &other) {
    _size = other._size;
    _data = new T[other._size]();
    for (unsigned int i = 0; i < _size; ++i) {
        _data[i] = other._data[i];
    }
}

template <typename T>
Array<T>::~Array() {
    if (_data) {
        delete[] _data;
    }
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
    if (this != &other) {
        if (_data) {
            delete[] _data;
        }
        _size = other._size;
        if (_size > 0) {
            _data = new T[_size];
        } else {
            _data = NULL;
        }
        for (unsigned int i = 0; i < _size; ++i) {
            _data[i] = other._data[i];
        }
    }
    
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index) {
    if (index >= _size) {
        throw OutOfBoundsException();
    }  
    return _data[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw() {
    return "Index out of bounds";
}

#endif

