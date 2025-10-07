#pragma once

#include <vector>
#include <random>
#include <ctime>
#include <iostream>
#include <sstream>
#include <algorithm>

// Struktura do przechowywania wygenerowanej instancji (jak w opisie problemu)
struct BrazilianSalesmanInstance {
    int num_vertices;
    std::vector<std::vector<int>> edges;
    int start_vertex;
    std::vector<double> edge_weights;

    // Metoda do konwersji instancji na format JSON (uproszczony dla podglądu)
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
    /**
     * @brief Generuje losową instancję problemu Brazilian Salesman.
     * * @param num_vertices Liczba wierzchołków w grafie.
     * @param min_weight Minimalna waga krawędzi.
     * @param max_weight Maksymalna waga krawędzi.
     * @return Wygenerowana instancja.
     */
    BrazilianSalesmanInstance generate(double min_weight, double max_weight);
};
