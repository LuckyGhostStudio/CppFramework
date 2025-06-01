#pragma once

#include <memory>

#ifdef LF_DEBUG
    #define LF_ENABLE_ASSERTS
#endif

#ifdef LF_ENABLE_ASSERTS    // ���ö���
    // ���ԣ�xΪ�� ����ʾERROR��־��Ϣ ���жϵ���
    #define LF_ASSERT(x, ...) { if(!(x)) { LF_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
    // ���ԣ�xΪ�� ����ʾERROR��־��Ϣ ���жϵ���
    #define LF_CORE_ASSERT(x, ...) { if(!(x)) { LF_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else   // ���ö���
    #define LF_ASSERT(x, ...)
    #define LF_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)     // 1 ���� x λ

// ���¼����� ���غ�������
#define LF_BIND_EVENT_FUNC(func) [this](auto&&... args) -> decltype(auto) { return this->func(std::forward<decltype(args)>(args)...); }

namespace LFrame
{
    /// <summary>
    /// Ψһָ��
    /// </summary>
    /// <typeparam name="T">����</typeparam>
    template<typename T>
    using Scope = std::unique_ptr<T>;

    /// <summary>
    /// ����Ψһָ��
    /// </summary>
    /// <typeparam name="T">����</typeparam>
    /// <typeparam name="...Args">���������б�</typeparam>
    /// <param name="...args">�����б�</param>
    /// <returns></returns>
    template<typename T, typename ... Args>
    constexpr Scope<T> CreateScope(Args&& ... args)
    {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    /// <summary>
    /// ����ָ��
    /// </summary>
    /// <typeparam name="T">����</typeparam>
    template<typename T>
    using Ref = std::shared_ptr<T>;

    /// <summary>
    /// ��������ָ��
    /// </summary>
    /// <typeparam name="T">����</typeparam>
    /// <typeparam name="...Args">���������б�</typeparam>
    /// <param name="...args">�����б�</param>
    /// <returns></returns>
    template<typename T, typename ... Args>
    constexpr Ref<T> CreateRef(Args&& ... args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }
}