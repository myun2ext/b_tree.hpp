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
			::std::vector<void*> ptr_list;
		public:
		};
	}
}

#endif//__MYUN2__BTREE__ALC_MEM__HPP__
