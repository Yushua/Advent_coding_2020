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

    std::string string;

    int score = 0;
    std::string dupl;
    int size = 0;
    while (std::getline(infile, line))
    {
        std::string a;
        std::istringstream iss(line);
        if ((iss >> a)){
            string += a;
            size++;
        }
        else{
            dupl = removeDuplicates(string);
            std::cout << "[" << dupl << "][" << string << "]\n";
            for (int y = 0; y < dupl.size(); y++){
                int count = 0;
                for (int i = 0; i < string.size(); i++)
                    if (string[i] == dupl[y])
                    count++;
                std::cout << "[" << count << "][" << size << "]\n";
                if (count == size){
                    score += 1;
                    std::cout << "char[" << dupl[y] << "]\n";
                }
            }
            size = 0;
            std::cout << "score [" << score << "]\n\n";
            string = "";
        }
    }
    dupl = removeDuplicates(string);
    std::cout << "[" << dupl << "][" << string << "]\n";
    for (int y = 0; y < dupl.size(); y++){
        int count = 0;
        for (int i = 0; i < string.size(); i++)
            if (string[i] == dupl[y])
            count++;
        std::cout << "[" << count << "][" << size << "]\n";
        if (count == size){
            score += 1;
            std::cout << "char[" << dupl[y] << "]\n";
        }
    }
    size = 0;
    std::cout << "score [" << score << "]\n\n";
    string = "";
    std::cout << "score [" << score << "]\n";
    return (0);
}
