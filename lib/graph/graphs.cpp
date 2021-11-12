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
        return result != node_vector.end();
    }

    void DFS(NodePtr &node, std::function<void(NodePtr)> callback){
        NodeVector visited;
        _DFS(node, callback, visited);
    }

    void _DFS(NodePtr &node, std::function<void(NodePtr)> callback, NodeVector& visited){
        if (!NodeIsInVector(node, visited)) {
            visited.push_back(node);
            callback(node);
        } else {
            for(auto item : visited){
                std::cout<<item->id << " ";
            }
            std::cout << "\n";
        }
        for (auto&& n : node->children){
            if (!NodeIsInVector(n, visited)){
                _DFS(n, callback, visited);
            }
        }
    }

    void BFS(NodePtr &node, std::function<void(NodePtr)> callback){
        NodeVector visited;
        std::list<NodePtr> to_visit;
        to_visit.push_back(node);
        while (!to_visit.empty())
        {
            NodePtr parent = to_visit.front();
            visited.push_back(parent);
            to_visit.pop_front();
            
            if (callback){
                callback(parent);
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


    NodePtr getNode(NodePtr parent,  NodePosition position){
        for( NodePtr child : parent->children ) {
            if (child-> position == position){
                return child;
            }
        }
        return nullptr;
    }

    NodePtr getNode(NodePtr parent,  std::vector<NodePosition> positions){
        NodePtr result = parent; 
        for (NodePosition position  : positions){
            result = getNode(result, position);
        }
        return result;
    }

    void addEdge(NodePtr parent, NodePtr new_node, NodePosition position){
        new_node->position = position;
        new_node->parent = parent;

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

    bool isBST(NodePtr root, int _min, int _max, bool _is_bst){  //optimized version of isBST()
        if (!root || !_is_bst){
            return _is_bst; 
        }

        int id = root -> id;
        if (id < _min || id > _max){
            _is_bst = false;
        }

        _is_bst = isBST(getNode(root, LEFT), INT_MIN, root->id, _is_bst);
        _is_bst = isBST(getNode(root, RIGHT), root->id, INT_MAX, _is_bst);

        return _is_bst;
    }


} //namespace graph
