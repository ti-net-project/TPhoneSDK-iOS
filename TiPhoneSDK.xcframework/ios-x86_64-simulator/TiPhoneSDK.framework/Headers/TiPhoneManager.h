//
//  TiPhone.h
//  TiPhoneSDK
//
//  Created by 马迪 on 2022/10/10.
//

#import <Foundation/Foundation.h>
#import <TiPhoneSDK/TiPhoneListener.h>
#import "TiLoginModel.h"
NS_ASSUME_NONNULL_BEGIN


@interface TiPhoneManager : NSObject


+ (instancetype)sharedTiPhoneManager;

/**
 初始化对象
 @param apiUrl 平台url
 @param isDebug 是否Debug环境
 */
- (void)initSDK:(nullable NSString *)apiUrl setDebug:(BOOL)isDebug;

/**
 座席上线接口
 @param loginModel 登录参数模型
 @param webSocketDelegate 监听登录事件 Clink2专用
 @param successBlock  登录成功的回调
 @param errorBlock   登录失败的回调 [status:失败的错误码]
 
 注: strCrmId和strCrmPassword是一对鉴权方式  strCno和strEnterpriseToken是一对鉴权方式
*/
- (void)loginTiPhone:(TiLoginModel *)loginModel webSocketDelegate:(nullable id <TiLoginMessageListener>)webSocketDelegate success:(nullable TiSuccessCallback)successBlock error:(nullable TiFailureCallback)errorBlock;

/**
 认证语音验证码
 @param code 输入电话听到的语音验证码
 @param successBlock  成功的回调
 @param errorBlock   失败的回调 [status:失败的错误码]
 */
- (void)confirmVerification:(NSString *)code success:(nullable TiSuccessCallback)successBlock error:(nullable TiFailureCallback)errorBlock;

/**
 更新员工密码 (仅支持密码登录用户 token鉴权方式不支持)
 @param oldPassword 旧密码
 @param newPassword 新密码
 */
- (void)changePwd:(NSString *)oldPassword newPassword:(NSString *)newPassword success:(nullable TiSuccessCallback)successBlock error:(nullable TiFailureCallback)errorBlock;

/**
 拨打电话
 @param number 需要拨打的手机号
 @param obClid 客户外显号码
 @param requestUniqueId 通话的唯一标识 如果不传 则SDK中会自动生成
 @param userField 自定义参数
 ex: @"{\"id\":\"xxxxxxxx\",\"workNum\":\"xxxxxxx\",\"depId\":\"xxxxxx\"}"
*/
-(void)call:(NSString *)number obClid:(nullable NSString *) obClid
requestUniqueId:(nullable NSString*)requestUniqueId userField:(nullable NSDictionary *)userField;

/**
 外呼事件监听 ， 必须在登录之前调用
 @param listener TiPhoneMessageListener接口的实例
 */
-(void)setOnEventListener:(id<TiOnEventListener>)listener;

/**
 设置回呼监听 需要在登录成功之后调用
@param listener TiIncomingMessageListener接口的实例
*/
-(void)setIncomingMessageListener:(id<TiIncomingMessageListener>)listener;

/**
 挂断电话
 */
-(void)hungUp;

/**
 退出登录
 */
- (void)logoutTiPhone:(nullable TiSuccessCallback)successBlock error:(nullable TiFailureCallback)errorBlock;

/**
 本地音频静音
 @param muted  发送本地音频流(false:默认发送本地音频流  true：发送本地静音音频流）
*/
-(void)setMicrophoneMute:(BOOL)muted;

/**
 检查扬声器是否开启
 @return true  扬声器已开启，语音会输出到扬声器
 @return false 扬声器未开启，语音会输出到听筒
*/
-(BOOL)isSpeakerphoneEnabled;

/**
 启用/关闭扬声器
 @param enabled 是否将音频外放(true：切换到外放  false：切换到听筒)
*/
-(void)setEnableSpeakerphone:(BOOL)enabled;

/**
 发送DTMF消息
 
 @param tones          所需要发送的DTMF消息.
 @param duration       消息时长 单位：秒
 @param interToneGap   消息间隔 单位：秒
*/
-(void)sendDTMF:(NSString *)tones duration:(NSTimeInterval)duration interToneGap:(NSTimeInterval)interToneGap;

/**
 预览外呼
 @param phoneNumber 需要拨打的手机号
 @param obClid 客户外显号码
*/
- (void)previewOutCall:(NSString *)phoneNumber obClid:(nullable NSString *)obClid success:(nullable TiSuccessCallback)successBlock error:(nullable TiFailureCallback)errorBlock;

/**
 获取坐席置忙描述列表
 */
- (void)getAgentSettings:(TiSuccessCallback)successBlock error:(TiFailureCallback)errorBlock;

/**
 获取坐席当前状态
 */
- (void)getAgentStatus:(nullable TiSuccessCallback)successBlock error:(nullable TiFailureCallback)errorBlock;

/**
 坐席置忙
 @param description  设置的置忙描述 需要在获取坐席可用置忙描述列表中选择
 */
- (void)setAgentPause:(NSString *)description success:(nullable TiSuccessCallback)successBlock error:(nullable TiFailureCallback)errorBlock;

/**
 坐席置闲
 */
- (void)setAgentUnPause:(nullable TiSuccessCallback)successBlock error:(nullable TiFailureCallback)errorBlock;

/**
 设置是否需要手机号外显
 */
- (void)setTelExplicit:(BOOL)isTelExplicit;

/**
 Voip转预览外呼
 @param requestUniqueId 通话的唯一标识 如果传入为@"" 则SDK中会自动生成
*/
-(void)transferCall:(NSString *_Nonnull)requestUniqueId success:(nullable TiSuccessCallback)successBlock error:(nullable TiFailureCallback)errorBlock;

/**
 获取sdk版本号
 @return NSString* 版本号
*/
-(NSString *)getVersion;



@end

NS_ASSUME_NONNULL_END
