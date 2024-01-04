//
// Created by st034444 on 12/14/2023.
//
#include <iostream>
#include <fstream>
#include "Array/Graph/Graph.h"
#include <vector>

array::Graph constructGraph(std::vector<std::string> wordlist, int wordLength){
    array::Graph graph = array::Graph(wordlist.size());
    for(int i = 0; i < wordlist.size();i++){
        for(int a = 0; a < wordlist.size(); a++){
            if(i != a){

                int mutualLetterCount = 0;
                for(int b = 0; b < wordLength ; b++){
                    if(wordlist[i][b] == wordlist[a][b])
                        mutualLetterCount++;
                }
                if(mutualLetterCount == wordLength-1) {
                    graph.addEdge(i, a);
                    graph.addEdge(a,i);
                }
            }
        }
    }
    return graph;
}
void performSearch(array::Graph graph, std::vector<std::string> wordlist, std::string fromWord, std::string toWord){
    int from = -1, to = -1;
    for (int i = 0; i < wordlist.size(); ++i) {
        if(wordlist[i] == fromWord)
            from = i;
        if(wordlist[i] == toWord)
            to = i;
    }
    graph.breadthFirstSearch2(wordlist, from, to);
}
Path shortestPath(array::Graph graph, std::vector<std::string> wordlist, std::string fromWord, std::string toWord){
    int from = -1, to = -1;
    for (int i = 0; i < wordlist.size(); ++i) {
        if(wordlist[i] == fromWord)
            from = i;
        if(wordlist[i] == toWord)
            to = i;
    }
    return graph.dijkstra(from, to);
}

int main(){

    std::vector<std::string> threeLetterWords = {};
    std::vector<std::string> fourLetterWords = {};
    std::vector<std::string> fiveLetterWords = {};

    std::ifstream file("C:\\Users\\st034444\\Desktop\\english-dictionary.txt");
    std::string line;

    while (std::getline(file, line)) {
        if(line.size() == 3)
            threeLetterWords.push_back(line);
        if(line.size() == 4)
            fourLetterWords.push_back(line);
        if(line.size() == 5)
            fiveLetterWords.push_back(line);
    }

    array::Graph threeLetterGraph = constructGraph(threeLetterWords, 3);
    array::Graph fourLetterGraph = constructGraph(fourLetterWords, 4);
    array::Graph fiveLetterGraph = constructGraph(fiveLetterWords,5);

    performSearch(threeLetterGraph, threeLetterWords, "cot", "dog"); //273 262  //line 1
    performSearch(fourLetterGraph, fourLetterWords, "anne", "anoa"); //107 106  //line 2
    performSearch(fiveLetterGraph, fiveLetterWords, "abaca", "aback"); //       //line 3
    //The code only returns path when words exists in dictionary but no path between!
    //Give word inputs as here, three letter words for line 1, four letter words for line 2, five letter words for line3
    //shortest path method exists
    return 0;//273 262
}
