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




