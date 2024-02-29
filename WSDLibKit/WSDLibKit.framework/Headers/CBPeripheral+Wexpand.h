//
//  CBPeripheral+Wexpand.h
//  WSDLibKit
//
//  Created by List on 16/9/2022.
//  Copyright © 2022 List. All rights reserved.
//

#import <CoreBluetooth/CoreBluetooth.h>

NS_ASSUME_NONNULL_BEGIN

@interface CBPeripheral (Wexpand)
//设备的mac
@property(nonatomic,copy)NSString *macAddress;
//授权返回值
@property(nonatomic,copy)NSString *sessionKey;
//配对返回值
@property(nonatomic,copy)NSString *userKey;
@end

NS_ASSUME_NONNULL_END
