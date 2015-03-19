#include <stdio.h>
#include "btree.hpp"
#include "alc_mem.hpp"
#include "alc_file.hpp"

using namespace myun2;

template <typename Bt>
void btree_test(Bt& bt)
{
	bt.insert("a", "abcdef");
	bt.insert("d", "dfghij");
}

int main()
{
	btree<btree_::mem_alloc, const char*, const char*> bt_mem;
	btree<btree_::file_alloc, const char*, const char*> bt_file("btree.db");

	btree_test(bt_mem);
	btree_test(bt_file);

	return 0;
}
