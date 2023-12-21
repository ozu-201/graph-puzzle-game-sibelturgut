//
// Created by st034444 on 12/14/2023.
//
#include <iostream>
#include <fstream>
#include "Array/Graph/Graph.h"
#include <vector>

//namespace std{
    array::Graph constructGraph(array::Graph graph, std::vector<std::string> wordlist, int wordLength){
        for(int i = 0; i < wordlist.size();i++){
            for(int a = i; a < wordlist.size(); a++){
                int mutualLetterCount = 0;
                for(int b = 0; b < wordLength ; b++){
                    if(wordlist[i][b] == wordlist[a][b])
                        mutualLetterCount++;
                }
                if(mutualLetterCount == wordLength-1)
                    graph.addEdge(i,a);
            }
        }
        return graph;
    }

    int main(){

        std::vector<std::string> threeLetterWords = {"aee","aee","aee"};
        std::vector<std::string> fourLetterWords = {};
        std::vector<std::string> fiveLetterWords = {};

//        std::vector<std::string> flw = {};
//        flw.push_back("test");
//
//        std::cout << flw[0];


        int threeCount = 0;
        int fourCount = 0;
        int fiveCount = 0;

        std::ifstream file("C:\\Users\\st034444\\Desktop\\vocab.txt");
        std::string line;

        while (std::getline(file, line)) {
            if(line.size() == 3)
                threeLetterWords.push_back(line);
            if(line.size() == 4)
                fourLetterWords.push_back(line);
            if(line.size() == 5)
                fiveLetterWords.push_back(line);
        }

        array::Graph threeLetterGraph = array::Graph(threeCount); //wordlst.size yap
        constructGraph(threeLetterGraph, threeLetterWords, 3);
        array::Graph fourLetterGraph = array::Graph(fourCount);
        constructGraph(fourLetterGraph,fiveLetterWords, 4);
        array::Graph fiveLetterGraph = array::Graph(fiveCount);
        constructGraph(fiveLetterGraph,fiveLetterWords,5);

        std::cout << threeCount;
        std::cout << threeLetterWords.size();

        return 0;
    }
//}
