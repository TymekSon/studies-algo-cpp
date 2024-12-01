#include "tree.h"

int main() {
    BinarySearchTree<int> testTree;

    testTree.add(5);
    testTree.add(3);
    testTree.add(7);
    testTree.add(2);
    testTree.add(4);
    testTree.add(6);
    testTree.add(8);

    std::cout << "In-order traversal: ";
    testTree.inOrder();

    std::cout << "Pre-order traversal: ";
    testTree.preOrder();

    std::cout << "Tree height: " << testTree.height() << std::endl;

    std::cout << "Tree as string: " << testTree.toString() << std::endl;

    std::cout << "Try to Find 4: " << (testTree.find(4) ? "Found" : "Not found") << std::endl;
    std::cout << "Try to Find 10: " << (testTree.find(10) ? "Found" : "Not found") << std::endl;

    testTree.remove(5);
    std::cout << "In-order traversal after removing 5: ";
    testTree.inOrder();

    testTree.clear();
    std::cout << "In-order traversal after clearing: ";
    testTree.inOrder();

    return 0;
}