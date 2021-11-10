/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include "graphs.h"

namespace graph {

    bool NodeIsInVector(NodePtr node, NodeVector node_vector){
        auto result = std::find(node_vector.begin(), node_vector.end(), node);
        while (result != node_vector.end()) {
            if (*result == node){ 
                return true;
            }
            result = std::find(result, node_vector.end(), node);
        }
        return false;
    }

    // will it handle a circular graph?
    void DFS(NodePtr &node, void (*callback)(NodePtr, void * userdata), void * userdata){
        static NodeVector visited;
        if (!NodeIsInVector(node, visited)) {
            visited.push_back(node);
            if (callback){
                callback(node, userdata);
            }
        }
        if (node->children.empty()) return; 
        for (auto&& n : node->children){
            if (!NodeIsInVector(n, visited)){
                DFS(n, callback, userdata);
            }
        }
    }

    // I think this will work with circular graphs.
    void BFS(NodePtr &node, void (*callback)(NodePtr, void * userdata), void * userdata){
        NodeVector visited;
        std::list<NodePtr> to_visit;
        to_visit.push_back(node);
        while (!to_visit.empty())
        {
            NodePtr parent = to_visit.front();
            visited.push_back(parent);
            to_visit.pop_front();
            
            if (callback){
                callback(parent, userdata);
            }
            for (NodePtr n : parent->children){
                if (!NodeIsInVector(n, visited)){
                    to_visit.push_back(n);
                }
            }
        }
    }

    NodePtr make_node(int id){
        NodePtr node(new Node);
        node->id=id;
        return node;
    }

    // checks if tree is a binary search tree
    bool isBST(NodePtr root){
        return true;
    }

    NodePtr getNode(NodePtr parent,  NodePosition position){
        for( NodePtr child : parent->children ) {
            if (child-> position == position){
                return child;
            }
        }
        return nullptr;
    }

    void addEdge(NodePtr parent, NodePtr new_node, NodePosition position){
        new_node->position=position;

        // if not a binary tree, simply add node
        if (position == NONE){
            parent->children.push_back(new_node);
            return;
        }

        // it is a binary tree (a position is defined), either replace node at position
        // or append a new node if there isn't a node in place.
        if (NodePtr node = getNode(parent, position)){
            node = new_node;  // replace the node at the position
        } else {
            parent->children.push_back(new_node); 
        }
    }

} //namespace graph
