#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "include\Record.h"

TEST(Record_Test,
    Can_Create_Int_Record_Without_Parametres) {
    // Arrange
    int key = 0;
    int value = 0;
    //Act
    Record<int> test;
    //Assert
    EXPECT_EQ(key, test.GetKey());
    EXPECT_EQ(value, test.GetValue());
}
TEST(Record_Test,
    Can_Create_String_Record_Without_Parametres) {
    // Arrange
    int key = 0;
    std::string value;
    //Act
    Record<std::string> test;
    //Assert
    EXPECT_EQ(key, test.GetKey());
    EXPECT_EQ(value, test.GetValue());
}
TEST(Record_Test,
    Can_Create_Record_With_Int) {
    // Arrange
    int key = 10;
    int value = 20;
    //Act
    Record<int> test(key,value);
    //Assert
    EXPECT_EQ(key,test.GetKey());
    EXPECT_EQ(value, test.GetValue());
}
TEST(Record_Test,
    Can_Create_Record_With_Int_And_String) {
    // Arrange
    int key = 10;
    std::string value = "20";
    //Act
    Record<std::string> test(key, value);
    //Assert
    EXPECT_EQ(key, test.GetKey());
    EXPECT_EQ(value, test.GetValue());
}


