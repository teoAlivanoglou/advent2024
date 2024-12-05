//
// Created by teoal on 12/5/2024.
//
#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include "Common.h"

namespace Day1 {

    using namespace Common;

    inline int find_distance() {
        int distance = 0;

        for (int i = 0; i < left.size(); ++i) {
            distance += abs(left[i] - right[i]);
        }

        return distance;
    }

    inline void run() {
        read();
        const int total_distance = find_distance();
        std::cout << "Total Distance: " << total_distance << std::endl;
    }
}
