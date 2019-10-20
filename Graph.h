#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include "Vertex.h"
using namespace std;

class Graph
{
private:
    vector<vector<Vertex*>> vertices;
<<<<<<< HEAD
    float sumOfDegrees = 0; //store's the sum of vertices degrees
=======
    float maxProbSum = 0;

>>>>>>> f6a639d4071c1adb913d3129655e71067e7551f7
public:
    Graph();
    Graph(int nbreVertex); //Graph constructor for question 1
    void setVertices(vector<vector<Vertex*>> vertices);
    vector< vector<Vertex*> > getVertices();
    void showGraph();
<<<<<<< HEAD
    void addVertex(Vertex* neighborVertex);
    float returnProbability(int VertexId);
    void updateSumOfDegrees();
    int getDegree(int VertexId);
    int getSumOfDegrees();
    void setSumOfDegrees(float newSum);
    void showAllProbabilities();
    void updateAllProbabilities();
    void addEdgesToGrpah(int nbreVerte, float probablity); // Question 1
    Vertex* chooseNextVertex();                            // Question 2
    ~Graph();
};
#endif
=======
    void BronKerbosch(vector<Vertex*> R,vector<Vertex*> P,vector<Vertex*> X);
    void showCliques(vector<Vertex*> clique);
    void addVertex(Vertex* neighborVertex);
    float returnRandomProbability(int VertexId);
    void updateMAxProbSum();
    int getDegree(int VertexId);
    int getMAxProbSym();
    void setMaxProbSum(float newSum);
    Vertex* addEdgesToGrpah(int nbreVerte, float probablity);
    ~Graph();
};
#endif
>>>>>>> f6a639d4071c1adb913d3129655e71067e7551f7
