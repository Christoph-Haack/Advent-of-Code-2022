#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

int main(){

    printf("Code is running :)  \n");

    int temp_int, total_score, delimiter_pos, end_pos, first_pos, second_pos, first_int, second_int, third_int, fourth_int, counter, overlaping;
    string first_number, second_number, third_number, fourth_number;
    temp_int = 0;
    counter = 1;
    total_score = 0;
    
    
    fstream inputfile;
    inputfile.open("input.txt",ios::in);
    if(inputfile.is_open()){
        string current_line;
        printf("file is open and read \n");
        while(getline(inputfile, current_line)){
            cout << current_line << "\n";

        delimiter_pos = current_line.find(',');
        end_pos = current_line.length();
        //cout << "The end is at pos " << end_pos << "\n";

        //check if the first number is in the range of the seconf half
        //do the same for the second number
        //if both are true it overlaps

        first_pos = current_line.find('-');
        second_pos = current_line.find('-', first_pos +1);
        //cout << first_pos << "   " << second_pos << "\n";

        first_number = current_line.substr(0, first_pos);
        //cout << first_number << "  ";
        second_number = current_line.substr(first_pos +1, delimiter_pos -1 - first_pos);
        //cout << second_number << "  ";

        third_number = current_line.substr(delimiter_pos +1, second_pos -1 - delimiter_pos);
        fourth_number = current_line.substr(second_pos +1, end_pos - second_pos);
        //cout << third_number << "   " << fourth_number << "\n";

        first_int = stoi(first_number);
        second_int = stoi(second_number);
        third_int = stoi(third_number);
        fourth_int = stoi(fourth_number);

        //cout << first_int << "   " << second_int << "   " << third_int << "   " << fourth_int << "\n";

        if(first_int > second_int){
            temp_int = first_int;
            first_int = second_int;
            second_int = temp_int;
        }
        if(third_int > fourth_int){
            temp_int = third_int;
            third_int = fourth_int;
            fourth_int = temp_int;
        }
        
        //cout << first_int << "   " << second_int << "   " << third_int << "   " << fourth_int << "\n";
        
        if(first_int >= third_int){
            if(first_int <= fourth_int){
                total_score = total_score +1;
                overlaping = 1;
            }
        }
        if(overlaping == 0){
            if(second_int >= third_int){
                if(second_int <= fourth_int){
                    total_score = total_score +1;
                    overlaping = 1;
                }
            }
        }
        if(overlaping == 0){
            if(third_int >= first_int){
                if(third_int <= second_int){
                    total_score = total_score +1;
                    overlaping = 1;
                }
            }
        }
        if(overlaping == 0){
            if(fourth_int >= first_int){
                if(fourth_int <= second_int){
                    total_score = total_score +1;
                    overlaping = 1;
                }
            }
        }    
        if(overlaping == 0){
            cout << "NOT OVERLAPING \n \n";
        }
        
        counter = counter +1;
        overlaping = 0;
        //cout << "LINE BREAK...\n\n";
        }
    

    }




    inputfile.close();
    cout << "Lines read " << counter -1 << "\n";
    cout << "The total score is " << total_score << "\n \n \n";
    return 0;
}


