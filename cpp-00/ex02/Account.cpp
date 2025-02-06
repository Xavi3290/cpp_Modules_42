/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:41:29 by xavi              #+#    #+#             */
/*   Updated: 2025/02/06 18:04:46 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    _nbAccounts++;
    _totalAmount += initial_deposit;
    
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";created" << std::endl;    
}

Account::~Account() 
{
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";closed" << std::endl; 
}

void Account::_displayTimestamp()
{
    std::time_t now = std::time(0);
    std::tm *ltm = std::localtime(&now);
    std::cout << std::setfill('0') << "[" << 1900 + ltm->tm_year
              << std::setw(2) << 1 + ltm->tm_mon
              << std::setw(2) << ltm->tm_mday << "_"
              << std::setw(2) << ltm->tm_hour
              << std::setw(2) << ltm->tm_min
              << std::setw(2) << ltm->tm_sec << "]";
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex
              << ";p_amount:" << this->_amount
              << ";deposit:" << deposit;
    this->_amount += deposit;
    this->_nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    
    std::cout << ";amount:" << this->_amount
              << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex
              << ";p_amount:" << this->_amount
              << ";withdrawal:";
    
    if (withdrawal > this->_amount)
    {
        std::cout << "refused" << std::endl;
        return false;
    }
    
    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;

    std::cout << withdrawal
              << ";amount:" << this->_amount
              << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return true;
}

void Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";deposits:" << this->_nbDeposits
              << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << " accounts:" << _nbAccounts
              << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

int Account::checkAmount() const
{
    return this->_amount;
}

int Account::getNbAccounts()
{
    return _nbAccounts;
}

int Account::getTotalAmount()
{
    return _totalAmount;
}

int Account::getNbDeposits()
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
    return _totalNbWithdrawals;
}
