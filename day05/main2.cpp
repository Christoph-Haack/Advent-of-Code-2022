#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <stack>
using namespace std;

/*
Initialize the starting formation of the 9 stacks
    -read the first nine lines
    -push the chars of the lower objects on the designated stacks
Read the liines after 10, and extract the 3 int values amount_of_char, original_stack_number, future_stack_number
    -execute the given instructions
    -pop the original stack the given amount of times and push the char on the future stack
Read which chars are on the top of the stacks and give the result
*/


void show_stacks();
void initialize_stacks();
void reverse_stacks();
void exe_all_instructions();

    stack<char> stack_1;
    stack<char> stack_2;
    stack<char> stack_3;
    stack<char> stack_4;
    stack<char> stack_5;
    stack<char> stack_6;
    stack<char> stack_7;
    stack<char> stack_8;
    stack<char> stack_9;
    stack<char> stack_temp_1;
    stack<char> stack_temp_2;

    int temp_amount, temp_origin, temp_destination;

int main(){
    fstream inputfile;
    inputfile.open("input.txt",ios::in);
    initialize_stacks();
    reverse_stacks();
    exe_all_instructions();
    show_stacks();
    return 0;
}


void exe_all_instructions(){
    fstream inputfile;
    inputfile.open("input.txt",ios::in);
    string current_line, temp_string;
    
    for(int i = 0; i <= 512; i++){
        getline(inputfile, current_line);
        if(i >= 10){
            if(current_line.at(6) != ' '){
                temp_string = current_line.substr(5, 2);
                temp_amount = stoi(temp_string);
                temp_string = current_line.substr(13, 1);
                temp_origin = stoi(temp_string);
                temp_string = current_line.substr(18, 1);
                temp_destination = stoi(temp_string);
            }
            else{
                temp_string = current_line.substr(5, 1);
                temp_amount = stoi(temp_string);
                temp_string = current_line.substr(12, 1);
                temp_origin = stoi(temp_string);
                temp_string = current_line.substr(17, 1);
                temp_destination = stoi(temp_string);
            }
            cout << temp_amount << " " << temp_origin << " " << temp_destination << "\n";


            for(int i = 0; i <= temp_amount -1; i++){

                switch(temp_origin){
                    case 1:
                        stack_temp_1.push(stack_1.top());
                        stack_1.pop();
                        break;
                    case 2:
                        stack_temp_1.push(stack_2.top());
                        stack_2.pop();
                        break;
                    case 3:
                        stack_temp_1.push(stack_3.top());
                        stack_3.pop();
                        break;
                    case 4:
                        stack_temp_1.push(stack_4.top());
                        stack_4.pop();
                        break;
                    case 5:
                        stack_temp_1.push(stack_5.top());
                        stack_5.pop();
                        break;
                    case 6:
                        stack_temp_1.push(stack_6.top());
                        stack_6.pop();
                        break;
                    case 7:
                        stack_temp_1.push(stack_7.top());
                        stack_7.pop();
                        break;
                    case 8:
                        stack_temp_1.push(stack_8.top());
                        stack_8.pop();
                        break;
                    case 9:
                        stack_temp_1.push(stack_9.top());
                        stack_9.pop();
                        break;            
                }
            }

            for(int i = 0; i <= temp_amount -1; i++){

                switch(temp_destination){
                    case 1:
                        stack_1.push(stack_temp_1.top());
                        stack_temp_1.pop();
                        break;
                    case 2:
                        stack_2.push(stack_temp_1.top());
                        stack_temp_1.pop();
                        break;
                    case 3:
                        stack_3.push(stack_temp_1.top());
                        stack_temp_1.pop();
                        break;
                    case 4:
                        stack_4.push(stack_temp_1.top());
                        stack_temp_1.pop();
                        break;
                    case 5:
                        stack_5.push(stack_temp_1.top());
                        stack_temp_1.pop();
                        break;
                    case 6:
                        stack_6.push(stack_temp_1.top());
                        stack_temp_1.pop();
                        break;
                    case 7:
                        stack_7.push(stack_temp_1.top());
                        stack_temp_1.pop();
                        break;
                    case 8:
                        stack_8.push(stack_temp_1.top());
                        stack_temp_1.pop();
                        break;
                    case 9:
                        stack_9.push(stack_temp_1.top());
                        stack_temp_1.pop();
                        break;            
                }
            }
            


        }
    }


}





void show_stacks(void){
    for(int k = 0; k <= 49; k++){
            if(stack_1.size() + k >= 50){  
                cout << stack_1.top() << " ";
                stack_1.pop();
            }
            else{cout << "  ";};
            if(stack_2.size() + k >= 50){  
                cout << stack_2.top() << " ";
                stack_2.pop();
            }
            else{cout << "  ";};
            if(stack_3.size() + k >= 50){  
                cout << stack_3.top() << " ";
                stack_3.pop();
            }
            else{cout << "  ";};
            if(stack_4.size() + k >= 50){  
                cout << stack_4.top() << " ";
                stack_4.pop();
            }
            else{cout << "  ";};
            if(stack_5.size() + k >= 50){  
                cout << stack_5.top() << " ";
                stack_5.pop();
            }
            else{cout << "  ";};
            if(stack_6.size() + k >= 50){  
                cout << stack_6.top() << " ";
                stack_6.pop();
            }
            else{cout << "  ";};
            if(stack_7.size() + k >= 50){  
                cout << stack_7.top() << " ";
                stack_7.pop();
            }
            else{cout << "  ";};
            if(stack_8.size() + k >= 50){  
                cout << stack_8.top() << " ";
                stack_8.pop();
            }
            else{cout << "  ";};
            if(stack_9.size() + k >= 50){  
                cout << stack_9.top() << " ";
                stack_9.pop();
            }
            else{cout << "  ";};
            cout << "\n";
    }
}

void initialize_stacks(){
    fstream inputfile;
    inputfile.open("input.txt",ios::in);
    if(inputfile.is_open()){
        string current_line;
        char temp_char;
        for(int i = 0;i <= 7; i++){
            getline(inputfile, current_line);

            if(current_line.at(1) != ' '){
                stack_1.push(current_line.at(1));
            }
            if(current_line.at(5) != ' '){
                stack_2.push(current_line.at(5));
            }
            if(current_line.at(9) != ' '){
                stack_3.push(current_line.at(9));
            }
            if(current_line.at(13) != ' '){
                stack_4.push(current_line.at(13));
            }
            if(current_line.at(17) != ' '){
                stack_5.push(current_line.at(17));
            }
            if(current_line.at(21) != ' '){
                stack_6.push(current_line.at(21));
            }
            if(current_line.at(25) != ' '){
                stack_7.push(current_line.at(25));
            }
            if(current_line.at(29) != ' '){
                stack_8.push(current_line.at(29));
            }
            if(current_line.at(33) != ' '){
                stack_9.push(current_line.at(33));
            }
        }
        stack_1.push('0');
        stack_2.push('0');
        stack_3.push('0');
        stack_4.push('0');
        stack_5.push('0');
        stack_6.push('0');
        stack_7.push('0');
        stack_8.push('0');
        stack_9.push('0');
    }
}

void reverse_stacks(){

    while(stack_1.size() != 0){
        stack_temp_1.push(stack_1.top());
        stack_1.pop();
    }
    while(stack_temp_1.size() != 0){
        stack_temp_2.push(stack_temp_1.top());
        stack_temp_1.pop();
    }
    while(stack_temp_2.size() != 0){
        stack_1.push(stack_temp_2.top());
        stack_temp_2.pop();
    }

    while(stack_2.size() != 0){
        stack_temp_1.push(stack_2.top());
        stack_2.pop();
    }
    while(stack_temp_1.size() != 0){
        stack_temp_2.push(stack_temp_1.top());
        stack_temp_1.pop();
    }
    while(stack_temp_2.size() != 0){
        stack_2.push(stack_temp_2.top());
        stack_temp_2.pop();
    }

    while(stack_3.size() != 0){
        stack_temp_1.push(stack_3.top());
        stack_3.pop();
    }
    while(stack_temp_1.size() != 0){
        stack_temp_2.push(stack_temp_1.top());
        stack_temp_1.pop();
    }
    while(stack_temp_2.size() != 0){
        stack_3.push(stack_temp_2.top());
        stack_temp_2.pop();
    }

    while(stack_4.size() != 0){
        stack_temp_1.push(stack_4.top());
        stack_4.pop();
    }
    while(stack_temp_1.size() != 0){
        stack_temp_2.push(stack_temp_1.top());
        stack_temp_1.pop();
    }
    while(stack_temp_2.size() != 0){
        stack_4.push(stack_temp_2.top());
        stack_temp_2.pop();
    }

    while(stack_5.size() != 0){
        stack_temp_1.push(stack_5.top());
        stack_5.pop();
    }
    while(stack_temp_1.size() != 0){
        stack_temp_2.push(stack_temp_1.top());
        stack_temp_1.pop();
    }
    while(stack_temp_2.size() != 0){
        stack_5.push(stack_temp_2.top());
        stack_temp_2.pop();
    }

    while(stack_6.size() != 0){
        stack_temp_1.push(stack_6.top());
        stack_6.pop();
    }
    while(stack_temp_1.size() != 0){
        stack_temp_2.push(stack_temp_1.top());
        stack_temp_1.pop();
    }
    while(stack_temp_2.size() != 0){
        stack_6.push(stack_temp_2.top());
        stack_temp_2.pop();
    }

    while(stack_7.size() != 0){
        stack_temp_1.push(stack_7.top());
        stack_7.pop();
    }
    while(stack_temp_1.size() != 0){
        stack_temp_2.push(stack_temp_1.top());
        stack_temp_1.pop();
    }
    while(stack_temp_2.size() != 0){
        stack_7.push(stack_temp_2.top());
        stack_temp_2.pop();
    }

    while(stack_8.size() != 0){
        stack_temp_1.push(stack_8.top());
        stack_8.pop();
    }
    while(stack_temp_1.size() != 0){
        stack_temp_2.push(stack_temp_1.top());
        stack_temp_1.pop();
    }
    while(stack_temp_2.size() != 0){
        stack_8.push(stack_temp_2.top());
        stack_temp_2.pop();
    }

    while(stack_9.size() != 0){
        stack_temp_1.push(stack_9.top());
        stack_9.pop();
    }
    while(stack_temp_1.size() != 0){
        stack_temp_2.push(stack_temp_1.top());
        stack_temp_1.pop();
    }
    while(stack_temp_2.size() != 0){
        stack_9.push(stack_temp_2.top());
        stack_temp_2.pop();
    }




}