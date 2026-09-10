#pragma once

#include <memory>
#include "spdlog/spdlog.h"

namespace TGL::LOG
{
    
    class logger
    {
    public:
        static void init();

        inline static std::shared_ptr<spdlog::logger>& get_core_logger()
        {
            return m_core_logger;
        }

        inline static std::shared_ptr<spdlog::logger>& get_client_logger()
        {
            return m_client_logger;
        }

    private:
        static std::shared_ptr<spdlog::logger> m_core_logger;
        static std::shared_ptr<spdlog::logger> m_client_logger;

    };
    
}

// Engine Log
#define TGL_CORE_TRACE(...) ::TGL::LOG::logger::get_core_logger()->trace(__VA_ARGS__)
#define TGL_CORE_INFO(...)  ::TGL::LOG::logger::get_core_logger()->info(__VA_ARGS__)
#define TGL_CORE_WARN(...)  ::TGL::LOG::logger::get_core_logger()->warn(__VA_ARGS__)
#define TGL_CORE_ERROR(...) ::TGL::LOG::logger::get_core_logger()->error(__VA_ARGS__)
// Client Log
#define TGL_TRACE(...)      ::TGL::LOG::logger::get_client_logger()->trace(__VA_ARGS__)
#define TGL_INFO(...)       ::TGL::LOG::logger::get_client_logger()->info(__VA_ARGS__)
#define TGL_WARN(...)       ::TGL::LOG::logger::get_client_logger()->warn(__VA_ARGS__)
#define TGL_ERROR(...)      ::TGL::LOG::logger::get_client_logger()->error(__VA_ARGS__)
