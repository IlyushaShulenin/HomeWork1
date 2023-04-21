#include "MatrixGraph.h"

using std::make_pair;

MatrixGraph::MatrixGraph(int v_count)
{
    g.resize(v_count);
    for (int i = 0; i < v_count; ++i)
        g[i].resize(v_count);
    this->v_count = v_count;
}

MatrixGraph::~MatrixGraph() {
    clear();
}

void MatrixGraph::insert(int v, int w, int weight)
{
    if (v >= v_count || w >= v_count)
    {
        v_count = (v > w ? v : w) + 1;
        g.resize(v_count);
        for (int i = 0; i < v_count; ++i)
            g[i].resize(v_count);
    }
    g[v][w] = weight;
    g[w][v] = weight;
}

void MatrixGraph::remove(int v, int w) {
    if (v >= v_count || w >= v_count) {
        return;
    }
    g[v][w] = 0;
    g[w][v] = 0;
}

void MatrixGraph::clear() {
    for (int i = 0; i < v_count; i++) {
        g[i].clear();
    }
    g.clear();
    v_count = 0;
}

vector<pair<int, int>> MatrixGraph::adjacent_vertices(int v) {
    vector<pair<int, int>> vec;
    if (v >= v_count)
        return vec;

    for (int i = 0; i < v_count; ++i) {
        if (g[v][i] != 0) {
            vec.push_back(make_pair(i, g[v][i]));
        }
    }
    return vec;
}

int MatrixGraph::getSize() {
    return v_count;
}

int MatrixGraph::getWeight(int v, int w) {
    if (v < v_count && w < v_count)
        return g[v][w];

    return 0;
}




