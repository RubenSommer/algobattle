#include <iostream>
#include <unordered_map>
#include <vector>
#include <fstream>
#include "json.hpp"
#include "io.hpp"

#include <random>
#include <algorithm>

using ull = unsigned long long;
using ll = long long;


ull generate_rand_number() {
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<ull> dist(1, (1ULL << 63) - 1);
    ull random_number = dist(gen);
    return random_number;
}

std::vector<ull> generator(int max_size, int max_fake_pairs) {
    std::vector<ull> instance;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, max_size-1);

    if(max_size < 4) {
        return {};
    }

    for(int i=0; i < max_size-4; ++i) {
        ull rand = generate_rand_number();
        instance.emplace_back(rand);
    }

    for(int j = 0; j < max_fake_pairs; ++j) {
        std::vector<int> fake_pairs;

        for(int k = 0; k < 4; ++k) {
            int rand_fake = dist(gen);
            fake_pairs.emplace_back(rand_fake);
        }

        instance[fake_pairs[1]] = instance[fake_pairs[0]];
        instance[fake_pairs[2]] = instance[fake_pairs[0]]-1;
        instance[fake_pairs[3]] = instance[fake_pairs[0]];

    }

    ull rand1 = generate_rand_number();
    ull rand2 = generate_rand_number();
    ull temp1 = rand1 + rand2;
    ull rand_temp = dist(gen) % (temp1);
    temp1 -= rand_temp;
    ull temp2 = rand_temp;
    instance.emplace_back(rand1);
    instance.emplace_back(rand2);
    instance.emplace_back(temp1);
    instance.emplace_back(temp2);

    
    std::shuffle(instance.begin(), instance.end(), gen);

    std::vector<int> certificate(4);

    for(int l = 0; l < max_size; ++l) {
        if(instance[l] == rand1) {
            certificate[0] = l;
        }
        else if (instance[l] == rand2) {
            certificate[1] = l;
        }
        else if(instance[l] == temp1) {
            certificate[2] = l;
        }
        else if(instance[l] == temp2) {
            certificate[3] = l;
        }
    }

    write_solution(certificate);

    return instance;
}

int main() {
    int max_size = read_max_size();
    std::vector<ull> instance = generator(max_size, max_size/16);
    write_instance(instance);

    return 0;
}