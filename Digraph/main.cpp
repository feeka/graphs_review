// test digraph class
// ------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

#include "API/digraph.h"
#include "API/dfs.h"
#include "API/graphvizGen.h"

int main(int argc, char *argv[]) {
    // create a graph from a file

    Digraph G(10);
    G.addEdge(0, 1);
    G.addEdge(0, 2);
    G.addEdge(0, 5);
    G.addEdge(1, 2);
    G.addEdge(2, 3);
    G.addEdge(2, 4);
    G.addEdge(3, 4);
    G.addEdge(3, 5);
    G.addEdge(3, 6);
    G.addEdge(4, 6);
    G.addEdge(5, 4);
    G.addEdge(5, 6);
    G.addEdge(7, 8);
    G.addEdge(9, 8);
    G.addEdge(9, 7);
    G.addEdge(6,0);
    // print out the graph
    cout << G.toString() << endl;
    // reverse the graph
    Digraph R = G.reverse();
    cout << R.toString() << endl;
    cout<<"DFS of G"<<endl;
    for (int v = 0; v < G.getV(); v++) {
        DFS dfs(G, v);
        dfs.printTrail(G);
    }
    cout<<""<<endl;
    cout<<"DFS of R"<<endl;
    for (int v = 0; v < R.getV(); v++) {
        DFS dfsR(R, v);
        dfsR.printTrail(R);
    }

    GraphvizGen graphvizGen(G,"G");
    GraphvizGen graphvizGenR(R,"R");

    return 0;
}