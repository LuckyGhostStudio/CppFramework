#pragma once

#include "LFrame/Core/Editor/EditorPanel.h"

namespace LFrame
{
    class ExamplePanel : public EditorPanel
    {
    public:
        ExamplePanel() = default;
        ~ExamplePanel() = default;

        void OnGUI() override;

        /// <summary>
        /// 事件处理函数
        /// </summary>
        /// <param name="event">事件</param>
        void OnEvent(Event& event) override;
    };
}