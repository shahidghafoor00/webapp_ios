//
//  TDLogger.h
//  Tapdaq
//
//  Created by Dmitry Dovgoshliubnyi on 03/10/2017.
//  Copyright © 2017 Tapdaq. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <Tapdaq/TDLogLevel.h>

@interface TDLogger : NSObject
+ (TDLogLevel)logLevel;
+ (void)setLogLevel:(TDLogLevel)logLevel;
@end
