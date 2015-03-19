#ifndef __MYUN2__BTREE__ALC_FILE__HPP__
#define __MYUN2__BTREE__ALC_FILE__HPP__

namespace myun2
{
	namespace btree_
	{
		class file_alloc
		{
		private:
			mutable FILE* fp;
			long size() const {
				fseek(fp, 0, SEEK_END);
				return ftell(fp);
			}
		public:
			file_alloc(const char* filename) { fp = fopen(filename, "w+b"); }
			bool empty() const { return size() == 0; }

			size_t write(const void* p, size_t size) {
				return fwrite(p, size, 1, fp);
			}
			void* read(long pos, void* p, size_t size) {
				fread(p, size, 1, fp);
				return p;
			}
		};
	}
}

#endif//__MYUN2__BTREE__ALC_FILE__HPP__
