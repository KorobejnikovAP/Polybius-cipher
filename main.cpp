// Copyright 2021 Korobejnikov Alexander
#include <thread>
#include <chrono>
#include "Polybius.h"

int main() {
    while (true) {
        std::cout << "Choose an alphabet or enter your own..." << std::endl
            << "1. Latin alphabet" << std::endl << "2. Enter your alphabet"
            << std::endl << "3. Exit" << std::endl;
        int n;
        std::string str;
        std::vector<std::vector<char>> v;
        std::cin >> n;
        switch (n) {
            case 1:
                std::cout << "Polybius square" << std::endl;
                v = createLatinAlph();
                printAlph(v);
                break;
            case 2:
                std::cout << "Enter the alphabet without spaces..."
                    << std::endl;
                std::cin >> str;
                v = createAlph(str);
                printAlph(v);
                break;
            case 3:
                return 0;
            default:
                break;
        }
        std::cout << "Enter a message..." << std::endl;
        std::string msg;
        std::cin >> msg;
        std::cout << "encrypted message : "
            << PolybiusCode(msg, v) << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}
