#include <vector>

#include "cssselector.h"

class StyleData{
    public:
        static StyleData* Instance();
        unsigned int hasSelector(CssSelector cssSel);
        void append(CssSelector cssSel);

    private:
        StyleData();
        static StyleData* _instance;

        std::vector<CssSelector> selectors;
};