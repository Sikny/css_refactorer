#include "cssselector.h"

CssSelector::CssSelector(std::string name) : selector(name){

}

bool CssSelector::operator==(CssSelector other){
    return this->selector.compare(other.selector) == 0;
}

int CssSelector::hasAttribute(std::string other){
    int i = 0;
    for (std::string attr : attributes){
        if(attr.compare(other) == 0)
            return i;
        i++;
    }
    return -1;
}

std::string CssSelector::value_of(std::string attr){
    int ind = this->hasAttribute(attr);
    if(ind >= 0)
        return values.at(ind);
    else return "null";
}

void CssSelector::append(std::string attribute, std::string value){
    int ind = this->hasAttribute(attribute);
    if(ind >= 0){
        if(this->values.at(ind).compare(value) == 0)
            return;
        else {
            std::cout << std::endl << "Conflict:" << std::endl;
            std::cout << selector << " {" << std::endl;
            std::cout << '\t' << attribute << ": " << std::endl;
            std::cout << "\t\tcurrent(0): " << std::endl << "\t\t\t" << values.at(ind) << std::endl;
            std::cout << "\t\tnew(1): " << std::endl << "\t\t\t" << value << std::endl;
            std::cout << "}" << std::endl;
            unsigned int i = 0;
            std::cin >> i;
            if(i == 1) values.at(ind) = value;
        }
    } else {
        attributes.push_back(attribute);
        values.push_back(value);
    }
}

void CssSelector::merge(CssSelector other){
    unsigned int ind = 0;
    for(std::string attr : other.attributes){
        this->append(attr, other.values.at(ind));
        ind++;
    }
}

std::string CssSelector::toString(){
    std::string str = selector + " {\n";
    unsigned int i = 0;
    for(std::string attr : attributes){
        str += "\t" + attr + ": " + values.at(i) + ";\n";
        i++;
    }
    str += "}\n";
    return str;
}