// include Digraph class
#include "digraph.h"
#include <stack>
#include <set>
class DFS{
    private:
        bool *marked;
        void applyDFS(Digraph G, int v);
        vector<int> result;
    public:
        DFS(Digraph G, int s);
        ~DFS();
        bool *getMarked() { return marked; }
        void printTrail(Digraph G);
        
};

DFS::DFS(Digraph G, int s){
    marked = new bool[G.getV()];
    for (int i = 0; i < G.getV(); i++)
        marked[i] = false;
    applyDFS(G, s);    
}

DFS::~DFS() { }

void DFS::applyDFS(Digraph G, int v){
    marked[v] = true;
    result.push_back(v);
    for (int w : G.getAdj(v))

        if (!marked[w])
            applyDFS(G, w);
}

/*
// use above method and make iterative version
void DFS::applyDFS(Digraph G, int s){

    // create a stack  
    stack<int> iterativeStack;
    // push the source vertex
    iterativeStack.push(s);
    int depth=4;
    // while the stack is not empty
    while (!iterativeStack.empty()) {
        // pop the top vertex
        int v = iterativeStack.top();
        iterativeStack.pop();
        
        // if the vertex is not marked
        if (!marked[v]) {
            // mark it
            marked[v] = true;
            result.push_back(v);
            // push all its adjacent vertices
            for (int w : G.getAdj(v)){
                // if the adjacent vertex is not marked
                if (!marked[w]){
                    // push it
                    iterativeStack.push(w);
                    depth--;
                }
                if (w==s)
                    cout << "cycle detected at node "<<w << endl;   
            }
        if (depth==0)
            break;
        
        }
    }
}
*/
void DFS::printTrail(Digraph G){
    for (int v : result)
        cout << v << " ";
    cout << endl;
}
