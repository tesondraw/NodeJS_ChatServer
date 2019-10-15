//
//  ZebraStripeView.h
//  RoundProgressTest
//
//  Created by Teson Draw on 1/11/17.
//  Copyright © 2017 Teson Draw. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ZebraStripeView : UIView


- (void)setProgress:(float)progress;///<0~1之间

- (void)setStatus:(NSString *)status;


- (void)setCompletedUnit:(int)unit;
- (void)setTotalUnit:(int)unit;

- (void)setProgressBackgroundColor:(UIColor *)color;
- (void)setTotalUnitLabelColor:(UIColor *)color;


- (void)stopTimer;

//调试用
- (void)reset;

@end
