#include "Test.h"
#include "ScriptingCore.h"
#include "jsapi.h"

using namespace sj;

Test::Test(){
}

Test::~Test(){
}

bool Test::init(){
	return true;
}

std::string Test::funcTest() {
	return "Hello from Test::Hello";
}

void Test::argcTest(int a){
	CCLOG("cclog from Test:%d",a);
}