//
//  NavigationBarView.h
//
//
//  Created by Teson Draw on 6/8/16.
//  Copyright (c) 2014年 Teson Draw. All rights reserved.
//

#import <UIKit/UIKit.h>

#define IS_IOS6 [[UIDevice currentDevice].systemVersion floatValue] < 7
#define STATUS_BAR_HEIGHT (IS_IOS6 ? 0:20)


@protocol NavigationBarDelegate <NSObject>

- (void)navigationBarLeftButtonAction;

@optional
- (void)navigationBarRightButtonAction;

@end

@interface NavigationBarView : UIView

@property (strong, nonatomic) UILabel   *titleLabel;
@property (nonatomic, strong) UILabel   *leftButtonLabel;

@property (strong, nonatomic) UIButton  *leftButton;
@property (strong, nonatomic) UIButton  *rightButton;

@property (strong, nonatomic) UIButton  *leftSecondButton;
@property (strong, nonatomic) UIButton  *rightSecondButton;

@property (nonatomic, strong) UIView    *leftButtonBackgroundView;

@property (nonatomic, strong) UIImageView *leftButtonImageView;
@property (nonatomic, strong) UIImageView *rightButtonImageView;

@property (nonatomic, assign) id <NavigationBarDelegate> delegate;

/**
 *  图片为背景的导航栏，带设置左右按钮图片参数
 *
 *  @param title                导航条居中显示的标题名字
 *  @param titleColor           标题的字体颜色
 *  @param backgroundImageName  导航条背景的图片名字
 *  @param leftButtonImageName  导航条左部的按钮的图片名字
 *  @param rightButtonImageName 导航条右部的按钮的图片名字
 *
 *  @return 导航条UIView的实例
 */


- (instancetype)initWithTitle:(NSString *)title
                   titleColor:(UIColor *)titleColor
          backgroundImageName:(NSString *)backgroundImageName
          leftButtonImageName:(NSString *)leftButtonImageName
         rightButtonImageName:(NSString *)rightButtonImageName;


/**
 *  颜色为背景的导航栏，带设置左右按钮图片参数
 *
 *  @param title                导航条居中显示的标题名字
 *  @param titleColor           标题的字体颜色
 *  @param backgroundColor      导航条背景色
 *  @param leftButtonImageName  导航条左部的按钮的图片名字
 *  @param rightButtonImageName 导航条右部的按钮的图片名字
 *
 *  @return 导航条UIView的实例
 */
- (instancetype)initWithTitle:(NSString *)title
                   titleColor:(UIColor *)titleColor
              backgroundColor:(UIColor *)backgroundColor
          leftButtonImageName:(NSString *)leftButtonImageName
         rightButtonImageName:(NSString *)rightButtonImageName;


/**
 *  颜色为背景的导航栏，带设置左右按钮图片参数(UIImage)
 *
 *  @param title                导航条居中显示的标题名字
 *  @param titleColor           标题的字体颜色
 *  @param backgroundColor      导航条背景色
 *  @param leftButtonImage      导航条左部的按钮的图片(UIImage)
 *  @param rightButtonImage     导航条右部的按钮的图片(UIImage)
 *
 *  @return 导航条UIView的实例
 */
- (instancetype)initWithTitle:(NSString *)title
                   titleColor:(UIColor *)titleColor
              backgroundColor:(UIColor *)backgroundColor
              leftButtonImage:(UIImage *)leftButtonImage
             rightButtonImage:(UIImage *)rightButtonImage;


/**
 *  @author Teson Draw, 16-06-30 15:06:31
 *
 *  @brief 适用于仅设置左右按钮标题文字的导航栏
 *
 *  @param title            标题
 *  @param titleColor       标题颜色
 *  @param backgroundColor  导航栏背景颜色
 *  @param buttonTitleColor 按钮标题颜色
 *  @param leftButtonName   左部按钮标题文字
 *  @param rightButtonName  右部按钮标题文字
 *
 *  @return 导航条UIView的实例
 */
- (instancetype)initWithTitle:(NSString *)title
                   titleColor:(UIColor *)titleColor
              backgroundColor:(UIColor *)backgroundColor
             buttonTitleColor:(UIColor *)buttonTitleColor
               leftButtonName:(NSString *)leftButtonName
              rightButtonName:(NSString *)rightButtonName;


/**
 *  颜色为背景的导航栏，参数带设置左右按钮标题文字或图片
 *
 *  @param title                导航条居中显示的标题名字
 *  @param titleColor           标题的字体颜色
 *  @param backgroundColor      导航条背景颜色
 *  @param buttonTitleColor     导航条左部的按钮的标题颜色
 *  @param leftButtonName       导航条左部的按钮的标题名字
 *  @param leftButtonImageName  导航条左部的按钮背景图片的名字
 *  @param rightButtonName      导航条右部的按钮的标题名字
 *  @param rightButtonImageName 导航条右部的按钮背景图片的名字
 *
 *  @return 导航条UIView的实例
 */
- (instancetype)initWithTitle:(NSString *)title
                   titleColor:(UIColor *)titleColor
              backgroundColor:(UIColor *)backgroundColor
             buttonTitleColor:(UIColor *)buttonTitleColor
               leftButtonName:(NSString *)leftButtonName
          leftButtonImageName:(NSString *)leftButtonImageName
              rightButtonName:(NSString *)rightButtonName
         rightButtonImageName:(NSString *)rightButtonImageName;

/**
 *  带设置左边按钮起始位置，图片宽度，按钮标题文字，右边按钮仅设置标题文字和图片
 *
 *  @param title                导航条居中显示的标题名字
 *  @param titleColor           标题的字体颜色
 *  @param backgroundColor      导航条背景颜色
 *  @param buttonTitleColor     导航条左部的按钮的标题颜色
 *  @param leftButtonBgViewOriginX  导航条左部的按钮背景视图X轴起始位置
 *  @param leftButtonImageWidth 导航条左部按钮背景图片宽度
 *  @param leftButtonName       导航条左部的按钮的标题名字
 *  @param leftButtonImageName  导航条左部的按钮背景图片的名字
 *  @param rightButtonName      导航条右部的按钮的标题名字
 *  @param rightButtonImageName 导航条右部的按钮背景图片的名字
 *
 *  @return 导航条UIView的实例
 */
- (instancetype)initWithTitle:(NSString *)title
                   titleColor:(UIColor *)titleColor
              backgroundColor:(UIColor *)backgroundColor
             buttonTitleColor:(UIColor *)buttonTitleColor
      leftButtonBgViewOriginX:(CGFloat)leftButtonBgViewOriginX
         leftButtonImageWidth:(CGFloat)leftButtonImageWidth
               leftButtonName:(NSString *)leftButtonName
          leftButtonImageName:(NSString *)leftButtonImageName
              rightButtonName:(NSString *)rightButtonName
         rightButtonImageName:(NSString *)rightButtonImageName;


/**
 *  仅设置左部按钮标题，右部无按钮的情况，可设置按钮的起始位置
 *
 *  @param title                导航条居中显示的标题名字
 *  @param titleColor           标题的字体颜色
 *  @param backgroundColor      导航条背景颜色
 *  @param leftButtonOriginX    左部按钮起始位置
 *  @param leftButtonName       导航条左部的按钮的标题名字
 *  @param leftButtonTitleColor 导航条左部的按钮的标题颜色
 *
 *  @return 导航条UIView的实例
 */
- (instancetype)initWithTitle:(NSString *)title
                   titleColor:(UIColor *)titleColor
              backgroundColor:(UIColor *)backgroundColor
            leftButtonOriginX:(CGFloat)leftButtonOriginX
               leftButtonName:(NSString *)leftButtonName
         leftButtonTitleColor:(UIColor *)leftButtonTitleColor;


/**
 *  左部只有图片按钮，右部无按钮的情况，可设置按钮的起始位置
 *
 *  @param title                导航条居中显示的标题名字
 *  @param titleColor           标题的字体颜色
 *  @param backgroundColor      导航条背景颜色
 *  @param leftButtonOriginX    左部按钮起始位置
 *  @param leftButtonImageName  左部的按钮图片
 *
 *  @return 导航条UIView的实例
 */
- (instancetype)initWithTitle:(NSString *)title
                   titleColor:(UIColor *)titleColor
              backgroundColor:(UIColor *)backgroundColor
            leftButtonOriginX:(CGFloat)leftButtonOriginX
          leftButtonImageName:(NSString *)leftButtonImageName;


/**
 *  带图片起始位置、高度、标题文字、按钮起始位置参数，仅设置左右按钮
 *
 *  @param title                导航条居中显示的标题名字
 *  @param titleColor           标题的字体颜色
 *  @param backgroundColor      导航条背景颜色
 *  @param leftButtonImageName  左部的按钮背景图片
 *  @param leftButtonImageOriginX 左部图片起始位置
 *  @param leftButtonImageHeight 导航条左部按钮背景图片高度
 *  @param leftButtonOriginX    左部按钮起始位置
 *  @param leftButtonName       导航条左部的按钮的标题名字
 *  @param leftButtonTitleColor 导航条左部的按钮的标题颜色
 *  @param rightButtonImageName 导航条右部的按钮背景图片的名字
 *  @param rightButtonImageOriginX 右部图片起始位置
 *  @param rightButtonImageHeight 右部图片高度
 *  @param rightButtonOriginX   右部按钮起始位置
 *  @param rightButtonName      导航条右部的按钮的标题名字
 *  @param rightButtonTitleColor  导航条右部按钮的标题颜色
 *
 *  @return 导航条UIView的实例
 */
- (instancetype)initWithTitle:(NSString *)title
                   titleColor:(UIColor *)titleColor
              backgroundColor:(UIColor *)backgroundColor
          leftButtonImageName:(NSString *)leftButtonImageName
       leftButtonImageOriginX:(CGFloat)leftButtonImageOriginX
        leftButtonImageHeight:(CGFloat)leftButtonImageHeight
            leftButtonOriginX:(CGFloat)leftButtonOriginX
               leftButtonName:(NSString *)leftButtonName
         leftButtonTitleColor:(UIColor *)leftButtonTitleColor
         rightButtonImageName:(NSString *)rightButtonImageName
      rightButtonImageOriginX:(CGFloat)rightButtonImageOriginX
       rightButtonImageHeight:(CGFloat)rightButtonImageHeight
           rightButtonOriginX:(CGFloat)rightButtonOriginX
              rightButtonName:(NSString *)rightButtonName
        rightButtonTitleColor:(UIColor *)rightButtonTitleColor;

/**
 *  自定义导航条 （适用左右共有4个按钮的情况）
 *
 *  @param title                      导航条居中显示的标题名字
 *  @param titleColor                 标题的字体颜色
 *  @param backgroundColor            导航条背景颜色
 *  @param leftButtonName             左一按钮标题名字
 *  @param leftButtonImageName        左一按钮图片名字
 *  @param leftSecondButtonName       左二按钮标题名字
 *  @param leftSecondButtonImageName  左二按钮图片名字
 *  @param rightButtonName            右一按钮标题名字
 *  @param rightButtonImageName       右一按钮图片名字
 *  @param rightSecondButtonName      右二按钮标题名字
 *  @param rightSecondButtonImageName 右二按钮图片名字
 *
 *  @return 导航条UIView的实例
 */
- (instancetype)initWithTitle:(NSString *)title
                   titleColor:(UIColor *)titleColor
              backgroundColor:(UIColor *)backgroundColor
               leftButtonName:(NSString *)leftButtonName
          leftButtonImageName:(NSString *)leftButtonImageName
         leftSecondButtonName:(NSString *)leftSecondButtonName
    leftSecondButtonImageName:(NSString *)leftSecondButtonImageName
              rightButtonName:(NSString *)rightButtonName
         rightButtonImageName:(NSString *)rightButtonImageName
        rightSecondButtonName:(NSString *)rightSecondButtonName
   rightSecondButtonImageName:(NSString *)rightSecondButtonImageName;

@end
