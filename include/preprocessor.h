#ifndef CPP_PREPROCESSOR
#define CPP_PREPROCESSOR


namespace preprocessor
{

bool getNewWord(std::ifstream &program, std::string &word);
void preprocessing(std::ifstream &program, char *path);

}

#endif //CPP_PREPROCESSOR
