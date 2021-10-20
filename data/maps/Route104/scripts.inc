Route104_MapScripts::
	.byte 0


Route104_EventScript_ExpertF::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_CHESTO_BERRY_ROUTE_104, Route104_EventScript_ExpertF_2
Route104_EventScript_ExpertF_1:
	msgbox Route104_EventScript_ExpertF_Text_1, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_ExpertF_2:
	msgbox Route104_EventScript_ExpertF_Text_0, MSGBOX_DEFAULT
	giveitem ITEM_ASPEAR_BERRY
	compare VAR_RESULT, FALSE
	goto_if_eq Route104_EventScript_ExpertF_4
	setflag FLAG_RECEIVED_CHESTO_BERRY_ROUTE_104
	goto Route104_EventScript_ExpertF_1

Route104_EventScript_ExpertF_4:
	goto Common_EventScript_ShowBagIsFull
	goto Route104_EventScript_ExpertF_1


Route104_Tori::
	msgbox Route104_Tori_Text_0, MSGBOX_NPC
	return


Route104_HillGirl::
	msgbox Route104_HillGirl_Text_0, MSGBOX_NPC
	return


Route104_WatersideDude::
	msgbox Route104_WatersideDude_Text_0, MSGBOX_NPC
	return


Route104_SurfRodBoy::
	msgbox Route104_SurfRodBoy_Text_0, MSGBOX_NPC
	return


Route104_ScaredGirl::
	msgbox Route104_ScaredGirl_Text_0, MSGBOX_NPC
	return


Route104_HappyBoy::
	msgbox Route104_HappyBoy_Text_0, MSGBOX_NPC
	return


Route104_HayFeverWoman::
	msgbox Route104_HayFeverWoman_Text_0, MSGBOX_NPC
	return


Route104_Sign_BoragoUp::
	msgbox Route104_Sign_BoragoUp_Text_0, MSGBOX_SIGN
	return


Route104_Sign_PoppyDown::
	msgbox Route104_Sign_PoppyDown_Text_0, MSGBOX_SIGN
	return


Route104_Sign_TrainerTips::
	msgbox Route104_Sign_TrainerTips_Text_0, MSGBOX_SIGN
	return


Route104_EventScript_Cindy::
	trainerbattle_single TRAINER_GRC_DAVE_1, Route104_EventScript_Cindy_Text_0, Route104_EventScript_Cindy_Text_1, Route104_EventScript_TryRegisterCindyAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route104_EventScript_Cindy_1
	setvar VAR_0x8004, TRAINER_GRC_DAVE_1
	specialvar VAR_RESULT, IsTrainerRegistered
	compare VAR_RESULT, FALSE
	goto_if_eq Route104_EventScript_Cindy_6
Route104_EventScript_Cindy_5:
	msgbox Route104_EventScript_Cindy_Text_5, MSGBOX_DEFAULT
	release
	return

Route104_EventScript_Cindy_1:
	trainerbattle_rematch TRAINER_GRC_DAVE_1, Route104_EventScript_Cindy_Text_2, Route104_EventScript_Cindy_Text_3
	msgbox Route104_EventScript_Cindy_Text_4, MSGBOX_AUTOCLOSE
	return

Route104_EventScript_Cindy_4:
	call Route104_EventScript_RegisterCindy
	return

Route104_EventScript_Cindy_6:
	goto_if_set FLAG_SYS_MATCH_CALL_GET, Route104_EventScript_Cindy_4
	goto Route104_EventScript_Cindy_5


Route104_EventScript_TryRegisterCindyAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_SYS_MATCH_CALL_GET, Route104_EventScript_TryRegisterCindyAfterBattle_2
Route104_EventScript_TryRegisterCindyAfterBattle_1:
	release
	return

Route104_EventScript_TryRegisterCindyAfterBattle_2:
	call Route104_EventScript_RegisterCindy
	goto Route104_EventScript_TryRegisterCindyAfterBattle_1


Route104_EventScript_RegisterCindy::
	msgbox Route104_EventScript_RegisterCindy_Text_0, MSGBOX_DEFAULT
	register_matchcall TRAINER_GRC_DAVE_1
	return


Route104_EventScript_Haley::
	trainerbattle_single TRAINER_GRC_ERIN_1, Route104_EventScript_Haley_Text_0, Route104_EventScript_Haley_Text_1, Route104_EventScript_TryRegisterHaleyAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route104_EventScript_Haley_1
	setvar VAR_0x8004, TRAINER_GRC_ERIN_1
	specialvar VAR_RESULT, IsTrainerRegistered
	compare VAR_RESULT, FALSE
	goto_if_eq Route104_EventScript_Haley_6
Route104_EventScript_Haley_5:
	msgbox Route104_EventScript_Haley_Text_5, MSGBOX_DEFAULT
	release
	return

Route104_EventScript_Haley_1:
	trainerbattle_rematch TRAINER_GRC_ERIN_1, Route104_EventScript_Haley_Text_2, Route104_EventScript_Haley_Text_3
	msgbox Route104_EventScript_Haley_Text_4, MSGBOX_AUTOCLOSE
	return

Route104_EventScript_Haley_4:
	call Route104_EventScript_RegisterHaley
	return

Route104_EventScript_Haley_6:
	goto_if_set FLAG_SYS_MATCH_CALL_GET, Route104_EventScript_Haley_4
	goto Route104_EventScript_Haley_5


Route104_EventScript_TryRegisterHaleyAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_SYS_MATCH_CALL_GET, Route104_EventScript_TryRegisterHaleyAfterBattle_2
Route104_EventScript_TryRegisterHaleyAfterBattle_1:
	release
	return

Route104_EventScript_TryRegisterHaleyAfterBattle_2:
	call Route104_EventScript_RegisterHaley
	goto Route104_EventScript_TryRegisterHaleyAfterBattle_1


Route104_EventScript_RegisterHaley::
	msgbox Route104_EventScript_RegisterCindy_Text_0, MSGBOX_DEFAULT
	register_matchcall TRAINER_GRC_ERIN_1
	return


Route104_EventScript_Winston::
	trainerbattle_single TRAINER_GRC_MAXIME_1, Route104_EventScript_Winston_Text_0, Route104_EventScript_Winston_Text_1, Route104_EventScript_TryRegisterWinstonAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route104_EventScript_Winston_1
	setvar VAR_0x8004, TRAINER_GRC_MAXIME_1
	specialvar VAR_RESULT, IsTrainerRegistered
	compare VAR_RESULT, FALSE
	goto_if_eq Route104_EventScript_Winston_6
Route104_EventScript_Winston_5:
	msgbox Route104_EventScript_Winston_Text_5, MSGBOX_DEFAULT
	release
	return

Route104_EventScript_Winston_1:
	trainerbattle_rematch TRAINER_GRC_MAXIME_1, Route104_EventScript_Winston_Text_2, Route104_EventScript_Winston_Text_3
	msgbox Route104_EventScript_Winston_Text_4, MSGBOX_AUTOCLOSE
	return

Route104_EventScript_Winston_4:
	call Route104_EventScript_RegisterWinston
	return

Route104_EventScript_Winston_6:
	goto_if_set FLAG_SYS_MATCH_CALL_GET, Route104_EventScript_Winston_4
	goto Route104_EventScript_Winston_5


Route104_EventScript_TryRegisterWinstonAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_SYS_MATCH_CALL_GET, Route104_EventScript_TryRegisterWinstonAfterBattle_2
Route104_EventScript_TryRegisterWinstonAfterBattle_1:
	release
	return

Route104_EventScript_TryRegisterWinstonAfterBattle_2:
	call Route104_EventScript_RegisterWinston
	goto Route104_EventScript_TryRegisterWinstonAfterBattle_1


Route104_EventScript_RegisterWinston::
	msgbox Route104_EventScript_RegisterWinston_Text_0, MSGBOX_DEFAULT
	register_matchcall TRAINER_GRC_MAXIME_1
	return


Route104_EventScript_Ivan::
	trainerbattle_single TRAINER_GRC_KYLE, Route104_EventScript_Ivan_Text_0, Route104_EventScript_Ivan_Text_1
	msgbox Route104_EventScript_Ivan_Text_2, MSGBOX_AUTOCLOSE
	return


Route104_EventScript_Billy::
	trainerbattle_single TRAINER_GRC_KRISSY, Route104_EventScript_Billy_Text_0, Route104_EventScript_Billy_Text_1
	msgbox Route104_EventScript_Billy_Text_2, MSGBOX_AUTOCLOSE
	return


Route104_EventScript_Darian::
	trainerbattle_single TRAINER_GRC_FINN, Route104_EventScript_Darian_Text_0, Route104_EventScript_Darian_Text_1
	msgbox Route104_EventScript_Darian_Text_2, MSGBOX_AUTOCLOSE
	return


Route104_EventScript_Gina::
	trainerbattle_double TRAINER_GRC_MEG_AND_MIA, Route104_EventScript_Gina_Text_0, Route104_EventScript_Gina_Text_1, Route104_EventScript_Gina_Text_2
	msgbox Route104_EventScript_Gina_Text_3, MSGBOX_AUTOCLOSE
	return


Route104_EventScript_Mia::
	trainerbattle_double TRAINER_GRC_MEG_AND_MIA, Route104_EventScript_Mia_Text_0, Route104_EventScript_Mia_Text_1, Route104_EventScript_Mia_Text_2
	msgbox Route104_EventScript_Mia_Text_3, MSGBOX_AUTOCLOSE
	return


@ NOTE: Route 104's sail to Dewford script references local IDs from Dewford's map. 
@  These are labeled in DewfordTown/scripts.inc
.set LOCALID_RIVAL, 34

@Route104_MapScripts::
@	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route104_OnFrame
@	map_script MAP_SCRIPT_ON_TRANSITION, Route104_OnTransition
@	.byte 0

Route104_OnFrame:
@	map_script_2 VAR_BOARD_BRINEY_BOAT_STATE, 1, Route104_EventScript_StartSailToDewford
@	.2byte 0

Route104_EventScript_StartSailToDewford::
@	lockall
@	goto Route104_EventScript_SailToDewford
@	end

Route104_OnTransition:
@	call Common_EventScript_SetupRivalGfxId
@	call Route104_EventScript_TrySetRivalPos
@	call Route104_EventScript_ShowOrHideWhiteHerbFlorist
@	end

Route104_EventScript_ShowOrHideWhiteHerbFlorist::
@	goto_if_unset FLAG_MET_PRETTY_PETAL_SHOP_OWNER, Route104_EventScript_HideWhiteHerbFlorist
@	goto_if_unset FLAG_BADGE03_GET, Route104_EventScript_HideWhiteHerbFlorist
@	clearflag FLAG_HIDE_ROUTE_104_WHITE_HERB_FLORIST
@	return

Route104_EventScript_HideWhiteHerbFlorist::
@	setflag FLAG_HIDE_ROUTE_104_WHITE_HERB_FLORIST
@	return

Route104_EventScript_TrySetRivalPos::
@	compare VAR_BOARD_BRINEY_BOAT_STATE, 1
@	goto_if_ge Route104_EventScript_DontSetRivalPos
@	goto_if_set FLAG_MET_RIVAL_RUSTBORO, Route104_EventScript_DontSetRivalPos
@	goto_if_unset FLAG_REGISTER_RIVAL_POKENAV, Route104_EventScript_DontSetRivalPos
@	setobjectxyperm LOCALID_RIVAL, 17, 52
@	return

Route104_EventScript_DontSetRivalPos::
@	return

Route104_EventScript_Rival::
@	lockall
@	setvar VAR_0x8008, 1
@	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
@	waitmovement 0
@	goto Route104_EventScript_RivalEncounter

Route104_EventScript_RivalTrigger::
@	lockall
@	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
@	setvar VAR_RUSTBORO_CITY_STATE, 8
@	setvar VAR_ROUTE104_STATE, 2
@	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
@	waitmovement 0
@	delay 10
@	addobject LOCALID_RIVAL
@	clearflag FLAG_GRC_HIDE_MUSKETEERS_BORAGO_GATE
@	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerBackUp
@	waitmovement 0
@	applymovement LOCALID_RIVAL, Route104_Movement_RivalExitBrineysCottage
@	waitmovement 0
@	delay 20
@	setvar VAR_0x8008, 0
@	call RustboroCity_EventScript_PlayRivalMusic
@	playse SE_PIN
@	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
@	waitmovement 0
@	applymovement LOCALID_RIVAL, Common_Movement_Delay48
@	waitmovement 0
@	goto Route104_EventScript_RivalEncounter

@ Unused, shares script with Rustboro encounter instead
Route104_EventScript_PlayRivalMusic::
@	checkplayergender
@	compare VAR_RESULT, MALE
@	goto_if_eq Route104_EventScript_PlayMayMusic
@	compare VAR_RESULT, FEMALE
@	goto_if_eq Route104_EventScript_PlayBrendanMusic
@	return

Route104_EventScript_PlayMayMusic::
@	playbgm MUS_ENCOUNTER_MAY, TRUE
@	return

Route104_EventScript_PlayBrendanMusic::
@	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
@	return

Route104_EventScript_RivalEncounter::
@	checkplayergender
@	compare VAR_RESULT, MALE
@	goto_if_eq Route104_EventScript_MayEncounter
@	compare VAR_RESULT, FEMALE
@	goto_if_eq Route104_EventScript_BrendanEncounter
@	end

Route104_EventScript_MayEncounter::
@	goto_if_set FLAG_DEFEATED_RIVAL_ROUTE_104, Route104_EventScript_MayDefeated
@	goto_if_set FLAG_REGISTER_RIVAL_POKENAV, Route104_EventScript_MayAskToBattle
@	setflag FLAG_REGISTER_RIVAL_POKENAV
@	msgbox Route104_Text_MayWeShouldRegister, MSGBOX_DEFAULT
@	closemessage
@	delay 30
@	playfanfare MUS_REGISTER_MATCH_CALL
@	msgbox Route104_Text_RegisteredMay, MSGBOX_DEFAULT
@	waitfanfare
@	closemessage
@	delay 30
@	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
@	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerFaceRival
@	applymovement LOCALID_RIVAL, Route104_Movement_RivalWalkSlowLeft
@	msgbox Route104_Text_MayHowsYourPokedex, MSGBOX_DEFAULT
@	closemessage
@	waitmovement 0
@	applymovement LOCALID_RIVAL, Route104_Movement_RivalApproachPlayer
@	waitmovement 0
@	copyobjectxytoperm LOCALID_RIVAL
@	msgbox Route104_Text_MayMinesDecentLetsBattle, MSGBOX_YESNO
@	compare VAR_RESULT, YES
@	goto_if_eq Route104_EventScript_BattleMay
@	msgbox Route104_Text_MayHaventRaisedPokemon, MSGBOX_DEFAULT
@	call Route104_EventScript_RestoreMusic
@	releaseall
@	end

Route104_Movement_RivalWalkSlowLeft:
@	walk_slow_left
@	step_end

Route104_Movement_RivalApproachPlayer:
@	walk_down
@	face_right
@	step_end

Route104_Movement_PlayerFaceRival:
@	delay_4
@	walk_in_place_fastest_left
@	step_end

Route104_EventScript_MayAskToBattle::
@	msgbox Route104_Text_MayLetsBattle, MSGBOX_YESNO
@	compare VAR_RESULT, YES
@	goto_if_eq Route104_EventScript_BattleMay
@	msgbox Route104_Text_MayHaventRaisedPokemon, MSGBOX_DEFAULT
@	releaseall
@	end

Route104_EventScript_BattleMay::
@	msgbox Route104_Text_MayIntro, MSGBOX_DEFAULT
@	switch VAR_STARTER_MON
@	case 0, Route104_EventScript_BattleMayTreecko
@	case 1, Route104_EventScript_BattleMayTorchic
@	case 2, Route104_EventScript_BattleMayMudkip
@	end

Route104_EventScript_MayDefeated::
@	msgbox Route104_Text_MayPostBattle, MSGBOX_DEFAULT
@	compare VAR_0x8008, 0
@	call_if_eq Route104_EventScript_RestoreMusic
@	releaseall
@	end

Route104_EventScript_RestoreMusic::
@	savebgm MUS_DUMMY
@	fadedefaultbgm
@	return

Route104_EventScript_BattleMayTreecko::
@	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TREECKO, Route104_Text_MayDefeat
@	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
@	goto Route104_EventScript_MayDefeated
@	end

Route104_EventScript_BattleMayTorchic::
@	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TORCHIC, Route104_Text_MayDefeat
@	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
@	goto Route104_EventScript_MayDefeated
@	end

Route104_EventScript_BattleMayMudkip::
@	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_MUDKIP, Route104_Text_MayDefeat
@	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
@	goto Route104_EventScript_MayDefeated
@	end

Route104_EventScript_BrendanEncounter::
@	goto_if_set FLAG_DEFEATED_RIVAL_ROUTE_104, Route104_EventScript_BrendanDefeated
@	goto_if_set FLAG_REGISTER_RIVAL_POKENAV, Route104_EventScript_BrendanAskToBattle
@	setflag FLAG_REGISTER_RIVAL_POKENAV
@	msgbox Route104_Text_BrendanWeShouldRegister, MSGBOX_DEFAULT
@	closemessage
@	delay 30
@	playfanfare MUS_REGISTER_MATCH_CALL
@	msgbox Route104_Text_RegisteredBrendan, MSGBOX_DEFAULT
@	waitfanfare
@	closemessage
@	delay 30
@	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
@	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerFaceRival
@	applymovement LOCALID_RIVAL, Route104_Movement_RivalWalkSlowLeft
@	msgbox Route104_Text_BrendanHowsYourPokedex, MSGBOX_DEFAULT
@	closemessage
@	waitmovement 0
@	applymovement LOCALID_RIVAL, Route104_Movement_RivalApproachPlayer
@	waitmovement 0
@	copyobjectxytoperm LOCALID_RIVAL
@	msgbox Route104_Text_BrendanDoingGreatLetsBattle, MSGBOX_YESNO
@	compare VAR_RESULT, YES
@	goto_if_eq Route104_EventScript_BattleBrendan
@	msgbox Route104_Text_BrendanNoConfidence, MSGBOX_DEFAULT
@	call Route104_EventScript_RestoreMusic
@	releaseall
@	end

Route104_EventScript_BrendanAskToBattle::
@	msgbox Route104_Text_BrendanLetsBattle, MSGBOX_YESNO
@	compare VAR_RESULT, YES
@	goto_if_eq Route104_EventScript_BattleBrendan
@	msgbox Route104_Text_BrendanNoConfidence, MSGBOX_DEFAULT
@	releaseall
@	end

Route104_EventScript_BattleBrendan::
@	msgbox Route104_Text_BrendanIntro, MSGBOX_DEFAULT
@	switch VAR_STARTER_MON
@	case 0, Route104_EventScript_BattleBrendanTreecko
@	case 1, Route104_EventScript_BattleBrendanTorchic
@	case 2, Route104_EventScript_BattleBrendanMudkip
@	end

Route104_EventScript_BrendanDefeated::
@	msgbox Route104_Text_BrendanPostBattle, MSGBOX_DEFAULT
@	compare VAR_0x8008, 0
@	call_if_eq Route104_EventScript_RestoreMusic
@	releaseall
@	end

Route104_EventScript_BattleBrendanTreecko::
@	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TREECKO, Route104_Text_BrendanDefeat
@	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
@	goto Route104_EventScript_BrendanDefeated
@	end

Route104_EventScript_BattleBrendanTorchic::
@	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TORCHIC, Route104_Text_BrendanDefeat
@	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
@	goto Route104_EventScript_BrendanDefeated
@	end

Route104_EventScript_BattleBrendanMudkip::
@	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_MUDKIP, Route104_Text_BrendanDefeat
@	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
@	goto Route104_EventScript_BrendanDefeated
@	end

Route104_Movement_PlayerBackUp:
@	lock_facing_direction
@	walk_down
@	unlock_facing_direction
@	step_end

Route104_Movement_RivalExitBrineysCottage:
@	walk_down
@	step_end

Route104_EventScript_WhiteHerbFlorist::
@	lock
@	faceplayer
@	goto_if_set FLAG_RECEIVED_WHITE_HERB, Route104_EventScript_ReceivedWhiteHerb
@	msgbox Route104_Text_DontNeedThisTakeIt, MSGBOX_DEFAULT
@	giveitem ITEM_WHITE_HERB
@	compare VAR_RESULT, FALSE
@	goto_if_eq Common_EventScript_ShowBagIsFull
@	setflag FLAG_RECEIVED_WHITE_HERB
@	release
@	end

Route104_EventScript_ReceivedWhiteHerb::
@	msgbox Route104_Text_FlowerShopSellingSaplings, MSGBOX_DEFAULT
@	release
@	end

Route104_EventScript_Girl1::
@	msgbox Route104_Text_BrineyLivesInSeasideCottage, MSGBOX_NPC
@	end

Route104_EventScript_BugCatcher::
@	msgbox Route104_Text_WhatsItLikeAtBottomOfSea, MSGBOX_SIGN
@	end

Route104_EventScript_BrineysCottageSign::
@	msgbox Route104_Text_MrBrineysCottage, MSGBOX_SIGN
@	end

Route104_EventScript_RouteSignPetalburg::
@	msgbox Route104_Text_RouteSignPetalburg, MSGBOX_SIGN
@	end

Route104_EventScript_RouteSignRustboro::
@	msgbox Route104_Text_RouteSignRustboro, MSGBOX_SIGN
@	end

Route104_EventScript_FlowerShopSign::
@	msgbox Route104_Text_PrettyPetalFlowShop, MSGBOX_SIGN
@	end

Route104_EventScript_TrainerTipsDoubleBattles::
@	msgbox Route104_Text_TrainerTipsDoubleBattles, MSGBOX_SIGN
@	end

Route104_EventScript_Boy1::
@	msgbox Route104_Text_ThrowBallAtWeakenedPokemon, MSGBOX_NPC
@	end

Route104_EventScript_Woman::
@	msgbox Route104_Text_OnlyThrowBallAtWildPokemon, MSGBOX_NPC
@	end

Route104_EventScript_Boy2::
@	lock
@	faceplayer
@	goto_if_set FLAG_RECEIVED_TM09, Route104_EventScript_ReceivedBulletSeed
@	msgbox Route104_Text_LikeFillingMouthWithSeedsTakeThis, MSGBOX_DEFAULT
@	giveitem ITEM_TM09
@	compare VAR_RESULT, FALSE
@	goto_if_eq Common_EventScript_ShowBagIsFull
@	setflag FLAG_RECEIVED_TM09
@	release
@	end

Route104_EventScript_ReceivedBulletSeed::
@	msgbox Route104_Text_TMsAreOneTimeUse, MSGBOX_DEFAULT
@	release
@	end

Route104_EventScript_Girl2::
@	msgbox Route104_Text_ImNotATrainer, MSGBOX_NPC
@	end

Route104_EventScript_SailToDewford::
@	setobjectpriority LOCALID_BRINEY_R104, MAP_ROUTE104, 0
@	setobjectpriority OBJ_EVENT_ID_PLAYER, MAP_ROUTE104, 0
@	applymovement LOCALID_BRINEY_R104, Route104_Movement_BrineyBoardBoat
@	waitmovement 0
@	removeobject LOCALID_BRINEY_R104
@	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerBoardBoat
@	waitmovement 0
@	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_ROUTE104
@	call Common_EventScript_PlayBrineysBoatMusic
@	goto_if_set FLAG_ENABLE_NORMAN_MATCH_CALL, Route104_EventScript_SailToDewfordNoCall
@	goto_if_unset FLAG_ENABLE_NORMAN_MATCH_CALL, Route104_EventScript_SailToDewfordDadCalls
@	end

Route104_EventScript_SailToDewfordNoCall::
@	applymovement LOCALID_BOAT_R104, Route104_Movement_SailToDewford
@	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_SailToDewford
@	waitmovement 0
@	goto Route104_EventScript_ArriveInDewford

Route104_EventScript_SailToDewfordDadCalls::
@	applymovement LOCALID_BOAT_R104, Route104_Movement_SailToDewfordBeforeDadCalls
@	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_SailToDewfordBeforeDadCalls
@	waitmovement 0
@	pokenavcall Route104_Text_DadPokenavCall
@	waitmessage
@	delay 30
@	playfanfare MUS_REGISTER_MATCH_CALL
@	msgbox Route104_Text_RegisteredDadInPokenav, MSGBOX_DEFAULT
@	waitfanfare
@	closemessage
@	delay 30
@	setflag FLAG_ENABLE_NORMAN_MATCH_CALL
@	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_SailToDewfordAfterDadCalls
@	applymovement LOCALID_BOAT_R104, Route104_Movement_SailToDewfordAfterDadCalls, MAP_ROUTE104
@	waitmovement LOCALID_BOAT_R104, MAP_ROUTE104
@	waitmovement 0
@	goto Route104_EventScript_ArriveInDewford

Route104_EventScript_ArriveInDewford::
@	delay 50
@	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerExitBoat
@	waitmovement 0
@	call Common_EventScript_StopBrineysBoatMusic
@	showobjectat OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN
@	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerMoveForBriney
@	waitmovement 0
@	setobjectxyperm LOCALID_BRINEY_DEWFORD, 12, 8
@	addobject LOCALID_BRINEY_DEWFORD
@	setobjectpriority LOCALID_BRINEY_DEWFORD, MAP_DEWFORD_TOWN, 0
@	clearflag FLAG_GRC_HIDE_RIVAL_POPPY
@	applymovement LOCALID_BRINEY_DEWFORD, Route104_Movement_BrineyExitBoat
@	waitmovement 0
@	addobject LOCALID_BOAT_DEWFORD
@	clearflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
@	call Common_EventScript_StopBrineysBoatMusic
@	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
@	hideobjectat LOCALID_BOAT_R104, MAP_ROUTE104
@	copyvar VAR_BRINEY_LOCATION, VAR_0x8008
@	resetobjectpriority OBJ_EVENT_ID_PLAYER, MAP_ROUTE104
@	resetobjectpriority LOCALID_BRINEY_DEWFORD, MAP_DEWFORD_TOWN
@	copyobjectxytoperm LOCALID_BRINEY_DEWFORD
@	setvar VAR_BOARD_BRINEY_BOAT_STATE, 0
@	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, Route104_EventScript_DeliverLetterReminder
@	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, Route104_EventScript_LandedInDewford
@	end

Route104_EventScript_DeliverLetterReminder::
@	msgbox Route104_Text_LandedInDewfordDeliverLetter, MSGBOX_DEFAULT
@	releaseall
@	end

Route104_EventScript_LandedInDewford::
@	msgbox DewfordTown_Text_BrineyLandedInDewford, MSGBOX_DEFAULT
@	releaseall
@	end

Route104_Movement_SailToDewfordBeforeDadCalls:
@	walk_down
@	walk_down
@	walk_down
@	walk_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_right
@	walk_fast_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fast_right
@	walk_fast_right
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	step_end

Route104_Movement_SailToDewfordAfterDadCalls:
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_right
@	walk_fast_right
@	walk_fast_right
@	walk_fast_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fast_right
@	walk_fast_right
@	walk_fast_right
@	walk_fast_right
@	walk_right
@	walk_right
@	walk_down
@	walk_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_down
@	walk_down
@	step_end

Route104_Movement_SailToDewford:
@	walk_down
@	walk_down
@	walk_down
@	walk_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_right
@	walk_fast_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fast_right
@	walk_fast_right
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fastest_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_right
@	walk_fast_right
@	walk_fast_right
@	walk_fast_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fastest_right
@	walk_fast_right
@	walk_fast_right
@	walk_fast_right
@	walk_fast_right
@	walk_right
@	walk_right
@	walk_down
@	walk_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	walk_down
@	walk_down
@	step_end

Route104_Movement_PlayerBoardBoat:
@	walk_left
@	walk_down
@	walk_down
@	step_end

Route104_Movement_PlayerExitBoat:
@	walk_down
@	step_end

Route104_Movement_PlayerMoveForBriney:
@	walk_down
@	walk_left
@	walk_in_place_fastest_right
@	step_end

Route104_Movement_BrineyBoardBoat:
@	walk_down
@	walk_down
@	step_end

Route104_Movement_BrineyExitBoat:
@	walk_down
@	walk_in_place_fastest_left
@	step_end

Route104_Text_BrineyLivesInSeasideCottage:
@	.string "That seaside cottage is where\n"
@	.string "MR. BRINEY lives.\p"
@	.string "He was once a mighty sailor who never\n"
@	.string "feared the sea, however stormy.$"

Route104_Text_WhatsItLikeAtBottomOfSea:
@	.string "The sea, huh?\p"
@	.string "I wonder what it's like at the bottom\n"
@	.string "of the sea?$"

Route104_Text_ThrowBallAtWeakenedPokemon:
@	.string "If you're going to throw a POKé BALL,\n"
@	.string "weaken the wild POKéMON first.\p"
@	.string "It will be easier to catch if it's been\n"
@	.string "poisoned, burned, or lulled to sleep.$"

Route104_Text_OnlyThrowBallAtWildPokemon:
@	.string "You're a thief if you try to steal\n"
@	.string "someone else's POKéMON.\p"
@	.string "You should throw POKé BALLS only at\n"
@	.string "wild POKéMON.$"

Route104_Text_ImNotATrainer:
@	.string "Oh, no, I'm not a TRAINER.\p"
@	.string "But that's right, if TRAINERS lock eyes,\n"
@	.string "it's a challenge to battle.\p"
@	.string "If you don't want to battle, stay out\n"
@	.string "of their sight.$"

Route104_Text_LikeFillingMouthWithSeedsTakeThis:
@	.string "I like filling my mouth with seeds,\n"
@	.string "then spitting them out fast!\p"
@	.string "You can have this, so you try it out!\p"
@	.string "Use it on a POKéMON, and it will learn\n"
@	.string "a move for firing seeds rapidly.$"

Route104_Text_TMsAreOneTimeUse:
@	.string "A word of advice!\p"
@	.string "A TM, TECHNICAL MACHINE, is good only\n"
@	.string "for one-time use.\p"
@	.string "Once you use it, it's gone.\n"
@	.string "Think twice before using it!$"

Route104_Text_DontNeedThisTakeIt:
@	.string "This FLOWER SHOP started selling\n"
@	.string "saplings recently.\p"
@	.string "It made me so happy, I went overboard\n"
@	.string "shopping.\p"
@	.string "I don't need this WHITE HERB anymore.\n"
@	.string "Would you take it, please?$"

Route104_Text_FlowerShopSellingSaplings:
@	.string "This FLOWER SHOP started selling\n"
@	.string "saplings recently.\p"
@	.string "It made me so happy, I went overboard\n"
@	.string "shopping. Where should I put them?$"

Route104_Text_MrBrineysCottage:
@	.string "MR. BRINEY'S COTTAGE$"

Route104_Text_RouteSignPetalburg:
@	.string "ROUTE 1O4\n"
@	.string "{RIGHT_ARROW} PETALBURG CITY$"

Route104_Text_RouteSignRustboro:
@	.string "ROUTE 1O4\n"
@	.string "{UP_ARROW} RUSTBORO CITY$"

Route104_Text_PrettyPetalFlowShop:
@	.string "PRETTY PETAL FLOWER SHOP$"

Route104_Text_TrainerTipsDoubleBattles:
@	.string "TRAINER TIPS\p"
@	.string "In the HOENN region there are pairs\n"
@	.string "of TRAINERS who challenge others\l"
@	.string "for 2-on-2 POKéMON battles called\l"
@	.string "DOUBLE BATTLES.\p"
@	.string "In a DOUBLE BATTLE, the TRAINER must\n"
@	.string "send out two POKéMON, the one at the\l"
@	.string "left of the list and the top one.\l"
@	.string "Watch how POKéMON are lined up.$"

Route104_Text_MayWeShouldRegister:
@	.string "MAY: Oh, hi, {PLAYER}{KUN}!\p"
@	.string "DEVON upgraded your POKéNAV with\n"
@	.string "the MATCH CALL system, huh?\p"
@	.string "We should register each other so we\n"
@	.string "can get in contact anytime.$"

Route104_Text_RegisteredMay:
@	.string "{PLAYER} registered MAY\n"
@	.string "in the POKéNAV.$"

Route104_Text_MayHowsYourPokedex:
@	.string "MAY: Oh, by the way, {PLAYER}{KUN},\n"
@	.string "how's your POKéDEX coming along?$"

Route104_Text_MayMinesDecentLetsBattle:
@	.string "Mine's looking pretty decent.\n"
@	.string "So…\l"
@	.string "How about a little battle?$"

Route104_Text_MayHaventRaisedPokemon:
@	.string "MAY: Oh, what's the matter?\p"
@	.string "Haven't you caught or raised your\n"
@	.string "POKéMON very much?\p"
@	.string "That's not very good for a TRAINER!$"

Route104_Text_MayLetsBattle:
@	.string "MAY: So, what do you think?\n"
@	.string "How about a little battle here?$"

Route104_Text_MayIntro:
@	.string "MAY: You just became a TRAINER,\n"
@	.string "{PLAYER}{KUN}. I'm not going to lose!$"

Route104_Text_MayDefeat:
@	.string "Yikes!\n"
@	.string "You're better than I expected!$"

Route104_Text_MayPostBattle:
@	.string "MAY: I can tell you've gotten pretty\n"
@	.string "good with the way you handle POKéMON.\p"
@	.string "But instead of only making them\n"
@	.string "battle, you should be like MR. BRINEY.\p"
@	.string "It's important to become friends with\n"
@	.string "POKéMON, too.$"

Route104_Text_BrendanWeShouldRegister:
@	.string "BRENDAN: Oh, hey, {PLAYER}!\p"
@	.string "Cool, you had DEVON install the MATCH\n"
@	.string "CALL system on your POKéNAV!\p"
@	.string "Let's register each other in our\n"
@	.string "POKéNAVS so we can keep in touch.$"

Route104_Text_RegisteredBrendan:
@	.string "{PLAYER} registered BRENDAN\n"
@	.string "in the POKéNAV.$"

Route104_Text_BrendanHowsYourPokedex:
@	.string "BRENDAN: {PLAYER}, how's your POKéDEX?\n"
@	.string "Have you filled in any pages yet?$"

Route104_Text_BrendanDoingGreatLetsBattle:
@	.string "Me, I'm doing great!\p"
@	.string "Want to check out how good I am with\n"
@	.string "a battle?$"

Route104_Text_BrendanNoConfidence:
@	.string "BRENDAN: What's the matter? Don't have\n"
@	.string "any confidence in your POKéMON?$"

Route104_Text_BrendanLetsBattle:
@	.string "BRENDAN: What's up?\n"
@	.string "Want to have a battle with me?$"

Route104_Text_BrendanIntro:
@	.string "BRENDAN: I know you just became\n"
@	.string "a TRAINER, but I won't go easy!$"

Route104_Text_BrendanDefeat:
@	.string "Hmm…\n"
@	.string "You're pretty good.$"

Route104_Text_BrendanPostBattle:
@	.string "BRENDAN: You've gotten pretty decent\n"
@	.string "at handling POKéMON.\p"
@	.string "But, you know, you shouldn't just be\n"
@	.string "making POKéMON battle.\p"
@	.string "Like MR. BRINEY, it's important to\n"
@	.string "become friends with your POKéMON.$"

Route104_EventScript_ExpertF_Text_0:
	.string "Berries make the world a more beautiful\n"
	.string "place. They are like nature's own\l"
	.string "jewels.\p"
	.string "Here, I'll share one with you!$"

Route104_EventScript_ExpertF_Text_1:
	.string "You can help make the world lovelier by\n"
	.string "tending to Berries with love and care.\p"
	.string "Always remember to give back what you\n"
	.string "take from the earth!$"

Route104_Tori_Text_0:
	.string "Oh. Hi, {PLAYER}. I'm not in the mood to\n"
	.string "fight you, so don't bother asking.\p"
	.string "I'm just trying to see if I can catch\n"
	.string "something nice here. See ya.$"

Route104_HillGirl_Text_0:
	.string "Do you see that sandy hill? No matter\n"
	.string "how often I try to mount it, I just\l"
	.string "keep falling back.\p"
	.string "Maybe if I could just go faster…$"

Route104_WatersideDude_Text_0:
	.string "Ahh, nothing's better for the old bones\n"
	.string "than taking a nice, long stroll!\p"
	.string "If only more of those young\n"
	.string "whippersnappers were more like you…\p"
	.string "Nothing good'll come of sitting around\n"
	.string "all day.$"

Route104_SurfRodBoy_Text_0:
	.string "Some Pokémon can only be found if you\n"
	.string "cross the water or use a fishing rod.\p"
	.string "I don't know what lies on the other\n"
	.string "side, but I'm itching to find out! Agh,\l"
	.string "it's driving me nuts!$"

Route104_ScaredGirl_Text_0:
	.string "I wanna go to the city! But I have to\n"
	.string "cross the forest to get there, and I\l"
	.string "really don't like Bug Pokémon… Eww…$"

Route104_HappyBoy_Text_0:
	.string "Wheeeeee! Today's a nice day.$"

Route104_HayFeverWoman_Text_0:
	.string "Ah, achoo! If only I didn't have this hay\n"
	.string "fever, I could enjoy the flowers and\l"
	.string "the trees…$"

Route104_Sign_BoragoUp_Text_0:
	.string "{UP_ARROW} Borago City$"

Route104_Sign_PoppyDown_Text_0:
	.string "{DOWN_ARROW} Poppy Town$"

Route104_Sign_TrainerTips_Text_0:
	.string "Trainer Tips! If you have any Poké Balls\n"
	.string "on you, press {R_BUTTON} to instantly throw\l"
	.string "another Ball of the same kind without\l"
	.string "having to browse through your Bag.$"

Route104_EventScript_Cindy_Text_0:
	.string "Hey, you know what happens when\n"
	.string "Trainers meet?\p"
	.string "Yeah, you do. Let's get this show on the\n"
	.string "road!$"

Route104_EventScript_Cindy_Text_1:
	.string "Whoa, you're strong stuff! I couldn't\n"
	.string "measure up…$"

Route104_EventScript_Cindy_Text_2:
	.string "Hey, you know what? Me and my Pokémon\n"
	.string "have gotten stronger since last time!\p"
	.string "Let's get this show on the road!$"

Route104_EventScript_Cindy_Text_3:
	.string "Aw, seriously? Guess I gotta train\n"
	.string "harder…$"

Route104_EventScript_Cindy_Text_4:
	.string "I shouldn't be rushing myself or my\n"
	.string "Pokémon. We may have a long way to go,\l"
	.string "but we'll get there in time. I shouldn't\l"
	.string "lose sight of that.$"

Route104_EventScript_Cindy_Text_5:
	.string "I gotta get stronger. Someday, I wanna\n"
	.string "challenge the best of the best… and\l"
	.string "come out on top! You just watch!$"

Route104_EventScript_RegisterCindy_Text_0:
	.string "Oh, hey! You got a P-Drive? Why don't I\n"
	.string "give you my number?\p"
	.string "I'll call you if I'm feeling like fighting\n"
	.string "you again!$"

Route104_EventScript_Haley_Text_0:
	.string "Huh? Wait, my training spot's been\n"
	.string "found! Well, I've been looking for a\l"
	.string "challenge, so I hope you won't let me\l"
	.string "down!$"

Route104_EventScript_Haley_Text_1:
	.string "Whew! Talk about a workout…$"

Route104_EventScript_Haley_Text_2:
	.string "My Pokémon and I have been pushing our\n"
	.string "limits all the time. I've been looking\l"
	.string "forward to this match!$"

Route104_EventScript_Haley_Text_3:
	.string "Clearly, you've been going the extra\n"
	.string "mile…$"

Route104_EventScript_Haley_Text_4:
	.string "Having someone like you around helps\n"
	.string "keep me sharp. You don't know how much\l"
	.string "I appreciate that, {PLAYER}.$"

Route104_EventScript_Haley_Text_5:
	.string "That was fun! I'll let you know when I'm\n"
	.string "ready for the next round, okay? Look\l"
	.string "forward to it!$"

Route104_EventScript_Winston_Text_0:
	.string "My grandpappy gave me this Pokémon as\n"
	.string "a birthday gift. Allow me to\l"
	.string "demonstrate how a proper Pokémon\l"
	.string "fights!$"

Route104_EventScript_Winston_Text_1:
	.string "Wh-whaaaaat?! No! Its feathers are all\n"
	.string "ruffled now… Sob… Grandpappy…$"

Route104_EventScript_Winston_Text_2:
	.string "Well, well! You have arrived! This time,\n"
	.string "my superior care shall see us through!$"

Route104_EventScript_Winston_Text_3:
	.string "Ah… well. Hmm. Something must have gone\n"
	.string "amiss.$"

Route104_EventScript_Winston_Text_4:
	.string "My grandpappy is growing old. That's why\n"
	.string "I cherish Noctowl so.\p"
	.string "It was his birthday gift to me, and it\n"
	.string "has been my best friend since./pI don't\l"
	.string "think I could have asked for a better\l"
	.string "gift than that.$"

Route104_EventScript_Winston_Text_5:
	.string "Hmm… Perhaps I should explore\n"
	.string "Contests. A podium is a better fit than\l"
	.string "a battlefield.$"

Route104_EventScript_RegisterWinston_Text_0:
	.string "Excuse me! You! I demand your number.\n"
	.string "This will not be the last time we have\l"
	.string "crossed paths!$"

Route104_EventScript_Ivan_Text_0:
	.string "Ready or not, we're gonna kick your\n"
	.string "butt!$"

Route104_EventScript_Ivan_Text_1:
	.string "Ow, ow, ow! Uncle! I said Uncle!$"

Route104_EventScript_Ivan_Text_2:
	.string "I was always the toughest kid on the\n"
	.string "block. Guess there's bigger fish in the\l"
	.string "pond now, huh?$"

Route104_EventScript_Billy_Text_0:
	.string "My Pokémon are the cutest! But they're\n"
	.string "even stronger than they're cute!$"

Route104_EventScript_Billy_Text_1:
	.string "No! My little cuties! Are you okay?!$"

Route104_EventScript_Billy_Text_2:
	.string "I like to pamper my Pokémon, especially\n"
	.string "since they always do their best for me.\l"
	.string "They're the best!$"

Route104_EventScript_Darian_Text_0:
	.string "Aw, dang it! I almost had that fish!\n"
	.string "Urgh, if only you weren't there to ruin\l"
	.string "my catch!\p"
	.string "I'll just have to take it out on you!$"

Route104_EventScript_Darian_Text_1:
	.string "Phew… maybe I needed that. Thanks.$"

Route104_EventScript_Darian_Text_2:
	.string "It's not easy, being a fisherman. If we\n"
	.string "don't get our catch, we won't have food\l"
	.string "on the table.\p"
	.string "That's why we can be grumpy at times.\n"
	.string "Don't take it personally, kid.$"

Route104_EventScript_Gina_Text_0:
	.string "Hi, I'm Meg! And this is my sister Mia!\n"
	.string "Together, we can't be stopped!$"

Route104_EventScript_Gina_Text_1:
	.string "Aww. But that was fun!$"

Route104_EventScript_Gina_Text_2:
	.string "Uh-oh! We can't fight you if you don't\n"
	.string "have two Pokémon!$"

Route104_EventScript_Gina_Text_3:
	.string "We're twins! That means we're super in\n"
	.string "sync all the time. That's why we're such\l"
	.string "a good combo!$"

Route104_EventScript_Mia_Text_0:
	.string "My name's Mia! And this is Meg, my sis! We\n"
	.string "can beat anyone together!$"

Route104_EventScript_Mia_Text_1:
	.string "That was fun! Right?$"

Route104_EventScript_Mia_Text_2:
	.string "Two against one isn't fair. Can you\n"
	.string "bring another Pokémon?$"

Route104_EventScript_Mia_Text_3:
	.string "Sometimes, we get weird looks because\n"
	.string "Meg and I are so in sync. Not like we\l"
	.string "really mind!$"
