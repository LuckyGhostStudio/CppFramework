#pragma once

extern LFrame::Application* LFrame::CreateApplication();

int main(int argc, char** argv)
{
    LFrame::Log::Init();    // 初始化日志系统

    LF_CORE_INFO("Initialized Log.");
    LF_CORE_INFO("Hello LFrame.");
    
    LFrame::Application* app = LFrame::CreateApplication(); // 创建 Application

    app->Run();

    delete app;
}