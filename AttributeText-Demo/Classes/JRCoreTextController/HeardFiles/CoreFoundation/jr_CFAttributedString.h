//
//  jr_CFAttributedString.h
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/1/8.
//  Copyright © 2017年 王潇. All rights reserved.
//

#ifndef jr_CFAttributedString_h
#define jr_CFAttributedString_h


typedef const struct CF_BRIDGED_TYPE(NSAttributedString) __CFAttributedString *CFAttributedStringRef;
typedef struct CF_BRIDGED_MUTABLE_TYPE(NSMutableAttributedString) __CFAttributedString *CFMutableAttributedStringRef;

CF_EXPORT CFTypeID CFAttributedStringGetTypeID(void);


/* --------------------------------------------------------------------------- */
/*** CFAttributedString ***/
/* --------------------------------------------------------------------------- */

/// 创建属性字符串
CFAttributedStringRef CFAttributedStringCreate(CFAllocatorRef alloc,
											   CFStringRef str, 
											   CFDictionaryRef attributes);
/// 获取子串
CFAttributedStringRef CFAttributedStringCreateWithSubstring(CFAllocatorRef alloc, 
															CFAttributedStringRef aStr, 
															CFRange range);
/// 拷贝 属性字符串
CFAttributedStringRef CFAttributedStringCreateCopy(CFAllocatorRef alloc, 
												   CFAttributedStringRef aStr);

/// 根据 属性字符串 获取 CFStringRef
CFStringRef CFAttributedStringGetString(CFAttributedStringRef aStr);

/// 获取属性字符串长度
CFIndex CFAttributedStringGetLength(CFAttributedStringRef aStr);

/// 获取属性
CFDictionaryRef CFAttributedStringGetAttributes(CFAttributedStringRef aStr, 
												CFIndex loc, 
												CFRange *effectiveRange);

/// 获取属性
CFTypeRef CFAttributedStringGetAttribute(CFAttributedStringRef aStr, 
										 CFIndex loc, 
										 CFStringRef attrName, 
										 CFRange *effectiveRange);

/// 获取属性
CFDictionaryRef CFAttributedStringGetAttributesAndLongestEffectiveRange(CFAttributedStringRef aStr, 
																		CFIndex loc, 
																		CFRange inRange, 
																		CFRange *longestEffectiveRange);

/// 获取属性
CFTypeRef CFAttributedStringGetAttributeAndLongestEffectiveRange(CFAttributedStringRef aStr, 
																 CFIndex loc, 
																 CFStringRef attrName, 
																 CFRange inRange, 
																 CFRange *longestEffectiveRange);


/* --------------------------------------------------------------------------- */
/*** CFMutableAttributedString ***/
/* --------------------------------------------------------------------------- */

/// 创建可变属性字符串
CFMutableAttributedStringRef CFAttributedStringCreateMutableCopy(CFAllocatorRef alloc, 
																 CFIndex maxLength, 
																 CFAttributedStringRef aStr);
/// 创建可变属性字符串
CFMutableAttributedStringRef CFAttributedStringCreateMutable(CFAllocatorRef alloc, 
															 CFIndex maxLength);

/// 替换字符串
void CFAttributedStringReplaceString(CFMutableAttributedStringRef aStr, 
									 CFRange range, 
									 CFStringRef replacement);

/// 获取 不可变属性
CFMutableStringRef CFAttributedStringGetMutableString(CFMutableAttributedStringRef aStr);

/// 设置属性
void CFAttributedStringSetAttributes(CFMutableAttributedStringRef aStr, 
									 CFRange range, 
									 CFDictionaryRef replacement,
									 Boolean clearOtherAttributes);

/// 设置属性
void CFAttributedStringSetAttribute(CFMutableAttributedStringRef aStr, 
									CFRange range, 
									CFStringRef attrName, 
									CFTypeRef value);

/// 删除属性
void CFAttributedStringRemoveAttribute(CFMutableAttributedStringRef aStr, 
									   CFRange range, 
									   CFStringRef attrName);

/// 替换属性字符串
void CFAttributedStringReplaceAttributedString(CFMutableAttributedStringRef aStr, 
											   CFRange range, 
											   CFAttributedStringRef replacement);

/// 开始编辑
void CFAttributedStringBeginEditing(CFMutableAttributedStringRef aStr);

/// 结束编辑
void CFAttributedStringEndEditing(CFMutableAttributedStringRef aStr);

#endif /* jr_CFAttributedString_h */
