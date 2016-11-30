// implements avl.h
// by Peter Master, 11/26/16

#include <iostream>
#include <sstream>
#include "assert.h"
#include "avl.h"

using namespace std;

AVLTree::AVLTree( ) : root(NULL) { }

AVLTree::~AVLTree( ) { makeEmpty(root); }

void AVLTree::Insert(Element val) {
    root = Insert(val, root);
}

void AVLTree::Delete(Element val) {
    root = Delete(val, root);
}

bool AVLTree::Access(Element val) const {
    return Access(val, root);
}

// CONSIDER USING A TRAVERSE FUNCTION THAT TAKES IN AN
// ARGUMENT FOR THE BELOW THREE FUNCTIONS
std::string AVLTree::PrintPreOrder( ) const {
    if (root) {
        std::string result = PrintPreOrder(root);
        result.pop_back( );
        return result;
    }
        //return root->elem + PrintPreOrder(root->left) +
        //        PrintPreOrder(root->right);
    return "";
}

std::string AVLTree::PrintInOrder( ) const {
    if (root) {
        std::string result = PrintInOrder(root);
        result.pop_back( );
        return result;
    }
        //return PrintInOrder(root->left) + root->elem +
        //        PrintPreOrder(root->right);
    return "";
}

void AVLTree::makeEmpty(BinaryNode *t) {
    // uses postorder traversal to delete all nodes
    if (!t)
        return;
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
    return;
}
// SEE COMMENT BEFORE PrintPreOrder FUNCTION IMPLEMENTATION

BinaryNode* AVLTree::getMin(BinaryNode *t) const {
    assert(t);
    while (t->left)
        t = t->left;
    return t;
}

// returns the height of left subtree subtracted by the height of right subtree
int AVLTree::getBalance(const BinaryNode *t) const {
    //if (!t)
    //    return 0;
    //if (t->left) {
    //    if (t->right)
    //        return t->left->height - t->right->height;
    //    return (t->left->height);
    //}
    //if (t->right)
    //    return -(t->right->height);
    //return 0;
    return getHeight(t->left) - getHeight(t->right);
}

// the height of a node is the number of levels in the node's
// subtree (for which each level has at least one node)
int AVLTree::getHeight(const BinaryNode *t) const {
    if (t)
        return t->height;
    return 0;
}

// the height of a node is the number of levels in the node's
// subtree (for which each level has at least one node)
int AVLTree::getHeightRecursively(const BinaryNode *t) const {
    if (t)
        return 1 + max(getHeightRecursively(t->left), getHeightRecursively(t->right));
    return 0;
}

BinaryNode* AVLTree::rotateLeft(BinaryNode *x) {
    BinaryNode *y = x->right;
    BinaryNode *t2 = y->left;

    // rotate
    y->left = x;
    x->right = t2;

    // update heights
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}

BinaryNode* AVLTree::rotateRight(BinaryNode *y) {
    BinaryNode *x = y->left;
    BinaryNode *t2 = x->right;

    // rotate
    x->right = y;
    y->left = t2;

    // update heights
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

BinaryNode* AVLTree::Insert(const Element e, BinaryNode *t) {
    // inserts element as leaf
    if (t == NULL) {
        t = new BinaryNode(e);
        return t;
    }
    else if (e > t->elem) {
        t->right = Insert(e, t->right);
    }
    else if (e < t->elem) {
            t->left = Insert(e, t->left);
    }
    else  //  e == t->elem
        return t;
    // update height
    t->height = 1 + max(getHeight(t->left), getHeight(t->right));
    // perform appropriate rotations
    int balance = getBalance(t);
    if (balance > 1) {
        if (e < t->left->elem) { // outside rotation (LL)
            return rotateRight(t);
        }
        else { // inside rotation (LR)
            t->left = rotateLeft(t->left);
            return rotateRight(t);
        }
    }
    else if (balance < -1) {
        if (e > t->right->elem) // outside rotation (RR)
            return rotateLeft(t);
        else { // inside rotation (RL)
            t->right = rotateRight(t->right);
            return rotateLeft(t);
        }
    }
    return t;
}

BinaryNode* AVLTree::Delete(const Element e, BinaryNode *t) {
    if (t == NULL)
        return t;
    else if (e > t->elem)
        t->right = Delete(e, t->right);
    else if (e < t->elem)
        t->left = Delete(e, t->left);
    else { //  e == t->elem
        BinaryNode *temp;
        if (t->left && t->right) { //  t has two children
            temp = getMin(t->right);
            t->elem = temp->elem;
            t->right = Delete(temp->elem, t->right);
        }
        else { //  t has zero or one children
            temp = t->left ? t->left : t->right;
            if (temp) // t has one child
                *t = *temp;
            else { // t has no children
                temp = t;
                t = NULL;
            }
        delete temp;
        if (!t) // if t had no children and is now NULL
            return t;
        }
    }

    // update height
    t->height = 1 + max(getHeight(t->left), getHeight(t->right));

    // perform appropriate rotations
    int balance = getBalance(t);

    if (balance > 1) {
        if (getBalance(t->left) >= 0) // outside rotation (LL)
            return rotateRight(t);
        else { // inside rotation (LR)
            t->left = rotateLeft(t->left);
            return rotateRight(t);
        }
    }
    else if (balance < -1) {
        if (getBalance(t->right) <= 0) // outside rotation (RR)
            return rotateLeft(t);
        else { // inside rotation (RL)
            t->right = rotateRight(t->right);
            return rotateLeft(t);
        }
    }

    return t;
}

bool AVLTree::Access(const Element e, const BinaryNode *t) const {
    if (t == NULL)
        return false;
    else if (e > t->elem) {
        Access(e, t->right);
    }
    else if (e < t->elem) {
        Access(e, t->left);
    }
    else //  (e == t->elem)
        return true;
}

std::string AVLTree::PrintPreOrder(const BinaryNode *t) const {
    if (t) {
        //return std::to_string(t->elem) + " " + PrintPreOrder(t->left) + PrintPreOrder(t->right);
        std::ostringstream tToString;
        tToString << t->elem;
        return tToString.str( ) + " " + PrintPreOrder(t->left) + PrintPreOrder(t->right);
    }
    return "";
}




std::string AVLTree::PrintInOrder(const BinaryNode *t) const{
    if (t) {
         //return PrintInOrder(t->left) + std::to_string(t->elem) + " " + PrintInOrder(t->right);
        std::ostringstream tToString;
        tToString << t->elem;
        return PrintInOrder(t->left) + tToString.str( ) + " " + PrintInOrder(t->right);
    }
    return "";
}
