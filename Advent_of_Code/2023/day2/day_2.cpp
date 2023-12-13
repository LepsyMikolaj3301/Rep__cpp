#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <regex>
using namespace std;

struct game_data
{
    int num_game;
    int num_red;
    int num_green;
    int num_blue;
};


string between(
    string const &in,
    string const &before,
    string const &after) 
{
  size_t beg = in.find(before);
  beg += before.size();
  size_t end = in.find(after, beg);
  return in.substr(beg, end-beg);
}



game_data data_outta_string(string line) {
    
    game_data one_line_data;
    

    /*
    index    |   color
        0    |   red
        1    |   blue
        2    |   green
    */ 
    vector<int> spheres[3];

    regex   reg_blue("(\d+)\s+blue"), 
            reg_red("(\d+)\s+red"), 
            reg_green("(\d+)\s+green");

    one_line_data.num_game = stoi(between(line, "Game ", ": "));
    one_line_data.num_red = 




}





int main() {
    fstream file("input.txt");
    string the_line;
    while(getline(file, the_line)) {

    }


}