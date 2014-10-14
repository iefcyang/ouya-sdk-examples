#ifndef __ORG_JSON_JSONOBJECT_JSONOBJECT_H__
#define __ORG_JSON_JSONOBJECT_JSONOBJECT_H__

#if defined(ANDROID)
#include "s3eEdk.h"
#include "s3eEdk_android.h"
#include <jni.h>
#endif

#include <string>

namespace org_json_JSONArray
{
	class JSONArray;
}

struct _JNIEnv;
typedef _JNIEnv JNIEnv;

class _jclass;
typedef _jclass* jclass;

class _jobject;
typedef _jobject* jobject;

class _jmethodID;
typedef _jmethodID* jmethodID;

namespace org_json_JSONObject
{
	class JSONObject
	{
	public:
		static int InitJNI(JNIEnv* env);
		static void FindJNI();
		JSONObject(jobject jsonObject);
		JSONObject(const std::string& json);
		jobject GetInstance() const;
		double getDouble(const std::string& name) const;
		org_json_JSONArray::JSONArray getJSONArray(const std::string& name) const;
		JSONObject getJSONObject(const std::string& name) const;
		int getInt(const std::string& name) const;
		std::string getString(const std::string& name) const;
		bool has(const std::string& name) const;
	private:
		static JNIEnv* _env;
		static jclass _jcJsonObject;
		static jmethodID _mConstruct;
		static jmethodID _mGetDouble;
		static jmethodID _mGetInt;
		static jmethodID _mGetJsonArray;
		static jmethodID _mGetJsonObject;
		static jmethodID _mGetString;
		static jmethodID _mHas;
		jobject _instance;
	};
}

#endif