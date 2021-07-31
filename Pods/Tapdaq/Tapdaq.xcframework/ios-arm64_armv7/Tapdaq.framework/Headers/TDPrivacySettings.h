//
//  TDPrivacySettings.h
//  Tapdaq
//
//  Created by Dmitry Dovgoshliubnyi on 18/03/2020.
//  Copyright © 2020 Tapdaq. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TDPrivacyStatus) {
    TDPrivacyStatusNo = 0,
    TDPrivacyStatusYes = 1,
    TDPrivacyStatusUnknown = 2
};

@interface TDPrivacySettings : NSObject

/**
 * User is subject to EU GDPR laws.
 */
@property (readwrite, nonatomic) TDPrivacyStatus userSubjectToGdpr;

/**
 * Property that indicates whether a user has given consent to use his private data.
 */
@property (readwrite, nonatomic) TDPrivacyStatus gdprConsentGiven;

/**
 * User is of age 16 or below.
 */
@property (readwrite, nonatomic) TDPrivacyStatus ageRestrictedUser;

/**
 * User is subject to CCPA.
 */
@property (readwrite, nonatomic) TDPrivacyStatus userSubjectToUSPrivacy;

/**
 * User data can not be sold.
 */
@property (readwrite, nonatomic) TDPrivacyStatus usPrivacyDoNotSell;

/**
 * Setting this flag to true allows personalised ads to be served.
 *
 * @note The flag is only passed to Facebook Audience Network.
 */
@property (assign, nonatomic) TDPrivacyStatus advertiserTracking;

@end

NS_ASSUME_NONNULL_END
