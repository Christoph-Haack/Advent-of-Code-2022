#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

int main(){

    printf("Code is running :)  \n");

    int temp_int, total_score, string_length_1, string_length_2, string_length_3;
    temp_int = 0;
    total_score = 0;
    char right_object, temp_char;


    fstream inputfile;
    inputfile.open("input.txt",ios::in);
    if(inputfile.is_open()){
        string current_line, first_line, second_line, third_line, temp_string;
        printf("file is open and read \n");


        for(int iterator = 0; iterator <= 99 ; iterator++){
            getline(inputfile, current_line);
            cout << current_line << "\n";
            string_length_1 = current_line.length();
            first_line = current_line;

            getline(inputfile, current_line);
            cout << current_line << "\n";
            string_length_2 = current_line.length();
            second_line = current_line;

            getline(inputfile, current_line);
            cout << current_line << "\n";
            string_length_3 = current_line.length();
            third_line = current_line;
            

            for(int j = 0; j <= string_length_1 -1; j++){
                temp_char = first_line.at(j);
                //cout << temp_char << "\n";

                for(int k = 0; k <= string_length_2 -1; k++){
                    if(temp_char == second_line.at(k)){
                        for(int l = 0; l <= string_length_3 -1; l++){
                            if(temp_char == third_line.at(l)){

                                right_object = temp_char;
                                cout << right_object << "\n";
                                int temp_value = 0;
                                temp_value = right_object;
                                //cout << temp_value << "\n";
                                j = string_length_1;
                                k = string_length_2;
                                l = string_length_3;

                                if(temp_value < 91){
                                    temp_value = temp_value -38;
                                    }
                                    else{
                                        temp_value = temp_value -96;
                                    }
                                    //cout << temp_value << "\n";
                                    total_score = total_score + temp_value;
                                    cout << "The Score is " << total_score << "\n \n";

                            }
                        }
                    }
                }   
            }   
        }
    }

    cout << "The total score is " << total_score << "\n \n";

    inputfile.close();
    return 0;
};
