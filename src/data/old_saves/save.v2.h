#include "global.h"
#include "save.h"

// This file contains the backups for the save file of v2.
// Editing this file may cause unwanted behaviour.
// Please use make release in case problems arise.

struct BattleFrontier_v2
{
    struct EmeraldBattleTowerRecord towerPlayer;
    struct EmeraldBattleTowerRecord towerRecords[5];
    struct BattleTowerInterview towerInterview;
    struct BattleTowerEReaderTrainer ereaderTrainer;
    u8 challengeStatus;
    u8 lvlMode:2;
    u8 challengePaused:1;
    u8 disableRecordBattle:1;
    u16 selectedPartyMons[4];
    u16 curChallengeBattleNum;
    u16 trainerIds[20];
    u32 winStreakActiveFlags;
    u16 towerWinStreaks[4][2];
    u16 towerRecordWinStreaks[4][2];
    u16 battledBrainFlags;
    u16 towerSinglesStreak;
    u16 towerNumWins;
    u8 towerBattleOutcome;
    u8 towerLvlMode;
    u8 domeAttemptedSingles50:1;
    u8 domeAttemptedSinglesOpen:1;
    u8 domeHasWonSingles50:1;
    u8 domeHasWonSinglesOpen:1;
    u8 domeAttemptedDoubles50:1;
    u8 domeAttemptedDoublesOpen:1;
    u8 domeHasWonDoubles50:1;
    u8 domeHasWonDoublesOpen:1;
    u8 domeUnused;
    u8 domeLvlMode;
    u8 domeBattleMode;
    u16 domeWinStreaks[2][2];
    u16 domeRecordWinStreaks[2][2];
    u16 domeTotalChampionships[2][2];
    struct BattleDomeTrainer domeTrainers[16];
    u16 domeMonIds[16][3];
    u16 unused_DC4;
    u16 palacePrize;
    u16 palaceWinStreaks[2][2];
    u16 palaceRecordWinStreaks[2][2];
    u16 arenaPrize;
    u16 arenaWinStreaks[2];
    u16 arenaRecordStreaks[2];
    u16 factoryWinStreaks[2][2];
    u16 factoryRecordWinStreaks[2][2];
    u16 factoryRentsCount[2][2];
    u16 factoryRecordRentsCount[2][2];
    u16 pikePrize;
    u16 pikeWinStreaks[2];
    u16 pikeRecordStreaks[2];
    u16 pikeTotalStreaks[2];
    u8 pikeHintedRoomIndex:3;
    u8 pikeHintedRoomType:4;
    u8 pikeHealingRoomsDisabled:1;
    u16 pikeHeldItemsBackup[3];
    u16 pyramidPrize;
    u16 pyramidWinStreaks[2];
    u16 pyramidRecordStreaks[2];
    u16 pyramidRandoms[4];
    u8 pyramidTrainerFlags;
    struct PyramidBag pyramidBag;
    u8 pyramidLightRadius;
    u16 verdanturfTentPrize;
    u16 fallarborTentPrize;
    u16 slateportTentPrize;
    struct RentalMon rentalMons[6];
    u16 battlePoints;
    u16 cardBattlePoints;
    u32 battlesCount;
    u16 domeWinningMoves[16];
    u8 trainerFlags;
    u8 opponentNames[2][8];
    u8 opponentTrainerIds[2][4];
    u8 unk_EF9:7;
    u8 savedGame:1;
    u8 unused_EFA;
    u8 unused_EFB;
    struct DomeMonData domePlayerPartyData[3];
};


bool8 UpdateSave_v2_v3(const struct SaveSectorLocation *locations)
{
    const struct SaveBlock2* sOldSaveBlock2Ptr = (struct SaveBlock2*)(locations[0].data); // SECTOR_ID_SAVEBLOCK2
    const struct SaveBlock1* sOldSaveBlock1Ptr = (struct SaveBlock1*)(locations[1].data); // SECTOR_ID_SAVEBLOCK1_START
    const struct PokemonStorage* sOldPokemonStoragePtr = (struct PokemonStorage*)(locations[5].data); // SECTOR_ID_PKMN_STORAGE_START
    u32 i;

    // SaveBlock2 
    gSaveBlock2Ptr->_saveSentinel = 0xFF;
    gSaveBlock2Ptr->saveVersion = 3;
    for(i = 0; i < min(ARRAY_COUNT(gSaveBlock2Ptr->playerName), ARRAY_COUNT(sOldSaveBlock2Ptr->playerName)); i++) gSaveBlock2Ptr->playerName[i] = sOldSaveBlock2Ptr->playerName[i];
    gSaveBlock2Ptr->playerGender = sOldSaveBlock2Ptr->playerGender;
    gSaveBlock2Ptr->specialSaveWarpFlags = sOldSaveBlock2Ptr->specialSaveWarpFlags;
    for(i = 0; i < min(ARRAY_COUNT(gSaveBlock2Ptr->playerTrainerId), ARRAY_COUNT(sOldSaveBlock2Ptr->playerTrainerId)); i++) gSaveBlock2Ptr->playerTrainerId[i] = sOldSaveBlock2Ptr->playerTrainerId[i];
    gSaveBlock2Ptr->playTimeHours = sOldSaveBlock2Ptr->playTimeHours;
    gSaveBlock2Ptr->playTimeMinutes = sOldSaveBlock2Ptr->playTimeMinutes;
    gSaveBlock2Ptr->playTimeSeconds = sOldSaveBlock2Ptr->playTimeSeconds;
    gSaveBlock2Ptr->playTimeVBlanks = sOldSaveBlock2Ptr->playTimeVBlanks;
    gSaveBlock2Ptr->optionsButtonMode = sOldSaveBlock2Ptr->optionsButtonMode;
    gSaveBlock2Ptr->optionsTextSpeed = sOldSaveBlock2Ptr->optionsTextSpeed;
    gSaveBlock2Ptr->optionsWindowFrameType = sOldSaveBlock2Ptr->optionsWindowFrameType;
    for(i = 0; i < min(ARRAY_COUNT(gSaveBlock2Ptr->questData), ARRAY_COUNT(sOldSaveBlock2Ptr->questData)); i++) gSaveBlock2Ptr->questData[i] = sOldSaveBlock2Ptr->questData[i];
    for(i = 0; i < min(ARRAY_COUNT(gSaveBlock2Ptr->subQuests), ARRAY_COUNT(sOldSaveBlock2Ptr->subQuests)); i++) gSaveBlock2Ptr->subQuests[i] = sOldSaveBlock2Ptr->subQuests[i];
    gSaveBlock2Ptr->optionsSound = sOldSaveBlock2Ptr->optionsSound;
    gSaveBlock2Ptr->optionsBattleStyle = sOldSaveBlock2Ptr->optionsBattleStyle;
    gSaveBlock2Ptr->optionsBattleSceneOff = sOldSaveBlock2Ptr->optionsBattleSceneOff;
    gSaveBlock2Ptr->regionMapZoom = sOldSaveBlock2Ptr->regionMapZoom;
    gSaveBlock2Ptr->pokedex = sOldSaveBlock2Ptr->pokedex;
    for(i = 0; i < min(ARRAY_COUNT(gSaveBlock2Ptr->filler_90), ARRAY_COUNT(sOldSaveBlock2Ptr->filler_90)); i++) gSaveBlock2Ptr->filler_90[i] = sOldSaveBlock2Ptr->filler_90[i];
    gSaveBlock2Ptr->localTimeOffset = sOldSaveBlock2Ptr->localTimeOffset;
    gSaveBlock2Ptr->lastBerryTreeUpdate = sOldSaveBlock2Ptr->lastBerryTreeUpdate;
    gSaveBlock2Ptr->gcnLinkFlags = sOldSaveBlock2Ptr->gcnLinkFlags;
    gSaveBlock2Ptr->encryptionKey = sOldSaveBlock2Ptr->encryptionKey;
    gSaveBlock2Ptr->playerApprentice = sOldSaveBlock2Ptr->playerApprentice;
    CpuCopy16(&sOldSaveBlock2Ptr->apprentices, &gSaveBlock2Ptr->apprentices, sizeof(gSaveBlock2Ptr->apprentices));
    gSaveBlock2Ptr->berryCrush = sOldSaveBlock2Ptr->berryCrush;
    gSaveBlock2Ptr->pokeJump = sOldSaveBlock2Ptr->pokeJump;
    gSaveBlock2Ptr->berryPick = sOldSaveBlock2Ptr->berryPick;
    CpuCopy16(&sOldSaveBlock2Ptr->hallRecords1P, &gSaveBlock2Ptr->hallRecords1P, sizeof(gSaveBlock2Ptr->hallRecords1P));
    CpuCopy16(&sOldSaveBlock2Ptr->hallRecords2P, &gSaveBlock2Ptr->hallRecords2P, sizeof(gSaveBlock2Ptr->hallRecords2P));
    CpuCopy16(&sOldSaveBlock2Ptr->contestLinkResults, &gSaveBlock2Ptr->contestLinkResults, sizeof(gSaveBlock2Ptr->contestLinkResults));
    gSaveBlock2Ptr->frontier.towerPlayer = sOldSaveBlock2Ptr->frontier.towerPlayer;
    CpuCopy16(&sOldSaveBlock2Ptr->frontier.towerRecords, &gSaveBlock2Ptr->frontier.towerRecords, sizeof(gSaveBlock2Ptr->frontier.towerRecords));
    gSaveBlock2Ptr->frontier.towerInterview = sOldSaveBlock2Ptr->frontier.towerInterview;
    gSaveBlock2Ptr->frontier.ereaderTrainer = sOldSaveBlock2Ptr->frontier.ereaderTrainer;
    gSaveBlock2Ptr->frontier.challengeStatus = sOldSaveBlock2Ptr->frontier.challengeStatus;
    gSaveBlock2Ptr->frontier.lvlMode = sOldSaveBlock2Ptr->frontier.lvlMode;
    gSaveBlock2Ptr->frontier.challengePaused = sOldSaveBlock2Ptr->frontier.challengePaused;
    gSaveBlock2Ptr->frontier.disableRecordBattle = sOldSaveBlock2Ptr->frontier.disableRecordBattle;
    for(i = 0; i < min(ARRAY_COUNT(gSaveBlock2Ptr->frontier.selectedPartyMons), ARRAY_COUNT(sOldSaveBlock2Ptr->frontier.selectedPartyMons)); i++) gSaveBlock2Ptr->frontier.selectedPartyMons[i] = sOldSaveBlock2Ptr->frontier.selectedPartyMons[i];
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = sOldSaveBlock2Ptr->frontier.curChallengeBattleNum;
    for(i = 0; i < min(ARRAY_COUNT(gSaveBlock2Ptr->frontier.trainerIds), ARRAY_COUNT(sOldSaveBlock2Ptr->frontier.trainerIds)); i++) gSaveBlock2Ptr->frontier.trainerIds[i] = sOldSaveBlock2Ptr->frontier.trainerIds[i];
    gSaveBlock2Ptr->frontier.winStreakActiveFlags = sOldSaveBlock2Ptr->frontier.winStreakActiveFlags;
    CpuCopy16(&sOldSaveBlock2Ptr->frontier.towerWinStreaks, &gSaveBlock2Ptr->frontier.towerWinStreaks, sizeof(gSaveBlock2Ptr->frontier.towerWinStreaks));
    CpuCopy16(&sOldSaveBlock2Ptr->frontier.towerRecordWinStreaks, &gSaveBlock2Ptr->frontier.towerRecordWinStreaks, sizeof(gSaveBlock2Ptr->frontier.towerRecordWinStreaks));
    gSaveBlock2Ptr->frontier.battledBrainFlags = sOldSaveBlock2Ptr->frontier.battledBrainFlags;
    gSaveBlock2Ptr->frontier.towerSinglesStreak = sOldSaveBlock2Ptr->frontier.towerSinglesStreak;
    gSaveBlock2Ptr->frontier.towerNumWins = sOldSaveBlock2Ptr->frontier.towerNumWins;
    gSaveBlock2Ptr->frontier.towerBattleOutcome = sOldSaveBlock2Ptr->frontier.towerBattleOutcome;
    gSaveBlock2Ptr->frontier.towerLvlMode = sOldSaveBlock2Ptr->frontier.towerLvlMode;
    gSaveBlock2Ptr->frontier.domeAttemptedSingles50 = sOldSaveBlock2Ptr->frontier.domeAttemptedSingles50;
    gSaveBlock2Ptr->frontier.domeAttemptedSinglesOpen = sOldSaveBlock2Ptr->frontier.domeAttemptedSinglesOpen;
    gSaveBlock2Ptr->frontier.domeHasWonSingles50 = sOldSaveBlock2Ptr->frontier.domeHasWonSingles50;
    gSaveBlock2Ptr->frontier.domeHasWonSinglesOpen = sOldSaveBlock2Ptr->frontier.domeHasWonSinglesOpen;
    gSaveBlock2Ptr->frontier.domeAttemptedDoubles50 = sOldSaveBlock2Ptr->frontier.domeAttemptedDoubles50;
    gSaveBlock2Ptr->frontier.domeAttemptedDoublesOpen = sOldSaveBlock2Ptr->frontier.domeAttemptedDoublesOpen;
    gSaveBlock2Ptr->frontier.domeHasWonDoubles50 = sOldSaveBlock2Ptr->frontier.domeHasWonDoubles50;
    gSaveBlock2Ptr->frontier.domeHasWonDoublesOpen = sOldSaveBlock2Ptr->frontier.domeHasWonDoublesOpen;
    gSaveBlock2Ptr->frontier.domeUnused = sOldSaveBlock2Ptr->frontier.domeUnused;
    gSaveBlock2Ptr->frontier.domeLvlMode = sOldSaveBlock2Ptr->frontier.domeLvlMode;
    gSaveBlock2Ptr->frontier.domeBattleMode = sOldSaveBlock2Ptr->frontier.domeBattleMode;
    CpuCopy16(&sOldSaveBlock2Ptr->frontier.domeWinStreaks, &gSaveBlock2Ptr->frontier.domeWinStreaks, sizeof(gSaveBlock2Ptr->frontier.domeWinStreaks));
    CpuCopy16(&sOldSaveBlock2Ptr->frontier.domeRecordWinStreaks, &gSaveBlock2Ptr->frontier.domeRecordWinStreaks, sizeof(gSaveBlock2Ptr->frontier.domeRecordWinStreaks));
    CpuCopy16(&sOldSaveBlock2Ptr->frontier.domeTotalChampionships, &gSaveBlock2Ptr->frontier.domeTotalChampionships, sizeof(gSaveBlock2Ptr->frontier.domeTotalChampionships));
    CpuCopy16(&sOldSaveBlock2Ptr->frontier.domeTrainers, &gSaveBlock2Ptr->frontier.domeTrainers, sizeof(gSaveBlock2Ptr->frontier.domeTrainers));
    CpuCopy16(&sOldSaveBlock2Ptr->frontier.domeMonIds, &gSaveBlock2Ptr->frontier.domeMonIds, sizeof(gSaveBlock2Ptr->frontier.domeMonIds));
    gSaveBlock2Ptr->frontier.unused_DC4 = sOldSaveBlock2Ptr->frontier.unused_DC4;
    gSaveBlock2Ptr->frontier.palacePrize = sOldSaveBlock2Ptr->frontier.palacePrize;
    CpuCopy16(&sOldSaveBlock2Ptr->frontier.palaceWinStreaks, &gSaveBlock2Ptr->frontier.palaceWinStreaks, sizeof(gSaveBlock2Ptr->frontier.palaceWinStreaks));
    CpuCopy16(&sOldSaveBlock2Ptr->frontier.palaceRecordWinStreaks, &gSaveBlock2Ptr->frontier.palaceRecordWinStreaks, sizeof(gSaveBlock2Ptr->frontier.palaceRecordWinStreaks));
    gSaveBlock2Ptr->frontier.arenaPrize = sOldSaveBlock2Ptr->frontier.arenaPrize;
    for(i = 0; i < min(ARRAY_COUNT(gSaveBlock2Ptr->frontier.arenaWinStreaks), ARRAY_COUNT(sOldSaveBlock2Ptr->frontier.arenaWinStreaks)); i++) gSaveBlock2Ptr->frontier.arenaWinStreaks[i] = sOldSaveBlock2Ptr->frontier.arenaWinStreaks[i];
    for(i = 0; i < min(ARRAY_COUNT(gSaveBlock2Ptr->frontier.arenaRecordStreaks), ARRAY_COUNT(sOldSaveBlock2Ptr->frontier.arenaRecordStreaks)); i++) gSaveBlock2Ptr->frontier.arenaRecordStreaks[i] = sOldSaveBlock2Ptr->frontier.arenaRecordStreaks[i];
    CpuCopy16(&sOldSaveBlock2Ptr->frontier.factoryWinStreaks, &gSaveBlock2Ptr->frontier.factoryWinStreaks, sizeof(gSaveBlock2Ptr->frontier.factoryWinStreaks));
    CpuCopy16(&sOldSaveBlock2Ptr->frontier.factoryRecordWinStreaks, &gSaveBlock2Ptr->frontier.factoryRecordWinStreaks, sizeof(gSaveBlock2Ptr->frontier.factoryRecordWinStreaks));
    CpuCopy16(&sOldSaveBlock2Ptr->frontier.factoryRentsCount, &gSaveBlock2Ptr->frontier.factoryRentsCount, sizeof(gSaveBlock2Ptr->frontier.factoryRentsCount));
    CpuCopy16(&sOldSaveBlock2Ptr->frontier.factoryRecordRentsCount, &gSaveBlock2Ptr->frontier.factoryRecordRentsCount, sizeof(gSaveBlock2Ptr->frontier.factoryRecordRentsCount));
    gSaveBlock2Ptr->frontier.pikePrize = sOldSaveBlock2Ptr->frontier.pikePrize;
    for(i = 0; i < min(ARRAY_COUNT(gSaveBlock2Ptr->frontier.pikeWinStreaks), ARRAY_COUNT(sOldSaveBlock2Ptr->frontier.pikeWinStreaks)); i++) gSaveBlock2Ptr->frontier.pikeWinStreaks[i] = sOldSaveBlock2Ptr->frontier.pikeWinStreaks[i];
    for(i = 0; i < min(ARRAY_COUNT(gSaveBlock2Ptr->frontier.pikeRecordStreaks), ARRAY_COUNT(sOldSaveBlock2Ptr->frontier.pikeRecordStreaks)); i++) gSaveBlock2Ptr->frontier.pikeRecordStreaks[i] = sOldSaveBlock2Ptr->frontier.pikeRecordStreaks[i];
    for(i = 0; i < min(ARRAY_COUNT(gSaveBlock2Ptr->frontier.pikeTotalStreaks), ARRAY_COUNT(sOldSaveBlock2Ptr->frontier.pikeTotalStreaks)); i++) gSaveBlock2Ptr->frontier.pikeTotalStreaks[i] = sOldSaveBlock2Ptr->frontier.pikeTotalStreaks[i];
    gSaveBlock2Ptr->frontier.pikeHintedRoomIndex = sOldSaveBlock2Ptr->frontier.pikeHintedRoomIndex;
    gSaveBlock2Ptr->frontier.pikeHintedRoomType = sOldSaveBlock2Ptr->frontier.pikeHintedRoomType;
    gSaveBlock2Ptr->frontier.pikeHealingRoomsDisabled = sOldSaveBlock2Ptr->frontier.pikeHealingRoomsDisabled;
    for(i = 0; i < min(ARRAY_COUNT(gSaveBlock2Ptr->frontier.pikeHeldItemsBackup), ARRAY_COUNT(sOldSaveBlock2Ptr->frontier.pikeHeldItemsBackup)); i++) gSaveBlock2Ptr->frontier.pikeHeldItemsBackup[i] = sOldSaveBlock2Ptr->frontier.pikeHeldItemsBackup[i];
    gSaveBlock2Ptr->frontier.pyramidPrize = sOldSaveBlock2Ptr->frontier.pyramidPrize;
    for(i = 0; i < min(ARRAY_COUNT(gSaveBlock2Ptr->frontier.pyramidWinStreaks), ARRAY_COUNT(sOldSaveBlock2Ptr->frontier.pyramidWinStreaks)); i++) gSaveBlock2Ptr->frontier.pyramidWinStreaks[i] = sOldSaveBlock2Ptr->frontier.pyramidWinStreaks[i];
    for(i = 0; i < min(ARRAY_COUNT(gSaveBlock2Ptr->frontier.pyramidRecordStreaks), ARRAY_COUNT(sOldSaveBlock2Ptr->frontier.pyramidRecordStreaks)); i++) gSaveBlock2Ptr->frontier.pyramidRecordStreaks[i] = sOldSaveBlock2Ptr->frontier.pyramidRecordStreaks[i];
    for(i = 0; i < min(ARRAY_COUNT(gSaveBlock2Ptr->frontier.pyramidRandoms), ARRAY_COUNT(sOldSaveBlock2Ptr->frontier.pyramidRandoms)); i++) gSaveBlock2Ptr->frontier.pyramidRandoms[i] = sOldSaveBlock2Ptr->frontier.pyramidRandoms[i];
    gSaveBlock2Ptr->frontier.pyramidTrainerFlags = sOldSaveBlock2Ptr->frontier.pyramidTrainerFlags;
    gSaveBlock2Ptr->frontier.pyramidBag = sOldSaveBlock2Ptr->frontier.pyramidBag;
    gSaveBlock2Ptr->frontier.pyramidLightRadius = sOldSaveBlock2Ptr->frontier.pyramidLightRadius;
    gSaveBlock2Ptr->frontier.verdanturfTentPrize = sOldSaveBlock2Ptr->frontier.verdanturfTentPrize;
    gSaveBlock2Ptr->frontier.fallarborTentPrize = sOldSaveBlock2Ptr->frontier.fallarborTentPrize;
    gSaveBlock2Ptr->frontier.slateportTentPrize = sOldSaveBlock2Ptr->frontier.slateportTentPrize;
    CpuCopy16(&sOldSaveBlock2Ptr->frontier.rentalMons, &gSaveBlock2Ptr->frontier.rentalMons, sizeof(gSaveBlock2Ptr->frontier.rentalMons));
    gSaveBlock2Ptr->frontier.battlePoints = sOldSaveBlock2Ptr->frontier.battlePoints;
    gSaveBlock2Ptr->frontier.cardBattlePoints = sOldSaveBlock2Ptr->frontier.cardBattlePoints;
    gSaveBlock2Ptr->frontier.battlesCount = sOldSaveBlock2Ptr->frontier.battlesCount;
    for(i = 0; i < min(ARRAY_COUNT(gSaveBlock2Ptr->frontier.domeWinningMoves), ARRAY_COUNT(sOldSaveBlock2Ptr->frontier.domeWinningMoves)); i++) gSaveBlock2Ptr->frontier.domeWinningMoves[i] = sOldSaveBlock2Ptr->frontier.domeWinningMoves[i];
    gSaveBlock2Ptr->frontier.trainerFlags = sOldSaveBlock2Ptr->frontier.trainerFlags;
    CpuCopy16(&sOldSaveBlock2Ptr->frontier.opponentNames, &gSaveBlock2Ptr->frontier.opponentNames, sizeof(gSaveBlock2Ptr->frontier.opponentNames));
    CpuCopy16(&sOldSaveBlock2Ptr->frontier.opponentTrainerIds, &gSaveBlock2Ptr->frontier.opponentTrainerIds, sizeof(gSaveBlock2Ptr->frontier.opponentTrainerIds));
    gSaveBlock2Ptr->frontier.unk_EF9 = sOldSaveBlock2Ptr->frontier.unk_EF9;
    gSaveBlock2Ptr->frontier.savedGame = sOldSaveBlock2Ptr->frontier.savedGame;
    gSaveBlock2Ptr->frontier.unused_EFA = sOldSaveBlock2Ptr->frontier.unused_EFA;
    gSaveBlock2Ptr->frontier.unused_EFB = sOldSaveBlock2Ptr->frontier.unused_EFB;
    CpuCopy16(&sOldSaveBlock2Ptr->frontier.domePlayerPartyData, &gSaveBlock2Ptr->frontier.domePlayerPartyData, sizeof(gSaveBlock2Ptr->frontier.domePlayerPartyData));

    // SaveBlock1 
    *gSaveBlock1Ptr = *sOldSaveBlock1Ptr;

    // PokemonStorage 
    *gPokemonStoragePtr = *sOldPokemonStoragePtr;

    SetContinueGameWarpStatus();
    gSaveBlock1Ptr->continueGameWarp = gSaveBlock1Ptr->lastHealLocation;

    return TRUE;
}
