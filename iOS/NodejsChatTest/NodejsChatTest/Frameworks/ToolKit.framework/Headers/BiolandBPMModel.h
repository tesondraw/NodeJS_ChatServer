//
//  BiolandBPMModel.h
//  SEUICBluetooth
//
//  Created by Teson Draw on 11/9/16.
//  Copyright © 2016 Teson Draw. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BiolandBPMModel : NSObject

/* 实时数据 */
@property (nonatomic, assign) int nHeartbeat;
@property (nonatomic, assign) int nBatteryLevel;
@property (nonatomic, assign) int nErrorCode;
@property (nonatomic, assign) int nPressure;

/* 结果数据 */
@property (nonatomic, assign) int nSystolicPressure;
@property (nonatomic, assign) int nDiastolicPressure;
@property (nonatomic, assign) int nPulse;


@end
