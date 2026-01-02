#include <iostream>
#include <span>
#include <string>
#include <fstream>
#include <sstream>
#include "lexer/lexer.hpp"

std::string readFile(const std::string &filename)
{
    std::ifstream file(filename, std::ios::in | std::ios::binary);
    if (!file)
    {
        throw std::runtime_error("Could not open file: " + filename);
    }

    std::ostringstream ss;
    ss << file.rdbuf(); // read whole file
    return ss.str();
}
int main(int argC, char *Argsv[])
{
    int argCount = argC - 1;
    std::span<char *> args{Argsv, static_cast<size_t>(argC)};
    std::span<char *> userArgs = args.subspan(1);
    if (argCount > 0)
    {
        char *fileName = userArgs[0];
        std::string src = readFile(fileName);
        Lexer lexer(src);
        std::vector<Token> tokens = lexer.tokenize();
        for (const auto &tok : tokens)
        {
            std::cout << tok.lexeme << "\n";
        }
        // for (int i = 0; i < argCount; i++)
        // {
        //     printf("%s\n", userArgs[i]);
        // }
    }
    else
    {
        printf("No Arguments Supplied!\n");
    }
    return 0;
}