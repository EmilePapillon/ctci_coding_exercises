#include <stdint.h>
#include <iostream>
#include <vector>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/breadth_first_search.hpp>

int main() {
  typedef boost::adjacency_list<boost::vecS, boost::hash_setS, boost::undirectedS, uint32_t, uint32_t, boost::no_property> graph_t;
  graph_t graph(4);
  graph_t::vertex_descriptor a = boost::vertex(0, graph);
  graph_t::vertex_descriptor b = boost::vertex(1, graph);
  graph_t::vertex_descriptor c = boost::vertex(2, graph);
  graph_t::vertex_descriptor d = boost::vertex(3, graph);
  graph[a] = 0;
  graph[b] = 1;
  graph[c] = 2;
  graph[d] = 3;
  std::pair<graph_t::edge_descriptor, bool> result = boost::add_edge(a, b, 0, graph);
  result = boost::add_edge(a, c, 1, graph);
  result = boost::add_edge(c, b, 2, graph);
  class {
  public:
    void initialize_vertex(const graph_t::vertex_descriptor &s, graph_t &g) {
      std::cout << "Initialize: " << g[s] << std::endl;
    }
    void discover_vertex(const graph_t::vertex_descriptor &s, graph_t &g) {
      std::cout << "Discover: " << g[s] << std::endl;
    }
    void examine_vertex(const graph_t::vertex_descriptor &s, graph_t &g) {
      std::cout << "Examine vertex: " << g[s] << std::endl;
    }
    void examine_edge(const graph_t::edge_descriptor &e, graph_t &g) {
      std::cout << "Examine edge: " << g[e] << std::endl;
    }
    void tree_edge(const graph_t::edge_descriptor &e, graph_t &g) {
      std::cout << "Tree edge: " << g[e] << std::endl;
    }
    void non_tree_edge(const graph_t::edge_descriptor &e, graph_t &g) {
      std::cout << "Non-Tree edge: " << g[e] << std::endl;
    }
    void gray_target(const graph_t::edge_descriptor &e, graph_t &g) {
      std::cout << "Gray target: " << g[e] << std::endl;
    }
    void black_target(const graph_t::edge_descriptor &e, graph_t &g) {
      std::cout << "Black target: " << g[e] << std::endl;
    }
    void finish_vertex(const graph_t::vertex_descriptor &s, graph_t &g) {
      std::cout << "Finish vertex: " << g[s] << std::endl;
    }
  } bfs_visitor;
  boost::breadth_first_search(graph, a, bfs_visitor);
  return 0;
}
