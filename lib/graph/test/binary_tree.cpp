#include "graphs.h"

using namespace graph;
int main(){

	NodePtr root = make_node(0); 
	addEdge(root, make_node(1), LEFT);
	addEdge(root, make_node(2), RIGHT);

	addEdge(getNode(root, LEFT),make_node(3),LEFT);
	addEdge(getNode(root, LEFT), make_node(4), RIGHT);

	addEdge(getNode(root, RIGHT),make_node(5),LEFT);
	addEdge(getNode(root, RIGHT), make_node(6), RIGHT);

	DFS(root, [](NodePtr node){ std::cout << node->id << " " }, nullptr);
	std::cout << "\n";
	return 0;
}
