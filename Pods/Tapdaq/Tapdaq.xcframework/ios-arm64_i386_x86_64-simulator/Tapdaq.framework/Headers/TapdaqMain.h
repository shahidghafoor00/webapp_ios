//
//  Tapdaq.h
//  Tapdaq
//
//  Created by Tapdaq <support@tapdaq.com>
//  Copyright (c) 2016 Tapdaq. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <Tapdaq/TDMNetworkEnum.h>
#import <Tapdaq/TDMBannerSize.h>
#import <Tapdaq/TDReward.h>
#import <Tapdaq/TDMediatedNativeAd.h>
#import <Tapdaq/TDProperties.h>
#import <Tapdaq/TapdaqDelegate.h>

@protocol TDAdRequestDelegate;
@protocol TDBannerAdRequestDelegate;

@class TDPlacement;
@class TDError;

@interface Tapdaq : NSObject

/**
 * Current version of the SDK.
 */
@property (readonly, nonatomic) NSString *sdkVersion;

/**
 * Delegate that will receive SDK events.
 */
@property (nonatomic, weak) id <TapdaqDelegate> delegate;

/**
 * User ID.
 */
@property (nonatomic) NSString *userId;

/**
 * Forward user ID to ad networks. When set to YES userId will be forwarded to ad networks when applicable.
 */
@property (nonatomic) BOOL forwardUserId;

/**
 * AdMob content rating.
 */
@property (nonatomic) NSString *adMobContentRating;

/**
 * An object with a collection of settings for the SDK including privacy settings and user data.
 */
@property (readonly, nonatomic) TDProperties *properties;

/**
 * Provides a list of networks and their config states and config errors if applicable.
 */
@property (readonly, nonatomic, copy) NSArray *networkStatuses;

#pragma mark Singleton
/**
 The singleton Tapdaq object, use this for all method calls
 
 @return The Tapdaq singleton.
 */
+ (instancetype)sharedSession;

- (void)trackPurchaseForProductName:(NSString *)productName
                              price:(double)price
                        priceLocale:(NSString *)priceLocale
                           currency:(NSString *)currency
                      transactionId:(NSString *)transactionId
                          productId:(NSString *)productId;

#pragma mark Initializing Tapdaq

/**
 A setter for the Application ID of your app, and the Client Key associated with your Tapdaq account. 
 You can obtain these details when you sign up and add your app to https://tapdaq.com
 You must use this in the application:didFinishLaunchingWithOptions method.
 
 @param applicationId The application ID tied to your app.
 @param clientKey The client key tied to your app.
 @param properties The properties object that overrides the Tapdaq defaults. See TDProperties for info on all configuration options.
 */
- (void)setApplicationId:(NSString *)applicationId
               clientKey:(NSString *)clientKey
              properties:(TDProperties *)properties;

/**
 * Get current SDK initialisation status
 *
 * @return YES if the SDK is initialised. NO otherwise.
 */
- (BOOL)isInitialised;

#pragma mark Reward
- (NSString *)rewardIdForPlacementTag:(NSString *)placementTag;

#pragma mark Debugger
- (void)presentDebugViewController;

#pragma mark Banner


- (void)loadBannerForPlacementTag:(NSString *)placementTag withSize:(TDMBannerSize)bannerSize delegate:(id<TDBannerAdRequestDelegate>)delegate;

- (void)loadBannerForPlacementTag:(NSString *)placementTag
                       targetSize:(CGSize)targetSize
                         delegate:(id<TDBannerAdRequestDelegate>)delegate;

#pragma mark Interstitial
- (void)loadInterstitialForPlacementTag:(NSString *)placementTag delegate:(id<TDAdRequestDelegate>)delegate;

- (void)loadInterstitialForPlacementTag:(NSString *)placementTag;

- (BOOL)isInterstitialReadyForPlacementTag:(NSString *)placementTag;

- (TDError *)interstitialCappedForPlacementTag:(NSString *)placementTag;

- (void)showInterstitialForPlacementTag:(NSString *)placementTag delegate:(id<TDAdRequestDelegate>)delegate;

#pragma mark Video
- (void)loadVideoForPlacementTag:(NSString *)placementTag delegate:(id<TDAdRequestDelegate>)delegate;

- (void)loadVideoForPlacementTag:(NSString *)placementTag;

- (BOOL)isVideoReadyForPlacementTag:(NSString *)placementTag;

- (TDError *)videoCappedForPlacementTag:(NSString *)placementTag;

- (void)showVideoForPlacementTag:(NSString *)placementTag delegate:(id<TDAdRequestDelegate>)delegate;

#pragma mark Rewarded Video
- (void)loadRewardedVideoForPlacementTag:(NSString *)placementTag delegate:(id<TDAdRequestDelegate>)delegate;

- (void)loadRewardedVideoForPlacementTag:(NSString *)placementTag;

- (BOOL)isRewardedVideoReadyForPlacementTag:(NSString *)placementTag;

- (TDError *)rewardedVideoCappedForPlacementTag:(NSString *)placementTag;

- (void)showRewardedVideoForPlacementTag:(NSString *)placementTag delegate:(id<TDAdRequestDelegate>)delegate;

#pragma mark Mediated native ads

- (void)loadNativeAdInViewController:(UIViewController *)viewController
                        placementTag:(NSString *)placementTag
                             options:(TDMediatedNativeAdOptions)options
                            delegate:(id<TDAdRequestDelegate>)delegate;

#pragma mark - Deprecated
@property (nonatomic) TDSubjectToGDPR userSubjectToGDPR __deprecated_msg("Use properties.privacySettings instead. Deprecated on 03/18/2020 version 7.6.0.");
@property (nonatomic) BOOL isConsentGiven __deprecated_msg("Use properties.privacySettings instead. Deprecated on 03/18/2020 version 7.6.0.");
@property (nonatomic) BOOL isAgeRestrictedUser __deprecated_msg("Use properties.privacySettings instead. Deprecated on 03/18/2020 version 7.6.0.");

- (void)loadBannerWithSize:(TDMBannerSize)size completion:(void(^)(UIView *))completion
__deprecated_msg("Use -loadBannerForPlacementTag:withSize: instead. Deprecated on 01/29/2020 version 7.5.0.");
- (void)showInterstitialForPlacementTag:(NSString *)placementTag __deprecated_msg("Use -showInterstitialForPlacementTag:delegate: instead. Deprecated on 02/28/2020 version 7.5.1.");
- (void)showVideoForPlacementTag:(NSString *)placementTag __deprecated_msg("Use -showVideoForPlacementTag:delegate: instead. Deprecated on 02/28/2020 version 7.5.1.");
- (void)showRewardedVideoForPlacementTag:(NSString *)placementTag __deprecated_msg("Use -showRewardedVideoForPlacementTag:delegate: instead. Deprecated on 02/28/2020 version 7.5.1.");
- (void)showRewardedVideoForPlacementTag:(NSString *)placementTag hashedUserId:(NSString *)hashedUserId __attribute__((deprecated("showRewardedVideoForPlacementTag:hashedUserId: has been deprecated. Please use showRewardedVideoForPlacementTag: instead. To set user ID plese use userId property of TDProperties class or Tapdaq interface. This method will be removed in future releases. Deprecated on 09/07/2019 version 7.2.0.")));
@end
