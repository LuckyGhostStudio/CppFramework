#pragma once

#include "LFrame/Core/Layer.h"
#include "LFrame/Core/Events/ApplicationEvent.h"
#include "LFrame/Core/Events/KeyEvent.h"
#include "LFrame/Core/Events/MouseEvent.h"

namespace LFrame
{
    /// <summary>
    /// ImGui ��
    /// </summary>
    class ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        /// <summary>
        /// ���ò���ӵ���ջʱ����
        /// </summary>
        virtual void OnAttach() override;

        /// <summary>
        /// ���ò�Ӳ�ջ�Ƴ�ʱ����
        /// </summary>
        virtual void OnDetach() override;

        /// <summary>
        /// �¼��ص�����
        /// </summary>
        /// <param name="event">�¼�</param>
        virtual void OnEvent(Event& event) override;

        void Begin();

        void End();

        /// <summary>
        /// ��ֹ�¼�����ֹ�����¼�
        /// </summary>
        /// <param name="block">�Ƿ���ֹ</param>
        void BlockEvents(bool block) { m_BlockEvents = block; }

        /// <summary>
        /// ���ó�����ʽ��������ʽ��
        /// </summary>
        void SetDefaultStyles();
    private:
        bool m_BlockEvents = true;  // �Ƿ���ֹ�����¼�
    };
}