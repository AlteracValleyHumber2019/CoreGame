#include "pav_pch.h"
#include "SpatialTree.h"
#include "TreeNode.h"
#include "QuadTreePartitionStrategy.h"


template<class T>
void pav::QuadTreePartitionStrategy<T>::SetWidth(int newVal) {
	width = newVal;
}

template<class T>
pav::TreeNode<T>* pav::QuadTreePartitionStrategy<T>::Partition(TreeNode<T>* node, SpatialTree<T>* tree) {
	
	if (node->children.size > limit) {
		northwest = new TreeNode<T>();
		northwest->SetFolderNode(true);

		northeast = new TreeNode<T>();
		northeast->SetFolderNode(true);

		southwest = new TreeNode<T>();
		southwest->SetFolderNode(true);

		southeast = new TreeNode<T>();
		southeast->SetFolderNode(true);

		for (const auto &element :node.children) {
			if (element.second.value > width / 2 && element.second.value > height / 2) {
				southeast->AddChild(element.first, element.second);
			}else if (element.second.value > width / 2 && element.second.value < height / 2) {
				northeast->AddChild(element.first, element.second);
			}
			else if (element.second.value < width / 2 && element.second.value > height / 2) {
				southwest->AddChild(element.first, element.second);
			}
			else if (element.second.value < width / 2 && element.second.value < height / 2) {
				northwest->AddChild(element.first, element.second);
			}
		}

		if (northwest->children.size > limit) {
			northwest = Partition(northwest, tree);
		}
		if (northeast->children.size > limit) {
			northeast = Partition(northeast, tree);
		}
		if (southwest->children.size > limit) {
			southwest = Partition(southwest, tree);
		}
		if (southeast->children.size > limit) {
			southeast = Partition(southeast, tree);
		}

		TreeNode<T>* newNode = new TreeNode<T>();
		newNode->AddChild("NW", northwest);
		newNode->AddChild("NE", northeast);
		newNode->AddChild("SW", southwest);
		newNode->AddChild("SE", southeast);

		return newNode;
	}

}