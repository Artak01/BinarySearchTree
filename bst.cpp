#include "bst.h"

template <typename T>
BST<T>::BST() 
    : root (nullptr)
{}

template <typename T>
BST<T>::~BST() 
{
    clear(root);
}

template <typename T>
typename BST<T>::Node* BST<T>::insert(Node*& node, T value)
{
    if (!node) {
        node = new Node(value);
    } else if (value < node->val) {
        node->left = insert(node->left, value);
    } else if (value > node->val) {
        node->right = insert(node->right, value);
    }
    return node;
}

template <typename T>
typename BST<T>::Node* BST<T>::search(Node* node, T value) const
{
    if (!node) {
        return node;
    }
    if (node -> val == value) {
        return node;
    } else if (node -> val < value) {
        return search(node -> right, value);
    } else
        return search(node -> left, value);
}


template <typename T>
void BST<T>::inorder(Node* node) const
{
    if (!node) {
        return;
    }
    inorder(node -> left);
    std::cout << node -> val << " ";
    inorder(node -> right); 
}

template <typename T>
void BST<T>::preorder(Node* node) const
{
    if (!node) {
        return;
    }
    std::cout << node -> val << " ";
    preorder(node -> left);
    preorder(node -> right);
}

template <typename T>
void BST<T>::postorder(Node* node) const
{
    if (!node) {
        return;
    }
    postorder(node -> left);
    postorder(node -> right);
    std::cout << node -> val << " ";
}

template <typename T>
void BST<T>::clear(Node* node)
{
    if (!node) {
        return;
    }
    clear(node -> left);
    clear(node -> right);
    delete node;
}

template <typename T>
typename BST<T>::Node* BST<T>::deleteNode(Node* node, T value)
{
    if (!node) {
        return node;
    }
    if (node -> val < value) {
        node -> right = deleteNode(node -> right, value);
    } else if (node -> val > value) {
        node -> left = deleteNode(node -> left, value);
    } else if (node -> val == value) {
        if (!node -> left) {
            Node* tmp = node -> right;
            delete node;
            return tmp;
        } else if (!node -> right) {
            Node* tmp = node -> left;
            delete node;
            return tmp;
        } else {
            Node* tmp = getMax(node -> left);
            node -> val = tmp -> val;
            node = deleteNode(node -> left, tmp -> val);
        }
    }
    return node;
}

template <typename T>
typename BST<T>::Node* BST<T>::getMin(Node* node) const
{
    while (node && node -> left) {
        node = node -> left;
    }
    return node;
}

template <typename T>
typename BST<T>::Node* BST<T>::getMax(Node* node) const
{
    while (node && node -> right) {
        node = node -> right;
    }
    return node;    
}

template <typename T>
int BST<T>::getHeight(Node* node) const
{
    if (!node) {
        return 0;
    } 
    return std::max(getHeight(node -> left), getHeight(node -> right)) + 1;
}

template <typename T>
int BST<T>::getSize(Node* node) const
{
    if (!node) {
        return 0;
    }
    return 1 + getSize(node -> left) + getSize(node -> right); 
}

template <typename T>
typename BST<T>::Node* BST<T>::getPredecessor(Node* node, T value) const
{
    Node* curr = search(node, value);

    if (!curr) {
        throw std::invalid_argument("Invalid value!");
    }
    
    if (curr -> left) {
        return getMax(curr -> left);
    }

    Node* predecessor = nullptr;
    Node* ancestor = node;
    while (ancestor != curr) {
        if (ancestor -> val < value) {
            predecessor = ancestor;
            ancestor = ancestor -> right;
        } else {
            ancestor = ancestor -> left;
        }
    }
    return predecessor;
}

template <typename T>
typename BST<T>::Node* BST<T>::getSuccessor(Node* node, T value) const
{
    Node* curr = search(node, value);
    if (!curr) {
        throw std::invalid_argument("Invalid value!");
    }
    if (curr -> right) {
        return getMin(curr -> right);
    }

    Node* successor = nullptr;
    Node* ancestor = node;
    while (curr != ancestor) {
        if (ancestor -> val > value) {
            successor = ancestor;
            ancestor = ancestor -> left;
        } else {
            ancestor = ancestor -> right;
        }
    }
    return successor;
}

/////////////////////////////////////////////

template <typename T>
void BST<T>::insert(T value)
{
    root = insert(root, value);
}

template <typename T>
bool BST<T>::search(T value) const
{
    return search(root, value);
}

template <typename T>
void BST<T>::inorder() const
{
    inorder(root);
    std::cout << std::endl;
}

template <typename T>
void BST<T>::preorder() const
{
    preorder(root);
    std::cout << std::endl;
}

template <typename T>
void BST<T>::postorder() const 
{
    postorder(root);
    std::cout << std::endl;
}

template <typename T>
void BST<T>::deleteValue(T value)
{
    deleteNode(root, value);
}

template <typename T>
int BST<T>::getHeight() const
{
    return getHeight(root);
}

template <typename T>
int BST<T>::getSize() const
{
    return getSize(root);
}

template <typename T>
T BST<T>::getPredecessor(T value) const
{
    Node* node = getPredecessor(root, value);
    if (!node) {
        throw std::invalid_argument("The value is firast element!");
    }
    return node -> val;
}

template <typename T>
T BST<T>::getSuccessor(T value) const
{
    Node* node = getSuccessor(root, value);
    if (!node) {
        throw std::invalid_argument("The value is last element!");
    }
    return node -> val;
}
