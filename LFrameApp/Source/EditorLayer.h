#pragma once

#include <LFrame.h>

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
    };
}