#include "sample_for_gtest.h"

#include <thread>
#include <cstdio>
#include <cstdint>

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
        printf("数字を入力してください\n");
        printf("0...スレッドBにメッセージを送信します\n");
        printf("1...プロセスを終了します\n");
        scanf("%d", &input);

        switch (input) {
        case 0:
            msg_ = 1;
            break;
        case 1:
            end_flag_ = 0;
            break;
        default:
            printf("０か１を入力してください\n");
            break;
        }
    }
    printf("スレッドA終了\n");
}

void ThreadB()
{
    while (end_flag_) {
        if (msg_) {
            printf("スレッドAからメッセージを受信しました\n");
            msg_ = 0;
        }
    }
    printf("スレッドB終了\n");
}



