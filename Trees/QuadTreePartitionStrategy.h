#pragma once
#include "ISpatialPartitionStrategy.h"

namespace pav {

	template <class T>
	class QuadTreePartitionStrategy : pav::ISpatialPartitionStrategy<T> {
	public:
		TreeNode<T>* Partition(TreeNode<T>* node, SpatialTree<T>* tree);
	};
	
	

}
