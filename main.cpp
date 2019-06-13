#include <iostream>
#include <fstream>

#include "cssparser.h"

int main(int argc, char** argv){
    StyleData* data = StyleData::Instance();
    std::ifstream infile("styleIn.css");
    std::ofstream outfile("styleOut.css");

    CssParser::Instance()->parse(infile, data);
    CssParser::Instance()->write(outfile, data);
    return 0;
}