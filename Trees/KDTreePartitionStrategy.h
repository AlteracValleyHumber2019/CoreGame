#pragma once
#include "ISpatialPartitionStrategy.h"

template <class T>

class KDTreePartitionStrategy : ISpatialPartitionStrategy<T> {
	TreeNode<T>* Partition(TreeNode<T>* node, SpatialTree<T>* tree);
};