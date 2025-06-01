#pragma once

namespace LFrame
{
    class Application
    {
    private:
        static Application* s_Instance;

        bool m_Running = true;
    public:
        Application();

        virtual ~Application();

        void Run();

        void Close();
    public:
        inline static Application& GetInstance() { return *s_Instance; }
    };

    /// <summary>
    /// 创建 App：在 LFrameApplication 中定义
    /// </summary>
    /// <returns></returns>
    Application* CreateApplication();
}