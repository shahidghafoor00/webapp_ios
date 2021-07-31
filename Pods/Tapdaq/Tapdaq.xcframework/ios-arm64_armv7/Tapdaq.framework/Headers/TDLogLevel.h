//
//  TDLogLevel.h
//  Tapdaq iOS SDK
//
//  Created by Dmitry Dovgoshliubnyi on 03/10/2017.
//  Copyright © 2017 Tapdaq. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, TDLogLevel) {
    TDLogLevelDisabled = 0,
    TDLogLevelError,
    TDLogLevelWarning,
    TDLogLevelInfo,
    TDLogLevelDebug
};

