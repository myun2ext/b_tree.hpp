#include <stdio.h>
#include "btree.hpp"

using namespace myun2;

class file_alloc
{
private:
	FILE* fp;
public:
	file_alloc(const char* filename) { fp = fopen(filename, "w+b"); }
};

int main()
{
	btree<file_alloc, char[4], unsigned int, 64> bt;
	return 0;
}
