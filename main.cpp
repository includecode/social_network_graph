#include <iostream>
#include <time.h>
#include "Graph.h"
#include "Vertex.h"
#include <vector>
<<<<<<< HEAD
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
=======

using namespace std;
int main(){
    srand(time(NULL));
    Graph *testG1 = new Graph(5);
    //Vertex *v4 = new Vertex(testG1->getVertices().size() + 1, testG1->returnRandomProbability(testG1->getVertices().size() + 1));
    //testG1->addVertex(testG1->getVertices().at(0).at(0));
    testG1->showGraph();
    cout <<testG1->getDegree(1)<<endl;
    cout << "---------------------"<<endl;
    testG1->addEdgesToGrpah(5, 0.4);
    testG1->showGraph();
    cout <<testG1->getDegree(1)<<endl;
    cout <<testG1->getDegree(4)<<endl;
    //cout << "La somme est: "<<testG1->getMAxProbSym()<<endl;
    //cout << "Next is : "<<testG1->chooseNextVertex()->getId()<<endl;
    vector<Vertex*> R,X={};
    vector<Vertex*> P;
    int i=0;
    //for(auto element : testG1->getVertices() )
    for(i;i<testG1->getVertices().size();i++ )
    {
        P.push_back(testG1->getVertices().at(i).at(0));
    }
    cout << "Maximal cliques :"<<endl;
    testG1->BronKerbosch(R,P,X);
>>>>>>> f6a639d4071c1adb913d3129655e71067e7551f7
    return 0;
}
