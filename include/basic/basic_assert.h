#pragma once

#include "basic_log.h"

#include <filesystem>

#define EB_ASSERT_IMPL(_type, _condition, _msgFmt, ...) \
    if (!(_condition)) {                                \
        EB_##_type##_ERROR(_msgFmt, __VA_ARGS__);       \
        __debugbreak();                                 \
    }

#define EB_ASSERT_WITH_MSG(_type, _condition, ...)      \
    EB_ASSERT_IMPL(_type, _condition, "Assertion failed: %s", __VA_ARGS__)
#define EB_ASSERT_WITHOUT_MSG(_type, _condition)        \
    EB_ASSERT_IMPL(_type, _condition, "Assertion '%s' failed at file(%s):line(%d)", #_condition, \
                   std::filesystem::path(__FILE__).filename().string().c_str(), __LINE__)

#define EB_ASSERT_EXPANE_MACRO(_macro) _macro
#define EB_ASSERT_GET_MACRO_NAME(_arg1, _arg2, _macro, ...) _macro
#define EB_ASSERT_GET_MARCO(...)                        \
    EB_ASSERT_EXPANE_MACRO(EB_ASSERT_GET_MACRO_NAME(__VA_ARGS__, EB_ASSERT_WITH_MSG, EB_ASSERT_WITHOUT_MSG))

#define EB_CORE_ASSERT(...)                             \
    EB_ASSERT_EXPANE_MACRO(EB_ASSERT_GET_MARCO(__VA_ARGS__)(CORE, __VA_ARGS__))
#define EB_CLIENT_ASSERT(...)                           \
    EB_ASSERT_EXPANE_MACRO(EB_ASSERT_GET_MARCO(__VA_ARGS__)(CLIENT, __VA_ARGS__))
#define EB_ASSERT(...)                                  \
    EB_ASSERT_EXPANE_MACRO(EB_CORE_ASSERT(__VA_ARGS__))