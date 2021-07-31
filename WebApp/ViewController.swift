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
    
    @IBOutlet weak var webView: WKWebView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        Tapdaq.sharedSession().delegate = self
        Tapdaq.sharedSession().properties.autoReloadAds = true
        
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
        
    }
    
    func didLoadConfig() {
        Tapdaq.sharedSession().loadInterstitial(forPlacementTag: "my_interstitial_tag", delegate: self)
    }
    
    func didLoad(_ adRequest: TDInterstitialAdRequest) {
        if adRequest.placement.tag == "my_interstitial_tag" {
            if adRequest.placement.adUnit == .unitStaticInterstitial {
                adRequest.display()
            }
        }
    }
    
    
    func loadBannerAd() {
        Tapdaq.sharedSession()?.loadBanner(forPlacementTag: "my_banner_tag", with: .standard, delegate: self)
        
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
}

