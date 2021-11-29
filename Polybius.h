// Copyright 2021 Korobejnikov Alexander

#include <vector>
#include <iostream>
#include <string>

std::vector<std::vector<char>> createLatinAlph();
std::vector<std::vector<char>> createAlph(std::string str);
void printAlph(std::vector<std::vector<char>> vec);
std::string PolybiusCode(std::string str, std::vector<std::vector<char>> alph);
