/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <regex>
#include <string>


using namespace std;

int main()
{
    regex   reg_blue(R"((\d+)(?=\sblue))");
    string line = "Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green";
    smatch m;
    copy( sregex_token_iterator(line.begin(), line.end(), reg_blue, -1),
     sregex_token_iterator(),
     ostream_iterator<string>(cout, "\n"));
    return 0;
}
