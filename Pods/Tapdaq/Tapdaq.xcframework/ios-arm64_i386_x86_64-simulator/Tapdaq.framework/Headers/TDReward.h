//
//  TDReward.h
//  Tapdaq
//
//  Created by Dmitry Dovgoshliubnyi on 30/11/2017.
//  Copyright © 2017 Tapdaq. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TDReward : NSObject
@property (readonly, nonatomic) NSString *eventId;
@property (readonly, nonatomic) NSString *name;
@property (readonly, nonatomic) int value;
@property (readonly, nonatomic) BOOL isValid;
@property (readonly, nonatomic) NSString *tag;
@property (readonly, nonatomic) id customJson;
@property (readonly, nonatomic) NSString *rewardId;
@property (readonly, nonatomic) NSString *hashedUserId __deprecated_msg("Use userId in TDProperties object instead. Deprecated on 03/26/2020 version 7.6.0.");
@end
