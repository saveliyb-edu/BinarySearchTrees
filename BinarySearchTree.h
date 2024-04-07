#pragma once
#include <iostream>
#include "StackArray.h"
#include "CircularQueue.h"
#include "Queue.h"

template <class T>
class BinarySearchTree {
private:
	struct Node {
		T key_;
		Node* left_;
		Node* right_;
		Node* p_;
		Node(T key, Node* left = nullptr, Node* right = nullptr, Node* p = nullptr) :
			key_(key), left_(left), right_(right), p_(p)
		{ }

	};
	Node* root_;

	// Функция поиска адреса узла по ключу в бинарном дереве поиска
	Node* searchNodeIterative(const T& key) const {
		Node* current = root_;
		while (current != nullptr && current->key_ != key) {
			if (key < current->key_) {
				current = current->left_;
			}
			else {
				current = current->right_;
			}
		}
		return current;
	}

	// Рекурсивная функция для вывода структуры дерева в выходной поток
	void output(std::ostream& out, Node* root) const {
		if (root == nullptr) {
			out << "null";
			return;
		}
		out << root->key_;
		if (root->left_ != nullptr || root->right_ != nullptr) {
			out << "(";
			output(out, root->left_);
			out << ",";
			output(out, root->right_);
			out << ")";
		}
	}

	// Рекурсивная функция определения количества узлов дерева
	int getNumberOfNodes(const Node* node) const {
		if (node == nullptr) {
			return 0;
		}
		return 1 + getNumberOfNodes(node->left_) + getNumberOfNodes(node->right_);
	}
	
	// Рекурсивная функция определения высоты дерева
	int getHeight(const Node* node) const {
		if (node == nullptr) {
			return 0;
		}
		int leftHeight = getHeight(node->left_);
		int rightHeight = getHeight(node->right_);
		return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
	}

	// Рекурсивная функция для инфиксного обхода узлов дерева
	void inorderWalk(Node* node) const {
		if (node != nullptr) {
			inorderWalk(node->left_);
			std::cout << node->key_ << " ";
			inorderWalk(node->right_);
		}
	}
	
	// 10 Являются ли два дерева похожими. Похожими будем называть деревья поиска, содержащие одинаковые наборы ключей. Рекомендация: параллельно обходить инфиксным обходом сравниваемые деревья
	bool isSimilar(Node* node1, Node* node2) const {
		if (node1 == nullptr || node2 == nullptr) {
			return node1 == node2;
		}
		if (node1->key_ != node2->key_) {
			return false;
		}
		return isSimilar(node1->left_, node2->left_) && isSimilar(node1->right_, node2->right_);
	}

	// 11 Есть одинаковые ключи в двух деревьях поиска. Рекомендация: параллельно обходить инфиксным обходом сравниваемые деревья
	bool isIdenticalKey(Node* node1, Node* node2) const {
		if (node1 == nullptr || node2 == nullptr) {
			return node1 == node2;
		}
		if (node1->key_ != node2->key_) {
			return true;
		}
		return isIdenticalKey(node1->left_, node2->left_) || isIdenticalKey(node1->right_, node2->right_);
	}

	void transplant(Node* u, Node* v) {
		if (u->p_ == nullptr) {
			root_ = v;
		}
		else if (u == u->p_->left_) {
			u->p_->left_ = v;
		}
		else {
			u->p_->right_ = v;
		}
		if (v != nullptr) {
			v->p_ = u->p_;
		}
	}
	
	Node* minimum(Node* node) {
		while (node->left_ != nullptr) {
			node = node->left_;
		}
		return node;
	}

public:
	BinarySearchTree() : root_(nullptr){}

	BinarySearchTree(const BinarySearchTree<T>& scr) = delete;
	BinarySearchTree(BinarySearchTree<T>&& scr) noexcept {
		root_ = scr.root_;
		scr.root_ = nullptr;
	}

	BinarySearchTree <T>& operator= (const BinarySearchTree <T>& src) = delete;
	BinarySearchTree <T>& operator= (BinarySearchTree <T>&& src) noexcept {
		if (this != &src) {
			root_ = src.root_;
			src.root_ = nullptr;
		}
		return *this;
	}

	virtual ~BinarySearchTree() {
		while (root_ != nullptr) {
			deleteNode(root_->key_);
		}
	};

	bool searchKeyIterative(const T& key) const {
		return searchNodeIterative(key) != nullptr;
	}

	// 2 Вставка нового элемента в дерево: true, если элемент добавлен; false, если элемент уже был
	bool insertNode(const T& key) {
		Node* current = root_;
		Node* parent = nullptr;
		while (current != nullptr) {
			parent = current;
			if (key == current->key_) {
				return false;
			}
			if (key < current->key_) {
				current = current->left_;
			}
			else {
				current = current->right_;
			}
		}
		Node* newNode = new Node(key, nullptr, nullptr, parent);
		if (parent == nullptr) {
			root_ = newNode;
		}
		else if (key < parent->key_) {
			parent->left_ = newNode;
		}
		else {
			parent->right_ = newNode;
		}
		return true;
	}

	// 3.1 Удаление элемента c заданным ключом, не нарушающее порядок элементов true, если элемент удален; false, если элемента не было
	bool deleteNode(const T& key) {
		Node* current = searchNodeIterative(key);
		if (current == nullptr) {
			return false;
		}
		if (current->left_ == nullptr) {
			transplant(current, current->right_);
		}
		else if (current->right_ == nullptr) {
			transplant(current, current->left_);
		}
		else {
			Node* min = minimum(current->right_);
			if (min->p_ != current) {
				transplant(min, min->right_);
				min->right_ = current->right_;
				min->right_->p_ = min;
			}
			transplant(current, min);
			min->left_ = current->left_;
			min->left_->p_ = min;
		}
		delete current;
		return true;
	}


	// 4.1 Вывод структуры (строкового изображения дерева) в выходной поток out, использовать скобки, чтобы показать структуру дерева
	void output(std::ostream& out) const {
		output(out, root_);
	}

	int getNumberOfNodes() const {
		return getNumberOfNodes(this->root_);
	};

	int getHeight() const {
		return getHeight(this->root_);
	};


	// 7 Инфиксный обход дерева (итеративный)
	void inorderWalkIterative() const {
		size_t temp = this->getHeight();
		if (temp == 0) {
			return;
		}

		StackArray<Node*> stack(temp);
		Node* current = root_;
		while (current != nullptr || !stack.isEmpty()) {
			while (current != nullptr) {
				stack.push(current);
				current = current->left_;
			}
			current = stack.top();
			stack.pop();
			std::cout << current->key_ << " ";
			current = current->right_;
		}
	}
	// 8.1 Инфиксный обход дерева (рекурсивный)
	void inorderWalk() const {
		inorderWalk(root_);
	}
	// 9 Обход двоичного дерева по уровням (в ширину).
	void walkByLevels() const {
		size_t temp = this->getNumberOfNodes();
		if (temp == 0) {
			return;
		}

		CircularQueue<Node*>* queue = new CircularQueue<Node*>(temp);
		queue->enQueue(root_);
		while (!queue->isEmpty()) {
			Node* current = queue->front();
			queue->deQueue();
			std::cout << current->key_ << " ";
			if (current->left_ != nullptr) {
				queue->enQueue(current->left_);
			}
			if (current->right_ != nullptr) {
				queue->enQueue(current->right_);
			}
		}
		delete queue;
	}




	// 10 Являются ли два дерева похожими. Похожими будем называть деревья поиска, содержащие одинаковые наборы ключей.Рекомендация: параллельно обходить инфиксным обходом сравниваемые деревья
	bool isSimilar(const BinarySearchTree<T>& other) const {
		return isSimilar(root_, other.root_);
	}

	// 11 Есть одинаковые ключи в двух деревьях поиска
	bool isIdenticalKey(const BinarySearchTree<T>& other) const {
		return isIdenticalKey(root_, other.root_);
	}
};

