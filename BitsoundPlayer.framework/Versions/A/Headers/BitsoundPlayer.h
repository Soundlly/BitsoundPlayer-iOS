//
//  BitsoundPlayerLib.h
//  BitsoundPlayerLib
//
//  Created by wonje-soundlly on 2017. 7. 21..
//  Copyright © 2017년 wonje-soundlly. All rights reserved.
//

#import <Foundation/Foundation.h>


@protocol BitsoundPlayerDelegate;

@interface BitsoundPlayer : NSObject

@property (nonatomic, weak, nullable) id <BitsoundPlayerDelegate> delegate;

/**
 *  singleton BitsoundReceiver instance를 return한다.
 */
+ (nonnull BitsoundPlayer *)sharedInstance;

/**
 * 해당 beacon으로 신호 play
 * beacon : play할 beacon id
 * volume : VOL_MAX_DBFS = 0, VOL_MIN_DBFS = -32
 */

- (void)playWithBeacon:(unsigned int)beacon volume:(int)volume;

/**
 * 해당 beacon으로, duration만큼 신호 play
 * beacon : play할 beacon id
 * volume : VOL_MAX_DBFS = 0, VOL_MIN_DBFS = -32
 * duration : 초단위로, duration 동안 play하다가 stop
 */
- (void)playWithBeacon:(unsigned int)beacon volume:(int)volume duration:(NSTimeInterval)duration;

/**
 * play 종료
 */
- (void)stop;

@end


@protocol BitsoundPlayerDelegate <NSObject>

/**
 *	player play 직후에 호출된다.
 */
- (void)playerDidStart;

/**
 *	player stop 직후에 호출된다.
 */
- (void)playerDidStop;

/**
 *	play시, 오류가 발생될때 호출된다.
 */
- (void)playWithError:(NSError *_Nullable)error;

/**
 *	stop시, 오류가 발생될때 호출된다.
 */
- (void)stopWithError:(NSError *_Nullable)error;

@end
