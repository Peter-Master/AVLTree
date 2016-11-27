// implements an AVL Tree with unique elements
// by Peter Master, 11/26/16

#ifndef AVL_H_
#define AVL_H_
#define Element int32_t

#include <string>

class AVLTree
{
public:
    AVLTree ();
    virtual ~AVLTree ();
    void Insert (const Element val);
    // chooses smallest node on the right subtree when deleting a node with two children
    void Delete (const Element val);
    bool Access (const Element val);
    std::string PrintPreOrder () const;
    std::string PrintInOrder () const;

private:
    struct BinaryNode {
        Element elem;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode(): elem(0), left(NULL), right(NULL) {}
        BinaryNode(const Element &e, BinaryNode *lt, BinaryNode *rt): elem(e), left(lt), right(rt) {}
    } *root;

    void makeEmpty(BinaryNode *t);
    BinaryNode* getMin(BinaryNode *t) const;
	void Insert(const Element e, BinaryNode * & t);
	void Delete(const Element e, BinaryNode * & t);
	bool Access(const Element e, BinaryNode * & t) const;
	std::string PrintPreOrder(BinaryNode * & t) const;
	std::string PrintInOrder(BinaryNode * & t) const;
};

#endif /* end of include guard: AVL_H_ */
