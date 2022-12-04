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

    int a;
    std::list<int> my_list;
    int max = 0;
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        iss >> a;
        my_list.push_back(a);
    }
    for (int x : my_list) {
        for (int z : my_list){
            for (int f : my_list){
                if (x + z + f == 2020){
                    std::cout << "[" << x * z * f << "]\n";
                    return (0);
                }
            }
        }
	}
    return (0);
}

