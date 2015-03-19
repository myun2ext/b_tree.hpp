#include <stdio.h>
#include "btree.hpp"
#include "alc_mem.hpp"
#include "alc_file.hpp"

using namespace myun2;

int main()
{
	btree<btree_::mem_alloc, const char*, const char*> bt;
	bt.insert("a", "abcdef");
	bt.insert("d", "dfghij");
	return 0;
}
