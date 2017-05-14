#include <gtest/gtest.h>
#include "include\HashTableChain.h"


TEST(HashTableChain_Test, Can_Not_Create_Table_Witn_Zero_Size) {
    EXPECT_ANY_THROW(HashTableChain<int>(0));
}

TEST(HashTableChain_Test, Can_Create_Table_Without_Parametres) {
    HashTableChain<int> test;
    EXPECT_EQ(0, test.GetSize());
}
TEST(HashTableChain_Test, Can_Create_Table_With_Parametres) {
    int size = 32;
    HashTableChain<int> test = HashTableChain<int>(size);
    EXPECT_EQ(0, test.GetSize()); // GetSize() - получить число вставленных элементов(так удобнее, имхо)
}
