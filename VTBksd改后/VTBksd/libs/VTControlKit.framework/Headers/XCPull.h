
typedef enum{
    pTop,
    pDown
}XCPullScrollOrientation;

typedef enum{
    tDisplay,
    tLoad,
    tNotLoad,
    tDisappear,
    tLoading,
    tNotData
}XCPullTopViewState;

typedef enum{
    dDisplay,
    dLoad,
    dNotLoad,
    dDisappear,
    dLoading,
    dNotData
}XCPullDownViewState;


#define ANMAITON_DES    0.25


#define DOWN_VIEW_HEIGHT 460                        //加载更多view高
#define TOP_VIEW_HEIGHT 460                         //下拉刷新view高

#define TOP_CHECK_H 60                              //下拉刷新检测范围
#define DOWN_CHECK_H 45                             //加载更多检测范围

//#define PULL_MESSAGE_IMG_NAME @"loadingBackgroud.png"
#define PULL_MESSAGE_IMG_H  26
#define PULL_MESSAGE_SHOW_ANMATION_TIME 0.85
#define PULL_MESSAGE_SHOW_TIME 1                    //提示栏默认停留1秒钟后开始消失动画




