// include Digraph class

#include "digraph.h"
#include <fstream>

class GraphvizGen{
    private:
        void generateGraphviz(Digraph G, string name);
    public:
        GraphvizGen(Digraph G, string name);
        ~GraphvizGen();
};

GraphvizGen::GraphvizGen(Digraph G, string name){
    generateGraphviz(G, name);
}

GraphvizGen::~GraphvizGen(){}



void GraphvizGen::generateGraphviz(Digraph G, string name)
{
    std::ofstream myfile;
    myfile.open(name + ".dot");
    myfile << "digraph G {\n";
    for (int v = 0; v < G.getV(); v++) {
        for (int w : G.getAdj(v)) {
            myfile << v << " -> " << w << ";\n";
        }
    }
    myfile << "}\n";
    myfile.close();
}
