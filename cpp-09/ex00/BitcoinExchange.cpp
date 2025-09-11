/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:25:09 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/09/11 12:15:42 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <sstream>
#include <ctime>

static std::string trim(const std::string &str) {
    size_t start = str.find_first_not_of(" \t\n\r");
    if (start == std::string::npos) {
        return "";
    }
    size_t end = str.find_last_not_of(" \t\n\r");
    return str.substr(start, end - start + 1);
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _data(other._data) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other) {
        _data = other._data;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string &dbFile) {
    std::ifstream file(dbFile.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Could not open database file: " + dbFile);
    }

    std::string line;
    if (std::getline(file, line) && line.find("date,exchange_rate") != std::string::npos) {
    }else {
        file.clear();
        file.seekg(0);
    }
    
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date, priceStr;
        if (!std::getline(ss, date, ',') || !std::getline(ss, priceStr)) {
            continue;
        }
        date = trim(date);
        priceStr = trim(priceStr);
        std::stringstream ps(priceStr);
        double price;
        if (!(ps >> price) || !ps.eof())
            continue;
        _data[date] = price;
    }
}

void BitcoinExchange::processInput(const std::string &inputFile) const {
    std::ifstream file(inputFile.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Could not open input file: " + inputFile);
    }
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }
        try {
            size_t pipe = line.find('|');
            if (pipe == std::string::npos) {
                throw std::invalid_argument("Invalid input format: " + line);
            }
            std::string date = trim(line.substr(0, pipe));
            std::string valueStr = trim(line.substr(pipe + 1));
            validateDate(date);
            double value = parseValue(valueStr);
            double rate = findRate(date);
            double result = value * rate;
            std::cout << date << " => " 
                      << value << " = " 
                      << result << std::endl;
        } catch (const std::invalid_argument &e) {
            std::string msg = e.what();
            if (msg == "not a positive number." || msg == "too large a number.")
                std::cerr << "Error: " << msg << std::endl;
            else
                std::cerr << "Error: bad input => " << line << std::endl;
        } catch (const std::runtime_error &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}

void BitcoinExchange::validateDate(const std::string &date) const {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        throw std::invalid_argument(date);

    int y, m, d;
    char dash1, dash2;
    std::istringstream ss(date);
    if (!(ss >> y >> dash1 >> m >> dash2 >> d) ||
        dash1 != '-' || dash2 != '-' || !ss.eof())
    {
        throw std::invalid_argument(date);
    }

    if (m < 1 || m > 12 || d < 1 || d > 31)
        throw std::invalid_argument(date);

    std::tm tmv;
    tmv.tm_year = y - 1900;
    tmv.tm_mon  = m - 1;
    tmv.tm_mday = d;
    tmv.tm_hour = 0;
    tmv.tm_min  = 0;
    tmv.tm_sec  = 0;
    tmv.tm_isdst = -1;

    if (std::mktime(&tmv) == -1 ||
        tmv.tm_year != y - 1900 ||
        tmv.tm_mon  != m - 1   ||
        tmv.tm_mday != d)
    {
        throw std::invalid_argument(date);
    }
}

double BitcoinExchange::findRate(const std::string &date) const {
    std::map<std::string, double>::const_iterator it = _data.upper_bound(date);
    if (it == _data.begin()) {
        throw std::runtime_error("No data available for date: " + date);
    }
    -- it;
    return it->second;
}

double BitcoinExchange::parseValue(const std::string &token) const {
    std::stringstream ss(token);
    double value;
    if (!(ss >> value) || !ss.eof()) {
        throw std::invalid_argument("Invalid value format: " + token);
    }
    if (value < 0) {
        throw std::invalid_argument("not a positive number.");
    }
    if (value > 1000) {
        throw std::invalid_argument("too large a number.");
    }
    return value;
}
