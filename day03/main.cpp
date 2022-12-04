#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

int main(){
    //printf("Code is running :)  \n");
    int temp_int, total_score, half_string_length;
    temp_int = 0;
    total_score = 0;

    fstream inputfile;
    inputfile.open("input.txt",ios::in);
    if(inputfile.is_open()){
        string current_line, first_half, second_half, temp_string;
        //printf("file is open and read \n");
        while(getline(inputfile, current_line)){
            //cout << current_line << "\n";
            half_string_length = (current_line.length())/2;     //calculating the half of the length of the current string
            first_half = current_line.substr(0, half_string_length);    //determing what is the first half of the string
            second_half = current_line.substr(half_string_length, half_string_length * 2);  //determing what is the second half of the string
            //cout << first_half << "\n" ;
            //cout << second_half << "\n";
            for(int i = 0;i <= half_string_length -1; i++){
                temp_string = first_half;
                char temp_char, temp_char_2, right_object;
                temp_char = temp_string.at(i);      //iterating through each character of the first half of the current line
                //cout << temp_char << "\n";
                int iterator = 0;
                for(iterator; iterator <= half_string_length -1; iterator++){
                    temp_char_2 = second_half.at(iterator);     //iterating through each character of the second half of the curent line
                    if(temp_char == temp_char_2){   //checking if the character that is used at the moment is the duplicate one
                        right_object = temp_char;   //using name right object for the char
                        //cout << "The object is " << right_object << "\n";
                        iterator = half_string_length;  //breaking the iterator cycle
                        i = half_string_length; //breaking i cycle
                        int temp_value = 0;
                        temp_value = right_object;  //the duplicat character is converted to a int
                        //cout << temp_value << "\n";
                        if(temp_value < 91){    //taking note if the char is lower or uppercase by comparing the int value
                            temp_value = temp_value -38;    //using specific int as subtractor to achieve the desired range
                        }
                        else{
                            temp_value = temp_value -96;    //using other subtractor for the desired range
                        }
                        //cout << temp_value << "\n";
                        total_score = total_score + temp_value;     //adding the value to the sum
                        //cout << "The Score is " << total_score << "\n \n";
                    }
                }
            }
        }
    }
    cout << "The total score is " << total_score << "\n";
    inputfile.close();
    return 0;
};
