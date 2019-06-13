#include <string>
#include <fstream>

#include "styledata.h"
#include "stringtrim.h"

class CssParser{
    public:
        static CssParser* Instance();
        void parse(std::ifstream& in, StyleData* out);
        void write(std::ofstream& out, StyleData* in);
    
    private:
        CssParser();
        static CssParser* _instance;
        bool isLargeData;
};