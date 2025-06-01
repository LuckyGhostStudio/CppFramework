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
    /// ���� App���� LFrameApplication �ж���
    /// </summary>
    /// <returns></returns>
    Application* CreateApplication();
}