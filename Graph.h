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
    float sumOfDegrees = 0; //store's the sum of vertices degrees
public:
    Graph();
    Graph(int nbreVertex); //Graph constructor for question 1
    void setVertices(vector<vector<Vertex*>> vertices);
    vector< vector<Vertex*> > getVertices();
    void showGraph();
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
