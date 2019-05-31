#include "cssselector.h"

CssSelector::CssSelector(std::string name) : selector(name){

}

bool CssSelector::operator==(CssSelector other){
    return this->selector.compare(other.selector) == 0;
}

unsigned int CssSelector::hasAttribute(std::string other){
    unsigned int i = 0;
    for (std::string attr : attributes){
        if(attr.compare(other) == 0)
            return i;
        i++;
    }
    return -1;
}

std::string CssSelector::value_of(std::string attr){
    unsigned int ind = this->hasAttribute(attr);
    if(ind >= 0)
        return values.at(ind);
    else return "null";
}

void CssSelector::append(std::string attribute, std::string value){
    unsigned int ind = this->hasAttribute(attribute);
    if(ind >= 0){
        if(this->values.at(ind).compare(value) == 0)
            return;
        else {
            StyleConflicts::Instance()->append(selector, ind, attribute, {values.at(ind), value});
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