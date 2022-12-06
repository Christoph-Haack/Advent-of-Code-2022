#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;



int main(){
    fstream inputfile;                              //creating file stream
    inputfile.open("input.txt",ios::in);            //opening file in filestream
    string input_string, sorted_string_segment;     //defining the strings
    getline(inputfile, input_string);               //copying the content into the string
    cout << input_string << "\n";                   //printing content
    int char_pos, counter;                          //defining the ints

    for(int i = 0; i <= input_string.length(); i++){        //iterating through each character with the iterator i
        sorted_string_segment = input_string.substr(i, 14);     //copying the content of the next 14 chars of the string into a temp_string
        sort(sorted_string_segment.begin(), sorted_string_segment.end());   //sorting the temp_string
        for(int k = 0; k <= 12; k++){       //iterating through the the temp_string for each comparison (13)
            if(sorted_string_segment.at(k) != sorted_string_segment.at(k +1)){      //testing if the current elememt of the sorted string is distinctive compared to the next one
                counter = counter +1;   //in that case adding one to the temp counter
            }
        }
        if(counter == 13){      //checking if every character of the 14 chars in the temp sorted string were distinctive
            char_pos = i +14;       //setting the requested char pos value
            i = input_string.length();  //breaking the loop, by setting the iterator i to the end
            cout << char_pos << "\n";   //printing the requested value
        }
        else{       //in case the chrs were not distinctive
            counter = 0;    //reseting counter
        }
    }
}