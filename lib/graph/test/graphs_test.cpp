#include "graphs.h"

using namespace graph;

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

    //test default callbacks (print nodes)
    std::cout << "DFS: ";
    std::cout<< "\n";

    DFS(root, [](NodePtr node){ std::cout << node->id << " " ;});
    std::cout << "\n\n" ;
    std::cout << "BFS: ";
    std::cout << "\n";
    BFS(root, [](NodePtr node){ std::cout << node->id << " " ;});
    std::cout << "\n\n" ;

    int count = 0;
    DFS(root, [&count](NodePtr node) mutable { ++count; });
    std::cout << "DFS count: there are " << count << " nodes.\n";
    
    count = 0;
    BFS(root, [&count](NodePtr node) mutable { ++count; });
    std::cout << "BFS count: there are " << count << " nodes.\n";
    return 0;
}

