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
    float maxProbSum = 0;
public:
    Graph();
    Graph(int nbreVertex); //Graph constructor for question 1
    void setVertices(vector<vector<Vertex*>> vertices);
    vector< vector<Vertex*> > getVertices();
    void showGraph();
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