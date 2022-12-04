#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

int main(){

    printf("Code is running :)  \n");

    int temp_int, total_score, half_string_length;
    temp_int = 0;
    total_score = 0;


    fstream inputfile;
    inputfile.open("input.txt",ios::in);
    if(inputfile.is_open()){
        string current_line, first_half, second_half, temp_string;
        printf("file is open and read \n");
        while(getline(inputfile, current_line)){
            //cout << current_line << "\n";

            half_string_length = (current_line.length())/2;
            first_half = current_line.substr(0, half_string_length);
            second_half = current_line.substr(half_string_length, half_string_length * 2);
            //cout << first_half << "\n" ;
            //cout << second_half << "\n";

            for(int i = 0;i <= half_string_length -1; i++){
                temp_string = first_half;
                char temp_char, temp_char_2, right_object;
                temp_char = temp_string.at(i);

                //cout << temp_char << "\n";
                int iterator = 0;
                for(iterator; iterator <= half_string_length -1; iterator++){
                    temp_char_2 = second_half.at(iterator);
                    
                    if(temp_char == temp_char_2){
                        right_object = temp_char;
                        cout << "The object is " << right_object << "\n";
                        iterator = half_string_length;
                        i = half_string_length;
                        int temp_value = 0;
                        temp_value = right_object;
                        cout << temp_value << "\n";
                        if(temp_value < 91){
                            temp_value = temp_value -38;
                        }
                        else{
                            temp_value = temp_value -96;
                        }
                        //cout << temp_value << "\n";
                        total_score = total_score + temp_value;
                        //cout << "The Score is " << total_score << "\n \n";

                    }

                }

            }


        }
    }

    cout << "The total score is " << total_score << "\n \n";

    inputfile.close();
    return 0;
};
