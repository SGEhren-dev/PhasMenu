// Generated C++ file by Il2CppInspector - http://www.djkaty.com - https://github.com/djkaty
// Custom injected code entry point

#include "pch-il2cpp.h"
#include "../kiero/kiero.h"
#include "PhasHooks.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <iostream>
#include <d3d11.h>
#include "il2cpp-appdata.h"
#include "helpers.h"
#include "includes.h"

using namespace app;

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

Present oPresent;
HWND window = NULL;
WNDPROC oWndProc;
ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
ID3D11RenderTargetView* mainRenderTargetView;

// Set the name of your log file here
extern const LPCWSTR LOG_FILE = L"il2cpp-log.txt";

/* Controllers and other fields */
GhostAI* gAI = nullptr;                                                                         //Pointer to the ghost
DNAEvidence* dna = nullptr;                                                                     //Pointer to evidence
GameController* gc;                                                                             //Pointer to the GameController
Player_1* p1;                                                                                   //Pointer to the player object
SetupPhaseController* sPC;                                                                      //Pointer to phase controller
MethodInfo* methodI;                                                                            //Pointer to GhostAI method sig
LevelController* levelCont;                                                                     //Pointer to level controller
GhostTraits* gTraits;                                                                           //Pointer to ghost traits
Camera* cam;                                                                                    //Pointer to the camera
GhostActivity* gActivity;                                                                       //Pointer to the GhostActivity
EvidenceController* eController;                                                                //Pointer to the Evidence controller

bool isGameStarted() { return gAI && dna; }                                                     //Check if the game has started
bool isGameController() { return gc; }                                                          //Check if the game controller has been started

void InitImGui() {
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
    ImGui_ImplWin32_Init(window);
    ImGui_ImplDX11_Init(pDevice, pContext);
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
        return true;

    return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

/* Mod activation bools */
bool bSetMaxMoney = false, bSetMaxHoops = false, bGetGhostData = false, bShowGhost = false, bChangeGhostState = false, bShowInGameMenu = false;
//

/* Game hooks go here */
typedef void(__stdcall* oGhostAI)(GhostAI* __this, MethodInfo* method);
typedef void(__stdcall* oDNAEvidence)(DNAEvidence* __this, MethodInfo* method);
typedef void(__stdcall* oGameController)(GameController* __this, MethodInfo* method);
typedef void(__stdcall* oExitLevel)(ExitLevel* __this, MethodInfo* method);
typedef void(__stdcall* oPauseMenuController)(PauseMenuController* __this, MethodInfo* method);
typedef void(__stdcall* oGhostAIA)(GhostAI* __this, bool __hunt, MethodInfo* method);
typedef void(__stdcall* oSetupPhaseController)(SetupPhaseController* __this, MethodInfo* method);
typedef void(__stdcall* oLevelController)(LevelController* __this, MethodInfo* method);
typedef void(__stdcall* oGhostActivity)(GhostActivity* __this, MethodInfo* method);
typedef void(__stdcall* oEvidenceController)(EvidenceController* __this, MethodInfo* method);
typedef float(__stdcall* oGameControllerF)(GameController* __this, MethodInfo* method);


/* Original method declarations */
static oGhostAI oGhostAI_Start = NULL;
static oDNAEvidence oDNAEvidence_Start = NULL;
static oGameController oGameController_Start = NULL;
static oExitLevel oExitLevel_Exit = NULL;
static oPauseMenuController oPauseMenuController_Leave = NULL;
static oLevelController oLevelController_Start = NULL;
static oGhostActivity oGhostActivity_Start = NULL;
static oEvidenceController oEvidenceController_Start = NULL;
static oGameControllerF oGameController_GetAveragePlayerInsanity = NULL;

/* Hooks go here */
void hkGhostAI_Start(GhostAI* __this, MethodInfo* method) {             //Hooks the GhostAI Start
    oGhostAI_Start(__this, method);                                     //Call the original

    if (__this) gAI = __this;                                           //Check if the GhostAI ptr is null
    else gAI = nullptr;

    if (method) methodI = method;                                       //Check if the method ptr is null (not used)
    else method = nullptr;

    gTraits = &__this->fields.ghostInfo->fields.ghostTraits;            //Get the ghost traits
}

void hkDNAEvidence_Start(DNAEvidence* __this, MethodInfo* method) {     //Hooks the DNAEvidence Start
    oDNAEvidence_Start(__this, method);                                 //Call the original
    if (__this) dna = __this;                                           //Check if DNAEvidence is null
    else dna = nullptr;
}

void hkGameController_Start(GameController* __this, MethodInfo* method) {
    oGameController_Start(__this, method);

    if (__this) {
        gc = __this;
        //p1 = __this->fields.myPlayer->fields.player;
        //cam = __this->fields.myPlayer->fields.player->fields.firstPersonController->fields.m_Camera;
    }
    else {
        gc = nullptr;
        p1 = nullptr;
    }
}

void hkExitLevel_Exit(ExitLevel* __this, MethodInfo* method) {
    oExitLevel_Exit(__this, method);

    gAI = nullptr, dna = nullptr, p1 = nullptr, gc = nullptr;
}

void hkPauseMenuController_Leave(PauseMenuController* __this, MethodInfo* method) {
    oPauseMenuController_Leave(__this, method);

    gAI = nullptr, dna = nullptr, p1 = nullptr, gc = nullptr;
}

void hkLevelController_Start(LevelController* __this, MethodInfo* method) {
    oLevelController_Start(__this, method);

    if (__this) levelCont = __this;
    else levelCont = nullptr;
}

void hkGhostActivity_Start(GhostActivity* __this, MethodInfo* method) {
    oGhostActivity_Start(__this, method);

    if (__this) gActivity = __this;
    else gActivity = nullptr;
}

void hkEvidenceController_Start(EvidenceController* __this, MethodInfo* method) {
    oEvidenceController_Start(__this, method);

    if (__this) eController = __this;
    else eController = nullptr;
}

float hkGameController_GetAveragePlayerInsanity(GameController* __this, MethodInfo* method) {
    return oGameController_GetAveragePlayerInsanity(__this, method);
}

bool init = false, show = false;
int tabs = 1;

HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags) {
    if (!init) {
        if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice))) {
            pDevice->GetImmediateContext(&pContext);
            DXGI_SWAP_CHAIN_DESC sd;
            pSwapChain->GetDesc(&sd);
            window = sd.OutputWindow;
            ID3D11Texture2D* pBackBuffer;
            pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
            pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
            pBackBuffer->Release();
            oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);

            if (MH_CreateHook(GhostAI_Start, &hkGhostAI_Start, (void**)&oGhostAI_Start) != MH_OK)
                std::cout << "Failed to hook GhostAI_Start!\n";

            if (MH_CreateHook(DNAEvidence_Start, &hkDNAEvidence_Start, (void**)&oDNAEvidence_Start) != MH_OK)
                std::cout << "Failed to hook DNAEvidence_Start!\n";

            if (MH_CreateHook(GameController_Start, &hkGameController_Start, (void**)&oGameController_Start) != MH_OK)
                std::cout << "Failed to hook GameController_Start!\n";

            if (MH_CreateHook(PauseMenuController_Leave, &hkPauseMenuController_Leave, (void**)&oPauseMenuController_Leave) != MH_OK)
                std::cout << "Failed to hook PauseMenuController_Leave!\n";

            if (MH_CreateHook(ExitLevel_Exit, &hkExitLevel_Exit, (void**)&oExitLevel_Exit) != MH_OK)
                std::cout << "Failed to hook GameController_Start!\n";

            if (MH_CreateHook(LevelController_Start, &hkLevelController_Start, (void**)&oLevelController_Start) != MH_OK)
                std::cout << "Failed to hook LevelController_Start!\n";

            if (MH_CreateHook(GhostActivity_Start, &hkGhostActivity_Start, (void**)&oGhostActivity_Start) != MH_OK)
                std::cout << "Failed to hook GhostActivity_Start!\n";

            if (MH_CreateHook(GameController_GetAveragePlayerInsanity, &hkGameController_GetAveragePlayerInsanity,
                (void**)&oGameController_GetAveragePlayerInsanity) != MH_OK)
                std::cout << "Failed to hook GameController_GetAveragePlayerInsanity!\n";

            if (MH_CreateHook(FuseBox_TurnOff, &hkFuseBox_TurnOff, (void**)&oFuseBox_TurnOff) != MH_OK)
                std::cout << "Failed to hook FuseBox_TurnOff!\n";

            if (MH_CreateHook(Player_1_ChangeSanity, &hkPlayer_1_ChangeSanity, (void**)&oPlayer_1_ChangeSanity) != MH_OK)
                std::cout << "Failed to hook Player_1_ChangeSanity!\n";

            if (MH_CreateHook(FileBasedPrefs_GetInt, &hkFileBasedPrefs_GetInt, (void**)&oFileBasedPrefs_GetInt) != MH_OK)
                std::cout << "Failed to hook FileBasedPrefs_GetInt!\n";

            if (MH_CreateHook(FileBasedPrefs_SetInt, &hkFileBasedPrefs_SetInt, (void**)&oFileBasedPrefs_SetInt) != MH_OK)
                std::cout << "Failed to hook FileBasedPrefs_SetInt!\n";

            if (MH_CreateHook(Car_Start, &hkCar_Start, (void**)&oCar_Start) != MH_OK)
                std::cout << "Failed to hook Car_Start!\n";

            MH_EnableHook(MH_ALL_HOOKS);

            InitImGui();
            init = true;
        }
        else
            return oPresent(pSwapChain, SyncInterval, Flags);
    }

    if (GetAsyncKeyState(VK_F1) & 1) {
        show = !show;
    }

    if (show) {
        ImGui_ImplDX11_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("Galxiez Menu");

        if (ImGui::Button("Lobby", ImVec2(152, 25))) {
            tabs = 1;
        }
        ImGui::SameLine();
        if (ImGui::Button("Ghost", ImVec2(152, 25))) {
            tabs = 2;
        }
        ImGui::SameLine();
        if (ImGui::Button("Game", ImVec2(152, 25))) {
            tabs = 3;
        }
        ImGui::SameLine();
        if (ImGui::Button("Inventory", ImVec2(152, 25))) {
            tabs = 4;
        }

        if (tabs == 1) {            /* Lobby Modifications */
            ImGui::Checkbox("Unlimited Money",  &checks[PMONEY]);
            ImGui::Checkbox("Max Hoops",        &checks[PHOOPS]);
            ImGui::Checkbox("Max Level",        &checks[PLEVEL]);
            ImGui::Checkbox("Max Experience",   &checks[PEXP]);
            ImGui::Checkbox("Modify Items",     &checks[PITEMS]);
        }
        if (tabs == 2) {            /* Ghost Modifications */

            if (isGameStarted()) {
                if (ImGui::Button("Force Appear"))
                    GhostAI_Appear(gAI, true, nullptr);
                if (ImGui::Button("Force Hunt")) {
                    gAI->fields.canEnterHuntingMode = true;
                    gAI->fields.isHunting = true;
                    //Change state to hunting
                    GhostAI_ChangeState(gAI, GhostAI_States__Enum_hunting, NULL, NULL, nullptr);
                    GhostAI_Hunting(gAI, true, nullptr);
                }
                ImGui::SameLine();
                if (ImGui::Button("Random Event")) {
                    GhostAI_RandomEvent(gAI, nullptr);
                }
                char buffer[10];
                //ImGui::InputText("Event Count (1-5): ", buffer, 10);
                ImGui::SameLine();
                if(ImGui::Button("Execute Events")) {
                   for (int i = 0; i < *(int*)buffer[0]; i++) {
                       GhostAI_RandomEvent(gAI, nullptr);
                   }
                }

                ImGui::Text("Ghost Information");
                if (gTraits) {
                    std::string name = getNameFromString(gTraits->ghostName);
                    std::string rmName = getNameFromString(gAI->fields.ghostInfo->fields.favouriteRoom->fields.roomName);
                    ImGui::Text("Ghost Age: " + gTraits->ghostAge);
                    ImGui::Text("Ghost Name: ");
                    ImGui::SameLine();
                    ImGui::Text(name.c_str());
                    ImGui::Text("Ghost Type: ");
                    ImGui::SameLine();
                    ImGui::Text(getNameFromEnum(gTraits->ghostType).c_str());
                    ImGui::Text("Ghost Room: ");
                    ImGui::SameLine();
                    ImGui::Text(rmName.c_str());
                    (gTraits->isShy) ? ImGui::Text("Ghost isShy: True") : ImGui::Text("Ghost isShy: False");
                    (gAI->fields.canAttack) ? ImGui::Text("Ghost canAttack: True") : ImGui::Text("Ghost canAttack: False");
                    (gAI->fields.canEnterHuntingMode) ? ImGui::Text("Ghost canHunt: True") : ImGui::Text("Ghost canHunt: False");
                }
            }
            else {
                ImGui::Text("Please load into a game to use Ghost Modifications!");
            }
        }
        if (tabs == 3) {            /* Game Modifications */
            if (isGameStarted()) {
                ImGui::Checkbox("Ghost ESP", &checks[GESP]);
                ImGui::SameLine();
                ImGui::Checkbox("Bone ESP", &checks[BESP]);
                ImGui::SameLine();
                ImGui::Checkbox("Ouija ESP", &checks[OESP]);
                ImGui::SameLine();
                ImGui::Checkbox("Player ESP", &checks[PESP]);
                ImGui::SameLine();
                ImGui::Checkbox("Max Sanity", &checks[SANITY_CHECK]);
                char buffer[10];
                ImGui::InputText("Interaction Count (1-5): ", buffer, 10);
                ImGui::SameLine();
                if (ImGui::Button("Interact")) {
                    for (int i = 0; i < *(int*)buffer[0]; i++) {
                        hkGhostActivity_Start(gActivity, nullptr);
                    }
                }
                ImGui::Text("Average Player Sanity: ");
                ImGui::SameLine();
                ImGui::Text(std::to_string(hkGameController_GetAveragePlayerInsanity(gc, nullptr)).c_str());
                if (ImGui::Button("Set max lights")) {
                    levelCont->fields.fuseBox->fields.maxLights = 15;
                }
                if (ImGui::Button("Fuse Box Always On")) {
                    bFuseBoxAlwaysOn = !bFuseBoxAlwaysOn;
                }
                if (ImGui::Button("Trigger Car")) {
                    Car_TurnAlarmOn(carPtr, nullptr);
                }
            }
            else {
                ImGui::Text("Please load into game to use Game Modifications!");
            }
        }
        if (tabs == 4) {
            ImGui::Text("Player Inventory Modifications!");
            ImGui::Text("All of these are experimental! Please do not report the bugs. WE ALREADY KNOW ABOUT THEM");
            ImGui::Checkbox("Max Items", &checks[PMAXITEMS]);
            ImGui::SameLine();
            ImGui::Text("You must buy the item first (doesn't cost you a thing).");
            ImGui::Checkbox("Never lose items", &checks[PLOSEITEMS]);
        }

        if (checks[PMONEY]) {
            //FileBasedPrefs_SetInt(Marshal_PtrToStringAnsi((void*)"PlayersMoney", nullptr), 250000, nullptr);      (Not working due to Anti-Cheat)
        }
        if (checks[PEXP]) {
            //FileBasedPrefs_SetInt(Marshal_PtrToStringAnsi((void*)"myTotalExp", nullptr), 9000, nullptr);          (Not working due to Anti-Cheat)
        }
        if (checks[PHOOPS]) {
            //FileBasedPrefs_SetInt(Marshal_PtrToStringAnsi((void*)"HoopCounter", nullptr), 10000000, nullptr);     (Not working due to Anti-Cheat)
        }
        if (checks[3]) {

        }
        if (checks[GESP]) {               //Ghost ESP
            auto draw = ImGui::GetBackgroundDrawList();
        }
        if (checks[BESP]) {               //Bone ESP
            auto draw = ImGui::GetBackgroundDrawList();
        }
        if (checks[OESP]) {               //Ouija ESP
            auto draw = ImGui::GetBackgroundDrawList();
        }
        if (checks[PESP]) {               //Player ESP
            auto draw = ImGui::GetBackgroundDrawList();
        }
        if (checks[SANITY_CHECK]) {
            isCont = true;
            if (p1) hkPlayer_1_ChangeSanity(p1, 100, nullptr);
        }
        else
            isCont = false;


        ImGui::SameLine();
            
        ImGui::End();

        ImGui::Render();

        pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
        ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
    }

    return oPresent(pSwapChain, SyncInterval, Flags);
}

// Custom injected code entry point
void Run()
{
    // If you would like to write to a log file, specify the name above and use il2cppi_log_write()
    // il2cppi_log_write("Startup");

    // If you would like to output to a new console window, use il2cppi_new_console() to open one and redirect stdout
    il2cppi_new_console();

    // Place your custom code here
    /* Main code for ImGui window here, should be drawn first */
    bool init_hook = false;
    do {
        if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success) {
            kiero::bind(8, (void**)&oPresent, hkPresent);
            init_hook = true;
        }
    } while (!init_hook);
}