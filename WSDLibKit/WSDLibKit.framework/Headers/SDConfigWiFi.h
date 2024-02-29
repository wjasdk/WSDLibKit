//
//  SDConfigWiFi.h
//  ZDKSimpleConfig
//
//  Created by List on 16/4/2019.
//  Copyright © 2019 List. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SDConfigModel.h"

/**
 WiFi配置状态
 
 - SDConfigWiFiStatusSuccess: 配置成功并且有设备
 - SDConfigWiFiStatusFail: 配置失败，无设备
 */
typedef NS_ENUM(NSUInteger, SDConfigWiFiStatus) {
    SDConfigWiFiStatusSuccess,
    SDConfigWiFiStatusFail,
};
typedef void(^ConfigWiFiListenerResult)(SDConfigWiFiStatus configStatus, NSMutableArray *deviceModelAry);

@interface SDConfigWiFi : NSObject

@property (nonatomic, assign) int timeoutInterval;   // 超时时间，默认 120秒

/*
 初始化WiFi配置类
 */
- (instancetype)init;

/**
 WiFi 开始配置
 @param ssid WIFI name
 @param pwd WIFI password
 @param configWiFiListener status callback
 */
- (void)sd_StartConfigSSIDWiFi:(NSString *)ssid pwd:(NSString *)pwd configWiFiListener:(ConfigWiFiListenerResult)configWiFiListener;


/**
 停止配置
 */
- (void)sd_StopConfig;

@end

