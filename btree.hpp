#ifndef __MYUN2__BTREE__HPP__
#define __MYUN2__BTREE__HPP__

namespace myun2
{
	template <typename Alloc, typename Key, typename Value, unsigned int RecCount=8>
	class btree
	{
	private:
		Alloc alc;
		struct node {
			Key k;
			Value v;
		};
		struct block {
			struct header {
				unsigned char used;
				unsigned char _reserved;	//	Locking Flag
				unsigned char _reserved2;
				unsigned char _reserved3;
				unsigned int left;
				unsigned int right;
				unsigned int _padding;
			};
			header head;
			node nodes[RecCount - 1];

			bool is_full() const { return head.used >= RecCount -1; }
			void add(const node& n) {
				nodes[head.used] = n;
				head.used++;
			}
		};
		block root;
		void init() {
			if ( alc.empty() )
				root = allocate();
			else {
				root = *(block*)alc[0];
			}
		}
		block allocate() {
			block blk = { 0,0,0,0 };
			alc.write(&blk, sizeof(block));
			return blk;
		}
		block* _block(unsigned int i) { return (block*)alc[i]; }
		void put_block(unsigned int i, const block* blk) { return (block*)alc[i]; }
	public:
		btree(){ init(); }
		btree(const Alloc& _alc) : alc(_alc) { init(); }

		void insert(const Key& key, const Value& value)
		{
			node n = { key, value };
			if ( root.is_full() ) { /* TODO */ }
			root.add(n);
			alc.write(0, &root, sizeof(root));
		}
	};
}

#endif//__MYUN2__BTREE__HPP__
