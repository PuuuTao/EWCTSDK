//
//  EWCTModuleMonitorModel.h
//  EwayBLETools
//
//  Created by developer on 2024/4/29.
//

#import <Foundation/Foundation.h>
#import "EWCTModuleProfiles.h"

NS_ASSUME_NONNULL_BEGIN

@interface EWCTModuleMonitorModel : NSObject

// 电压
@property (nonatomic, assign) float voltage;
// 电流
@property (nonatomic, assign) float current;
// 有功功率
@property (nonatomic, assign) float actPower;
// 视在功率
@property (nonatomic, assign) float aprtPower;
// 温度
@property (nonatomic, assign) float temp;
// sw
@property (nonatomic, assign) NSInteger sw;
// 错误
@property (nonatomic, assign) EWCTMonitorError ctMonitorError;

@end

NS_ASSUME_NONNULL_END
