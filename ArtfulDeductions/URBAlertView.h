//
//  URBAlertView.h
//  URBFlipModalViewControllerDemo
//
//  Created by Nicholas Shipes on 12/21/12.
//  Copyright (c) 2012 Urban10 Interactive. All rights reserved.
//

#import <UIKit/UIKit.h>

@class ARTAvatar;
@class ARTAlertImageView;

enum {
	URBAlertAnimationDefault = 0,
	URBAlertAnimationFade,
	URBAlertAnimationFlipHorizontal,
	URBAlertAnimationFlipVertical,
	URBAlertAnimationTumble,
	URBAlertAnimationSlideLeft,
	URBAlertAnimationSlideRight,
    URBAlertAnimationNone
};
typedef NSInteger URBAlertAnimation;

extern CGSize const kURBAlertViewDefaultSizeIPhone5;
extern CGSize const kURBAlertViewDefaultSizeIPhone6;
extern CGSize const kURBAlertViewDefaultSizeIPad;

@interface URBAlertView : UIView <UITextFieldDelegate>

typedef void (^URBAlertViewBlock)(NSInteger buttonIndex, URBAlertView *alertView);

@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *message;
@property (nonatomic, strong) UIView *contentView;

///-----------------
/// @name Appearance
///-----------------

@property (nonatomic, strong) UIColor *backgroundColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, assign) CGFloat backgroundGradation UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *strokeColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, assign) CGFloat strokeWidth UI_APPEARANCE_SELECTOR;
@property (nonatomic, assign) CGFloat cornerRadius UI_APPEARANCE_SELECTOR;

@property (nonatomic, strong) UIFont *titleFont UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *titleColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *titleShadowColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, assign) CGSize titleShadowOffset UI_APPEARANCE_SELECTOR;

@property (nonatomic, strong) UIFont *messageFont UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *messageColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *messageShadowColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, assign) CGSize messageShadowOffset UI_APPEARANCE_SELECTOR;

@property (nonatomic) NSTextAlignment messageTextAlignment UI_APPEARANCE_SELECTOR;
@property (nonatomic) NSTextAlignment titleTextAlignment UI_APPEARANCE_SELECTOR;

//------------------------
// @name Button Appearance
//------------------------

@property (nonatomic, strong) UIColor *buttonBackgroundColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *buttonStrokeColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, assign) CGFloat buttonStrokeWidth UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *cancelButtonBackgroundColor UI_APPEARANCE_SELECTOR;

@property (nonatomic, strong) UIFont *textFieldFont UI_APPEARANCE_SELECTOR;

@property (nonatomic, assign) BOOL darkenBackground;
@property (nonatomic, assign) BOOL blurBackground;

@property (nonatomic, strong) ARTAlertImageView *alertImageView;


+ (URBAlertView *)dialogWithTitle:(NSString *)title message:(NSString *)message;

- (id)initWithTitle:(NSString *)title message:(NSString *)message;
- (id)initWithTitle:(NSString *)title
			message:(NSString *)message
  cancelButtonTitle:(NSString *)cancelButtonTitle
  otherButtonTitles:(NSString *)otherButtonTitles, ... NS_REQUIRES_NIL_TERMINATION;

- (NSInteger)addButtonWithTitle:(NSString *)title;

- (void)addAlertImage:(UIImage *)image imageScale:(CGFloat)imageScale backgroundColor:(UIColor *)backgroundColor captionText:(NSString *)captionText;
- (void)addSpeechBubbleWithSpeechText:(NSString *)speechText;

- (void)addTextFieldWithPlaceholder:(NSString *)placeholder secure:(BOOL)secure;
- (NSString *)textForTextFieldAtIndex:(NSUInteger)index;

- (void)setTitleTextAttributes:(NSDictionary *)textAttributes UI_APPEARANCE_SELECTOR;
- (void)setMessageTextAttributes:(NSDictionary *)textAttributes UI_APPEARANCE_SELECTOR;

//- (void)setMessageTextAlignment:(NSTextAlignment)textAlignment UI_APPEARANCE_SELECTOR;
//- (void)setTitleTextAlignment:(NSTextAlignment)textAlignment UI_APPEARANCE_SELECTOR;

- (void)setButtonTextAttributes:(NSDictionary *)textAttributes forState:(UIControlState)state UI_APPEARANCE_SELECTOR;
- (void)setCancelButtonTextAttributes:(NSDictionary *)textAttributes forState:(UIControlState)state UI_APPEARANCE_SELECTOR;
- (void)setTextFieldTextAttributes:(NSDictionary *)textAttributes;

- (void)setHandlerBlock:(URBAlertViewBlock)block;

///--------------------------------
/// @name Presenting and Dismissing
///--------------------------------
- (void)show;
- (void)showWithCompletionBlock:(void(^)())completion;
- (void)showWithAnimation:(URBAlertAnimation)animation ;
- (void)showWithAnimation:(URBAlertAnimation)animation  completionBlock:(void(^)())completion;

- (void)hide;
- (void)hideWithCompletionBlock:(void(^)())completion;
- (void)hideWithAnimation:(URBAlertAnimation)animation;
- (void)hideWithAnimation:(URBAlertAnimation)animation completionBlock:(void(^)())completion;

@end
