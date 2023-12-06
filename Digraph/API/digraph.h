#ifndef DIGRAPH_H
#define DIGRAPH_H

#include <vector>
#include <string>
using namespace std;

// Digraph class represents a directed graph of vertices named 0 through V - 1.
// It supports the following operations: add an edge to the graph, iterate over all of the vertices adjacent to a vertex.
// Parallel edges and self-loops are permitted.
class Digraph
{
    private:
        int V;
        int E;
        // create array of vectors
        vector<int> *adj;    
    public:
        Digraph(int V);
        ~Digraph();
        int getV() ;
        int getE() ;
        void addEdge(int v, int w);
        vector<int> getAdj(int v);
        Digraph reverse();
        string toString();
         
};

// constructor(number of vertices V)
Digraph::Digraph(int V) : V(V), E(0), adj(new vector<int>[V]) {
    for (int i = 0; i < V; i++)
        adj[i] = vector<int>();
}

Digraph::~Digraph() {}

int Digraph::getV() {
    return V;
}

int Digraph::getE() {
    return E;
}

// add a directed edge v->w
void Digraph::addEdge(int v, int w) {
    adj[v].push_back(w);
    E++;
}

// return list of vertices adjacent to v
vector<int> Digraph::getAdj(int v) {
    return adj[v];
}

// create a reverse of this digraph
Digraph Digraph::reverse() {
    Digraph R(V);
    for (int v = 0; v < V; v++)
        for (int w : getAdj(v))
            R.addEdge(w, v);
    return R;
}

// string representation of the digraph
string Digraph::toString() {
    string s = to_string(V) + " vertices, " + to_string(E) + " edges\n";
    for (int v = 0; v < V; v++) {
        s += to_string(v) + ": ";
        for (int w : getAdj(v))
            s += to_string(w) + " ";
        s += "\n";
    }
    return s;
}

#endif