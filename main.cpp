#include "generator.h"
#include <iostream>
#include <stdexcept>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;
using ull = unsigned long long;


int read_max_size() {
    std::ifstream fin("/input/max_size.txt");

    if(!fin) {
        throw std::runtime_error("reading max size error: /input/max_size.txt not found or accessible.");
    }

    int max_size = -1;
    if (!(fin >> max_size)) {
         throw std::runtime_error("reading max size error: Could not read integer from file.");
    }

    fin.close();
    return max_size;
}
void write_instance(ull num_vertices, const std::vector<std::vector<int>>& edges, ull start, const std::vector<ull>& edge_weights) {
    json output_instance;
    
    output_instance["num_vertices"] = num_vertices;
    output_instance["edges"] = edges;
    output_instance["start"] = start;
    output_instance["edge_weights"] = edge_weights;

    std::ofstream fout("/output/instance.json");

    if(!fout) {
        throw std::runtime_error("writing instance error: Cannot open /output/instance.json for writing.");
    }

    fout << output_instance.dump();
    fout.close();
}

int main() {
    BrazilianSalesmanGenerator generator;

    int max_N_from_file = -1;
    try {
        max_N_from_file = read_max_size();
    } catch (const std::exception& e) {
        std::cerr << "Ostrzezenie: Nie mozna odczytac max_size. Uzywam domyslnych wartosci. " << e.what() << std::endl;
    }

    ull min_W = 1;
    ull max_W = 18446744073709551615ULL;

    // ---------------------------------
    
    try {
        BrazilianSalesmanInstance instance = generator.generate(min_W, max_W);

        write_instance(
            instance.num_vertices,
            instance.edges,
            instance.start_vertex,
            instance.edge_weights
        );

        
    } catch (const std::exception& e) {
        std::cerr << "Error while generating: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
