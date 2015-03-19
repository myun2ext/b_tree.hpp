#include <stdio.h>
#include "btree.hpp"
#include "alc_mem.hpp"
#include "alc_file.hpp"

using namespace myun2;

template <typename Bt>
void btree_test(Bt& bt)
{
	bt.insert(*(unsigned int*)"defg", *(unsigned int*)"DEFG");
	bt.insert(*(unsigned int*)"abcd", *(unsigned int*)"ABCD");
	bt.insert(*(unsigned int*)"jklm", *(unsigned int*)"JKLM");

	bt.insert(*(unsigned int*)"opql", *(unsigned int*)"OPQL");
	bt.insert(*(unsigned int*)"ghij", *(unsigned int*)"GHIJ");
	bt.insert(*(unsigned int*)"stuv", *(unsigned int*)"STUV");

	bt.insert(*(unsigned int*)"vwxy", *(unsigned int*)"VWXY");
	bt.insert(*(unsigned int*)"abcd", *(unsigned int*)"ABCD");
	bt.insert(*(unsigned int*)"xyz0", *(unsigned int*)"XYZ0");
	bt.insert(*(unsigned int*)"1234", *(unsigned int*)"1234");

	bt.insert(*(unsigned int*)"abcd", *(unsigned int*)"ABCD");
	bt.insert(*(unsigned int*)"4567", *(unsigned int*)"4567");
	bt.insert(*(unsigned int*)"789_", *(unsigned int*)"789_");
	bt.insert(*(unsigned int*)"%$#\"", *(unsigned int*)"%$#\"");
}

int main()
{
	btree<btree_::mem_alloc, unsigned int, unsigned int> bt_mem;
	btree<btree_::file_alloc, unsigned int, unsigned int> bt_file("btree.db");

	btree_test(bt_mem);
	printf("file\n");
	btree_test(bt_file);

	return 0;
}
