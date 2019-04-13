#pragma once
namespace pav {

	template <class T>
	struct CoordNode {
		std::vector<float> coordinate;
		T value;
		
		CoordNode(std::vector<float> coordinates_, T data_);
	};
}