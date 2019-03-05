#include "pav_pch.h"
#include "TreeNode.h"

template <class T>

void pav::TreeNode<T>::SetValue(T* newVal) {
	value = *newVal;
}

template<class T>
T * pav::TreeNode<T>::GetValue() {
	return value;
}

template<class T>
void pav::TreeNode<T>::SetFolderNode(bool isFolder) {
	folderNode = isFolder;
}

template<class T>
bool pav::TreeNode<T>::IsFolderNode() {
	return folderNode;
}

template<class T>
void pav::TreeNode<T>::AddChild(std::string && name, TreeNode<T>* child) {
	children.insert({ name, child });
}

template<class T>
void pav::TreeNode<T>::RemoveChild(std::string && name) {
	children.erase(name);
}

