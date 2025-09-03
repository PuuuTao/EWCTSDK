//
//  EWCTModuleProfiles.h
//  EwayBLETools
//
//  Created by developer on 2024/4/29.
//

#ifndef EWCTModuleProfiles_h
#define EWCTModuleProfiles_h

#import <EWBluetoothSDK/EWBluetoothSDK.h>

@class EWCTModuleMonitorModel, EWCTModuleInfoModel, EWCTModuleConfigModel;

typedef NS_ENUM(NSUInteger, EWCTCommandType) {
    EWCTCommandTypeStart = 22, //启动
    EWCTCommandTypeStop = 44, //停止
    EWCTCommandTypeReadProductID = 0x00, //读产品id
    EWCTCommandTypeReadSN = 0x01, //读产品编号
    EWCTCommandTypeReadDeviceInfo = 0x02, //读设备版本信息
    EWCTCommandTypeConfigModule = 0x04, //模块配置
    EWCTCommandTypeAdjust = 0x05, //模块校准
    EWCTCommandTypeMoniter = 0x06, //监视
    EWCTCommandTypeNetwork = 0x08, //wifi
    EWCTCommandTypeUserID = 0x0C, //配置用户id
    EWCTCommandTypeConfigIDSN = 0x0D, //配置机型编码及SN码
    EWCTCommandTypeConfigUrl = 0x0E, //配置服务器地址
    EWCTCommandTypeConfigServerURL = 0x14, //配置多个服务器
    EWCTCOmmandTypeMQTTAccount = 0x15, //配置MQTT账号密码
    EWCTCommandTypeReadIP = 0x20, //读取IP地址
    EWCTCommandTypeSlaveSN = 0x21, //读写从设备SN
    EWCTCommandTypeUpgrade = 0xF0,      // OTA升级
};

//CT控制模式
typedef NS_ENUM(NSUInteger, EWCTControlMode) {
    EWCTControlModeTcpCP = 0x00, //modbus_tcp(充电桩)
    EWCTControlModeMqtt = 0x01, //mqtt
    EWCTControlModeTcpMI = 0x02, //modbus_tcp(微逆)
};

//监视错误
typedef NS_ENUM(NSUInteger, EWCTMonitorError) {
    EWCTMonitorErrorNo = 0x00, //无错误
    EWCTMonitorErrorPowerMeter = 0x01, //电表芯片故障
    EWCTMonitorErrorActPower = 0x02, //有功功率超出范围
    EWCTMonitorErrorAprtPower = 0x03, //视在功率超出范围
    EWCTMonitorErrorVoltage = 0x04, //电压超范围
    EWCTMonitorErrorCurrent = 0x05, //电流超范围
    EWCTMonitorErrorTypeNotSet = 0x06, //CT类型未设置
};

typedef NS_ENUM(NSUInteger, EWCTWiFiStatus) {
    EWCTWiFiStatusDisconnect = 0x00,     // 未连接
    EWCTWiFiStatusConnecting = 0x01,     // 连接中
    EWCTWiFiStatusConnected = 0x02,      // 已连接
    EWCTWiFiStatusConnectFailed = 0x03,  // 连接失败
    EWCTWiFiStatusDisabled = 0x04,       // 不可用
    EWCTWiFiStatusUnknow = 0x99,         // 未知
};

//服务器编号
typedef NS_ENUM(NSUInteger, EWCTModuleServerID) {
    EWCTModuleMQTTServer = 0x00, //MQTT服务器
    EWCTModuleCloudServer = 0x01, //云快充服务器
};

// 蓝牙状态回调
typedef void (^EWBluetoothDidUpdateStateHandler)(EWBluetoothState state);
// 发现CT回调(蓝牙广播号)
typedef void (^EWScanCTModuleHandler)(NSString *_Nullable ctModuleName);
// CT消失回调(蓝牙广播号)
typedef void (^EWCTModuleDisappearHandler)(NSString *_Nullable ctModuleName);
// 停止扫描CT回调(是否成功)
typedef void (^EWStopScanCTModuleHandler)(BOOL success);
// CT成功失败结果回调(名称，成功否，错误)
typedef void (^EWCTModuleResultHandler)(NSString * _Nullable ctModuleName, BOOL result, NSError * _Nullable error);
// CT ProductID（名称，ProductID，错误）
typedef void (^EWCTModuleProductIDHandler)(NSString * _Nullable ctModuleName, NSString * _Nullable productID,  NSError * _Nullable error);
// CT SN（名称，SN，错误）
typedef void (^EWCTModuleSNHandler)(NSString * _Nullable ctModuleName, NSString * _Nullable sn,  NSError * _Nullable error);
// CT模块信息（名称，模块信息，错误）
typedef void (^EWCTModuleInfoHandler)(NSString * _Nullable ctModuleName, EWCTModuleInfoModel * _Nullable infoModel, NSError * _Nullable error);
// CT模块配置（名称、模块配置信息，错误）
typedef void (^EWCTModuleConfigHandler)(NSString * _Nullable ctModuleName, EWCTModuleConfigModel * _Nullable configModel, NSError * _Nullable error);
// CT模块校准（名称、校准电压、校准电流，校准功率，错误）
typedef void (^EWCTModuleAdjustHandler)(NSString * _Nullable ctModuleName, NSNumber * _Nullable adjustVol, NSNumber * _Nullable adjustCur,  NSNumber * _Nullable adjustPower, NSError * _Nullable error);
// 监控CT状态(名称，状态模型，错误信息)
typedef void (^EWCTMonitorStatusHandler)(NSString * _Nullable ctModuleName, EWCTModuleMonitorModel * _Nullable monitorModel, NSError * _Nullable error);
// 获取充电桩 Wi-Fi 状态(名称，Wi-Fi 状态，错误信息)
typedef void (^EWCTModuleWiFiStatusHandler)(NSString * _Nullable ctModuleName, EWCTWiFiStatus status, NSError * _Nullable error);
// 获取充电桩Wi-Fi信息(名称，Wi-Fi，错误信息)
typedef void (^EWCTModuleWiFiInfoHandler)(NSString * _Nullable ctModuleName, NSString * _Nullable wifiName,  NSError * _Nullable error);
// CT UserID回调(名称，UserID，错误)
typedef void (^EWCTModuleUserIDHandler)(NSString * _Nullable ctModuleName, NSString * _Nullable userID, NSError * _Nullable error);
// CT机型编码及SN码回调(名称，机型编码，SN码，错误)
typedef void (^EWCTModuleModelAndSNCodeHandler)(NSString * _Nullable ctModuleName, NSString * _Nullable modelCode, NSString * _Nullable SNCode, NSError * _Nullable error);
// CT服务器地址回调(名称，服务器地址，错误)
typedef void (^EWCTModuleUrlAddressHandler)(NSString * _Nullable ctModuleName, NSString * _Nullable urlAddress, NSError * _Nullable error);
// CT配置多个服务器地址回调(名称，服务器ID, 服务器地址，错误)
typedef void (^EWCTModuleServerHandler)(NSString * _Nullable ctModuleName, EWCTModuleServerID serverID,NSString * _Nullable urlAddress, NSError * _Nullable error);
//配置mqtt账号密码回调 (名称，账号，密码，错误)
typedef void (^EWCTModuleAccountAndPasswordHandler)(NSString * _Nullable ctModuleName, NSString * _Nullable account, NSString * _Nullable password, NSString * _Nullable key, NSError * _Nullable error);
// CT读取ip地址回调(名称，ip地址，错误)
typedef void (^EWCTModuleReadIPHandler)(NSString * _Nullable ctModuleName, NSString * _Nullable ip, NSError * _Nullable error);
// CT读取从设备SN
typedef void (^EWCTModuleConfigSlaveSNHandler)(NSString * _Nullable ctModuleName, NSArray <NSString *> * _Nullable slaveSNArray, NSError * _Nullable error);
// 升级回调(名称，进度，当前时间，总时间，错误信息)
typedef void (^EWCTModuleUpgradeHandler)(NSString * _Nullable ctModuleName, double progress, NSInteger currentTime, NSInteger totalTime, NSError * _Nullable error);
#endif /* EWCTModuleProfiles_h */
