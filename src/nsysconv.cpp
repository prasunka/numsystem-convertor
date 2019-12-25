#include <iostream>
#include <algorithm>
#include "convertor.h"

std::vector<std::string> modes = {"-b2o","-b2d","-b2h","-o2b","-o2d","-o2h","-d2b","-d2o","-d2h","-h2b","-h2o","-h2d"};

void show_usage(std::string name){
    std::cerr << "Usage: " << name << " <option(s)> SOURCES"
              << "Options:\n"
              << "\t-h,--help\t\tShow this help message\n"
              << "\t-d,--destination DESTINATION\tSpecify the destination path"
              << std::endl;
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
    std::string infile = "";
    std::string outfile = "";

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
                infile = argv[++i];   
            } else { 
                  std::cerr << "--file option requires one argument." << std::endl;
                return 1;
            }  
        }

        else if ((arg == "-o") || (arg == "--out")) {
            if (i + 1 < argc) {   
                outfile = argv[++i];   
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

    std::cout << "successfully parsed :)" << std::endl;
    
    return 0;
}