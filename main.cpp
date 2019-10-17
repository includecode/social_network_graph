#include <iostream>
#include <time.h>
#include "Graph.h"
#include "Vertex.h"
#include <vector>

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
    return 0;
}
