#include "pav_pch.h"
#include "CoordNode.h"

template <class T>
pav::CoordNode<T>::CoordNode(std::vector<float> coordinates_, T data_) {
	coordinate = coordinates_;
	value = data_;
}
