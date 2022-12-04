#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

int main(){
    //printf("Code is running :)  \n");
    int temp_calories, sum_calories, highest_sum_calories, temp_int, second_highest_sum_calories, third_highest_sum_calories;
    highest_sum_calories = 0;
    temp_int = 0;
    temp_calories = 0;
    sum_calories = 0;
    fstream inputfile;
    inputfile.open("input.txt",ios::in);    //opening file input
    if(inputfile.is_open()){                //checking if opening is successfull
        string current_line;
        //printf("file is open and read \n");
        while(getline(inputfile, current_line)){    //getting the current line
            //cout << current_line << "\n";
            temp_int = temp_int + 1;    //temporary counter for each line
            if(current_line.length() == 0){     //checking if line is empty
                if(sum_calories >= highest_sum_calories){   //making comparisons to determine if it is the highest calories
                    third_highest_sum_calories = second_highest_sum_calories;   //ripple effect on the values of the 2 and 3 place
                    second_highest_sum_calories = highest_sum_calories;
                    highest_sum_calories = sum_calories;
                    //printf("new highest calories is %d  \n  In Line %d \n", highest_sum_calories, temp_int);
                    sum_calories = 0;
                }
                else{
                    if(sum_calories >= second_highest_sum_calories){    //same but for 2 highest
                        third_highest_sum_calories = second_highest_sum_calories;
                        second_highest_sum_calories = sum_calories;
                    }
                    else{
                        if(sum_calories >= third_highest_sum_calories){ //same but for 3 highest
                            third_highest_sum_calories = sum_calories;
                        }
                    }
                    sum_calories = 0;   //reseting the summation
                }
            } 
            else{
                temp_calories = stoi(current_line);         //converting the string of the value to an temporary int
                sum_calories = sum_calories + temp_calories;    //adding the int to the sum
                //printf("new sum is %d  \n", sum_calories);
            }
        }
        inputfile.close();
        temp_int = highest_sum_calories + second_highest_sum_calories + third_highest_sum_calories; //using temp int for the end calc for the result
        printf("The highest are %d \nThe second highest are %d \nThe third highest are %d \nTotal sum is %d \n ", highest_sum_calories, second_highest_sum_calories, third_highest_sum_calories, temp_int);
    }
    return 0;
}


