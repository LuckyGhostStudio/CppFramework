#pragma once

#include "LFrame/Core/Layer.h"
#include "LFrame/Core/Events/ApplicationEvent.h"
#include "LFrame/Core/Events/KeyEvent.h"
#include "LFrame/Core/Events/MouseEvent.h"

namespace LFrame
{
    /// <summary>
    /// ImGui 层
    /// </summary>
    class ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        /// <summary>
        /// 将该层添加到层栈时调用
        /// </summary>
        virtual void OnAttach() override;

        /// <summary>
        /// 将该层从层栈移除时调用
        /// </summary>
        virtual void OnDetach() override;

        /// <summary>
        /// 事件回调函数
        /// </summary>
        /// <param name="event">事件</param>
        virtual void OnEvent(Event& event) override;

        void Begin();

        void End();

        /// <summary>
        /// 阻止事件：阻止接收事件
        /// </summary>
        /// <param name="block">是否阻止</param>
        void BlockEvents(bool block) { m_BlockEvents = block; }

        /// <summary>
        /// 设置常规样式（总体样式）
        /// </summary>
        void SetDefaultStyles();
    private:
        bool m_BlockEvents = true;  // 是否阻止接收事件
    };
}