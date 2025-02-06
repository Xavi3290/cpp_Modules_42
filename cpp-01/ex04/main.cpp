/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:59:04 by xavi              #+#    #+#             */
/*   Updated: 2025/02/06 18:07:07 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

void   replaceInFile(const std::string &filename, const std::string &s1, const std::string &s2) {
    std::ifstream inputFile(filename.c_str());
    if (!inputFile) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }
    
    std::string outputFilename = filename + ".replace";
    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile) {
        std::cerr << "Error: Could not creat output file " << outputFilename << std::endl;
        return;
    }
    
    std::string line;
    while (std::getline(inputFile, line)) {
        std::string newLine;
        size_t pos = 0;
        while (pos < line.length()) {
            size_t found = line.find(s1, pos);
            if(found !=std::string::npos) {
                newLine.append(line, pos, found - pos);  // Copy characthers that not are s1
                newLine.append(s2);                     // Insert s2 in place of s1
                pos = found + s1.length();              // Move pos to the end of s1
            } else {
                newLine.append(line, pos, line.length() -pos);
                break;
            }
        }
        outputFile << newLine << std::endl;
    }
    inputFile.close();
    outputFile.close();
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " filename s1 s2" << std::endl;
        return 1;
    }
    
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    
    if (s1.empty() || s2.empty()) {
        std::cerr << "Error: s1 and s2 must not be empty" << std::endl;
        return 1;
    }

    replaceInFile(filename, s1, s2);
    return 0;
}