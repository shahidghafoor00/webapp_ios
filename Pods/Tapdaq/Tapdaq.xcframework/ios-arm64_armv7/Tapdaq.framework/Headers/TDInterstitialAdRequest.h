//
//  TDInterstitialAdRequest.h
//  Tapdaq
//
//  Created by Dmitry Dovgoshliubnyi on 26/01/2018.
//  Copyright © 2018 Tapdaq. All rights reserved.
//

#import <Tapdaq/TDAdRequest.h>

@interface TDInterstitialAdRequest : TDAdRequest
- (void)display;
@end

typedef TDInterstitialAdRequest TDMediationAdRequest __deprecated_msg("Use TDInterstitialAdRequest instead. Deprecated on 03/23/2020 version 7.6.0.");
