#include <LFrame.h>
#include <LFrame/Core/EntryPoint.h>

#include "EditorLayer.h"

class LFrameApplication : public LFrame::Application
{
public:
    LFrameApplication()
        : LFrame::Application()
    {
        PushLayer(new LFrame::EditorLayer());
    }
};

LFrame::Application* LFrame::CreateApplication()
{
    return new LFrameApplication();
}