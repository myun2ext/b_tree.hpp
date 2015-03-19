#ifndef __MYUN2__BTREE__ALC_MEM__HPP__
#define __MYUN2__BTREE__ALC_MEM__HPP__

#include <vector>

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
			void *root() { return ptrs[0]; }
			void* allocate(size_t size) {
				ptrs.push_back(new char[size]);
				return *(ptrs.rbegin());
			}
		};
	}
}

#endif//__MYUN2__BTREE__ALC_MEM__HPP__
