#ifndef IO_HPP
#define IO_HPP

#include <vector>
using ull = unsigned long long;

// read instance.json
std::vector<ull> read_instance();

// write instance.json
void write_instance(std::vector<ull> numbers);

// read max_size.txt
int read_max_size();

// write the solution to output.json (indices)
void write_solution(const std::vector<int> & indices);

#endif