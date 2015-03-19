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
		public:
			bool empty() const { return ptrs.empty(); }

			void* write(size_t size) {
				ptrs.push_back(new char[size]);
				return *(ptrs.rbegin());
			}
			size_t write(const void* p, size_t size)
			{
				void *buffer = new char[size];
				memcpy(buffer, p, size);
				ptrs.push_back(buffer);
				return size;
			}
			void* read(long pos, void* p, size_t size) {
				memcpy(p, ptrs[pos], size);
				return p;
			}
		};
	}
}

#endif//__MYUN2__BTREE__ALC_MEM__HPP__
