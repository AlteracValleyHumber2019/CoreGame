/*#include "pav_pch.h"
#include "QuadTree.h"

template <class T>
pav::QuadTree<T>::QuadTree() {
	
}

template <class T>
pav::QuadTree<T>::QuadTree(vector<float> topLB_, vector<float> botRB_) {

	topLBound = topLB_;
	botRBound = botRB_;
	node = NULL;

	topLQuad = NULL;
	topRQuad = NULL;
	botLQuad = NULL;
	botRQuad = NULL;
}

template<class T>
void pav::QuadTree<T>::InsertNode(pav::CoordNode<T>* qnode_) {
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

	if (nodes.empty()) {
		nodes = vector<pav::CoordNode<T>*>();
		nodes.push_back(qnode_);
		std::cout << "Node was Added" << endl;
		return;
	}

	if (nodes.size() < size) {
		nodes.push_back(qnode_);
		std::cout << "Node was Added" << endl;
		return;
	}
	else {
		Divide();
		return;
	}
}


template<class T>
pav::CoordNode<T>* pav::QuadTree<T>::Find(vector<float> coord_) {
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
vector<pav::CoordNode<T>*> pav::QuadTree<T>::FindInRadius(vector<float> coord_, float radius) {
	return vector<pav::CoordNode<T>*>();
}

template<class T>
bool pav::QuadTree<T>::inBound(vector<float> coord_) {
	return (coord_[0] >= topLBound[0] && coord_[0] <= botRBound[0] && coord_[1] >= topLBound[1]
		&& coord_[1] <= botRBound[1]);
}

//TODO Implement Divide
template<class T>
void pav::QuadTree<T>::Divide() {
	//check if we cannot subdivide this quadrant any further
	if (abs(topLBound[0] - botRBound[0]) <= 1 && abs(topLBound[1] - botRBound[1]) <= 1) {
		//Todo: figure out some else to implement here for when the quadrant cant be divided further and is full
		return;
	}
	if (topLQuad == NULL) {
		vector<float> newbound;
		newbound.push_back((topLBound[0] + botRBound[0]) / 2);
		newbound.push_back((topLBound[1] + botRBound[1]) / 2);

		topLQuad = new QuadTree(topLBound, newbound);
		std::cout << "Top L Quad Made" << endl;
		for (int i = 0; i < nodes.size(); i++) {
			topLQuad->InsertNode(nodes[i]);
		}
	}
		
	//checking for botleft quadrant
	if (botLQuad == NULL) {
		vector<float> newLbound;
		newLbound.push_back(topLBound[0]);
		newLbound.push_back((topLBound[1] + botRBound[1]) / 2);

		vector<float> newRbound;
		newRbound.push_back((topLBound[0] + botRBound[0]) / 2);
		newRbound.push_back(botRBound[1]);

		botLQuad = new QuadTree(newLbound, newRbound);
		std::cout << "Bot L Quad Made" << endl;
		for (int i = 0; i < nodes.size(); i++) {
			botLQuad->InsertNode(nodes[i]);
		}
	}
	//checking for topright quad
	if (topRQuad == NULL) {
		vector<float> newLbound;
		newLbound.push_back((topLBound[0] + botRBound[0]) / 2);
		newLbound.push_back(topLBound[1]);

		vector<float> newRbound;
		newRbound.push_back(botRBound[0]);
		newRbound.push_back((topLBound[1] + botRBound[1]) / 2);

		topRQuad = new QuadTree(newLbound, newRbound);
		std::cout << "Top R Quad Made" << endl;
		for (int i = 0; i < nodes.size(); i++) {
			topRQuad->InsertNode(nodes[i]);
		}

	}
	//checking for botright quad
	if (botRQuad == NULL) {
		vector<float> newLbound;
		newLbound.push_back((topLBound[0] + botRBound[0]) / 2);
		newLbound.push_back((topLBound[1] + botRBound[1]) / 2);

		botRQuad = new QuadTree(newLbound, botRBound);
		std::cout << "Bot R Quad Made" << endl;
		for (int i = 0; i < nodes.size(); i++) {
			botRQuad->InsertNode(nodes[i]);
		}

	}

	divided = true;
	nodes.clear();
}

template class pav::QuadTree<int>;
template class pav::QuadTree<float>;*/