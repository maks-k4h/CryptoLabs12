#include "format.hpp"

std::string as_base(bigint a, std::string base) {
    if (a == 0)
        return base.substr(0, 1);

    bigint b = base.length();
    std::string res;
    while (a > 0) {
        res.insert(res.begin(), base[a % b]);
        a /= b;
    }
    return res;
}

std::string as_base2(bigint a) {
    return as_base(a, "01");
}

std::string as_base10(bigint a) {
    return as_base(a, "0123456789");
}

std::string as_base64(bigint a) {
    return as_base(a, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/");
}

uint8_t get_byte(bigint a, size_t byte) {
    return 0xFF & (a >> (8 * byte));
}