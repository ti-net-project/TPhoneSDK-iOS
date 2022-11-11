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
                   DESC

  spec.homepage     = "https://github.com/ti-net-project/TPhoneSDK-iOS"

  spec.license      = { :type => "MIT", :file => "FILE_LICENSE" }
  s.author           = { 'gyb1314' => 'gyb_1314@126.com' }
  s.source           = { :git => 'https://github.com/ti-net-project/TPhoneSDK-iOS', :tag => s.version.to_s }

  s.ios.deployment_target = '11.0'
  s.vendored_frameworks  = "TPhoneSDKCore.xcframework"
  s.vendored_frameworks  = "WebRTC.framework"

  s.pod_target_xcconfig = {'VALID_ARCHS'=>'arm64 x86_64','EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }

end
