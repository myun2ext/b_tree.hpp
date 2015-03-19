#ifndef __MYUN2__BTREE__ALC_FILE__HPP__
#define __MYUN2__BTREE__ALC_FILE__HPP__

namespace myun2
{
	namespace btree_
	{
		class file_alloc
		{
		private:
			FILE* fp;
		public:
			file_alloc(const char* filename) { fp = fopen(filename, "w+b"); }
		};
	}
}

#endif//__MYUN2__BTREE__ALC_FILE__HPP__
