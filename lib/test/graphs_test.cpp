#include "graphs.h"

using namespace graph;

void countNodes(NodePtr node, void * i){
    int * n =(int*)i;
    *n++;
}

int main()
{
    NodePtr root(make_node(0));
    addEdge(root, make_node(1)); 
    NodePtr node_two = make_node(2);
    addEdge(root, node_two);
    addEdge(root->children[0], make_node(3));
    addEdge(root->children[0], make_node(4));
    addEdge(root->children[1], make_node(5));
    NodePtr node_six=make_node(6);
    addEdge(root->children[1], node_six);

    //make the graph circular 6-->2
    addEdge(node_six, node_two);

   //root.children.push_back()
    std::cout << "DFS: ";
    std::cout<< "\n";
    DFS(root, [](NodePtr node, void * userdata){ std::cout << node->id << " " ;}, nullptr);
    std::cout << "\n\n" ;
    std::cout << "BFS: ";
    std::cout << "\n";
    BFS(root, [](NodePtr node, void * userdata){ std::cout << node->id << " " ;}, nullptr);
    std::cout << "\n\n" ;

    int num_nodes = 0;
    int * n_ptr = &num_nodes;
    BFS(root, countNodes, (void*) n_ptr);
    std::cout << "there are " << *n_ptr << " nodes.\n";
    return 0;
}

