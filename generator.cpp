#include "generator.h"

// Używamy std::mt19937 jako generatora liczb pseudolosowych dla lepszej jakości
static std::mt19937 generator(static_cast<unsigned int>(std::time(0)));

BrazilianSalesmanInstance BrazilianSalesmanGenerator::generate(int num_vertices, double min_weight, double max_weight) {
    if (num_vertices < 2) {
        throw std::invalid_argument("too low number of vertices");
    }
    
    BrazilianSalesmanInstance instance;
    instance.num_vertices = num_vertices;
    instance.start_vertex = 0;

    // Rozkład jednostajny dla wag krawędzi (możemy użyć double)
    std::uniform_real_distribution<double> dist(min_weight, max_weight);

    // Generowanie grafu pełnego (K_N): każda para wierzchołków jest połączona
    for (int u = 0; u < num_vertices; ++u) {
        for (int v = u + 1; v < num_vertices; ++v) {
            // Dodaj krawędź
            instance.edges.push_back({u, v});
            
            // Losuj wagę
            double weight = dist(generator);
            instance.edge_weights.push_back(weight);
        }
    }

    // Opcjonalnie: losowe wybranie wierzchołka startowego
    std::uniform_int_distribution<int> start_dist(0, num_vertices - 1);
    instance.start_vertex = start_dist(generator);

    return instance;
}
