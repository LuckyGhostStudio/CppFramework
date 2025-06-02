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

    void Application::OnEvent(Event& event)
    {
        EventDispatcher dispatcher(event);  // �¼�������
        dispatcher.Dispatch<WindowCloseEvent>(LF_BIND_EVENT_FUNC(Application::OnWindowClose));      // ���ڹر��¼�
        dispatcher.Dispatch<WindowResizeEvent>(LF_BIND_EVENT_FUNC(Application::OnWindowResize));    // ���ڴ�С�ı��¼�

        // ��������±�����ջ
        for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
        {
            if (event.m_Handled)
            {
                break;  // �¼��Ѵ���
            }
            (*--it)->OnEvent(event);    // ���ȡ�������¼�
        }
    }

    void Application::Run()
    {
        while (m_Running)
        {
            // ����δ��С��
            if (!m_Minimized)
            {
                // ���²�ջ�����в�
                for (Layer* layer : m_LayerStack)
                {
                    layer->OnUpdate();
                }
            }

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