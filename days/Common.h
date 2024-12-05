//
// Created by teoal on 12/5/2024.
//

#ifndef COMMON_H
#define COMMON_H
#include <algorithm>
#include <fstream>
#include <vector>

namespace Common {
    inline std::vector<int> left;
    inline std::vector<int> right;

    inline void read() {
        std::ifstream file("input.txt");
        std::string line;

        if (file.is_open()) {
            int l, r;
            while (file >> l >> r) {
                left.push_back(l);
                right.push_back(r);
            }

            std::sort(left.begin(), left.end());
            std::sort(right.begin(), right.end());
        }
    }
}


#endif //COMMON_H
