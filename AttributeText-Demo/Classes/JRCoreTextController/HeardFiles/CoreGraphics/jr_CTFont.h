//
//  jr_CTFont.h
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/1/5.
//  Copyright © 2017年 王潇. All rights reserved.
//

#ifndef jr_CTFont_h
#define jr_CTFont_h


/*! --------------------------------------------------------------------------
 @group Font Types
 *///--------------------------------------------------------------------------

/*!
 @function   CTFontGetTypeID
 @abstract   Returns the type identifier for Core Text font references.
 @result     The identifier for the opaque type CTFontRef.
 */
CFTypeID CTFontGetTypeID( void ) CT_AVAILABLE(10_5, 3_2);

/*! --------------------------------------------------------------------------
 @group Font Constants
 *///--------------------------------------------------------------------------

// Name specifier constants
/*!
 @defined    kCTFontCopyrightNameKey
 @abstract   The name specifier for the copyright name.
 */
CT_EXPORT const CFStringRef kCTFontCopyrightNameKey CT_AVAILABLE(10_5, 3_2);
/*!
 @defined    kCTFontFamilyNameKey
 @abstract   The name specifier for the family name.
 */
CT_EXPORT const CFStringRef kCTFontFamilyNameKey CT_AVAILABLE(10_5, 3_2);
/*!
 @defined    kCTFontSubFamilyNameKey
 @abstract   The name specifier for the subfamily name.
 */
CT_EXPORT const CFStringRef kCTFontSubFamilyNameKey CT_AVAILABLE(10_5, 3_2);
/*!
 @defined    kCTFontStyleNameKey
 @abstract   The name specifier for the style name.
 */
CT_EXPORT const CFStringRef kCTFontStyleNameKey CT_AVAILABLE(10_5, 3_2);
/*!
 @defined    kCTFontUniqueNameKey
 @abstract   The name specifier for the unique name.
 @discussion Note that this name is often not unique and should not be
 assumed to be truly unique.
 */
CT_EXPORT const CFStringRef kCTFontUniqueNameKey CT_AVAILABLE(10_5, 3_2);
/*!
 @defined    kCTFontFullNameKey
 @abstract   The name specifier for the full name.
 */
CT_EXPORT const CFStringRef kCTFontFullNameKey CT_AVAILABLE(10_5, 3_2);
/*!
 @defined    kCTFontVersionNameKey
 @abstract   The name specifier for the version name.
 */
CT_EXPORT const CFStringRef kCTFontVersionNameKey CT_AVAILABLE(10_5, 3_2);
/*!
 @defined    kCTFontPostScriptNameKey
 @abstract   The name specifier for the PostScript name.
 */
CT_EXPORT const CFStringRef kCTFontPostScriptNameKey CT_AVAILABLE(10_5, 3_2);
/*!
 @defined    kCTFontTrademarkNameKey
 @abstract   The name specifier for the trademark name.
 */
CT_EXPORT const CFStringRef kCTFontTrademarkNameKey CT_AVAILABLE(10_5, 3_2);
/*!
 @defined    kCTFontManufacturerNameKey
 @abstract   The name specifier for the manufacturer name.
 */
CT_EXPORT const CFStringRef kCTFontManufacturerNameKey CT_AVAILABLE(10_5, 3_2);
/*!
 @defined    kCTFontDesignerNameKey
 @abstract   The name specifier for the designer name.
 */
CT_EXPORT const CFStringRef kCTFontDesignerNameKey CT_AVAILABLE(10_5, 3_2);
/*!
 @defined    kCTFontDescriptionNameKey
 @abstract   The name specifier for the description name.
 */
CT_EXPORT const CFStringRef kCTFontDescriptionNameKey CT_AVAILABLE(10_5, 3_2);
/*!
 @defined    kCTFontVendorURLNameKey
 @abstract   The name specifier for the vendor url name.
 */
CT_EXPORT const CFStringRef kCTFontVendorURLNameKey CT_AVAILABLE(10_5, 3_2);
/*!
 @defined    kCTFontDesignerURLNameKey
 @abstract   The name specifier for the designer url name.
 */
CT_EXPORT const CFStringRef kCTFontDesignerURLNameKey CT_AVAILABLE(10_5, 3_2);
/*!
 @defined    kCTFontLicenseNameKey
 @abstract   The name specifier for the license name.
 */
CT_EXPORT const CFStringRef kCTFontLicenseNameKey CT_AVAILABLE(10_5, 3_2);
/*!
 @defined    kCTFontLicenseURLNameKey
 @abstract   The name specifier for the license url name.
 */
CT_EXPORT const CFStringRef kCTFontLicenseURLNameKey CT_AVAILABLE(10_5, 3_2);
/*!
 @defined    kCTFontSampleTextNameKey
 @abstract   The name specifier for the sample text name string.
 */
CT_EXPORT const CFStringRef kCTFontSampleTextNameKey CT_AVAILABLE(10_5, 3_2);
/*!
 @defined    kCTFontPostScriptCIDNameKey
 @abstract   The name specifier for the PostScript CID name.
 */
CT_EXPORT const CFStringRef kCTFontPostScriptCIDNameKey CT_AVAILABLE(10_5, 3_2);


/*! --------------------------------------------------------------------------
 @group Creating Fonts
 *///--------------------------------------------------------------------------
{

/// Returns a new font reference for the given name.
/// example : CTFontCreateWithName((CFStringRef)[UIFont boldSystemFontOfSize:14].fontName, 24, NULL);
CTFontRef CTFontCreateWithName(
							   CFStringRef __nullable      name,
							   CGFloat                     size,
							   const CGAffineTransform * __nullable matrix ) CT_AVAILABLE(10_5, 3_2);

/// Returns a new font reference that best matches the given font descriptor.
CTFontRef CTFontCreateWithFontDescriptor(
										 CTFontDescriptorRef     descriptor,
										 CGFloat                 size,
										 const CGAffineTransform * __nullable matrix ) CT_AVAILABLE(10_5, 3_2);

/*!
 @enum       CTFontOptions
 @abstract   Options for descriptor match and font creation.
 @constant   kCTFontOptionsPreventAutoActivation
			Prevents automatic font activation from taking place.
 @constant   kCTFontOptionsPreferSystemFont
			Font matching will prefer to match Apple system fonts.
 */
typedef CF_OPTIONS(CFOptionFlags, CTFontOptions) {
	kCTFontOptionsDefault               = 0,
	kCTFontOptionsPreventAutoActivation = 1 << 0,
	kCTFontOptionsPreferSystemFont      = 1 << 2
};


/// Returns a new font reference for the given name and options.
CTFontRef CTFontCreateWithNameAndOptions(
										 CFStringRef                 name,
										 CGFloat                     size,
										 const CGAffineTransform * __nullable matrix,
										 CTFontOptions               options ) CT_AVAILABLE(10_6, 3_2);

/// 创建 CTFontRef CTFontCreateWithFontDescriptorAndOptions
CTFontRef CTFontCreateWithFontDescriptorAndOptions(
												   CTFontDescriptorRef     descriptor,
												   CGFloat                 size,
												   const CGAffineTransform * __nullable matrix,
												   CTFontOptions           options ) CT_AVAILABLE(10_6, 3_2);

/*!
 @enum       UI Type constants
 @abstract   These constants represent the specific user interface purpose to specify for font creation.
 @discussion Use these constants with CTFontCreateUIFontForLanguage to indicate the intended user interface usage of the font reference to be created.
 */
typedef CF_ENUM(uint32_t, CTFontUIFontType) {
	kCTFontUIFontNone                   CT_ENUM_AVAILABLE(10_8, 6_0) = (uint32_t)-1,
	kCTFontUIFontUser                   CT_ENUM_AVAILABLE(10_8, 6_0) =  0,
	kCTFontUIFontUserFixedPitch         CT_ENUM_AVAILABLE(10_8, 6_0) =  1,
	kCTFontUIFontSystem                 CT_ENUM_AVAILABLE(10_8, 6_0) =  2,
	kCTFontUIFontEmphasizedSystem       CT_ENUM_AVAILABLE(10_8, 6_0) =  3,
	kCTFontUIFontSmallSystem            CT_ENUM_AVAILABLE(10_8, 6_0) =  4,
	kCTFontUIFontSmallEmphasizedSystem  CT_ENUM_AVAILABLE(10_8, 6_0) =  5,
	kCTFontUIFontMiniSystem             CT_ENUM_AVAILABLE(10_8, 6_0) =  6,
	kCTFontUIFontMiniEmphasizedSystem   CT_ENUM_AVAILABLE(10_8, 6_0) =  7,
	kCTFontUIFontViews                  CT_ENUM_AVAILABLE(10_8, 6_0) =  8,
	kCTFontUIFontApplication            CT_ENUM_AVAILABLE(10_8, 6_0) =  9,
	kCTFontUIFontLabel                  CT_ENUM_AVAILABLE(10_8, 6_0) = 10,
	kCTFontUIFontMenuTitle              CT_ENUM_AVAILABLE(10_8, 6_0) = 11,
	kCTFontUIFontMenuItem               CT_ENUM_AVAILABLE(10_8, 6_0) = 12,
	kCTFontUIFontMenuItemMark           CT_ENUM_AVAILABLE(10_8, 6_0) = 13,
	kCTFontUIFontMenuItemCmdKey         CT_ENUM_AVAILABLE(10_8, 6_0) = 14,
	kCTFontUIFontWindowTitle            CT_ENUM_AVAILABLE(10_8, 6_0) = 15,
	kCTFontUIFontPushButton             CT_ENUM_AVAILABLE(10_8, 6_0) = 16,
	kCTFontUIFontUtilityWindowTitle     CT_ENUM_AVAILABLE(10_8, 6_0) = 17,
	kCTFontUIFontAlertHeader            CT_ENUM_AVAILABLE(10_8, 6_0) = 18,
	kCTFontUIFontSystemDetail           CT_ENUM_AVAILABLE(10_8, 6_0) = 19,
	kCTFontUIFontEmphasizedSystemDetail CT_ENUM_AVAILABLE(10_8, 6_0) = 20,
	kCTFontUIFontToolbar                CT_ENUM_AVAILABLE(10_8, 6_0) = 21,
	kCTFontUIFontSmallToolbar           CT_ENUM_AVAILABLE(10_8, 6_0) = 22,
	kCTFontUIFontMessage                CT_ENUM_AVAILABLE(10_8, 6_0) = 23,
	kCTFontUIFontPalette                CT_ENUM_AVAILABLE(10_8, 6_0) = 24,
	kCTFontUIFontToolTip                CT_ENUM_AVAILABLE(10_8, 6_0) = 25,
	kCTFontUIFontControlContent         CT_ENUM_AVAILABLE(10_8, 6_0) = 26,
	
	kCTFontNoFontType CT_ENUM_DEPRECATED(10_5, 10_11, 3_2, 9_0) = kCTFontUIFontNone,
	kCTFontUserFontType CT_ENUM_DEPRECATED(10_5, 10_11, 3_2, 9_0) = kCTFontUIFontUser,
	kCTFontUserFixedPitchFontType CT_ENUM_DEPRECATED(10_5, 10_11, 3_2, 9_0) = kCTFontUIFontUserFixedPitch,
	kCTFontSystemFontType CT_ENUM_DEPRECATED(10_5, 10_11, 3_2, 9_0) = kCTFontUIFontSystem,
	kCTFontEmphasizedSystemFontType CT_ENUM_DEPRECATED(10_5, 10_11, 3_2, 9_0) = kCTFontUIFontEmphasizedSystem,
	kCTFontSmallSystemFontType CT_ENUM_DEPRECATED(10_5, 10_11, 3_2, 9_0) = kCTFontUIFontSmallSystem,
	kCTFontSmallEmphasizedSystemFontType CT_ENUM_DEPRECATED(10_5, 10_11, 3_2, 9_0) = kCTFontUIFontSmallEmphasizedSystem,
	kCTFontMiniSystemFontType CT_ENUM_DEPRECATED(10_5, 10_11, 3_2, 9_0) = kCTFontUIFontMiniSystem,
	kCTFontMiniEmphasizedSystemFontType CT_ENUM_DEPRECATED(10_5, 10_11, 3_2, 9_0) = kCTFontUIFontMiniEmphasizedSystem,
	kCTFontViewsFontType CT_ENUM_DEPRECATED(10_5, 10_11, 3_2, 9_0) = kCTFontUIFontViews,
	kCTFontApplicationFontType CT_ENUM_DEPRECATED(10_5, 10_11, 3_2, 9_0) = kCTFontUIFontApplication,
	kCTFontLabelFontType CT_ENUM_DEPRECATED(10_5, 10_11, 3_2, 9_0) = kCTFontUIFontLabel,
	kCTFontMenuTitleFontType CT_ENUM_DEPRECATED(10_5, 10_11, 3_2, 9_0) = kCTFontUIFontMenuTitle,
	kCTFontMenuItemFontType CT_ENUM_DEPRECATED(10_5, 10_11, 3_2, 9_0) = kCTFontUIFontMenuItem,
	kCTFontMenuItemMarkFontType CT_ENUM_DEPRECATED(10_5, 10_11, 3_2, 9_0) = kCTFontUIFontMenuItemMark,
	kCTFontMenuItemCmdKeyFontType CT_ENUM_DEPRECATED(10_5, 10_11, 3_2, 9_0) = kCTFontUIFontMenuItemCmdKey,
	kCTFontWindowTitleFontType CT_ENUM_DEPRECATED(10_5, 10_11, 3_2, 9_0) = kCTFontUIFontWindowTitle,
	kCTFontPushButtonFontType CT_ENUM_DEPRECATED(10_5, 10_11, 3_2, 9_0) = kCTFontUIFontPushButton,
	kCTFontUtilityWindowTitleFontType CT_ENUM_DEPRECATED(10_5, 10_11, 3_2, 9_0) = kCTFontUIFontUtilityWindowTitle,
	kCTFontAlertHeaderFontType CT_ENUM_DEPRECATED(10_5, 10_11, 3_2, 9_0) = kCTFontUIFontAlertHeader,
	kCTFontSystemDetailFontType CT_ENUM_DEPRECATED(10_5, 10_11, 3_2, 9_0) = kCTFontUIFontSystemDetail,
	kCTFontEmphasizedSystemDetailFontType CT_ENUM_DEPRECATED(10_5, 10_11, 3_2, 9_0) = kCTFontUIFontEmphasizedSystemDetail,
	kCTFontToolbarFontType CT_ENUM_DEPRECATED(10_5, 10_11, 3_2, 9_0) = kCTFontUIFontToolbar,
	kCTFontSmallToolbarFontType CT_ENUM_DEPRECATED(10_5, 10_11, 3_2, 9_0) = kCTFontUIFontSmallToolbar,
	kCTFontMessageFontType CT_ENUM_DEPRECATED(10_5, 10_11, 3_2, 9_0) = kCTFontUIFontMessage,
	kCTFontPaletteFontType CT_ENUM_DEPRECATED(10_5, 10_11, 3_2, 9_0) = kCTFontUIFontPalette,
	kCTFontToolTipFontType CT_ENUM_DEPRECATED(10_5, 10_11, 3_2, 9_0) = kCTFontUIFontToolTip,
	kCTFontControlContentFontType CT_ENUM_DEPRECATED(10_5, 10_11, 3_2, 9_0) = kCTFontUIFontControlContent
};

/// Returns the special user-interface font for the given language and user-interface type.
CTFontRef __nullable CTFontCreateUIFontForLanguage(
												   CTFontUIFontType    uiType,
												   CGFloat             size,
												   CFStringRef __nullable language ) CT_AVAILABLE(10_5, 3_2);

/// Returns a new font with additional attributes based on the original font.
CTFontRef CTFontCreateCopyWithAttributes(
										 CTFontRef                   font,
										 CGFloat                     size,
										 const CGAffineTransform * __nullable matrix,
										 CTFontDescriptorRef __nullable attributes ) CT_AVAILABLE(10_5, 3_2);

/// Returns a new font in the same font family as the original with the specified symbolic traits.
CTFontRef __nullable CTFontCreateCopyWithSymbolicTraits(
														CTFontRef                   font,
														CGFloat                     size,
														const CGAffineTransform * __nullable matrix,
														CTFontSymbolicTraits        symTraitValue,
														CTFontSymbolicTraits        symTraitMask ) CT_AVAILABLE(10_5, 3_2);

/// Returns a new font in the specified family based on the traits of the original font.
CTFontRef __nullable CTFontCreateCopyWithFamily(
												CTFontRef                   font,
												CGFloat                     size,
												const CGAffineTransform * __nullable matrix,
												CFStringRef                 family ) CT_AVAILABLE(10_5, 3_2);

/// Returns a new font reference that can best map the given string range based on the current font.
CTFontRef CTFontCreateForString(
								CTFontRef       currentFont,
								CFStringRef     string,
								CFRange         range ) CT_AVAILABLE(10_5, 3_2);
	
}


/*! --------------------------------------------------------------------------
 @group Getting Font Data
 *///--------------------------------------------------------------------------
{
/// Returns the normalized font descriptor for the given font reference.
CTFontDescriptorRef CTFontCopyFontDescriptor(CTFontRef       font );
/// Returns the value associated with an arbitrary attribute of the given font.
CFTypeRef __nullable CTFontCopyAttribute(CTFontRef       font, CFStringRef     attribute );

/// Returns the point size of the given font.
CGFloat CTFontGetSize( CTFontRef font ) CT_AVAILABLE(10_5, 3_2);

/// Returns the transformation matrix of the given font.
CGAffineTransform CTFontGetMatrix( CTFontRef font ) CT_AVAILABLE(10_5, 3_2);

/// Returns the symbolic traits of the given font.
CTFontSymbolicTraits CTFontGetSymbolicTraits( CTFontRef font ) CT_AVAILABLE(10_5, 3_2);

/// Returns the traits dictionary of the given font.
CFDictionaryRef CTFontCopyTraits( CTFontRef font ) CT_AVAILABLE(10_5, 3_2);
}

/*! --------------------------------------------------------------------------
 @group Getting Font Names
 *///--------------------------------------------------------------------------
{
/// Returns the PostScript name of the given font.
CFStringRef CTFontCopyPostScriptName( CTFontRef font ) CT_AVAILABLE(10_5, 3_2);

/// Returns the family name of the given font.
CFStringRef CTFontCopyFamilyName( CTFontRef font ) CT_AVAILABLE(10_5, 3_2);

/// Returns the full name of the given font.
CFStringRef CTFontCopyFullName( CTFontRef font ) CT_AVAILABLE(10_5, 3_2);

/// Returns the display name of the given font.
CFStringRef CTFontCopyDisplayName( CTFontRef font ) CT_AVAILABLE(10_5, 3_2);

/// Returns a reference to the requested name of the given font.
CFStringRef __nullable CTFontCopyName(
									  CTFontRef       font,
									  CFStringRef     nameKey ) CT_AVAILABLE(10_5, 3_2);

/// Returns a reference to a localized name for the given font.
CFStringRef __nullable CTFontCopyLocalizedName(
											   CTFontRef       font,
											   CFStringRef     nameKey,
											   CFStringRef __nullable * __nullable actualLanguage ) CT_AVAILABLE(10_5, 3_2);
	
}

/*! --------------------------------------------------------------------------
 @group Working With Encoding
 *///--------------------------------------------------------------------------
{
	
/// Returns the Unicode character set of the font.
CFCharacterSetRef CTFontCopyCharacterSet( CTFontRef font ) CT_AVAILABLE(10_5, 3_2);

/// Returns the best string encoding for legacy format support.
CFStringEncoding CTFontGetStringEncoding( CTFontRef font ) CT_AVAILABLE(10_5, 3_2);

/// Returns an array of languages supported by the font.
CFArrayRef CTFontCopySupportedLanguages( CTFontRef font ) CT_AVAILABLE(10_5, 3_2);

}

/*!
 @function   CTFontGetGlyphsForCharacters
 @abstract   Performs basic character-to-glyph mapping.
 
 @discussion This function only provides the nominal mapping as specified by the font's Unicode cmap (or equivalent); such mapping does not constitute proper Unicode layout: it is the caller's responsibility to handle the Unicode properties of the characters.
 
 @param      font
 The font reference.
 
 @param      characters
 An array of characters (UTF-16 code units). Non-BMP characters must be encoded as surrogate pairs.
 
 @param      glyphs
 A pointer to a buffer to receive the glyphs. Glyphs for non-BMP characters are sparse: the first glyph corresponds to the full character and the second glyph will be 0.
 
 @param      count
 The capacity of both the characters and glyphs arrays.
 
 @result     The return value indicates whether all provided characters were successfully mapped. A return value of true indicates that the font mapped all characters. A return value of false indicates that some or all of the characters were not mapped; glyphs for unmapped characters will be 0 (with the exception of those corresponding non-BMP characters as described above).
 
 @seealso    CTFontCopyCharacterSet
 */
bool CTFontGetGlyphsForCharacters(
								  CTFontRef       font,
								  const UniChar   characters[],
								  CGGlyph         glyphs[],
								  CFIndex         count ) CT_AVAILABLE(10_5, 3_2);

/*! --------------------------------------------------------------------------
 @group Getting Font Metrics
 *///--------------------------------------------------------------------------

/// Returns the scaled font-ascent metric of the given font.
CGFloat CTFontGetAscent( CTFontRef font ) CT_AVAILABLE(10_5, 3_2);

/// Returns the scaled font-descent metric of the given font.
CGFloat CTFontGetDescent( CTFontRef font ) CT_AVAILABLE(10_5, 3_2);

/// Returns the scaled font-leading metric of the given font.
CGFloat CTFontGetLeading( CTFontRef font ) CT_AVAILABLE(10_5, 3_2);

/// Returns the units-per-em metric of the given font.
unsigned CTFontGetUnitsPerEm( CTFontRef font ) CT_AVAILABLE(10_5, 3_2);

/// Returns the number of glyphs of the given font.
CFIndex CTFontGetGlyphCount( CTFontRef font ) CT_AVAILABLE(10_5, 3_2);

/// Returns the scaled bounding box of the given font.
CGRect CTFontGetBoundingBox( CTFontRef font ) CT_AVAILABLE(10_5, 3_2);

/// Returns the scaled underline position of the given font.
CGFloat CTFontGetUnderlinePosition( CTFontRef font ) CT_AVAILABLE(10_5, 3_2);

/// Returns the scaled underline-thickness metric of the given font.
CGFloat CTFontGetUnderlineThickness( CTFontRef font ) CT_AVAILABLE(10_5, 3_2);

/// Returns the slant angle of the given font.
CGFloat CTFontGetSlantAngle( CTFontRef font ) CT_AVAILABLE(10_5, 3_2);

/// Returns the cap-height metric of the given font.
CGFloat CTFontGetCapHeight( CTFontRef font ) CT_AVAILABLE(10_5, 3_2);

/// Returns the x-height metric of the given font.
CGFloat CTFontGetXHeight( CTFontRef font ) CT_AVAILABLE(10_5, 3_2);

/*! --------------------------------------------------------------------------
 @group Getting Glyph Data
 *///--------------------------------------------------------------------------

/// Returns the CGGlyph value for the specified glyph name in the given font.
CGGlyph CTFontGetGlyphWithName(
							   CTFontRef           font,
							   CFStringRef         glyphName ) CT_AVAILABLE(10_5, 3_2);

/// Calculates the bounding rects for an array of glyphs and returns the overall bounding rectangle for the glyph run.
CGRect CTFontGetBoundingRectsForGlyphs(
									   CTFontRef           font,
									   CTFontOrientation   orientation,
									   const CGGlyph       glyphs[],
									   CGRect * __nullable boundingRects,
									   CFIndex             count ) CT_AVAILABLE(10_5, 3_2);

/// Calculates the optical bounding rects for an array of glyphs and returns the overall optical bounding rect for the run.
CGRect CTFontGetOpticalBoundsForGlyphs(
									   CTFontRef           font,
									   const CGGlyph       glyphs[],
									   CGRect * __nullable boundingRects,
									   CFIndex             count,
									   CFOptionFlags       options ) CT_AVAILABLE(10_8, 6_0);

/// Calculates the advances for an array of glyphs and returns the summed advance.
double CTFontGetAdvancesForGlyphs(
								  CTFontRef           font,
								  CTFontOrientation   orientation,
								  const CGGlyph       glyphs[],
								  CGSize * __nullable advances,
								  CFIndex             count ) CT_AVAILABLE(10_5, 3_2);

/// Calculates the offset from the default (horizontal) origin to the vertical origin for an array of glyphs.
void CTFontGetVerticalTranslationsForGlyphs(
											CTFontRef       font,
											const CGGlyph   glyphs[],
											CGSize          translations[],
											CFIndex         count ) CT_AVAILABLE(10_5, 3_2);

/// Creates a path for the specified glyph.
CGPathRef __nullable CTFontCreatePathForGlyph(
											  CTFontRef                   font,
											  CGGlyph                     glyph,
											  const CGAffineTransform * __nullable matrix ) CT_AVAILABLE(10_5, 3_2);

/*! --------------------------------------------------------------------------
 @group Font Variations
 *///--------------------------------------------------------------------------

/*!
 @defined    kCTFontVariationAxisIdentifierKey
 @abstract   Key to get the variation axis identifier.
 @discussion This key is used with a variation axis dictionary to get the axis identifier value as a CFNumberRef.
 */
CT_EXPORT const CFStringRef kCTFontVariationAxisIdentifierKey CT_AVAILABLE(10_5, 3_2);
/*!
 @defined    kCTFontVariationAxisMinimumValueKey
 @abstract   Key to get the variation axis minimum value.
 @discussion This key is used with a variation axis dictionary to get the minimum axis value as a CFNumberRef.
 */
CT_EXPORT const CFStringRef kCTFontVariationAxisMinimumValueKey CT_AVAILABLE(10_5, 3_2);
/*!
 @defined    kCTFontVariationAxisMaximumValueKey
 @abstract   Key to get the variation axis maximum value.
 @discussion This key is used with a variation axis dictionary to get the maximum axis value as a CFNumberRef.
 */
CT_EXPORT const CFStringRef kCTFontVariationAxisMaximumValueKey CT_AVAILABLE(10_5, 3_2);
/*!
 @defined    kCTFontVariationAxisDefaultValueKey
 @abstract   Key to get the variation axis default value.
 @discussion This key is used with a variation axis dictionary to get the default axis value as a CFNumberRef.
 */
CT_EXPORT const CFStringRef kCTFontVariationAxisDefaultValueKey CT_AVAILABLE(10_5, 3_2);
/*!
 @defined    kCTFontVariationAxisNameKey
 @abstract   Key to get the variation axis name string.
 @discussion This key is used with a variation axis dictionary to get the localized variation axis name.
 */
CT_EXPORT const CFStringRef kCTFontVariationAxisNameKey CT_AVAILABLE(10_5, 3_2);

/*!
 @function   CTFontCopyVariationAxes
 @abstract   Returns an array of variation axis dictionaries.
 
 @param      font
 The font reference.
 
 @result     This function returns an array of variation axis dictionaries or null if the font does not support variations. Each variation axis dictionary contains the five kCTFontVariationAxis* keys above.
 */
CFArrayRef __nullable CTFontCopyVariationAxes( CTFontRef font ) CT_AVAILABLE(10_5, 3_2);

/*!
 @function   CTFontCopyVariation
 @abstract   Returns a variation dictionary.
 @discussion This function describes the current configuration of a variation font: a dictionary of number values with variation identifier number keys. As of macOS 10.12 and iOS 10.0, only non-default values (as determined by the variation axis) are returned.
 
 @param      font
 The font reference.
 
 @result     This function returns a variation dictionary or null if the font does not support variations.
 
 @seealso    kCTFontVariationAxisIdentifierKey
 @seealso    kCTFontVariationAxisDefaultValueKey
 */
CFDictionaryRef __nullable CTFontCopyVariation( CTFontRef font ) CT_AVAILABLE(10_5, 3_2);

/*! --------------------------------------------------------------------------
 @group Font Features
 *///--------------------------------------------------------------------------

/*!
 @defined    kCTFontOpenTypeFeatureTag
 @abstract   Key to get the OpenType feature tag.
 @discussion This key can be used with a font feature dictionary to get the tag as a CFStringRef.
 */
CT_EXPORT const CFStringRef kCTFontOpenTypeFeatureTag CT_AVAILABLE(10_10, 8_0);
/*!
 @defined    kCTFontOpenTypeFeatureValue
 @abstract   Key to get the OpenType feature value.
 @discussion This key can be used with a font feature dictionary to get the value as a CFNumberRef.
 */
CT_EXPORT const CFStringRef kCTFontOpenTypeFeatureValue CT_AVAILABLE(10_10, 8_0);
/*!
 @defined    kCTFontFeatureTypeIdentifierKey
 @abstract   Key to get the font feature type value.
 @discussion This key can be used with a font feature dictionary to get the type identifier as a CFNumberRef.
 */
CT_EXPORT const CFStringRef kCTFontFeatureTypeIdentifierKey CT_AVAILABLE(10_5, 3_2);
/*!
 @defined    kCTFontFeatureTypeNameKey
 @abstract   Key to get the font feature name.
 @discussion This key can be used with a font feature dictionary to get the localized type name string as a CFString.
 */
CT_EXPORT const CFStringRef kCTFontFeatureTypeNameKey CT_AVAILABLE(10_5, 3_2);
/*!
 @defined    kCTFontFeatureTypeExclusiveKey
 @abstract   Key to get the font feature exclusive setting.
 @discussion This key can be used with a font feature dictionary to get the the exclusive setting of the feature as a CFBoolean. The value associated with this key indicates whether the feature selectors associated with this type should be mutually exclusive.
 */
CT_EXPORT const CFStringRef kCTFontFeatureTypeExclusiveKey CT_AVAILABLE(10_5, 3_2);
/*!
 @defined    kCTFontFeatureTypeSelectorsKey
 @abstract   Key to get the font feature selectors.
 @discussion This key can be used with a font feature dictionary to get the array of font feature selectors as a CFArrayRef. This is an array of selector dictionaries that contain the values for the following selector keys.
 */
CT_EXPORT const CFStringRef kCTFontFeatureTypeSelectorsKey CT_AVAILABLE(10_5, 3_2);
/*!
 @defined    kCTFontFeatureSelectorIdentifierKey
 @abstract   Key to get the font feature selector identifier.
 @discussion This key can be used with a selector dictionary corresponding to a feature type to obtain the selector identifier value as a CFNumberRef.
 */
CT_EXPORT const CFStringRef kCTFontFeatureSelectorIdentifierKey CT_AVAILABLE(10_5, 3_2);
/*!
 @defined    kCTFontFeatureSelectorNameKey
 @abstract   Key to get the font feature selector name.
 @discussion This key is used with a selector dictionary to get the localized name string for the selector as a CFStringRef.
 */
CT_EXPORT const CFStringRef kCTFontFeatureSelectorNameKey CT_AVAILABLE(10_5, 3_2);
/*!
 @defined    kCTFontFeatureSelectorDefaultKey
 @abstract   Key to get the font feature selector default setting value.
 @discussion This key is used with a selector dictionary to get the default indicator for the selector. This value is a CFBooleanRef which if present and true indicates that this selector is the default setting for the current feature type.
 */
CT_EXPORT const CFStringRef kCTFontFeatureSelectorDefaultKey CT_AVAILABLE(10_5, 3_2);
/*!
 @defined    kCTFontFeatureSelectorSettingKey
 @abstract   Key to get or specify the current feature setting.
 @discussion This key is used with a selector dictionary to get or specify the current setting for the selector. This value is a CFBooleanRef to indicate whether this selector is on or off. If this key is not present, the default setting is used.
 */
CT_EXPORT const CFStringRef kCTFontFeatureSelectorSettingKey CT_AVAILABLE(10_5, 3_2);

/*!
 @function   CTFontCopyFeatures
 @abstract   Returns an array of font features
 
 @param      font
 The font reference.
 
 @result     This function returns an array of font feature dictionaries for the font reference.
 */
CFArrayRef __nullable CTFontCopyFeatures( CTFontRef font ) CT_AVAILABLE(10_5, 3_2);

/*!
 @function   CTFontCopyFeatureSettings
 @abstract   Returns an array of font feature setting tuples
 
 @discussion A setting tuple is a dictionary of a kCTFontFeatureTypeIdentifierKey key-value pair and a kCTFontFeatureSelectorIdentifierKey key-value pair. Each tuple corresponds to an enabled non-default setting. It is the caller's responsibility to handle exclusive and non-exclusive settings as necessary.
 
 @param      font
 The font reference.
 
 @result     This function returns a normalized array of font feature setting dictionaries. The array will only contain the non-default settings that should be applied to the font, or NULL if the default settings should be used.
 */
CFArrayRef __nullable CTFontCopyFeatureSettings( CTFontRef font ) CT_AVAILABLE(10_5, 3_2);

/*! --------------------------------------------------------------------------
 @group Font Conversion
 *///--------------------------------------------------------------------------

/// Returns a Core Graphics font reference and attributes.
CGFontRef CTFontCopyGraphicsFont(
								 CTFontRef           font,
								 CTFontDescriptorRef __nullable * __nullable attributes ) CT_AVAILABLE(10_5, 3_2);

/// Creates a new font reference from an existing Core Graphics font reference.
CTFontRef CTFontCreateWithGraphicsFont(
									   CGFontRef                   graphicsFont,
									   CGFloat                     size,
									   const CGAffineTransform * __nullable matrix,
									   CTFontDescriptorRef __nullable attributes ) CT_AVAILABLE(10_5, 3_2);

#ifndef ATSFONTREF_DEFINED
typedef UInt32 ATSFontRef;
#define ATSFONTREF_DEFINED 1
#endif

/// Returns an ATS font reference and attributes.
ATSFontRef CTFontGetPlatformFont(
								 CTFontRef               font,
								 CTFontDescriptorRef __nullable * __nullable attributes ) CT_AVAILABLE_MAC(10_5);

/// Creates a new font reference from an ATS font reference.
CTFontRef __nullable CTFontCreateWithPlatformFont(
												  ATSFontRef                  platformFont,
												  CGFloat                     size,
												  const CGAffineTransform * __nullable matrix,
												  CTFontDescriptorRef __nullable attributes ) CT_AVAILABLE_MAC(10_5);

/// Returns a font reference for the given QuickDraw instance.
CTFontRef CTFontCreateWithQuickdrawInstance(
											ConstStr255Param __nullable name,
											int16_t             identifier,
											uint8_t             style,
											CGFloat             size ) CT_AVAILABLE_MAC(10_5);

/*! --------------------------------------------------------------------------
 @group Getting Font Table Data
 *///--------------------------------------------------------------------------

enum {
	kCTFontTableBASE    = 'BASE',   // Baseline
	kCTFontTableCFF     = 'CFF ',   // PostScript font program
	kCTFontTableDSIG    = 'DSIG',   // Digital signature
	kCTFontTableEBDT    = 'EBDT',   // Embedded bitmap
	kCTFontTableEBLC    = 'EBLC',   // Embedded bitmap location
	kCTFontTableEBSC    = 'EBSC',   // Embedded bitmap scaling
	kCTFontTableGDEF    = 'GDEF',   // Glyph definition
	kCTFontTableGPOS    = 'GPOS',   // Glyph positioning
	kCTFontTableGSUB    = 'GSUB',   // Glyph substitution
	kCTFontTableJSTF    = 'JSTF',   // Justification
	kCTFontTableLTSH    = 'LTSH',   // Linear threshold
	kCTFontTableMATH    = 'MATH',   // Math
	kCTFontTableOS2     = 'OS/2',   // OS/2 and Windows specific metrics
	kCTFontTablePCLT    = 'PCLT',   // PCL 5 data
	kCTFontTableVDMX    = 'VDMX',   // Vertical device metrics
	kCTFontTableVORG    = 'VORG',   // Vertical origin
	kCTFontTableZapf    = 'Zapf',   // Glyph reference
	kCTFontTableAcnt    = 'acnt',   // Accent attachment
	kCTFontTableAnkr    = 'ankr',   // Anchor points
	kCTFontTableAvar    = 'avar',   // Axis variation
	kCTFontTableBdat    = 'bdat',   // Bitmap data
	kCTFontTableBhed    = 'bhed',   // Bitmap font header
	kCTFontTableBloc    = 'bloc',   // Bitmap location
	kCTFontTableBsln    = 'bsln',   // Baseline
	kCTFontTableCmap    = 'cmap',   // Character to glyph mapping
	kCTFontTableCvar    = 'cvar',   // CVT variation
	kCTFontTableCvt     = 'cvt ',   // Control value table
	kCTFontTableFdsc    = 'fdsc',   // Font descriptor
	kCTFontTableFeat    = 'feat',   // Layout feature
	kCTFontTableFmtx    = 'fmtx',   // Font metrics
	kCTFontTableFpgm    = 'fpgm',   // Font program
	kCTFontTableFvar    = 'fvar',   // Font variation
	kCTFontTableGasp    = 'gasp',   // Grid-fitting/Scan-conversion
	kCTFontTableGlyf    = 'glyf',   // Glyph data
	kCTFontTableGvar    = 'gvar',   // Glyph variation
	kCTFontTableHdmx    = 'hdmx',   // Horizontal device metrics
	kCTFontTableHead    = 'head',   // Font header
	kCTFontTableHhea    = 'hhea',   // Horizontal header
	kCTFontTableHmtx    = 'hmtx',   // Horizontal metrics
	kCTFontTableHsty    = 'hsty',   // Horizontal style
	kCTFontTableJust    = 'just',   // Justification
	kCTFontTableKern    = 'kern',   // Kerning
	kCTFontTableKerx    = 'kerx',   // Extended kerning
	kCTFontTableLcar    = 'lcar',   // Ligature caret
	kCTFontTableLtag    = 'ltag',   // Language tags
	kCTFontTableLoca    = 'loca',   // Index to location
	kCTFontTableMaxp    = 'maxp',   // Maximum profile
	kCTFontTableMort    = 'mort',   // Morph
	kCTFontTableMorx    = 'morx',   // Extended morph
	kCTFontTableName    = 'name',   // Naming table
	kCTFontTableOpbd    = 'opbd',   // Optical bounds
	kCTFontTablePost    = 'post',   // PostScript information
	kCTFontTablePrep    = 'prep',   // CVT program
	kCTFontTableProp    = 'prop',   // Properties
	kCTFontTableSbit    = 'sbit',   // Bitmap data
	kCTFontTableSbix    = 'sbix',   // Extended bitmap data
	kCTFontTableTrak    = 'trak',   // Tracking
	kCTFontTableVhea    = 'vhea',   // Vertical header
	kCTFontTableVmtx    = 'vmtx'    // Vertical metrics
};
typedef FourCharCode CTFontTableTag;

typedef CF_OPTIONS(uint32_t, CTFontTableOptions) {
	kCTFontTableOptionNoOptions CT_ENUM_AVAILABLE(10_5, 3_2) = 0,
	kCTFontTableOptionExcludeSynthetic CT_ENUM_DEPRECATED(10_5, 10_8, 3_2, 6_0) = (1 << 0)
};

/// Returns an array of font table tags.
CFArrayRef __nullable CTFontCopyAvailableTables(
												CTFontRef           font,
												CTFontTableOptions  options ) CT_AVAILABLE(10_5, 3_2);

/// Returns a reference to the font table data.
CFDataRef __nullable CTFontCopyTable(
									 CTFontRef           font,
									 CTFontTableTag      table,
									 CTFontTableOptions  options ) CT_AVAILABLE(10_5, 3_2);

/// Renders the given glyphs of a font at the specified positions in the supplied graphics context.
void CTFontDrawGlyphs(
					  CTFontRef       font,
					  const CGGlyph   glyphs[],
					  const CGPoint   positions[],
					  size_t          count,
					  CGContextRef    context ) CT_AVAILABLE(10_7, 4_2);


/// Returns caret positions within a glyph.
CFIndex CTFontGetLigatureCaretPositions(
										CTFontRef       font,
										CGGlyph         glyph,
										CGFloat * __nullable positions,
										CFIndex         maxPositions ) CT_AVAILABLE(10_5, 3_2);

/*! --------------------------------------------------------------------------
 @group Baseline Alignment
 *///--------------------------------------------------------------------------

/*!
 @defined    kCTBaselineClassRoman
 
 @abstract   Key to reference the Roman baseline class.
 
 @discussion This key can be used with a baseline info dictionary to offset to the Roman baseline as a CFNumberRef float. It can also be used as the value for kCTBaselineClassAttributeName.
 */
CT_EXPORT const CFStringRef kCTBaselineClassRoman CT_AVAILABLE(10_8, 6_0);

/*!
 @defined    kCTBaselineClassIdeographicCentered
 
 @abstract   Key to reference the Ideographic Centered baseline class.
 
 @discussion This key can be used with a baseline info dictionary to offset to the Ideographic Centered baseline as a CFNumberRef float. It can also be used as the value for kCTBaselineClassAttributeName.
 */
CT_EXPORT const CFStringRef kCTBaselineClassIdeographicCentered CT_AVAILABLE(10_8, 6_0);

/*!
 @defined    kCTBaselineClassIdeographicLow
 
 @abstract   Key to reference the Ideographic Low baseline class.
 
 @discussion This key can be used with a baseline info dictionary to offset to the Ideographic Low baseline as a CFNumberRef float. It can also be used as the value for kCTBaselineClassAttributeName.
 */
CT_EXPORT const CFStringRef kCTBaselineClassIdeographicLow CT_AVAILABLE(10_8, 6_0);

/*!
 @defined    kCTBaselineClassIdeographicHigh
 
 @abstract   Key to reference the Ideographic High baseline class.
 
 @discussion This key can be used with a baseline info dictionary to offset to the Ideographic High baseline as a CFNumberRef float. It can also be used as the value for kCTBaselineClassAttributeName.
 */
CT_EXPORT const CFStringRef kCTBaselineClassIdeographicHigh CT_AVAILABLE(10_8, 6_0);

/*!
 @defined    kCTBaselineClassHanging
 
 @abstract   Key to reference the Hanging baseline class.
 
 @discussion This key can be used with a baseline info dictionary to offset to the Hanging baseline as a CFNumberRef float. It can also be used as the value for kCTBaselineClassAttributeName.
 */
CT_EXPORT const CFStringRef kCTBaselineClassHanging CT_AVAILABLE(10_8, 6_0);

/*!
 @defined    kCTBaselineClassMathKey
 
 @abstract   Key to reference the Math baseline class.
 
 @discussion This key can be used with a baseline info dictionary to offset to the Math baseline as a CFNumberRef float. It can also be used as the value for kCTBaselineClassAttributeName.
 */
CT_EXPORT const CFStringRef kCTBaselineClassMath CT_AVAILABLE(10_8, 6_0);

/*!
 @defined    kCTBaselineReferenceFont
 
 @abstract   Key to reference a font for the reference baseline.
 
 @discussion This key can be used to specify a font for the reference baseline. The value is a CTFontRef or the kCTBaselineOriginalFont constant.
 */
CT_EXPORT const CFStringRef kCTBaselineReferenceFont CT_AVAILABLE(10_8, 6_0);

/*!
 @defined    kCTBaselineOriginalFont
 
 @abstract   Use the original font for setting the reference baseline.
 
 @discussion This constant can be used as the value for kCTBaselineReferenceFont to specify that the original font should be used for the reference baseline.
 */
CT_EXPORT const CFStringRef kCTBaselineOriginalFont CT_AVAILABLE(10_8, 6_0);


/*!
 @function   CTFontCopyDefaultCascadeListForLanguages
 @abstract   Return an ordered list of CTFontDescriptorRef's for font fallback derived from the system default fallback region according to the given language preferences. The style of the given is also matched as well as the weight and width of the font is not one of the system UI font, otherwise the UI font fallback is applied.
 
 @param      font
 The font reference.
 
 @param      languagePrefList
 The language preference list - ordered array of CFStringRef's of ISO language codes.
 
 @result     The ordered list of fallback fonts - ordered array of CTFontDescriptors.
 */
CFArrayRef __nullable CTFontCopyDefaultCascadeListForLanguages( CTFontRef font, CFArrayRef __nullable languagePrefList ) CT_AVAILABLE(10_8, 6_0);

CF_ASSUME_NONNULL_END
CF_EXTERN_C_END
CF_IMPLICIT_BRIDGING_DISABLED

#endif



#endif /* jr_CTFont_h */
