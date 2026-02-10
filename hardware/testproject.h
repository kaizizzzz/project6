#ifndef TESTPROJECT_H
#define TESTPROJECT_H
#include "device.h"
#include "pm.h"

#include <qtimer.h>

// 测试状态 线性调节率测试的测试流程
enum class TestState_LineRegulation{
    State_getContrl,  // 进入远程控制状态
    State_setMinInputV, // 设置最小输入电压
    State_turnOnInput, // 开启输入电压
    State_setMaxLoad,  // 设置最大负载
    State_turnOnOutput,// 开启负载
    State_getOutputV_min, // 获得最小输入电压下的输出电压
    State_setMaxInputV, //设置最大输入电压
    State_getOutputV_max,// 获得最大输入电压下的输出电压
    State_turnDownOutput // 关闭负载，方便交替正负输出测试
};
// 顺便获取输入电压实际值，用以计算效率
enum class TestState_LoadRegulation{
    State_getContrl,
    State_setStandardInputV,
    State_turnOnInput,
    State_setMinLoad,
    State_turnOnOutput,
    State_getOutputV_min,  // 额定输入电压下，最小负载的输出电压
    State_setMaxLoad,
    State_getOutputV_max,   // 额定输入电压下，最大负载的输出电压
    State_getinputA_staInputV_maxload, // 输入电流,计算效率 *
    State_getActV, // 获取实际上的输入电压 *
    State_turnDownOutput    // 关闭负载，方便交替正负输出测试
};

enum class TestState_input_A{
    State_getContrl,
    State_setStandardInputV,
    State_turnOnInput,
    State_getInput_A
};


class TestProject : public QObject
{
    Q_OBJECT
public:
    TestProject(QObject *parent = nullptr);
    TestProject(QObject *parent, Device *inputDe, Device *loadDe, PM *pm);
    ~TestProject();

    void startTestSequence_LR(); // 开始线性调节率测试
    void handleStateMachine_LR(); // 处理线性调节率测试状态一次

    void startTestSequence_LoadR(); // 开始负载调节率测试
    void handleStateMachine_LoadR(); // 处理线性调节率测试状态一次

    void startTestSequence_Input_A();
    void handleStateMachine_Input_A();
signals:
    void end_LR(); // 提示线性调节率测试已完成
    void end_LoadR(); // 提示负载调节率测试已完成
    void end_Input_A();

public:
    // 设备对象
    Device *inputDevice;
    Device *loadDevice;
    // 电源模块对象
    PM *powerModule;
    // 测试状态
    TestState_LineRegulation stateLR;
    TestState_LoadRegulation stateLoadR;
    TestState_input_A stateInput_A;
    QTimer *stateTimer;
};

#endif // TESTPROJECT_H
