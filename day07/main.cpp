#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <tuple>
#include <cctype>
using namespace std;


/*
$ cd x        looks in the current directory for the directory x and moves in it
$ cd ..       moves out of the directory by one level
$ cd /        move directly to the outmost directory
$ ls          lists all the files and directories insde the current directory
0000 abc    inside the current directory is the file abc with the size 0000   
dir xyz     inside the current directory is the directory xyz

struct(directory)  
    pointer to the outer directory              *struct directory
    list of files                               tuple <string, int>
    pointer to a sub-directory                  *struct directory
    pointer to sister directorie                *struct directory

$ cd x      if the pointer to a sub-directory is empty add one to a new directory named x, else move to the sub-directory and move so far through the sister directories till the pointer is empty then create the directory x
$ cd ..     look at the pointer to the outer directory, and move to it
$ cd /      look and move as long as the pointer to the outer directory isnt empty to it
    $ ls        ignore, read the next lines normally
0000 abc    add the key abc to the map with the value 0000, and add abc to the list of filenames of the current directory
dir xyz     create the directory xyz and add the pointer to the pointer to a sub-directory if it was empty, else sollow the sub-directory and it`s sister directories till the pointer is empty and add it there

*/          

void move_to_sub_directory(string);
void move_to_outer_directory();
void move_to_the_origin();
void create_file(string, int);
void create_directory(string);

struct directory {
    struct directory *outer_directory;
    struct directory *sub_directory;
    struct directory *sister_directory;
    string name;
    vector<tuple<string, int>> files;
};



directory p_current_directory = &origin_directory;





int main(){                                     //
    fstream inputfile;                          //  creating of the file stream
    inputfile.open("test.txt",ios::in);        //  standard file opening and reading
    string current_line, temp_string;                        //  string to be copied into
    
    while(getline(inputfile, current_line)){   //  reads all the lines and passes them to the string current_line, line by line
        cout << current_line << "\n";               //  printing of content

        if(current_line.at(0) == '$'){
            //cout << "beginnt mit $ \n";
            if(current_line.at(2) == 'l'){
                cout << "IGNORE \n";
            }
            else{
                switch(current_line.at(5)){
                    case '/':
                        cout << "MOVE TO ORIGIN \n";

                        break;
                    case '.':
                        cout << "MOVE TO OUTER DIRECTORY \n";

                        break;
                    default:
                        temp_string = current_line.substr(5);
                        cout << "GO TO THE SUB DIRECTORY " << temp_string << "\n";

                }
            }
        }
        else{
            temp_string = current_line.substr(0, current_line.find(' '));
            if(isdigit(temp_string.at(0))){
                int temp_int = stoi(temp_string);
                cout << "CREATE FILE " << current_line.substr(temp_string.length()) << " with the size " << temp_string << "\n";

            }
            else{
                cout << "MAKE DIRECTORY " << current_line.substr(temp_string.length()) << "\n";

            }
        }

    }

    cout << (*p_current_directory).name;

    return 0;
}



/*

void move_to_sub_directory(string directory_name){
    //string sub_directory_name = *current_directory.sub_directory.name;     
    //int equalornot = sub_directory_name.compare(directory_name);
    //if(equalornot == 0){

    }
}


void move_to_outer_directory(){
    current_directory = current_directory->outer_directory;
}


void move_to_the_origin();

void create_file(string, int);

void create_directory(string);

*/