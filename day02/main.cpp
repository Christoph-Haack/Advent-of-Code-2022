#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
using namespace std;


int main(){

    printf("Code is running :)  \n");

    int temp_int, total_score;
    temp_int = 0;
    total_score = 0;

    /*
    map<string,int>scenario;
    scenario.insert({"A X",4});     //rock rock 1 tie 3 = 4
    scenario.insert({"B X",1});     //paper rock 1 loss 0 = 1  
    scenario.insert({"C X",7});     //scissor rock 1 win 6 = 7
    scenario.insert({"A Y",8});     //rock paper 2 win 6 = 8
    scenario.insert({"B Y",5});     //paper paper 2 tie 3 = 5
    scenario.insert({"C Y",2});     //scissor paper 2 loss 0 = 2
    scenario.insert({"A Z",3});     //rock scissor 3 loss 0 = 3
    scenario.insert({"B Z",9});     //paper scissor 3 win 6 = 9
    scenario.insert({"C Z",6});     //scissor scissor 3 tie 3 = 6
    */

    map<string,int>scenario;
    scenario.insert({"A X",3});     //rock scissor 3 
    scenario.insert({"B X",1});     //paper rock 1
    scenario.insert({"C X",2});     //scissor paper 2
    scenario.insert({"A Y",4});     //rock rock 1 tie 3 = 4
    scenario.insert({"B Y",5});     //paper paper 2 tie 3 = 5
    scenario.insert({"C Y",6});     //scissor scissor 3 tie 3 = 6
    scenario.insert({"A Z",8});     //rock paper 2 win 6 = 8
    scenario.insert({"B Z",9});     //paper scissor 3 win 6 = 9
    scenario.insert({"C Z",7});     //scissor rock 1 win 6 = 7

    fstream inputfile;
    inputfile.open("input.txt",ios::in);
    if(inputfile.is_open()){
        string current_line;
        printf("file is open and read \n");
        while(getline(inputfile, current_line)){
            cout << current_line << "\n";

            temp_int = scenario.at(current_line);
            printf("%d \n", temp_int);
            total_score = total_score + temp_int;
            printf("new score %d \n", total_score);


            





        }
    }


    printf("The answer is %d \n ", total_score);

    inputfile.close();
    return 0;
};
