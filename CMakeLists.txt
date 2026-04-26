# 设置cmake最低标准
CMAKE_MINIMUM_REQUIRED(VERSION 3.8.0)

# 设置工程名称
project(testMultiDLL)

# 设置项目名称变量
set(TARGET "testMultiDLL")

# 设置C++语言标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# 设置输出路径变量
set(TARGET_BIN_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")
set(TARGET_LIB_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/lib")

# 设置文件变量和文件映射
file(GLOB SOURCE "${PROJECT_SOURCE_DIR}/source/*.cpp")
source_group("source" FILES ${SOURCE})# 将源文件映射在名为 "source" 的 Visual Studio 组中。

file(GLOB ADDDLLFILE "${PROJECT_SOURCE_DIR}/mathDll/addDLL.h" "${PROJECT_SOURCE_DIR}/mathDll/addDLL.cpp")
file(GLOB MINUSDLLFILE "${PROJECT_SOURCE_DIR}/mathDll/minusDLL.h" "${PROJECT_SOURCE_DIR}/mathDll/minusDLL.cpp")
set(MATHFILES ${ADDDLLFILE} ${MINUSDLLFILE})
source_group("mathDll" FILES ${MATHFILES})

# 包含头文件目录
include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}/mathDll")
include_directories("${PROJECT_SOURCE_DIR}/dependencies/gtest/include")


# 创建动态库给主项目使用
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)# window系统生成动态库时同时生成lib文件需要该语句设置
add_library(addDLL SHARED "${ADDDLLFILE}")
set_target_properties(addDLL PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${TARGET_LIB_OUTPUT_PATH}")# .lib输出目录设置
set_target_properties(addDLL PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${TARGET_BIN_OUTPUT_PATH}")# .dll和.exe输出目录设置
add_library(minusDLL SHARED "${MINUSDLLFILE}")
set_target_properties(minusDLL PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${TARGET_LIB_OUTPUT_PATH}")
set_target_properties(minusDLL PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${TARGET_BIN_OUTPUT_PATH}")

# 添加预处理宏XXX -DXXX
#add_definitions(-DADDDLL_EXPORTS -DMINUSDLL_EXPORTS)# 所有项目都添加相同的预编译宏，具有全局性
target_compile_definitions(addDLL PRIVATE ADDDLL_EXPORTS)# 给特定项目（PRIVATE）添加指定宏
target_compile_definitions(minusDLL PRIVATE INUSDLL_EXPORTS)

# 包含库文件目录，要在add_executable语句前才会生效
## 包含编译出来的库文件目录（lib输出目录下生成的Debug和Release）
link_directories(${TARGET}  "${PROJECT_SOURCE_DIR}/lib/Debug")
link_directories(${TARGET}  "${PROJECT_SOURCE_DIR}/lib/Release")
link_directories(${TARGET}  "${PROJECT_SOURCE_DIR}/dependencies/gtest/lib/windows/x64/Debug")
link_directories(${TARGET}  "${PROJECT_SOURCE_DIR}/dependencies/gtest/lib/windows/x64/Release")
link_directories(${TARGET}  "${PROJECT_SOURCE_DIR}/dependencies/gtest/lib/windows/x86/Debug")
link_directories(${TARGET}  "${PROJECT_SOURCE_DIR}/dependencies/gtest/lib/windows/x86/Release")


# 输出exe文件
add_executable(${TARGET} ${SOURCE})

# 添加项目的引用依赖，保证编译顺序正确（先编译addDLL minusDLL后再编译${TARGET}）
add_dependencies(${TARGET} addDLL minusDLL)

# 链接库 #给所有配置进行链接库，debug和optimized可以表示所有配置
target_link_libraries(${TARGET} debug addDLL.lib optimized addDLL.lib)
target_link_libraries(${TARGET} debug minusDLL.lib optimized minusDLL.lib)
target_link_libraries(${TARGET} debug gtestd.lib optimized gtest.lib)
target_link_libraries(${TARGET} debug gtestd.lib optimized gtest_maind.lib)

set_target_properties(${TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${TARGET_BIN_OUTPUT_PATH}")# .dll和.exe输出目录设置