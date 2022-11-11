#
#  Be sure to run `pod spec lint TiPhoneSDK.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|

  spec.name         = "TiPhoneSDK"
  spec.version      = "1.0.0"
  spec.summary      = "TiPhoneSDK iOS 实时语音呼叫SDK"

  spec.description  = <<-DESC
  TODO: Add long description of the pod here.
                   DESC

  spec.homepage     = "https://github.com/ti-net-project/TPhoneSDK-iOS.git"

  spec.license      = { :type => 'MIT', :file => 'LICENSE' }
  spec.author           = { 'gyb1314' => 'gyb_1314@126.com' }
  spec.source           = { :git => 'git@github.com:ti-net-project/TPhoneSDK-iOS.git', :tag => spec.version.to_s }

  #spec.platform     = :ios, "11.0"
spec.ios.deployment_target = '13.0'

  spec.vendored_frameworks  = "TiPhoneSDK.xcframework"
  #spec.vendored_frameworks  = "TPhoneSDKCore.xcframework"
  #spec.vendored_frameworks  = "WebRTC.framework"

 #spec.pod_target_xcconfig = {'VALID_ARCHS'=>'arm64 x86_64','EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  #spec.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }

  #spec.user_target_xcconfig = { 'BUILD_LIBRARY_FOR_DISTRIBUTION' => 'YES' }
  #spec.pod_target_xcconfig = { 'BUILD_LIBRARY_FOR_DISTRIBUTION' => 'YES' }

end
