/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:51:42 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/07/23 20:07:22 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe {
    private:
        void parseArgs(int argc, char **argv, std::vector<int> &vec, std::deque<int> &deq) const;
        bool isValidNumber(const std::string &str) const;
        void printSequence(const std::string &labe, const std::vector<int> &seq) const;
        void sortVector(std::vector<int> &vec, size_t start, size_t len) const;
        void sortDeque(std::deque<int> &deq, size_t start, size_t len) const;
        void insertVector(std::vector<int> &vec, int value) const;
        void insertDeque(std::deque<int> &deq, int value) const;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        int run(int argc, char **argv) const;
};

#endif
