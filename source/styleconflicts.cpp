#include "styleconflicts.h"

StyleConflicts* StyleConflicts::Instance(){
    if(!_instance)
        _instance = new StyleConflicts();
    return _instance;
}

void StyleConflicts::append(std::string sel, unsigned int ind, std::string attr, std::vector<std::string> values){
    for(StyleConflict conflict : conflicts){
        if(conflict.hasSelector(sel) && conflict.hasAttribute(attr)){
            conflict.appendValues(values);
            return;
        }
    }
    StyleConflict c(sel, ind, attr, values);
    conflicts.push_back(c);
}