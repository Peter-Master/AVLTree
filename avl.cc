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

bool AVLTRee::Access(Element val) const {
    return = Access(val, root);
}

std::string AVLTree::PrintPreOrder( ) const {
    return PrintPreOrder(root);
}

std::string AVLTree::PrintInOrder( ) const {
    return PrintInOrder(root);
}
