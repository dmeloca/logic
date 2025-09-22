#pragma once
#include <stdexcept> 

namespace logic {

class Bit {
private:
    int value_;

public:
    Bit(int value) {
        set(value);
    }

    void set(int value) {
        if (value != 0 && value != 1) {
            throw std::invalid_argument("It's a bit: just 1 or 0.");
        }
        value_ = value;
    }

    int get() const {
        return value_;
    }

    operator int() const {
        return value_;
    }
};

}
