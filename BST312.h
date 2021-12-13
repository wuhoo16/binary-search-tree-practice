
/*  BST312.h
    EE312 Fall 2019
    Andy Wu
    11/14/19

  a simple implementation of a binary search tree


*/

#ifndef BST_312_H
#define BST_312_H

#include <cstdlib>  // Provides size_t
#include <iostream>
#include <vector>

using namespace std;

template<class ItemType>
class BST_312 {
public:

    BST_312();

    //Copy constructor
    BST_312(const BST_312 & src);

    ~BST_312();

/****************************
makeEmpty

Function: Removes all the items from the BST.
Preconditions: BST has been initialized
Postconditions: All the items have been removed
*****************************/
    void makeEmpty();

/****************************
isEmpty

Function: Checks to see if there are any items in the BST.
Preconditions: BST has been initialized
Postconditions: Returns true if there are no items in the BST, else false.
*****************************/
    bool isEmpty() const;

/****************************
isFull

Function: Determines if you have any more room to add items to the BST
Preconditions: BST has been initialized
Postconditions: Returns true if there is no more room to add items, else false
*****************************/
    bool isFull() const;

/****************************
insertItem

Function: Adds newItem to the BST.
Preconditions: BST has been initialized and is not full.
Postconditions: newItem is in the proper position for a BST.
*****************************/
    void insertItem(const ItemType &);

/****************************
deleteItem

Function: Removes target from BST.
Preconditions: BST has been initialized.
Postconditions: If found, element has been removed from BST.
*****************************/
    void deleteItem(const ItemType& newItem);

/****************************
countNodes

Function: Counts the number of nodes in the BST
Preconditions: BST has been initialized.
Postconditions: returns the number of nodes in the BST
*****************************/
    int countNodes();

/****************************
preOrderTraversal

Function: Returns the preOder (Node, Left, Right) as a vector of ItemTypes
Preconditions: BST has been initialized.
Postconditions: none
*****************************/
    vector<ItemType> preOrderTraversal();

/****************************
inOrderTraversal

Function: Returns the inOder (Left, Node, Right) as a vector of ItemTypes
Preconditions: BST has been initialized.
Postconditions: none
*****************************/
    vector<ItemType> inOrderTraversal();

/****************************
postOrderTraversal

Function: returns the postOder (Left, Right, Node) as a vector of ItemTypes
Preconditions: BST has been initialized.
Postconditions: none
*****************************/
    vector<ItemType> postOrderTraversal();

/********************
 isItemInTree

Function: Determines if a given Item is in tree.
Preconditions: BST has been initialized.
Postconditions: none
*****************************/

    bool isItemInTree(const ItemType& item);


private:
    struct TreeNode {
        ItemType data;
        TreeNode *left;
        TreeNode *right;
    };

    TreeNode * root;


    void insertItem(TreeNode*& t, const ItemType& newItem);
    void inOrderTraversal(TreeNode* t,vector<ItemType>& result) const;
    int countNodes(TreeNode* t) const;
    void deleteNode(TreeNode*& node);
    void makeEmpty(TreeNode*& t);
    void deleteItem(TreeNode*& t, const ItemType& newItem);
    void getPredecessor(TreeNode* t, ItemType& data);
    void preOrderTraversal(TreeNode* t,vector<ItemType>& result) const;
    void postOrderTraversal(TreeNode* t,vector<ItemType>& result) const;
    void copyTree(TreeNode*& copy, const TreeNode *originalTree);

};

/*******************************
//Function implementations
********************************/

// default constructor - set root node to NULL
template<class ItemType>
BST_312<ItemType>::BST_312 ()
{
    root = NULL;
}

// copy constructor
template<class ItemType>
BST_312<ItemType>::BST_312(const BST_312 & src)
{
    copyTree(root, src.root);
}

// deconstructor
template<class ItemType>
BST_312<ItemType>::~BST_312()
{
    makeEmpty();

}

// private copyTree function 
// called in overridden copy constructor
template<class ItemType>
void BST_312<ItemType>::copyTree(TreeNode*& copy, const TreeNode* originalTree)
{
    if (originalTree == NULL)
        copy = NULL;
    else
    {
        copy = new TreeNode;
        copy->data = originalTree->data;

        copyTree(copy->left, originalTree->left);
        copyTree(copy->right, originalTree->right);
    }
}


template<class ItemType>
void BST_312 <ItemType>::deleteNode(TreeNode*& t)
{
    ItemType info;
    TreeNode *tempPtr;

    tempPtr = t;

    if (t->left == NULL) // if to-be deleted node has no left child, replace it with right child
    {
        t = t->right;
        delete tempPtr;
    }
    else if (t->right == NULL) // if to-be deleted node has no right child, replace it with left child
    {
        t = t->left;
        delete tempPtr;
    }
    else // if to-be deleted node has 2 children... replace with max value of the left subtree and delete the predecessor node
    {
        getPredecessor(t->left, info);
        t->data = info;
        deleteItem(t->left, info);
    }
}


// Private helper function for deleteNode()
// Find largest data value in left subtree
template<class ItemType>
void BST_312 <ItemType>::getPredecessor(TreeNode* t, ItemType& data)
{

    while (t->right != NULL)
        t = t->right;

    data = t->data;

}


// private helper function for deleteNode
template<class ItemType>
void BST_312 <ItemType>::deleteItem(TreeNode*& t, const ItemType& newItem)
{
    if (t == NULL)
        return;
    else if (newItem < t->data)
        deleteItem(t->left, newItem);
    else if (newItem > t->data)
        deleteItem(t->right, newItem);
    else
        deleteNode(t);
}

// public interface delete function
// simply calls the private deleteItem() with the pointer to root as an extra parameter
template<class ItemType>
void BST_312 <ItemType>::deleteItem(const ItemType& newItem)
{
    deleteItem(root, newItem);

}

// private makeEmpty() function
template<class ItemType>
void BST_312 <ItemType>::makeEmpty(TreeNode*& t)
{
    if (t == NULL) {
        return;
    }

    if (t -> left != NULL) {
        makeEmpty(t -> left);
    }
    else if (t -> right != NULL) {
        makeEmpty(t -> right);
    }
    else { // t points to a leaf node with no children nodes
        deleteNode(t);
    }
    return;
}

template<class ItemType>
void BST_312 <ItemType>::makeEmpty()
{
    makeEmpty(root);
    root = NULL;
}

template<class ItemType>
bool BST_312 <ItemType>::isEmpty() const
{
    return root == NULL;
}



template<class ItemType>
bool BST_312 <ItemType>::isFull() const
{
    try
    {
        TreeNode *temp = new TreeNode;
        delete temp;
        return false;
    }
    catch (std::bad_alloc)
    {
        return true;
    }

}

// private recursive insertItem() function
template<class ItemType>
void BST_312 <ItemType>::insertItem(TreeNode*& t, const ItemType& newItem)
{
    if (t == NULL) {
        TreeNode* newNode = new TreeNode;
        t = newNode;
        t -> data = newItem;
        t -> left = NULL;
        t -> right = NULL;
        return;
    }

    if (newItem < t -> data) {
        insertItem(t -> left, newItem);
    }
    else if (newItem > t -> data) {
        insertItem(t -> right, newItem);
    }
}

template<class ItemType>
void BST_312 <ItemType>::insertItem(const ItemType& newItem)
{
    insertItem(root, newItem);
    return;
}


template<class ItemType>
int BST_312 <ItemType>::countNodes(TreeNode* t) const
{
        if (t == NULL) { // Empty tree has 0 nodes
            return 0;
        }
        else {
            return (1 + countNodes(t -> left) + countNodes(t -> right));
        }
}

template<class ItemType>
int BST_312 <ItemType>::countNodes()
{
        return countNodes(root);
}


template<class ItemType>
void BST_312 <ItemType>::preOrderTraversal(TreeNode* t,vector<ItemType>& result) const
{
    if (t == NULL) {
        return;
    }

    result.push_back(t -> data);
    preOrderTraversal(t -> left, result);
    preOrderTraversal(t -> right, result);
    return;
}

template<class ItemType>
vector<ItemType> BST_312 <ItemType>::preOrderTraversal()
{
    vector<ItemType> resultOrder;
    preOrderTraversal(root, resultOrder);
    return resultOrder;
}


template<class ItemType>
void BST_312 <ItemType>::inOrderTraversal(TreeNode* t,vector<ItemType>& result) const
{
    if (t == NULL) {
        return;
    }

    inOrderTraversal(t -> left, result);
    result.push_back(t -> data);
    inOrderTraversal(t -> right, result);
    return;
}

template<class ItemType>
vector<ItemType> BST_312 <ItemType>::inOrderTraversal()
{
    vector<ItemType> resultOrder;
    inOrderTraversal(root, resultOrder);
    return resultOrder;
}


template<class ItemType>
void BST_312 <ItemType>::postOrderTraversal(TreeNode* t,vector<ItemType>& result) const
{
    if (t == NULL) {
        return;
    }

    postOrderTraversal(t -> left, result);
    postOrderTraversal(t -> right, result);
    result.push_back(t -> data);
}

template<class ItemType>
vector<ItemType> BST_312 <ItemType>::postOrderTraversal()
{
    vector<ItemType> resultOrder;
    postOrderTraversal(root, resultOrder);
    return resultOrder;
}


// public function for searching item in binary search tree
// Time complexity: O(log n)
// returns boolean true/false
template<class ItemType>
bool BST_312 <ItemType>::isItemInTree(const ItemType& item)
{
    if (root == NULL) {
        return false;
    }
    TreeNode* temp = root;
    while (temp != NULL) {
        if (item == temp -> data) {
            return true;
        }
        else if (item < temp -> data) {
            temp = temp -> left;
        }
        else { // item is larger than node data so update pointer to right child
            temp = temp -> right;
        }
    }

    return false; // if NULL is ever reached, that means the item is NOT in the binary search tree

}
#endif