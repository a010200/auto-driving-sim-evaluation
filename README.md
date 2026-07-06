# 基于 C++ 与 Python 的自动驾驶跟车急刹场景仿真与离线评测工具链

## 项目背景

本项目面向自动驾驶仿真测试和路测测试实习场景，使用 C++ 实现简化车辆纵向运动仿真，后续使用 Python 对仿真日志进行离线分析和绘图。

第一阶段只完成最小可运行版本：

- 使用 CMake 管理 C++17 项目
- 创建基础目录结构
- 实现 `Vehicle` 车辆类
- 在 `main.cpp` 中运行一个简单的纵向运动仿真

## 当前运行方法

```bash
mkdir -p build
cd build
cmake ..
cmake --build .
./simulator
```

## 当前项目结构

```text
auto-driving-sim-evaluation/
├── CMakeLists.txt
├── README.md
├── .gitignore
├── include/
│   └── Vehicle.h
├── src/
│   ├── Vehicle.cpp
│   └── main.cpp
├── scripts/
├── data/
├── result/
└── docs/
```

## 后续计划

- 加入 CSV 日志输出
- 加入前车急刹场景
- 加入跟车控制和 TTC 计算
- 使用 Python 绘制速度、加速度、车距和 TTC 曲线
- 检测急刹不舒适片段和风险片段
