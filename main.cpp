#include <iostream>

#include "cssparser.h"

int main(int argc, char** argv){
    StyleData* data = StyleData::Instance();
    CssParser::Instance()->parse("style.css", data);
    CssParser::Instance()->write("output.css", data);
    return 0;
}