#include "gates.hpp"
#include <iostream>

int main() {
    using namespace logic;

    Nand nand_gate;

    Bit inputs[2] = { Bit(0), Bit(1) };

    for (Bit a : inputs) {
        for (Bit b : inputs) {
            nand_gate.setInputs(a, b);
            Bit out = nand_gate.evaluate();
            std::cout << "NAND(" << a.get() << ", " << b.get() << ") = "
                      << out.get() << std::endl;
        }
    }

    return 0;
}
