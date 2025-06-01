#pragma once

extern LFrame::Application* LFrame::CreateApplication();

int main(int argc, char** argv)
{
    LFrame::Application* app = LFrame::CreateApplication(); // ´´½¨ Application

    app->Run();

    delete app;
}