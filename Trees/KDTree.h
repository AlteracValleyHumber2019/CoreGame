#pragma once
#include "QuadNode.h"


namespace pav {

	template <class T>
	class KDTree {
		//dimensions being used
		const int k = 3;

		//the main node of this tree
		QuadNode<T>* node;

		//the depth level, used for determining the dimension
		int depth;

		//the two branches of the tree
		KDTree<T>* leftBranch;
		KDTree<T>* rightBranch;

		//helper function for comparing if two nodes are at the same position
		bool ComparePosition(QuadNode<T>* node_);

	public:

		KDTree(QuadNode<T>* node_, int depth_);
		~KDTree();

		//fucntion to insert a node into the kdtree
		void InsertN(QuadNode<T>* node_);
		//function to find out if there is a node at the same position as the node being passed in, and returns the node
		QuadNode<T>* FindN(QuadNode<T>* node_);
	};
}

