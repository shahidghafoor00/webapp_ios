//
//  TDAdUnit.h
//  Tapdaq iOS SDK
//
//  Created by Nick Reffitt on 22/12/2016.
//  Copyright © 2016 Tapdaq. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, TDAdUnit) {
    TDUnitUnknown = 0,
    TDUnitStaticInterstitial,
    TDUnitVideoInterstitial,
    TDUnitRewardedVideo,
    TDUnitBanner,
    TDUnitMediatedNative
};

TDAdUnit TDAdUnitFromString(NSString *string);
NSString *NSStringFromAdUnit(TDAdUnit adUnit);

