//
//  SDConfigQRCode.h
//  WSDLibKit
//
//  Created by List on 8/9/2021.
//  Copyright © 2021 List. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SDServer.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^ConfigQrCodeResult)(BOOL isSuccess, UIImage *qrImage);

@interface SDConfigQRCode : NSObject

@property (nonatomic, assign) int timeoutInterval;   // 超时时间，默认 30秒


/// 初始化二维码生成库
/// @param server 网络服务类
/// @param token 用户token
- (instancetype)initWithServer:(SDServer *)server token:(NSString *)token;

/// 初始化二维码生成库
/// @param serverDomain Iot域名，传入鉴权地址或者纯域名均可
/// @param token 用户token
- (instancetype)initWithServerDomain:(NSString *)serverDomain token:(NSString *)token;


/// 生成二维码
/// @param ssid WiFi名称
/// @param password WiFi密码
/// @param size 生成的图片大小
/// @param language 0：中文 1：英文；默认中文
/// @param server 服务器前缀，如wmq-cn, wmq-na、wmq-cn.xxx.xxx等
- (void)creatQrCodeImageWithSsid:(NSString *)ssid password:(NSString *)password size:(CGFloat)size language:(NSInteger)language server:(NSString *)server finishResult:(ConfigQrCodeResult)finishResult;

@end

NS_ASSUME_NONNULL_END
