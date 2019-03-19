#include "pav_pch.h"
#include "QuadNode.h"

template <class T>
pav::QuadNode<T>::QuadNode(float xcoord_, float ycoord_, T data_) {
	coordinate.push_back(xcoord_);
	coordinate.push_back(ycoord_);
	value = data_;
}
