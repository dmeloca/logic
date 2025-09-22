#pragma once
#include "bit.hpp"
#include "transistor.hpp"

namespace logic {
    class Nand {
        private:
            Bit a, b;
            PMOS p1, p2;
            NMOS n1, n2;

        public:
            Nand() : a(0), b(0) {}

            void setInputs(Bit inA, Bit inB) {
                a = inA; b = inB;

                p1.setGate(a);
                p2.setGate(b);
                n1.setGate(a);
                n2.setGate(b);

                p1.setSource(Bit(1));
                p2.setSource(Bit(1));
                n1.setSource(Bit(0));
                n2.setSource(Bit(0));
            }

            Bit evaluate() const {
                // --- Pull-up (PMOS en paralelo) ---
                bool pun = (p1.getGate() == Bit(0)) || (p2.getGate() == Bit(0));

                // --- Pull-down (NMOS en serie) ---
                bool pdn = (n1.getGate() == Bit(1)) && (n2.getGate() == Bit(1));

                if (pdn) return Bit(0); 
                if (pun) return Bit(1);  
                return Bit(0);          
            }
    };

}