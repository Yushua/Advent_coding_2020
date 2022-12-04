#include <fstream>
#include <iostream>
#include <sstream>

#include <string>
#include <algorithm>
#include <iostream>
#include <list>

int slope(int posxx, int posa, std::list<std::string> forest){
    int score = 0;
    int posx = 0;
    int pos = 0;
    for (std::string x : forest) {
        if (pos % posa == 0 && pos != 0){
            if (posx >= x.length()){
                posx -= x.length();
            }
            if (x[posx] == '#'){
                score++;
            }
        }
        if (pos % posa == 0){
            posx += posxx;
        }
        pos++;
	}
    std::cout << "score == [" << score << "]\n";
    return (score);
}

int main(){
    std::ifstream infile("text_1.txt");
    std::string line;
    std::string a;

    std::list<std::string> forest;
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        iss >> a;
        std::cout << "lenght == [" << a.length() << "]\n";
        forest.push_back(a);
    }
    int posy = 0;
    int posx = 0;
    int pos = 0;
    int end = 1;
    long int score = 1;
    score = score * slope(1, 1, forest);
    std::cout << score << std::endl;
    score = score * slope(3, 1, forest);
    std::cout << score << std::endl;
    score = score * slope(5, 1, forest);
    std::cout << score << std::endl;
    score = score * slope(7, 1, forest);
    std::cout << score << std::endl;
    score = score * slope(1, 2, forest);
    std::cout << score << std::endl;
    return (0);
}
