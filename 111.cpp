/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/


//��α��� :-)
class Solution {
public:
	int minDepth(TreeNode* root) {
		if (!root) return 0;
		queue<TreeNode*> q;
		q.push(root);
		int res = 1;
		int prevNum = 1;
		int curNum = 0;
		while (!q.empty()) {
			while (prevNum--) {
				TreeNode* tmp = q.front();
				q.pop();
				if (tmp->left == nullptr&&tmp->right == nullptr) return res;
				if (tmp->left) {
					q.push(tmp->left);
					++curNum;
				}
				if (tmp->right) {
					q.push(tmp->right);
					++curNum;
				}

			}
			prevNum = curNum;
			curNum = 0;
			++res;
		}
		return res;
	}
};

//����ݹ�ⷨ ������Ŀ��������[1,2]��������

class Solution {
public:
	int minDepth(TreeNode* root) {
		if (!root) return 0;
		int left = minDepth(root->left);
		int right = minDepth(root->right);
		return (left&&right) ? 1 + min(left, right) : 1 + left + right;
	}
};

//�ٷ�BFS ͨ��pair��¼����������
class Solution {
public:
	int minDepth(TreeNode *root) {
		if (root == nullptr) {
			return 0;
		}

		queue<pair<TreeNode *, int> > que;
		que.emplace(root, 1);
		while (!que.empty()) {
			TreeNode *node = que.front().first;
			int depth = que.front().second;
			que.pop();
			if (node->left == nullptr && node->right == nullptr) {
				return depth;
			}
			if (node->left != nullptr) {
				que.emplace(node->left, depth + 1);
			}
			if (node->right != nullptr) {
				que.emplace(node->right, depth + 1);
			}
		}

		return 0;
	}
};