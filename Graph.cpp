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
    Vertex *v1 = new Vertex(1);
    Vertex *v2 = new Vertex(2);
    Vertex *v3 = new Vertex(3);

    //Base Vertex ID = 1
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
    this->updateSumOfDegrees();
    this->updateAllProbabilities();

    v1->setProbability(this->returnProbability(v1->getId()));
    v2->setProbability(this->returnProbability(v2->getId()));
    v3->setProbability(this->returnProbability(v3->getId()));
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
        Vertex *v1 = new Vertex(i + 1);

        //Base Vertex* ID = 1
        nextVertex.push_back(v1);
        baseVertices.push_back(nextVertex);
    }

    this->vertices = baseVertices;
    cout << "A Graph of " << nbreVertex << " Vertices has been created" << endl;
}

/** ALGO 1
 * Given n Vertices and a given probability p, this function adds adges to a graph according to the probability
 */
void Graph::addEdgesToGrpah(int nbreVertex, float probablity)
{
    for (int i = 0; i < nbreVertex; i++)
    {
        Vertex *currentVertex = this->vertices.at(i).at(0);
        for (int j = i + 1; j < nbreVertex; j++)
        {
            //Generate a randon number between 1 and 100
            int rander = rand() % 100 + 1;
            if (rander >= 0 && rander <= (probablity * 100))
            {
                this->vertices.at(i).push_back(this->vertices.at(j).at(0));
                this->vertices.at(j).push_back(this->vertices.at(i).at(0));
            }
        }
    }
}

/**
 * Given n vertices, the probabilty to add a new Vertex to any of the vertices is deg(v)/sum(deg(all_vertices))
 */
Vertex *Graph::chooseNextVertex()
{
    //Generate a randon number between 1 and 100
    int rander = rand() % 100 + 1;
    cout << "rander = " << rander << endl;
    //Idea:
    //1. genarate a number between 1 and the 100
    //2. to pick the choosen Vertex, divide the generated as following example: for a sorted Graph of two vertices of probabilities 0.3 (=30) and 0.7 (=70)... if the
    //generated number R is between 1 and 30 then choosen VErtex is the first of the vector (1 or A), if R is between 30 and 100 then the choosen Vertex is the second of th list...

    float pivot = 1.f; // This pivot will compute all the ranges successively
    Vertex *choosen = NULL;
    int i = 0;
    while (choosen == NULL)
    {

        /* cout <<"pivot  est "<<pivot<<endl;
            cout <<"probabilite de "<< sortedProbsOfEachVertex.at(i)->getId()<<"est " <<sortedProbsOfEachVertex.at(i)->getProbability() * 100<<endl;
            cout <<"at  est "<<sortedProbsOfEachVertex.at(i)->getProbability() * 100 + pivot<<endl;
            cout <<"FIRST comp de  "<<rander<<" et "<<pivot<<endl;
            cout <<"SEC comp de  "<<rander<<" et "<<pivot + sortedProbsOfEachVertex.at(i)->getProbability() * 100<<endl;
        */
        if (rander >= pivot && rander <= pivot + this->vertices.at(i).at(0)->getProbability() * 100)
        {
            choosen = this->vertices.at(i).at(0);
            if (choosen->getMAxCountNewEdges() >= 2){
                choosen = NULL; // m = 2 (enoncé Barabàsi-Albert)
                rander = rand() % 100 + 1; // rand a new number
                i=0;  //restart all over
                pivot = 1.f; //restart all over
            }
            else
                break;
        }
        else
        {
            pivot = pivot + this->vertices.at(i).at(0)->getProbability() * 100;
            i++;
        }
    }
    return choosen;
}
float Graph::returnProbability(int VertexId)
{
    float prob = (float)this->getDegree(VertexId) / (float)this->getSumOfDegrees();

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

        Vertex *currentNew = new Vertex(vertices.size() + 1); //Create the vertex
        newVertex.push_back(currentNew);                      // Set current vertex as main (index 0)
        newVertex.push_back(neighborVertex);                  //Set the new Vertex's neigbor
        this->vertices.push_back(newVertex);                  // Add a new Vertex to the Graph

        this->vertices.at(neighborVertex->getId() - 1).push_back(currentNew); // set the new Vertex as someone's neighbor
        this->updateSumOfDegrees();                                           //Update the Graph's maxSum
        this->updateAllProbabilities();

        //Recompute probalities of each of vertices we are working on
        this->vertices.at(neighborVertex->getId() - 1).at(0)->setProbability(this->returnProbability(neighborVertex->getId()));
        currentNew->setProbability(this->returnProbability(currentNew->getId()));

        this->vertices.at(neighborVertex->getId() - 1).at(0)->setMAxCountNewEdges(this->vertices.at(neighborVertex->getId() - 1).at(0)->getMAxCountNewEdges() + 1);
        currentNew->setMAxCountNewEdges(currentNew->getMAxCountNewEdges() + 1);

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
void Graph::updateSumOfDegrees()
{
    this->sumOfDegrees = 0;
    for (int i = 0; i < this->vertices.size(); i++)
    {
        this->sumOfDegrees += (this->getDegree(this->vertices.at(i).at(0)->getId()));
    }
}
void Graph::showAllProbabilities()
{
    cout << "--Displaying probabilities--" << endl;
    for (int i = 0; i < this->vertices.size(); i++)
    {
        cout << "Pr(" << this->vertices.at(i).at(0)->getId() << ") = " << this->vertices.at(i).at(0)->getProbability() << endl;
    }
}

void Graph::updateAllProbabilities()
{

    for (int i = 0; i < this->vertices.size(); i++)
    {
        this->vertices.at(i).at(0)->setProbability(this->returnProbability(this->vertices.at(i).at(0)->getId()));
    }
    cout << "--All Probabilities updated--" << endl;
}
vector<vector<Vertex *>> Graph::getVertices()
{
    return this->vertices;
}
int Graph::getSumOfDegrees()
{
    return this->sumOfDegrees;
}
void Graph::setSumOfDegrees(float newSum)
{
    this->sumOfDegrees = newSum;
}