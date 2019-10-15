//
//  SVProgressHUD+Category.h
//  AHCResidentClient
//
//  Created by Teson Draw on 4/15/16.
//  Copyright © 2016 arrcen. All rights reserved.
//

#import "SVProgressHUD.h"

@interface SVProgressHUD (Category)

+ (void)showWithStatus:(NSString *)status duration:(NSTimeInterval)duration;


+ (void)showWithStatus:(NSString *)status maskType:(SVProgressHUDMaskType)maskType duration:(NSTimeInterval)duration;

@end
