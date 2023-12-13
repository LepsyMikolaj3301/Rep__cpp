#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
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


int all_cube_val(string line, string color_cube) {
    stringstream stream_line(line);
    string s;
    vector<string> v;
    int value_max = 0, possible_val;

    while(getline(stream_line, s, ' ')) {
        v.push_back(s);
    }
    for (int i = 2; i < v.size(); i++) {
        if(v[i].find(color_cube) != string::npos) {
            possible_val = stoi(v[i - 1]);
            if(possible_val > value_max) {
                value_max = possible_val;
            }
        }
    }
    return value_max;
}


game_data line_data_to_struct(string line) {
    game_data one_line_data;
    one_line_data.num_game = stoi(between(line, "Game ", ": "));
    one_line_data.num_red = all_cube_val(line, "red");
    one_line_data.num_green = all_cube_val(line, "green");
    one_line_data.num_blue = all_cube_val(line, "blue");
    return one_line_data;
}





int main() {

    game_data optimal_cube_values = {0, 12, 13, 14}, line_data;
    int sum_of_ids = 0;


    fstream file("input.txt");
    string the_line;
    while(getline(file, the_line)) {
        line_data = line_data_to_struct(the_line);
        if(optimal_cube_values.num_red < line_data.num_red) continue;
        if(optimal_cube_values.num_green < line_data.num_green) continue;
        if(optimal_cube_values.num_blue < line_data.num_blue) continue;
        sum_of_ids += line_data.num_game;
    }
    cout << "Suma ID gier: " << sum_of_ids << '\n';
}