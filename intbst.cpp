// intbst.cpp
// Implements class IntBST
// Peter Li, 2026/1/27

#include "intbst.h"

#include <iostream>
using std::cout;

// constructor sets up empty tree
IntBST::IntBST() { 
    root = nullptr;
}

// destructor deletes all nodes
IntBST::~IntBST() {
    clear(root);
}

// recursive helper for destructor
void IntBST::clear(Node *n) {
    if (n == nullptr) {
        return;
    }

    clear(n -> left);
    clear(n -> right);
    delete n;
}

// insert value in tree; return false if duplicate
bool IntBST::insert(int value) {
    if (root == nullptr) {
        root = new Node(value);
        return true;
    }
    return insert(value, root);
}

// recursive helper for insert (assumes n is never 0)
bool IntBST::insert(int value, Node* n) {
    if (n -> info > value) {
        if (n -> left == nullptr) {
            n -> left = new Node(value);
            n -> left -> parent = n;
            return true;
        } else {
            return insert(value, n -> left);
        }
    } else if (n -> info < value) {
        if (n -> right == nullptr) {
            n -> right = new Node(value);
            n -> right -> parent = n;
            return true;
        } else {
            return insert(value, n -> right);
        }
    } else {
        return false;
    }
}

// print tree data pre-order
void IntBST::printPreOrder() const {
    printPreOrder(root);
}

// recursive helper for printPreOrder()
void IntBST::printPreOrder(Node *n) const {
    if (n == nullptr) {
        return;
    }
    cout << n -> info << " ";
    printPreOrder(n -> left);
    printPreOrder(n -> right);
}

// print tree data in-order, with helper
void IntBST::printInOrder() const {
    printInOrder(root);
}
void IntBST::printInOrder(Node *n) const {
    if (n == nullptr) {
        return;
    }
    printInOrder(n -> left);
    cout << n -> info << " ";
    printInOrder(n -> right);
}

// prints tree data post-order, with helper
void IntBST::printPostOrder() const {
    printPostOrder(root);
}

void IntBST::printPostOrder(Node *n) const {
    if (n == nullptr) {
        return;
    }
    printPostOrder(n -> left);
    printPostOrder(n -> right);
    cout << n -> info << " ";
}

// return sum of values in tree
int IntBST::sum() const {
    return sum(root); // REPLACE THIS NON-SOLUTION
}

// recursive helper for sum
int IntBST::sum(Node *n) const {
    if (n == nullptr) {
        return 0;
    } 
    return sum(n -> left) + sum(n -> right) + n -> info;
}

// return count of values
int IntBST::count() const {
    return count(root);
}

// recursive helper for count
int IntBST::count(Node *n) const {
    if (n == nullptr) {
        return 0;
    } 
    return count(n -> left) + count(n -> right) + 1;
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
IntBST::Node* IntBST::getNodeFor(int value, Node* n) const{
    if (n == nullptr) {
        return nullptr;
    }
    if (n -> info > value) {
        return getNodeFor(value, n -> left);
    } else if (n -> info < value) {
        return getNodeFor(value, n -> right);
    } else {
        return n;
    }
}

// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const {
    return (getNodeFor(value, root) != nullptr); 
}

// returns the Node containing the predecessor of the given value
IntBST::Node* IntBST::getPredecessorNode(int value) const{
    if (root == nullptr) {
        return nullptr;
    }

    Node* curr = getNodeFor(value, root);

    if (curr == nullptr) {
        return nullptr;
    }

    if (curr -> left != nullptr) {
        curr = curr -> left;
        while (curr -> right != nullptr) {
            curr = curr -> right;
        }
        return curr;
    } else {
        while (curr -> parent != nullptr && curr -> parent -> left == curr) {
            curr = curr -> parent;
        }
        curr = curr -> parent;
        return curr;
    }
    return nullptr;
}

// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const{
    Node* predecessor = getPredecessorNode(value);
    if (predecessor == nullptr) {
        return 0;
    }
    return predecessor -> info;
}

// returns the Node containing the successor of the given value
IntBST::Node* IntBST::getSuccessorNode(int value) const{
    if (root == nullptr) {
        return nullptr;
    }

    Node* curr = getNodeFor(value, root);

    if (curr == nullptr) {
        return nullptr;
    }
    
    if (curr -> right != nullptr) {
        curr = curr -> right;
        while (curr -> left != nullptr) {
            curr = curr -> left;
        }
        return curr;
    } else {
        while (curr -> parent != nullptr && curr -> parent -> right == curr) {
            curr = curr -> parent;
        } 
        curr = curr -> parent;
        return curr;
    }
    return nullptr;
}

// returns the successor value of the given value or 0 if there is none
int IntBST::getSuccessor(int value) const{
    Node* successor = getSuccessorNode(value);
    if (successor == nullptr) {
        return 0;
    }
    return successor -> info;
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool IntBST::remove(int value){
    Node* nodeToDelete = getNodeFor(value, root);

    if (nodeToDelete == nullptr) {
        return false;
    }
    // Case 1: To delete node having two children, we can replace the value in nodeToDelete 
    // with the value of the successor, and then delete the successor (successors can't have
    // 2 children).
    if (nodeToDelete -> left != nullptr && nodeToDelete -> right != nullptr) {
        Node* successor = getSuccessorNode(value);
        nodeToDelete -> info = successor -> info;
        nodeToDelete = successor; 
    }
    // Case 2: Delete node with one or zero child
    Node* child = nullptr;
    if (nodeToDelete -> left != nullptr) {
        child = nodeToDelete -> left;
    } else {
        child = nodeToDelete -> right;
    }

    if (nodeToDelete -> parent == nullptr) {
        root = child;
        delete nodeToDelete;
        return true;
    } else if (nodeToDelete == nodeToDelete -> parent -> left) {
        nodeToDelete -> parent -> left = child;
    } else {
        nodeToDelete -> parent -> right = child;
    }

    if (child != nullptr) {
        child -> parent = nodeToDelete -> parent;
    }

    delete nodeToDelete;
    return true;
}
