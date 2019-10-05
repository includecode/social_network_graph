#include <iostream>

using namespace std;

class Graph
{
private:
    short int id;
    int degree;
    
public:
    Graph(short int id, int degree);
    void setId(short int id);
    short int getId();
    void showGraph();
    ~Graph();
};
