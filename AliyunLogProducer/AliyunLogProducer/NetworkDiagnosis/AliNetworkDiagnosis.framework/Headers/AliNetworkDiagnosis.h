//
//  AliNetworkDiagnosis.h
//  AliNetworkDiagnosis
//
//  Created by colin on 2021/4/2.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, AliNetDiagLogLevel){
    AliNetDiagLogLevelUpload = 10, // 上报SLS+写文件
    AliNetDiagLogLevelFile   = 11, // 写文件
    AliNetDiagLogLevelError  = 12, // 写文件+打印控制台
    AliNetDiagLogLevelWarn   = 13, // 业务侧选择性打印到控制台
    AliNetDiagLogLevelInfo   = 14, // 业务侧选择性打印到控制台
    AliNetDiagLogLevelDebug  = 15  // 业务侧选择性打印到控制台

};

@protocol AliNetworkDiagnosisDelegate <NSObject>

- (void)report:(NSString*)content level:(AliNetDiagLogLevel)level context:(id)context;

- (void)log:(NSString*)content level:(AliNetDiagLogLevel)level context:(id)context;

@end

@interface AliNetworkDiagnosis : NSObject
// objectType: 52001
+(void)handlePushMessage:(NSString*)message type:(NSString*)type context:(id)context;

+(void)registerDelegate:(id<AliNetworkDiagnosisDelegate>)delegate;

+(void)init:(NSString*)appKey;
+(void)init:(NSString*)appKey deviceId:(NSString*)deviceId withSiteId:(NSString*)siteId;

@end

