#include <cassert>
#include <string>
#include "BST312.h"

using namespace std;

int main() {
    int one = 1;
    int two = 2;
    int three = 3;
    int four = 4;
    int five = 5;
    int six = 6;
    int seven = 7;
    int eight = 8;
    int nine = 9;
    vector<int> traversedElements;
    vector<string> traversedStrings;
    bool present = false;

    // Test default constructor and isEmpty()
    BST_312<int> tree1;
    assert(tree1.isEmpty());
    cout << "Binary tree #1 is empty." << endl;

    tree1.insertItem(five);
    tree1.insertItem(four);
    tree1.insertItem(two);
    tree1.insertItem(eight);
    tree1.insertItem(three);
    tree1.insertItem(six);
    tree1.insertItem(nine);
    
    // Testing in order traversal
    traversedElements = tree1.inOrderTraversal();
    cout << "InOrderTraversal of Binary Tree #1: ";
    for (vector<int>::iterator it = traversedElements.begin(); it != traversedElements.end(); it++) {
        cout << *it << " ";
    }
    cout << endl << endl;

    // Testing pre order traversal
    traversedElements = tree1.preOrderTraversal();
    cout << "preOrderTraversal of Binary Tree #1: ";
    for (vector<int>::iterator it = traversedElements.begin(); it != traversedElements.end(); it++) {
        cout << *it << " ";
    }
    cout << endl << endl;

    // Testing post order traversal
    traversedElements = tree1.postOrderTraversal();
    cout << "postOrderTraversal of Binary Tree #1: ";
    for (vector<int>::iterator it = traversedElements.begin(); it != traversedElements.end(); it++) {
        cout << *it << " ";
    }
    cout << endl << endl;

    // Testing countNodes()
    cout << "There are a total of " << tree1.countNodes() << " nodes in binary tree #1." << endl << endl; // should be 7 nodes


    // Testing isItemInTree() function
    present = tree1.isItemInTree(nine);
    if (present) {
        cout << "9 is an item in binary search tree #1." << endl;
    }

    present = tree1.isItemInTree(five);
    if (present) {
        cout << "5 is an item in binary search tree #1." << endl;
    }

    present = tree1.isItemInTree(seven);
    if (!present) {
        cout << "7 is NOT an item in binary search tree #1." << endl;
    }

    // Testing overriden copy constructor
    BST_312<int> tree2(tree1);

    traversedElements = tree2.inOrderTraversal();
    cout << "InOrderTraversal of Binary Tree #2 after copying from Tree #1: ";
    for (vector<int>::iterator it = traversedElements.begin(); it != traversedElements.end(); it++) {
        cout << *it << " ";
    }
    cout << endl << endl;

    // Testing deleteItem() function
    // Case 1 - deleting a leaf node
    tree1.deleteItem(three);

    traversedElements = tree1.inOrderTraversal();
    cout << "InOrderTraversal of Binary Tree #1 after deleting 3: ";
    for (vector<int>::iterator it = traversedElements.begin(); it != traversedElements.end(); it++) {
        cout << *it << " ";
    }
    cout << endl << endl;

    // Case 2 - deleting a node with 1 child
    tree1.deleteItem(four);

    traversedElements = tree1.inOrderTraversal();
    cout << "InOrderTraversal of Binary Tree #1 after deleting 4: ";
    for (vector<int>::iterator it = traversedElements.begin(); it != traversedElements.end(); it++) {
        cout << *it << " ";
    }
    cout << endl << endl;

    // Case 3 - deleting a node with 2 children
    tree1.deleteItem(eight);

    traversedElements = tree1.inOrderTraversal();
    cout << "InOrderTraversal of Binary Tree #1 after deleting 8: ";
    for (vector<int>::iterator it = traversedElements.begin(); it != traversedElements.end(); it++) {
        cout << *it << " ";
    }
    cout << endl << endl;


    // Make sure tree2 was not a shallow copy
    traversedElements = tree2.inOrderTraversal();
    cout << "Binary Tree #2 traversal (should be the same despite tree1 deletes): ";
    for (vector<int>::iterator it = traversedElements.begin(); it != traversedElements.end(); it++) {
        cout << *it << " ";
    }
    cout << endl << endl;

    // Testing makeEmpty() function
    tree2.makeEmpty();
    assert(tree2.isEmpty());
    cout << "makeEmpty() function is successful." << endl << endl;

    // Testing a binary tree with different data type
    BST_312<string> tree3;

    tree3.insertItem("mom");
    tree3.insertItem("poo");
    tree3.insertItem("quack");
    tree3.insertItem("andy");
    tree3.insertItem("cat");
    tree3.insertItem("fat");
    tree3.insertItem("soup");
    tree3.insertItem("ugh");
    tree3.insertItem("zap");

    // Testing in order traversal for tree3
    traversedStrings = tree3.inOrderTraversal();
    cout << "InOrderTraversal of Binary Tree #3: ";
    for (vector<string>::iterator it = traversedStrings.begin(); it != traversedStrings.end(); it++) {
        cout << *it << " ";
    }
    cout << endl << endl;

    // Testing countNodes()
    cout << "There are a total of " << tree3.countNodes() << " nodes in binary tree #3." << endl << endl; // should be 9 nodes

    // Testing deleteItem()
    tree3.deleteItem("fat");
    tree3.deleteItem("soup");

    // Testing in order traversal for tree3
    traversedStrings = tree3.inOrderTraversal();
    cout << "InOrderTraversal of Binary Tree #3 after removing fat and soup strings: ";
    for (vector<string>::iterator it = traversedStrings.begin(); it != traversedStrings.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}