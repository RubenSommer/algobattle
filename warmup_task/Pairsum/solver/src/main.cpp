#include <iostream>
#include <unordered_map>
#include <vector>
#include <fstream>
#include "json.hpp"
#include "io.hpp"

using ull = unsigned long long;
using ll = long long;

//find solution to pairsum problem
bool find_equal_sum_pairs(const std::vector<ull>& L, int& a, int& b, int& c, int& d) {
    std::unordered_map<ull, std::vector<std::pair<int, int>>> sum_map;
    int n = L.size();

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ull s = L[i] + L[j];

            if (sum_map.count(s)) {
                for (const auto& p : sum_map[s]) {
                    if (p.first != i && p.first != j && p.second != i && p.second != j) {
                        a = p.first;
                        b = p.second;
                        c = i;
                        d = j;
                        return true;
                    }
                }
            }

            sum_map[s].emplace_back(i, j);
        }
    }

    return false;
}

int main() {
    int a, b, c, d;
    std::vector<ull> numbers = read_instance();
    if(find_equal_sum_pairs(numbers, a, b, c, d)) {
        write_solution({a, b, c, d});
    }
    else {
        write_solution({});
    }
    return 0;
}
