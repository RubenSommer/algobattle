#include "io.hpp"
#include <fstream>
#include "json.hpp"
#include <stdexcept>

using json = nlohmann::json;
using ull = unsigned long long;


std::vector<ull> read_instance() {
    std::ifstream fin("/input/instance.json");
    
    if(!fin) {
        throw std::runtime_error("reading instance error");
        return {};
    }

    json input_instance;
    fin >> input_instance;
    fin.close();
    
    std::vector<ull> numbers;

    if (input_instance.contains("numbers") && input_instance["numbers"].is_array()) {
        for (json& v : input_instance["numbers"])
            numbers.push_back(static_cast<ull>(v.get<ull>()));
    }

    return numbers;
}

void write_instance(std::vector<ull> numbers) {
    json output_instance;
    output_instance["numbers"] = numbers;
    std::ofstream fout("/output/instance.json");

    if(!fout) {
        throw std::runtime_error("writing output error");
        return;
    }

    fout << output_instance.dump();
    fout.close();
}

int read_max_size() {
    std::ifstream fin("/input/max_size.txt");

    if(!fin) {
        throw std::runtime_error("reading max size error");
        return -1;
    }

    int max_size = -1;
    fin >> max_size;

    return max_size;
}

void write_solution(const std::vector<int>& indices) {
    json ouput_solution;
    ouput_solution["indices"] = indices;
    std::ofstream fout("/output/solution.json");

    if(!fout) {
        throw std::runtime_error("writing output error");
        return;
    }

    fout << ouput_solution.dump();
    fout.close();
}