
#include <atomic>
#include <string>
#include <iostream>
#include <algorithm>
#include <thread>
#include <vector>
#include <chrono>

std::atomic_bool gs_terminating = false;
std::atomic_int gs_wait_group = 0;


void logic_thread() {
    while (!gs_terminating) {
        // do work
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    std::cout << "logic thread terminating..." << std::endl;

    // terminating
    bool logic_queue_empty = true;
    while (!logic_queue_empty) {
        // logic queue pop
        // work
    }

    --gs_wait_group;
    std::cout << "logic thread terminated" << std::endl;
}

int main() {
    gs_terminating = false;

    std::thread t1(logic_thread), t2(logic_thread);
    t1.detach();
    t2.detach();

    std::string input;
    while (true) {
        std::cin >> input;
        std::for_each(input.begin(), input.end(), [](char& c) { c = std::tolower(c); });
        if (input == "e" || input == "exit" || input == "q" || input == "quit") {
            gs_wait_group = 2;
            gs_terminating = true;
            break;
        }
    }

    while (gs_wait_group > 0) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::cout << "main thread terminated safely" << std::endl;

    return 0;
}
