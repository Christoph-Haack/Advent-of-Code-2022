#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;



int main(){
    fstream inputfile;
    inputfile.open("input.txt",ios::in);
    string input_string, sorted_string_segment;
    getline(inputfile, input_string);
    cout << input_string << "\n";

    int char_pos, counter;
    

    for(int i = 0; i <= input_string.length(); i++){
        sorted_string_segment = input_string.substr(i, 14);
        sort(sorted_string_segment.begin(), sorted_string_segment.end());
        for(int k = 0; k <= 12; k++){
            if(sorted_string_segment.at(k) != sorted_string_segment.at(k +1)){
                counter = counter +1;
            }
        }
        if(counter == 13){
            char_pos = i +14;
            i = input_string.length();
            cout << char_pos << "\n";
        }
        else{
            counter = 0;
        }
    }

}