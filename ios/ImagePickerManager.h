#import <React/RCTBridgeModule.h>
#import <UIKit/UIKit.h>
#import <React/RCTConvert.h>
#import <QBImagePicker/QBImagePicker.h>
// 集成步骤
// 1. 主工程 Libraries 里引入 RNImagePicker.xcodeproj
// 2. 在 Build Phases - Link Binary with Libraries 中 add QBImagePicker.framework、libRNImagePicker.a
// 3. 在 Build Phases 里 New Copy Files, 把 Copy Files 的 Destination 改成 Frameworks，然后 + QBImagePicker.framework
// 第3步参考自：https://blog.csdn.net/zjpjay/article/details/103597159?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-103597159-blog-96147453.pc_relevant_antiscanv2&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-103597159-blog-96147453.pc_relevant_antiscanv2&utm_relevant_index=1

typedef NS_ENUM(NSInteger, RNImagePickerTarget) {
  camera = 1,
  library
};

@implementation RCTConvert(PresentationStyle)

// see: https://developer.apple.com/documentation/uikit/uimodalpresentationstyle?language=objc
RCT_ENUM_CONVERTER(
    UIModalPresentationStyle,
    (@{
      @"currentContext": @(UIModalPresentationCurrentContext),
      @"fullScreen": @(UIModalPresentationFullScreen),
      @"pageSheet": @(UIModalPresentationPageSheet),
      @"formSheet": @(UIModalPresentationFormSheet),
      @"popover": @(UIModalPresentationPopover),
      @"overFullScreen": @(UIModalPresentationOverFullScreen),
      @"overCurrentContext": @(UIModalPresentationOverCurrentContext)
    }),
    UIModalPresentationCurrentContext,
    integerValue)

@end

@interface ImagePickerManager : NSObject <RCTBridgeModule>

@end
