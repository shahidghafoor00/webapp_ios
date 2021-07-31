//
//  TDErrorCodes.h
//  Tapdaq
//
//  Created by Dmitry Dovgoshliubnyi on 15/01/2018.
//  Copyright © 2018 Tapdaq. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    TDErrorCodeUnknown = -999,
    TDErrorCodeNotInitialised = 10,
    TDErrorCodeInvalidCredentials = 20,
    TDErrorCodeCredentialsMissing = 21,
    TDErrorCodeNoAdaptersRegistered = 41,
    TDErrorCodeNetworksFailedToInitialise = 42,
    TDErrorCodeNoAdepters = 100,
    TDErrorCodeNoNetworksEnabled = 110,
    TDErrorCodeNoPlacementTagAvailable = 120,
    TDErrorCodeFailedToLoad = 130,
    TDErrorCodeInvalidPlacementTag = 140,
    TDErrorCodeNoAdLoadedForPlacement = 200,
    TDErrorCodeUnknownAdType = 210,
    TDErrorCodeAdExpired = 220,
    TDErrorCodeAdFrequencyCapped = 230,
    
    TDErrorCodeAdapterFailedToLoad = 1000,
    TDErrorCodeAdapterAdIdMissing = 1001,
    TDErrorCodeAdapterBannerSizeUnsupported= 1010,
    TDErrorCodeAdapterTimeout = 1011,
    TDErrorCodeAdapterNetworkNotInitialised = 1100,
    TDErrorCodeAdUnitSuspended = 1012,
    TDErrorCodeAdapterAdAlreadyShown = 1002,
    TDErrorCodeNoBidPayload = 1201,
    
    
    TDErrorCodeAdapterConfigFailed = 1101,
    TDErrorCodeAdapterConfigTimedOut = 1102,
    TDErrorCodeAdapterConfigInvalidCredentials = 1103,
    TDErrorCodeAdapterConfigInvalidOSVersion = 1104,
    TDErrorCodeAdapterConfigSubjectToGdprRequired = 1105,
    
    TDErrorCodeAdapterAppLovinFailedToLoad = 12000,
    TDErrorCodeAdapterChartboostFailedToLoad = 13000,
    TDErrorCodeAdapterIronSourceFailedToLoad = 17000,
    TDErrorCodeAdapterTapjoyNoContent = 20100,
    TDErrorCodeAdapterTapjoyDisplayError = 20200,
    TDErrorCodeAdapterUnityAdsDisplayError = 21200,
    TDErrorCodeAdapterUnityAdsDisabled = 21100,
    TDErrorCodeAdapterUnityAdsNoFill = 21101,
    TDErrorCodeAdapterUnityAdsUnavailable = 21102,
    TDErrorCodeAdapterVungleFailedToLoad = 22000
} TDErrorCode;
