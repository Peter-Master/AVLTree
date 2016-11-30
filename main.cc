#include <iostream>
#include <fstream>

#include "gtest/gtest.h"

#include "avl.h"

using namespace std;

TEST (AVLTree, Test1) {
  AVLTree avltree;
  avltree.Insert(20);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "20");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "20");

  avltree.Insert(10);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "20 10");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "10 20");

  avltree.Insert(2);
  avltree.Access(2);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "10 2 20");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "2 10 20");

  avltree.Insert(15);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "10 2 20 15");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "2 10 15 20");

  avltree.Insert(18);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "10 2 18 15 20");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "2 10 15 18 20");

  avltree.Insert(12);
  avltree.Access(15);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "15 10 2 12 18 20");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "2 10 12 15 18 20");

  avltree.Delete(10);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "15 12 2 18 20");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "2 12 15 18 20");
  
  avltree.Delete(18);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "15 12 2 20");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "2 12 15 20");

  avltree.Delete(20);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "12 2 15");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "2 12 15");

  avltree.Insert(7);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "12 2 7 15");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "2 7 12 15");

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
  }
  ifile.close();
  ifile.open("s10000.txt");
  for (int i = 0; i < N; i++) {
    ifile >> next;
    if (i % 3 == 0)
      avltree2.Delete(next);
  }
  ofile << avltree2.PrintInOrder();
  ofile.close();
  ofile.open("s10000preorder.txt");
  ofile << avltree2.PrintPreOrder();
  ofile.close();
}

int main(int argc, char *argv[])
{
  ::testing::InitGoogleTest (&argc, argv);
  return RUN_ALL_TESTS ();
}
