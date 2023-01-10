//
//  TiPhoneListener.h
//  TiPhoneSDK
//
//  Created by 马迪 on 2022/10/11.
//

#ifndef TiPhoneListener_h
#define TiPhoneListener_h

#pragma mark - Event Name
//
const static NSString * _Nullable JanusSignalTypeSuccess = @"success";
const static NSString * _Nullable JanusSignalTypeAck     = @"ack";
const static NSString * _Nullable JanusSignalTypeEvent   = @"event";
const static NSString * _Nullable JanusMsgTypeError      = @"error";
const static NSString * _Nullable JanusMsgTypeWebrtcup   = @"webrtcup";

//接收event-type
const static NSString * _Nullable Registering = @"registering";
//const static NSString * _Nullable Registration_Failed = @"registration_failed";
const static NSString * _Nullable Registered = @"registered";
const static NSString * _Nullable Calling = @"calling";
//const static NSString * _Nullable Rolling = @"Rolling";
const static NSString * _Nullable Progress = @"progress";
const static NSString * _Nullable Accepted = @"accepted";
const static NSString * _Nullable Hangup = @"hangup";

//custom
const static NSString * _Nullable WssStatus = @"wssStatus";
const static NSString * _Nullable RequestUniqueId = @"requestUniqueId";

#pragma mark - 接口中error的错误码 ErrorCode

const static int ErrNetwork                                     = 5001; // 网络请求错误
const static int ErrorNoSupport                                 = 5002; // 功能上不支持的错误
const static int ErrorParams                                    = 5003; // 请求参数错误

const static int ErrorInit                                      = 6001; // 初始化错误
const static int ErrorAuth                                      = 6002; // 鉴权错误
const static int ErrorErrorTelVerify                            = 6003; // 手机号验证错误，需要验证手机号
const static int ErrorConfirmVerification                       = 6004; // 确认语音验证码错误
const static int ErrorChangePwd                                 = 6005; // 修改密码错误
const static int ErrorPreviewOutCall                            = 6006; // 预览外呼错误

const static int ErrorAgentPause                                = 7001; // 坐席置忙错误
const static int ErrorAgentUnPause                              = 7002; // 坐席置闲错误
const static int ErrorAgentGet                                  = 7003; // 获取坐席状态错误

const static int ErrorLogin                                     = 8001; // 上线错误 Clink2
const static int ErrorKickOut                                   = 8002; // 被踢 Clink2


#pragma mark - Message Code

const static int MESSAGE_REGISTERED                             = 101;    // 注册成功
const static int MESSAGE_REGISTER_FAILED                        = 102;    // 注册失败
const static int MESSAGE_CALLING                                = 103;    // 响铃中
const static int MESSAGE_ACCEPTED                               = 104;    // 已接通
const static int MESSAGE_HANGUP                                 = 105;    // 已挂断
const static int MESSAGE_RINGING                                = 106;    // 对端开始响铃(本端无铃声)
const static int MESSAGE_PROGRESS                               = 107;    // 对端开始响铃(本端有铃声)
const static int MESSAGE_TRANSFER_CALL                          = 108;    // 切换为预览外呼

const static int MESSAGE_PARAMS_COUNT_INCORRECT                 = 201;    // 参数个数不合法
const static int MESSAGE_PARAMS_KEYLENGTH_INCORRECT             = 202;    // 参数中Key长度不合法
const static int MESSAGE_PARAMS_VALUELENGTH_INCORRECT           = 203;    // 参数中的Value长度不合法
const static int MESSAGE_PARAMS_KEYUSED                         = 204;    // 参数key已用
const static int MESSAGE_WAIT_LASTCALL                          = 205;    // 等待上一次拨打结束在拨打

const static int MESSAGE_REQUEST_UNIQUE_ID                      = 301;    // 当传入唯一标识为空时 sdk生成一个并通过这个消息id返回
const static int MESSAGE_RTC_QOS_GOOD                           = 350;    // QOS GOOD
const static int MESSAGE_RTC_QOS_BAD                            = 351;    // QOS BAD
const static int MESSAGE_RTC_QOS_COMMON                         = 352;    // QOS Common

const static int MESSAGE_ERROR                                  = 400;    // 错误信息
const static int MESSAGE_AGENT_AXB_ERROR                        = 401;    // AXB绑定错误信息
const static int MESSAGE_AGENT_PREVIEWCALL_ERROR                = 402;    // 预览外呼错误信息
const static int MESSAGE_NETPEER_CLOSED                         = 410;    //

#pragma mark - Login Code

const static int LOGIN_AUTH_ERROR                               = 10001;    //鉴权错误，请检查输入的企业Id,账号和密码是否正确。
const static int LOGIN_ERROR                                    = 10002; // 登录错误
const static int LOGIN_VERIFICATION_ERROR                       = 10003;//请求语音验证错误
const static int LOGIN_CONFIRM_VERIFICATION_ERROR               = 10004; // 确认验证码错误
const static int LOGIN_CHANGE_PWD_ERROR                         = 10005; // 修改密码错误
const static int LOGIN_PREVIEW_OUTCALL_ERROR                    = 10006; //预览外呼错误
const static int LOGIN_NETWORK_ERROR                            = 10007; // 网络请求失败
const static int LOGIN_NO_SUPPORT_ERROR                         = 10008; // 不支持的功能
const static int LOGIN_AGENT_PAUSE_ERROR                        = 10009; // 坐席置忙错误
const static int LOGIN_AGENT_UNPAUSE_ERROR                      = 10011; // 坐席置闲错误
const static int LOGIN_AGENT_GET_ERROR                          = 10012; //获取坐席状态
const static int LOGIN_WEBSOCKET_ERROR                          = 10013; // WebSocket链接错误
const static int LOGIN_AGENT_Status_ERROR                       = 10014; // 座席状态错误


typedef void (^TiSuccessCallback)(NSString * _Nullable data);
typedef void (^TiFailureCallback)(NSInteger code, NSString * _Nullable msg);


@protocol TiOnEventListener <NSObject>

- (void)onEventError:(int32_t)errCode errMsg:(nullable NSString *)errMsg;

- (void)onEventChange:(int)eventId message:(nullable NSString *)message;

@end

@protocol TiIncomingMessageListener <NSObject>

- (void)onIncomingError:(int32_t)errCode errMsg:(nullable NSString *)errMsg;

- (void)onIncomingMessage:(NSString* _Nullable)message;

@end

@protocol TiLoginMessageListener <NSObject>

- (void)onLoginMessageError:(int32_t)errCode errMsg:(nullable NSString *)errMsg;

- (void)onLoginMessageSuccess:(NSString* _Nullable)message;

- (void)onLoginMessagWebSocketMessage:(NSString* _Nullable)message;

@end





#endif /* TiPhoneListener_h */
