#include "myrand.hpp"
#include <cstdlib>

bigint randint() {
    bigint res = 0;
    for (size_t b = 0; b < sizeof(bigint); ++b) {
        res += (rand() & 0xFF) << (8 * b);
    }
    return res;
}

bigint randintb(bigint min, bigint max) {
    return min + randint() % (max - min);
}
