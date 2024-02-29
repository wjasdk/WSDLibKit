#
# Be sure to run `pod lib lint WSDLibKit.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'WSDLibKit'
  s.version          = '0.1.0'
  s.summary          = '设备配网SDK'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
一款为设备配网的SDK，通过二维码、局域网、声波给设备传输WiFi信息等数据
                       DESC

  s.homepage         = 'https://github.com/wjasdk/WSDLibKit.git'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'wjasdk' => 'lishutian@wjacloud.com' }
  s.source           = { :git => 'https://github.com/wjasdk/WSDLibKit.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '8.0'

  s.source_files = 'WSDLibKit/Classes/**/*'
  s.vendored_frameworks = 'WSDLibKit/*.{framework}'

  # s.resource_bundles = {
  #   'WSDLibKit' => ['WSDLibKit/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end
