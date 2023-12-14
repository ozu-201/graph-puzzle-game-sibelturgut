//
// Created by st034444 on 12/14/2023.
//
#include <iostream>
#include <fstream>
#include "../List/Array/Graph/Graph.h"

void constructList(){

}

int main(){
    std::cout << "a";

    int threeCount = 0;
    int fourCount = 0;
    int fiveCount = 0;

    std::ifstream file("C:/Users/TEMP/Desktop/vocab.txt");
    std::string line;

    while (getline(file, line)) {
        if(line.size() == 3)
            threeCount++;
        if(line.size() == 4)
            fourCount++;
        if(line.size() == 5)
            fiveCount++;
    }
    array::Graph threeLetterGraph = array::Graph(threeCount);
    array::Graph fourLetterGraph = array::Graph(fourCount);
    array::Graph fiveLetterGraph = array::Graph(fiveCount);
    return 0;
}

