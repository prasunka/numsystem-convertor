#include <unordered_map>
#include <algorithm>
#include <string>
#include <vector>

void init();

bool checkBinary(std::string str);
bool checkOctal(std::string str);
bool checkDecimal(std::string str);
bool checkHex(std::string str);

std::string binarytoOctal(std::string str);
std::string binarytoDecimal(std::string str);
std::string binarytoHex(std::string str);

std::string octaltoBinary(std::string str);
std::string decimaltoBinary(std::string str);
std::string hextoBinary(std::string str);
