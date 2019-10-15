//
//  BiolandBluetooth.h
//  AHCResidentClient
//
//  Created by Teson Draw on 5/3/16.
//  Copyright © 2016 arrcen. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

#import "BiolandBPMModel.h"
#import "BluetoothModel.h"


typedef void(^TurnOnBluetoothSuccess)();
typedef void(^ConnectPeripheralSuccess)(void);
typedef void(^ConnectPeripheralFailure)(NSString *errorMsg);

typedef void(^DisconnectPeripheralSuccessBlock)(void);
typedef void(^DisconnectPeripheralFailureBlock)(NSString *errorMsg);

//获取所有参数成功与失败Block
typedef void(^GetAllSetSuccessBlock)(NSDictionary *resultDic);
typedef void(^GetAllSetFailureBlock)(NSDictionary *resultDic);

//读取设置成功与失败Block（SN、电量、版本号）
typedef void(^ReadSetSuccessBlock)(NSString *message);
typedef void(^ReadSetFailureBlock)(NSDictionary *resultDic);

//写设置成功与失败Block
typedef void(^WriteSetSuccessBlock)(NSString *message);
typedef void(^WriteSetFailureBlock)(NSDictionary *resultDic);



typedef NS_ENUM(NSUInteger, InstrumentType) {
    InstrumentBloodPressureMonitor,
    InstrumentBloodGlucoseMonitor,
    InstrumentSeuicRingScanner
};


typedef NS_ENUM(NSUInteger, ScannerOption) {
    ScannerOptionGetVersion,
    ScannerOptionPower,
    ScannerOptionReadSN,
};

typedef NS_ENUM(NSUInteger, ScannerProtocol) {
    ScannerProtocolHID,
    ScannerProtocolSPP
};

typedef NS_ENUM(NSUInteger, ScannerSwitchOption) {
    ScannerSwitchOptionSound,
    ScannerSwitchOptionVibration
};

typedef NS_ENUM(NSUInteger, ScannerWriteOption) {
    ScannerWriteOptionBarCodePrefix,
    ScannerWriteOptionBarCodeSuffix,
    ScannerWriteOptionSN
};



@protocol BluetoothDelegate <NSObject>

@optional

/* 找到指定设备 */
- (void)didFindBluetoothDevice:(NSString *)deviceName;

/* 找到任意一个设备 */
- (void)didFindPeripheralWithModel:(BluetoothModel *)model;

/* 断开蓝牙连接 */
- (void)didDisconnectBluetoothDevice;


@optional
/* 血压实时数据代理方法 */
- (void)didReceiveBloodPressureProcessData:(BiolandBPMModel *)model;

/* 血压最终结果代理方法 */
- (void)didReceiveBloodPressureResultData:(BiolandBPMModel *)model;

/* 血糖结果代理方法 */
- (void)didReceiveBloodGlucoseData:(float)data;


/* 条码扫描相关代理方法 */
- (void)didReceiveBarcodeData:(NSString *)data;///<接收到条码数据

- (void)readyToReceiveBarcodeData;///<准备好接收条码
- (void)setScannerWithResponse:(NSString *)response;///<设置扫描枪

@end



@interface Bluetooth : NSObject



- (instancetype)initWithDelegate:(id <BluetoothDelegate>)delegate
                  instrumentType:(InstrumentType)instrumentType;


/* 带成功回调的初始化方法 */
- (instancetype)initWithDelegate:(id <BluetoothDelegate>)delegate
                  instrumentType:(InstrumentType)instrumentType
                         success:(TurnOnBluetoothSuccess)success;


/* 本机蓝牙当前状态 */
- (CBManagerState)currentState;


//蓝牙设备是否打开
- (BOOL)isTurnOn;///<蓝牙设备是否打开

//是否连接到某个蓝牙设备
- (BOOL)isConnectPeripheral;///<是否连接到某个蓝牙设备

//设置蓝牙
- (void)setBluetooth;///<打开系统蓝牙设置界面


/* 开始扫描 */
- (void)scan;///<开始扫描


/* 停止扫描 */
- (void)stopScan;///<停止扫描


/* 连接指定设备 */
- (void)connectPeripheral:(CBPeripheral *)peripheral
                  success:(ConnectPeripheralSuccess)succes
                  failure:(ConnectPeripheralFailure)failure;


/* 断开蓝牙连接 */
- (void)disconnectPeripheral:(CBPeripheral *)peripheral
                     success:(DisconnectPeripheralSuccessBlock)success
                     failure:(DisconnectPeripheralFailureBlock)failure;


/**
 *  读取扫描仪设置，包含SN、版本号、电量
 */
- (void)readScannerSetWithOption:(ScannerOption)option Success:(ReadSetSuccessBlock)success failure:(ReadSetFailureBlock)failure;///<读取扫描仪设置，包含SN、版本号、电量


/* 读取扫描仪所有选项，不包含铃音、振动等选项 */
- (void)getAllScannerSetSuccess:(GetAllSetSuccessBlock)success failure:(GetAllSetFailureBlock)failure;


/**
 *  扫描仪铃音、振动开关设置
 */
- (void)setScannerSwitchOption:(ScannerSwitchOption)option value:(int)value success:(WriteSetSuccessBlock)success failure:(WriteSetFailureBlock)failure;///<扫描仪铃音、振动开关设置


/**
 *  添加、删除前缀后缀，写入SN专用
 */
- (void)setScannerWithOption:(ScannerWriteOption)option value:(NSString *)value success:(WriteSetSuccessBlock)success failure:(WriteSetFailureBlock)failure;///<添加、删除前缀后缀，写入SN专用


/**
 *  更改扫描仪设置，带有数值参数
 */
- (void)setScannerWithParamID:(int)paramID value:(int)value success:(WriteSetSuccessBlock)success failure:(WriteSetFailureBlock)failure;///<更改扫描仪设置，带有数值参数


/**
 *  切换扫描仪协议
 */
- (void)setScannerProtocol:(ScannerProtocol)protocol success:(WriteSetSuccessBlock)success failure:(WriteSetFailureBlock)failure;///<切换扫描仪协议


/**
 *  读取扫描仪单个设置
 */
- (void)getSannerSetWithParamID:(int)paramID;///<读取扫描仪单个设置




@end

