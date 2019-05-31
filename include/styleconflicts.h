#include <vector>
#include <string>

#include "styleconflict.h"

class StyleConflicts{
    public:
        static StyleConflicts* Instance();
        void append(std::string sel, unsigned int ind, std::string attr, std::vector<std::string> values);

    private:
        StyleConflicts();
        static StyleConflicts* _instance;
        std::vector<StyleConflict> conflicts;
};