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
    cout << "start of nonrecursive printpreorder" << endl;
    if (root) {
        cout << "1" << endl;
        std::string result = PrintPreOrder(root);
        cout << "result with extra space: " << result << endl;
        result.pop_back( );
        return result;
    }
    cout << " SSHOULD ____NOT_____ GET HERE!!!" << endl;
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
    // STUB
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
    cout << "HEIGHTS: ";
    cout << getHeight(t);
    cout << " ";
    cout << getHeight(t->left);
    cout << " ";
    cout << getHeight(t->right) << endl;
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
    cout << "left rotate1" << endl;
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    cout << "left rotate2" << endl;
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    cout << "left rotate3" << endl;

    return y;
}

BinaryNode* AVLTree::rotateRight(BinaryNode *y) {
    BinaryNode *x = y->left;
    BinaryNode *t2 = x->right;

    // rotate
    x->right = y;
    y->left = t2;

    // update heights
    cout << "right rotate1" << endl;
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    cout << "right rotate2" << endl;
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    cout << "right rotate3" << endl;

    cout << "the root is now " << root->elem << endl;
    return x;
}

BinaryNode* AVLTree::Insert(const Element e, BinaryNode *t) {
    cout << "Beginning of Recursive Insert" << endl;
    // inserts element as leaf
    if (t == NULL) {
        t = new BinaryNode(e);
        return t;
    }
    else if (e > t->elem) {
        cout << "element goes to right" << endl;
        t->right = Insert(e, t->right);
        cout << "element went to the right, t is " << t->elem << " and t->right now equals " << t->right->elem << endl;
    }
    else if (e < t->elem) {
        cout << "element goes to left" << endl;
        t->left = Insert(e, t->left);
        cout << "element went to the left, t is " << t->elem << " and t->left now equals " << t->left->elem << endl;
    }
    else  //  e == t->elem
        return t;
    cout << "222" << endl;
    // update height
    t->height = 1 + max(getHeight(t->left), getHeight(t->right));
    cout << "T->HEIGHT " << t->height << endl;
    cout << "333" << endl;
    // perform appropriate rotations
    int balance = getBalance(t);
    cout << "444" << endl;
    if (balance > 1) {
        cout << "555" << endl;
        cout << "t->elem " << t->elem << " t->left->elem " << t->left->elem << endl;
        if (e < t->left->elem) { // outside rotation (LL)
            cout << "555.110 rotating right with t: " << t->elem << endl;
            return rotateRight(t);
        }
        else { // inside rotation (LR)
            cout << "555.112" << endl;
            t->left = rotateLeft(t->left);
            cout << "555.113" << endl;
            return rotateRight(t);
        }
    }
    else if (balance < -1) {
        cout << "666" << endl;
        if (e > t->right->elem) // outside rotation (RR)
            return rotateLeft(t);
        else { // inside rotation (RL)
            t->right = rotateRight(t->right);
            return rotateLeft(t);
        }
    }
    cout << "777" << endl;
    cout << root->elem << endl;
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
    cout << "Start of Recursive PrintPreOrder" << endl;
    if (t) {
        //return std::to_string(t->elem) + " " + PrintPreOrder(t->left) + PrintPreOrder(t->right);
        cout << "hello again" << endl;
        std::ostringstream tToString;
        tToString << t->elem;
        cout << tToString.str( ) << ": left-" << (t->left ? t->left->elem : 0) << " right-" << (t->right ? t->right->elem : 0) << endl;
        return tToString.str( ) + " " + PrintPreOrder(t->left) + PrintPreOrder(t->right);
    }
    return "";
}




std::string AVLTree::PrintInOrder(const BinaryNode *t) const{
    cout << "Start of Recursive PrintInOrder" << endl;
    if (t) {
         //return PrintInOrder(t->left) + std::to_string(t->elem) + " " + PrintInOrder(t->right);
        std::ostringstream tToString;
        tToString << t->elem;
        cout << tToString.str( ) << ": left-" << (t->left ? t->left->elem : 0) << " right-" << (t->right ? t->right->elem : 0) << endl;
        return PrintInOrder(t->left) + tToString.str( ) + " " + PrintInOrder(t->right);
    }
    return "";
}
