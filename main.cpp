#include <iostream>
#include <time.h>
#include "Graph.h"
#include "Vertex.h"
#include <vector>
using namespace std;
int main(int argc, char *argv[])
{

    if (argc > 3)
    {
        cout << "---------CLIQUES MAXIMALES------" << endl;
        cout << " Pour utiliser ce programme, veuillez suivre la syntaxe." << endl;
        cout << "\tTaper:    ./app 10  0.4      (par exmple pour créer 10 sommets avec une probabilité 0.4 d'avoir une arête (ALGO 1)" << endl;
        cout << "\tTaper:    ./app 15      (par exmple pour ajouter 15 sommets aux 3 premiers sommets de Barabasi Albert (ALGO 2)" << endl;
        cout << "\tTaper:    ./app       (Pour enumérer les cliques et afficher l'ordre de dégénérescence)" << endl;

        cout << "------FIN DU PROGRAMME-----" << endl;
        cout << "Par: Pavel SAMENE TIAH, Rida LAKSIR, Meriem HAMMAR (c) Novembre 2019" << endl;
        cout << "<ISTY 2019, IATIC 4>" << endl;
    }
    else
    {
        srand(time(0));
        if (argc == 3)
        {
            int nbreVertex;
            nbreVertex = atoi(argv[1]);
            float prob;
            prob = atof(argv[2]);
            //######## A L G O  1 ##*****************************
            cout << "######## A L G O  1 ##*****************************" << endl;
            //cout << "How many  Vertices do you want for the graph ?";
            cout << " Creation de " << nbreVertex << " Sommets" << endl;

            //cin >> nbreVertex;
            //cout << "What is the probability (between 0 and 1) ?";
            //cin >> prob;
            cout << "Avec la probabilité: ( " << prob << " )" << endl;
            getchar();
            Graph *testG1 = new Graph(nbreVertex);
            testG1->showGraph();
            cout << "---------------------" << endl;
            testG1->addEdgesToGrpah(nbreVertex, prob);
            testG1->showGraph();
        }
        
        if (argc == 2)
        {
            //######## A L G O  2 ##*****************************
            cout << "######## A L G O  2 ##*****************************" << endl;

            Graph *testG2 = new Graph();
            cout << "----------INITIAL GRAPH-----------" << endl;
            testG2->showGraph();
            cout << "---------------------" << endl;

            int nbre;
            nbre = atoi(argv[1]);
            //cin >> nbre;
            cout << "Ajout de ( " << nbre << " ) sommets aux 3 sommets initiaux, appuyer entrer pour valider ";
            getchar();
            
            for (int i = 0; i < nbre; i++)
            {
                Vertex *choosen = testG2->chooseNextVertex();

                cout << "Next is on : " << choosen->getId() << endl;

                testG2->addVertex(choosen);

                testG2->showGraph();
                cout << "SUM of degrees is " << testG2->getSumOfDegrees() << endl;
                testG2->showAllProbabilities();
                
            }
        }
        
        if (argc < 2)
        {
            Graph *testBr = new Graph();
            vector<Vertex> *P = new vector<Vertex>;
            for (int i = 0; i < testBr->getVertices().size(); i++)
            {
                P->push_back(*testBr->getVertices().at(i).at(0));
            }
            vector<Vertex> *R = new vector<Vertex>;
            vector<Vertex> *X = new vector<Vertex>;
            testBr->bronKerboschStandard(R, P, X, 0, P->size());
            cout << "clics are \t";
            for (int i = 0; i < X->size(); i++)
            {
                cout << X->at(i).getId() <<"\t";
            }
            cout<<"\n-----------------------------######---------------------------------"<<endl;
            cout <<"\nAppuyer sur entrée pour exécuter l'ordre de degenerescence de ce graphe"<<endl;
            cout<<"\n-----------------------------######---------------------------------"<<endl;
            getchar();
            Graph *testDegOrder = new Graph();
            testDegOrder->addVertex(testDegOrder->getVertices().at(1).at(0));
            testDegOrder->addVertex(testDegOrder->getVertices().at(3).at(0));
            /*vector<Vertex> *A = new vector<Vertex>;
            for (int i = 0; i < testDegOrder->getVertices().size(); i++)
            {
                P->push_back(*testDegOrder->getVertices().at(i).at(0));
            }*/
            testDegOrder->showGraph();
            vector<Vertex> a = testDegOrder->returnDegeneracyOrder();
            for (int i = 0; i < a.size(); i++)
            {
                cout << "DEGENERESCENCE ORDER " << a.at(i).getId() << endl;
            }
            testDegOrder->showGraph();
        }
    }
    return 0;
}
