//
//  TDAdRequestDelegate.h
//  Tapdaq
//
//  Created by Dmitry Dovgoshliubnyi on 24/01/2018.
//  Copyright © 2018 Tapdaq. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TDAdRequest;
@class TDInterstitialAdRequest;
@class TDNativeAdRequest;
@class TDBannerAdRequest;
@class TDError;

@protocol TDAdRequestDelegate;

/**
* Implementing this protocol allows listening to native ad events from ad requests.
*/
@protocol TDNativeAdRequestDelegate <TDAdRequestDelegate>
- (void)didLoadNativeAdRequest:(TDNativeAdRequest * _Nonnull)adRequest;
@end

/**
 * Implementing this protocol allows listening to interstitial related events from ad requests.
 */
@protocol TDInterstitialAdRequestDelegate <TDAdRequestDelegate>
@optional
- (void)didLoadInterstitialAdRequest:(TDInterstitialAdRequest * _Nonnull)adRequest;
- (void)adRequest:(TDInterstitialAdRequest * _Nonnull)adRequest didFailToDisplayWithError:(TDError * _Nullable)error;
- (void)willDisplayAdRequest:(TDInterstitialAdRequest * _Nonnull)adRequest;
- (void)didDisplayAdRequest:(TDInterstitialAdRequest * _Nonnull)adRequest;
- (void)didCloseAdRequest:(TDInterstitialAdRequest * _Nonnull)adRequest;
@end

/**
 * Implementing this protocol allows listening to reward related events from ad requests.
 */
@protocol TDRewardedVideoAdRequestDelegate <TDInterstitialAdRequestDelegate>
@optional
- (void)adRequest:(TDInterstitialAdRequest * _Nonnull)adRequest didValidateReward:(TDReward * _Nonnull)reward;
- (void)adRequest:(TDInterstitialAdRequest * _Nonnull)adRequest didFailToValidateReward:(TDReward * _Nonnull)reward;
@end

/**
 * Implementing this protocol allows listening to banner related events from ad requests.
 */
@protocol TDBannerAdRequestDelegate <TDAdRequestDelegate>
@optional
- (void)didLoadBannerAdRequest:(TDBannerAdRequest * _Nonnull)adRequest;
- (void)didRefreshBannerForAdRequest:(TDBannerAdRequest * _Nonnull)adRequest;
- (void)didFailToRefreshBannerForAdRequest:(TDBannerAdRequest * _Nonnull)adRequest withError:(TDError * _Nullable)error;
@end

/**
 * Base protocl with shared methods between all ad type specific ad requests. Please avoid usin this on its own.
 */
@protocol TDAdRequestDelegate <NSObject>
@optional
- (void)adRequest:(TDAdRequest * _Nonnull)adRequest didFailToLoadWithError:(TDError * _Nullable)error;
- (void)didClickAdRequest:(TDAdRequest * _Nonnull)adRequest;
- (void)didLoadAdRequest:(TDAdRequest * _Nonnull)adRequest __deprecated_msg("Use didLoad method for appropriate ad types instead. Deprecated on 03/23/2020 version 7.6.0.");
@end

__deprecated_msg("Use TDAdRequestDelegate instead. Deprecated on 03/23/2020 version 7.6.0.")
@protocol TDClickableAdRequestDelegate <TDAdRequestDelegate>
@end

__deprecated_msg("Use TDInterstitialAdRequestDelegate instead. Deprecated on 03/23/2020 version 7.6.0.")
@protocol TDDisplayableAdRequestDelegate <TDInterstitialAdRequestDelegate>
@end
