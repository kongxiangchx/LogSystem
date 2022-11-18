#include <iostream>
#include <thread>
#include "../chx/log.h"
#include "../chx/util.h"

#include <sstream>
#include <fstream>

int main(int argc, char** argv) {
    chx::Logger::ptr logger(new chx::Logger);
    logger->addAppender(chx::LogAppender::ptr(new chx::StdoutLogAppender));

    chx::FileLogAppender::ptr file_appender(new chx::FileLogAppender("./log.txt"));
    
    chx::LogFormatter::ptr fmt(new chx::LogFormatter("%d%T%p%T%m%n"));
    file_appender->setFormatter(fmt);
    file_appender->setLevel(chx::LogLevel::ERROR);

    logger->addAppender(file_appender);

    //chx::LogEvent::ptr event(new chx::LogEvent(__FILE__, __LINE__, 0, chx::GetThreadId(), chx::GetFiberId(), time(0)));
    //logger->log(chx::LogLevel::DEBUG, event);
    //std::cout << "hello chx log" << std::endl;

    CHX_LOG_INFO(logger) << "test macro";
    CHX_LOG_ERROR(logger) << "test macro error";

    CHX_LOG_FMT_ERROR(logger, "test macro fmt error %s", "aa");

    auto l = chx::LoggerMgr::GetInstance()->getLogger("xx");
    CHX_LOG_INFO(l) << "xxx";

    std::stringstream m_ss;
    m_ss << "asas" << std::endl;
    return 0;
}
