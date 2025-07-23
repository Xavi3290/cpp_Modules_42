/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:51:46 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/07/23 20:37:03 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>
#include <stdexcept>
#include <sstream>
#include <algorithm>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
    (void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    (void)other;
    return *this;
}

PmergeMe::~PmergeMe() {}

int PmergeMe::run(int argc, char **argv) const {
    std::vector<int> vec;
    std::deque<int> deq;
    
    try {
        parseArgs(argc, argv, vec, deq);
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    printSequence("Before: ", vec); 
    clock_t startV = std::clock();
    sortVector(vec, 0, vec.size());
    clock_t endV = std::clock();
    clock_t startD = std::clock();
    sortDeque(deq, 0, deq.size());
    clock_t endD = std::clock();
    printSequence("After: ", vec);

    std::cout << "Time to process a range of " << vec.size() << 
    " elements with std::vector : " << (endV - startV) * 1000000 /CLOCKS_PER_SEC << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() <<
    " elements with std::deque : " << (endD - startD) * 1000000 / CLOCKS_PER_SEC << " us" << std::endl;
    
    return 0;
}

bool PmergeMe::isValidNumber(const std::string &str) const {
    if (str.empty())
        return false;
    for (std::string::size_type i = 0; i < str.size(); ++i) {
        if (!std::isdigit(static_cast<unsigned char>(str[i]))) 
            return false;
    }
    std::istringstream ss(str);
    int v;
    if (!(ss >> v) || !ss.eof())
        return false;
    return v > 0;
}

void PmergeMe::parseArgs(int argc, char **argv, std::vector<int> &vec, std::deque<int> &deq) const {
    if (argc < 2) 
        throw std::invalid_argument("No input");
    for (int i = 1; i < argc; ++i) {
        if (!isValidNumber(argv[i])) 
            throw std::invalid_argument("Invalid integer");
        int value;
        std::istringstream ss(argv[i]);
        ss >> value;
        vec.push_back(value);
        deq.push_back(value);
    }
}

void PmergeMe::printSequence(const std::string &label, const std::vector<int> &seq) const {
    std::cout << label;
    for (std::vector<int>::size_type i = 0; i < seq.size(); ++i) {
        std::cout << seq[i];
        if (i + 1 < seq.size())
            std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::insertVector(std::vector<int> &vec, int value) const {
    std::vector<int>::iterator it = std::lower_bound(vec.begin(), vec.end(), value);
    vec.insert(it, value);
}

void PmergeMe::sortVector(std::vector<int> &vec, size_t start, size_t len) const {
    if (len <= 1)
        return;
    std::vector<int> A;
    std::vector<int> B;
    A.reserve((len + 1) / 2);
    B.reserve(len / 2);
    size_t i;

    for (i = 0; i + 1 < len; i += 2) {
        int x = vec[start + i];
        int y = vec[start + i + 1];
        if (x < y) {
            A.push_back(x);
            B.push_back(y);
        } else {
            A.push_back(y);
            B.push_back(x);
        }
    }
    bool hasExtra = (len % 2 == 1);
    int extra = 0;
    if (hasExtra) 
        extra = vec[start + len - 1];
    
    sortVector(A, 0, A.size());
    for (size_t j = 0; j < B.size(); ++j) 
        insertVector(A, B[j]);
    if (hasExtra) 
        insertVector(A, extra);
    for (size_t j = 0; j < A.size(); ++j)
        vec[start + j] = A[j];
}

void PmergeMe::insertDeque(std::deque<int> &deq, int value) const {
    std::deque<int>::iterator it = std::lower_bound(deq.begin(), deq.end(), value);
    deq.insert(it, value);
}

void PmergeMe::sortDeque(std::deque<int> &deq, size_t start, size_t len) const {
    if (len <= 1)
        return;
    std::deque<int> A;
    std::deque<int> B;
    size_t i;

    for (i = 0; i + 1 < len; i += 2) {
        int x = deq[start + i];
        int y = deq[start + i + 1];
        if (x < y) {
            A.push_back(x);
            B.push_back(y);
        } else {
            A.push_back(y);
            B.push_back(x);
        }
    }
    bool hasExtra = (len % 2 == 1);
    int extra = 0;
    if (hasExtra) 
        extra = deq[start + len - 1];
    
    sortDeque(A, 0, A.size());
    for (size_t j = 0; j < B.size(); ++j) 
        insertDeque(A, B[j]);
    if (hasExtra) 
        insertDeque(A, extra);
    for (size_t j = 0; j < A.size(); ++j)
        deq[start + j] = A[j];
}
