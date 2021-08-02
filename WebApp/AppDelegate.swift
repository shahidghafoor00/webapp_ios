//
//  AppDelegate.swift
//  WebApp
//
//  Created by Shahid Ghafoor on 01/08/2021.
//

import UIKit
import Tapdaq

let kAppId = "610670b008fe6c2d735d692f"
let kClientKey = "c58275b0-b461-46a8-b3ae-09e83a67efe3"
//let kAppId = "6106c07308fe6c2d735d6934"
//let kClientKey = "6ed0d95a-f18c-441a-a9d0-617db5a8fd86"

@main
class AppDelegate: UIResponder, UIApplicationDelegate {



    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        // Override point for customization after application launch.
        
        let properties = TDProperties()
        properties.privacySettings.userSubjectToGdpr = TDPrivacyStatus.yes  //GDPR declare if user is in EU
        properties.privacySettings.gdprConsentGiven = TDPrivacyStatus.yes //GDPR consent must be obtained from the user
        properties.privacySettings.ageRestrictedUser = TDPrivacyStatus.yes //Is user subject to COPPA or GDPR age restrictions

        //Tapdaq.sharedSession().setApplicationId("6105be4008fe6c2d735d692c", clientKey: "fdc91ec4-f65a-437d-a344-69a74773f3ba", properties: properties)
        Tapdaq.sharedSession().setApplicationId(kAppId, clientKey: kClientKey, properties: properties)
        
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

