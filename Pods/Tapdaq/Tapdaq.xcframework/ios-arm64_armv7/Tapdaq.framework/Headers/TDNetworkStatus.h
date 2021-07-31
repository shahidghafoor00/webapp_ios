//
//  TDNetworkStatus.h
//  Tapdaq
//
//  Created by Dmitry Dovgoshliubnyi on 01/06/2020.
//  Copyright © 2020 Tapdaq. All rights reserved.
//

#import <Foundation/Foundation.h>
@class TDError;

NS_ASSUME_NONNULL_BEGIN

@interface TDNetworkStatus : NSObject
@property (readonly, nonatomic, copy) NSString *name;
@property (readonly, nonatomic, copy) NSString *status;
@property (readonly, nonatomic, nullable) NSError *error;
@end

NS_ASSUME_NONNULL_END
