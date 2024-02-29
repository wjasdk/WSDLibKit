//
//  SDConfigAP.h
//  WSDLibKit
//
//  Created by List on 15/9/2021.
//  Copyright © 2021 List. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SDServer.h"
#import "SDConfigModel.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^ConfigAPResult)(BOOL isSuccess,SDConfigModel *resultModel);

@interface SDConfigAP : NSObject

@property (nonatomic, assign) int timeoutInterval;   // 超时时间，默认 120秒

+ (SDConfigAP *)shareIntance;

/// 初始化AP配网库
/// @param server 网络服务类
/// @param authToken 平台token（鉴权token）
- (void)initWithServer:(SDServer *)server authToken:(NSString *)authToken;


/// 初始化AP配网库
/// @param serverDomain  Iot域名，传入鉴权地址或者纯域名均可
/// @param authToken 平台token（鉴权token）
- (void)initWithServerDomain:(NSString *)serverDomain authToken:(NSString *)authToken;


/// 开始配置
/// @param ssid WiFi名称
/// @param pwd WiFi密码
/// @param language 0：中文 1：英文；默认中文
/// @param server 服务器前缀，如wmq-cn, wmq-na等等
- (void)startAPConfigSSIDWiFi:(NSString *)ssid pwd:(NSString *)pwd language:(NSInteger)language server:(NSString *)server finishResult:(ConfigAPResult)finishResult;

/// 开始配置
/// @param object 要传输的自定义格式{@"key":@"value"}
- (void)startAPConfigFromWiFiInfoObject:(id)object;

/// 停止配置，使用场景是离开配置页面，切记要调用
- (void)stopAPConfig;

@end

NS_ASSUME_NONNULL_END
