/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include <algorithm>
namespace graph {

    typedef std::shared_ptr<struct Node> NodePtr;
    typedef std::vector<NodePtr> NodeVector;

    struct Node {
        int id{0};
        bool visited{false};
        NodeVector children;
        int position{0}; //position relative to parent 1 = left, 2 = right (0 is for non binary graphs)
    };

    enum NodePosition{
        NONE = 0, // for non-binary trees
        LEFT = 1,
        RIGHT = 2
    };

    bool NodeIsInVector(NodePtr node, NodeVector node_vector);

    void DFS(NodePtr &node, void (*callback)(NodePtr, void * userdata)=nullptr, void * userdata=nullptr);

    void BFS(NodePtr &node, void (*callback)(NodePtr, void * userdata)=nullptr, void * userdata=nullptr);

    NodePtr make_node(int id);

    NodePtr getNode(NodePtr parent, NodePosition position);

    void addEdge(NodePtr parent, NodePtr new_node, NodePosition position=NONE);
} //namespace graph
