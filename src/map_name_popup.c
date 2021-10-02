#include "global.h"
#include "battle_pyramid.h"
#include "bg.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "menu.h"
#include "map_name_popup.h"
#include "palette.h"
#include "region_map.h"
#include "start_menu.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "constants/layouts.h"
#include "constants/region_map_sections.h"
#include "constants/weather.h"

// enums
enum MapPopUp_Themes
{
    MAPPOPUP_THEME_WOOD,
    MAPPOPUP_THEME_MARBLE,
    MAPPOPUP_THEME_STONE,
    MAPPOPUP_THEME_BRICK,
    MAPPOPUP_THEME_UNDERWATER,
    MAPPOPUP_THEME_STONE2,
};

// static functions
static void Task_MapNamePopUpWindow(u8 taskId);
static void ShowMapNamePopUpWindow(void);
static void LoadMapNamePopUpWindowBg(void);

// EWRAM
static EWRAM_DATA u8 sPopupTaskId = 0;

// .rodata
static const u8 sMapPopUp_Table[][960] =
{
    [MAPPOPUP_THEME_WOOD]       = INCBIN_U8("graphics/interface/map_popup/wood.4bpp"),
    [MAPPOPUP_THEME_MARBLE]     = INCBIN_U8("graphics/interface/map_popup/marble.4bpp"),
    [MAPPOPUP_THEME_STONE]      = INCBIN_U8("graphics/interface/map_popup/stone.4bpp"),
    [MAPPOPUP_THEME_BRICK]      = INCBIN_U8("graphics/interface/map_popup/brick.4bpp"),
    [MAPPOPUP_THEME_UNDERWATER] = INCBIN_U8("graphics/interface/map_popup/underwater.4bpp"),
    [MAPPOPUP_THEME_STONE2]     = INCBIN_U8("graphics/interface/map_popup/stone2.4bpp"),
};

static const u8 sMapPopUp_OutlineTable[][960] =
{
    [MAPPOPUP_THEME_WOOD]       = INCBIN_U8("graphics/interface/map_popup/wood_outline.4bpp"),
    [MAPPOPUP_THEME_MARBLE]     = INCBIN_U8("graphics/interface/map_popup/marble_outline.4bpp"),
    [MAPPOPUP_THEME_STONE]      = INCBIN_U8("graphics/interface/map_popup/stone_outline.4bpp"),
    [MAPPOPUP_THEME_BRICK]      = INCBIN_U8("graphics/interface/map_popup/brick_outline.4bpp"),
    [MAPPOPUP_THEME_UNDERWATER] = INCBIN_U8("graphics/interface/map_popup/underwater_outline.4bpp"),
    [MAPPOPUP_THEME_STONE2]     = INCBIN_U8("graphics/interface/map_popup/stone2_outline.4bpp"),
};

static const u16 sMapPopUp_PaletteTable[][16] =
{
    [MAPPOPUP_THEME_WOOD]       = INCBIN_U16("graphics/interface/map_popup/wood.gbapal"),
    [MAPPOPUP_THEME_MARBLE]     = INCBIN_U16("graphics/interface/map_popup/marble_outline.gbapal"),
    [MAPPOPUP_THEME_STONE]      = INCBIN_U16("graphics/interface/map_popup/stone_outline.gbapal"),
    [MAPPOPUP_THEME_BRICK]      = INCBIN_U16("graphics/interface/map_popup/brick_outline.gbapal"),
    [MAPPOPUP_THEME_UNDERWATER] = INCBIN_U16("graphics/interface/map_popup/underwater_outline.gbapal"),
    [MAPPOPUP_THEME_STONE2]     = INCBIN_U16("graphics/interface/map_popup/stone2_outline.gbapal"),
};

static const u16 sMapPopUp_Palette_Underwater[16] = INCBIN_U16("graphics/interface/map_popup/underwater.gbapal");

static const u8 gRegionMapSectionId_To_PopUpThemeIdMapping[] =
{
    [MAPSEC_TURPIA_TOWN] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_MAGNOLIA_TOWN] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_POPPY_TOWN] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_CLEMATI_TOWN] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_FALLUGE_HAMLET] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_HELIANTH_TOWN] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_KELLIP_TOWN] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_DAFFLE_CITY] = MAPPOPUP_THEME_BRICK,
    [MAPSEC_ORCHIDALE_CITY] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_ARECACE_CITY] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_CALLUNE_CITY] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_LECHENA_CITY] = MAPPOPUP_THEME_BRICK,
    [MAPSEC_ROSEVALE_CITY] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_VYGIE_CITY] = MAPPOPUP_THEME_BRICK,
    [MAPSEC_HEDERA_CITY] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_BORAGO_CITY] = MAPPOPUP_THEME_BRICK,
    [MAPSEC_GRC_ROUTE1] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_GRC_ROUTE8] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_GRC_ROUTE3] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_GRC_ROUTE2] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_GRC_ROUTE14] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_GRC_ROUTE23] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_GRC_ROUTE29] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_GRC_ROUTE4] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_GRC_ROUTE12] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_GRC_ROUTE7] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_GRC_ROUTE20] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_GRC_ROUTE26] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_GRC_ROUTE27] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_GRC_ROUTE21] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_GRC_ROUTE22] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_GRC_ROUTE5] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_GRC_ROUTE11] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_GRC_ROUTE32] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_GRC_ROUTE28] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_GRC_ROUTE19] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_GRC_ROUTE18] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_GRC_ROUTE6] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_GRC_ROUTE25] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_GRC_ROUTE24] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_125] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_GRC_ROUTE30] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_127] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_128] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_GRC_ROUTE15] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_GRC_ROUTE13] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_GRC_ROUTE10] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_GRC_ROUTE17] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_GRC_ROUTE9] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_GRC_ROUTE16] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_UNDERWATER_124] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_UNDERWATER_126] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_UNDERWATER_127] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_UNDERWATER_128] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_UNDERWATER_SOOTOPOLIS] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_SHRUB_GROTTO] = MAPPOPUP_THEME_STONE,
    [MAPSEC_ORCHIDALE_SLUMS] = MAPPOPUP_THEME_STONE,
    [MAPSEC_SAFARI_ZONE] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_BATTLE_FRONTIER] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_BORAGO_GROVE] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_PASS_OF_TRIALS] = MAPPOPUP_THEME_STONE,
    [MAPSEC_PARCHED_RUINS] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_MIASMIC_WOODS] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_CANDID_CAVE] = MAPPOPUP_THEME_STONE,
    [MAPSEC_CANDID_CAVE2] = MAPPOPUP_THEME_STONE,
    [MAPSEC_HELIX_SPIRE] = MAPPOPUP_THEME_STONE,
    [MAPSEC_VITAE_HIDEOUT_OLD] = MAPPOPUP_THEME_STONE,
    [MAPSEC_HEDERA_MINES] = MAPPOPUP_THEME_STONE,
    [MAPSEC_COCYTUS_CAVERN] = MAPPOPUP_THEME_STONE,
    [MAPSEC_UNDERWATER_SEAFLOOR_CAVERN] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_VICTORY_ROAD] = MAPPOPUP_THEME_STONE,
    [MAPSEC_MIRAGE_ISLAND] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_CAVE_OF_ORIGIN] = MAPPOPUP_THEME_STONE,
    [MAPSEC_SOUTHERN_ISLAND] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_TORRID_HOLLOW] = MAPPOPUP_THEME_STONE,
    [MAPSEC_TORRID_HOLLOW2] = MAPPOPUP_THEME_STONE,
    [MAPSEC_SLOPE_OF_SLEET] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_SLOPE_OF_SLEET2] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_SEALED_CHAMBER] = MAPPOPUP_THEME_STONE,
    [MAPSEC_UNDERWATER_SEALED_CHAMBER] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_MINOS_RUINS] = MAPPOPUP_THEME_STONE,
    [MAPSEC_ISLAND_CAVE] = MAPPOPUP_THEME_STONE,
    [MAPSEC_DESERT_RUINS] = MAPPOPUP_THEME_STONE,
    [MAPSEC_ANCIENT_TOMB] = MAPPOPUP_THEME_STONE,
    [MAPSEC_SS_VARUNA] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_SKY_PILLAR] = MAPPOPUP_THEME_STONE,
    [MAPSEC_SECRET_BASE] = MAPPOPUP_THEME_STONE,
    [MAPSEC_DYNAMIC] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_VITAE_HIDEOUT - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_STONE,
    [MAPSEC_GRATIA_FOREST - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_STONE,
    [MAPSEC_MIRAGE_TOWER - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_STONE,
    [MAPSEC_BIRTH_ISLAND - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_FARAWAY_ISLAND - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_AXIOM_ALTAR - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_STONE,
    [MAPSEC_ABYSSAL_TRENCH - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_STONE,
    [MAPSEC_UNDERWATER_MARINE_CAVE - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_MOLTEN_CHAMBER - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_STONE,
    [MAPSEC_UNDERWATER_105 - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_UNDERWATER_125 - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_UNDERWATER_129 - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_DESERT_UNDERPASS - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_STONE,
    [MAPSEC_ALTERING_CAVE - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_STONE,
    [MAPSEC_NAVEL_ROCK - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_STONE,
    [MAPSEC_TRAINER_HILL - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_MARBLE
};

static const u8 gText_PyramidFloor1[] = _("Pyramid Floor 1");
static const u8 gText_PyramidFloor2[] = _("Pyramid Floor 2");
static const u8 gText_PyramidFloor3[] = _("Pyramid Floor 3");
static const u8 gText_PyramidFloor4[] = _("Pyramid Floor 4");
static const u8 gText_PyramidFloor5[] = _("Pyramid Floor 5");
static const u8 gText_PyramidFloor6[] = _("Pyramid Floor 6");
static const u8 gText_PyramidFloor7[] = _("Pyramid Floor 7");
static const u8 gText_Pyramid[] = _("Pyramid");

static const u8 * const gBattlePyramid_MapHeaderStrings[] =
{
    gText_PyramidFloor1,
    gText_PyramidFloor2,
    gText_PyramidFloor3,
    gText_PyramidFloor4,
    gText_PyramidFloor5,
    gText_PyramidFloor6,
    gText_PyramidFloor7,
    gText_Pyramid,
};

// Unused
static bool8 StartMenu_ShowMapNamePopup(void)
{
    HideStartMenu();
    ShowMapNamePopup();
    return TRUE;
}

void ShowMapNamePopup(void)
{
    if (FlagGet(FLAG_HIDE_MAP_NAME_POPUP) != TRUE)
    {
        if (!FuncIsActiveTask(Task_MapNamePopUpWindow))
        {
            sPopupTaskId = CreateTask(Task_MapNamePopUpWindow, 90);
            SetGpuReg(REG_OFFSET_BG0VOFS, 40);
            gTasks[sPopupTaskId].data[0] = 6;
            gTasks[sPopupTaskId].data[2] = 40;
        }
        else
        {
            if (gTasks[sPopupTaskId].data[0] != 2)
                gTasks[sPopupTaskId].data[0] = 2;
            gTasks[sPopupTaskId].data[3] = 1;
        }
    }
}

static void Task_MapNamePopUpWindow(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 6:
        task->data[4]++;
        if (task->data[4] > 30)
        {
            task->data[0] = 0;
            task->data[4] = 0;
            ShowMapNamePopUpWindow();
        }
        break;
    case 0:
        task->data[2] -= 2;
        if (task->data[2] <= 0 )
        {
            task->data[2] = 0;
            task->data[0] = 1;
            gTasks[sPopupTaskId].data[1] = 0;
        }
        break;
    case 1:
        task->data[1]++;
        if (task->data[1] > 120 )
        {
            task->data[1] = 0;
            task->data[0] = 2;
        }
        break;
    case 2:
        task->data[2] += 2;
        if (task->data[2] > 39)
        {
            task->data[2] = 40;
            if (task->data[3])
            {
                task->data[0] = 6;
                task->data[4] = 0;
                task->data[3] = 0;
            }
            else
            {
                task->data[0] = 4;
                return;
            }
        }
        break;
    case 4:
        ClearStdWindowAndFrame(GetMapNamePopUpWindowId(), TRUE);
        task->data[0] = 5;
        break;
    case 5:
        HideMapNamePopUpWindow();
        return;
    }
    SetGpuReg(REG_OFFSET_BG0VOFS, task->data[2]);
}

void HideMapNamePopUpWindow(void)
{
    if (FuncIsActiveTask(Task_MapNamePopUpWindow))
    {
        ClearStdWindowAndFrame(GetMapNamePopUpWindowId(), TRUE);
        RemoveMapNamePopUpWindow();
        SetGpuReg_ForcedBlank(REG_OFFSET_BG0VOFS, 0);
        DestroyTask(sPopupTaskId);
    }
}

static void ShowMapNamePopUpWindow(void)
{
    u8 mapDisplayHeader[24];
    u8 *withoutPrefixPtr;
    u8 x;
    const u8* mapDisplayHeaderSource;

    if (InBattlePyramid())
    {
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP)
        {
            withoutPrefixPtr = &(mapDisplayHeader[3]);
            mapDisplayHeaderSource = gBattlePyramid_MapHeaderStrings[7];
        }
        else
        {
            withoutPrefixPtr = &(mapDisplayHeader[3]);
            mapDisplayHeaderSource = gBattlePyramid_MapHeaderStrings[gSaveBlock2Ptr->frontier.curChallengeBattleNum];
        }
        StringCopy(withoutPrefixPtr, mapDisplayHeaderSource);
    }
    else
    {
        withoutPrefixPtr = &(mapDisplayHeader[3]);
        GetMapName(withoutPrefixPtr, gMapHeader.regionMapSectionId, 0);
    }
    AddMapNamePopUpWindow();
    LoadMapNamePopUpWindowBg();
    x = GetStringCenterAlignXOffset(7, withoutPrefixPtr, 80);
    mapDisplayHeader[0] = EXT_CTRL_CODE_BEGIN;
    mapDisplayHeader[1] = EXT_CTRL_CODE_HIGHLIGHT;
    mapDisplayHeader[2] = TEXT_COLOR_TRANSPARENT;
    AddTextPrinterParameterized(GetMapNamePopUpWindowId(), 7, mapDisplayHeader, x, 3, 0xFF, NULL);
    CopyWindowToVram(GetMapNamePopUpWindowId(), 3);
}

#define TILE_TOP_EDGE_START 0x21D
#define TILE_TOP_EDGE_END   0x228
#define TILE_LEFT_EDGE_TOP  0x229
#define TILE_RIGHT_EDGE_TOP 0x22A
#define TILE_LEFT_EDGE_MID  0x22B
#define TILE_RIGHT_EDGE_MID 0x22C
#define TILE_LEFT_EDGE_BOT  0x22D
#define TILE_RIGHT_EDGE_BOT 0x22E
#define TILE_BOT_EDGE_START 0x22F
#define TILE_BOT_EDGE_END   0x23A

static void DrawMapNamePopUpFrame(u8 bg, u8 x, u8 y, u8 deltaX, u8 deltaY, u8 unused)
{
    s32 i;

    // Draw top edge
    for (i = 0; i < 1 + TILE_TOP_EDGE_END - TILE_TOP_EDGE_START; i++)
        FillBgTilemapBufferRect(bg, TILE_TOP_EDGE_START + i, i - 1 + x, y - 1, 1, 1, 14);

    // Draw sides
    FillBgTilemapBufferRect(bg, TILE_LEFT_EDGE_TOP,       x - 1,     y, 1, 1, 14);
    FillBgTilemapBufferRect(bg, TILE_RIGHT_EDGE_TOP, deltaX + x,     y, 1, 1, 14);
    FillBgTilemapBufferRect(bg, TILE_LEFT_EDGE_MID,       x - 1, y + 1, 1, 1, 14);
    FillBgTilemapBufferRect(bg, TILE_RIGHT_EDGE_MID, deltaX + x, y + 1, 1, 1, 14);
    FillBgTilemapBufferRect(bg, TILE_LEFT_EDGE_BOT,       x - 1, y + 2, 1, 1, 14);
    FillBgTilemapBufferRect(bg, TILE_RIGHT_EDGE_BOT, deltaX + x, y + 2, 1, 1, 14);

    // Draw bottom edge
    for (i = 0; i < 1 + TILE_BOT_EDGE_END - TILE_BOT_EDGE_START; i++)
        FillBgTilemapBufferRect(bg, TILE_BOT_EDGE_START + i, i - 1 + x, y + deltaY, 1, 1, 14);
}

static void LoadMapNamePopUpWindowBg(void)
{
    u8 popUpThemeId;
    u8 popupWindowId = GetMapNamePopUpWindowId();
    u16 regionMapSectionId = gMapHeader.regionMapSectionId;

    if (regionMapSectionId >= KANTO_MAPSEC_START)
    {
        if (regionMapSectionId > KANTO_MAPSEC_END)
            regionMapSectionId -= KANTO_MAPSEC_COUNT;
        else
            regionMapSectionId = 0; // Discard kanto region sections;
    }
    popUpThemeId = gRegionMapSectionId_To_PopUpThemeIdMapping[regionMapSectionId];

    LoadBgTiles(GetWindowAttribute(popupWindowId, WINDOW_BG), sMapPopUp_OutlineTable[popUpThemeId], 0x400, 0x21D);
    CallWindowFunction(popupWindowId, DrawMapNamePopUpFrame);
    PutWindowTilemap(popupWindowId);
    if (gMapHeader.weather == WEATHER_UNDERWATER_BUBBLES)
        LoadPalette(&sMapPopUp_Palette_Underwater, 0xE0, sizeof(sMapPopUp_Palette_Underwater));
    else
        LoadPalette(sMapPopUp_PaletteTable[popUpThemeId], 0xE0, sizeof(sMapPopUp_PaletteTable[0]));
    BlitBitmapToWindow(popupWindowId, sMapPopUp_Table[popUpThemeId], 0, 0, 80, 24);
}
