#include "pav_pch.h"
#include "SpatialTree.h"
#include "TreeNode.h"
#include "ISpatialPartitionStrategy.h"

template <class T>
void pav::SpatialTree<T>::EmplaceNode(std::string name, T* value) {
	nodes.insert({ name, value });
}

template<class T>
void pav::SpatialTree<T>::Partition() {
	root = SpatialPartitionStrategy->Partition(root, this);
}

template<class T>
pav::TreeNode<T>* pav::SpatialTree<T>::GetRoot() {
	return root;
}

template<class T>
pav::TreeNode<T>* pav::SpatialTree<T>::GetImmediateFolderNode() {
	return root;
}

template<class T>
pav::TreeNode<T>* pav::SpatialTree<T>::GetNode(std::string name) {
	return nodes.at(name);
}
