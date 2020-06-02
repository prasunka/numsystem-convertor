#include <iostream>
#include <algorithm>
#include "convertor.h"

std::vector<std::string> modes = {"-b2o","-b2d","-b2h","-o2b","-o2d","-o2h","-d2b","-d2o","-d2h","-h2b","-h2o","-h2d"};

void show_usage(const std::string &name){
    std::cerr << "Usage: " << name << " <mode> INPUT <option(s)> PATH\n"
              << "Modes:\n"
              << "\t-h,--help\tShow this help message\n"
              << "\n\t-b2o \t\tBinary to Octal"
              << "\n\t-b2d \t\tBinary to Decimal"
              << "\n\t-b2h \t\tBinary to Hexadecimal"
              << "\n\t-o2b \t\tOctal to Binary"
              << "\n\t-o2d \t\tOctal to Decimal"
              << "\n\t-o2h \t\tOctal to Hexadecimal"
              << "\n\t-d2b \t\tDecimal to Binary"
              << "\n\t-d2o \t\tDecimal to Octal"
              << "\n\t-d2h \t\tDecimal to Hexadecimal"
              << "\n\t-h2b \t\tHexadecimal to Binary"
              << "\n\t-h2o \t\tHexadecimal to Octal"
              << "\n\t-h2d \t\tHexadecimal to Decimal\n"
              << "Options:\n"
              << "\t-f,--file PATH\tSpecify the path of input file\n"
              << "\t-o,--out PATH\tSpecify the path of output file\n"
              << std::endl;
}

std::string convert(const std::string &input, const std::string &mode){
    if(mode == "-b2o"){
            if(!checkBinary(input)){
                std::cerr << "Invalid input!" << std::endl;
                show_usage("NsysConv");
                return ""; 
            }

            return binarytoOctal(input);
        }
        
        if(mode == "-b2d"){
            if(!checkBinary(input)){
                std::cerr << "Invalid input!" << std::endl;
                show_usage("NsysConv");
                return ""; 
            }

            return binarytoDecimal(input);
        }
        
        if(mode == "-b2h"){
            if(!checkBinary(input)){
                std::cerr << "Invalid input!" << std::endl;
                show_usage("NsysConv");
                return ""; 
            }

            return binarytoHex(input);
        }
        if(mode == "-d2b"){
            if(!checkDecimal(input)){
                std::cerr << "Invalid input!" << std::endl;
                show_usage("NsysConv");
                return ""; 
            }
            
            return decimaltoBinary(input);
        }
        if(mode == "-d2o"){
            if(!checkDecimal(input)){
                std::cerr << "Invalid input!" << std::endl;
                show_usage("NsysConv");
                return ""; 
            }
            
            return binarytoOctal(decimaltoBinary(input));
        }
        if(mode == "-d2h"){
            if(!checkDecimal(input)){
                std::cerr << "Invalid input!" << std::endl;
                show_usage("NsysConv");
                return ""; 
            }
            
            return binarytoHex(decimaltoBinary(input));
        }
        if(mode == "-o2b"){
            if(!checkOctal(input)){
                std::cerr << "Invalid input!" << std::endl;
                show_usage("NsysConv");
                return ""; 
            }
            
            return octaltoBinary(input);
        }
        if(mode == "-o2d"){
            if(!checkOctal(input)){
                std::cerr << "Invalid input!" << std::endl;
                show_usage("NsysConv");
                return ""; 
            }
            
            return binarytoDecimal(octaltoBinary(input));
        }
        if(mode == "-o2h"){
            if(!checkOctal(input)){
                std::cerr << "Invalid input!" << std::endl;
                show_usage("NsysConv");
                return ""; 
            }
            
            return binarytoHex(octaltoBinary(input));
        }
        if(mode == "-h2b"){
            if(!checkHex(input)){
                std::cerr << "Invalid input!" << std::endl;
                show_usage("NsysConv");
                return ""; 
            }
            
            return hextoBinary(input);
        }
        if(mode == "-h2o"){
            if(!checkHex(input)){
                std::cerr << "Invalid input!" << std::endl;
                show_usage("NsysConv");
                return ""; 
            }
            
            return binarytoOctal(hextoBinary(input));
        }
        if(mode == "-h2d"){
            if(!checkHex(input)){
                std::cerr << "Invalid input!" << std::endl;
                show_usage("NsysConv");
                return ""; 
            }
            
            return binarytoDecimal(hextoBinary(input));
        }
    return "";
}

int main(int argc, char **argv){
    init();
    
    if (argc < 3) {
        show_usage(argv[0]);
        return 1;
    }
    bool filemode = false;
    std::string mode = "";
    std::string input = "";
    //std::string infile = "";
    //std::string outfile = "";

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if ((arg == "-h") || (arg == "--help")) {
            show_usage(argv[0]);
            return 0;
        } 
        
        if(std::find(modes.begin(),modes.end(),arg) != modes.end()){
            mode = arg;
            if(i + 1 < argc){
                if(argv[i+1][0]!='-')
                    input = argv[++i];
            }
            else {
                show_usage(argv[0]);
                return 1;
            }
        }

        else if ((arg == "-f") || (arg == "--file")) {
            filemode = true;
            if (i + 1 < argc) {   
                //infile = argv[++i];   
            } else { 
                  std::cerr << "--file option requires one argument." << std::endl;
                return 1;
            }  
        }

        else if ((arg == "-o") || (arg == "--out")) {
            if (i + 1 < argc) {   
                //outfile = argv[++i];   
            } else { 
                  std::cerr << "--out option requires one argument." << std::endl;
                return 1;
            }  

        } 
        else {
            show_usage(argv[0]);
            return 1;
        }
    }

    if(!filemode){
        if(input.empty()){
            std::cerr << "No input to convert!" << std::endl;
            show_usage(argv[0]);
            return 1;
        }
        std::string output = convert(input,mode);
        if(!output.empty())std::cout << output << std::endl;
        
        return 0;
    }
    
    return 0;
}