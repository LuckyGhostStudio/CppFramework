#pragma once

#include "Base.h"

namespace LFrame
{
    /// <summary>
    /// 应用程序：管理应用程序的入口点和生命周期
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
    /// 创建 App：在 LFrameApplication 中定义
    /// </summary>
    /// <returns></returns>
    Application* CreateApplication();
}