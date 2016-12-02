#include <iostream>
#include <fstream>

#include "gtest/gtest.h"

#include "avl.h"

#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

class BinarySearchTree
{
public:
  BinarySearchTree(): root() {}
  ~BinarySearchTree() { makeEmpty(root);}

  bool Insert(const Element e);
  bool Access(const Element e);
  bool Delete(const Element e);

private:

  BinaryNode *root;

  BinaryNode * findMin(BinaryNode *t);
  void makeEmpty(BinaryNode * & t);
  bool Insert(const Element e, BinaryNode * & t);
  bool Access(const Element e, BinaryNode * & t);
  bool Delete(const Element e, BinaryNode * & t);
};


void runTimeTests() {
  BinarySearchTree bst;
  AVLTree avltree;
  int bstTimes[3][3];
  int avltreeTimes[3][3];
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      bstTimes[i][j] = 0;
      avltreeTimes[i][j] = 0;
    }
  high_resolution_clock::time_point t1;
  high_resolution_clock::time_point t2;

  int rSmallArray1[50000];
  int rSmallArray2[50000];
  int rSmallArray3[50000];
  for (int i = 0; i < 50000; i++) {
    rSmallArray1[i] = i;
    rSmallArray2[i] = i;
    rSmallArray3[i] = i;
  }
  int rMedArray1[50000];
  int rMedArray2[50000];
  int rMedArray3[50000];
  for (int i = 0; i < 50000; i++) {
    rMedArray1[i] = i;
    rMedArray2[i] = i;
    rMedArray3[i] = i;
  }
  int rBigArray1[50000];
  int rBigArray2[50000];
  int rBigArray3[50000];
  for (int i = 0; i < 50000; i++) {
    rBigArray1[i] = i;
    rBigArray2[i] = i;
    rBigArray3[i] = i;
  }
  random_shuffle((rSmallArray1), end(rSmallArray1));
  random_shuffle((rSmallArray2), end(rSmallArray2));
  random_shuffle((rSmallArray3), end(rSmallArray3));
  random_shuffle((rMedArray1), end(rMedArray1));
  random_shuffle((rMedArray2), end(rMedArray2));
  random_shuffle((rMedArray3), end(rMedArray3));
  random_shuffle((rBigArray1), end(rBigArray1));
  random_shuffle((rBigArray2), end(rBigArray2));
  random_shuffle((rBigArray3), end(rBigArray3));
  for (int i =0; i < 100; i++)
    cout << rBigArray2[i] << " ";
















  t1 = high_resolution_clock::now();
  for (int j = 100; j > 0; j--) {
  for (int i = 0; i < 1000; i++)
    bst.Insert(i);
  for (int i = 0; i < 1000; i++)
    bst.Access(i);
  for (int i = 0; i < 1000; i++)
    bst.Delete(i);
}
  t2 = high_resolution_clock::now();
  bstTimes[0][0] = duration_cast<microseconds>(t2-t1).count()/100;


  t1 = high_resolution_clock::now();
  for (int j = 100; j > 0; j--) {
  for (int i = 0; i < 1000; i++)
    avltree.Insert(i);
  for (int i = 0; i < 1000; i++)
    avltree.Access(i);
  for (int i = 0; i < 1000; i++)
    avltree.Delete(i);
}
  t2 = high_resolution_clock::now();
  avltreeTimes[0][0] = duration_cast<microseconds>(t2-t1).count()/100;


    t1 = high_resolution_clock::now();
  for (int i = 0; i < 10000; i++)
    bst.Insert(i);
  for (int i = 0; i < 10000; i++)
    bst.Access(i);
  for (int i = 0; i < 10000; i++)
    bst.Delete(i);

  t2 = high_resolution_clock::now();
  bstTimes[0][1] = duration_cast<microseconds>(t2-t1).count();


  t1 = high_resolution_clock::now();
  for (int i = 0; i < 10000; i++)
    avltree.Insert(i);
  for (int i = 0; i < 10000; i++)
    avltree.Access(i);
  for (int i = 0; i < 10000; i++)
    avltree.Delete(i);
  t2 = high_resolution_clock::now();
  avltreeTimes[0][1] = duration_cast<microseconds>(t2-t1).count();


  t1 = high_resolution_clock::now();
  for (int i = 0; i < 50000; i++)
    bst.Insert(i);
  for (int i = 0; i < 50000; i++)
    bst.Access(i);
  for (int i = 0; i < 50000; i++)
    bst.Delete(i);
  
  t2 = high_resolution_clock::now();
  bstTimes[0][2] = duration_cast<microseconds>(t2-t1).count();


  t1 = high_resolution_clock::now();
  for (int i = 0; i < 50000; i++)
    avltree.Insert(i);
  for (int i = 0; i < 50000; i++)
    avltree.Access(i);
  for (int i = 0; i < 50000; i++)
    avltree.Delete(i);
  t2 = high_resolution_clock::now();
  avltreeTimes[0][2] = duration_cast<microseconds>(t2-t1).count();
























  t1 = high_resolution_clock::now();
  for (int j = 100; j > 0; j--) {
  for (int i = 0; i < 1000; i++)
    bst.Insert(i);
  for (int i = 999; i >= 0; i--)
    bst.Access(i);
  for (int i = 999; i >= 0; i--)
    bst.Delete(i);
}
  t2 = high_resolution_clock::now();
  bstTimes[1][0] = duration_cast<microseconds>(t2-t1).count()/100;


  t1 = high_resolution_clock::now();
  for (int j = 100; j > 0; j--) {
  for (int i = 0; i < 1000; i++)
    avltree.Insert(i);
  for (int i = 999; i >= 0; i--)
    avltree.Access(i);
  for (int i = 999; i >= 0; i--)
    avltree.Delete(i);
}
  t2 = high_resolution_clock::now();
  avltreeTimes[1][0] = duration_cast<microseconds>(t2-t1).count()/100;


    t1 = high_resolution_clock::now();
  for (int i = 0; i < 10000; i++)
    bst.Insert(i);
  for (int i = 9999; i >= 0; i--)
    bst.Access(i);
  for (int i = 9999; i >= 0; i--)
    bst.Delete(i);

  t2 = high_resolution_clock::now();
  bstTimes[1][1] = duration_cast<microseconds>(t2-t1).count();


  t1 = high_resolution_clock::now();
  for (int i = 0; i < 10000; i++)
    avltree.Insert(i);
  for (int i = 9999; i >= 0; i--)
    avltree.Access(i);
  for (int i = 9999; i >= 0; i--)
    avltree.Delete(i);
  t2 = high_resolution_clock::now();
  avltreeTimes[1][1] = duration_cast<microseconds>(t2-t1).count();


  t1 = high_resolution_clock::now();
  for (int i = 0; i < 50000; i++)
    bst.Insert(i);
  for (int i = 49999; i >= 0; i--)
    bst.Access(i);
  for (int i = 49999; i >= 0; i--)
    bst.Delete(i);
  
  t2 = high_resolution_clock::now();
  bstTimes[1][2] = duration_cast<microseconds>(t2-t1).count();


  t1 = high_resolution_clock::now();
  for (int i = 0; i < 50000; i++)
    avltree.Insert(i);
  for (int i = 49999; i >= 0; i--)
    avltree.Access(i);
  for (int i = 49999; i >= 0; i--)
    avltree.Delete(i);
  t2 = high_resolution_clock::now();
  avltreeTimes[1][2] = duration_cast<microseconds>(t2-t1).count();



  












  t1 = high_resolution_clock::now();
  for (int j = 100; j > 0; j--) {
  for (int i = 0; i < 1000; i++)
    bst.Insert(rSmallArray1[i]);
  for (int i = 0; i < 1000; i++)
    bst.Access(rSmallArray2[i]);
  for (int i = 0; i < 1000; i++)
    bst.Delete(rSmallArray3[i]);
}
  t2 = high_resolution_clock::now();
  bstTimes[2][0] = duration_cast<microseconds>(t2-t1).count()/100;


  t1 = high_resolution_clock::now();
  for (int j = 100; j > 0; j--) {
  for (int i = 0; i < 1000; i++)
    avltree.Insert(rSmallArray1[i]);
  for (int i = 0; i < 1000; i++)
    avltree.Access(rSmallArray2[i]);
  for (int i = 0; i < 1000; i++)
    avltree.Delete(rSmallArray3[i]);
}
  t2 = high_resolution_clock::now();
  avltreeTimes[2][0] = duration_cast<microseconds>(t2-t1).count()/100;


    t1 = high_resolution_clock::now();
  for (int i = 0; i < 10000; i++)
    bst.Insert(rMedArray1[i]);
  for (int i = 0; i < 10000; i++)
    bst.Access(rMedArray2[i]);
  for (int i = 0; i < 10000; i++)
    bst.Delete(rMedArray3[i]);

  t2 = high_resolution_clock::now();
  bstTimes[2][1] = duration_cast<microseconds>(t2-t1).count();


  t1 = high_resolution_clock::now();
  for (int i = 0; i < 10000; i++)
    avltree.Insert(rMedArray1[i]);
  for (int i = 0; i < 10000; i++)
    avltree.Access(rMedArray2[i]);
  for (int i = 0; i < 10000; i++)
    avltree.Delete(rMedArray3[i]);
  t2 = high_resolution_clock::now();
  avltreeTimes[2][1] = duration_cast<microseconds>(t2-t1).count();


  t1 = high_resolution_clock::now();
  for (int i = 0; i < 50000; i++)
    bst.Insert(rBigArray1[i]);
  for (int i = 0; i < 50000; i++)
    bst.Access(rBigArray2[i]);
  for (int i = 0; i < 50000; i++)
    bst.Delete(rBigArray3[i]);
  
  t2 = high_resolution_clock::now();
  bstTimes[2][2] = duration_cast<microseconds>(t2-t1).count();


  t1 = high_resolution_clock::now();
  for (int i = 0; i < 50000; i++)
    avltree.Insert(rBigArray1[i]);
  for (int i = 0; i < 50000; i++)
    avltree.Access(rBigArray2[i]);
  for (int i = 0; i < 50000; i++)
    avltree.Delete(rBigArray3[i]);
  t2 = high_resolution_clock::now();
  avltreeTimes[2][2] = duration_cast<microseconds>(t2-t1).count();









  cout << endl << endl << "############TIMES############" << endl;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      cout << "test " << i << "-" << j << ": BST-" << bstTimes[i][j] << " and AVLTree-" << avltreeTimes[i][j] << endl;
}


TEST (AVLTree, Test1) {
  AVLTree avltree;

  avltree.Insert(200);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "200");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "200");

  avltree.Insert(300);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "200 300");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "200 300");

  avltree.Insert(500);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "300 200 500");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "200 300 500");

  avltree.Insert(100);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "300 200 100 500");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "100 200 300 500");

  avltree.Insert(150);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "300 150 100 200 500");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "100 150 200 300 500");

  avltree.Insert(400);
  EXPECT_STREQ (avltree.Access(150) ? "t" : "f", "t");
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "300 150 100 200 500 400");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "100 150 200 300 400 500");

  avltree.Insert(250);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "300 150 100 200 250 500 400");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "100 150 200 250 300 400 500");

  avltree.Insert(275);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "300 150 100 250 200 275 500 400");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "100 150 200 250 275 300 400 500");
  
  avltree.Insert(276);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "300 250 150 100 200 275 276 500 400");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "100 150 200 250 275 276 300 400 500");

  avltree.Insert(277);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "300 250 150 100 200 276 275 277 500 400");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "100 150 200 250 275 276 277 300 400 500");

  avltree.Insert(278);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "276 250 150 100 200 275 300 277 278 500 400");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "100 150 200 250 275 276 277 278 300 400 500");

  EXPECT_STREQ (avltree.Access(277) ? "t" : "f", "t");
  EXPECT_STREQ (avltree.Access(277) ? "t" : "f", "t");
  EXPECT_STREQ (avltree.Access(300) ? "t" : "f", "t");
  EXPECT_STREQ (avltree.Access(152) ? "t" : "f", "f");

  avltree.Delete(250);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "276 150 100 275 200 300 277 278 500 400");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "100 150 200 275 276 277 278 300 400 500");

  avltree.Delete(150);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "276 200 100 275 300 277 278 500 400");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "100 200 275 276 277 278 300 400 500");

  avltree.Delete(200);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "276 275 100 300 277 278 500 400");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "100 275 276 277 278 300 400 500");

  avltree.Delete(275);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "300 276 100 277 278 500 400");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "100 276 277 278 300 400 500");

  avltree.Delete(300);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "277 276 100 400 278 500");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "100 276 277 278 400 500");

  avltree.Insert(50);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "277 100 50 276 400 278 500");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "50 100 276 277 278 400 500");

  avltree.Insert(510);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "277 100 50 276 400 278 500 510");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "50 100 276 277 278 400 500 510");

  avltree.Insert(490);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "277 100 50 276 400 278 500 490 510");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "50 100 276 277 278 400 490 500 510");

  avltree.Insert(480);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "277 100 50 276 490 400 278 480 500 510");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "50 100 276 277 278 400 480 490 500 510");

  avltree.Insert(520);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "277 100 50 276 490 400 278 480 510 500 520");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "50 100 276 277 278 400 480 490 500 510 520");

  avltree.Insert(550);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "490 277 100 50 276 400 278 480 510 500 520 550");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "50 100 276 277 278 400 480 490 500 510 520 550");

  avltree.Delete(490);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "500 277 100 50 276 400 278 480 520 510 550");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "50 100 276 277 278 400 480 500 510 520 550");

  avltree.Delete(500);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "510 277 100 50 276 400 278 480 520 550");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "50 100 276 277 278 400 480 510 520 550");

  avltree.Delete(510);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "277 100 50 276 520 400 278 480 550");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "50 100 276 277 278 400 480 520 550");

  avltree.Delete(277);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "278 100 50 276 520 400 480 550");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "50 100 276 278 400 480 520 550");

  avltree.Insert(300);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "278 100 50 276 520 400 300 480 550");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "50 100 276 278 300 400 480 520 550");


  EXPECT_STREQ (avltree.Access(276) ? "t" : "f", "t");
  EXPECT_STREQ (avltree.Access(250) ? "t" : "f", "f");
  EXPECT_STREQ (avltree.Access(278) ? "t" : "f", "t");

  /*

  //for (int i = 0; i < 23; i++)
  //  if (!avltree.COUNTER[i]) cout << i << " is false" << endl;

  // the below has tested correct
  ifstream ifile;
  ofstream ofile;
  int N = 10000;
  ofile.open("s10000inorder.txt");
  AVLTree avltree2;
  ifile.open("s10000.txt");
  int next;
  for (int i = 0; i < N; i++) {
    ifile >> next;
    avltree2.Insert(next);
    if (i == 5000)
      avltree2.Insert(3501);
  }
  ifile.close();
  ifile.open("s10000.txt");
  for (int i = 0; i < N; i++) {
    ifile >> next;
    if (i % 3 == 0)
      avltree2.Delete(next);
    if (i == 5000) {
      avltree2.Delete(3501);
      avltree2.Delete(50);
      avltree2.Delete(550);
      avltree2.Delete(341);
    }
  }
  ofile << avltree2.PrintInOrder();
  ofile.close();
  ofile.open("s10000preorder.txt");
  ofile << avltree2.PrintPreOrder();
  ofile.close();

  //cout << "anything false in final test?" << endl  << "if no following blanks then everything is true\n{" << endl;
  for (int i = 0; i < 23; i++)
    if (!avltree2.COUNTER[i]) cout << i << " is false" << endl;
  //cout << "  }\n";

  */

  AVLTree avltree3;

  avltree3.Delete(10);
  EXPECT_STREQ (avltree3.PrintPreOrder().c_str(), "");
  EXPECT_STREQ (avltree3.PrintInOrder().c_str(), "");

  avltree3.Delete(200);
  EXPECT_STREQ (avltree3.PrintPreOrder().c_str(), "");
  EXPECT_STREQ (avltree3.PrintInOrder().c_str(), "");

  avltree3.Insert(150);
  EXPECT_STREQ (avltree3.PrintPreOrder().c_str(), "150");
  EXPECT_STREQ (avltree3.PrintInOrder().c_str(), "150");

  avltree3.Delete(150);
  EXPECT_STREQ (avltree3.PrintPreOrder().c_str(), "");
  EXPECT_STREQ (avltree3.PrintInOrder().c_str(), "");

  avltree3.Delete(150);
  EXPECT_STREQ (avltree3.PrintPreOrder().c_str(), "");
  EXPECT_STREQ (avltree3.PrintInOrder().c_str(), "");

  EXPECT_STREQ (avltree3.Access(275) ? "t" : "f", "f");
  EXPECT_STREQ (avltree3.Access(250) ? "t" : "f", "f");
  EXPECT_STREQ (avltree3.Access(150) ? "t" : "f", "f");

}

int main(int argc, char *argv[])
{
  ::testing::InitGoogleTest (&argc, argv);
  int useless_var = RUN_ALL_TESTS ();

  runTimeTests();
  return 0;
}





////////////////////////
// BST IMPLEMENTATION //
////////////////////////


// Public Methods

bool BinarySearchTree::Insert(const Element e)
{
  return Insert(e, root);
}

bool BinarySearchTree::Access(const Element e)
{
  return Access(e, root);
}

bool BinarySearchTree::Delete(const Element e)
{
  return Delete(e, root);
}

// Privte Methods

BinaryNode * BinarySearchTree::findMin(BinaryNode *t)
{
  if(t != NULL)
    while(t->left != NULL)
      t = t->left;
  return t;
}

void BinarySearchTree::makeEmpty(BinaryNode * & t)
{
  if(t != NULL) {
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
  }
  t = NULL;
}

bool BinarySearchTree::Insert(const Element e, BinaryNode * & t)
{
  if(t == NULL) {
    t = new BinaryNode(e);
    return true;
  } else if(e == t->elem)
    return false;
  else if(e < t->elem)
    return Insert(e, t->left);
  else if(e > t->elem)
    return Insert(e, t->right);
  else
    return false;
}

bool BinarySearchTree::Access(const Element e, BinaryNode * & t)
{
  if(t == NULL)
    return false;
  else if(e == t->elem)
    return true;
  else if(e < t->elem)
    return Access(e, t->left);
  else
    return Access(e, t->right);
}

bool BinarySearchTree::Delete(const Element e, BinaryNode * & t)
{
  if(t == NULL) {
//    cout << "case 1: t->elem= " << t->elem << endl;
    return false;
  }
  else if(e < t->elem) {
//    cout << "case 2: t->elem= " << t->elem << endl;
    return Delete(e, t->left);
  }
  else if(e > t->elem) {
//    cout << "case 3: t->elem= " << t->elem << endl;
    return Delete(e, t->right);
  }
  else {
    if(t->left != NULL && t->right != NULL) {
//      cout << "case 4_1: t->elem= " << t->elem << endl;
      t->elem = findMin(t->right)->elem;
//      cout << "case 4_1: t->elem= " << t->elem << endl;
      return Delete(t->elem, t->right);
    }
    else {
//      cout << "case 4_2: t->elem= " << t->elem << endl;
      BinaryNode *oldNode = t;
      t = (t->left != NULL) ? t->left : t->right;
      delete oldNode;
      return true;
    }
  }
}

