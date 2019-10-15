#include <iostream>
#include <ctime>
#include <random>
#include "Vertex.h"
using namespace std;
Vertex::Vertex(int id, float probability)
{
    this->id = id;
    this->probability = probability;
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