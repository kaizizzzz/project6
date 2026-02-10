#include "testproject.h"
#include "QDebug"

#include <QWidget>

TestProject::TestProject(QObject *parent)
    :QObject(parent)
{

}

TestProject::TestProject(QObject *parent, Device *inputDe, Device *loadDe, PM *pm)
    :QObject(parent)
    ,inputDevice(inputDe)
    ,loadDevice(loadDe)
    ,powerModule(pm)
{
    stateTimer = new QTimer(this);
}

TestProject::~TestProject()
{

}

void TestProject::startTestSequence_LR()
{
    // 先断开计时器的所有连接, 只连接需要当前测试项
    disconnect(stateTimer, nullptr, nullptr, nullptr);
    connect(stateTimer, &QTimer::timeout,
            this, &TestProject::handleStateMachine_LR);
    stateLR = TestState_LineRegulation::State_getContrl;
    // 开始测试的第一步
    handleStateMachine_LR();
}

void TestProject::handleStateMachine_LR()
{
    switch (stateLR) {
    case TestState_LineRegulation::State_getContrl:
        inputDevice->sendCommand("SYSTem:REMote");
        loadDevice->sendCommand("SYSTem:REMote");
        stateLR = TestState_LineRegulation::State_setMinInputV;
        stateTimer->start(200);
        break;
    case TestState_LineRegulation::State_setMinInputV:
        inputDevice->sendCommand(QString("VOLT %1").arg(powerModule->inputV_min));
        stateLR = TestState_LineRegulation::State_turnOnInput;
        stateTimer->start(200);
        break;
    case TestState_LineRegulation::State_turnOnInput:
        inputDevice->sendCommand("OUTP ON");
        stateLR = TestState_LineRegulation::State_setMaxLoad;
        stateTimer->start(1000); // 添加输入电压稍微久点
        break;
    case TestState_LineRegulation::State_setMaxLoad:
        loadDevice->sendCommand(QString("CURR %1").arg(powerModule->load_max));
        stateLR = TestState_LineRegulation::State_turnOnOutput;
        stateTimer->start(200);
        break;
    case TestState_LineRegulation::State_turnOnOutput:
        loadDevice->sendCommand("INP ON");
        stateLR = TestState_LineRegulation::State_getOutputV_min;
        stateTimer->start(1000); // 加上负载变化需要较长时间
        break;
    case TestState_LineRegulation::State_getOutputV_min:
        loadDevice->sendCommand("MEAS:VOLT?");
        if( loadDevice->serial->waitForReadyRead(5000) ){
            powerModule->outputV_minInputV_maxLoad = loadDevice->read();
            qDebug() << "最小电压满载，输出电压:" << powerModule->outputV_minInputV_maxLoad;
        }
        stateLR = TestState_LineRegulation::State_setMaxInputV;
        stateTimer->start(200);
        break;
    case TestState_LineRegulation::State_setMaxInputV:
        inputDevice->sendCommand(QString("VOLT %1").arg(powerModule->inputV_max));
        stateLR = TestState_LineRegulation::State_getOutputV_max;
        stateTimer->start(200);
    case TestState_LineRegulation::State_getOutputV_max:
        loadDevice->sendCommand("MEAS:VOLT?");
        if( loadDevice->serial->waitForReadyRead(5000) ){
            powerModule->outputV_maxInputV_maxLoad = loadDevice->read();
            qDebug() << "最大电压满载，输出电压:" << powerModule->outputV_maxInputV_maxLoad;
        }
        stateLR = TestState_LineRegulation::State_turnDownOutput;
        stateTimer->start(200);
        break;
    case TestState_LineRegulation::State_turnDownOutput:
        loadDevice->sendCommand("INP OFF");
        stateLR = TestState_LineRegulation::State_getContrl; // 回到测试起点
        emit end_LR();
        stateTimer->stop();
        break;
    default:
        break;
    }
}

void TestProject::startTestSequence_LoadR()
{
    // 先断开计时器的所有连接, 只连接需要当前测试项
    disconnect(stateTimer, nullptr, nullptr, nullptr);
    connect(stateTimer, &QTimer::timeout,
            this, &TestProject::handleStateMachine_LoadR);
    stateLoadR = TestState_LoadRegulation::State_getContrl;
    // 开始测试的第一步
    handleStateMachine_LoadR();
}

void TestProject::handleStateMachine_LoadR()
{
    switch (stateLoadR) {
    case TestState_LoadRegulation::State_getContrl:
        inputDevice->sendCommand("SYSTem:REMote");
        loadDevice->sendCommand("SYSTem:REMote");
        stateLoadR = TestState_LoadRegulation::State_setStandardInputV;
        stateTimer->start(200);
        break;
    case TestState_LoadRegulation::State_setStandardInputV:
        inputDevice->sendCommand(QString("VOLT %1").arg(powerModule->inputV_standard));
        stateLoadR = TestState_LoadRegulation::State_turnOnInput;
        stateTimer->start(200);
        break;
    case TestState_LoadRegulation::State_turnOnInput:
        inputDevice->sendCommand("OUTP ON"); // 打开输入
        stateLoadR = TestState_LoadRegulation::State_setMinLoad;
        stateTimer->start(1000);
        break;
    case TestState_LoadRegulation::State_setMinLoad:
        loadDevice->sendCommand(QString("CURR %1").arg(powerModule->load_min));
        stateLoadR = TestState_LoadRegulation::State_turnOnOutput;
        stateTimer->start(200);
        break;
    case TestState_LoadRegulation::State_turnOnOutput:
        loadDevice->sendCommand("INP ON");
        stateLoadR = TestState_LoadRegulation::State_getOutputV_min;
        stateTimer->start(1000); // 加上负载
        break;
    case TestState_LoadRegulation::State_getOutputV_min:
        loadDevice->sendCommand("MEAS:VOLT?");
        if( loadDevice->serial->waitForReadyRead(5000) ){
            powerModule->outputV_staInputV_minload = loadDevice->read();
            //qDebug() << "额定电压电压低载，输出电压:" << powerModule->outputV_staInputV_minload;
        }
        stateLoadR = TestState_LoadRegulation::State_setMaxLoad;
        stateTimer->start(200);
        break;
    case TestState_LoadRegulation::State_setMaxLoad:
        loadDevice->sendCommand(QString("CURR %1").arg(powerModule->load_max));
        stateLoadR = TestState_LoadRegulation::State_getOutputV_max;
        stateTimer->start(1000); // 负载变化需要时间稍长一点
        break;
    case TestState_LoadRegulation::State_getOutputV_max:
        loadDevice->sendCommand("MEAS:VOLT?");
        if( loadDevice->serial->waitForReadyRead(5000) ){
            powerModule->outputV_staInputV_maxload = loadDevice->read();
            //qDebug() << "额定电压电压满载，输出电压：" << powerModule->outputV_staInputV_maxload;
        }
        stateLoadR = TestState_LoadRegulation::State_getinputA_staInputV_maxload;
        stateTimer->start(200);
        break;
    case TestState_LoadRegulation::State_getinputA_staInputV_maxload:
        inputDevice->sendCommand("MEAS:CURR?");
        if( inputDevice->serial->waitForReadyRead(5000) ){
            powerModule->inputA_staInputV_maxload = inputDevice->read();
            qDebug() << "powerModule->inputA_staInputV_maxload=" << powerModule->inputA_staInputV_maxload;
        }
        stateLoadR = TestState_LoadRegulation::State_getActV;
        stateTimer->start(200);
        break;
    case TestState_LoadRegulation::State_getActV:
        inputDevice->sendCommand("MEAS:VOLT?");
        if( inputDevice->serial->waitForReadyRead(5000) ){
            powerModule->input_actV = inputDevice->read();
            qDebug() << "powerModule->input_actV=" << powerModule->input_actV;
        }
        stateLoadR = TestState_LoadRegulation::State_turnDownOutput;
        stateTimer->start(200);
        break;
    case TestState_LoadRegulation::State_turnDownOutput:
        loadDevice->sendCommand("INP OFF");
        stateLoadR = TestState_LoadRegulation::State_getContrl; //回到测试起点
        emit end_LoadR();
        stateTimer->stop();
    default:
        break;
    }
}

void TestProject::startTestSequence_Input_A()
{
    // 先断开计时器的所有连接, 只连接需要当前测试项
    disconnect(stateTimer, nullptr, nullptr, nullptr);
    connect(stateTimer, &QTimer::timeout,
            this, &TestProject::handleStateMachine_Input_A);
    stateInput_A = TestState_input_A::State_getContrl;
    // 开始测试的第一步
    handleStateMachine_Input_A();
}

void TestProject::handleStateMachine_Input_A()
{
    switch (stateInput_A) {
    case TestState_input_A::State_getContrl:
        inputDevice->sendCommand("SYSTem:REMote");
        stateInput_A = TestState_input_A::State_setStandardInputV;
        stateTimer->start(200);
        break;
    case TestState_input_A::State_setStandardInputV:
        inputDevice->sendCommand(QString("VOLT %1").arg(powerModule->inputV_standard));
        stateInput_A = TestState_input_A::State_turnOnInput;
        stateTimer->start(200);
        break;
    case TestState_input_A::State_turnOnInput:
        inputDevice->sendCommand("OUTP ON");
        stateInput_A = TestState_input_A::State_getInput_A;
        stateTimer->start(1000);// 上电压时间稍长一点
        break;
    case TestState_input_A::State_getInput_A:
        inputDevice->sendCommand("MEAS:CURR?");
        if( inputDevice->serial->waitForReadyRead(5000) ){
            powerModule->input_A = inputDevice->read();
        }
        stateInput_A = TestState_input_A::State_getContrl; //回到测试开始
        emit end_Input_A();
        stateTimer->stop();
    default:
        break;
    }
}
