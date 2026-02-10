#include "qobject.h"
#include <qstring.h>

#ifndef DATASTRUCT_H
#define DATASTRUCT_H

struct brigetestData{
    QString function;  // 测试功能
    QString frequency; // 测试电频
    QString voltage;   // 测试电平
    QString outPutResister; // 输出内阻模式
    bool is_Q; // 是否测量Q值
    bool is_Rs; // 是否测量Rs值
    bool isInitialized;
    brigetestData():function("FUNC:IMP RX\n"),
                    frequency("FREQ 1000\n"),
                    voltage("VOLT 1.0\n"),
                    outPutResister("ORES 100\n"),
                    is_Q(false),
                    is_Rs(false),
                    isInitialized(false){};
};

// 声明元类型
Q_DECLARE_METATYPE(brigetestData);

#endif // DATASTRUCT_H
