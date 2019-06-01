#include <string>
#include <vector>
#include <iostream>

#include "styleconflicts.h"

class CssSelector {
    public:
        CssSelector(std::string name);
        bool operator==(CssSelector other);
        int hasAttribute(std::string attr);    // returns attribute index if existing, -1 if not
        std::string value_of(std::string attr);
        void merge(CssSelector other);
        void append(std::string attribute, std::string value);
        std::string toString();
    
    private:
        std::string selector;
        std::vector<std::string> attributes;
        std::vector<std::string> values;
};