#include <LFrame.h>
#include <LFrame/Core/EntryPoint.h>

class ExampleLayer : public LFrame::Layer
{
public:
    ExampleLayer() : Layer("Example") {}

    void OnUpdate() override
    {
        LF_INFO("ExampleLayer::OnUpdate");
    }

    void OnEvent(LFrame::Event& event) override
    {
        LF_TRACE("{0}", event.ToString());
    }
};

class LFrameApplication : public LFrame::Application
{
public:
    LFrameApplication()
        : LFrame::Application()
    {
        PushLayer(new ExampleLayer());
    }
};

LFrame::Application* LFrame::CreateApplication()
{
    return new LFrameApplication();
}