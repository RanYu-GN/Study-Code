#include "binary_tree.h"

int main(int argc, char const *argv[]) {
    std::vector<int> tree_data = {1, 2, 3, 4, 5, 6, 7};

    BinaryTree<int> binary_tree(tree_data);

    std::cout << "前序遍历：";
    binary_tree.PreorderTraversal();
    std::cout << std::endl;

    std::cout << "中序遍历：";
    binary_tree.InorderTraversal();
    std::cout << std::endl;

    std::cout << "后序遍历：";
    binary_tree.PostorderTraversal();
    std::cout << std::endl;
    return 0;
}
