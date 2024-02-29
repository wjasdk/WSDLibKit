//
//  SDVoiceEncoder.h
//  SDLib
//
//  Created by xianjun on 2018/5/4.
//  Copyright © 2018年 zhidekan. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 声波发送状态

 - SDVoicePlayerStatusStart: 开始发送声波
 - SDVoicePlayerStatusEnd: 结束发送声波
 */
typedef NS_ENUM(NSUInteger, SDVoicePlayerStatus) {
    SDVoicePlayerStatusStart,
    SDVoicePlayerStatusEnd,
};

typedef void(^VoicePlayerListener)(SDVoicePlayerStatus playerStatus);

@interface SDVoicePlayer : NSObject
{
    /**
     播放器
     */
    void *player;
}

/**
 声波发送状态监听
 */
@property (nonatomic, strong) VoicePlayerListener playerListener;


/**
 初始化方法
 !!!播放器实例必须为属性，不可为局部变量

 @return 返回播放器实例
 */
- (instancetype) init;


/**
 声波发送是否停止

 @return 返回声波发送是否停止
 */
- (BOOL) isStopped;


/**
 play voice

 @param ssid WIFI name
 @param pwd WIFI password
 @param userId _userId
 @param appId _appId
 @param playerListener player status callback
 */
- (void) sd_PlayZSSSIDWiFi:(NSString *)ssid pwd:(NSString *)pwd userId:(NSString *)userId appId:(NSString *)appId voicePlayerListener:(VoicePlayerListener)playerListener;

// 停止播放声波
- (void) stop;

@end
