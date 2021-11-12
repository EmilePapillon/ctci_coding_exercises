cc_library(
	name="trees",
	srcs=["trees.h"],
	hdrs=["trees.h"],
	includes=["."],
	deps=["//lib/graph:graphs"],
)

# 4.5 Validate BST: Implement a function to check if a binary tree is a binary search tree
cc_binary(
	name="validate_bst_4_5",
	srcs=["validate_bst_4_5.cpp"],
	deps=["//lib/graph:graphs"],
)

# 4.6 successor: find the in-order successor of a node
cc_binary(
	name="successor_4_6",
	srcs =["successor_4_6.cpp"],
	deps=["//lib/graph:graphs"]
)

# 4.7 build order: given a set of project and their interdependency, find the build order
cc_binary(
	name="build_order_4_7",
	srcs =["build_order_4_7.cpp"],
	deps=["//lib/graph:graphs"]
)

# 4.8 first common ancestor: find the common ancestor between two nodes in a binary tree
cc_binary(
	name="first_common_ancestor_4_8",
	srcs =["first_common_ancestor_4_8.cpp"],
	deps=["//lib/graph:graphs",":trees"]
)
