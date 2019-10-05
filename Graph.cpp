#include <iostream>
#include "Graph.h"

using namespace std;

Graph::Graph(short int id, int degree){
    this->id = id;
    this->degree = degree;
}

void Graph::showGraph(){
    cout <<"id ="<<this->id<<endl;
    cout <<"degree ="<<this->degree<<endl;
}

void Graph::setId(short int id){
    this->id = id;
}

short int Graph::getId(){
    return this->id;
}
