#include "cocos2d_specifics.hpp"
#include "jsbSelf.h"
#include "Test.h"
#include "CCSpriteWithHue.h"

#include "cocos2d.h"
#include "spidermonkey_specifics.h"
#include "ScriptingCore.h"

JSClass  *jsb_sj_Test_class;
JSObject *jsb_sj_Test_prototype;

/*
template<class T>
static bool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
	JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
	JS::RootedValue initializing(cx);
	bool isNewValid = true;
	JS::RootedObject global(cx, ScriptingCore::getInstance()->getGlobalObject());
	isNewValid = JS_GetProperty(cx, global, "initializing", &initializing) && initializing.toBoolean();
	if (isNewValid)
	{
		TypeTest<T> t;
		js_type_class_t *typeClass = nullptr;
		std::string typeName = t.s_name();
		auto typeMapIter = _js_global_type_map.find(typeName);
		CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
		typeClass = typeMapIter->second;
		CCASSERT(typeClass, "The value is null.");

		JS::RootedObject proto(cx, typeClass->proto.get());
		JS::RootedObject parent(cx, typeClass->parentProto.get());
		JS::RootedObject _tmp(cx, JS_NewObject(cx, typeClass->jsclass, proto, parent));

		args.rval().set(OBJECT_TO_JSVAL(_tmp));
		return true;
	}

	JS_ReportError(cx, "Constructor for the requested class is not available, please refer to the API reference.");
	return false;
}

static bool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
	return false;
}*/

static bool js_is_native_obj(JSContext *cx, uint32_t argc, jsval *vp)
{
	JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
	args.rval().setBoolean(true);
	return true;
}

bool js_sj_Test_init(JSContext *cx, uint32_t argc, jsval *vp)
{
	JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
	JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	sj::Test* cobj = (sj::Test *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2(cobj, cx, false, "js_sj_Test_init : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->init();
		jsval jsret = JSVAL_NULL;
		jsret = BOOLEAN_TO_JSVAL(ret);
		args.rval().set(jsret);
		return true;
	}

	JS_ReportError(cx, "js_sj_Test_init : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}

bool jsb_sj_Test_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
	bool ok = true;
	sj::Test* cobj = new (std::nothrow) sj::Test();
	cocos2d::Ref *_ccobj = dynamic_cast<cocos2d::Ref *>(cobj);
	if (_ccobj) {
		_ccobj->autorelease();
	}
	TypeTest<sj::Test> t;
	js_type_class_t *typeClass = nullptr;
	std::string typeName = t.s_name();
	auto typeMapIter = _js_global_type_map.find(typeName);
	CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
	typeClass = typeMapIter->second;
	CCASSERT(typeClass, "The value is null.");
	// JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
	JS::RootedObject proto(cx, typeClass->proto.get());
	JS::RootedObject parent(cx, typeClass->parentProto.get());
	JS::RootedObject obj(cx, JS_NewObject(cx, typeClass->jsclass, proto, parent));
	args.rval().set(OBJECT_TO_JSVAL(obj));
	// link the native object with the javascript object
	js_proxy_t* p = jsb_new_proxy(cobj, obj);
	AddNamedObjectRoot(cx, &p->obj, "sj::Test");
	if (JS_HasProperty(cx, obj, "_ctor", &ok) && ok)
		ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(obj), "_ctor", args);
	return true;
}

bool js_sj_Test_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
	if (argc == 0) {
		sj::Test* ret = sj::Test::create();
		jsval jsret = JSVAL_NULL;
		do {
			if (ret) {
				js_proxy_t *jsProxy = js_get_or_create_proxy<sj::Test>(cx, (sj::Test*)ret);
				jsret = OBJECT_TO_JSVAL(jsProxy->obj);
			}
			else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		args.rval().set(jsret);
		return true;
	}
	JS_ReportError(cx, "js_sj_Test_create : wrong number of arguments");
	return false;
}

bool js_sj_Test_funcTest(JSContext *cx, uint32_t argc, jsval *vp)
{
	JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
	JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	sj::Test* cobj = (sj::Test *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2(cobj, cx, false, "js_sj_Test_funcTest : Invalid Native Object");
	if (argc == 0) {
		std::string ret = cobj->funcTest();
		jsval jsret = JSVAL_NULL;
		jsret = std_string_to_jsval(cx, ret);
		args.rval().set(jsret);
		return true;
	}
	JS_ReportError(cx, "js_sj_Test_funcTest : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}

bool js_sj_Test_argcTest(JSContext *cx, uint32_t argc, jsval *vp)
{
	JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
	JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	sj::Test* cobj = (sj::Test *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2(cobj, cx, false, "js_sj_Test_argcTest : Invalid Native Object");

	if (argc == 1) {
		double data;
		JS::ToNumber(cx, JS::RootedValue(cx, args[0]), &data);
		cobj->argcTest(data);
		args.rval().setUndefined();
		return true;
	}

	JS_ReportError(cx, "js_sj_Test_argcTest : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}

void js_sj_Test_finalize(JSFreeOp *fop, JSObject *obj) {
	//    CCLOGINFO("jsbindings: finalizing JS object %p (LsLeafsoar)", obj);
}

void js_register_sj_Test(JSContext *cx, JS::HandleObject global) {
	jsb_sj_Test_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_sj_Test_class->name = "Test";
	jsb_sj_Test_class->addProperty = JS_PropertyStub;
	jsb_sj_Test_class->delProperty = JS_DeletePropertyStub;
	jsb_sj_Test_class->getProperty = JS_PropertyStub;
	jsb_sj_Test_class->setProperty = JS_StrictPropertyStub;
	jsb_sj_Test_class->enumerate = JS_EnumerateStub;
	jsb_sj_Test_class->resolve = JS_ResolveStub;
	jsb_sj_Test_class->convert = JS_ConvertStub;
	jsb_sj_Test_class->finalize = js_sj_Test_finalize;
	jsb_sj_Test_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		JS_PSG("__nativeObj", js_is_native_obj, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_PS_END
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("funcTest", js_sj_Test_funcTest, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("argcTest", js_sj_Test_argcTest, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_sj_Test_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_sj_Test_prototype = JS_InitClass(
		cx, global,
		JS::NullPtr(), // parent proto
		jsb_sj_Test_class,
		jsb_sj_Test_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	//  bool found;
	//FIXME: Removed in Firefox v27 
	//  JS_SetPropertyAttributes(cx, global, "CustomClass", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<sj::Test> t;
	js_type_class_t *p;
	std::string typeName = t.s_name();
	if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
	{
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->jsclass = jsb_sj_Test_class;
		p->proto = jsb_sj_Test_prototype;
		p->parentProto = NULL;
		_js_global_type_map.insert(std::make_pair(typeName, p));
	}
}


JSClass  *jsb_sj_SpriteWithHue_class;
JSObject *jsb_sj_SpriteWithHue_prototype;


bool js_sj_SpriteWithHue_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
	if (argc == 1) {

		std::string data;
		jsval_to_std_string(cx, args.get(0), &data);

		sj::SpriteWithHue* ret = sj::SpriteWithHue::create(data);
		jsval jsret = JSVAL_NULL;
		do {
			if (ret) {
				js_proxy_t *jsProxy = js_get_or_create_proxy<sj::SpriteWithHue>(cx, (sj::SpriteWithHue*)ret);
				jsret = OBJECT_TO_JSVAL(jsProxy->obj);
			}
			else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		args.rval().set(jsret);
		return true;
	}
	JS_ReportError(cx, "js_sj_SpriteWithHue_create : wrong number of arguments");
	return false;
}

bool js_sj_SpriteWithHue_setPosition(JSContext *cx, uint32_t argc, jsval *vp)
{
	JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
	JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	sj::SpriteWithHue* cobj = (sj::SpriteWithHue *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2(cobj, cx, false, "js_sj_Test_argcTest1 : Invalid Native Object");
	if (argc == 2) {
		double x,y;
		JS::ToNumber(cx, JS::RootedValue(cx, args[0]), &x);
		JS::ToNumber(cx, JS::RootedValue(cx, args[1]), &y);
		cobj->setPosition(x,y);

		jsval jsret = JSVAL_NULL;
		args.rval().set(jsret);
		return true;
	}

	JS_ReportError(cx, "js_sj_Test_argcTest1 : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}

bool js_sj_SpriteWithHue_setHue(JSContext *cx, uint32_t argc, jsval *vp)
{
	JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
	JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	sj::SpriteWithHue* cobj = (sj::SpriteWithHue *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2(cobj, cx, false, "js_sj_Test_argcTest1 : Invalid Native Object");
	if (argc == 1) {
		double hue;
		JS::ToNumber(cx, JS::RootedValue(cx, args[0]), &hue);
		cobj->setHue(hue);

		jsval jsret = JSVAL_NULL;
		args.rval().set(jsret);
		return true;
	}

	JS_ReportError(cx, "js_sj_Test_argcTest1 : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}

bool jsb_sj_SpriteWithHue_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
	bool ok = true;
	sj::SpriteWithHue* cobj = new (std::nothrow) sj::SpriteWithHue();
	cocos2d::Sprite *_ccobj = dynamic_cast<cocos2d::Sprite *>(cobj);
	if (_ccobj) {
		_ccobj->autorelease();
	}
	TypeTest<sj::SpriteWithHue> t;
	js_type_class_t *typeClass = nullptr;
	std::string typeName = t.s_name();
	auto typeMapIter = _js_global_type_map.find(typeName);
	CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
	typeClass = typeMapIter->second;
	CCASSERT(typeClass, "The value is null.");
	// JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
	JS::RootedObject proto(cx, typeClass->proto.get());
	JS::RootedObject parent(cx, typeClass->parentProto.get());
	JS::RootedObject obj(cx, JS_NewObject(cx, typeClass->jsclass, proto, parent));
	args.rval().set(OBJECT_TO_JSVAL(obj));
	// link the native object with the javascript object
	js_proxy_t* p = jsb_new_proxy(cobj, obj);
	AddNamedObjectRoot(cx, &p->obj, "sj::SpriteWithHue");
	if (JS_HasProperty(cx, obj, "_ctor", &ok) && ok)
		ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(obj), "_ctor", args);
	return true;
}

void js_sj_SpriteWithHue_finalize(JSFreeOp *fop, JSObject *obj) {
	//    CCLOGINFO("jsbindings: finalizing JS object %p (LsLeafsoar)", obj);
}

void js_register_sj_SpriteWithHue(JSContext *cx, JS::HandleObject global) {
	jsb_sj_SpriteWithHue_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_sj_SpriteWithHue_class->name = "SpriteWithHue";
	jsb_sj_SpriteWithHue_class->addProperty = JS_PropertyStub;
	jsb_sj_SpriteWithHue_class->delProperty = JS_DeletePropertyStub;
	jsb_sj_SpriteWithHue_class->getProperty = JS_PropertyStub;
	jsb_sj_SpriteWithHue_class->setProperty = JS_StrictPropertyStub;
	jsb_sj_SpriteWithHue_class->enumerate = JS_EnumerateStub;
	jsb_sj_SpriteWithHue_class->resolve = JS_ResolveStub;
	jsb_sj_SpriteWithHue_class->convert = JS_ConvertStub;
	jsb_sj_SpriteWithHue_class->finalize = js_sj_SpriteWithHue_finalize;
	jsb_sj_SpriteWithHue_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		JS_PSG("__nativeObj", js_is_native_obj, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_PS_END
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("setPosition", js_sj_SpriteWithHue_setPosition, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setHue", js_sj_SpriteWithHue_setHue, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_sj_SpriteWithHue_create, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_sj_SpriteWithHue_prototype = JS_InitClass(
		cx, global,
		JS::NullPtr(), // parent proto
		jsb_sj_SpriteWithHue_class,
		jsb_sj_SpriteWithHue_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	//  bool found;
	//FIXME: Removed in Firefox v27 
	//  JS_SetPropertyAttributes(cx, global, "CustomClass", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<sj::SpriteWithHue> t;
	js_type_class_t *p;
	std::string typeName = t.s_name();
	if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
	{
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->jsclass = jsb_sj_SpriteWithHue_class;
		p->proto = jsb_sj_SpriteWithHue_prototype;
		p->parentProto = NULL;
		_js_global_type_map.insert(std::make_pair(typeName, p));
	}
}


void register_all_sj(JSContext* cx, JS::HandleObject obj) {
	// Get the ns
	JS::RootedObject ns(cx);
	get_or_create_js_obj(cx, obj, "sj", &ns);

	js_register_sj_Test(cx, ns);
	js_register_sj_SpriteWithHue(cx, ns);
}