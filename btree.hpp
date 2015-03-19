#ifndef __MYUN2__BTREE__HPP__
#define __MYUN2__BTREE__HPP__

#include <memory.h>

namespace myun2
{
	template <typename Alloc, typename Key, typename Value, unsigned int RecCount=4>
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
				unsigned int used;
				unsigned int left;
				unsigned int right;
				unsigned int _padding;
			};
			header head;
			node nodes[RecCount - 1];
		};
		void init() {
			if ( alc.empty() ) { allocate(); }
		}
		void allocate() {
			block* p_blk = (block*)alc.allocate(sizeof(node) * RecCount);
			memset(p_blk, 0x00, sizeof(block));
		}
	public:
		btree(){ init(); }
		btree(const Alloc& _alc) : alc(_alc) { init(); }
		void insert(const Key& key, const Value& value) {
			node n = { key, value };
		}
	};
}

#endif//__MYUN2__BTREE__HPP__
