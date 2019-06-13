#include <vector>

#include "cssselector.h"

class StyleData{
    public:
        static StyleData* Instance();
        int hasSelector(CssSelector cssSel);
        void append(CssSelector cssSel);
        std::string toString();

    private:
        StyleData();
        static StyleData* _instance;

        std::vector<CssSelector> selectors;
};