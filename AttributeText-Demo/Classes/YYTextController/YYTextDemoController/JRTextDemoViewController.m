//
//  JRTextDemoViewController.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/2/14.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import "JRTextDemoViewController.h"
#import "TZAssetModel.h"
#import "TZImagePickerController.h"
#import "JRImageManager.h"

@interface JRTextDemoViewController () <TZImagePickerControllerDelegate>

@property (nonatomic, strong) YYLabel	*label;

@end

@implementation JRTextDemoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
	
	[self setupUI];
	
}

/// 初始化界面
- (void)setupUI {
	
	self.view.backgroundColor = [UIColor whiteColor];

	self.label = [[YYLabel alloc] initWithFrame:CGRectMake(20, 80, 400, 200)];
	NSMutableAttributedString *aString = [[NSMutableAttributedString alloc] initWithString:@"TEST"];
	[aString yy_setFont:[UIFont systemFontOfSize:38] range:NSMakeRange(0, aString.length)];
	
	// 设置阴影
	YYTextShadow *shadow = [[YYTextShadow alloc] init];
	shadow.color = [UIColor redColor];
	shadow.offset = CGSizeMake(10, 10);
//	[aString yy_setTextShadow:shadow range:NSMakeRange(0, aString.length)];
	
	// 装饰
	YYTextDecoration *dec = [[YYTextDecoration alloc] init];
	dec.style = YYTextLineStyleThick;
	dec.width = [NSNumber numberWithInt:2];
	dec.color = [UIColor redColor];
//	[aString setYy_textUnderline:dec];
	
	// 边框
	YYTextBorder *border = [[YYTextBorder alloc] init];
	border.lineStyle = YYTextLineStylePatternCircleDot;
	border.strokeColor = [UIColor redColor];
	border.strokeWidth = 1;
	border.insets = UIEdgeInsetsMake(1, 1, 1, 1);
	[aString yy_setTextBorder:border range:NSMakeRange(0, aString.length)];
	
	/// 点击事件
	YYTextHighlight * act = [[YYTextHighlight alloc] init];
	[act setColor:[UIColor redColor]];
	act.tapAction = ^(UIView * _Nonnull containerView, 
					  NSAttributedString * _Nonnull text, 
					  NSRange range, 
					  CGRect rect) {
		NSLog(@"----------- %@", text.string);
	};

	[aString yy_setTextHighlight:act range:NSMakeRange(0, aString.length)];
	
	
	YYTextRubyAnnotation *ruby = [YYTextRubyAnnotation new];
	ruby.textBefore = @"zhù yīn";
	CTRubyAnnotationRef ctRuby = ruby.CTRubyAnnotation;
	if (ctRuby) {
		/// add to attributed string
		[aString yy_setTextRubyAnnotation:ruby range:NSMakeRange(0, aString.length)];
		
		CFRelease(ctRuby);
	}
	
	self.label.attributedText = aString;
	[self.view addSubview:self.label];
	self.label.backgroundColor = [UIColor yellowColor];
}


- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
	
	///
	[JRImageManager getAllAlbum];
	
	
//	[self pushImagePickerController];
//	[self photoAlbum];
//	NSLog(@"=============================== %zd", [PHPhotoLibrary authorizationStatus]);
//	[self imageTest];
//	[self imageTest2];
}

- (void)photoAlbum {
	
	/// 获取相册
	PHFetchOptions *option	= [[PHFetchOptions alloc] init];
//	option.predicate		= [NSPredicate predicateWithFormat:@"mediaType == %ld", PHAssetMediaTypeImage];
//	option.predicate		= [NSPredicate predicateWithFormat:@"mediaType == %ld", PHAssetMediaTypeVideo];
	PHFetchResult *res		= [PHAssetCollection fetchAssetCollectionsWithType:PHAssetCollectionTypeSmartAlbum
																   subtype:PHAssetCollectionSubtypeAlbumRegular
																   options:nil];
	for (PHAssetCollection *colc in res) {
		PHFetchResult *fetchResult = [PHAsset fetchAssetsInAssetCollection:colc options:option];
		if (fetchResult.count > 0) {
			NSLog(@"%@ -- %zd", colc.localizedTitle, fetchResult.count);
		}
	}
	
//	res	= [PHAssetCollection fetchAssetCollectionsWithType:PHAssetCollectionTypeAlbum
//													subtype:PHAssetCollectionSubtypeAlbumRegular
//													options:nil];
//	for (PHAssetCollection *colc in res) {
//		PHFetchResult *fetchResult = [PHAsset fetchAssetsInAssetCollection:colc options:option];
//		if (fetchResult.count > 0) {
//			NSLog(@"%@ -- %zd", colc.localizedTitle, fetchResult.count);
//		}
//	}
	
}

- (void)imageTest {
	[[TZImageManager manager] getAllAlbums:true allowPickingImage:true completion:^(NSArray<TZAlbumModel *> *models) {
		for (TZAlbumModel *m in models) {
			NSLog(@"%@ - %zd == %@", m.name, m.count, [m.result class]);
		}
	}];
	
}

- (void)imageTest2 {
	
	[[TZImageManager manager] getCameraRollAlbum:true allowPickingImage:true completion:^(TZAlbumModel *m) {
		NSLog(@"%@ - %zd == %@", m.name, m.count, [m.result class]);
	}];
}


/// 选择图片
- (void)pushImagePickerController {

	TZImagePickerController *imagePickerVc = [[TZImagePickerController alloc] initWithMaxImagesCount:9
																						columnNumber:4 
																							delegate:self 
																				   pushPhotoPickerVc:YES];
	
	
#pragma mark - 四类个性化设置，这些参数都可以不传，此时会走默认设置
	imagePickerVc.isSelectOriginalPhoto = YES;
	imagePickerVc.allowTakePicture		= YES; // 在内部显示拍照按钮

	imagePickerVc.allowPickingGif		= YES;
	imagePickerVc.allowPickingVideo		= YES;
	imagePickerVc.allowPickingImage		= YES;
	imagePickerVc.allowPickingOriginalPhoto			= YES;
	imagePickerVc.sortAscendingByModificationDate	= YES;

	/// 5. 单选模式,maxImagesCount为1时才生效
	imagePickerVc.allowCrop			= YES;
	imagePickerVc.showSelectBtn		= NO;
	imagePickerVc.needCircleCrop	= YES;
	imagePickerVc.circleCropRadius	= 100;
	
	// You can get the photos by block, the same as by delegate.
	// 你可以通过block或者代理，来得到用户选择的照片.
	[imagePickerVc setDidFinishPickingPhotosHandle:^(NSArray<UIImage *> *photos, NSArray *assets, BOOL isSelectOriginalPhoto) {
		
	}];
	
	[self presentViewController:imagePickerVc animated:YES completion:nil];
}

@end
