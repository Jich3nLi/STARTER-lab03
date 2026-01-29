// test_intbst.cpp
#include "intbst.h"
#include <iostream>
using namespace std;

int main() {
    IntBST bst;

    cout << "Insert Test" << endl;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    cout << endl << "Tree Traversal Test" << endl;
    cout << "Preorder: ";
    bst.printPreOrder();
    cout << endl;

    cout << "Inorder: ";
    bst.printInOrder();
    cout << endl;

    cout << "Postorder: ";
    bst.printPostOrder();
    cout << endl;

    cout << endl << "Count & Sum Test" << endl;
    cout << "Count: " << bst.count() << endl;
    cout << "Sum: " << bst.sum() << endl;

    cout << endl << "Contains Test" << endl;
    cout << "Contains 40? " << (bst.contains(40) ? "Yes" : "No") << endl;
    cout << "Contains 25? " << (bst.contains(25) ? "Yes" : "No") << endl;

    cout << endl << "Successor & Predecessor Test" << endl;
    cout << "Successor of 50: " << bst.getSuccessor(50) << endl;
    cout << "Predecessor of 50: " << bst.getPredecessor(50) << endl;

    cout << "Successor of 20: " << bst.getSuccessor(20) << endl;
    cout << "Predecessor of 80: " << bst.getPredecessor(80) << endl;

    cout << endl << "Remove Test" << endl;
    cout << "Removing 20 (leaf)" << endl;
    bst.remove(20);
    bst.printInOrder();
    cout << endl;

    cout << "Removing 30 (one child)" << endl;
    bst.remove(30);
    bst.printInOrder();
    cout << endl;

    cout << "Removing 50 (two children)" << endl;
    bst.remove(50);
    bst.printInOrder();
    cout << endl;

    cout << endl << "Final Tree Traversals" << endl;
    cout << "Preorder: ";
    bst.printPreOrder();
    cout << endl;

    cout << "Inorder: ";
    bst.printInOrder();
    cout << endl;

    cout << "Postorder: ";
    bst.printPostOrder();
    cout << endl;

    return 0;
}