#ifndef VERTEX_H
#define VERTEX_H
#include <iostream>

using namespace std;
class Vertex
{
private:
    int id;
    float probability;
public:
    Vertex(int id, float probability);
    void setId(int id);
    void setProbability(float probability);
    int getId();
    float getProbability();
    ~Vertex();
};
#endif
