#ifndef __MYUN2__BTREE__HPP__
#define __MYUN2__BTREE__HPP__

namespace myun2
{
	template <typename Alloc, typename Key, typename Value, unsigned int RecCount=4>
	class btree
	{
	private:
		struct node {
			Key k;
			Value v;
		};
		Alloc alc;
		void init() {
			if ( alc.empty() ) alc.allocate(sizeof(node) * RecCount);
		}
	public:
		btree(){ init(); }
		btree(const Alloc& _alc) : alc(_alc) { init(); }

		void insert(const Value& value) {
		}
	};
}

#endif//__MYUN2__BTREE__HPP__
