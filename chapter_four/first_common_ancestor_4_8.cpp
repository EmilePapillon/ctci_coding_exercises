#include <graphs.h>
//#include <trees.h>

using namespace graph;

// treets a node as a linked list, goes up to root and counts hops then returns it with the root
std::pair<int, NodePtr> GetLengthAndRoot(NodePtr node){
	if (!node){
		return std::make_pair(0, nullptr);
	}
	NodePtr root = node;
	NodePtr result;
	int size=0; 
	while(root = root->parent){
		result = root;
		size++;
	}
	return std::make_pair(size, result);
}

// returns the common ancestor node
// this version assumes that each node has a link to its parent
NodePtr FirstCommonAncestor(NodePtr first_subtree, NodePtr second_subtree){
	if  (!first_subtree || !second_subtree) {
		return nullptr;
	}

	std::pair<int, NodePtr> first = GetLengthAndRoot(first_subtree);
	std::pair<int, NodePtr> second = GetLengthAndRoot(second_subtree);

	if (first.second != second.second){
		return nullptr; // no common ancestor if they dont share the same root
	}

	NodePtr longest = first.first >= second.first ? first_subtree : second_subtree;
	NodePtr shortest = first.first < second.first ? first_subtree : second_subtree;

	//truncate the longest to the length of the shortest
	for (int i = 0; i < std::abs(first.first-second.first); i++){
		longest = longest->parent;
	}

	//find common ancestor iteratively
	for(int i = 0; i < std::min(first.first, second.first); i++){
		if (longest == shortest){
			return longest;
		}
		longest = longest->parent;
		shortest = shortest->parent;
	}
	return nullptr; //if we've reached here, we did a bad job at preliminary checks
}

//Driver code
int main(){

	std::cout << "Running first_common_ancestor_4_8.cpp\n";

	NodePtr BST_ONE = make_node(15);

	// TODO: import BST_ONE from a header file...
	// left subtree (starting with 10)
	addEdge(BST_ONE, make_node(10), LEFT);
	addEdge(getNode(BST_ONE, LEFT), make_node(8), LEFT);
	addEdge(getNode(BST_ONE, LEFT), make_node(12), RIGHT);
	addEdge(getNode(BST_ONE, {LEFT,LEFT}), make_node(6), LEFT);
	addEdge(getNode(BST_ONE, {LEFT,RIGHT}), make_node(11), LEFT);

	// right subtree (starting with 20)
	addEdge(BST_ONE, make_node(20), RIGHT);
	addEdge(getNode(BST_ONE, RIGHT), make_node(17), LEFT);
	addEdge(getNode(BST_ONE, RIGHT), make_node(25), RIGHT);
	addEdge(getNode(BST_ONE, {RIGHT, LEFT}), make_node(16), LEFT);
	addEdge(getNode(BST_ONE, {RIGHT, RIGHT}), make_node(27), RIGHT);

	NodePtr subtree_one = getNode(BST_ONE, {RIGHT,LEFT,LEFT});
	if(!subtree_one) {
		std::cout << "First subtree invalid\n";
		return 1;
	}
	NodePtr subtree_two = getNode(BST_ONE, {RIGHT,RIGHT,RIGHT});
	if(!subtree_two) {
		std::cout << "Second subtree invalid\n";
		return 1;
	}
	NodePtr common_ancestor = FirstCommonAncestor(subtree_one, subtree_two);
	if(common_ancestor){
		std::cout << "the common ancestor is: " << common_ancestor->id <<"\n";
	} else {
		std::cout << "could not find a common ancestor.\n";
	}
	return 0;
}
