#include<iostream>
#include<stack>
#include<>

template<class T>
class Tree_Node
{
public:
	using Self = Tree_Node<T>;
	T _val;
	Self* _left;
	Self* _right;
};

Tree_Node<int>* make_tree()
{
	Tree_Node<int>* root = new Tree_Node<int>();
	root->_val = 0;
	Tree_Node<int>* node1 = new Tree_Node<int>();
	node1->_val = 1;
	Tree_Node<int>* node2 = new Tree_Node<int>();
	node1->_val = 2;
	Tree_Node<int>* node3 = new Tree_Node<int>();
	node1->_val = 3;
	Tree_Node<int>* node4 = new Tree_Node<int>();
	node1->_val = 4;
	root->_left = node1;
	root->_right = node2;
	node2->_left = node3;
	node2->_right = node4;
}

std::stack<Tree_Node<int>*> sk;

void houxu(Tree_Node<int>* root)
{
	sk.push(root);
	while (!sk.empty())
	{
		Tree_Node<int>* node = sk.top();
		if (node->_left) sk.push(node->_left);
		else if (node->_right) sk.push(node->_right);
		else
		{
			std::cout << node->_val << std::endl;
			sk.pop();
		}
	}
}

int main()
{
	Tree_Node<int>* root = make_tree();

	return 0;
}