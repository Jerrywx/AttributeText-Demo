#Core Text Programming Guide

##About Core Text

Core Text is an advanced, low-level technology for laying out text and handling fonts. The Core Text API, introduced in Mac OS X v10.5 and iOS 3.2, is accessible from all OS X and iOS environments.

>Important: Core Text is intended for developers who must do text layout and font handling at a low level, such as developers of layout engines. You should develop your app using a higher-level framework if possible—that is, use Text Kit in iOS (see Text Programming Guide for iOS) or the Cocoa text system in OS X (see Cocoa Text Architecture Guide). Core Text is the technology underlying those text systems, so they share in its speed and efficiency. In addition, Text Kit and the Cocoa text system provide rich text editing, full-featured page layout engines, and other infrastructure that your app would otherwise need to provide if it used Core Text alone.