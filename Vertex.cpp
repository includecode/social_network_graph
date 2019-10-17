#include <iostream>
#include <ctime>
#include <random>
#include "Vertex.h"
using namespace std;

Vertex::Vertex(int id)
{
    this->id = id;
    this->countNewEdges = 0;
}
void Vertex::setId(int id)
{
    this->id = id;
}
void Vertex::setProbability(float probability)
{
    this->probability = probability;
}
int Vertex::getId()
{
    return this->id;
}
float Vertex::getProbability()
{
    return this->probability;
}
void Vertex::setMAxCountNewEdges(int newCount){
    this->countNewEdges = newCount;
}
int Vertex::getMAxCountNewEdges(){
    return this->countNewEdges;
}