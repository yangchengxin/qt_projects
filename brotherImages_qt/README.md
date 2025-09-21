# 📱 Calculator_Qt

一个使用 Qt Widgets 构建的简单四则运算器，支持加减乘除功能，界面简洁，跨平台可运行。

---

## 🧰 项目特性

- 使用 Qt Widgets 构建 UI
- 支持基本的四则运算（加、减、乘、除）
- 输入两个数字并选择运算符即可计算结果
- 使用 CMake 构建，兼容 Qt5 和 Qt6
- 可在 Windows 上打包为独立可执行文件

---

## 📦 环境要求

- Qt 5.15+ 或 Qt 6.5.3
- CMake 3.26+
- C++17 编译器（推荐 MinGW 或 MSVC）
- Qt Creator（推荐）

---

## 🚀 构建方式（CMake）

```bash
git clone https://github.com/yangchengxin/Qt_study.git
cd calculator_qt
mkdir build && cd build
cmake ..
cmake --build .
