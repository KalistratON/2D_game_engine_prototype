#include "Shader.h"
#include "Sprite.h"
#include "Texture.h"
#include "RenderManager.h"
#include "Window.h"
#include "GameObject.h"
#include "CharacterController.h"
/*
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw_gl3.h"
*/

#include <stdio.h>
#include <vector>;
#include <unordered_map>;

using namespace std;
using namespace engine;

int main ()
{
    Window aWindow (1440, 1080);

    Shader aShader (
        std::vector <GLint>       {GL_VERTEX_SHADER, GL_FRAGMENT_SHADER},
        std::vector <const char*> {"../../resources/protogonist.vert", "../../resources/protogonist.frag"});

    unordered_map <string, Texture> aTextures;
    aTextures.emplace (std::make_pair ("background",     Texture())); aTextures.at("background").create (("F:\\PetProjects\\game_project\\resources\\textures\\background.png"));
    aTextures.emplace (std::make_pair ("main_character", Texture())); aTextures.at("main_character").create (("F:\\PetProjects\\game_project\\resources\\textures\\main_character.png"));
    aTextures.emplace (std::make_pair ("box",            Texture())); aTextures.at("box").create ("F:\\PetProjects\\game_project\\resources\\textures\\box.png");
    aTextures.emplace (std::make_pair ("cow",            Texture())); aTextures.at("cow").create ("F:\\PetProjects\\game_project\\resources\\textures\\cow.png");

    unordered_map <string, Sprite> aSprites;
    aSprites.emplace (std::make_pair ("main_character", Sprite (aTextures.at("main_character"), GL_DYNAMIC_DRAW))); aSprites.at ("main_character").setScale (0.2, 0.2); aSprites.at ("main_character").setTranslation (0.2, -0.8);
    aSprites.emplace (std::make_pair ("background",     Sprite (aTextures.at("background"),     GL_STATIC_DRAW ))); aSprites.at ("background").setScale (3, 3);
    aSprites.emplace (std::make_pair ("box",            Sprite (aTextures.at("box"),            GL_STATIC_DRAW )));
    aSprites.emplace (std::make_pair ("cow",            Sprite (aTextures.at("cow"),            GL_STATIC_DRAW )));

    unordered_map <string, GameObject> aGameObjects;
    aGameObjects.emplace (std::make_pair ("main_character", GameObject (aShader, aSprites.at("main_character"))));
    aGameObjects.emplace (std::make_pair ("background",     GameObject (aShader, aSprites.at("background"))));
    aGameObjects.emplace (std::make_pair ("box",            GameObject (aShader, aSprites.at("box"))));
    aGameObjects.emplace (std::make_pair ("cow",            GameObject (aShader, aSprites.at("cow"))));

    CharacterController aCharacterController (aGameObjects.at ("main_character"), {7, 2});

    /*auto imgui = ImGui::CreateContext();
    ImGui_ImplGlfwGL3_Init (aWindow.data(), true);
    ImGui::StyleColorsDark();

    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    */
    RenderManager aRenderManager;
    glfwSetTime (0.0f);
    while (!aWindow.shouldClose())
    {
        // --------------------------------------------------
        aRenderManager.clear ( { 0.0f, 0.5f, 0.5f, 1.0f } );
        
        //ImGui_ImplGlfwGL3_NewFrame();
        
        float anInterval = glfwGetTime();
        // --------------------------------------------------
        // Start render

        aCharacterController.update (aWindow.data(), anInterval);

        aRenderManager.draw (aGameObjects.at ("background"));
        aRenderManager.draw (aGameObjects.at ("main_character"));

        /*
        {
            static float f = 0.0f;
            static int counter = 0;
            ImGui::Text("Hello, world!");                           // Display some text (you can use a format string too)
            ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f    
            ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color
        }

        if (show_another_window)
        {
            ImGui::Begin("Another Window", &show_another_window);
            ImGui::Text("Hello from another window!");
            if (ImGui::Button("Close Me"))
                show_another_window = false;
            ImGui::End();
        }

        // 3. Show the ImGui demo window. Most of the sample code is in ImGui::ShowDemoWindow(). Read its code to learn more about Dear ImGui!
        if (show_demo_window)
        {
            ImGui::SetNextWindowPos(ImVec2(650, 20), ImGuiCond_FirstUseEver); // Normally user code doesn't need/want to call this because positions are saved in .ini file anyway. Here we just want to make the demo initial state a bit more friendly!
            ImGui::ShowDemoWindow(&show_demo_window);
        }

        // End render
        // --------------------------------------------------
        ImGui::Render();
        ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
        */
        glfwSetTime (0.0f);
        aWindow.swapBuffers();
        // --------------------------------------------------
        
    }
    //ImGui_ImplGlfwGL3_Shutdown();
    //ImGui::DestroyContext();
    return 0;
}