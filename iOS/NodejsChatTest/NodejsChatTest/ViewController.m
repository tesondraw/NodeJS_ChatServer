//
//  ViewController.m
//  NodejsChatTest
//
//  Created by Teson Draw on 2017/8/23.
//  Copyright © 2017年 Teson Draw. All rights reserved.
//

#import "ViewController.h"

#import "SocketClient.h"

#import <Jetfire/Jetfire.h>

@interface ViewController () <JFRWebSocketDelegate>

@property (nonatomic, strong) JFRWebSocket *socket;
@property (nonatomic, strong) UIButton *sendButton;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
//    [[SocketClient sharedInstance] initSocket];
    
    [self JFRWebSocketInit];
}

- (void)JFRWebSocketInit {
    self.socket = [[JFRWebSocket alloc] initWithURL:[NSURL URLWithString:@"ws://192.168.22.90:8181"] protocols:@[@"chat",@"superchat"]];
    self.socket.delegate = self;
    [self.socket connect];
    
    [self.view addSubview:self.sendButton];
}

/**
 The websocket connected to its host.
 @param socket is the current socket object.
 */
-(void)websocketDidConnect:(nonnull JFRWebSocket*)socket{
    // MARK: - <label name>
    NSLog(@"websocket did connect");
}

/**
 The websocket was disconnected from its host.
 @param socket is the current socket object.
 @param error  is return an error occured to trigger the disconnect.
 */
-(void)websocketDidDisconnect:(nonnull JFRWebSocket*)socket error:(nullable NSError*)error {
    NSLog(@"did disconnect:%@", error.localizedDescription);
}

/**
 The websocket got a text based message.
 @param socket is the current socket object.
 @param string is the text based data that has been returned.
 */
-(void)websocket:(nonnull JFRWebSocket*)socket didReceiveMessage:(nonnull NSString*)string {
    NSLog(@"%@", string);
}

/**
 The websocket got a binary based message.
 @param socket is the current socket object.
 @param data   is the binary based data that has been returned.
 */
-(void)websocket:(nonnull JFRWebSocket*)socket didReceiveData:(nullable NSData*)data {
    NSLog(@"data:%@", data);
}


- (UIButton *)sendButton {
    if (!_sendButton) {
        _sendButton = [[UIButton alloc] initWithFrame:CGRectMake(20, 40, 44, 44)];
        [_sendButton setTitle:@"发送" forState:UIControlStateNormal];
        [_sendButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        
        [_sendButton addTarget:self action:@selector(sendButtonAction) forControlEvents:UIControlEventTouchUpInside];
        _sendButton.layer.borderWidth = 1;
        _sendButton.layer.borderColor = [UIColor blackColor].CGColor;
        // TODO: <text you want to remember>
    }
    return _sendButton;
}




- (void)sendButtonAction {
//    [self.socket writeString:@"hello world"];
    
    NSDictionary *extraDic = @{@"type":@"text"};
    NSDictionary *dic = @{@"senderID":@"13980557234",
                          @"senderName":@"卓天成",
                          @"receiverID":@"13808044804",
                          @"object":extraDic};
    
    NSData *data = [NSJSONSerialization dataWithJSONObject:dic options:NSJSONWritingPrettyPrinted error:nil];
    
    // FIXME:<xxxxx>
    [self.socket writeData:data];
}

@end
