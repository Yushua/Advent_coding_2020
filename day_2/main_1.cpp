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
        std::cout << c << " " << min << " " << max << "\n";
        int count = 0;
        for (int l = 0; l < pass.length(); l++){
            if (pass[l] == c){
                count++;
            }
        }
        if (count >= min && count <= max){
            score++;
        }
    }
    std::cout << "score " << score << std::endl;
    return (0);
}

