//
//  JRCollectionViewCell.h
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/2/16.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import <UIKit/UIKit.h>

@class JRCModel;
@interface JRCollectionViewCell : UICollectionViewCell

/// 内容
@property (nonatomic, strong) NSDictionary	*contentDic;

@property (nonatomic, strong) JRCModel	*model;

@end
