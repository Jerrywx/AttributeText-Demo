#Common Text Layout Operations

This chapter describes some common text layout operations and shows how they can be performed using Core Text. The following operations with code listings are included in this chapter:

* Laying Out a Paragraph
* Simple Text Label
* Columnar Layout
* Manual Line Breaking
* Applying a Paragraph Style
* Displaying Text in a Nonrectangular Region

##Laying Out a Paragraph

One of the most common operations in typesetting is laying out a multiline paragraph within an arbitrarily sized rectangular area. Core Text makes this operation easy, requiring only a few lines of Core Text–specific code. To lay out the paragraph, you need a graphics context to draw into, a rectangular path to provide the area where the text is laid out, and an attributed string. Most of the code in this example is required to create and initialize the context, path, and string. After that is done, Core Text requires only three lines of code to do the layout.

常见排版操作的一种是在一个固定大小的矩形区域绘制一个多行的段落。CoreText 可很简单的实现这个操作, 只需要简单的几行代码。绘制段落前你需要在获取的图形上下文中绘制一个矩形区域, 用于绘制文本。实例中的大多数代码被用于获取上下文，创建路径和字符串。做完这些操作后 CoreText 只需调用三句话来绘制文本。

The code in Listing 2-1 shows how a paragraph is laid out. This code could reside in the drawRect: method of a UIView subclass (an NSView subclass in OS X).
列表2-1展示了段落的绘制, 这些代码在 UIView或者NSView的 drawRect:方法 中被调用。

######Listing 2-1  Typesetting a simple paragraph

```
// Initialize a graphics context in iOS.
CGContextRef context = UIGraphicsGetCurrentContext();
 
// Flip the context coordinates, in iOS only.
CGContextTranslateCTM(context, 0, self.bounds.size.height);
CGContextScaleCTM(context, 1.0, -1.0);
 
// Initializing a graphic context in OS X is different:
// CGContextRef context =
//     (CGContextRef)[[NSGraphicsContext currentContext] graphicsPort];
 
// Set the text matrix.
CGContextSetTextMatrix(context, CGAffineTransformIdentity);
 
// Create a path which bounds the area where you will be drawing text.
// The path need not be rectangular.
CGMutablePathRef path = CGPathCreateMutable();
 
// In this simple example, initialize a rectangular path.
CGRect bounds = CGRectMake(10.0, 10.0, 200.0, 200.0);
CGPathAddRect(path, NULL, bounds );
 
// Initialize a string.
CFStringRef textString = CFSTR("Hello, World! I know nothing in the world that has as much power as a word. Sometimes I write one, and I look at it, until it begins to shine.");
 
// Create a mutable attributed string with a max length of 0.
// The max length is a hint as to how much internal storage to reserve.
// 0 means no hint.
CFMutableAttributedStringRef attrString =
         CFAttributedStringCreateMutable(kCFAllocatorDefault, 0);
 
// Copy the textString into the newly created attrString
CFAttributedStringReplaceString (attrString, CFRangeMake(0, 0),
         textString);
 
// Create a color that will be added as an attribute to the attrString.
CGColorSpaceRef rgbColorSpace = CGColorSpaceCreateDeviceRGB();
CGFloat components[] = { 1.0, 0.0, 0.0, 0.8 };
CGColorRef red = CGColorCreate(rgbColorSpace, components);
CGColorSpaceRelease(rgbColorSpace);
 
// Set the color of the first 12 chars to red.
CFAttributedStringSetAttribute(attrString, CFRangeMake(0, 12),
         kCTForegroundColorAttributeName, red);
 
// Create the framesetter with the attributed string.
CTFramesetterRef framesetter =
         CTFramesetterCreateWithAttributedString(attrString);
CFRelease(attrString);
 
// Create a frame.
CTFrameRef frame = CTFramesetterCreateFrame(framesetter,
          CFRangeMake(0, 0), path, NULL);
 
// Draw the specified frame in the given context.
CTFrameDraw(frame, context);
 
// Release the objects we used.
CFRelease(frame);
CFRelease(path);
CFRelease(framesetter);

```







