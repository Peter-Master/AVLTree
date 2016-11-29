#include <iostream>

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

  cout << "###########\n###################\n################\nEND OF INSERTS\n###################\n#################\n###########" << endl;

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
}

int main(int argc, char *argv[])
{
  ::testing::InitGoogleTest (&argc, argv);
  return RUN_ALL_TESTS ();
}
