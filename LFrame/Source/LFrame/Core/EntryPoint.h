#pragma once

extern LFrame::Application* LFrame::CreateApplication();

int main(int argc, char** argv)
{
    LFrame::Log::Init();    // ��ʼ����־ϵͳ

    LF_CORE_INFO("Initialized Log.");
    LF_CORE_INFO("Hello LFrame.");
    
    LFrame::Application* app = LFrame::CreateApplication(); // ���� Application

    app->Run();

    delete app;
}