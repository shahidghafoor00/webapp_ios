//
//  TDBannerAdRequest.h
//  Tapdaq
//
//  Created by Dmitry Dovgoshliubnyi on 26/01/2018.
//  Copyright © 2018 Tapdaq. All rights reserved.
//

#import <Tapdaq/TDAdRequest.h>
#import <Tapdaq/TDMBannerSize.h>
#import <Tapdaq/TDPlacement.h>

@interface TDBannerAdRequest : TDAdRequest
/**
 * Banner size.
 */
@property (readonly, nonatomic) TDMBannerSize size;

/**
 * Target size.
 */
@property (readonly, nonatomic) CGSize targetSize;

/**
 * Method used to access banner view.
 */
- (UIView * _Nullable)bannerView;

/**
 * Destroy assets associated with the ad request. Some networks may require this method to be called before discarding banner.
 */
- (void)destroy;
@end
