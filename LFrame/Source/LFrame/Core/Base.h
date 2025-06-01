#pragma once

#include <memory>

#ifdef LF_DEBUG
    #define LF_ENABLE_ASSERTS
#endif

#ifdef LF_ENABLE_ASSERTS    // 启用断言
    // 断言：x为假 则显示ERROR日志信息 并中断调试
    #define LF_ASSERT(x, ...) { if(!(x)) { LF_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
    // 断言：x为假 则显示ERROR日志信息 并中断调试
    #define LF_CORE_ASSERT(x, ...) { if(!(x)) { LF_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else   // 禁用断言
    #define LF_ASSERT(x, ...)
    #define LF_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)     // 1 左移 x 位

// 绑定事件函数 返回函数对象
#define LF_BIND_EVENT_FUNC(func) [this](auto&&... args) -> decltype(auto) { return this->func(std::forward<decltype(args)>(args)...); }

namespace LFrame
{
    /// <summary>
    /// 唯一指针
    /// </summary>
    /// <typeparam name="T">类型</typeparam>
    template<typename T>
    using Scope = std::unique_ptr<T>;

    /// <summary>
    /// 创建唯一指针
    /// </summary>
    /// <typeparam name="T">类型</typeparam>
    /// <typeparam name="...Args">参数类型列表</typeparam>
    /// <param name="...args">参数列表</param>
    /// <returns></returns>
    template<typename T, typename ... Args>
    constexpr Scope<T> CreateScope(Args&& ... args)
    {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    /// <summary>
    /// 共享指针
    /// </summary>
    /// <typeparam name="T">类型</typeparam>
    template<typename T>
    using Ref = std::shared_ptr<T>;

    /// <summary>
    /// 创建共享指针
    /// </summary>
    /// <typeparam name="T">类型</typeparam>
    /// <typeparam name="...Args">参数类型列表</typeparam>
    /// <param name="...args">参数列表</param>
    /// <returns></returns>
    template<typename T, typename ... Args>
    constexpr Ref<T> CreateRef(Args&& ... args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }
}