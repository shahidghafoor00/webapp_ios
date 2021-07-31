//
//  TDAdRequest.h
//  Tapdaq
//
//  Created by Dmitry Dovgoshliubnyi on 16/01/2018.
//  Copyright © 2018 Tapdaq. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Tapdaq/TDPlacement.h>

@protocol TDAdRequestDelegate;
@protocol TDDisplayableAdRequestDelegate;
@protocol TDClickableAdRequestDelegate;
@protocol TDRewardedVideoAdRequestDelegate;
@protocol TDBannerAdRequestDelegate;


@class TDReward;
@class TDError;
@class TDAdRequest;

typedef void (^TDAdRequestCompletion)(TDAdRequest * _Nonnull request, TDError * _Nullable error);

#pragma mark - Base Ad Request
@interface TDAdRequest : NSObject
/**
 * This object contains placement information such as placement tag and ad unit that is being loaded.
 */
@property (readonly, nonatomic, nonnull) TDPlacement *placement;

/**
 * A reward object to award to a user.
 *
 * Supported Ad units: TDUnitRewardedVideo
 */
@property (readonly, nonatomic, nullable) TDReward *reward;

/**
 * Delegate that will received all events associated with this ad request.
 */
@property (weak, nonatomic, nullable) id<TDAdRequestDelegate>delegate;

/**
 * Returns YES if this ad is ready to be shown.
 */
- (BOOL)isReady;

@property (strong, nonatomic, nullable) NSString *hashedUserId __deprecated_msg("Use userId in TDProperties object instead. Deprecated on 03/26/2020 version 7.6.0.");
@end

