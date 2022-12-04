#include <fstream>
#include <iostream>
#include <sstream>

#include <string>

int main(){
    std::ifstream infile("text_1.txt");

    std::string line;

    std::string param, pos, pass;
    int score = 0;
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        iss >> param >> pos >> pass;
        std::cout << param << " " << pos << " " << pass << " ";
        int i = param.find("-");
        char c = pos[0];
        int min = atoi(param.substr(0, i).c_str());
        int max = atoi(param.substr(i+1, param.length()).c_str());
        int count = 0;
        std::cout << pass[min - 1] << " " << pass[max - 1] << "\n";
        if (pass[min-1] == c && pass[max-1] != c){
            score++;
        }
        else if (pass[max-1] == c && pass[min-1] != c){
            score++;
        }
    }
    std::cout << "score " << score << std::endl;
    return (0);
}

