#pragma once
namespace pav {

	template <class T>
	struct QuadNode {
		std::vector<float> coordinate;
		T value;
		
		QuadNode(std::vector<float> coordinates_, T data_);
	};
}