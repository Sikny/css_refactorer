#include <string>
#include <fstream>

#include "styledata.h"
#include "stringtrim.h"

class CssParser{
    public:
        static CssParser* Instance();
        void parse(std::string in, StyleData* out);
        void write(std::string out, StyleData* in);
    
    private:
        CssParser();
        static CssParser* _instance;
        bool isLargeData;
};