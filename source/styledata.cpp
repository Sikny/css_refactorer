#include "styledata.h"

StyleData* StyleData::_instance;

StyleData::StyleData(){}

StyleData* StyleData::Instance() {
    if(!_instance)
        _instance = new StyleData();
    return _instance;
}

unsigned int StyleData::hasSelector(CssSelector cssSel){
    unsigned int i = 0;
    for(CssSelector sel : this->selectors){
        if(sel == cssSel)
            return i;
        i++;
    }
    return -1;
}

void StyleData::append(CssSelector cssSel){
    unsigned int ind = hasSelector(cssSel);
    if(ind >= 0)
        selectors.push_back(cssSel);
    else{
        selectors.at(ind).merge(cssSel);
    }
}

std::string StyleData::toString(){
    std::string str = "";
    for(CssSelector sel : selectors){
        str += sel.toString();
    }
    return str;
}