//判断一颗树是否为完全二叉树
//完全二叉树的定义是，前n-1层都是满的，第n层如有空缺，则是缺在右边，即第n层的最右边的节点，它的左边是满的，右边是空的。
//这个问题的描述已经提示了解法，采用广度优先遍历，从根节点开始，入队列，如果队列不为空，循环。遇到第一个没有左儿子或者右儿子的节点，设置标志位，如果之后再遇到有左/右儿子的节点，那么这不是一颗完全二叉树。
//这个方法需要遍历整棵树，复杂度为O(N)，N为节点的总数。

typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
} Node;

Queue<Node*> queue;

bool leftMost = false;

bool ProcessChild(Node* child) {
	if (child) {
		if (!leftMost) {
			queue.push(child);
		} else {
			return false;
		}
	} else {
		leftMost = true;
	}

	return true;
}

bool IsCompleteBinaryTree(Node* root) {
	//空树也是完全二叉树
	if (!root)
		return true;
	queue.push(root);

	while(!quue.empty()) {
		Node* node = queue.pop();
		//处理左节点
		if (!ProcessChild(node->left)
			return false;

		//处理右节点
		if (!ProcessChild(node->right))
			return false;
	}

	return true;
}

