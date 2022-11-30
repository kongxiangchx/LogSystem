#include <iostream>
#include <thread>
#include "chx/log.h"
#include "chx/util.h"
#include "chx/config.h"
#include <yaml-cpp/yaml.h>
#include <sstream>
#include <fstream>
#include <thread>

static chx::Logger::ptr system_log = CHX_LOG_NAME("system");

void fun() {
    while(true) {
        CHX_LOG_INFO(system_log) << "test";
    }
}

int main(int argc, char** argv) {
    YAML::Node root = YAML::LoadFile("/home/chx/workspace/bin/conf/log.yml");
    chx::Config::LoadFromYaml(root);
    
    std::thread thread1(fun);
    std::thread thread2(fun);
    std::thread thread3(fun);
    std::thread thread4(fun);

    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();
    return 0;
}
