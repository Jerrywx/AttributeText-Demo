//
//  jr_CFDictionary.h
//  AttributeText-Demo
//
//  Created by 王潇 on 2016/12/31.
//  Copyright © 2016年 王潇. All rights reserved.
//

#ifndef jr_CFDictionary_h
#define jr_CFDictionary_h

typedef const void *	(*CFDictionaryRetainCallBack)(CFAllocatorRef allocator, const void *value);
typedef void		(*CFDictionaryReleaseCallBack)(CFAllocatorRef allocator, const void *value);
typedef CFStringRef	(*CFDictionaryCopyDescriptionCallBack)(const void *value);
typedef Boolean		(*CFDictionaryEqualCallBack)(const void *value1, const void *value2);
typedef CFHashCode	(*CFDictionaryHashCallBack)(const void *value);
typedef struct {
	CFIndex							version;
	CFDictionaryRetainCallBack		retain;
	CFDictionaryReleaseCallBack		release;
	CFDictionaryCopyDescriptionCallBack	copyDescription;
	CFDictionaryEqualCallBack		equal;
	CFDictionaryHashCallBack		hash;
} CFDictionaryKeyCallBacks;

/*!
	@constant kCFTypeDictionaryKeyCallBacks
	Predefined CFDictionaryKeyCallBacks structure containing a
	set of callbacks appropriate for use when the keys of a
	CFDictionary are all CFTypes.
 */
CF_EXPORT
const CFDictionaryKeyCallBacks kCFTypeDictionaryKeyCallBacks;

/*!
	@constant kCFCopyStringDictionaryKeyCallBacks
	Predefined CFDictionaryKeyCallBacks structure containing a
	set of callbacks appropriate for use when the keys of a
	CFDictionary are all CFStrings, which may be mutable and
	need to be copied in order to serve as constant keys for
	the values in the dictionary.
 */
CF_EXPORT
const CFDictionaryKeyCallBacks kCFCopyStringDictionaryKeyCallBacks;

/*!
	@typedef CFDictionaryValueCallBacks
	Structure containing the callbacks for values of a CFDictionary.
	包含 字典 回调值的结构图
	@field version The version number of the structure type being passed
					in as a parameter to the CFDictionary creation functions.
					This structure is version 0.
	
	@field retain The callback used to add a retain for the dictionary
				  on values as they are put into the dictionary.
				  This callback returns the value to use as the value in the
				  dictionary, which is usually the value parameter passed to
				  this callback, but may be a different value if a different
				  value should be added to the dictionary. The dictionary's
				  allocator is passed as the first argument.

	@field release The callback used to remove a retain previously added
				for the dictionary from values as they are removed from
				the dictionary. The dictionary's allocator is passed as the
				first argument.
 
	@field copyDescription The callback used to create a descriptive
				string representation of each value in the dictionary. This
				is used by the CFCopyDescription() function.
	@field equal The callback used to compare values in the dictionary for
				equality in some operations.
 */
typedef struct {
	CFIndex				version;
	CFDictionaryRetainCallBack		retain;
	CFDictionaryReleaseCallBack		release;
	CFDictionaryCopyDescriptionCallBack	copyDescription;
	CFDictionaryEqualCallBack		equal;
} CFDictionaryValueCallBacks;

/*!
	@constant kCFTypeDictionaryValueCallBacks
	Predefined CFDictionaryValueCallBacks structure containing a set
	of callbacks appropriate for use when the values in a CFDictionary
	are all CFTypes.
 */
CF_EXPORT
const CFDictionaryValueCallBacks kCFTypeDictionaryValueCallBacks;

/*!
	@typedef CFDictionaryApplierFunction
	Type of the callback function used by the apply functions of
 CFDictionarys.
	@param key The current key for the value.
	@param value The current value from the dictionary.
	@param context The user-defined context parameter given to the apply
 function.
 */
typedef void (*CFDictionaryApplierFunction)(const void *key, const void *value, void *context);

/// 不可变 CFDictionary
typedef const struct CF_BRIDGED_TYPE(NSDictionary) __CFDictionary * CFDictionaryRef;

/// 可变 CFDictionary
typedef struct CF_BRIDGED_MUTABLE_TYPE(NSMutableDictionary) __CFDictionary * CFMutableDictionaryRef;

/// Returns the type identifier of all CFDictionary instances.
CFTypeID CFDictionaryGetTypeID(void);

/// 创建 CFDictionaryRef
CF_EXPORT CFDictionaryRef CFDictionaryCreate(CFAllocatorRef allocator, const void **keys, const void **values, CFIndex numValues, const CFDictionaryKeyCallBacks *keyCallBacks, const CFDictionaryValueCallBacks *valueCallBacks);

/// 创建 CFDictionaryRef 拷贝
CFDictionaryRef CFDictionaryCreateCopy(CFAllocatorRef allocator, CFDictionaryRef theDict);

/// 创建 CFMutableDictionaryRef
CFMutableDictionaryRef CFDictionaryCreateMutable(CFAllocatorRef allocator, CFIndex capacity, const CFDictionaryKeyCallBacks *keyCallBacks, const CFDictionaryValueCallBacks *valueCallBacks);

/// 创建 CFMutableDictionaryRef 拷贝
CFMutableDictionaryRef CFDictionaryCreateMutableCopy(CFAllocatorRef allocator, CFIndex capacity, CFDictionaryRef theDict);

/// 获取字典数量
CFIndex CFDictionaryGetCount(CFDictionaryRef theDict);

/// 获取 key 出现的次数
CFIndex CFDictionaryGetCountOfKey(CFDictionaryRef theDict, const void *key);

/// 获取 value 出现的次数
CFIndex CFDictionaryGetCountOfValue(CFDictionaryRef theDict, const void *value);

/// 获取是否包含 key  包含返回 1 不包含返回 0
Boolean CFDictionaryContainsKey(CFDictionaryRef theDict, const void *key);

/// 获取是否包含 value  包含返回 1 不包含返回 0
Boolean CFDictionaryContainsValue(CFDictionaryRef theDict, const void *value);

/// 根据 key 获取 value
const void *CFDictionaryGetValue(CFDictionaryRef theDict, const void *key);

/// 根据 key 获取 value
Boolean CFDictionaryGetValueIfPresent(CFDictionaryRef theDict, const void *key, const void **value);

/// 拆解字典为 keys values
void CFDictionaryGetKeysAndValues(CFDictionaryRef theDict, const void **keys, const void **values);

/// 迭代字典
void CFDictionaryApplyFunction(CFDictionaryRef theDict, CFDictionaryApplierFunction CF_NOESCAPE applier, void *context);

/// 追加值 用于可变字典
void CFDictionaryAddValue(CFMutableDictionaryRef theDict, const void *key, const void *value);

/// 修改 value
void CFDictionarySetValue(CFMutableDictionaryRef theDict, const void *key, const void *value);

/*!
	@function CFDictionaryReplaceValue
	Replaces the value of the key in the dictionary.
	@param theDict The dictionary to which the value is to be replaced. If this
 parameter is not a valid mutable CFDictionary, the behavior is
 undefined.
	@param key The key of the value to replace in the dictionary. If a key
 which matches this key is present in the dictionary, the value
 is changed to the given value, otherwise this function does
 nothing ("replace if present").
	@param value The value to replace into the dictionary. The value
 is retained by the dictionary using the retain callback provided
 when the dictionary was created, and the previous value is
 released. If the value is not of the sort expected by the
 retain or release callbacks, the behavior is undefined.
 */
CF_EXPORT
void CFDictionaryReplaceValue(CFMutableDictionaryRef theDict, const void *key, const void *value);

/// 删除指定 key
void CFDictionaryRemoveValue(CFMutableDictionaryRef theDict, const void *key);

/// 清空字典
void CFDictionaryRemoveAllValues(CFMutableDictionaryRef theDict);

CF_EXTERN_C_END
CF_IMPLICIT_BRIDGING_DISABLED

#endif /* ! __COREFOUNDATION_CFDICTIONARY__ */




#endif /* jr_CFDictionary_h */
