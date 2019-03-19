#pragma once

template <class FT>
class QuadNode;

namespace pav {

	template <class T>
	class KDTree {
		const int k = 3;

		QuadNode<T>* node;

		int depth;

		KDTree<T>* leftBranch;
		KDTree<T>* rightBranch;


	public:
		KDTree();
		KDTree(QuadNode<T>* node, int depth);
		~KDTree();
	};
}

