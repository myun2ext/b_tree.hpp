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
			size_t _block_size;
		public:
			file_alloc(const char* filename) { fp = fopen(filename, "w+b"); }
			void set_block_size(size_t size) { _block_size = size; }
			bool empty() const { return size() == 0; }

			size_t write(const void* p, size_t size) {
				return fwrite(p, size, 1, fp);
			}
			void* read(long pos, void* p, size_t size) {
				fread(p, size, 1, fp);
				return p;
			}
			void* operator[](unsigned int i) {
				char* buffer = new char[_block_size];
				return read(i * _block_size, buffer, _block_size);
			}
		};
	}
}

#endif//__MYUN2__BTREE__ALC_FILE__HPP__
