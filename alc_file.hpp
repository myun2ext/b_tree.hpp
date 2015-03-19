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
			size_t block_size;
		public:
			file_alloc(const char* filename) { fp = fopen(filename, "w+b"); }
			void set_block_size(size_t _size) { block_size = _size; }
			bool empty() const { return size() == 0; }

			size_t write(const void* p) {
				fseek(fp, 0, SEEK_END);
				return fwrite(p, block_size, 1, fp);
			}
			size_t write(long pos, const void* p) {
				fseek(fp, pos * block_size, SEEK_SET);
				return fwrite(p, block_size, 1, fp);
			}
			void* read(long pos, void* p) {
				fseek(fp, pos * block_size, SEEK_SET);
				fread(p, block_size, 1, fp);
				return p;
			}
			void* operator[](unsigned int i) {
				char* buffer = new char[block_size];
				return read(i * block_size, buffer);
			}
		};
	}
}

#endif//__MYUN2__BTREE__ALC_FILE__HPP__
