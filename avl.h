// implements an AVL Tree with unique elements
// by Peter Master, 11/26/16

#ifndef AVL_H_
#define AVL_H_
#define Element int32_t

#include <string>

struct BinaryNode {
        Element elem;
        BinaryNode *left;
        BinaryNode *right;
        // the height of a node is the number of levels in the node's
        // subtree (for which each level has at least one node)
        int height;

        BinaryNode(const Element &e) :
            elem(e), left(NULL), right(NULL), height(1) { }
};

class AVLTree
{
public:
    AVLTree ();
    virtual ~AVLTree ();
    void Insert (const Element val);
    // chooses smallest node on the right subtree
    // when deleting a node with two children
    void Delete (const Element val);
    bool Access (const Element val) const;
    std::string PrintPreOrder () const;
    std::string PrintInOrder () const;

private:
    //struct BinaryNode {
    //    Element elem;
    //    BinaryNode *left;
    //    BinaryNode *right;
    //    // the height of a node is the number of levels in the node's
    //    // subtree (for which each level has at least one node)
    //    int height;

    //    BinaryNode(const Element &e) :
    //        elem(e), left(NULL), right(NULL), height(1) { }
    //}
    BinaryNode *root;

    void makeEmpty(BinaryNode *t);
    BinaryNode* getMin(BinaryNode *t) const;
    int getBalance(const BinaryNode *t) const;
    int getHeight(const BinaryNode *t) const;
    int getHeightRecursively(const BinaryNode *t) const;
    BinaryNode* rotateLeft(BinaryNode *x);
    BinaryNode* rotateRight(BinaryNode *y);
	BinaryNode* Insert(const Element e, BinaryNode *t);
	BinaryNode* Delete(const Element e, BinaryNode *t);
	bool Access(const Element e, const BinaryNode *t) const;
	std::string PrintPreOrder(const BinaryNode *t) const;
	std::string PrintInOrder(const BinaryNode *t) const;
};

#endif /* end of include guard: AVL_H_ */
