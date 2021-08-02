//
//  ViewController.swift
//  WebApp
//
//  Created by Shahid Ghafoor on 01/08/2021.
//

import UIKit
import WebKit
import Foundation
import SystemConfiguration

import Tapdaq


class ViewController: UIViewController, WKUIDelegate ,WKNavigationDelegate, TapdaqDelegate, TDInterstitialAdRequestDelegate, TDBannerAdRequestDelegate {
    
    
    var bannerView: UIView!
    var placementTag: String = TDPTagDefault
    var selectedBannerSize: TDMBannerSize = .standard;
    
    var canShowFullScreenAds: Bool = true
    
    @IBOutlet weak var viewAdHeightConstraint: NSLayoutConstraint!
    @IBOutlet weak var viewBannerContainer: UIView!
    @IBOutlet weak var webView: WKWebView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        
        Tapdaq.sharedSession().delegate = self
        Tapdaq.sharedSession().properties.autoReloadAds = true
        Tapdaq.sharedSession()?.presentDebugViewController()
        
        self.setupTapdaq()
        if isInternetAvailable() {
            // webview navigation
            webView.navigationDelegate = self
            webView.uiDelegate = self
            webView.scrollView.bounces = true
            let myURL = URL(string:"https://www.google.com/")
            let myRequest = URLRequest(url: myURL!)
            webView.load(myRequest)
            // swipe left or right for going back or forward
            webView.allowsBackForwardNavigationGestures = true
            webView.configuration.defaultWebpagePreferences.allowsContentJavaScript = true
            webView.contentMode = .scaleAspectFit
        } else {
            showAlert()
        }
        
        let timer = Timer.scheduledTimer(timeInterval: 10.0, target: self, selector: #selector(activeFullScreenAds), userInfo: nil, repeats: true)
    }
    
    func setupTapdaq() {
        var properties = Tapdaq.sharedSession()?.properties
        if properties == nil {
            properties = TDProperties.default()
        }
        TDLogger.setLogLevel(.debug)
        Tapdaq.sharedSession()?.delegate = self
        Tapdaq.sharedSession()?.setApplicationId(kAppId, clientKey: kClientKey, properties: properties)
    }
    
    func show(adView: UIView?) {
        guard let adView = adView else { return }
        viewBannerContainer.addSubview(adView)
        adView.translatesAutoresizingMaskIntoConstraints = false
        viewAdHeightConstraint.constant = adView.frame.height == 0 ? 250 : adView.frame.height
        let views = [ "adView" : adView ]
        let verticalConstraints = NSLayoutConstraint.constraints(withVisualFormat: "V:|[adView]|", options: NSLayoutConstraint.FormatOptions(rawValue: 0), metrics: nil, views: views)
        let horizontalConstraints = NSLayoutConstraint.constraints(withVisualFormat: "H:|[adView]|", options: NSLayoutConstraint.FormatOptions(rawValue: 0), metrics: nil, views: views)
        viewBannerContainer.addConstraints(verticalConstraints)
        viewBannerContainer.addConstraints(horizontalConstraints)
    }
    
    func webView(_ webView: WKWebView,
                 didStartProvisionalNavigation navigation: WKNavigation!) {
        // webview started loading
        
    }
    
    func webView(_ webView: WKWebView, didFinish navigation: WKNavigation!) {
        // webview finished loading
    }
    
    func webView(_ webView: WKWebView, createWebViewWith configuration: WKWebViewConfiguration, for navigationAction: WKNavigationAction, windowFeatures: WKWindowFeatures) -> WKWebView? {
        if navigationAction.targetFrame == nil {
            let url = navigationAction.request.url
            if url?.description.range(of: "http://") != nil || url?.description.range(of: "https://") != nil || url?.description.range(of: "mailto:") != nil || url?.description.range(of: "tel:") != nil  {
                UIApplication.shared.open(url!)
            }
        }
        return nil
    }
    
    func webView(_ webView: WKWebView, runJavaScriptTextInputPanelWithPrompt prompt: String, defaultText: String?, initiatedByFrame frame: WKFrameInfo, completionHandler: @escaping (String?) -> Void) {
        completionHandler(defaultText)
    }
    
    func webView(_ webView: WKWebView, runJavaScriptAlertPanelWithMessage message: String, initiatedByFrame frame: WKFrameInfo, completionHandler: @escaping () -> Void) {
        completionHandler()
    }
    
    func webView(_ webView: WKWebView, runJavaScriptConfirmPanelWithMessage message: String, initiatedByFrame frame: WKFrameInfo, completionHandler: @escaping (Bool) -> Void) {
        completionHandler(true)
    }
    
    func isInternetAvailable() -> Bool
    {
        var zeroAddress = sockaddr_in()
        zeroAddress.sin_len = UInt8(MemoryLayout.size(ofValue: zeroAddress))
        zeroAddress.sin_family = sa_family_t(AF_INET)
        
        let defaultRouteReachability = withUnsafePointer(to: &zeroAddress) {
            $0.withMemoryRebound(to: sockaddr.self, capacity: 1) {zeroSockAddress in
                SCNetworkReachabilityCreateWithAddress(nil, zeroSockAddress)
            }
        }
        
        var flags = SCNetworkReachabilityFlags()
        if !SCNetworkReachabilityGetFlags(defaultRouteReachability!, &flags) {
            return false
        }
        let isReachable = flags.contains(.reachable)
        let needsConnection = flags.contains(.connectionRequired)
        return (isReachable && !needsConnection)
    }
    
    func showAlert() {
        if !isInternetAvailable() {
            let alert = UIAlertController(title: "Warning", message: "The Internet is not available", preferredStyle: .alert)
            let action = UIAlertAction(title: "Dismiss", style: .default, handler: nil)
            alert.addAction(action)
            present(alert, animated: true, completion: nil)
        }
    }
    
    func didLoadConfig() {
        print("Did load config")
        
        let isLoadEnabled = Tapdaq.sharedSession().isInitialised()
        if isLoadEnabled {
            Tapdaq.sharedSession()?.loadBanner(forPlacementTag: placementTag, with: .standard, delegate: self)
            Tapdaq.sharedSession()?.loadInterstitial(forPlacementTag: placementTag, delegate: self)// loadVideo(forPlacementTag: placementTag, delegate: self)
        }
        
    }
    
    func adRequest(_ adRequest: TDAdRequest, didFailToLoadWithError error: TDError?) {
        print(error?.localizedDescription)
    }

    func didRefreshBanner(for adRequest: TDBannerAdRequest) {
        
    }
    
    func didFailToRefreshBanner(for adRequest: TDBannerAdRequest, withError: TDError?) {
        print(withError?.localizedDescription ?? "")
    }

    
    func didFailToLoadConfigWithError(_ error: TDError!) {
        print("Did fail to load config with error: %@", error.localizedDescription)
        
    }
    
    func didClick(_ adRequest: TDAdRequest) {
        print("Did click ad unit - %@ tag - %@", NSStringFromAdUnit(adRequest.placement.adUnit), adRequest.placement.tag)
    }
    
    func didLoad(_ adRequest: TDInterstitialAdRequest) {
        if canShowFullScreenAds {
            self.showFullScreenAd()
        }
    }
    
    func didLoad(_ adRequest: TDBannerAdRequest){
        bannerView = adRequest.bannerView()
        show(adView: self.bannerView)
    }
    
    @objc func activeFullScreenAds() {
        self.canShowFullScreenAds = true
        
        let isReady = Tapdaq.sharedSession().isInterstitialReady(forPlacementTag: placementTag)
        
        if isReady {
            self.showFullScreenAd()
        }
    }
    
    func showFullScreenAd() {
        if self.canShowFullScreenAds {
            self.canShowFullScreenAds = false
            Tapdaq.sharedSession()?.showInterstitial(forPlacementTag: placementTag, delegate: self)
        }
    }
}

