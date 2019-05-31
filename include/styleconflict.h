#include <vector>
#include <string>

class StyleConflict{
    public:
        StyleConflict(std::string sel, unsigned int ind, std::string attr, std::vector<std::string> values);
        bool hasSelector(std::string sel);
        bool hasAttribute(std::string attr);
        void appendValues(std::vector<std::string> values);

    private:
        unsigned int indice;
        std::string selector;
        std::string attribute;
        std::vector<std::string> values;
};