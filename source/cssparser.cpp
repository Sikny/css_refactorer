#include "cssparser.h"

CssParser* CssParser::_instance;

CssParser::CssParser() : isLargeData(false){}

CssParser* CssParser::Instance(){
    if(!_instance)
        _instance = new CssParser();
    return _instance;
}

void CssParser::write(std::ofstream& out, StyleData* in){
    std::string str = in->toString();
    const char* buffer = str.c_str();
    unsigned int size = str.size();
    out.write(buffer, size);
    std::cout << size << " characters wrote";
    delete[] buffer;
}

void CssParser::parse(std::ifstream& in, StyleData* out){
    in.seekg(0, in.end);
    unsigned int size = in.tellg();
    in.seekg(0);
    std::cout << "input: " << size << " characters to read" << std::endl;
    if(size > 2000) isLargeData = true;
    std::string selector = "";
    char c;
    unsigned int lineNumber = 0;
    while(in.get(c)){
        if(c != '\n'){
            if(c == '{'){
                // selector end
                std::string attribute = "";
                CssSelector cssSel(trim(selector));
                while(in.get(c)){
                    if(c == ':'){
                        std::string value = "";
                        while(in.get(c)){
                            if(c == ';'){
                                cssSel.append(trim(attribute), trim(value));
                                value = "";
                                attribute = "";
                                break;
                            } else
                                value += c;
                        }
                    } else if(c == '}') {
                        selector = "";
                        break;
                    } else if(c != '\n' && c != '\t' && c != ' ')
                        attribute += c;
                    else if(c == '\n')
                        lineNumber++;
                }
                out->append(cssSel);
            } else {
                selector += c;
            }
        } else {
            lineNumber++;
        }
        std::cout << "\r" << in.tellg() << "/" << size << ", line " << lineNumber;
    }
    std::cout << "reached end of file." << std::endl;
}