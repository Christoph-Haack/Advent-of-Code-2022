#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

int main(){

    printf("Code is running :)  \n");

    int temp_calories, sum_calories, highest_sum_calories, temp_int, second_highest_sum_calories, third_highest_sum_calories;
    highest_sum_calories = 0;
    temp_int = 0;
    temp_calories = 0;
    sum_calories = 0;
    
    fstream inputfile;
    inputfile.open("day01",ios::in);
    if(inputfile.is_open()){
        string current_line;
        printf("file is open and read \n");
        while(getline(inputfile, current_line)){
            //cout << current_line << "\n";
            temp_int = temp_int + 1;
            if(current_line.length() == 0){
                if(sum_calories >= highest_sum_calories){
                    third_highest_sum_calories = second_highest_sum_calories;
                    second_highest_sum_calories = highest_sum_calories;
                    highest_sum_calories = sum_calories;
                    printf("new highest calories is %d  \n  In Line %d \n", highest_sum_calories, temp_int);
                    sum_calories = 0;
                }
                else{
                    if(sum_calories >= second_highest_sum_calories){
                        third_highest_sum_calories = second_highest_sum_calories;
                        second_highest_sum_calories = sum_calories;
                    }
                    else{
                        if(sum_calories >= third_highest_sum_calories){
                            third_highest_sum_calories = sum_calories;
                        }
                    }
                    sum_calories = 0;
                }
            } 
            else{
                temp_calories = stoi(current_line);
                sum_calories = sum_calories + temp_calories;
                //printf("new sum is %d  \n", sum_calories);
            }

        }
        inputfile.close();
        temp_int = highest_sum_calories + second_highest_sum_calories + third_highest_sum_calories;
        printf("The answer is %d \n The Second highest are %d \n The third highest are %d \n Total sum is %d \n ", highest_sum_calories, second_highest_sum_calories, third_highest_sum_calories, temp_int);

    }





    return 0;
}


