/*
The correct one is test2

test1: error with add. Can't add nodes to the tree
test3: error found when building second tree. has problem with toArray
test4: error with copy constructor. Not a deep copy
test5: error with remove. error found when removing root
test6: error with remove. remove node not exist will cause seg fault
test7: error with contains. after removing node, contains of that node is still true.

*/

#include "stdio.h"
#include "btree.h"

int main(int argc, char* argv[])
{

	// test default constructor
	BTree* btree1 = new BTree();

	// test add
	btree1->add(3);
	btree1->add(2);
	btree1->add(1);
	btree1->add(4);
	btree1->add(5);	
	btree1->add(6);
	btree1->add(7);
	btree1->add(8);


	//test size
	int s = btree1->size();
	printf("size of btree1 is %d\n", s);

	//test duplicate add
	btree1->add(5);
	printf("after add duplicate node, the size of btree1 is %d\n", btree1->size());
	//test toArray
	int * inorder = btree1->toArray();
	printf("inorder traverse btree1\n");

	for(int i = 0; i < s; i++)
	{
	printf("%d", inorder[i]);
	printf("->");
	}
	printf("\n");

	//test contains
	for(int i = 1; i <= s; i++)
	{
	printf("Is %d in tree? %d\n",i, btree1->contains(i));
	}

	//delete toArray
	delete[] inorder;

	//test remove root
	printf("-----------remove root(3)-----------\n");
	btree1->remove(3);
	printf("Is %d in tree? %d\n",3, btree1->contains(3));

	//check size again
	int s2_1 = btree1->size();
	printf("now the size of the tree is %d\n", s2_1);
    	
	//test remove left leaf
	printf("-----------remove leaf(1)-----------\n");
	btree1->remove(1);
	printf("Is %d in tree? %d\n",1, btree1->contains(1));

	//check size again
	int s2_2 = btree1->size();
	printf("now the size of the tree is %d\n", s2_2);

	//test remove right leaf
	printf("-----------remove leaf(8)-----------\n");
	btree1->remove(8);
	printf("Is %d in tree? %d\n",8, btree1->contains(8));	

	//check size again
	int s2_3 = btree1->size();
	printf("now the size of the tree is %d\n", s2_3);


	//test remove node not exist
	printf("--------remove node not exist------\n");
	btree1->remove(888);
	printf("Is %d in tree? %d\n",888, btree1->contains(888));	
	printf("now the size of the tree is %d\n", btree1->size());


	//check toArray
	int * inorder2 = btree1->toArray();
	printf("inorder traverse btree1\n");
	for(int i = 0; i < s2_3; i++)
	{
	printf("%d", inorder2[i]);
	printf("->");
	}
	printf("\n");

	//check duplicate remove
	printf("---------remove leaf(8) again-------\n");
	btree1->remove(8);
	printf("Is %d in tree? %d\n",8, btree1->contains(8));	

	//check size again
	int s2_4 = btree1->size();
	printf("now the size of the tree is %d\n", s2_4);

	//check toArray
	int * inorder2_2 = btree1->toArray();
	printf("inorder traverse\n");
	for(int i = 0; i < s2_4; i++)
	{
	printf("%d", inorder2_2[i]);
	printf("->");
	}
	printf("\n");

	//check contains and if the wanted node is removed and other nodes maintaine in tree
	for(int i = 1; i <= s; i++)
	{
	printf("is %d in tree? %d\n",i, btree1->contains(i));
	}

	delete[] inorder2;




	printf("\n");
	printf("-----------Building new BTree-----------\n");

	BTree* btree2 = new BTree();
	btree2->add(5);
	btree2->add(4);
	btree2->add(10);
	btree2->add(1);
	int size_b2 = btree2->size();

	printf("Is %d in btree2? %d\n", 1, btree2->contains(1));
	printf("Is %d in btree2? %d\n", 4, btree2->contains(4));
	printf("Is %d in btree2? %d\n", 5, btree2->contains(5));
	printf("Is %d in btree2? %d\n",10, btree2->contains(10));

	int * inorder3 = btree2->toArray();

	printf("inorder traverse btree2\n");
	printf("\n");
	for(int i = 0; i < size_b2; i++){
	printf("%d", inorder3[i]);
	printf("->");
	}
	printf("\n");
	delete[] inorder3;

	//test copy constructor
	printf("------------copy btree2 into btree3----------\n");
	BTree* btree3 = new BTree(*btree2);
	printf("inorder traverse btree3\n");
	int * inorder4 = btree3->toArray();

	printf("\n");
	for(int i = 0; i < size_b2; i++){
	printf("%d", inorder4[i]);
	printf("->");
	}
	printf("\n");
	delete[] inorder4;


	//test deep copy. remove node from original tree and check if the copied tree changes as well.
	btree2->remove(10);

	int * inorder5 = btree2->toArray();

	printf("\n");
	printf("10 removed from btree2. Inorder traverse btree2 again\n");

	for(int i = 0; i < size_b2-1; i++){
	printf("%d", inorder5[i]);
	printf("->");
	}
	printf("\n");
	printf("Is %d in btree2? %d\n", 1, btree2->contains(1));
	printf("Is %d in btree2? %d\n", 4, btree2->contains(4));
	printf("Is %d in btree2? %d\n", 5, btree2->contains(5));
	printf("Is %d in btree2? %d\n",10, btree2->contains(10));
	printf("\n");
	delete[] inorder5;


	printf("10 removed from btree2. Inorder traverse btree3 again\n");
	int * inorder6 = btree3->toArray();

	for(int i = 0; i < size_b2; i++){
	printf("%d", inorder6[i]);
	printf("->");
	}
	printf("\n");
	printf("Is %d in btree3? %d\n", 1, btree3->contains(1));
	printf("Is %d in btree3? %d\n", 4, btree3->contains(4));
	printf("Is %d in btree3? %d\n", 5, btree3->contains(5));
	printf("Is %d in btree3? %d\n",10, btree3->contains(10));
	printf("\n");

	delete[] inorder6;


	//test operator=
	btree2->add(200);
	btree2->add(100);

	btree3 = btree2;
	printf("copy btree2 into btree3. Inorder traverse btree3 again\n");
	int * inorder7 = btree3->toArray();

	for(int i = 0; i < 5; i++){
	printf("%d", inorder7[i]);
	printf("->");
	}
	printf("\n");
	printf("Is %d in btree3? %d\n", 1, btree3->contains(1));
	printf("Is %d in btree3? %d\n", 4, btree3->contains(4));
	printf("Is %d in btree3? %d\n", 5, btree3->contains(5));
	printf("Is %d in btree3? %d\n",10, btree3->contains(10));
	printf("Is %d in btree3? %d\n",100, btree3->contains(100));
	printf("\n");

	delete[] inorder7;

	int * inorder8 = btree2->toArray();
	printf("100 added to btree2. Inorder traverse btree2 again\n");
	for(int i = 0; i < 5; i++)
	{
		printf("%d", inorder8[i]);
		printf("->");	
	}
	printf("\n");

	delete[] inorder8;

}



