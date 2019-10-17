#include <iostream>
#include "Graph.h"
#include "Vertex.h"
#include <vector>
using namespace std;
int main()
{
    srand(time(0));

    /*
    //######## A L G O  1 ##*****************************
    cout << "######## A L G O  1 ##*****************************" << endl;
    cout << "How many  Vertices do you want for the graph ?";
    int nbreVertex;
    float prob;
    cin >> nbreVertex;
    cout << "What is the probability (between 0 and 1) ?";
    cin >> prob;
    Graph *testG1 = new Graph(nbreVertex);
    testG1->showGraph();
    cout << "---------------------" << endl;
    testG1->addEdgesToGrpah(nbreVertex, prob);
    testG1->showGraph();
    */
    //######## A L G O  2 ##*****************************
    cout << "######## A L G O  2 ##*****************************" << endl;

    Graph *testG2 = new Graph();
    cout << "----------INITIAL GRAPH-----------" << endl;
    testG2->showGraph();
    cout << "---------------------" << endl;
    cout << "How many  Vertices do you want to add to the previous 3 ?";
    int nbre;
    cin >> nbre;
    for (int i = 0; i < nbre; i++)
    {
        Vertex *choosen = testG2->chooseNextVertex();

        cout << "Next is on : " << choosen->getId() << endl;

        testG2->addVertex(choosen);

        testG2->showGraph();
        cout << "SUM of degrees is " << testG2->getSumOfDegrees() << endl;
        testG2->showAllProbabilities();
    }
    return 0;
}