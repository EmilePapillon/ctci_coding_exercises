#ifndef TREES_H
#define TREES_H

#include <graphs.h>

using namespace graph;
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
NodePtr BST_ONE = make_node(15);

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

#endif
