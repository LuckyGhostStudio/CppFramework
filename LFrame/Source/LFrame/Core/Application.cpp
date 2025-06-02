#include "lpch.h"
#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace LFrame
{
    Application* Application::s_Instance = nullptr;

    Application::Application()
    {
        LF_CORE_ASSERT(!s_Instance, "Application �Ѵ���!");

        s_Instance = this;

        m_Window = Window::Create(WindowProps());                               // ��������
        m_Window->SetEventCallback(LF_BIND_EVENT_FUNC(Application::OnEvent));   // ���ûص�����
    }

    Application::~Application()
    {
    }

    void Application::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);  // �¼�������
        dispatcher.Dispatch<WindowCloseEvent>(LF_BIND_EVENT_FUNC(Application::OnWindowClose));      // ���ڹر��¼�
        dispatcher.Dispatch<WindowResizeEvent>(LF_BIND_EVENT_FUNC(Application::OnWindowResize));    // ���ڴ�С�ı��¼�

        LF_CORE_TRACE("{0}", e.ToString());
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
            m_Window->OnUpdate();           // ���´���
        }
    }

    void Application::Close()
    {
        m_Running = false;
    }

    bool Application::OnWindowClose(WindowCloseEvent& e)
    {
        m_Running = false;  // ��������
        return true;
    }

    bool Application::OnWindowResize(WindowResizeEvent& e)
    {
        if (e.GetWidth() == 0 || e.GetHeight() == 0)
        {
            m_Minimized = true;        // ������С��
            return false;
        }

        m_Minimized = false;

        return false;
    }
}