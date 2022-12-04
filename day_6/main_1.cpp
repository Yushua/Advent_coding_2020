#include <fstream>
#include <iostream>
#include <sstream>

#include <string>
#include <algorithm>
#include <iostream>
#include <list>

std::string removeDuplicates(std::string string){
    for ( std::string::size_type i = 0; i < string.size(); i++ ){
        std::string::size_type j = i + 1;
        while ( j < string.size() ){
            if ( string[i] == string[j] ){
                string.erase( j, 1 );
            }
            else{
                ++j;
            }
        }
    }
    return (string);
}

int main(){
    std::ifstream infile("text_1.txt");

    std::string line;

    std::list<std::string> forest;
    std::string string;

    int score = 0;
    while (std::getline(infile, line))
    {
        std::string a;
        std::istringstream iss(line);
        if ((iss >> a)){
            string += a;
        }
        else{
            string = removeDuplicates(string);
            std::cout << "[" << string << "]\n";
            score += string.length();
            string = "";
        }
    }
    string = removeDuplicates(string);
    std::cout << "[" << string << "]\n";
    score += string.length();
    string = "";
    std::cout << "[" << score << "]\n";
    return (0);
}

