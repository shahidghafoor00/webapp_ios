//
//  AppDelegate.swift
//  WebApp
//
//  Created by Shahid Ghafoor on 01/08/2021.
//

import UIKit
import Tapdaq


@main
class AppDelegate: UIResponder, UIApplicationDelegate {



    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        // Override point for customization after application launch.
        
        let properties = TDProperties()
        properties.privacySettings.userSubjectToGdpr = TDPrivacyStatus.yes  //GDPR declare if user is in EU
        properties.privacySettings.gdprConsentGiven = TDPrivacyStatus.yes //GDPR consent must be obtained from the user
        properties.privacySettings.ageRestrictedUser = TDPrivacyStatus.yes //Is user subject to COPPA or GDPR age restrictions

        Tapdaq.sharedSession().setApplicationId("<APP_ID>", clientKey: "<CLIENT_KEY>", properties: properties)

        
        return true
    }

    // MARK: UISceneSession Lifecycle

    func application(_ application: UIApplication, configurationForConnecting connectingSceneSession: UISceneSession, options: UIScene.ConnectionOptions) -> UISceneConfiguration {
        // Called when a new scene session is being created.
        // Use this method to select a configuration to create the new scene with.
        return UISceneConfiguration(name: "Default Configuration", sessionRole: connectingSceneSession.role)
    }

    func application(_ application: UIApplication, didDiscardSceneSessions sceneSessions: Set<UISceneSession>) {
        // Called when the user discards a scene session.
        // If any sessions were discarded while the application was not running, this will be called shortly after application:didFinishLaunchingWithOptions.
        // Use this method to release any resources that were specific to the discarded scenes, as they will not return.
    }


}

