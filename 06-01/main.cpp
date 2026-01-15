#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

// threadを描画する
void PrintThread(int num)
{
    std::cout << "thread" << num << std::endl;
}

int main() {
    // スレッド1を実行
    std::thread th1(PrintThread, 1);
    th1.join();

    // スレッド2を実行
    std::thread th2(PrintThread, 2);
    th2.join();

    // スレッド3を実行
    std::thread th3(PrintThread, 3);
    th3.join();
	return 0;
}