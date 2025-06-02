#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

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
        WindowResizeEvent e(1280, 720);

        if (e.IsInCategory(EventCategoryApplication))
        {
            LF_TRACE(e.ToString());
        }

        if (e.IsInCategory(EventCategoryInput))
        {
            LF_TRACE(e.ToString());
        }

        while (m_Running)
        {

        }
    }

    void Application::Close()
    {
        m_Running = false;
    }
}