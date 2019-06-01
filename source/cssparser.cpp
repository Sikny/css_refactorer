#include "cssparser.h"

CssParser* CssParser::_instance;

CssParser::CssParser() : isLargeData(false){}

CssParser* CssParser::Instance(){
    if(!_instance)
        _instance = new CssParser();
    return _instance;
}

void CssParser::write(std::string out, StyleData* in){
    std::ofstream output(out);
    std::string str = in->toString();
    const char* buffer = str.c_str();
    unsigned int size = str.size();
    output.write(buffer, size);
    std::cout << size << " characters wrote to " << out;
    delete buffer;
    output.close();
}

void CssParser::parse(std::string in, StyleData* out){
    std::ifstream input(in);
    input.seekg(0, input.end);
    unsigned int size = input.tellg();
    input.seekg(0);
    std::cout << "input: '" << in << "', " << size << " characters to read" << std::endl;
    if(size > 2000) isLargeData = true;
    std::string selector = "";
    char c;
    while(input.get(c)){
        if(c != '\n'){
            if(c == '{'){
                // selector end
                std::string attribute = "";
                CssSelector cssSel(trim(selector));
                while(input.get(c)){
                    if(c == ':'){
                        std::string value = "";
                        while(input.get(c)){
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
                }
                out->append(cssSel);
            } else {
                selector += c;
            }
        }
    }
    std::cout << "reached end of file." << std::endl;
}