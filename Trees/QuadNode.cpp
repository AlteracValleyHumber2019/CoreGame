#include "pav_pch.h"
#include "QuadNode.h"

template <class T>
pav::QuadNode<T>::QuadNode(std::vector<float> coordinates_, T data_) {
	coordinate = coordinates_;
	value = data_;
}
