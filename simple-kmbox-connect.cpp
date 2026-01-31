#include "kmbox.hpp"
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    KmboxNet kmbox;

    // Example configuration
    std::string ip = "192.168.2.188";
    std::string port = "1234";
    std::string mac = "12344321"; // Example MAC

    std::cout << "Initializing kmbox..." << std::endl;
    int ret = kmbox.Init(ip, port, mac);

    if (ret != SUCCESS) {
        std::cout << "Failed to connect to kmbox. Error code: " << ret << std::endl;
    } else {
        std::cout << "Connected successfully." << std::endl;
    }

    // Example: Move mouse in a square
    std::cout << "Moving mouse..." << std::endl;
    for (int i = 0; i < 4; ++i) {
        kmbox.MouseMove(100, 0);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        kmbox.MouseMove(0, 100);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        kmbox.MouseMove(-100, 0);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        kmbox.MouseMove(0, -100);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    // Example: Click left button
    std::cout << "Clicking left button..." << std::endl;
    kmbox.MouseLeft(1); // Press
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Short delay
    kmbox.MouseLeft(0); // Release

    std::cout << "Done." << std::endl;

    return 0;
}
