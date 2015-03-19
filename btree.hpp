#ifndef __MYUN2__BTREE__HPP__
#define __MYUN2__BTREE__HPP__

namespace myun2
{
	template <typename Alloc, typename Key, typename Value, unsigned int RecordSize=8>
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

				header() {
					used = 0;
                    _reserved = 0;
                    _reserved2 = 0;
                    _reserved3 = 0;
                    left = 0;
                    right = 0;
                    _padding = 0;
				}
			} head;

			static const int NodeCount = RecordSize - (sizeof(header) / sizeof(node));
			node nodes[NodeCount];

			bool is_full() const { return head.used >= NodeCount; }
			void add(const node& n) {
				nodes[head.used] = n;
				head.used++;
			}
		};
		//block root;
		void init() {
			alc.set_block_size(sizeof(block));

			if ( alc.empty() )
				/*root =*/ allocate();
			else {
				/*root =*/ *(block*)alc[0];
			}
		}
		block allocate() {
			block blk;
			alc.write(&blk);
			return blk;
		}
		block* _block(unsigned int i) { return (block*)alc[i]; }
		block& get_block(unsigned int i) { return *(block*)alc[i]; }
		void put_block(unsigned int i, const block* blk) { return (block*)alc[i]; }

		block split(long pos, block& blk)
		{
			block left_block;	//	Smaller
			block right_block;	//	Bigger

			left_block.add(blk.nodes[0]);

			unsigned int base_i = 0;
			for(unsigned int i=1; i<blk.head.used; i++)
			{
				if ( blk.nodes[base_i].k < blk.nodes[i].k )
				{
					right_block.add(blk.nodes[i]);
				}
				else {
					left_block.add(blk.nodes[i]);
				}
			}
			long left_pos = alc.write(&left_block);
			right_block.head.left = left_pos;

			alc.write(pos, &right_block);
			return right_block;
		}
		void add(long pos, const node& n)
		{
			block &blk = get_block(pos);
			if ( blk.head.left && n.k < blk.nodes[0].k )
			{
				add(blk.head.left, n);
				return;
			}
			blk.add(n);
			alc.write(pos, &blk);
			if ( blk.is_full() )
				split(pos, blk);
		}
	public:
		btree(){ init(); }
		btree(const Alloc& _alc) : alc(_alc) { init(); }

		void insert(const Key& key, const Value& value)
		{
			node n = { key, value };
			add(0, n);
		}
	};
}

#endif//__MYUN2__BTREE__HPP__
