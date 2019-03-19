#pragma once

template <class FT>
class QuadNode;

namespace pav {

	template <class T>
	class QuadTree {
		const int size = 5;

		std::vector<float> topLBound;
		std::vector<float> botRBound;

		std::vector<QuadNode<T>*> nodes;

		QuadNode<T>* node;

		QuadTree<T>* topLQuad;
		QuadTree<T>* topRQuad;
		QuadTree<T>* botLQuad;
		QuadTree<T>* botRQuad;

	public:
		QuadTree();
		QuadTree(std::vector<float> topLB_, std::vector<float> botRB_);

		void InsertNode(QuadNode<T>* qnode_);
		QuadNode<T>* Find(std::vector<float> coord_);
		std::vector<QuadNode<T>*> FindInRadius(std::vector<float> coord_, float radius);

		bool inBound(std::vector<float> coord_);

	};

}