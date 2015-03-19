#include <stdio.h>
#include "btree.hpp"
#include "alc_mem.hpp"
#include "alc_file.hpp"

using namespace myun2;

template <typename Bt>
void btree_test(Bt& bt)
{
	bt.insert(*(unsigned int*)"abcd", *(unsigned int*)"ABCD");
	bt.insert(*(unsigned int*)"defg", *(unsigned int*)"DEFG");
}

int main()
{
	btree<btree_::mem_alloc, unsigned int, unsigned int> bt_mem;
	btree<btree_::file_alloc, unsigned int, unsigned int> bt_file("btree.db");

	btree_test(bt_mem);
	btree_test(bt_file);

	return 0;
}
