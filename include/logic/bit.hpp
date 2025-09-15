#pragma once
#include <stdexcept>  // std::invalid_argument

namespace logic {

class Bit {
private:
    int value;

public:
    Bit(int v) {
        set(v);
    }

    void set(int v) {
        if (v != 0 && v != 1) {
            throw std::invalid_argument("It's a bit: just 1 or 0.");
        }
        value = v;
    }

    int get() const {
        return value;
    }

    operator int() const {
        return value;
    }
};

}
