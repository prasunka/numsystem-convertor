#include <iostream>
#include <string>
#include <vector>
#include <cmath>

bool checkBinary(std::string str){
    for(char c: str){
        if(c!='1' && c!='0')return false;
    }
    return true;
}

bool checkOctal(std::string str){
    for (char c : str){
        if(c < '0' || c > '7')return false;
    }
    return true;
}

bool checkDecimal(std::string str){
    for (char c : str){
        if(c < '0' || c > '9')return false;
    }
    return true;
}

bool checkHex(std::string str){
    for (char c : str){
        if (!((c >= '0' && c <= '9') || (c >='A' && c <= 'F')))return false;
    }
    return true;
}

std::string binarytoDecimal(std::string str){
    long long int dec = 0;
    for(int i = 0; i < str.size(); ++i){
        dec += (str[i] - '0') * (long long int)pow(2,str.size()-1-i);
    }
    return std::to_string(dec);
}

int main(){
    std::cout << checkBinary("111000111") << std::endl;
    std::cout << checkDecimal("1431100A111") << std::endl;
    std::cout << checkOctal("11100758111") << std::endl;
    std::cout << checkHex("11100BCD25MFA111") << std::endl;
    std::cout << checkDecimal("-111006464694111") << std::endl;

    std::cout << binarytoDecimal("11001") << std::endl;
    std::cout << binarytoDecimal("0") << std::endl;
    std::cout << binarytoDecimal("1") << std::endl;
    std::cout << binarytoDecimal("0000111111111111111111111111100000000000000000000000000000010") << std::endl;
}