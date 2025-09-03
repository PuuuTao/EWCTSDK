//
//  EWCTModuleInfoModel.h
//  EwayBLETools
//
//  Created by developer on 2024/8/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface EWCTModuleInfoModel : NSObject
// ct名称
@property (nonatomic, strong) NSString *name;
// 网络模块芯片供应商
@property (nonatomic, strong) NSString *networkChipManufacturer;
// 网络模块芯片型号
@property (nonatomic, strong) NSString *networkChipModel;
// 网络模块芯片硬件版本
@property (nonatomic, assign) NSInteger networkChipHardware;
// 网络模块芯片软件版本
@property (nonatomic, assign) NSInteger networkChipSoftware;
@end

NS_ASSUME_NONNULL_END
