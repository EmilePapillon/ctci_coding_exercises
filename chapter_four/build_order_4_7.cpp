#include <graphs.h>

using namespace graph;

typedef std::pair<NodePtr, NodePtr> dependency_t; 
typedef std::vector<dependency_t> dependency_list_t;
NodeVector BuildOrder(NodeVector projects, dependency_list_t dependencies){
	std::vector<std::string> translation{"a", "b", "c", "d", "e", "f"};
	if (projects.empty() || dependencies.empty()) return projects; 

	NodeVector build_order; 

	// build a graph of dependencies: parent --depends-on--> child
	for(dependency_t dep : dependencies){
		addEdge(dep.second, dep.first);
	}

	for (NodePtr project : projects){
		std::cout << "Analysing project " << translation[project->id] << "\n";
		// if the project has no parent, do a DFS from it and add any nodes not already there to the BO.
		if (!project->parent){
			std::cout << "Project " << translation[project->id] << " has no parent. Performing DFS\n";
			DFS<NodeVector*>(project, [translation](NodePtr node, NodeVector *bo){
				std::cout << "DFS visiting node " << translation[node->id] << "\n";
				if (!NodeIsInVector(node, *bo)){
					bo->push_back(node);
				}
			}, &build_order);
		}
	}
	return build_order;
}

// driver code
int main(){

	// translating letters to number because nodes have to have an integer id.
	std::vector<std::string> translation{"a", "b", "c", "d", "e", "f"};
	NodePtr a=make_node(0);
	NodePtr b=make_node(1);
	NodePtr c=make_node(2);
	NodePtr d=make_node(3);
	NodePtr e=make_node(4);
	NodePtr f=make_node(5);
	
	NodeVector projects{a,b,c,d,e,f};
	dependency_list_t deps{{a,d},{f,b},{b,d},{f,a},{d,c}};

	NodeVector build_order = BuildOrder(projects, deps);

	std::cout << "The build order is:\n";
	for (NodePtr project : build_order){
		std::cout << translation[project->id] << ", "; 
	}
	std::cout << "\b\b" << "  \n";

	return 0;
}
