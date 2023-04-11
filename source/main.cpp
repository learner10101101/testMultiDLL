#include <iostream>
#include "addDLL.h"
#include "minusDLL.h"
#include <gtest/gtest.h>
#include <string>
#include <windows.h>

std::string GetModulePath()
{
    char path[MAX_PATH];
    GetModuleFileName(NULL, path, MAX_PATH);
    std::string::size_type pos = std::string(path).find_last_of("\\/");
    return std::string(path).substr(0, pos);
}


TEST(TestCaseName, TestName1) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(TestCaseName, TestName2) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

int main(int argc, char** argv) 
{
    int addResult = add(2,3);
    int minusResult = minus(5,2);
    float minusResult2 = minus(5.5f, 2.2f);
    std::cout << "Hello World" << std::endl;
    std::cout << "add(2,3) == " << addResult << std::endl;
    std::cout << "minus(5,2) == " << minusResult << std::endl;
    std::cout << "minus(5.5f, 2.2f) " << minusResult2 << std::endl;

    std::string modulePath = GetModulePath();
    std::string::size_type pos = modulePath.find("\\bin");
    std::string path = std::string(modulePath).substr(0, pos);

    testing::GTEST_FLAG(output) = std::string("xml:")+ path +"\\testRusultReport\\testRusult.xml";
    testing::InitGoogleTest(&argc, argv);
    int test = RUN_ALL_TESTS();

	  return 0;
}