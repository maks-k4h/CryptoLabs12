#include <iostream>
#include "src/operations.hpp"
#include "src/format.hpp"

int main() {
    bigint a = pow_mod(112135267322323, 53212433412311, 12452133421);

    std::cout << "Base2: " << as_base2(a) << std::endl;
    std::cout << "Base10: " << as_base10(a) << std::endl;
    std::cout << "Base64: " << as_base64(a) << std::endl;

    std::cout << "Third byte: " << as_base2(get_byte(a, 2)) << std::endl;

    return 0;
}