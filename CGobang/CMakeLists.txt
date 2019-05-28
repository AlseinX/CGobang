# CMakeList.txt: CGobang 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

# 将源代码添加到此项目的可执行文件。
add_executable (CGobang "main.c" "main.h" "color.c" "color.h" "chessboard.c" "chessboard.h")
target_link_libraries(CGobang libpanelw.a libncursesw.a)

# TODO: 如有需要，请添加测试并安装目标。
