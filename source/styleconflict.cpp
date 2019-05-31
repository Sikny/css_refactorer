#include "styleconflict.h"

StyleConflict::StyleConflict(std::string sel, unsigned int ind, 
    std::string attr, std::vector<std::string> values_p){
    selector = sel;
    indice = ind;
    attribute = attr;
    values = values_p;
}

bool StyleConflict::hasSelector(std::string sel){
    return sel.compare(selector) == 0;
}

bool StyleConflict::hasAttribute(std::string attr){
    return attr.compare(attribute) == 0;
}

void StyleConflict::appendValues(std::vector<std::string> values_p){
    for(std::string val : values_p){
        values.push_back(val);
    }
}