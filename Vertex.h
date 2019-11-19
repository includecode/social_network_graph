#ifndef VERTEX_H
#define VERTEX_H
#include <iostream>

using namespace std;
class Vertex
{
private:
    int id;
    float probability;
    int countNewEdges; //Compteur de nouvelles arretes ajoutées au noeeud (MAX m =2)
    bool isChoosenInDegeneracy = false;

public:
    Vertex(int id);
    void setId(int id);
    void setProbability(float probability);
    int getId();
    float getProbability();
    int getMAxCountNewEdges();
    void setMAxCountNewEdges(int newCount);
    bool getIsChoosenInDegeneracy();
    void setIsChoosenInDegeneracy(bool val);
    
    ~Vertex();
};
#endif
