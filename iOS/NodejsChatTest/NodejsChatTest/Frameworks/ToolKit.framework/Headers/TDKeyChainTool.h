//
//  TDKeyChainTool.h
//  StringTest
//
//  Created by Teson Draw on 2017/5/8.
//  Copyright © 2017年 Teson Draw. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TDKeyChainTool : NSObject

+ (void)save:(NSString *)service data:(id)data;
+ (id)load:(NSString *)service;
+ (void)deleteKeyData:(NSString *)service;

@end
