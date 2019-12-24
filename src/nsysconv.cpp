#include <iostream>
#include "convertor.h"

int main(){
    init();
    
    std::cout << checkBinary("111000111") << std::endl;
    std::cout << checkDecimal("1431100A111") << std::endl;
    std::cout << checkOctal("11100758111") << std::endl;
    std::cout << checkHex("11100BCD25MFA111") << std::endl;
    std::cout << checkDecimal("-111006464694111") << std::endl;

    std::cout << binarytoDecimal("11001") << std::endl;
    std::cout << binarytoDecimal("0") << std::endl;
    std::cout << binarytoDecimal("1") << std::endl;
    std::cout << binarytoDecimal("0000111111111111111111111111100000000000000000000000000000010") << std::endl;

    std::cout << decimaltoBinary("4") << std::endl;
    std::cout << decimaltoBinary("64") << std::endl;
    std::cout << decimaltoBinary("0") << std::endl;
    std::cout << decimaltoBinary("10000000000000000") << std::endl;

    std::cout << binarytoOctal("0") << std::endl;
    std::cout << binarytoOctal("100110101010110101011110110") << std::endl;
    std::cout << binarytoOctal("110110101011") << std::endl;
    
    std::cout << octaltoBinary("0") << std::endl;
    std::cout << octaltoBinary("7456132147563201") << std::endl;
    std::cout << octaltoBinary("210345621") << std::endl;

    std::cout << binarytoHex("0") << std::endl;
    std::cout << binarytoHex("100110101010110101011110110") << std::endl;
    std::cout << binarytoHex("1101101010111010101001010101001") << std::endl;

    std::cout << hextoBinary("0") << std::endl;
    std::cout << hextoBinary("7456132147563201") << std::endl;
    std::cout << hextoBinary("210345621ABACDABCDEDC12787") << std::endl;
}