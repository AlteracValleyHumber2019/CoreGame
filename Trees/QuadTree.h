#pragma once
#include <vector>
#include <iostream>


template <class FT>
class CoordNode;
using namespace std;
namespace pav {

	template <class T>
	class QuadTree {
		//TODO: rewrite the quad tree to handle a size if we decide to do so, as it is the quad tree will go
		//to a unit quad
		const int size = 10;
		bool divided = false;

		//the boundaries for the quad tree
		vector<float> topLBound;
		vector<float> botRBound;

		//TODO rewrite the quad tree to store a list of nodes in order to have less recursion and more populated quads
		vector<CoordNode<T>*> nodes;

		//the main node of this tree
		CoordNode<T>* node;

		//the four quadrants of the tree
		QuadTree<T>* topLQuad;
		QuadTree<T>* topRQuad;
		QuadTree<T>* botLQuad;
		QuadTree<T>* botRQuad;

	public:
		QuadTree();
		QuadTree(vector<float> topLB_, vector<float> botRB_);		
		//Method to find and return a node in the tree at the given position
		CoordNode<T>* Find(std::vector<float> coord_);
		//TODO implement the find In radius function in order to return a vector of all nodes within a certain search radius
		std::vector<CoordNode<T>*> FindInRadius(std::vector<float> coord_, float radius);

		//helper function to determine if a coordinate is inboundaries of this tree, may have separate applications
		//outside of being a helper function, leaving it public for now
		bool inBound(std::vector<float> coord_);

		//helper function to divide a tree when it is necessary to do so, leaving it public for now
		void Divide();

		//insert method for adding a node to the tree there was an issue where i could not get the cpp to properly identify the declaration for this method
		//therefore i moved the logic into the header file as that did not cause any errors.
		void InsertNode(CoordNode<T>* qnode_) {

			//check if a valid node is being passed
			if (qnode_ == NULL) {
				return;
			}

			//check to make sure if the node is within the bounds of this quadrant
			if (!inBound(qnode_->coordinate)) {
				return;
			}

			if (divided) {
				topLQuad->InsertNode(qnode_);
				topRQuad->InsertNode(qnode_);
				botLQuad->InsertNode(qnode_);
				botRQuad->InsertNode(qnode_);
				return;
			}

			if (nodes == NULL) {
				nodes = std::vector<CoordNode<T>*>();
				nodes.push_back(qnode_);
				std::cout << "Node was Added";
				return;
			}

			if (nodes.size() < size) {
				nodes.push_back(qnode_);
				std::cout << "Node was Added";
				return;
			}
			else {
				Divide();
				return;
			}

		}
	};

}