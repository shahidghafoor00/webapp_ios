//
//  TDBannerPosition.h
//  Tapdaq
//
//  Created by Dmitry Dovgoshliubnyi on 18/12/2019.
//  Copyright © 2019 Tapdaq. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, TDBannerPositionType) {
    TDBannerPositionTypeTop,
    TDBannerPositionTypeBottom,
    TDBannerPositionTypeCustom
};

typedef struct {
    TDBannerPositionType type;
    CGPoint location; // <- Location should only be used when type is TDBannerPositionTypeCustom
    NSString *name;
} TDBannerPosition;

TDBannerPosition TDBannerPositionMake(TDBannerPositionType type);
TDBannerPosition TDBannerPositionMakeCustom(CGPoint location);

NSString *NSStringFromBannerPositionType(TDBannerPositionType type);
