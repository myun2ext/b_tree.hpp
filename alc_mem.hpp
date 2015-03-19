#ifndef __MYUN2__BTREE__ALC_MEM__HPP__
#define __MYUN2__BTREE__ALC_MEM__HPP__

#include <vector>
#include "memory.h"

namespace myun2
{
	namespace btree_
	{
		class mem_alloc
		{
		private:
			::std::vector<void*> ptrs;
			size_t size;
		public:
			void set_block_size(size_t _size) { size = _size; }
			bool empty() const { return ptrs.empty(); }

			void* allocate(size_t size) {
				ptrs.push_back(new char[size]);
				return *(ptrs.rbegin());
			}
			size_t write(const void* p)
			{
				void *buffer = new char[size];
				memcpy(buffer, p, size);
				ptrs.push_back(buffer);
				return size;
			}
			size_t write(long pos, const void* p)
			{
				ptrs[pos] = (void*)p;
				return size;
			}
			void* read(long pos, void* p) {
				memcpy(p, ptrs[pos], size);
				return p;
			}
			void* operator[](unsigned int i) {
				return ptrs[i];
			}
		};
	}
}

#endif//__MYUN2__BTREE__ALC_MEM__HPP__
