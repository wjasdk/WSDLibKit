//
//  SDConfigESP.h
//  WSDLibKit
//
//  Created by List on 16/9/2022.
//  Copyright © 2022 List. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BlufiConfigureParams.h"
#import <CoreBluetooth/CoreBluetooth.h>
#import "CBPeripheral+Wexpand.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger,ConnectStatus){
    NO_Connect,
    Connecting,
    Connected,
    Connect_Failure
};

typedef NS_ENUM(NSInteger,BLUE_TYPE){
    BLUE_M30,
    BLUE_D8,
    BLUE_D02A,
};

@class BlufiClient;
 
@protocol SDConfigESPDelegate<NSObject>

@optional


/// 搜索到设备
/// @param central 蓝牙中央管理器
/// @param peripheral 蓝牙外设对象
/// @param advertisementData 广播的数据
/// @param RSSI 信号
- (void)wCentralManager:(CBCentralManager *_Nullable)central didDiscoverPeripheral:(CBPeripheral *)peripheral advertisementData:(NSDictionary<NSString *, id> *)advertisementData RSSI:(NSNumber *)RSSI;


/// 配网成功后返回设备相关信息
/// @param client 蓝牙连接对象
/// @param dict 设备相关信息
- (void)wBlufi:(BlufiClient *)client didReceiveCustomData:(NSDictionary *)dict;


/// 蓝牙连接状态
/// @param connect_status 连接状态
/// @param type 蓝牙设备类型
- (void)wConnectStatus:(ConnectStatus)connect_status type:(BLUE_TYPE)type;

/// 蓝牙数据解析出错
/// @param client 蓝牙连接对象
/// @param errCode 错误码
- (void)wBlufi:(BlufiClient *)client didReceiveError:(NSInteger)errCode;

@end

@interface SDConfigESP : NSObject
 
+(SDConfigESP *)sharedOneTimeClass;

//扫描所有设备
-(void)scanDevice:(id <SDConfigESPDelegate>)delegate;

//通过mac地址连接设备
-(void)connectPeripheralWithMac:(NSString *)macAddress;

//清除信息，断开蓝牙
-(void)cleanSelf;

//配网
-(void)configure:(BlufiConfigureParams *)configure;


@end
 

NS_ASSUME_NONNULL_END
