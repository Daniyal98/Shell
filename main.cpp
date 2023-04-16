#include <iostream>
using namespace std;

int main()
{
    string command;
    cout << "> ";
    getline(std::cin, command);
    cout << command << endl;
}