//
// Created by teoal on 12/5/2024.
//
#pragma once

#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include "Common.h"

namespace Day1 {
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


    inline int find_distance() {
        int distance = 0;

        for (int i = 0; i < left.size(); ++i) {
            distance += abs(left[i] - right[i]);
        }

        return distance;
    }

    inline int find_similarity() {
        int similarity = 0;

        const auto right_set = std::multiset(right.begin(), right.end());

        for (int i: left) {
            similarity += abs(i * static_cast<int>(right_set.count(i)));
        }

        return similarity;
    }

    inline void run() {
        read();
        const int total_distance = find_distance();
        const int total_similarity = find_similarity();
        std::cout << "Total Distance: " << total_distance << std::endl;
        std::cout << "Total Similarity: " << total_similarity << std::endl;
    }
}
