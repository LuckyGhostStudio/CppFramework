#pragma once

#include "LFrame/Core/Base.h"

namespace LFrame
{
    /// <summary>
    /// ��������
    /// </summary>
    /// <typeparam name="T">����</typeparam>
    template<typename T>
    class Singleton
    {
    public:
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;

        static void Create()
        {
            LF_ASSERT(s_Instance == nullptr);

            if (!s_Instance)
            {
                s_Instance = new T;
            }
        }

        static T* Get()
        {
            LF_ASSERT(s_Instance != nullptr)

            return s_Instance;
        }

        static void Destroy()
        {
            if (s_Instance)
            {
                delete s_Instance;
                s_Instance = nullptr;
            }
        }
    protected:
        Singleton() = default;
        virtual ~Singleton() = default;
    private:
        static T* s_Instance;
    };

    template<typename T>
    T* Singleton<T>::s_Instance = nullptr;
}