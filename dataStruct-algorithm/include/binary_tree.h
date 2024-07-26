#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <vector>

template<typename T>
class BinaryTree {
public:
    explicit BinaryTree(const std::vector<T> &);

    ~BinaryTree();

    // 递归前序遍历
    void PreorderTraversal(void) const;

    // 递归中序遍历
    void InorderTraversal(void) const;

    // 递归后序遍历
    void PostorderTraversal(void) const;

private:
    struct Node {
        T value;
        Node *left;
        Node *right;

        Node(const T &value) : value(value), left(nullptr), right(nullptr) {
        }
    };
    Node *root;

    // 函数声明
    Node *BuildTree(const std::vector<T> &data, int index);

    void DeleteTree(Node *);

    void Preorder(Node *) const;

    void Inorder(Node *) const;

    void Postorder(Node *) const;
};

template<typename T>
BinaryTree<T>::BinaryTree(const std::vector<T> &data) {
    if (data.empty()) {
        root = nullptr;
        return;
    }

    // 构建二叉树
    root = BuildTree(data, 0);
}

template<typename T>
BinaryTree<T>::~BinaryTree() {
    DeleteTree(root);
}

template<typename T>
typename BinaryTree<T>::Node *BinaryTree<T>::BuildTree(const std::vector<T> &data, int index) {
    if (index >= data.size()) {
        return nullptr;
    }

    // 创建节点
    Node *newNode = new Node(data[index]);

    // 递归构建左右子树
    newNode->left = BuildTree(data, 2 * index + 1);
    newNode->right = BuildTree(data, 2 * index + 2);

    return newNode;
}

template<typename T>
void BinaryTree<T>::DeleteTree(Node *node) {
    if (node == nullptr) {
        return;
    }

    // 递归删除左右子树
    DeleteTree(node->left);
    DeleteTree(node->right);

    // 删除当前节点
    delete node;
}

template<typename T>
void BinaryTree<T>::PreorderTraversal(void) const {
    Preorder(root);
}

template<typename T>
void BinaryTree<T>::InorderTraversal(void) const {
    Inorder(root);
}

template<typename T>
void BinaryTree<T>::PostorderTraversal(void) const {
    Postorder(root);
}

template<typename T>
void BinaryTree<T>::Preorder(Node *node) const {
    if (node == nullptr) {
        return;
    }

    // 访问当前节点
    std::cout << node->value << " ";

    // 递归前序遍历左右子树
    Preorder(node->left);
    Preorder(node->right);
}

template<typename T>
void BinaryTree<T>::Inorder(Node *node) const {
    if (node == nullptr) {
        return;
    }

    // 递归中序遍历左子树
    Inorder(node->left);

    // 访问当前节点
    std::cout << node->value << " ";

    // 递归中序遍历右子树
    Inorder(node->right);
}

template<typename T>
void BinaryTree<T>::Postorder(Node *node) const {
    if (node == nullptr) {
        return;
    }

    // 递归后序遍历左右子树
    Postorder(node->left);
    Postorder(node->right);

    // 访问当前节点
    std::cout << node->value << " ";
}

#endif