#pragma once
#ifndef INCLUDES_H
#define INCLUDES_H

#include <Windows.h>
#include <d3d11.h>
#include <dxgi.h>
#include <map>
#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_dx11.h"
#include "../imgui/imgui_impl_win32.h"
#include "../kiero/minhook/include/MinHook.h"

typedef HRESULT(__stdcall* Present) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
typedef uintptr_t PTR;

std::map<std::string, int> itemMap;

int* getPtrToItemCnt(std::string itemName) { return &itemMap.find(itemName)->second; }
void addItemToMap(std::string itemName, int itemCnt) { itemMap.insert(std::pair<std::string, int>(itemName, itemCnt)); }

std::string gTypes[12] = {
	"Spirit",
	"Wraith",
	"Phantom",
	"Poltergeist",
	"Banshee",
	"Jinn",
	"Mare",
	"Revenant",
	"Shade",
	"Demon",
	"Yurei",
	"Oni"
};

std::string getNameFromString(app::String* string) {
	std::string name;
	for (int i = 0; i < string->fields.m_stringLength; i++)
		name += *((&string->fields.m_firstChar) + i);

	return name;
}

std::string getNameFromEnum(app::GhostTraits_Type__Enum __type) {
	switch (__type) {
	case app::GhostTraits_Type__Enum_none:
		return "none";
		break;
	case app::GhostTraits_Type__Enum_Spirit:
		return "Spirit";
		break;
	case app::GhostTraits_Type__Enum_Wraith:
		return "Wraith";
		break;
	case app::GhostTraits_Type__Enum_Phantom:
		return "Phantom";
		break;
	case app::GhostTraits_Type__Enum_Poltergeist:
		return "Poltergeist";
		break;
	case app::GhostTraits_Type__Enum_Banshee:
		return "Banshee";
		break;
	case app::GhostTraits_Type__Enum_Jinn:
		return "Jinn";
		break;
	case app::GhostTraits_Type__Enum_Mare:
		return "Mare";
		break;
	case app::GhostTraits_Type__Enum_Revenant:
		return "Revenant";
		break;
	case app::GhostTraits_Type__Enum_Shade:
		return "Shade";
		break;
	case app::GhostTraits_Type__Enum_Demon:
		return "Demon";
		break;
	case app::GhostTraits_Type__Enum_Yurei:
		return "Yurei";
		break;
	case app::GhostTraits_Type__Enum_Oni:
		return "Oni";
		break;
	default:
		return NULL;
	}
}

#endif // !INCLUDES_H
