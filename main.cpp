#include "generator.h"
#include <iostream>

using ull = unsigned long long;

int main() {
    BrazilianSalesmanGenerator generator;

    // --- Parametry dla generatora ---
    // Używamy ull, aby obsłużyć maksymalny zakres.
    ull min_W = 1;
    // 2^64 - 1
    ull max_W = 18446744073709551615ULL;
    // Dodanie sufiksu ULL, by kompilator wiedział, że to ma być unsigned long long literal

    // Usunięcie zakomentowanego, ale nieprawidłowego wcześniej kodu
    
    try {
        BrazilianSalesmanInstance instance = generator.generate(min_W, max_W);

        std::cout << instance.to_json() << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error while generating: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
