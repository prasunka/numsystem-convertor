#include <iostream>
#include <string>
#include <vector>

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

//std::string binarytoDecimal(std::string str){

//}

int main(){
    std::cout << checkBinary("111000111") << std::endl;
    std::cout << checkDecimal("1431100A111") << std::endl;
    std::cout << checkOctal("11100758111") << std::endl;
    std::cout << checkHex("11100BCD25MFA111") << std::endl;
    std::cout << checkDecimal("-111006464694111") << std::endl;


}