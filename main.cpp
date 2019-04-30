#include <iostream>

using namespace std;

void print_in_hex(uint8_t byte);//маленькая
void print_in_hex(const void* data, size_t size);//большая
/*
void print_in_binary(uint8_t byte);
void print_in_binary(const void* data, size_t size);
*/

char nibble_to_hex (uint8_t i)
{
    char symbols[16] = '0123456789abcdef';
    return symbol[i];
}

int main()
{

    return 0;
}
