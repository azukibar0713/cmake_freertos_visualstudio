#include "test_sample1.h"

#include <cstdio>
#include <thread>
#include <cstdio>
#include <cstdint>
#include "gtest/gtest.h"

extern "C"
{
#include "test_freertos.h"
}

TEST(FactorialTest, HandlesZeroInput) {
    EXPECT_EQ(1, 1);
}
TEST(FactorialTest, Thread) {
    EXPECT_EQ(drive_freertos(), 0);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    int ret =  RUN_ALL_TESTS();
    return ret;
}

#if 1


uint32_t end_flag_;
uint32_t msg_;

void ThreadA();
void ThreadB();

int TestDriver()
{
    msg_ = 0;
    end_flag_ = 1;

    std::thread th_a(ThreadA);
    std::thread th_b(ThreadB);

    th_a.join();
    th_b.join();

    return 0;
}

void ThreadA()
{
    int32_t input = 0;
    while (end_flag_) {
        printf("��������͂��Ă�������\n");
        printf("0...�X���b�hB�Ƀ��b�Z�[�W�𑗐M���܂�\n");
        printf("1...�v���Z�X���I�����܂�\n");
        scanf("%d", &input);

        switch (input) {
        case 0:
            msg_ = 1;
            break;
        case 1:
            end_flag_ = 0;
            break;
        default:
            printf("�O���P����͂��Ă�������\n");
            break;
        }
    }
    printf("�X���b�hA�I��\n");
}

void ThreadB()
{
    while (end_flag_) {
        if (msg_) {
            printf("�X���b�hA���烁�b�Z�[�W����M���܂���\n");
            msg_ = 0;
        }
    }
    printf("�X���b�hB�I��\n");
}





#endif


