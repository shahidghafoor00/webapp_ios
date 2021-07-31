//
//  TDPlacement.h
//  Tapdaq
//
//  Created by Tapdaq <support@tapdaq.com>
//  Copyright (c) 2016 Tapdaq. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Tapdaq/TDAdUnit.h>

// Default.
extern NSString *const TDPTagDefault;

@interface TDPlacement : NSObject <NSCopying>

@property (nonatomic, readonly) TDAdUnit adUnit;
@property (nonatomic, readonly) NSString *tag;

+ (instancetype)defaultPlacementForAdUnit:(TDAdUnit)adUnit;
+ (instancetype)placementWithAdUnit:(TDAdUnit)adUnit tag:(NSString *)tag;

- (instancetype)initWithAdUnit:(TDAdUnit)adUnit forTag:(NSString *)tag;

+ (BOOL)isValidTag:(NSString *)tag;
@end
