#include "pav_pch.h"

template<class T>
bool pav::KDTree<T>::ComparePosition(CoordNode<T>* node_) {

	for (int i = 0; i < k; i++) {
		if (node->coordinate[i] != node_->coordinate[i]) {
			return false;
		}
	}

	return true;
}

template <class T>
pav::KDTree<T>::KDTree(CoordNode<T>* node_, int depth_) {
	node = node_;
	depth = depth_;
	leftBranch = NULL;
	rightBranch = NULL;
}

template<class T>
void pav::KDTree<T>::InsertNode(CoordNode<T>* node_) {

	//check if a valid node is being passed
	if (node_ == NULL) {
		return;
	}

	//check if this is a leaf node
	if (node == NULL) {
		node = node_;
		std::cout << "Node Inserted" << endl;
		return;
	}
	//calculate which dimension we are checking
	int dimension = depth % k;

	//check which side of the tree we need to go to next
	if (node_->coordinate[dimension] < node->coordinate[dimension]) {
		if (leftBranch == NULL) {
			leftBranch = new KDTree(NULL, depth + 1);
			std::cout << "Left Branch Made" << endl;
			leftBranch->InsertNode(node_);
		}
		else {
			leftBranch->InsertNode(node_);
		}
	}
	else {
		if (rightBranch == NULL) {
			rightBranch = new KDTree(NULL, depth + 1);
			std::cout << "Right Branch Made" << endl;
			rightBranch->InsertNode(node_);
		}
		else {
			rightBranch->InsertNode(node_);
		}
	}

}

template<class T>
pav::CoordNode<T>* pav::KDTree<T>::FindN(CoordNode<T>* node_) {

	//check if there is a node at this tree yet
	if (node == NULL) {
		return node;
	}

	//if there is a node and its the same location, then its there
	if (ComparePosition(node_)) {
		return node;
	}

	//get the current dimension
	int dimension = depth % k;

	//check which side of the tree to check next
	if (node_->coordinate[dimension] < node->coordinate[dimension]) {
		return leftBranch->FindN(node_);
	}
	else {
		return rightBranch->FindN(node_);
	}

}