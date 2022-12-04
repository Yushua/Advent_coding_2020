#include <fstream>
#include <iostream>
#include <sstream>

#include <string>
#include <algorithm>
#include <iostream>
#include <list>

int main(){
    std::ifstream infile("text_1.txt");
    std::string line;
    std::string a;

    std::list<std::string> forest;
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        iss >> a;
        forest.push_back(a);
    }
    int posy = 0;
    int posx = 0;
    int pos = 0;
    int score = 0;
    for (std::string x : forest) {
        std::cout << x << " " << pos << " " << posx << std::endl;
        if (pos != 0){
            if (posx >= x.length()){
                posx -= x.length();
            }
            if (x[posx] == '#'){
                score++;
            }
        }
        posx+= 3;
        pos++;
	}
    std::cout << score << std::endl;
    return (0);
}

