//
//  Tapdaq+PluginSupport.h
//  Tapdaq
//
//  Created by Dmitry Dovgoshliubnyi on 12/12/2019.
//  Copyright © 2019 Tapdaq. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Tapdaq/Tapdaq.h>

@protocol TDBannerAdRequestDelegate;

@interface Tapdaq (PluginSupport)

- (void)loadPluginBannerForDefaultPlacementTagWithSize:(TDMBannerSize)bannerSize delegate:(id<TDBannerAdRequestDelegate>)delegate;
- (void)loadPluginBannerForPlacementTag:(NSString *)placementTag
                         withSize:(TDMBannerSize)bannerSize
                               delegate:(id<TDBannerAdRequestDelegate>)delegate;
- (void)loadPluginBannerForPlacementTag:(NSString *)placementTag
                               withTargetSize:(CGSize)targetSize
                               delegate:(id<TDBannerAdRequestDelegate>)delegate;

- (BOOL)isBannerReadyForDefaultPlacementTag;
- (BOOL)isBannerReadyBannerForPlacementTag:(NSString *)placementTag;

- (void)showBannerForDefaultPlacementTagAtPosition:(TDBannerPosition)position inView:(UIView *)view;
- (void)showBannerForPlacementTag:(NSString *)placementTag
                       atPosition:(TDBannerPosition)position
                           inView:(UIView *)view;

- (void)hideBannerForDefaultPlacementTag;
- (void)hideBannerForPlacementTag:(NSString *)placementTag;

- (void)destroyBannerForDefaultPlacementTag;
- (void)destroyBannerForPlacementTag:(NSString *)placementTag;

- (NSArray<NSDictionary<NSString *, NSString *> *> *)networkStatusesDictionary;

+ (void)setPluginToolsVersion:(NSString *)pluginToolsVersion
                 userDefaults:(NSUserDefaults *)userDefaults;
@end
