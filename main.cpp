#include "generator.h"
#include <iostream>

/**
 * @brief Główna funkcja do demonstrowania generatora.
 */
int main() {
    BrazilianSalesmanGenerator generator;

    // --- Parametry dla generatora ---
    int N = 7;           // Liczba wierzchołków
    double min_W = 0.0;  // Minimalna waga krawędzi
    double max_W = 18446744073709551616.0; // Maksymalna waga krawędzi
    // ---------------------------------
//    
//    std::cout << "Generowanie instancji Brazilian Salesman z N=" << N
//              << " wierzcholkami i wagami w zakresie [" << min_W << ", " << max_W << "]." << std::endl;
//    std::cout << "Instancja jest grafem pelnym K_" << N << "." << std::endl;
//    std::cout << "====================================================================" << std::endl;

    try {
        BrazilianSalesmanInstance instance = generator.generate(N, min_W, max_W);

        std::cout << instance.to_json() << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error while generating: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
