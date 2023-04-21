#pragma once

#include "Graph.h"


using std::vector;
using std::pair;

class MatrixGraph : public Graph {
private:
    int v_count;
    vector<vector<int>> g;

public:
    MatrixGraph(int v_count);
    ~MatrixGraph();

    void insert(int v, int w, int weight = 1);
    void remove(int v, int w);
    void clear();
    vector<pair<int, int>> adjacent_vertices(int v);
    int getSize();
    int getWeight(int v, int w);
};

