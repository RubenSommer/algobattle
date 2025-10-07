#include "generator.h"


static std::mt19937 generator(static_cast<unsigned int>(std::time(0)));

BrazilianSalesmanInstance BrazilianSalesmanGenerator::generate(double min_weight, double max_weight) {

    std::uniform_int_distribution<int> num_vertices_dist(0, 50);
    int num_vertices = num_vertices_dist(generator);
    
    BrazilianSalesmanInstance instance;
    instance.num_vertices = num_vertices;
    instance.start_vertex = 0;

    std::uniform_real_distribution<double> dist(min_weight, max_weight);

    // Generowanie grafu pełnego (K_N): każda para wierzchołków jest połączona
    for (int u = 0; u < num_vertices; ++u) {
        for (int v = u + 1; v < num_vertices; ++v) {
            // Dodaj krawędź
            instance.edges.push_back({u, v});
            int weight = -1;
            //to play a bit with solver
            if(v%21 == 0) weight = 1;
            else weight = (int)dist(generator);
            
            
            instance.edge_weights.push_back(weight);
        }
    }

    std::uniform_int_distribution<int> start_dist(0, num_vertices - 1);
    instance.start_vertex = start_dist(generator);

    return instance;
}
