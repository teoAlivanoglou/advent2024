//
// Created by teoal on 12/5/2024.
//
#pragma once

#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include "Common.h"

namespace Day2 {
    inline bool validate(int num1, int num2) {
        return true;
    }

    inline void read_and_count_valid(int &total_strict_valid, int &total_loose_valid) {
        std::ifstream file("input_2.txt");
        std::string line;


        // std::vector<int> numbers;

        if (file.is_open()) {
            while (std::getline(file, line)) {
                // numbers.clear();
                int last_number;
                int second_last_number;
                bool last_number_set = false;

                bool ascending = true;
                bool direction_found = false;
                bool tolerate_used = false;

                bool valid = true;
                int num;
                std::stringstream string_stream(line);

                while (valid && string_stream >> num) {
                    if (!last_number_set) {
                        last_number_set = true;
                        valid = true;
                    } else {
                        // int last = numbers.back();
                        int diff = (last_number - num);

                        if (!direction_found) {
                            ascending = diff >= 0;
                            direction_found = true;
                        }

                        valid = abs(diff) >= 1 && abs(diff) <= 3 && (ascending == diff >= 0);

                        if (!valid ) {
                            if (!tolerate_used) {
                                tolerate_used = true;
                                valid = true;
                                continue;
                            }
                            else {
                                int diff = (second_last_number - num);

                                // if (!direction_found) {
                                    ascending = diff >= 0;
                                    direction_found = true;
                                // }

                                valid = abs(diff) >= 1 && abs(diff) <= 3 && (ascending == diff >= 0);
                            }
                        }
                    }
                    // TODO: FIX THAT SHIT.... I REALLY WANT TO DO IT WITHOUT A VECTOR
                    second_last_number = last_number;

                    if (valid) {
                        last_number = num;
                    }
                        // numbers.push_back(num);
                }
                if (valid) {
                    if (!tolerate_used) {
                        total_strict_valid++;
                        std::cout << "Line " << line << " -> strict\n";
                    } else {
                        std::cout << "Line " << line << " -> loose\n";
                    }
                    total_loose_valid++;
                }
            }
        }

        // return total_valid;
    }


    // inline int count_valid() {
    //     int valid = 0;
    //
    //     const auto right_set = std::multiset(right.begin(), right.end());
    //
    //     for (int i: left) {
    //         similarity += abs(i * static_cast<int>(right_set.count(i)));
    //     }
    //
    //     return similarity;
    // }

    inline void run() {
        int total_strict = 0;
        int total_loose = 0;
        read_and_count_valid(total_strict, total_loose);
        // const int total_similarity = find_similarity();
        std::cout << "Total Strict Valid: " << total_strict << std::endl;
        std::cout << "Total Loose Valid: " << total_loose << std::endl;
    }
}
