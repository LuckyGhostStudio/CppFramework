#include "Application.h"

namespace LFrame
{
    Application* Application::s_Instance = nullptr;

    Application::Application()
    {
        LF_CORE_ASSERT(!s_Instance, "Application ÒÑ´æÔÚ!");

        s_Instance = this;
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        while (m_Running)
        {

        }
    }

    void Application::Close()
    {
        m_Running = false;
    }
}