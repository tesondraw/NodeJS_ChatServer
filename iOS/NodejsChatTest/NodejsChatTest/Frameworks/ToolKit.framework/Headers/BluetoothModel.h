//
//  BluetoothModel.h
//  FrameworkProject
//
//  Created by Teson Draw on 11/18/16.
//  Copyright © 2016 Teson Draw. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <CoreBluetooth/CoreBluetooth.h>



@interface BluetoothModel : NSObject

@property (nonatomic, strong) CBPeripheral *peripheral;
@property (nonatomic, strong) NSDictionary *advertisementData;
@property (nonatomic, strong) NSNumber *RSSI;

/* JS回调使用 */
@property (nonatomic, strong) NSMutableDictionary *deviceDic;

@end
