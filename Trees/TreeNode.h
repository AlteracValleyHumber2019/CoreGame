#pragma once

namespace pav {

	template <class T>
	class TreeNode {
		T value;
		TreeNode<T>* parent;
		std::unordered_map<std::string, TreeNode<T>*> children;
		bool folderNode;

	public:
		void SetValue(T* newVal);
		T* GetValue();
		void SetFolderNode(bool isFolder);
		bool IsFolderNode();
		void AddChild(std::string&& name, TreeNode<T>* child);
		void RemoveChild(std::string&& name);

	};
}