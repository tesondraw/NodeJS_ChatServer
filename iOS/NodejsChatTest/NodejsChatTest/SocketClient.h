//
//  SocketClient.h
//  NodejsChatTest
//
//  Created by Teson Draw on 2017/8/23.
//  Copyright © 2017年 Teson Draw. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <SocketIO/SocketIO-Swift.h>


@interface SocketClient : NSObject

+ (SocketClient *)sharedInstance;


- (void)initSocket;

@end
