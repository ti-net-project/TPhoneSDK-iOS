//
//  TiLoginModel.h
//  TiPhoneSDK
//
//  Created by 马迪 on 2022/12/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// 登录账号类型
static NSString *TiPhoneLoginType_CrmIdAndPwd    = @"crmIdAndPwd"; // 员工和密码登录
static NSString *TiPhoneLoginType_CnoAndToken    = @"conAndToken"; // 坐席编号和token登录

// 平台类型
static NSString *TiPhonePlatformType_CTI    = @"platformCTI"; // CTI
static NSString *TiPhonePlatformType_Clink2    = @"platformClink2"; // Clink2

@interface TiLoginModel : NSObject

/// 企业id
@property (nonatomic, copy, nonnull) NSString *enterpriseId;
/// 登录类型，crmId和crmPassword是一对鉴权方式，  cno和token是一对鉴权方式
@property (nonatomic, copy, nonnull) NSString *loginType;
/// 平台类型, CTI/Clink2
@property (nonatomic, copy, nonnull) NSString *platformType;
/// 员工工号 / 座席工号
@property (nonatomic, copy, nonnull) NSString *loginKey;
/// 员工密码 / 企业token值
@property (nonatomic, copy, nonnull) NSString *loginSecret;
/// 绑定的手机号码
@property (nonatomic, copy, nonnull) NSString *bindTel;
/// 系统内部显示名称
@property (nonatomic, copy, nullable) NSString *showName;
/// 是否需要手机号外显
@property (nonatomic, assign) BOOL isTelExplicit;
/// 外部动态配置：是否需要调用上线接口(默认为是)。ex: @{@"isOnline":@"true"}
@property (nonatomic, strong, nonnull) NSDictionary *advanceParams;

@end

NS_ASSUME_NONNULL_END
