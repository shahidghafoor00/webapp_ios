//
//  TDProperties.h
//  Tapdaq
//
//  Created by Tapdaq <support@tapdaq.com>
//  Copyright (c) 2016 Tapdaq. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <Tapdaq/TDTestDevices.h>
#import <Tapdaq/TDLogLevel.h>
#import <Tapdaq/TDPrivacySettings.h>


typedef NS_ENUM(NSInteger, TDSubjectToGDPR) {
    TDSubjectToGDPRNo = 0,
    TDSubjectToGDPRYes = 1,
    TDSubjectToGDPRUnknown = 2
} __deprecated_msg("Use privacySettings class instead. Deprecated on 03/18/2020 version 7.6.0.");


@interface TDProperties : NSObject

/**
 * Enables/Disables logging of the adapters.
 */
@property (nonatomic) BOOL isDebugEnabled;

/**
 * Enables/Disables ad auto reloading.
 */
@property (nonatomic) BOOL autoReloadAds;

/**
 * Note: For plugin developers only.
 */
@property (nonatomic) NSString *pluginVersion;

/**
 * Property identifing the user.
 */
@property (strong, nonatomic) NSString *userId;

/**
 * If the to YES userId property will be forwarded to ad networks.
 */
@property (assign, nonatomic) BOOL forwardUserId;

/**
 * A flag that is passed to certain ad networks to mute ads on playback.
 */
@property (assign, nonatomic, getter=isMuted) BOOL muted;

/**
 * AdMob Ad content filtering options.
 */
@property (strong, nonatomic) NSString *adMobContentRating;

/**
 * Object used to get and set various user privacy settings.
 */
@property (readonly, nonatomic) TDPrivacySettings *privacySettings;

/**
 * A new instance with default values;
 */
+ (instancetype)defaultProperties;

- (BOOL)registerTestDevices:(TDTestDevices *)testDevices;

- (NSArray *)registeredTestDevices;


@property (assign, nonatomic) TDSubjectToGDPR userSubjectToGDPR
__deprecated_msg("Use privacySettings class instead. Deprecated on 03/18/2020 version 7.6.0.");
@property (assign, nonatomic) BOOL isConsentGiven
__deprecated_msg("Use privacySettings class instead. Deprecated on 03/18/2020 version 7.6.0.");
@property (assign, nonatomic) BOOL isAgeRestrictedUser
__deprecated_msg("Use privacySettings class instead. Deprecated on 03/18/2020 version 7.6.0.");
@property (assign, nonatomic) TDLogLevel logLevel
__deprecated_msg("Use TDLogger.logLevel instead. Deprecated on 03/26/2020 version 7.6.0.");
@end



#pragma mark - UserData

@interface TDProperties (UserData)
/**
 * Read-only dictionary where all stored user data values can be seen.
 */
@property (readonly, nonatomic) NSDictionary<NSString *, id> *userData;

/**
 * Set user data string.
 *
 * @param value A string value to set.
 * @param key A key value is associated with.
 */
- (void)setUserDataString:(NSString *)value forKey:(NSString *)key;

/**
 * Set user data integer.
 *
 * @param value An integer value to set.
 * @param key A key value is associated with.
 */
- (void)setUserDataInteger:(NSInteger)value forKey:(NSString *)key;

/**
 * Set user data boolean.
 *
 * @param value A boolean value to set.
 * @param key A key value is associated with.
 */
- (void)setUserDataBool:(BOOL)value forKey:(NSString *)key;

/**
 * Returns user data object stored for key.
 *
 * @param key A key value is associated with.
 *
 * @returns If the value was set as BOOL or NSInteger the object returned will be an NSNumber.
 */
- (id)userDataObjectForKey:(NSString *)key;

/**
 * Returns user data string stored for key.
 *
 * @param key A key value is associated with.
 *
 * @returns Value returned is nil if it is not a string, even if there is an object stored for this key.
 */
- (NSString *)userDataStringForKey:(NSString *)key;

/**
 * Returns user data BOOL stored for key.
 *
 * @param key A key value is associated with.
 *
 * @returns If the value stored is not BOOL, boolValue representation will be returned.
 */
- (BOOL)userDataBoolForKey:(NSString *)key;

/**
 * Returns user data NSInteger stored for key.
 *
 * @param key A key value is associated with.
 *
 * @returns If the value stored is not NSInteger, integerValue representation will be returned.
 */
- (NSInteger)userDataIntegerForKey:(NSString *)key;

/**
 * Removes value stored for key.
 *
 * @param key A key value is associated with.
 */
- (void)removeUserDataForKey:(NSString *)key;
@end

