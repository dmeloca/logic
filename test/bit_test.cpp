#include "logic/bit.hpp"
#include <cassert>
#include <iostream>
#include <stdexcept>

using logic::Bit;

int main() {
    std::cout << "=== Bit tests ===\n";

    // Test 1: valid construction
    Bit b1(0);
    Bit b2(1);
    assert(b1.get() == 0);
    assert(b2.get() == 1);
    std::cout << "Constructor with 0 and 1 passed\n";

    // Test 2: valid setter
    b1.set(1);
    assert(b1.get() == 1);
    std::cout << "Setter with valid value passed\n";

    // Test 3: implicit conversion to int
    int x = b2;
    assert(x == 1);
    std::cout << "Implicit conversion to int passed\n";

    // Test 4: exception on invalid value
    bool exceptionThrown = false;
    try {
        Bit b3(7); // should fail
    } catch (const std::invalid_argument&) {
        exceptionThrown = true;
    }
    assert(exceptionThrown && "Expected exception for invalid value");
    std::cout << "Exception on invalid constructor passed\n";

    std::cout << "=== All tests passed ===\n";
    return 0;
}
