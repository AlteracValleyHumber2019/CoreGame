#pragma once

namespace pav {
	template <class FT>
	class SpatialTree;

	template <class FT>
	class TreeNode;

	template <class T>
	class ISpatialPartitionStrategy {
	public:
		virtual TreeNode<T>* Partition(TreeNode<T>* node, SpatialTree* tree)=0;
	};
}
