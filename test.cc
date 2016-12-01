#include <iostream>
#include <fstream>

#include "gtest/gtest.h"

#include "avl.h"

using namespace std;

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
  return RUN_ALL_TESTS ();
}
