#ifndef GUARD_SAFARI_ZONE_H
#define GUARD_SAFARI_ZONE_H

extern u8 gNumSafariBalls;

bool32 GetSafariZoneFlag(void);
bool32 GetPastTutorialFlag(void);
void SetSafariZoneFlag(void);
void GRC_EnablePartyFlag(void);
void ResetSafariZoneFlag(void);

void EnterSafariMode(void);
void EnterSafariModeR1(void);
void ExitSafariMode(void);

bool8 SafariZoneTakeStep(void);
void SafariZoneRetirePrompt(void);

void CB2_EndSafariBattle(void);

struct Pokeblock *SafariZoneGetActivePokeblock(void);
void SafariZoneActivatePokeblockFeeder(u8 pokeblock_index);

#endif // GUARD_SAFARI_ZONE_H
