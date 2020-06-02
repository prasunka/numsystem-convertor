# numsystem-convertor

## Overview
A C++ tool to convert between number systems.

## Usage

### Building from source:
* Clone this repository
> git clone https://github.com/prasunka/numsystem-convertor numsys-conv
* Build using make
> cd numsys-conv
>
> make
* Usage:
> ./nsysconv <mode> INPUT <option(s)> PATH
>
> Modes:
>         -h,--help       Show this help message
> 
>         -b2o            Binary to Octal
>         -b2d            Binary to Decimal
>         -b2h            Binary to Hexadecimal
>         -o2b            Octal to Binary
>         -o2d            Octal to Decimal
>         -o2h            Octal to Hexadecimal
>         -d2b            Decimal to Binary
>         -d2o            Decimal to Octal
>         -d2h            Decimal to Hexadecimal
>         -h2b            Hexadecimal to Binary
>         -h2o            Hexadecimal to Octal
>         -h2d            Hexadecimal to Decimal
>
> Options:
>
>         -f,--file PATH  Specify the path of input file
>
>         -o,--out PATH   Specify the path of output file

* A simple example:
        
        ./nsysconv -b2d 1010
        Output: 10

### To-do:
* Add file support

## License
<big> MIT License </big>