#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

int main(){
    //printf("Code is running :)  \n");
    int temp_int, total_score, string_length_1, string_length_2, string_length_3;
    temp_int = 0;
    total_score = 0;
    char right_object, temp_char;
    fstream inputfile;
    inputfile.open("input.txt",ios::in);
    if(inputfile.is_open()){
        string current_line, first_line, second_line, third_line, temp_string;
        //printf("file is open and read \n");
        for(int iterator = 0; iterator <= 99 ; iterator++){ //for each three lines of input, one iterator for cycling
            getline(inputfile, current_line);           //getting the first line
            //cout << current_line << "\n";               
            string_length_1 = current_line.length();    //saving the length of the first line
            first_line = current_line;                  //saving the first line

            getline(inputfile, current_line);           //getting the second line
            //cout << current_line << "\n";
            string_length_2 = current_line.length();    //saving length of second line
            second_line = current_line;                 //saving the second line

            getline(inputfile, current_line);           //getting third line
            //cout << current_line << "\n";
            string_length_3 = current_line.length();    //saving the length of third line
            third_line = current_line;                  //saving the third line

            for(int j = 0; j <= string_length_1 -1; j++){   //cycling through the length of the first line
                temp_char = first_line.at(j);               //cycling through each char of the first line
                //cout << temp_char << "\n";
                for(int k = 0; k <= string_length_2 -1; k++){   //cycling through the length of the second line
                    if(temp_char == second_line.at(k)){         //cylcing through each char of the second line
                        for(int l = 0; l <= string_length_3 -1; l++){   //cycling through the length of the third line
                            if(temp_char == third_line.at(l)){          //cycling through each char of the third line and comparing it to the char of the first line
                                right_object = temp_char;           //renaming the duplicate to the right object char
                                //cout << right_object << "\n";
                                int temp_value = 0;
                                temp_value = right_object;      //converting the char to the inherent int value
                                //cout << temp_value << "\n";
                                j = string_length_1;        //breaking j cycle
                                k = string_length_2;        //breaking k cycle
                                l = string_length_3;        //breaking l cycle
                                if(temp_value < 91){    //splitting the lower and uppercase characters by comparing the values
                                    temp_value = temp_value -38;    //specific subtractor for the desired range
                                    }
                                    else{
                                        temp_value = temp_value -96;    //specific subtractor for the desired range
                                    }
                                    //cout << temp_value << "\n";
                                    total_score = total_score + temp_value;     //adding the value to the sum
                                    //cout << "The Score is " << total_score << "\n \n";
                            }
                        }
                    }
                }   
            }   
        }
    }
    cout << "The total score is " << total_score << "\n";
    inputfile.close();
    return 0;
};
