//
// Created by teoal on 12/5/2024.
//
#pragma once

#include <iostream>
#include <set>
#include <string>
#include "Common.h"

namespace Day2 {
    using namespace Common;

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
        const int total_similarity = find_similarity();
        std::cout << "Total Distance: " << total_similarity << std::endl;
    }
}
