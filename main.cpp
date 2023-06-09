#include <iostream>
#include <vector>
#include <sstream> 
#include <string>
#include <unistd.h>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

vector<string> tokenize(string command)
{
    vector<string> tokens;
    char *token = strtok(const_cast<char*>(command.c_str()), " ");
    while (token != nullptr) 
    { 
        tokens.push_back(std::string(token)); 
        token = strtok(nullptr, " "); 
    } 

    return tokens;
}

void change_directory(string path)
{
    int ret = chdir(path.c_str());
    if (ret != 0)
    {
        cout << "Error: " << path << endl;
    }
}

void present_working_directory()
{
    char dir[256];
    getcwd(dir, sizeof(dir));
    cout << dir << endl;
}

void list_directories()
{
    for (const auto & entry : fs::directory_iterator("."))
        std::cout << entry.path() << std::endl;
}

int main()
{
    while (1)
    {
        string command;
        cout << "> ";
        getline(std::cin, command);
        vector<string> tokens = tokenize(command);
        if (tokens[0] == "cd")
        {
            change_directory(tokens[1]);
        }

        else if (tokens[0] == "pwd")
        {
            present_working_directory();
        }

        else if (tokens[0] == "ls")
        {
            list_directories();
        }
    }
}