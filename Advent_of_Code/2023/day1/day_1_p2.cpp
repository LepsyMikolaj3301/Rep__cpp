#include <iostream>
#include <fstream>
#include <string>

using namespace std;


string reverse_string(string slowo) {
    string returning = "";
    for (int i = slowo.length() - 1; i > -1; i--) {
        returning += slowo[i];
    }
    return returning;
}


int reading_nums(string input) {
    string rev_string = reverse_string(input);
    int endval = 0;
    int m = 0;


    cout << input << '\n';
    // the left value
    for (int i = 0; i < input.length(); i++) {
        if (48 < int(input[i]) && int(input[i]) <= 57) {
            m = ((int)input[i] - 48) * 10;
            endval += m; // having the first value means, the number will be a number between 11 and 99, first num is decimal
            break;
        }
    }
    // the right value
    
    for (int i = 0; i < rev_string.length(); i++) {
        if (48 < int(rev_string[i]) && int(rev_string[i]) <= 57) {
            m = (int)rev_string[i] - 48;
            endval += m; // second value is digit
            break;
        }
    }
    cout << endval << '\n';
    return endval;
}



int main() {
    int end_sum = 0;
    string line;
    fstream file("input.txt");
    while (getline(file, line)) {
        end_sum += reading_nums(line);
    }
    cout << "The wynik: " << end_sum << '\n';
    
    return 0;
}