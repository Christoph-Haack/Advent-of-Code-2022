#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

int main(){
    //printf("Code is running :)  \n");
    int temp_int, total_score, delimiter_pos, end_pos, first_pos, second_pos, first_int, second_int, third_int, fourth_int, counter;
    string first_number, second_number, third_number, fourth_number;
    temp_int = 0;
    counter = 1;
    total_score = 0;
    fstream inputfile;
    inputfile.open("input.txt",ios::in);
    if(inputfile.is_open()){
        string current_line;
        //printf("file is open and read \n");
        while(getline(inputfile, current_line)){
            //cout << current_line << "\n";
        delimiter_pos = current_line.find(',');     //finding the pos of the delimiter ','
        end_pos = current_line.length();        //finding the pos of the end of line
        //cout << "The end is at pos " << end_pos << "\n";
        first_pos = current_line.find('-');     //finding the sub delimiter of the first range '-'
        second_pos = current_line.find('-', first_pos +1);  //finding the sub delimiter of the second range '-'
        //cout << first_pos << "   " << second_pos << "\n";
        first_number = current_line.substr(0, first_pos);   //determining which is the first number of the first range
        //cout << first_number << "  ";
        second_number = current_line.substr(first_pos +1, delimiter_pos -1 - first_pos);    //determining which is the second number of the first range
        //cout << second_number << "  ";
        third_number = current_line.substr(delimiter_pos +1, second_pos -1 - delimiter_pos);    //determing which is the first number of the second range
        fourth_number = current_line.substr(second_pos +1, end_pos - second_pos);   //determining which is the second number of the second range
        //cout << third_number << "   " << fourth_number << "\n";
        first_int = stoi(first_number);     //converting string to int 1
        second_int = stoi(second_number);   //converting string to int 2
        third_int = stoi(third_number);     //converting string to int 3
        fourth_int = stoi(fourth_number);   //converting string to int 4
        //cout << first_int << "   " << second_int << "   " << third_int << "   " << fourth_int << "\n";
        if(first_int > second_int){     //ordering the values of the first range by size
            temp_int = first_int;
            first_int = second_int;
            second_int = temp_int;
        }
        if(third_int > fourth_int){     //ordering the values of the second range by size
            temp_int = third_int;
            third_int = fourth_int;
            fourth_int = temp_int;
        }
        //cout << first_int << "   " << second_int << "   " << third_int << "   " << fourth_int << "\n";
        if(first_int <= third_int){          //cheking if the first range is inside the second range
            if(second_int >= fourth_int){       //cheking if the first range is inside the second range
                if(first_int == third_int){     //using an exception if the outer bounds of the ranges are the same
                    if(second_int == fourth_int){   //... further exception
                        total_score = total_score -1;   //subtracting one, because it triggers both of the following additions
                        //cout << first_int << " = " << third_int << " and " << second_int << " = " << fourth_int <<    "\n";
                    }
                }
                total_score = total_score + 1;      //adding one to the tally
                //cout << total_score << " At line " << counter << "\n";
            }
        }
        if(first_int >= third_int){     //making the check if the second range is inside the first one
            if(second_int <= fourth_int){   //making the check if the second range is inside the first one
                total_score = total_score + 1;      //adding to the tally
                //cout << total_score << " At line " << counter << "\n";
            }
        }
        counter = counter +1;       //adding up the line counter
        //cout << "LINE BREAK...\n\n";
        }
    }
    inputfile.close();
    //cout << "Lines read " << counter -1 << "\n";
    cout << "The total score is " << total_score << "\n \n \n";
    return 0;
}


