#ifndef PM_H
#define PM_H


// 电源模块类，记录包括被测试的电源的各项信息
class PM
{
public:
    PM();
public:
    // 需要输入的数据
    double channel; // 单路输出还是双路输出 1 单路 2 双路
    double inputV_standard;  // 额定输入电压
    double inputV_min;
    double inputV_max;
    double load_max; // 最大负载值 目前只写电流
    double load_min; // 最小负载值 测试负载调整率的最小值
    double outputV_standard; //额定输出电压

    double mainLoadCondition; // 主路带载值 百分比
    double secondaryMinLoadCondition; // 辅路最小带载值 %
    double secondaryMaxLoadCondition; // 辅路最大带载值 %
    // 测试项目
    // 电压调整率/线性调节率，输入电压在额定范围内变化时，输出段电压变化值与标准输出的电压的比值
    // 电流调整率/负载调节率，输入电压标准值，负载最小到最大时，输出电压变化值与满载输出电压比值
    // 正输出
    double V_regulation_positive; //都是百分率
    double A_regulation_positive;
    // 负输出
    double V_regulation_negative;
    double A_regulation_negative;
    double input_A; // 空载下，输入端电流
    double η; // 效率，满载下输出功率与输入功率比值
    double crossRegulation; // 交叉调整率
    // 测量判据  写入excel的时候判断下
    double lineR;
    double lineR_negative; // 负输出线性调节率判据
    double loadR;
    double loadR_negative; // 负输出负载调节率判据
    double yita; // 效率判据
    double crossR; // 交叉调整率判据


    //////////////////////////////////////////
    // 测量时的中间值
    double outputV_minInputV_maxLoad; // 最小输入电压满载下 的 输出电压
    double outputV_maxInputV_maxLoad; // 最大输入电压满载下 的 输出电压
    double outputV_staInputV_maxload; // 标准输入电压,满载下输出电压
    double outputV_staInputV_minload; // 标准输入电压,低载下输出电压
    double inputA_staInputV_maxload;  // 额定输入电压,满载下，输入的电流，计算效率使用
    double input_actV; // 实际输入电压
        // 交叉调整率
    double outputV_secondaryMinLoad; // 辅路最小负载下，主路输出电压
    double outputV_secondaryMaxLoad; // 辅路最大负载下，主路输出电压
};

#endif // PM_H
