#pragma once

template<typename T>
class TreeNode {
public:
    T data;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    int index;

    TreeNode(T data, int idx, TreeNode* parent = nullptr)
        : data(data), left(nullptr), right(nullptr), parent(parent), index(idx) {}
};
	