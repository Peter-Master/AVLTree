// implements avl.h
// by Peter Master, 11/26/16

#include <iostream>
#include <sstream>
#include "avl.h"

using namespace std;

AVLTree::AVLTree( ) : root(NULL) { }

AVLTree::~AVLTree( ) { makeEmpty(root); }

void AVLTree::Insert(Element val) {
    Insert(val, root);
}

void AVLTree::Delete(Element val) {
    Delete(val, root);
}

bool AVLTree::Access(Element val) const {
    return = Access(val, root);
}

// CONSIDER USING A TRAVERSE FUNCTION THAT TAKES IN AN
// ARGUMENT FOR THE BELOW FOUR FUNCTIONS
std::string AVLTree::PrintPreOrder( ) const {
    return PrintPreOrder(root);
}

std::string AVLTree::PrintInOrder( ) const {
    return PrintInOrder(root);
}

void AVLTree::makeEmpty( ) {
    // STUB
}

BinaryNode* AVLTree::getMin(BinaryNode *t) const {
    // STUB
    return root;
}
// SEE ABOVE MESSAGE

void AVLTree::Insert(const Element e, BinaryNode * & t) {
    if (t == NULL)
        t = new BinaryNode(e);
    else if (e > t->elem) {
        Insert(e, t->right);
    }
    else if (e < t->elem) {
        Insert(e, t->left);
    }
    else  //  e == t->elem
        return;
    // ***ROTATE***
}

void AVLTree::Delete(const Element e, BinaryNode * & t) {
    if (t == NULL)
        return false;
    else if (e > t->elem)
        Delete(e, t->right);
    else if (e < t->elem)
        Delete(e, t->left);
    else { //  e == t->elem
        BinaryNode *temp;
        if (t->left && t->right) { //  t has two children
            temp = getMin(t->right);
            t->elem = temp->elem;
        }
        else //  t has zero or one children
            t = t->left ? t->left : t->right;
        delete temp;

    }
    // ***ROTATE*** once or twice
    return;
}

bool AVLTree::Access(const Element e, BinaryNode * & t) const {
    if (t == NULL)
        return false;
    else if (e > t->elem) {
        Access(e, t->right);
    }
    else if (e < t->elem) {
        Access(e, t->left);
    }
    else { //  (e == t->elem)
        return true;
}
