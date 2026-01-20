#pragma once

#include <LFrame.h>

#include "EditorDockSpace.h"
#include "LFrame/Editor/PanelManager.h"

namespace LFrame
{
    class EditorLayer : public Layer
    {
    public:
        EditorLayer();

        virtual ~EditorLayer() override = default;

        virtual void OnAttach() override;

        virtual void OnDetach() override;

        virtual void OnUpdate() override;

        virtual void OnImGuiRender() override;

        virtual void OnEvent(Event& event) override;

        void UI_DrawMenuBar();
    private:
        EditorDockSpace m_EditorDockSpace;  // Í£¿¿¿Õ¼ä

        Scope<PanelManager> m_PanelManager; // ±à¼­Æ÷Ãæ°å¹ÜÀíÆ÷
    };
}