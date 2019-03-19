#pragma once

template <class FT>
class QuadNode;

namespace pav {

	template <class T>
	class QuadTree {
		//TODO: rewrite the quad tree to handle a size if we decide to do so, as it is the quad tree will go
		//to a unit quad
		const int size = 5;

		//the boundaries for the quad tree
		std::vector<float> topLBound;
		std::vector<float> botRBound;

		//TODO rewrite the quad tree to store a list of nodes in order to have less recursion and more populated quads
		std::vector<QuadNode<T>*> nodes;

		//the main node of this tree
		QuadNode<T>* node;

		//the four quadrants of the tree
		QuadTree<T>* topLQuad;
		QuadTree<T>* topRQuad;
		QuadTree<T>* botLQuad;
		QuadTree<T>* botRQuad;

	public:
		QuadTree();
		QuadTree(std::vector<float> topLB_, std::vector<float> botRB_);

		//insert method for adding a node to the tree TODO: find out why the declaration is incompatible and not funcitoning
		void InsertNode(QuadNode<T>* qnode_);
		//Method to find and return a node in the tree at the given position
		QuadNode<T>* Find(std::vector<float> coord_);
		//TODO implement the find In radius function in order to return a vector of all nodes within a certain search radius
		std::vector<QuadNode<T>*> FindInRadius(std::vector<float> coord_, float radius);

		//helper function to determine if a coordinate is inboundaries of this tree, may have separate applications
		//outside of being a helper function, leaving it public for now
		bool inBound(std::vector<float> coord_);

	};

}