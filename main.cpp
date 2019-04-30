#include <iostream>
#include <cassert>
using namespace std;

char
bit_digit(uint8_t byte, uint8_t bit)
{
    if (byte & (0x1 << bit))
    {
        return '1';
    }
    return '0';
}

void
print_in_binary(uint8_t byte)
{
    for (uint8_t bit = 7; bit >= 0; bit--)
    {
        cout << bit_digit(byte, bit);
        if (bit == 0)
            return;
    }
}

char nibble_to_hex (uint8_t i)
{
    assert((0x0 <= i) && (i <= 0xf));
    char symbols[] = "0123456789abcdef";
    return symbols[i];
}

void print_in_hex(uint8_t byte)
{
    cout << nibble_to_hex(byte >> 4)
         << nibble_to_hex(byte & 0xf);
}
//маленькая

void print_in_hex(const void* data, size_t size);//большая

const uint8_t*
as_bytes(const void* data)
{
    return reinterpret_cast<const uint8_t*>(data);
}

void
print_in_hex(const void* data, size_t size)
{
    const uint8_t* bytes = as_bytes(data);
    for (size_t i = 0; i < size; i++)
    {
        print_in_hex(bytes[i]);


        if ((i + 1) % 16 == 0)
        {
            cout << '\n';
        }
        else
        {
            cout << ' ';
        }
    }
}

void
print_in_binary(const void* data, size_t size)
{
    const uint8_t* bytes = as_bytes(data);
    for (size_t i = 0; i < size; i++)
    {
        print_in_binary(bytes[i]);
        if ((i + 1) % 4 == 0)
        {
            cout << '\n';
        }
        else
        {
            cout << ' ';
        }
    }
}

void calc  (uint16_t op1, char operat, uint16_t op2)
{
    print_in_hex(&op1, sizeof(op1));
    cout <<' '<< operat<<' ';
    print_in_hex(&op2, sizeof(op2));
    cout << " = ";
    uint16_t res;
    if (operat == '&')
    {
        res = op1 & op2;
    }
    if (operat == '|')
    {
        res = op1 | op2;
    }
    if (operat == '^')
    {
        res = op1 ^ op2;
    }
    print_in_hex(&res, sizeof(res));

    cout<<endl<<endl;

    print_in_binary(&op1, sizeof(op1));
    cout <<' '<< operat<<' ';
    print_in_binary(&op2, sizeof(op2));
    cout << " = ";

    print_in_binary(&res, sizeof(res));
}
struct Student
{
    char name[17];
    uint16_t year;
    float average;
    uint8_t gender : 1;
    uint8_t courses;
    Student* starosta;
};

int main()
{
    Student students[3] =
    {
        {"FeoktistovaAR", 1999, 5.0, 0, 1, nullptr},
        {"StryukovaTA", 2000, 4.5, 0, 1, &students[0]},
        {"ZabarinID", 2000, 4.0, 1, 1, &students[0]}
    };

    cout<<"adress of student: "<<&students<<endl;
    cout<<"Size of students: "<<sizeof(students);

    cout<<endl<<endl<<endl;

    for (size_t i=0; i<3; i++)
    {

        cout<<"adress of student: "<<&students[i]<<endl;
        cout<<"Size of students: "<<sizeof(students[i])<<endl<<endl;
    }



    cout << endl << "address of student 0 name " << &students[1].name;
    cout << endl << "offset of student 0 name " <<offsetof(Student, name);
    cout << endl << "Size of student 0 name  " << sizeof(students[1].name);
    cout << endl << "print_in_hex of student 0 name  "; print_in_hex(&students[1].name,sizeof(students[1].name));
    cout << endl << "print_in_binary of student 0 name  "; print_in_binary(&students[1].name,sizeof(students[1].name));
    cout << endl;
     cout << endl << "address of student 0 year " << &students[1].year;
    cout << endl << "offset of student 0 year " <<offsetof(Student, year);
    cout << endl << "Size of student 0 year  " << sizeof(students[1].year);
    cout << endl << "print_in_hex of student 0 year  "; print_in_hex(&students[1].year,sizeof(students[1].year));
    cout << endl << "print_in_binary of student 0 year  "; print_in_binary(&students[1].year,sizeof(students[1].year));
    cout << endl;//везде единички!!!!!!!!!!!!!!!!!!!
     cout << endl << "address of student 0 average " << &students[1].average;
    cout << endl << "offset of student 0 average " <<offsetof(Student, average);
    cout << endl << "Size of student 0 average  " << sizeof(students[1].average);
    cout << endl << "print_in_hex of student 0 average  "; print_in_hex(&students[1].average,sizeof(students[1].average));
    cout << endl << "print_in_binary of student 0 average  "; print_in_binary(&students[1].average,sizeof(students[1].average));
    cout << endl;
    cout << endl << "address of student 0 courses " << &students[1].courses;
    cout << endl << "offset of student 0 courses " <<offsetof(Student, courses);
    cout << endl << "Size of student 0 courses  " << sizeof(students[1].courses);
    cout << endl << "print_in_hex of student 0 courses  "; print_in_hex(&students[1].courses,sizeof(students[1].courses));
    cout << endl << "print_in_binary of student 0 courses  "; print_in_binary(&students[0].courses,sizeof(students[0].courses));
    cout << endl;
    cout << endl << "address of student 0 starosta " << &students[0].starosta;
    cout << endl << "offset of student 0 starosta " <<offsetof(Student, starosta);
    cout << endl << "Size of student 0 starosta  " << sizeof(students[0].starosta);
    cout << endl << "print_in_hex of student 0 starosta  "; print_in_hex(&students[0].starosta,sizeof(students[0].starosta));
    cout << endl << "print_in_binary of student 0 starosta  "; print_in_binary(&students[0].starosta,sizeof(students[0].starosta));

    /*
    assert(nibble_to_hex(0x0) == '0');
    assert(nibble_to_hex(0x1) == '1');
    assert(nibble_to_hex(0x2) == '2');
    assert(nibble_to_hex(0x3) == '3');
    assert(nibble_to_hex(0x4) == '4');
    assert(nibble_to_hex(0x5) == '5');
    assert(nibble_to_hex(0x6) == '6');
    assert(nibble_to_hex(0x7) == '7');
    assert(nibble_to_hex(0x8) == '8');
    assert(nibble_to_hex(0x9) == '9');
    assert(nibble_to_hex(0xa) == 'a');
    assert(nibble_to_hex(0xb) == 'b');
    assert(nibble_to_hex(0xc) == 'c');
    assert(nibble_to_hex(0xd) == 'd');
    assert(nibble_to_hex(0xe) == 'e');
    assert(nibble_to_hex(0xf) == 'f');

    uint32_t u32 = 0x42;
    cout << "u32 bytes: ";
    print_in_hex(&u32, sizeof(u32));
    cout << '\n';

    uint16_t u16 = 0x42;
    cout << "u16 bytes: ";
    print_in_hex(&u16, sizeof(u16));
    cout << '\n';

    uint8_t u8 = 0x42;
    cout << "u8 bytes: ";
    print_in_hex(&u8, sizeof(u8));
    cout << '\n';

    print_in_binary(15);
    cout << endl << endl;

    calc(1025,'&',127);

    */
    return 0;
}
