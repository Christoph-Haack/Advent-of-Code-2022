#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <stack>
using namespace std;



int main(){
    fstream inputfile;
    inputfile.open("input.txt",ios::in);
    string input_string;
    getline(inputfile, input_string);
    cout << input_string << "\n";

    int char_pos;

    for(int i = 0; i <= input_string.length(); i++){
        if( ( input_string.at(i) != input_string.at(i +1) ) && ( input_string.at(i) != input_string.at(i +2) ) && ( input_string.at(i) != input_string.at(i +3) ) ){
            if( ( input_string.at(i +1) != input_string.at(i +2) ) && ( input_string.at(i +1) != input_string.at(i +3) ) ){
                if( input_string.at(i +2) != input_string.at(i +3)){
                    char_pos = i +4;
                    cout << input_string.at(i) << input_string.at(i +1) << input_string.at(i +2) <<  input_string.at(i +3) << "\n";
                    cout << char_pos << "\n";
                    i = input_string.length();
                }
            }
        }        
    }
}