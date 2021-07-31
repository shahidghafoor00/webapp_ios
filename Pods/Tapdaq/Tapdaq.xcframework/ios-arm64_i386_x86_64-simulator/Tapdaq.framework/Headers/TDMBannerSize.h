//
//  TDMBannerSize.h
//  Tapdaq iOS SDK
//
//  Created by Mukund Agarwal on 17/10/2016.
//  Copyright © 2016 Tapdaq. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, TDMBannerSize) {
    TDMBannerStandard,
    TDMBannerLarge,
    TDMBannerMedium,
    TDMBannerFull,
    TDMBannerLeaderboard,
    TDMBannerSmart,
    TDMBannerCustom
};

NSString *NSStringFromBannerSize(TDMBannerSize bannerSize);
CGSize CGSizeFromBannerSize(TDMBannerSize bannerSize);
