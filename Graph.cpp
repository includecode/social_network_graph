#include <iostream>
#include <vector>
#include <iomanip>
#include "Graph.h"
#include <bits/stdc++.h>
using namespace std;

Graph::Graph()
{
    //Creating the 3 base Vertices
    vector<vector<Vertex *>> baseVertices;
    vector<Vertex *> baseNeighbor1;
    vector<Vertex *> baseNeighbor2;
    vector<Vertex *> baseNeighbor3;

    //Creating base vertices
    Vertex *v1 = new Vertex(1, Graph::returnRandomProbability(1));
    Vertex *v2 = new Vertex(2, Graph::returnRandomProbability(2));
    Vertex *v3 = new Vertex(3, Graph::returnRandomProbability(3));

    //Base Vertex* ID = 1
    baseNeighbor1.push_back(v1); //Vertex's itself is the first element of the list
    baseNeighbor1.push_back(v2); //Neighbor of 1
    baseNeighbor1.push_back(v3); //Neighbor of 1
    baseVertices.push_back(baseNeighbor1);

    //Base Vertex ID = 2
    baseNeighbor2.push_back(v2); //Vertex's ID itself is the first element of the list
    baseNeighbor2.push_back(v1); //Neighbor of 2
    baseNeighbor2.push_back(v3); //Neighbor of 2
    baseVertices.push_back(baseNeighbor2);

    //Base Vertex ID = 3
    baseNeighbor3.push_back(v3); //Vertex's ID itself is the first element of the list
    baseNeighbor3.push_back(v1); //Neighbor of 3
    baseNeighbor3.push_back(v2); //Neighbor of 3
    baseVertices.push_back(baseNeighbor3);

    this->vertices = baseVertices;
    this->updateMAxProbSum();
}

/**
 * A Graph constructor for the first Question algorithm
 */
Graph::Graph(int nbreVertex)
{
    //Creating the base Vertices
    vector<vector<Vertex *>> baseVertices;
    for (int i = 0; i < nbreVertex; i++)
    {
        vector<Vertex *> nextVertex;

        //Creating base vertices
        Vertex *v1 = new Vertex(i + 1, Graph::returnRandomProbability(i + 1));

        //Base Vertex* ID = 1
        nextVertex.push_back(v1);
        baseVertices.push_back(nextVertex);
    }

    this->vertices = baseVertices;
    cout << "A Graph of " << nbreVertex << " Vertices has been created" << endl;
}

/**
 * Given n graphes and a given probability p, this function adds adges to a graph according to the probability
 */
Vertex *Graph::addEdgesToGrpah(int nbreVertex, float probablity)
{
    Graph *newGraph = new Graph(nbreVertex);
    for (int i = 0; i < nbreVertex; i++)
    {
        Vertex *currentVertex = this->vertices.at(i).at(0);
        for (int j = i+1; j < nbreVertex; j++)
        {
            //Generate a randon number between 1 and maxProbSum
            int rander = rand() % 100 + 1;
            if(rander >= 0 && rander <= (probablity * 100) ){
                this->vertices.at(i).push_back(this->vertices.at(j).at(0));
                this->vertices.at(j).push_back(this->vertices.at(i).at(0));
            }
        }
    }

    /*
    //We need to sort the vertices according to thier respective probabilities, and store them in a temporary array (Vector)
    //So that we can easily  make the correspondance with the randon number and the choosen Vertex

    int nbreVertex = this->vertices.size();
    vector<Vertex *> sortedProbsOfEachVertex;

    //We make a copy of the graph's vertices
    for (int i = 0; i < this->vertices.size(); i++)
    {
        sortedProbsOfEachVertex.push_back(this->vertices.at(i).at(0));
    }
    std::sort(sortedProbsOfEachVertex.begin(), sortedProbsOfEachVertex.end());

    //Generate a randon number between 1 and maxProbSum
    int rander = rand() % ((int)this->getMAxProbSym()) + 1;

    //Idea:
    //1. genarate a number between 1 and the maxProb
    //2. to pick the choosen Vertex, divide the generated as following example: for a sorted Graph of two vertices of probabilities 0.3 (=30) and 0.7 (=70)... if the
    //generated number R is between 1 and 30 then choosen VErtex is the first of the vector (1 or A), if R is between 30 and 100 then the choosen Vertex is the second of th list...

    int pivot = 0; // This pivot will compute all the ranges successively
    Vertex *choosen = NULL;
    int i = 0;
    while (pivot <= rander)
    {
        if (((int)sortedProbsOfEachVertex.at(0)->getProbability() >= pivot) && ((int)sortedProbsOfEachVertex.at(0)->getProbability()) < ((int)this->getMAxProbSym() - (int)sortedProbsOfEachVertex.at(0)->getProbability())   )
        {
            choosen = sortedProbsOfEachVertex.at(i);
            break;
        }else
        {
            pivot = pivot + (int)sortedProbsOfEachVertex.at(0)->getProbability();
        }

        i++;
    }*/
    Vertex *choosen = NULL;
    return choosen;
}

float Graph::returnRandomProbability(int VertexId)
{

    float prob = ((float)rand() / RAND_MAX) - 0.001;
    std::cout << "Pr(" << VertexId << ") is : " << prob << endl;
    //a bigger number divided by a lesser one is always >0 and <1

    return prob;
}
void Graph::showGraph()
{
    for (int i = 0; i < this->vertices.size(); i++)
    {
        std::cout << this->vertices.at(i).at(0)->getId() << " : ";
        for (int j = 1; j < vertices.at(i).size(); j++) //We start at 1 because we prVertex*ed 0 the main Vertex*
        {
            std::cout << " -> " << this->vertices.at(i).at(j)->getId();
        }
        std::cout << "\n";
    }
}
/*
@Param neighborVertex : The Vertex on wich we want to attach the new Vertex
*/
void Graph::addVertex(Vertex *neighborVertex)
{
    //Search if the Vertex* exists before creating the new neighbor
    bool exists = false;
    for (int i = 0; i < this->vertices.size(); i++)
    {
        if (this->vertices.at(i).at(0)->getId() == neighborVertex->getId())
        {
            exists = true;
            break;
        }
    }

    if (exists)
    {
        vector<Vertex *> newVertex;

        Vertex *currentNew = new Vertex(vertices.size() + 1, Graph::returnRandomProbability(vertices.size() + 1)); //Create the vertex
        newVertex.push_back(currentNew);                                                                           // Set current vertex as main (index 0)
        newVertex.push_back(neighborVertex);                                                                       //Set the new Vertex's neigbor
        this->vertices.push_back(newVertex);                                                                       // Add a new Vertex to the Graph

        this->vertices.at(neighborVertex->getId() - 1).push_back(currentNew); // set the new Vertex as someone's neighbor
        this->updateMAxProbSum();                                             //Update the Graph's maxSum
        std::cout << "A new Vertex* has been added ID is : " << this->vertices.size() << endl;
    }
    else
    {
        std::cout << " **** OVERFLOW the Vertex* number **** [" << neighborVertex << "] does not exist in graph " << endl;
    }
}

/*
    Return's the degree of a Vertex*
    @Param Vertex*Id : The Vertex*'s ID
*/
int Graph::getDegree(int VertexId)
{
    return this->vertices.at(VertexId - 1).size() - 1;
}
void Graph::setVertices(vector<vector<Vertex *>> vertices)
{
    this->vertices = vertices;
}
/**
 * Updates the sum of vertex probabilities
 *
*/
void Graph::updateMAxProbSum()
{
    for (int i = 0; i < this->vertices.size(); i++)
    {
        this->maxProbSum += (this->vertices.at(i).at(0)->getProbability() * 100);
    }
}
vector<vector<Vertex *>> Graph::getVertices()
{
    return this->vertices;
}
int Graph::getMAxProbSym()
{
    return this->maxProbSum;
}
void Graph::setMaxProbSum(float newSum)
{
    this->maxProbSum = newSum;
}

/* Implementation of the Bron-Kerbosch algorithm(to find the maximal cliques) */
vector<Vertex*> set_union(vector<Vertex*> a, vector<Vertex*> b) {
  vector<Vertex*> c;
  set_union(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.end()) );
  return c;
}
vector<Vertex*> set_intersection(vector<Vertex*> a, vector<Vertex*> b) {
  vector<Vertex*> c;
  set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.end()));
  return c;
}
vector<Vertex*> set_difference(vector<Vertex*> a, vector<Vertex*> b) {
  vector<Vertex*> c;
  set_difference(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.end()));
  return c;
}


void Graph::BronKerbosch(vector<Vertex*> R,vector<Vertex*> P,vector<Vertex*> X)
{
    int i=0;
    vector<Vertex*> intersect;
    if(P.empty() && X.empty()){

        cout<<"{ ";
        for(int i=0;i<R.size();i++ )
        {
            cout<<R.at(i)->getId()<<" ";
        }
        cout<<"}\n";
    }
    //for (vector<Vertex*> vertex:vertices)
    for(i;i<this->getVertices().size();i++ )
    {

        for (Vertex* ver:P)
        {
            if(this->getVertices().at(i).at(0)==ver){
                intersect.push_back(ver);
                BronKerbosch(set_union(R,this->getVertices().at(i)),
                            set_intersection(P,this->vertices.at(ver->getId())),
                            set_intersection(X,this->vertices.at(ver->getId())));
                P = set_difference(P,this->getVertices().at(i));
                X = set_union(X,this->getVertices().at(i));
            }
        }
    }
}



