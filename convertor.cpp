#include <unordered_map>
#include <algorithm>
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

std::unordered_map<std::string, char> umap; 

std::string binarytoOctal(std::string str){
    std::string octal = "";
    str = std::string((3 - str.size()%3)%3,'0') + str;
    for(int i = 0; i < str.size(); i+=3){
        std::string tmp = str.substr(i,3);
        octal += umap["0"+tmp];
    }
    return octal;
}

std::string octaltoBinary(std::string str){
    std::string binary = "";
    std::unordered_map<std::string,char>::iterator itr;
    for(int i = 0; i < str.size(); ++i){
        std::string bits = "";
        for(itr = umap.begin(); itr!=umap.end(); ++itr){
            char entry = itr->second;
            if(str[i] == entry){
                bits = itr->first.substr(1);
                break;
            }
        }
        binary += bits;
    }
    return binary;
}

std::string binarytoDecimal(std::string str){
    long long int dec = 0;
    for(int i = 0; i < str.size(); ++i){
        dec += (str[i] - '0') * (long long int)pow(2,str.size()-1-i);
    }
    return std::to_string(dec);
}

std::string decimaltoBinary(std::string str){
    long long int dec = std::stoll(str);
    std::string binary="";
    int i = 0;
    
    if (dec == 0) return "0";
    while(dec!=0){
        int rem = dec%2;
        binary += std::to_string(rem);
        dec /= 2;
    }
    std::reverse(binary.begin(),binary.end());
    return binary;
}

std::string binarytoHex(std::string str){
    std::string hex = "";
    str = std::string((4 - str.size()%4)%4,'0') + str;
    for(int i = 0; i < str.size(); i+=4){
        std::string tmp = str.substr(i,4);
        hex += umap[tmp];
    }
    return hex;
}

std::string hextoBinary(std::string str){
    std::string binary = "";
    std::unordered_map<std::string,char>::iterator itr;
    for(int i = 0; i < str.size(); ++i){
        std::string bits = "";
        for(itr = umap.begin(); itr!=umap.end(); ++itr){
            char entry = itr->second;
            if(str[i] == entry){
                bits = itr->first.substr(0);
                break;
            }
        }
        binary += bits;
    }
    return binary;
}

int main(){
    umap["0000"] = '0'; 
    umap["0001"] = '1'; 
    umap["0010"] = '2'; 
    umap["0011"] = '3'; 
    umap["0100"] = '4'; 
    umap["0101"] = '5'; 
    umap["0110"] = '6'; 
    umap["0111"] = '7'; 
    umap["1000"] = '8'; 
    umap["1001"] = '9'; 
    umap["1010"] = 'A'; 
    umap["1011"] = 'B'; 
    umap["1100"] = 'C'; 
    umap["1101"] = 'D'; 
    umap["1110"] = 'E'; 
    umap["1111"] = 'F';


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