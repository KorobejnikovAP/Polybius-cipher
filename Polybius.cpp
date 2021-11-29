// Copyright 2021 Korobejnikov Alexander
#include <math.h>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <random>
#include "Polybius.h"

std::vector<std::vector<char>> createLatinAlph() {
    int n = 5;
    std::vector<std::vector<char>> vec(n);
    for (int i = 0; i < n; ++i) {
        vec[i].resize(n);
        for (int j = 0; j < n; ++j) {
            vec[i][j] = 'a' + n*i + j;
        }
    }
    return vec;
}

std::vector<std::vector<char>> createAlph(std::string str) {
    int len = str.length();
    double eps = 1e-8;
    int n = ceil(sqrt(len) - eps);
    int k = 48;
    std::vector<std::vector<char>> vec(n);
    for (int i = 0; i < n; ++i) {
        vec[i].resize(n);
        for (int j = 0; j < n; ++j) {
            if (i*n + j < len) {
                vec[i][j] = str[n*i + j];
            } else {
                vec[i][j] = k++;
            }
        }
    }
    return vec;
}

void printAlph(std::vector<std::vector<char>> vec) {
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < vec.size(); ++j) {
            std::cout << vec[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

std::string PolybiusCode(std::string str, std::vector<std::vector<char>> alph) {
    std::vector<std::pair<int, int>> vecPair;
    std::vector<std::pair<int, int>> resPair;
    std::string res = "";
    int len = str.length();
    for (int c = 0; c < len; ++c) {
        for (int i = 0; i < alph.size(); ++i) {
            bool flag = false;
            for (int j = 0; j < alph.size(); ++j) {
                if (alph[i][j] == str[c]) {
                    flag = true;
                    vecPair.push_back(std::make_pair(j, i));
                    break;
                }
            }
            if (flag == true) {
                break;
            }
        }
    }
    bool flag_even = (len % 2 == 0) ? true : false;
    if (flag_even) {
        for (int i = 0; i < len; i+=2) {
            resPair.push_back(
                std::make_pair(vecPair[i].first, vecPair[i+1].first));
        }
        for (int i = 0; i < len; i+=2) {
            resPair.push_back(
                std::make_pair(vecPair[i].second, vecPair[i+1].second));
        }
    } else {
        for (int i = 0; i < len-1; i+=2) {
            resPair.push_back(
                std::make_pair(vecPair[i].first, vecPair[i+1].first));
        }
        resPair.push_back(
            std::make_pair(vecPair[len-1].first, vecPair[0].second));
        for (int i = 1; i < len; i+=2) {
            resPair.push_back(
                std::make_pair(vecPair[i].second, vecPair[i+1].second));
        }
    }
    for (int i = 0; i < len; ++i) {
        res += alph[resPair[i].second][resPair[i].first];
    }
    return res;
}
