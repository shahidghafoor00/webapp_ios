//
//  TDMediatedNativeAd.h
//  Tapdaq
//
//  Created by Dmitry Dovgoshliubnyi on 14/03/2018.
//  Copyright © 2018 Tapdaq. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Tapdaq/TDPlacement.h>

#ifndef __TDMediatedNativeAdViewType

#define __TDMediatedNativeAdViewType
typedef NS_ENUM(NSInteger, TDMediatedNativeAdViewType) {
    TDMediatedNativeAdViewTypeUnknown = -1,
    TDMediatedNativeAdViewTypeHeadline,
    TDMediatedNativeAdViewTypeSubtitle,
    TDMediatedNativeAdViewTypeCaption,
    TDMediatedNativeAdViewTypeStore,
    TDMediatedNativeAdViewTypePrice,
    TDMediatedNativeAdViewTypeStarRating,
    TDMediatedNativeAdViewTypeBody,
    TDMediatedNativeAdViewTypeImageView,
    TDMediatedNativeAdViewTypeLogo,
    TDMediatedNativeAdViewTypeCallToAction,
    TDMediatedNativeAdViewTypeAdvertiser,
    TDMediatedNativeAdViewTypeMedia,
    TDMediatedNativeAdViewTypeAdChoices
    
};

typedef NS_ENUM(NSInteger, TDMediatedNativeAdOptions) {
    TDMediatedNativeAdOptionsAdChoicesTopRight = 1 << 0,
    TDMediatedNativeAdOptionsAdChoicesTopLeft = 1 << 1,
    TDMediatedNativeAdOptionsAdChoicesBottomRight = 1 << 2,
    TDMediatedNativeAdOptionsAdChoicesBottomLeft = 1 << 3
};

#endif //__TDMediatedNativeAdViewType
@class TDNativeAdImage;

@interface TDMediatedNativeAd : NSObject
@property (strong, nonatomic, nullable) NSString *title;
@property (strong, nonatomic, nullable) NSString *subtitle;
@property (strong, nonatomic, nullable) NSString *caption;
@property (strong, nonatomic, nullable) NSString *callToAction;
@property (strong, nonatomic, nullable) NSString *socialContext;
@property (strong, nonatomic, nullable) NSString *body;
@property (strong, nonatomic, nullable) NSString *store;
@property (strong, nonatomic, nullable) NSString *price;
@property (strong, nonatomic, nullable) TDNativeAdImage *icon DEPRECATED_MSG_ATTRIBUTE("icon has been deprecated. Please use -iconView instead. This method will be removed in future releases. Deprecated on 21/09/2018 version 6.4.0.");
@property (strong, nonatomic, nullable) UIView *iconView;
@property (strong, nonatomic, nullable) NSArray<TDNativeAdImage *> *images;
@property (strong, nonatomic, nullable) NSDecimalNumber *starRating;
@property (strong, nonatomic, nullable) NSString *advertiser;
@property (strong, nonatomic, nullable) UIView *mediaView;
@property (readonly, nonatomic, nonnull) NSString *placementTag;

- (void)setAdView:(UIView * _Nonnull)adView;
- (void)registerView:(UIView * _Nonnull)view type:(TDMediatedNativeAdViewType)type;

- (void)trackImpression;
@end
