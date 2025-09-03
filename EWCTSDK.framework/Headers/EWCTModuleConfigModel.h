//
//  EWCTModuleConfigModel.h
//  EwayBLETools
//
//  Created by developer on 2024/8/14.
//

#import <Foundation/Foundation.h>
#import "EWCTModuleProfiles.h"

NS_ASSUME_NONNULL_BEGIN


@interface EWCTModuleConfigModel : NSObject

//电流阀值
@property (nonatomic, assign) NSInteger current;
//控制模式（预留）
@property (nonatomic, assign) NSInteger controlMode;
//CT防逆流开关
@property (nonatomic, assign) BOOL antiBackflowSwitch;

@end

NS_ASSUME_NONNULL_END
