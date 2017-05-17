#include <gtest/gtest.h>
#include "include\HashTableCuckoo.h"

TEST(HashTableCuckoo_Test, Can_Not_Create_Table_Witn_Zero_Size) {
    EXPECT_ANY_THROW(HashTableCuckoo<int>(0));
}

TEST(HashTableCuckoo_Test, Can_Get_Size) {
    HashTableCuckoo<int> Table;
    EXPECT_EQ(Table.GetSize(), 0);
}

TEST(HashTableCuckoo_Test, Can_Check_If_Contains_1) {
    HashTableCuckoo<int> Table;
    EXPECT_EQ(Table.ContainsKey(1), false);
}

TEST(HashTableCuckoo_Test, Can_Check_If_Contains_2) {
    HashTableCuckoo<int> Table;
    Table.Insert(0, 0);
    Table.Insert(1, 1);
    EXPECT_EQ(Table.ContainsKey(1), true);
}

TEST(HashTableCuckoo_Test, Can_Insert_Value) {
    HashTableCuckoo<int> Table;
    Table.Insert(0, 0);
    EXPECT_EQ(Table.GetSize(), 1);
}

TEST(HashTableCuckoo_Test, Can_Delete_Value) {
    HashTableCuckoo<int> Table;
    Table.Insert(0, 0);
    Table.Insert(1, 1);
    Table.Delete(1);
    Table.Delete(0);
    EXPECT_EQ(Table.GetSize(), 0);
}





