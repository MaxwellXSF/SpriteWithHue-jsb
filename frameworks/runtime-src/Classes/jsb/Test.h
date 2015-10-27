#ifndef __JSBTest_H__
#define __JSBTest_H__

#include "cocos2d.h"
namespace sj{
	class Test :public cocos2d::Ref
	{
	public:
		Test();
		virtual ~Test();
		virtual bool init();
		CREATE_FUNC(Test);

		std::string funcTest();
		void argcTest(int a);
	};
}

#endif // __AnimationKoo_H__