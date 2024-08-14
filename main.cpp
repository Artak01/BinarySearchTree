#include <iostream>
#include "bst.h"

int main() {
    // Create a BST instance
    BST<int> bst;

    // Insert elements into the BST
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    // Inorder traversal (should print sorted order)
    std::cout << "Inorder traversal: ";
    bst.inorder();
    std::cout << std::endl;

    // Preorder traversal
    std::cout << "Preorder traversal: ";
    bst.preorder();
    std::cout << std::endl;

    // Postorder traversal
    std::cout << "Postorder traversal: ";
    bst.postorder();
    std::cout << std::endl;

    // Search for a value
    int searchValue = 40;
    if (bst.search(searchValue)) {
        std::cout << searchValue << " found in the BST." << std::endl;
    } else {
        std::cout << searchValue << " not found in the BST." << std::endl;
    }

    // Get the height of the BST
    std::cout << "Height of the BST: " << bst.getHeight() << std::endl;

    // Get the size of the BST
    std::cout << "Size of the BST: " << bst.getSize() << std::endl;

    // Get predecessor of a value
    int predecessorValue = 60;
    try {
        int predecessor = bst.getPredecessor(predecessorValue);
        std::cout << "Predecessor of " << predecessorValue << " is " << predecessor << std::endl;
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    // Get successor of a value
    int successorValue = 60;
    try {
        int successor = bst.getSuccessor(successorValue);
        std::cout << "Successor of " << successorValue << " is " << successor << std::endl;
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    // Delete a value from the BST
    int deleteValue = 50;
    bst.deleteValue(deleteValue);
    std::cout << "Inorder traversal after deleting " << deleteValue << ": ";
    bst.inorder();
    std::cout << std::endl;

    return 0;
}
   
