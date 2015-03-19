#include <stdio.h>
#include "btree.hpp"
#include "alc_mem.hpp"
#include "alc_file.hpp"

using namespace myun2;

int main()
{
	btree<btree_::mem_alloc, char[4], unsigned int> bt;
	return 0;
}
