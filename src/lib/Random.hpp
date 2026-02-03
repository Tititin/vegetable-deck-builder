#pragma once

#include <random>

class Random {
public:
    static std::mt19937& engine() {
        static std::mt19937 rng{ std::random_device{}() };
        return rng;
    }
};