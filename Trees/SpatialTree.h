#pragma once

namespace pav {

	template <class FT>
	class ISpatialPartitionStrategy;

	template <class FT>
	class TreeNode;

	template <class T>
	class SpatialTree {
		ISpatialPartitionStrategy<T>* SpatialPartitionStrategy;
		std::unordered_map<std::string, TreeNode<T>> nodes;
		TreeNode<T>* root;

	public:
		void EmplaceNode(std::string name, T* value);
		void Partition();
		TreeNode<T>* GetRoot();
		TreeNode<T>* GetImmediateFolderNode();
		TreeNode<T>* GetNode(std::string name);
	};
}