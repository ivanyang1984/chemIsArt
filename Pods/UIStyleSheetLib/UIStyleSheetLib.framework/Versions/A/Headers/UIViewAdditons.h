//
//  UIViewAdditons.h
//  xiamiHD
//
//  Created by go886 on 11-9-27.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (xiamiUIView)
@property(nonatomic)CGFloat  left;
@property(nonatomic)CGFloat  right;
@property(nonatomic)CGFloat  top;
@property(nonatomic)CGFloat  bottom;
@property(nonatomic)CGFloat  width;
@property(nonatomic)CGFloat  height;
@property(nonatomic)CGFloat  centerX;
@property(nonatomic)CGFloat  centerY;
@property(nonatomic)CGFloat  cornerRadius;
@property(nonatomic)CGFloat  borderWidth;
//@property(nonatomic,retain)UIColor* borderColor;
//@property(nonatomic)CGSize shadowOffset;
//@property(nonatomic,retain)UIColor* shadowColor;

- (void)removeAllSubViews;
- (void)closeKeyboard;
- (UIImage*)toImage;
@end
