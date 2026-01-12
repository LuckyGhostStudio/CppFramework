#include "EditorLayer.h"

namespace LFrame
{
    EditorLayer::EditorLayer()
        : Layer("EditorLayer")
    {

    }

    void EditorLayer::OnAttach()
    {
        LF_TRACE("EditorLayer::OnAttach");
    }

    void EditorLayer::OnDetach()
    {
        LF_TRACE("EditorLayer::OnDetach");
    }

    void EditorLayer::OnUpdate()
    {
        
    }

    void EditorLayer::OnImGuiRender()
    {

    }

    void EditorLayer::OnEvent(Event& event)
    {
        //LF_TRACE("{0}", event.ToString());
    }
}
