#pragma once
#include "ISpatialPartitionStrategy.h"

namespace pav {

	template <class T>
	class QuadTreePartitionStrategy : ISpatialPartitionStrategy<T> {

		int limit = 10;
		int width;
		int height;
		int max_width = 1000;
		int max_height = 1000;

		TreeNode<T>* northwest;
		TreeNode<T>* northeast;
		TreeNode<T>* southwest;
		TreeNode<T>* southeast;

	public:
		void SetWidth(int newVal);
		void SetHeight(int newVal);
		TreeNode<T>* Partition(TreeNode<T>* node, SpatialTree<T>* tree);
	};
	
	

}
