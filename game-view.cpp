#ifndef VIEW_H
#define VIEW_H 1

#include <iostream>
#include <SDL2/SDL.h>
#include "./imgui/imgui.h"
#include "./imgui/backends/imgui_impl_sdl2.h"
#include "./imgui/backends/imgui_impl_sdlrenderer2.h"
#include "models/game-board.cpp"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

class GameView
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool isInitialized = false;

public:
    GameView() = default;
    ~GameView()
    {
        // cleanup
        if (renderer)
        {
            SDL_DestroyRenderer(renderer);
        }

        if (window)
        {
            SDL_DestroyWindow(window);
        }
        SDL_Quit();
    }

    bool init()
    {
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
        {
            SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
            return -1;
        }

        window = SDL_CreateWindow("SDL2 Demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if (!window)
        {
            SDL_Log("Failed to create window: %s", SDL_GetError());
            return -1;
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        if (!renderer)
        {
            SDL_Log("Failed to create renderer: %s", SDL_GetError());
            SDL_DestroyWindow(window);
            ImGui_ImplSDLRenderer2_Shutdown();
            ImGui_ImplSDL2_Shutdown();
            ImGui::DestroyContext();
            SDL_Quit();
            return -1;
        }

        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
        ImGui_ImplSDLRenderer2_Init(renderer);
        ImGuiIO &io = ImGui::GetIO();
        io.Fonts->AddFontDefault();
        io.Fonts->Build();

        isInitialized = true;

        return 1;
    }

    bool processEvent(SDL_Event *event)
    {
        if (!isInitialized)
        {
            std::cerr << "SdlApp is not initialized. Call init() first before calling processEvent()." << std::endl;
            return -1;
        }
        ImGui_ImplSDL2_ProcessEvent(event);
        return 1;
    }

    bool render(GameBoard *board)
    {
        ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
        if (!isInitialized)
        {
            std::cerr << "SdlApp is not initialized. Call init() first before calling render()." << std::endl;
            return -1;
        }

        ImGui_ImplSDLRenderer2_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        // bool show = true;
        ImGui::ShowDemoWindow();

        // static float f = 0.0f;
        // static int counter = 0;

        // ImGui::Begin("Hello, world!"); // Create a window called "Hello, world!" and append into it.

        // ImGui::Text("This is some useful text."); // Display some text (you can use a format strings too)
        // ImGui::Checkbox("Demo Window", &show);    // Edit bools storing our window open/close state
        // ImGui::Checkbox("Another Window", &show);

        // ImGui::SliderFloat("float", &f, 0.0f, 1.0f);             // Edit 1 float using a slider from 0.0f to 1.0f
        // ImGui::ColorEdit3("clear color", (float *)&clear_color); // Edit 3 floats representing a color

        // if (ImGui::Button("Button")) // Buttons return true when clicked (most widgets return true when edited/activated)
        //     counter++;
        // ImGui::SameLine();
        // ImGui::Text("counter = %d", counter);

        // ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        // ImGui::End();

        ImGui::Render();
        SDL_SetRenderDrawColor(renderer, (Uint8)(clear_color.x * 255), (Uint8)(clear_color.y * 255), (Uint8)(clear_color.z * 255), (Uint8)(clear_color.w * 255));
        SDL_RenderClear(renderer);
        ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());
        SDL_RenderPresent(renderer);

        return 1;
    }
};

#endif