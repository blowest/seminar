#include <cmath>
#include <queue>
#include <iostream>
using namespace std;

class tree_node {
private:
	int value;
	int level;
	tree_node* leftNode;
	tree_node* rightNode;

public:
	tree_node(int v, int l=0) {
		value = v;
		level = l;
		leftNode = nullptr;
		rightNode = nullptr;
	}

	bool is_left_node_empty() {
		if (leftNode == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}

	bool is_right_node_empty() {
		if (rightNode == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}

	int get_level() {
		return level;
	}

	void set_level(int new_level) {
		level = new_level;
	}

	int get_value() {
		return value;
	}

	tree_node* get_left_node() {
		return leftNode;
	}

	tree_node* get_right_node() {
		return rightNode;
	}

	void set_left_node(tree_node* node) {
		node->set_level(level + 1);
		leftNode = node;
	}

	void set_right_node(tree_node* node) {
		node->set_level(level + 1);
		rightNode = node;
	}
};


class binary_tree {
private:
	tree_node* root;

public:
	binary_tree(int n) {
		root = nullptr;
		queue<tree_node*> q;
		tree_node* node;

		for (int i = 1; i <= n; i++) {
			node = new tree_node(i);

			if (root == nullptr) {
				root = node;
				q.push(node);
			}
			else {
				tree_node* front = q.front();

				if (front->is_left_node_empty()) {
					front->set_left_node(node);
					q.push(node);
				}
				else if (front->is_right_node_empty()) {
					front->set_right_node(node);
					q.push(node);
					q.pop();
				}
			}
		}
	}

	void print() {
		queue<tree_node*> q;
		int current_level = 0;

		q.push(root);
		while (!q.empty()) {
			tree_node* node = q.front();

			if (!node->is_left_node_empty()) {
				q.push(node->get_left_node());
			}
			if(!node->is_right_node_empty()) {
				q.push(node->get_right_node());
			}

			if (current_level != node->get_level()) {
				current_level = node->get_level();
				cout << endl;
			}
			
			cout << node->get_value();

			q.pop();
		}
	}
};

int main()
{
	binary_tree bt = binary_tree(8);
	bt.print();
	return 0;
}