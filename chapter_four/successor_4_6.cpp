#include <graphs.h>
#include <stdexcept>

using namespace graph;
// find the successor of a node
NodePtr Successor(NodePtr node, NodePtr root){
	if (!isBST(root)){
		throw std::runtime_error("The graph is not a binary search tree");
	}

	// if there is a right subtree, go down to leftmost node and return it.
	if (NodePtr right_subtree = getNode(node, RIGHT) ){
		NodePtr sucessor=right_subtree;
		while (NodePtr left_node = getNode(sucessor, LEFT)){
			sucessor = left_node;
		}
		return sucessor ;
	}

	// if there is no right subtree, return first parent which is > node
	else{
		int val = node->id;
		NodePtr sucessor = node->parent;

		while( sucessor && (sucessor->id < val)){
			sucessor = sucessor->parent;  //go up ancestry to first unvisited parent
		}
		return sucessor;
	}

	// if all fails
	return nullptr;
}

// driver code
int main(){

/*
* this binary tree:
*
*	      15
*	     /  \
*	    /    \
*	   10     20
*	  / \    / \ 
*	 8   12 17 25
*   /   /   /   \
*  6   11  16   27	          
*/
	NodePtr binary_tree = make_node(15);

	// left subtree (starting with 10)
	addEdge(binary_tree, make_node(10), LEFT);
	addEdge(getNode(binary_tree, LEFT), make_node(8), LEFT);
	addEdge(getNode(binary_tree, LEFT), make_node(12), RIGHT);
	addEdge(getNode(binary_tree, {LEFT,LEFT}), make_node(6), LEFT);
	addEdge(getNode(binary_tree, {LEFT,RIGHT}), make_node(11), LEFT);

	// right subtree (starting with 20)
	addEdge(binary_tree, make_node(20), RIGHT);
	addEdge(getNode(binary_tree, RIGHT), make_node(17), LEFT);
	addEdge(getNode(binary_tree, RIGHT), make_node(25), RIGHT);
	addEdge(getNode(binary_tree, {RIGHT, LEFT}), make_node(16), LEFT);
	addEdge(getNode(binary_tree, {RIGHT, RIGHT}), make_node(27), RIGHT);

	NodePtr successor;
	successor = Successor(binary_tree, binary_tree);  //node "15" : root
	std::cout << "The sucessor was: " << successor->id << "\n";
	std::cout << "The expected sucessor is: 16" << "\n";

	successor = Successor(getNode(binary_tree, {LEFT,LEFT}), binary_tree);  //node "8"
	std::cout << "The sucessor was: " << successor->id << "\n";
	std::cout << "The expected sucessor is: 10" << "\n";

	successor = Successor(getNode(binary_tree, {LEFT,RIGHT}), binary_tree);  //node "12"
	std::cout << "The sucessor was: " << successor->id << "\n";
	std::cout << "The expected sucessor is: 15" << "\n";
	return 0;
}
