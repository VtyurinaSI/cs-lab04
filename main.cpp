#include <iostream>
#include <cassert>
using namespace std;

void print_in_hex(uint8_t byte)
{
    cout << nibble_to_hex(byte >> 4)
         << nibble_to_hex(byte & 0x0f);
}
//���������
void print_in_hex(const void* data, size_t size);//�������
/*
void print_in_binary(uint8_t byte);
void print_in_binary(const void* data, size_t size);
*/

char nibble_to_hex (uint8_t i)
{
    assert(0x0 <= i && i <= 0xf);
    char symbols[] = "0123456789abcdef";
    return symbols[i];
}

int main()
{

    assert(nibble_to_hex(0x0) == '0');
    assert(nibble_to_hex(0x1) == '1');
    assert(nibble_to_hex(0x2) == '2');
    assert(nibble_to_hex(0x3) == '3');
    assert(nibble_to_hex(0x4) == '4');
    assert(nibble_to_hex(0x5) == '5');
    assert(nibble_to_hex(0x6) == '6');
    assert(nibble_to_hex(0x7) == '7');
    assert(nibble_to_hex(0x8) == '8');
    assert(nibble_to_hex(0x9) == '8');
    assert(nibble_to_hex(0xa) == 'a');
    assert(nibble_to_hex(0xb) == 'b');
    assert(nibble_to_hex(0xc) == 'c');
    assert(nibble_to_hex(0xd) == 'd');
    assert(nibble_to_hex(0xe) == 'e');
    assert(nibble_to_hex(0xf) == 'f');

    return 0;
}
