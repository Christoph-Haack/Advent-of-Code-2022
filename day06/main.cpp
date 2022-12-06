#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <stack>
using namespace std;



int main(){                                     //
    fstream inputfile;                          //  creating of the file stream
    inputfile.open("input.txt",ios::in);        //  standard file opening and reading
    string input_string;                        //  string to be copied into
    getline(inputfile, input_string);           //  all the content is in one line, which is copied
    cout << input_string << "\n";               //  printing of content

    int char_pos;       //the int value, that signifies the position of the requested character

    for(int i = 0; i <= input_string.length(); i++){        //iterates through each character, with the iterator i
        if( ( input_string.at(i) != input_string.at(i +1) ) && ( input_string.at(i) != input_string.at(i +2) ) && ( input_string.at(i) != input_string.at(i +3) ) ){
            //tests if the first character is distinctive compared to the second, third and fourth one
            if( ( input_string.at(i +1) != input_string.at(i +2) ) && ( input_string.at(i +1) != input_string.at(i +3) ) ){
                //tests if the second one is distinctive compared to the third and fourth one
                if( input_string.at(i +2) != input_string.at(i +3)){
                    //tests if the third one is distinctive to the fourth one
                    char_pos = i +4;    //setting the requested position of the char
                    cout << input_string.at(i) << input_string.at(i +1) << input_string.at(i +2) <<  input_string.at(i +3) << "\n"; //printing the compared chars
                    cout << char_pos << "\n";   //printing the requested positional value
                    i = input_string.length();  //breaking the cycle, by setting the iterator directly to the end
                }
            }
        }        
    }
}