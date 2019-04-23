#pragma once
#include "CoordNode.h"


namespace pav {

	template <class T>
	class KDTree {
		//dimensions being used
		const int k = 3;

		//the main node of this tree
		CoordNode<T>* node;

		//the depth level, used for determining the dimension
		int depth;

		//the two branches of the tree
		KDTree<T>* leftBranch;
		KDTree<T>* rightBranch;

		//helper function for comparing if two nodes are at the same position
		bool ComparePosition(CoordNode<T>* node_);

	public:

		KDTree(CoordNode<T>* node_, int depth_);
		~KDTree();

		//fucntion to insert a node into the kdtree
		void InsertNode(CoordNode<T>* node_);
		//function to find out if there is a node at the same position as the node being passed in, and returns the node
		CoordNode<T>* FindN(CoordNode<T>* node_);
	};
#include "KDTree.cpp"
}

