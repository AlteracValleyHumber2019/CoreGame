#include "pav_pch.h"
#include "QuadTree.h"
#include "QuadNode.h"

template <class T>
pav::QuadTree<T>::QuadTree() {
	
}

template <class T>
pav::QuadTree<T>::QuadTree(std::vector<float> topLB_, std::vector<float> botRB_) {

	topLBound = topLB_;
	botRBound = botRB_;
	node = NULL;

	topLQuad = NULL;
	topRQuad = NULL;
	botLQuad = NULL;
	botRQuad = NULL;
}

//keeping all this code under comments so that the project can be compiled and worked on
//TODO: Find out why the declaration for the function is incompatible
/*template<class T>
void pav::QuadTree<T>::InsertNode(pav::QuadNode<T>* qnode_) {
	
	//check if a valid node is being passed
	if (qnode_ == NULL) {
		return;
	}

	//check to make sure if the node is within the bounds of this quadrant
	if (!inBound(qnode_->coordinate)) {
		return;
	}

	//check if we cannot subdivide this quadrant any further
	if (abs(topLBound[0] - botRBound[0]) <= 1 && abs(topLBound[1] - botRbound[1]) <= 1) {
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
				newbound.pushback((topLBound[0] + botRBound[0]) / 2);
				newbound.pushback((topLBound[1] + botRBound[1]) / 2);

				topLQuad = new QuadTree(topLBound, newbound);
				topLQuad->InsertNode(qnode_);
			}
		}
		//checking for botleft quadrant
		else {
			if (botLQuad == NULL) {
				vector<float> newLbound;
				newLbound.pushback(topLBound[0]);
				newLbound.pushback((topLBound[1] + botRBound[1]) / 2);

				vector<float> newRbound;
				newRbound.pushback((topLBound[0] + botRBound[0]) / 2);
				newRbound.pushback(botRBound[1]);

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
				newLbound.pushback((topLBound[0] + botRBound[0])/2);
				newLbound.pushback(topLBound[1]);

				vector<float> newRbound;
				newRbound.pushback(botRBound[0]);
				newRbound.pushback((topLBound[1] + botRBound[1]) / 2);

				topRQuad = new QuadTree(newLbound, newRbound);
				topRQuad->InsertNode(qnode_);

			}
		}
		//checking for botright quad
		else {
			if (botRQuad == NULL) {
				vector<float> newLbound;
				newLbound.pushback((topLBound[0] + botRBound[0]) / 2);
				newLbound.pushback((topLBound[1] + botRBound[1]) / 2);

				botRQuad = new QuadTree(newLbound, botRBound);
				botRQuad->InsertNode(qnode_);

			}
		}
	}


}*/

template<class T>
QuadNode<T>* pav::QuadTree<T>::Find(std::vector<float> coord_) {
	//check if its in the quad
	if (!inBound(coord_)) {
		return NULL;
	}

	if (node != NULL) {
		return node;
	}

	if ((topLBound[0] + botRBound[0]) / 2 >= coord_[0]) {
		// check topleftquad
		if ((topLBound[1] + botRBound[1]) / 2 >= coord_[1]) {
			if (topLQuad == NULL) {
				return NULL;
			}
			return topLQuad->Find(coord_);
		}

		//check botleftquad
		else {
			if (botLQuad == NULL) {
				return NULL;
			}
			return botLQuad->Find(coord_);
		}
	}
	else {
		// check topRQuad 
		if ((topLBound[1] + botRBound[1]) / 2 >= coord_[1]) {
			if (topRQuad == NULL) {
				return NULL;
			}
			return topRQuad->Find(coord_);
		}

		// check botRQuad
		else {
			if (botRQuad == NULL) {
				return NULL;
			}
			return botRQuad->Find(coord_);
		}
	}
}

template<class T>
std::vector<QuadNode<T>*> pav::QuadTree<T>::FindInRadius(std::vector<float> coord_, float radius) {
	return std::vector<QuadNode<T>*>();
}

template<class T>
bool pav::QuadTree<T>::inBound(std::vector<float> coord_) {
	return (coord_[0] >= topLBound[0] && coord_[0] <= botRBound[0] && coord_[1] >= topLBound[1]
		&& coord_[1] <= botRBound[1]);
}




