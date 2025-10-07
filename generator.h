#pragma once

#include <vector>
#include <random>
#include <ctime>
#include <iostream>
#include <sstream>
#include <algorithm>

using ull = unsigned long long;


struct BrazilianSalesmanInstance {
    
    ull num_vertices;
    std::vector<std::vector<int>> edges;
    ull start_vertex;
    std::vector<ull> edge_weights;

    
    std::string to_json() const {
        std::stringstream ss;
        ss << "{\n";
        ss << "  \"num_vertices\": " << num_vertices << ",\n";
        ss << "  \"edges\": [\n";
        for (size_t i = 0; i < edges.size(); ++i) {
         
            ss << "    [" << edges[i][0] << ", " << edges[i][1] << "]";
            if (i < edges.size() - 1) ss << ",";
            ss << "\n";
        }
        ss << "  ],\n";
        ss << "  \"start\": " << start_vertex << ",\n";
        ss << "  \"edge_weights\": [\n";
        for (size_t i = 0; i < edge_weights.size(); ++i) {
            // Wypisujemy ull
            ss << "    " << edge_weights[i];
            if (i < edge_weights.size() - 1) ss << ",";
            ss << "\n";
        }
        ss << "  ]\n";
        ss << "}";
        return ss.str();
    }
};

class BrazilianSalesmanGenerator {
public:
    BrazilianSalesmanInstance generate(ull min_weight, ull max_weight);
};
