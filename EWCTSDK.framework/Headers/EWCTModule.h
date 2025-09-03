//
//  EWCTModule.h
//  EwayBLETools
//
//  Created by developer on 2024/4/29.
//
#import <EWBluetoothSDK/EWBluetoothSDK.h>
#import <Foundation/Foundation.h>
#import "EWCTModuleProfiles.h"
#import "EWCTModuleInfoModel.h"
#import "EWCTModuleConfigModel.h"
#import "EWCTModuleMonitorModel.h"

// 升级文件
#import "EWPeripheral+YModem.h"

NS_ASSUME_NONNULL_BEGIN

@interface EWCTModule : NSObject

/// 蓝牙状态发生变化
@property (nonatomic, copy) EWBluetoothDidUpdateStateHandler bluetoothDidUpdateStateHandler;

///单例
+ (instancetype)share;

///配置连接的CT模块（连接成功后传入连接的设备）
/// - Parameters:
///   - ctModule: 连接的CT模块
///   - handler: 配置结果回调
- (void)ew_configureConnectedCTModule: (EWPeripheral *)ctModule
                              handler:(EWCTModuleResultHandler)handler;

/// 获取产品ID
/// - Parameters:
///   - ctModuleName: CT蓝牙广播号
///   - handler: 产品ID回调
- (void)ew_getCTModuleProductID:(NSString *)ctModuleName
                        handler: (EWCTModuleProductIDHandler)handler;

/// 获取产品编号
/// - Parameters:
///   - ctModuleName: CT蓝牙广播号
///   - handler: 产品ID回调
- (void)ew_getCTModuleSN:(NSString *)ctModuleName
                        handler: (EWCTModuleSNHandler)handler;

/// 获取CT版本信息
/// - Parameters:
///   - ctModuleName: CT蓝牙广播号
///   - handler: 产品版本信息回调
- (void)ew_getCTModuleInfo:(NSString *)ctModuleName
                   handler: (EWCTModuleInfoHandler)handler;

/// 读取/写入CT模块配置
/// - Parameters:
///   - ctModuleName: CT蓝牙广播号
///   - isWrite: 是否写入
///   - configModel: 配置信息
///   - handler: 模块配置信息回调
- (void)ew_configCTModule:(NSString *)ctModuleName
                     isWirte:(BOOL)isWirte
                 configModel:(nullable EWCTModuleConfigModel *)configModel
                     handler: (EWCTModuleConfigHandler)handler;

/// 校准CT模块
/// - Parameters:
///   - ctModuleName: CT蓝牙广播号
///   - adjustVol: 校准电压
///   - adjustCur: 校准电流
///   - adjustPower: 校准功率
///   - handler: 校准回调
- (void)ew_configAdjustCTModule:(NSString *)ctModuleName
                      adjustVol: (NSInteger)adjustVol
                      adjustCur:(NSInteger)adjustCur
                    adjustPower:(NSInteger)adjPower
                        handler:(EWCTModuleAdjustHandler)handler;

/// 监视CT模块
/// - Parameters:
///   - ctModuleName: CT蓝牙广播号
///   - handler: 监控充电桩状态回调
- (void)ew_monitorCTStatus:(NSString *)ctModuleName
                             handler:(EWCTMonitorStatusHandler)handler;

/// 停止监控CT状态
/// - Parameters:
///   - ctModuleName: CT蓝牙广播号
///   - handler: 成功回调
- (void)ew_stopMonitorCTStatus:(NSString *)ctModuleName
                                 handler:(EWCTModuleResultHandler)handler;

/// 获取CT Wi-Fi 状态
/// - Parameters:
///   - ctModuleName: CT蓝牙广播号
///   - handler: 获取充电桩 Wi-Fi 状态回调
- (void)ew_getCTModuleWiFiStatus:(NSString *)ctModuleName
                             handler:(EWCTModuleWiFiStatusHandler)handler;

/// 给CT传输 Wi-Fi 信息
/// - Parameters:
///   - ctModuleName: CT蓝牙广播号
///   - SSID: Wi-Fi名称
///   - password: Wi-Fi密码
///   - handler: 获取CT Wi-Fi 状态回调
- (void)ew_transmitWiFiInformationToCTModule:(NSString *)ctModuleName
                                            SSID:(NSString *)SSID
                                        password:(nullable NSString *)password
                                         handler:(EWCTModuleWiFiStatusHandler)handler;

/// CT连接 Wi-Fi
/// - Parameters:
///   - ctModuleName: CT蓝牙广播号
///   - handler: 获取CT Wi-Fi 状态回调
- (void)ew_ctModuleConnectionWiFi:(NSString *)ctModuleName
                              handler:(EWCTModuleWiFiStatusHandler)handler;

/// 断开CT Wi-Fi
/// - Parameters:
///   - ctModuleName: CT蓝牙广播号
///   - handler: 获取CT Wi-Fi 状态回调
- (void)ew_disconnectCTModuleWiFi:(NSString *)ctModuleName
                              handler:(EWCTModuleWiFiStatusHandler)handler;

/// 获取CT Wi-Fi信息
/// - Parameters:
///   - ctModuleName: CT蓝牙广播号
///   -  handler: 获取CT Wi-Fi 信息回调
- (void)ew_getCTModuleWiFiInformation:(NSString *)ctModuleName
                                  handler:(EWCTModuleWiFiInfoHandler)handler;

/// 重置CT Wi-Fi
/// - Parameters:
///   - ctModuleName: CT蓝牙广播号
///   -  handler: 重置回调
- (void)ew_resetCTModuleWiFi:(NSString *)ctModuleName
                         handler:(EWCTModuleResultHandler)handler;

///配置用户ID
/// - Parameters:
///   - ctModuleName: CT蓝牙广播号
///   - userID: 用户id
///   - isWrite: 读/写
///   -  handler: 用户id回调
- (void)ew_configUserIDWithCTModule:(NSString *)ctModuleName
                             userID:(NSString *)userID
                            isWrite:(BOOL)isWrite
                            handler:(EWCTModuleUserIDHandler)handler;

/// 配置机型编码及SN码
/// - Parameters:
///   - ctModuleName: CT蓝牙广播号
///   - isWrite: 是否写入
///   - modelcode: 机型编码
///   - SNCode: SN码
///   - handler: 回调
- (void)ew_configureModelCodeAndSNWithCTModule:(NSString *)ctModuleName
                                           isWrite:(BOOL)isWrite
                                         modelCode:(nullable NSString *)modelcode
                                            SNCode:(nullable NSString *)SNCode
                                           handler:(EWCTModuleModelAndSNCodeHandler)handler;

/// 配置服务器地址
/// - Parameters:
///   - ctModuleName: CT名字
///   - isWrite: 是否写入
///   - urlAddress: 服务器地址
///   - handler: 回调
- (void)ew_configUrlAddressWithCTModule:(NSString *)ctModuleName
                                 isWrite:(BOOL)isWrite
                              urlAddress: (nullable NSString *)urlAddress
                                 handler:(EWCTModuleUrlAddressHandler)handler;

///配置多个服务器地址
///   - ctModuleName: 充电桩名字
///   - isWrite: 写/读
///   - serverID: 服务器编号
///   - url: 服务器地址
///   - handler: 回调
- (void)ew_configureServerWithCTModule: (NSString *)ctModuleName
                                               isWrite: (BOOL)isWrite
                                              serverID: (EWCTModuleServerID)serverID
                                                   url: (NSString *)urlAddress
                                                handle: (EWCTModuleServerHandler)handler;

/// 配置MQTT账号密码
/// - Parameters:
///   - ctModuleName: CT蓝牙广播号
///   - isWrite: 是否写入
///   - account: mqtt账号
///   - password: mqtt密码
///   - key: mqtt密钥
///   - handler: 回调
- (void)ew_configAccountAndPasswordWithCTModule:(NSString *)ctModuleName
                                           isWrite:(BOOL)isWrite
                                                account:(nullable NSString *)account
                                               password:(nullable NSString *)password
                                                   key: (nullable NSString *)mqttkey
                                               handler:(EWCTModuleAccountAndPasswordHandler)handler;

/// 读取IP地址
/// - Parameters:
///   - ctModuleName: CT蓝牙广播号
///   - handler: 回调
- (void)ew_getIPWithCTModule:(NSString *)ctModuleName
                     handler:(EWCTModuleReadIPHandler)handler;

///CT读写从设备SN
/// - Parameters:
///   - ctModuleName: CT蓝牙广播号
///   - isWrite: 是否写入
///   - slaveCount: 从机数量
///   - slaveSNArray: 从机SN数组
///   - handler: 回调
- (void)ew_configureSlaveSNWithCTModule:(NSString *)ctModuleName
                                isWrite:(BOOL)isWrite
                             slaveCount: (NSInteger)slaveCount
                           slaveSNArray: (NSArray<NSString *> *)slaveSNArray
                                handler: (EWCTModuleConfigSlaveSNHandler)handler;

/// OTA升级
/// - Parameters:
///   - ctModuleName: CT蓝牙广播号
///   - upgradeDelegate: 升级代理
///   - filePath: 文件路径
///   - handler: 回调
- (void)ctModuleUpdate:(NSString *)ctModuleName
           upgradeDelegate:(id<EWPeripheralUpgradeDelegate>)upgradeDelegate
                  filePath:(NSString *)filePath
                   handler:(EWCTModuleUpgradeHandler)handler;


@end

NS_ASSUME_NONNULL_END
