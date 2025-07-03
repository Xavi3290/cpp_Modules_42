/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:06:25 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/07/03 16:35:01 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "TOP:" << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "SIZE:" << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "Iterating through MutantStack:" << std::endl;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);

    std::cout << std::endl;

    MutantStack<std::string> mstackStr;
    mstackStr.push("Hello");
    mstackStr.push("Mutant");
    mstackStr.push("Stack");
    std::cout << "TOP: " << mstackStr.top() << std::endl;
    mstackStr.pop();
    std::cout << "SIZE: " << mstackStr.size() << std::endl;
    mstackStr.push("C++");
    mstackStr.push("is");
    mstackStr.push("awesome");
    mstackStr.push("!");
    MutantStack<std::string>::iterator itStr = mstackStr.begin();
    MutantStack<std::string>::iterator iteStr = mstackStr.end();
    ++itStr;
    --itStr;
    std::cout << "Iterating through MutantStack of strings:" << std::endl;
    while (itStr != iteStr)
    {
        std::cout << *itStr << std::endl;
        ++itStr;
    }
    std::stack<std::string> sStr(mstackStr);
    
    return 0;
}
