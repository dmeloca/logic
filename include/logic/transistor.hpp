#pragma once
#include "bit.hpp"

namespace logic {
    class MOSFET{
        private:
            Bit gate_;
            Bit drain_;
            Bit source_;
        public:
            MOSFET() : gate_(0), drain_(0), source_(0) {}
            MOSFET(Bit g, Bit d, Bit s) : gate_(g), drain_(d), source_(s) {}
            void setGate(Bit value) { gate_ = value; }
            void setDrain(Bit value) { drain_ = value; }
            void setSource(Bit value) { source_ = value; }
            Bit getGate() const { return gate_; }
            Bit getDrain() const { return drain_; }
            Bit getSource() const { return source_; }
            virtual Bit evaluate() const = 0;
            virtual ~MOSFET() = default;
     };

    class NMOS : public MOSFET {
        public:
            Bit evaluate() const override {
                 return (getGate() == Bit(1)) ? getSource() : Bit(0);
            }
    };

    class PMOS : public MOSFET {
        public:
            Bit evaluate() const override {
                 return (getGate() == Bit(0)) ? getSource() : Bit(0);
            }
    };
}