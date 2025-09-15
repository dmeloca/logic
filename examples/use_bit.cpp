#include "logic/bit.hpp"
#include <iostream>

int main() {
    logic::Bit b1(1);
    logic::Bit b0(0);

    std::cout << "b1 = " << b1 << "\n";
    std::cout << "b0 = " << b0.get() << "\n";

    try {
        logic::Bit invalid(5);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Caught error: " << e.what() << "\n";
    }
}
