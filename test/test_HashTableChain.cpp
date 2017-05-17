#include <gtest/gtest.h>
#include "include\HashTableChain.h"


TEST(HashTableChain_Test, Can_Not_Create_Table_Witn_Zero_Size) {
    EXPECT_ANY_THROW(HashTableChain<int>(0));
}


TEST(HashTableChain_Test, Can_Get_Size) {
    HashTableChain<int> Table;
    EXPECT_EQ(Table.GetSize(), 0);
}

TEST(HashTableChain_Test, Can_Check_If_Contains_1) {
    HashTableChain<int> Table;
    EXPECT_EQ(Table.ContainsKey(1), false);
}

TEST(HashTableChain_Test, Can_Check_If_Contains_2) {
    HashTableChain<int> Table;
    Table.Insert(0, 0);
    Table.Insert(1, 1);
    EXPECT_EQ(Table.ContainsKey(1), true);
}

TEST(HashTableChain_Test, Can_Insert_Value) {
    HashTableChain<int> Table;
    Table.Insert(0, 0);
    EXPECT_EQ(Table.GetSize(), 1);
}

TEST(HashTableChain_Test, Can_Delete_Value) {
    HashTableChain<int> Table;
    Table.Insert(0, 0);
    Table.Insert(1, 1);
    Table.Delete(1);
    Table.Delete(0);
    EXPECT_EQ(Table.GetSize(), 0);
}