#ifndef LABS_FORMAT
#define LABS_FORMAT


#include "defs.hpp"
#include <string>


std::string as_base2(bigint a);

std::string as_base10(bigint a);

std::string as_base64(bigint a);

uint8_t get_byte(bigint a, size_t byte);


#endif