#pragma once


namespace pav {

	template <class T>
	struct QuadNode {
		std::vector<float> coordinate;
		T value;
		
		QuadNode(float xcoord_, float ycoord_, T data_);
	};
}