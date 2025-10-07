#include "generator.h"
#include <stdexcept> 

using ull = unsigned long long;

static std::mt19937 generator(static_cast<unsigned int>(std::time(0)));

BrazilianSalesmanInstance BrazilianSalesmanGenerator::generate(ull min_weight, ull max_weight) {

    const int MIN_N = 5;
    const int MAX_N = 50;
    std::uniform_int_distribution<int> num_vertices_dist(MIN_N, MAX_N);
    int num_vertices_int = num_vertices_dist(generator);

    if (num_vertices_int < 2) {
        throw std::runtime_error("Liczba wierzcholkow mniejsza niz 2.");
    }
    
    BrazilianSalesmanInstance instance;
    instance.num_vertices = num_vertices_int;
    instance.start_vertex = 0;

    if (min_weight > max_weight) {
        std::swap(min_weight, max_weight);
    }
    std::uniform_int_distribution<ull> dist(min_weight, max_weight);

    for (int u = 0; u < num_vertices_int; ++u) {
        for (int v = u + 1; v < num_vertices_int; ++v) {
          
            instance.edges.push_back({u, v});
            ull weight;
            
            // to play a bit with solver
            if(v % 21 == 0) {
                weight = 1;
            } else {
                weight = dist(generator);
            }
            
            instance.edge_weights.push_back(weight);
        }
    }

    std::uniform_int_distribution<ull> start_dist(0, instance.num_vertices - 1);
    instance.start_vertex = start_dist(generator);

    return instance;
}

