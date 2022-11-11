//
//  TiPhoneListener.h
//  TiPhoneSDK
//
//  Created by 马迪 on 2022/10/11.
//

#ifndef TiPhoneListener_h
#define TiPhoneListener_h


// message definitions
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
