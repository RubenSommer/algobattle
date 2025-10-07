#include "generator.h"
#include <iostream>

/**
 * @brief Główna funkcja do demonstrowania generatora.
 */
int main() {
    BrazilianSalesmanGenerator generator;

    // --- Parametry dla generatora ---
    int min_W = 0.0;  // Minimalna waga krawędzi
    double max_W = 5000000000000000; // Maksymalna waga krawędzi
    // ---------------------------------
//    
//    std::cout << "Generowanie instancji Brazilian Salesman z N=" << N
//              << " wierzcholkami i wagami w zakresie [" << min_W << ", " << max_W << "]." << std::endl;
//    std::cout << "Instancja jest grafem pelnym K_" << N << "." << std::endl;
//    std::cout << "====================================================================" << std::endl;

    try {
        BrazilianSalesmanInstance instance = generator.generate(min_W, max_W);

        std::cout << instance.to_json() << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error while generating: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
