#pragma once

#include "Base.h"

namespace LFrame
{
    /// <summary>
    /// Ӧ�ó��򣺹���Ӧ�ó������ڵ����������
    /// </summary>
    class Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

        void Close();

        static Application& GetInstance() { return *s_Instance; }
    private:
        static Application* s_Instance;

        bool m_Running = true;
    };

    /// <summary>
    /// ���� App���� LFrameApplication �ж���
    /// </summary>
    /// <returns></returns>
    Application* CreateApplication();
}