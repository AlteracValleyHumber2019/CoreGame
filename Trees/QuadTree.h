#pragma once
#include <vector>

template <class FT>
class QuadNode;
using namespace std;
namespace pav {

	template <class T>
	class QuadTree {
		//TODO: rewrite the quad tree to handle a size if we decide to do so, as it is the quad tree will go
		//to a unit quad
		const int size = 5;

		//the boundaries for the quad tree
		vector<float> topLBound;
		vector<float> botRBound;

		//TODO rewrite the quad tree to store a list of nodes in order to have less recursion and more populated quads
		vector<QuadNode<T>*> nodes;

		//the main node of this tree
		QuadNode<T>* node;

		//the four quadrants of the tree
		QuadTree<T>* topLQuad;
		QuadTree<T>* topRQuad;
		QuadTree<T>* botLQuad;
		QuadTree<T>* botRQuad;

	public:
		QuadTree();
		QuadTree(vector<float> topLB_, vector<float> botRB_);		
		//Method to find and return a node in the tree at the given position
		QuadNode<T>* Find(std::vector<float> coord_);
		//TODO implement the find In radius function in order to return a vector of all nodes within a certain search radius
		std::vector<QuadNode<T>*> FindInRadius(std::vector<float> coord_, float radius);

		//helper function to determine if a coordinate is inboundaries of this tree, may have separate applications
		//outside of being a helper function, leaving it public for now
		bool inBound(std::vector<float> coord_);

		//insert method for adding a node to the tree TODO: find out why the declaration is incompatible and not funcitoning
		void InsertNode(QuadNode<T>* qnode_) {

			//check if a valid node is being passed
			if (qnode_ == NULL) {
				return;
			}

			//check to make sure if the node is within the bounds of this quadrant
			if (!inBound(qnode_->coordinate)) {
				return;
			}

			//check if we cannot subdivide this quadrant any further
			if (abs(topLBound[0] - botRBound[0]) <= 1 && abs(topLBound[1] - botRBound[1]) <= 1) {
				if (node == NULL) {
					node = qnode_;
				}
				return;
			}

			if ((topLBound[0] + botRBound[0]) / 2 >= qnode_->coordinate[0]) {
				//checking for topleft quadrant
				if ((topLBound[1] + botRBound[1]) / 2 >= qnode_->coordinate[1]) {
					if (topLQuad == NULL) {
						vector<float> newbound;
						newbound.push_back((topLBound[0] + botRBound[0]) / 2);
						newbound.push_back((topLBound[1] + botRBound[1]) / 2);

						topLQuad = new QuadTree(topLBound, newbound);
						topLQuad->InsertNode(qnode_);
					}
				}
				//checking for botleft quadrant
				else {
					if (botLQuad == NULL) {
						vector<float> newLbound;
						newLbound.push_back(topLBound[0]);
						newLbound.push_back((topLBound[1] + botRBound[1]) / 2);

						vector<float> newRbound;
						newRbound.push_back((topLBound[0] + botRBound[0]) / 2);
						newRbound.push_back(botRBound[1]);

						botLQuad = new QuadTree(newLbound, newRbound);
						botLQuad->InsertNode(qnode_);
					}
				}
			}
			else {
				//checking for topright quad
				if ((topLBound[1] + botRBound[1]) / 2 >= qnode_->coordinate[1]) {
					if (topRQuad == NULL) {
						vector<float> newLbound;
						newLbound.push_back((topLBound[0] + botRBound[0]) / 2);
						newLbound.push_back(topLBound[1]);

						vector<float> newRbound;
						newRbound.push_back(botRBound[0]);
						newRbound.push_back((topLBound[1] + botRBound[1]) / 2);

						topRQuad = new QuadTree(newLbound, newRbound);
						topRQuad->InsertNode(qnode_);

					}
				}
				//checking for botright quad
				else {
					if (botRQuad == NULL) {
						vector<float> newLbound;
						newLbound.push_back((topLBound[0] + botRBound[0]) / 2);
						newLbound.push_back((topLBound[1] + botRBound[1]) / 2);

						botRQuad = new QuadTree(newLbound, botRBound);
						botRQuad->InsertNode(qnode_);

					}
				}
			}


		}
	};

}