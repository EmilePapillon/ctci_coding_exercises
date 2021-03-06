#ifndef GRAPHS_H
#define GRAPHS_H

#include <climits>
#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include <algorithm>
#include <functional>
namespace graph {

    typedef std::shared_ptr<struct Node> NodePtr;
    typedef std::vector<NodePtr> NodeVector;

    struct Node {
        int id{0};
        bool visited{false};
        NodeVector children;
        NodePtr parent;
        int position{0}; //position relative to parent 1 = left, 2 = right (0 is for non binary graphs)
    };

    enum NodePosition{
        NONE = 0, // for non-binary trees
        LEFT = 1,
        RIGHT = 2
    };

    bool NodeIsInVector(NodePtr node, NodeVector node_vector);

    void DFS(NodePtr &node, std::function<void(NodePtr)> callback);

    void _DFS(NodePtr &node, std::function<void(NodePtr)> callback, NodeVector& visited);

    void BFS(NodePtr &node, std::function<void(NodePtr)> callback);   

    NodePtr make_node(int id);

    /*!
     * \brief returns node to the position relative to parent
     */
    NodePtr getNode(NodePtr parent, NodePosition position);

    /*!
     * \brief follows nodes from parent according to positions list of positions and returns last
     */
    NodePtr getNode(NodePtr parent, std::vector<NodePosition> positions);

    void addEdge(NodePtr parent, NodePtr new_node, NodePosition position=NONE);

    /*!
     * \brief Check weather a graph is a binary search tree
     * \param root: root of the tree
     * \_min: used internally 
     * \_max: used internally
     * \_is_bst: used internally
     */ 
    bool isBST(NodePtr root, int _min=INT_MIN, int _max=INT_MAX, bool _is_bst=true);

} //namespace graph


#endif
