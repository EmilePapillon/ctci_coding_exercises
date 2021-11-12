#include <iostream>
#include <graphs.h>
#include <climits>

using namespace graph; 

void echo(std::string string){
	std::cout << string << '\n';
}

int TreeMax(NodePtr root, int max = INT_MIN){
	NodeVector visited; 

	if (!NodeIsInVector(root, visited)) {
		visited.push_back(root);
		if (root->id > max){
			max=root->id;
		} 
		if (root->children.empty()) return max;
		for (auto&& n : root->children){
			max = TreeMax(n, max);
		}
	}
	//std::cout << "\n";
	return max;
}

int TreeMin(NodePtr root, int min = INT_MAX){
	NodeVector visited; 

	if (!NodeIsInVector(root, visited)) {
		visited.push_back(root);
		if (root->id < min){
			min=root->id;
		} 
		if (root->children.empty()) return min;
		for (auto&& n : root->children){
			min = TreeMin(n, min);
		}
	}
	return min;
}

bool badIsBST(NodePtr root, bool is_bst = true) {
	NodeVector visited; 

	if (!NodeIsInVector(root, visited)) {
		
		if (!root || root->children.empty()){
			return is_bst;
		} 

		visited.push_back(root); 

		NodePtr left = getNode(root, LEFT);
		NodePtr right = getNode(root, RIGHT);

		if (root->id > TreeMax(right) || root->id < TreeMin(left)){
			return false;
		} 
		 
		for (auto&& n : root->children){
			is_bst = isBST(n, is_bst);
		}
	}
	return is_bst;
}

bool checkBST(NodePtr root, int min=INT_MIN, int max=INT_MAX, bool is_bst=true){  //optimized version of isBST()
	if (!root || !is_bst){
		return is_bst; 
	}

	int id = root -> id;
	if (id < min || id > max){
		is_bst = false;
	}

	is_bst = checkBST(getNode(root, LEFT), INT_MIN, root->id, is_bst);
	is_bst = checkBST(getNode(root, RIGHT), root->id, INT_MAX, is_bst);

	return is_bst;
}

// Driver code 
void echo_binary_result(NodePtr root){
	echo("Testing if BST");
	if (badIsBST(root)) {
		std::cout << "it is a binary search tree\n";
	} else {
		std::cout << "it is NOT a binary search tree\n";
	}

	echo("Testing if BST (optimzed)");
	if (checkBST(root)) {
		std::cout << "it is a binary search tree\n";
	} else {
		std::cout << "it is NOT a binary search tree\n";
	}
}


int main(){

	// a binary search tree
	NodePtr binary_tree = make_node(5);
	addEdge(binary_tree, make_node(3), LEFT);
	addEdge(binary_tree, make_node(7), RIGHT);
	addEdge(getNode(binary_tree,LEFT), make_node(2), LEFT);
	addEdge(getNode(binary_tree,LEFT), make_node(4), RIGHT);
	addEdge(getNode(binary_tree,RIGHT), make_node(6), LEFT);
	addEdge(getNode(binary_tree,RIGHT), make_node(8), RIGHT);

	// not a binary search tree
	NodePtr nonbinary_tree = make_node(5);
	addEdge(nonbinary_tree, make_node(4), LEFT);
	addEdge(nonbinary_tree, make_node(7), RIGHT);
	addEdge(getNode(nonbinary_tree,LEFT), make_node(2), LEFT);
	addEdge(getNode(nonbinary_tree,LEFT), make_node(3), RIGHT);
	addEdge(getNode(nonbinary_tree,RIGHT), make_node(6), LEFT);
	addEdge(getNode(nonbinary_tree,RIGHT), make_node(8), RIGHT);

	int max = TreeMax(binary_tree);
	std::cout << "\n";
	std::cout << "Max is: " << max << "\n";

	int min = TreeMin(binary_tree);
	std::cout << "\n";
	std::cout << "Min is: " << min << "\n";
	std::cout << "\n";

	// test for binary tree
	echo_binary_result(binary_tree);
	echo_binary_result(nonbinary_tree);

}
