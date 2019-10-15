//
//  SocketClient.m
//  NodejsChatTest
//
//  Created by Teson Draw on 2017/8/23.
//  Copyright © 2017年 Teson Draw. All rights reserved.
//

#import "SocketClient.h"



@interface SocketClient ()
{
    SocketManager * _manager;
    SocketIOClient *_socketIO;
}


@end

static SocketClient *sharedInstance;

@implementation SocketClient


+ (SocketClient *)sharedInstance {
    
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[SocketClient alloc] init];
    });
    
    return sharedInstance;
}

- (void)initSocket {
//    NSURL* url = [[NSURL alloc] initWithString:@"http://192.168.120.187:9090"];
    NSURL *url = [NSURL URLWithString:@"192.168.22.90:8000"];
//    _socketIO = [[SocketIOClient alloc] initWithSocketURL:url config:nil];
    
    _manager = [[SocketManager alloc] initWithSocketURL:url config:nil];//@{@"log": @YES, @"compress": @YES}
    //    SocketIOClient* socket = manager.defaultSocket;
    
    _socketIO = _manager.defaultSocket;
    
    [self initEventCallback];
    
    [_socketIO connect];
}

//- (void)initSocket {
//    NSURL * url = [NSURL URLWithString:@"192.168.22.90:8000"];//[NSURL URLWithString:[[SettingTool shareSetting] imBaseUrl]];
//    xxx = [[SocketIOClient alloc] initWithSocketURL:url config:nil];
////    [self setDefaultEventsCallback];
////    [self setBusinessEventsCallback];
////    
////    [_socketIO connect];
//}

- (void)initEventCallback {
    
    __block typeof(self)weakSelf = self;
    
    [_socketIO on:@"connect" callback:^(NSArray* data, SocketAckEmitter* ack) {
        NSLog(@"connect-%@\n%@", data, ack);
        
//        [weakSelf performSelector:@selector(didConnectToSocketIOServer) withObject:nil afterDelay:0.1];

    }];
    
    [_socketIO on:@"disconnect" callback:^(NSArray * _Nonnull data, SocketAckEmitter * _Nonnull ack) {
        NSLog(@"disconnect-%@\n%@", data, ack);
//        if (self.autoReconnectBlock) {
//            self.autoReconnectBlock();
//        }
    }];
    
    [_socketIO on:@"error" callback:^(NSArray * _Nonnull data, SocketAckEmitter * _Nonnull ack) {
        NSLog(@"error-%@\n%@", data, ack);
        
//        if (_imDelegate && [_imDelegate respondsToSelector:@selector(imErrorMessage:)]) {
//            
//            if (data.count > 0) {
//                NSString *message = data[0];
//                
//                if ([message isKindOfClass:[NSString class]]) {
//                    [_imDelegate imErrorMessage:message];
//                }
//            }
//        }
    }];
    
    [_socketIO on:@"reconnect" callback:^(NSArray * _Nonnull data, SocketAckEmitter * _Nonnull ack) {
        NSLog(@"reconnect-%@\n%@", data, ack);
//        if (self.userInfo) {
//            [self loginWithUserId:self.userInfo.userId project:self.userInfo.project token:self.userInfo.token callback:^(BOOL flag, NSDictionary * _Nullable result) {
//                NSLog(@"重连后验证 %@", result);
//            }];
//        }
    }];
    
    [_socketIO on:@"reconnectAttempt" callback:^(NSArray * _Nonnull data, SocketAckEmitter * _Nonnull ack) {
        NSLog(@"reconnectAttempt-%@\n%@", data, ack);
    }];
}

- (void)setReceiveOnlineMessage {
    [_socketIO on:@"receive" callback:^(NSArray * _Nonnull data, SocketAckEmitter * _Nonnull ack) {
        NSLog(@"receive data:%@", data);
//        NSLog(@"data count:%ld, contents:%@", data.count, data[0]);
//
//        BOOL bType = [data[0] isKindOfClass:[NSString class]];
//
//        if (bType) {
//            NSLog(@"NSString type");
//        } else {
//            NSLog(@"not NSString type");
//        }
//
//        bType = [data[0] isKindOfClass:[NSData class]];
//        if (bType) {
//            NSLog(@"NSData type");
//            Login *receiveData = [[Login alloc] initWithData:data[0] error:nil];
//
//            NSLog(@"Login data:%@", receiveData);
//
//            NSLog(@"\naccount is:%@\npassword is:%@", receiveData.account, receiveData.password);
//        } else {
//            NSLog(@"not NSData type");
//        }
        
    }];
}

- (void)send2ButtonAction {
    
//    Login *loginInfo = [Login new];
//    loginInfo.account = @"20181008";
//    loginInfo.password = @"666888";
//
//    NSData *data = [loginInfo data];
//
//    OnAckCallback *ackCallback = [_socketIO emitWithAck:@"test" with:@[data]];
//    [ackCallback timingOutAfter:3 callback:^(NSArray * _Nonnull data) {
//        //        NSLog(@"data:%@, %@", data, data[0]);
//        NSLog(@"data:%@", data);
//        //        BOOL bType = [data[0] isKindOfClass:[NSString class]];
//        //
//        //        if (bType) {
//        //            NSLog(@"string type");
//        //        } else {
//        //            NSLog(@"not string type");
//        //        }
//    }];
}

@end
