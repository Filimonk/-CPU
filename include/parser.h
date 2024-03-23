#ifndef CPP_PARSER
#define CPP_PARSER


namespace parser
{

int find(std::string &word);
bool isNotInt(std::string &word);
void parser(std::vector <std::string> &stream, 
            std::vector <int> &numOfLabelToIndex, char *path);

}

#endif //CPP_PARSER
