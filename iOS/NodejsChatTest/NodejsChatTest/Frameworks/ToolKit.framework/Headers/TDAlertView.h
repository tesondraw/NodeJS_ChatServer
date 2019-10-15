//
//  TDAlertView.h
//  Alert
//
//  Created by Teson Draw on 14/12/5.
//  Copyright (c) 2014年 Teson Draw. All rights reserved.
//

#import <UIKit/UIKit.h>



typedef NS_ENUM(NSInteger, TDAlertViewStyle)
{
    TDAlertViewStyleSuccess,
    TDAlertViewStyleFailure
};

//协议
@protocol TDAlertViewDelegate <NSObject>

@optional

- (void)alertClickConfirm;
- (void)removeWindow;

@end

@interface TDAlertView : UIView

//代理对象,内存管理属性必须是weak或者asign,对象必须遵循协议,类型为id(任意类型的可以,遵循协议)
@property (assign, nonatomic) id<TDAlertViewDelegate> delegate;


- (instancetype)initWithFrame:(CGRect)frame
                          msg:(NSString *)msg
                        delay:(NSTimeInterval)delay;


+ (void)showMsg:(NSString *)msg
       duration:(NSTimeInterval)duration;

+ (void)showMsg:(NSString *)msg
   confirmTitle:(NSString *)confirm
         cancel:(NSString *)cancel
       delegate:(id <TDAlertViewDelegate>)delegate;


#pragma mark - Alert View with Animation
+ (void)showWithStyle:(TDAlertViewStyle)style
                title:(NSString *)title
             duration:(NSTimeInterval)duration;

+ (void)showInFrame:(CGRect)frame
          ImageName:(NSString *)imageName
            message:(NSString *)message
           duration:(NSTimeInterval)duration;

+ (void)showInFrame:(CGRect)frame
          ImageName:(NSString *)imageName
            message:(NSString *)message
           duration:(NSTimeInterval)duration
        orientation:(UIInterfaceOrientation)orientation;

@end


