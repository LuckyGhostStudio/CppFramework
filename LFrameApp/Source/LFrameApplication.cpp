#include <LFrame.h>
#include <LFrame/Core/EntryPoint.h>

class LFrameApplication : public LFrame::Application
{
public:
    LFrameApplication()
        : LFrame::Application()
    {

    }
};

LFrame::Application* LFrame::CreateApplication()
{
    return new LFrameApplication();
}