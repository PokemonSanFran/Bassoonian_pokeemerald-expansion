LittlerootTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Turpia_Outside_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Turpia_Outside_OnFrame
	.byte 0


EventScript_HMFlyPole::
	msgbox EventScript_HMFlyPole_Text_0, MSGBOX_SIGN
	return


Turpia_Outside_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	call Turpia_ShowRivals_Start_Movement
	setflag FLAG_VISITED_LITTLEROOT_TOWN
	end
	
Turpia_Outside_OnFrame:
	map_script_2 VAR_GRC_TURPIA_INTRO_STATE, 4, Turpia_ProtaSquad_A
	map_script_2 VAR_GRC_TURPIA_INTRO_STATE, 5, Turpia_ProtaSquad_B
	map_script_2 VAR_GRC_TURPIA_INTRO_STATE, 6, Turpia_Celebration
	.2byte 0

Turpia_SloganBoard::
	msgbox Turpia_SloganBoard_Text_0, MSGBOX_SIGN
	return


Turpia_FulgurSign::
	goto_if_unset FLAG_GRC_TURPIA_HIDE_PARENTS, Turpia_FulgurSign_1
	msgbox Turpia_FulgurSign_Text_1, MSGBOX_SIGN
	return

Turpia_FulgurSign_1:
	msgbox Turpia_FulgurSign_Text_0, MSGBOX_SIGN
	return


Turpia_FlammaSign::
	goto_if_unset FLAG_GRC_TURPIA_HIDE_PARENTS, Turpia_FlammaSign_1
	msgbox Turpia_FlammaSign_Text_1, MSGBOX_SIGN
	return

Turpia_FlammaSign_1:
	msgbox Turpia_FlammaSign_Text_0, MSGBOX_SIGN
	return


Turpia_LacusSign::
	goto_if_unset FLAG_GRC_TURPIA_HIDE_PARENTS, Turpia_LacusSign_1
	msgbox Turpia_LacusSign_Text_1, MSGBOX_SIGN
	return

Turpia_LacusSign_1:
	msgbox Turpia_LacusSign_Text_0, MSGBOX_SIGN
	return


Turpia_FractalSign::
	msgbox Turpia_FractalSign_Text_0, MSGBOX_SIGN
	return


Turpia_SpruceWhileBagPick::
	msgbox Turpia_SpruceWhileBagPick_Text_0, MSGBOX_NPC
	return


Turpia_DontRunAway::
	lockall
	applymovement 9, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox Turpia_DontRunAway_Text_0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	applymovement 9, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	releaseall
	return


Turpia_Celebration::
	lockall
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_GRC_TURPIA_INTRO_STATE, 7
	clearflag FLAG_SYS_POKEMON_GET
	setflag FLAG_GRC_R1_HIDE_BADDIES
	applymovement 9, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox Turpia_Celebration_Text_0
	closemessage
	msgbox Turpia_Celebration_Text_1
	closemessage
	msgbox Turpia_Celebration_Text_2
	closemessage
	applymovement 9, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox Turpia_Celebration_Text_3
	closemessage
	applymovement 9, Turpia_Prof_MovesUp
	waitmovement 0
	addobject 10
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	applymovement 6, Common_Movement_WalkInPlaceFastestLeft
	applymovement 7, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox Turpia_Celebration_Text_4
	closemessage
	applymovement 9, Turpia_Prof_MovesSide
	waitmovement 0
	applymovement 6, Common_Movement_WalkLeft
	applymovement 7, Turpia_Rival_MovesToBox
	waitmovement 0
	applymovement 6, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox Turpia_Celebration_Text_5
	closemessage
	applymovement 7, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	getpartysize
	compare VAR_RESULT, 0
	goto_if_eq Turpia_Celebration_2
	compare VAR_RESULT, 1
	goto_if_eq Turpia_Celebration_3
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Turpia_Celebration_16
	msgbox Turpia_Celebration_Text_17
Turpia_Celebration_15:
	closemessage
	applymovement 6, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox Turpia_Celebration_Text_18
	closemessage
	applymovement 7, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	compare VAR_RESULT, MALE
	goto_if_eq Turpia_Celebration_25
	msgbox Turpia_Celebration_Text_20
Turpia_Celebration_1:
	closemessage
	releaseall
	end

Turpia_Celebration_2:
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Turpia_Celebration_8
	msgbox Turpia_Celebration_Text_7
Turpia_Celebration_7:
	closemessage
	applymovement 6, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox Turpia_Celebration_Text_8
	closemessage
	applymovement 7, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	compare VAR_RESULT, MALE
	goto_if_eq Turpia_Celebration_19
	msgbox Turpia_Celebration_Text_10
	goto Turpia_Celebration_1

Turpia_Celebration_3:
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Turpia_Celebration_12
	msgbox Turpia_Celebration_Text_12
Turpia_Celebration_11:
	closemessage
	applymovement 6, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox Turpia_Celebration_Text_13
	closemessage
	applymovement 7, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	compare VAR_RESULT, MALE
	goto_if_eq Turpia_Celebration_22
	msgbox Turpia_Celebration_Text_15
	goto Turpia_Celebration_1

Turpia_Celebration_8:
	msgbox Turpia_Celebration_Text_6
	goto Turpia_Celebration_7

Turpia_Celebration_12:
	msgbox Turpia_Celebration_Text_11
	goto Turpia_Celebration_11

Turpia_Celebration_16:
	msgbox Turpia_Celebration_Text_16
	goto Turpia_Celebration_15

Turpia_Celebration_19:
	msgbox Turpia_Celebration_Text_9
	goto Turpia_Celebration_1

Turpia_Celebration_22:
	msgbox Turpia_Celebration_Text_14
	goto Turpia_Celebration_1

Turpia_Celebration_25:
	msgbox Turpia_Celebration_Text_19
	goto Turpia_Celebration_1


Turpia_BagPickStarter::
	lockall
	special FullPartyToPC
	fadescreen FADE_TO_BLACK
	special ChooseStarter
	waitstate
	bufferleadmonspeciesname 0
	applymovement 9, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	message Turpia_BagPickStarter_Text_0
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	applymovement 9, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox Turpia_BagPickStarter_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_ne Turpia_BagPickStarter_2
Turpia_BagPickStarter_1:
	switch VAR_STARTER_MON
	case 0, Turpia_BagPickStarter_6
	case 1, Turpia_BagPickStarter_7
	case 2, Turpia_BagPickStarter_8
Turpia_BagPickStarter_4:
	applymovement 7, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Turpia_BagPickStarter_10
	message Turpia_BagPickStarter_Text_3
Turpia_BagPickStarter_9:
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	applymovement 6, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	message Turpia_BagPickStarter_Text_4
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	playse SE_POKENAV_ON
	delay 30
	applymovement 9, Common_Movement_ExclamationMark
	waitmovement 0
	delay 30
	playse SE_POKENAV_OFF
	applymovement 9, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox Turpia_BagPickStarter_Text_5
	closemessage
	applymovement 9, Common_Movement_WalkRight
	applymovement OBJ_EVENT_ID_PLAYER, Turpia_Prof_MovesUp
	waitmovement 0
	removeobject 10
	applymovement 9, Turpia_Prof_Runsoff
	waitmovement 0
	removeobject 9
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
	applymovement OBJ_EVENT_ID_PLAYER, Turpia_PlayerMovesBackIntoPosition
	waitmovement 0
	applymovement 7, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Turpia_BagPickStarter_14
	msgbox Turpia_BagPickStarter_Text_7
Turpia_BagPickStarter_13:
	closemessage
	applymovement 6, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox Turpia_BagPickStarter_Text_8
	closemessage
	applymovement 7, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	compare VAR_RESULT, MALE
	goto_if_eq Turpia_BagPickStarter_18
	msgbox Turpia_BagPickStarter_Text_10
Turpia_BagPickStarter_17:
	closemessage
	applymovement 6, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox Turpia_BagPickStarter_Text_11
	closemessage
	switch VAR_STARTER_MON
	case 0, Turpia_BagPickStarter_22
	case 1, Turpia_BagPickStarter_23
	case 2, Turpia_BagPickStarter_24
	return

Turpia_BagPickStarter_2:
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	goto Turpia_BagPickStarter_1

Turpia_BagPickStarter_6:
	bufferspeciesname 1, SPECIES_TORCHIC
	bufferspeciesname 2, SPECIES_MUDKIP
	goto Turpia_BagPickStarter_4

Turpia_BagPickStarter_7:
	bufferspeciesname 1, SPECIES_MUDKIP
	bufferspeciesname 2, SPECIES_TREECKO
	goto Turpia_BagPickStarter_4

Turpia_BagPickStarter_8:
	bufferspeciesname 1, SPECIES_TREECKO
	bufferspeciesname 2, SPECIES_TORCHIC
	goto Turpia_BagPickStarter_4

Turpia_BagPickStarter_10:
	message Turpia_BagPickStarter_Text_2
	goto Turpia_BagPickStarter_9

Turpia_BagPickStarter_14:
	msgbox Turpia_BagPickStarter_Text_6
	goto Turpia_BagPickStarter_13

Turpia_BagPickStarter_18:
	msgbox Turpia_BagPickStarter_Text_9
	goto Turpia_BagPickStarter_17

Turpia_BagPickStarter_22:
	trainerbattle_continue_after_lose TRAINER_GRC_TORI_TURPIA_TREECKO, 0, Turpia_Defeat_Tori, Turpia_Celebration_Cont_A
	return

Turpia_BagPickStarter_23:
	trainerbattle_continue_after_lose TRAINER_GRC_TORI_TURPIA_TORCHIC, 0, Turpia_Defeat_Tori, Turpia_Celebration_Cont_A
	return

Turpia_BagPickStarter_24:
	trainerbattle_continue_after_lose TRAINER_GRC_TORI_TURPIA_MUDKIP, 0, Turpia_Defeat_Tori, Turpia_Celebration_Cont_A
	return


Turpia_PlayerMovesBackIntoPosition:
	walk_down
	walk_in_place_fastest_right
	step_end

Turpia_Celebration_Cont_A::
	special HealPlayerParty
	applymovement 7, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Turpia_Celebration_Cont_A_2
	msgbox Turpia_Celebration_Cont_A_Text_1
Turpia_Celebration_Cont_A_1:
	closemessage
	compare VAR_RESULT, MALE
	goto_if_eq Turpia_Celebration_Cont_A_5
	switch VAR_STARTER_MON
	case 0, Turpia_Celebration_Cont_A_13
	case 1, Turpia_Celebration_Cont_A_14
	case 2, Turpia_Celebration_Cont_A_15
	return

Turpia_Celebration_Cont_A_2:
	msgbox Turpia_Celebration_Cont_A_Text_0
	goto Turpia_Celebration_Cont_A_1

Turpia_Celebration_Cont_A_5:
	switch VAR_STARTER_MON
	case 0, Turpia_Celebration_Cont_A_9
	case 1, Turpia_Celebration_Cont_A_10
	case 2, Turpia_Celebration_Cont_A_11
	return

Turpia_Celebration_Cont_A_9:
	trainerbattle_continue_after_lose TRAINER_GRC_ALYSSA_TURPIA_TREECKO, 0, Turpia_Defeat_Alyssa, Turia_Celebration_Cont_B
	return

Turpia_Celebration_Cont_A_10:
	trainerbattle_continue_after_lose TRAINER_GRC_ALYSSA_TURPIA_TORCHIC, 0, Turpia_Defeat_Alyssa, Turia_Celebration_Cont_B
	return

Turpia_Celebration_Cont_A_11:
	trainerbattle_continue_after_lose TRAINER_GRC_ALYSSA_TURPIA_MUDKIP, 0, Turpia_Defeat_Alyssa, Turia_Celebration_Cont_B
	return

Turpia_Celebration_Cont_A_13:
	trainerbattle_continue_after_lose TRAINER_GRC_BASIL_TURPIA_TREECKO, 0, Turpia_Defeat_Basil, Turia_Celebration_Cont_B
	return

Turpia_Celebration_Cont_A_14:
	trainerbattle_continue_after_lose TRAINER_GRC_BASIL_TURPIA_TORCHIC, 0, Turpia_Defeat_Basil, Turia_Celebration_Cont_B
	return

Turpia_Celebration_Cont_A_15:
	trainerbattle_continue_after_lose TRAINER_GRC_BASIL_TURPIA_MUDKIP, 0, Turpia_Defeat_Basil, Turia_Celebration_Cont_B
	return


Turia_Celebration_Cont_B::
	special HealPlayerParty
	applymovement 7, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Turia_Celebration_Cont_B_2
	msgbox Turia_Celebration_Cont_B_Text_1
Turia_Celebration_Cont_B_1:
	closemessage
	applymovement 7, Turpia_Rival_RunsOff
	waitmovement 0
	removeobject 7
	applymovement 6, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	compare VAR_RESULT, MALE
	goto_if_eq Turia_Celebration_Cont_B_6
	msgbox Turia_Celebration_Cont_B_Text_3
Turia_Celebration_Cont_B_5:
	closemessage
	applymovement 6, Turpia_Tori_RunsOff
	waitmovement 0
	removeobject 6
	setflag FLAG_GRC_TURPIA_HIDE_RIVALS
	setflag FLAG_GRC_R1_HIDE_RIVALS
	clearflag FLAG_GRC_R1_HIDE_NPCS
	setflag FLAG_SYS_POKEMON_GET
	releaseall
	end

Turia_Celebration_Cont_B_2:
	msgbox Turia_Celebration_Cont_B_Text_0
	goto Turia_Celebration_Cont_B_1

Turia_Celebration_Cont_B_6:
	msgbox Turia_Celebration_Cont_B_Text_2
	goto Turia_Celebration_Cont_B_5


Turpia_Rival_RunsOff:
	player_run_left
	player_run_left
	player_run_left
	player_run_up
	player_run_left
	player_run_left
	player_run_left
	player_run_left
	player_run_left
	player_run_left
	step_end

Turpia_Tori_RunsOff:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Turpia_Prof_Runsoff:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Turpia_Prof_MovesUp:
	walk_up
	walk_in_place_fastest_down
	step_end

Turpia_Prof_MovesSide:
	walk_left
	walk_left
	walk_down
	walk_in_place_fastest_right
	step_end

Turpia_Rival_MovesToBox:
	walk_up
	walk_left
	walk_in_place_fastest_down
	step_end

Turpia_NoAccessR1::
	lockall
	applymovement 5, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	applymovement 5, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox Turpia_NoAccessR1_Text_0
	closemessage
	checkfollower
	compare VAR_RESULT, 0
	goto_if_ne Turpia_NoAccessR1_2
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
Turpia_NoAccessR1_1:
	releaseall
	return

Turpia_NoAccessR1_2:
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	facefollower
	goto Turpia_NoAccessR1_1


Turpia_ScientistR1Block::
	msgbox Turpia_ScientistR1Block_Text_0, MSGBOX_NPC
	return


Turpia_SigurdCameo::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, Turpia_SigurdCameo_2
	goto_if_unset FLAG_TEMP_1F, Turpia_SigurdCameo_5
	msgbox Turpia_SigurdCameo_Text_3, MSGBOX_NPC
Turpia_SigurdCameo_1:
	release
	return

Turpia_SigurdCameo_2:
	msgbox Turpia_SigurdCameo_Text_0, MSGBOX_NPC
	goto Turpia_SigurdCameo_1

Turpia_SigurdCameo_5:
	setflag FLAG_TEMP_1F
	msgbox Turpia_SigurdCameo_Text_1
	closemessage
	applymovement 4, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox Turpia_SigurdCameo_Text_2, MSGBOX_NPC
	goto Turpia_SigurdCameo_1


Turpia_BeachLady::
	msgbox Turpia_BeachLady_Text_0, MSGBOX_NPC
	return


Turpia_LittleKiddo::
	msgbox Turpia_LittleKiddo_Text_0, MSGBOX_NPC
	return


Turpia_Fisherman::
	msgbox Turpia_Fisherman_Text_0, MSGBOX_NPC
	return


Turpia_RealEstateGuy::
	showmoneybox 0, 0, 0
	lock
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Turpia_RealEstateGuy_2
	msgbox Turpia_RealEstateGuy_Text_1, MSGBOX_YESNO
Turpia_RealEstateGuy_1:
	compare VAR_RESULT, 0
	goto_if_ne Turpia_RealEstateGuy_6
	msgbox Turpia_RealEstateGuy_Text_4
Turpia_RealEstateGuy_5:
	release
	hidemoneybox
	return

Turpia_RealEstateGuy_2:
	msgbox Turpia_RealEstateGuy_Text_0, MSGBOX_YESNO
	goto Turpia_RealEstateGuy_1

Turpia_RealEstateGuy_6:
	checkmoney 500000, 0
	compare VAR_RESULT, 0
	goto_if_ne Turpia_RealEstateGuy_9
	msgbox Turpia_RealEstateGuy_Text_3
	goto Turpia_RealEstateGuy_5

Turpia_RealEstateGuy_9:
	msgbox Turpia_RealEstateGuy_Text_2
	goto Turpia_RealEstateGuy_5


Turpia_ShowRivals_Start_Movement::
	compare VAR_GRC_TURPIA_INTRO_STATE, 4
	goto_if_eq Turpia_ShowRivals_Start_Movement_2
Turpia_ShowRivals_Start_Movement_1:
	compare VAR_GRC_TURPIA_INTRO_STATE, 5
	goto_if_eq Turpia_ShowRivals_Start_Movement_5
Turpia_ShowRivals_Start_Movement_4:
	compare VAR_GRC_TURPIA_INTRO_STATE, 6
	goto_if_eq Turpia_ShowRivals_Start_Movement_7
	return

Turpia_ShowRivals_Start_Movement_2:
	clearflag FLAG_GRC_HIDE_TURPIA_SCIENTIST
	setobjectxyperm 6, 22, 9
	setobjectxyperm 7, 21, 9
	savebgm MUS_FOLLOW_ME
	goto Turpia_ShowRivals_Start_Movement_1

Turpia_ShowRivals_Start_Movement_5:
	clearflag FLAG_GRC_HIDE_TURPIA_SCIENTIST
	setobjectxyperm 6, 14, 17
	setobjectxyperm 7, 13, 17
	savebgm MUS_FOLLOW_ME
	goto Turpia_ShowRivals_Start_Movement_4

Turpia_ShowRivals_Start_Movement_7:
	setobjectxyperm 6, 7, 14
	setobjectxyperm 7, 6, 14
	setobjectmovementtype 6, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype 7, MOVEMENT_TYPE_FACE_DOWN
	return


Turpia_ProtaSquad_A::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Turpia_ProtaSquad_A_Player
	applymovement 7, Turpia_ProtaSquad_A_Rival
	applymovement 6, Turpia_ProtaSquad_A_Tori
	waitmovement 0
	goto Turpia_ProtaSquad_C
	return


Turpia_ProtaSquad_B::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Turpia_ProtaSquad_B_Player
	applymovement 7, Turpia_ProtaSquad_B_Rival
	applymovement 6, Turpia_ProtaSquad_B_Tori
	waitmovement 0
	goto Turpia_ProtaSquad_C
	return


Turpia_ProtaSquad_C::
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
	setflag FLAG_HIDE_MAP_NAME_POPUP
	setflag FLAG_DONT_TRANSITION_MUSIC
	applymovement OBJ_EVENT_ID_PLAYER, Turpia_ProtaSquad_C_Player
	applymovement 6, Turpia_ProtaSquad_C_Tori
	applymovement 7, Turpia_ProtaSquad_C_Rival
	waitmovement 0
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Turpia_ProtaSquad_C_2
	msgbox Turpia_ProtaSquad_C_Text_1
Turpia_ProtaSquad_C_1:
	closemessage
	applymovement 6, Common_Movement_WalkInPlaceFastestLeft, MAP_LITTLEROOT_TOWN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight, MAP_LITTLEROOT_TOWN
	waitmovement 6, MAP_LITTLEROOT_TOWN
	msgbox Turpia_ProtaSquad_C_Text_2
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft, MAP_LITTLEROOT_TOWN
	applymovement 7, Common_Movement_WalkInPlaceFastestRight, MAP_LITTLEROOT_TOWN
	waitmovement 7, MAP_LITTLEROOT_TOWN
	compare VAR_RESULT, MALE
	goto_if_eq Turpia_ProtaSquad_C_6
	msgbox Turpia_ProtaSquad_C_Text_4
Turpia_ProtaSquad_C_5:
	closemessage
	applymovement 6, Common_Movement_WalkInPlaceFastestLeft, MAP_LITTLEROOT_TOWN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight, MAP_LITTLEROOT_TOWN
	waitmovement 6, MAP_LITTLEROOT_TOWN
	msgbox Turpia_ProtaSquad_C_Text_5, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Turpia_ProtaSquad_C_10
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft, MAP_LITTLEROOT_TOWN
	applymovement 7, Common_Movement_WalkInPlaceFastestRight, MAP_LITTLEROOT_TOWN
	waitmovement 7, MAP_LITTLEROOT_TOWN
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Turpia_ProtaSquad_C_20
	msgbox Turpia_ProtaSquad_C_Text_10
Turpia_ProtaSquad_C_9:
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Turpia_ProtaSquad_E_Player
	applymovement 7, Turpia_ProtaSquad_E_Rival, MAP_LITTLEROOT_TOWN
	applymovement 6, Turpia_ProtaSquad_E_Tori, MAP_LITTLEROOT_TOWN
	waitmovement 6, MAP_LITTLEROOT_TOWN
	msgbox Turpia_ProtaSquad_C_Text_11
	playbgm MUS_HELP, FALSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	applymovement 7, Common_Movement_WalkInPlaceFastestDown, MAP_LITTLEROOT_TOWN
	applymovement 6, Common_Movement_ExclamationMark, MAP_LITTLEROOT_TOWN
	waitmovement 6, MAP_LITTLEROOT_TOWN
	applymovement 5, Common_Movement_WalkInPlaceFastestLeft, MAP_LITTLEROOT_TOWN
	waitmovement 5, MAP_LITTLEROOT_TOWN
	applymovement 5, Common_Movement_ExclamationMark, MAP_LITTLEROOT_TOWN
	msgbox Turpia_ProtaSquad_C_Text_12
	closemessage
	applymovement 5, R1_Scientist_Save, MAP_LITTLEROOT_TOWN
	waitmovement 5, MAP_LITTLEROOT_TOWN
	msgbox Turpia_ProtaSquad_C_Text_13
	closemessage
	special SavePlayerParty
	special PutZigzagoonInPlayerParty
	special StartWallyTutorialBattle
	waitstate
	special LoadPlayerParty
	applymovement 5, Common_Movement_WalkInPlaceFastestLeft, MAP_LITTLEROOT_TOWN
	waitmovement 5, MAP_LITTLEROOT_TOWN
	msgbox Turpia_ProtaSquad_C_Text_14
	closemessage
	applymovement 5, R1_Scientist_BackOff, MAP_LITTLEROOT_TOWN
	waitmovement 5, MAP_LITTLEROOT_TOWN
	applymovement 7, Common_Movement_WalkInPlaceFastestDown, MAP_LITTLEROOT_TOWN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp, MAP_LITTLEROOT_TOWN
	waitmovement 7, MAP_LITTLEROOT_TOWN
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Turpia_ProtaSquad_C_14
	msgbox Turpia_ProtaSquad_C_Text_16
Turpia_ProtaSquad_C_13:
	closemessage
	applymovement 6, Common_Movement_WalkInPlaceFastestUp, MAP_LITTLEROOT_TOWN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown, MAP_LITTLEROOT_TOWN
	waitmovement 6, MAP_LITTLEROOT_TOWN
	msgbox Turpia_ProtaSquad_C_Text_17
	closemessage
	applymovement 7, Common_Movement_WalkInPlaceFastestDown, MAP_LITTLEROOT_TOWN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp, MAP_LITTLEROOT_TOWN
	waitmovement 7, MAP_LITTLEROOT_TOWN
	compare VAR_RESULT, MALE
	goto_if_eq Turpia_ProtaSquad_C_24
	msgbox Turpia_ProtaSquad_C_Text_21
	closemessage
	applymovement 6, Common_Movement_WalkInPlaceFastestUp, MAP_LITTLEROOT_TOWN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown, MAP_LITTLEROOT_TOWN
	waitmovement 6, MAP_LITTLEROOT_TOWN
	msgbox Turpia_ProtaSquad_C_Text_22
	closemessage
	applymovement 7, Common_Movement_WalkInPlaceFastestDown, MAP_LITTLEROOT_TOWN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp, MAP_LITTLEROOT_TOWN
	waitmovement 7, MAP_LITTLEROOT_TOWN
	msgbox Turpia_ProtaSquad_C_Text_23
Turpia_ProtaSquad_C_23:
	closemessage
	applymovement 6, Common_Movement_WalkInPlaceFastestUp, MAP_LITTLEROOT_TOWN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown, MAP_LITTLEROOT_TOWN
	waitmovement 6, MAP_LITTLEROOT_TOWN
	msgbox Turpia_ProtaSquad_C_Text_24
	closemessage
	applymovement 7, Common_Movement_WalkInPlaceFastestDown, MAP_LITTLEROOT_TOWN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp, MAP_LITTLEROOT_TOWN
	waitmovement 7, MAP_LITTLEROOT_TOWN
	compare VAR_RESULT, MALE
	goto_if_eq Turpia_ProtaSquad_C_28
	msgbox Turpia_ProtaSquad_C_Text_26
Turpia_ProtaSquad_C_27:
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Turpia_ProtaSquad_D_Player
	applymovement 7, Turpia_ProtaSquad_D_Rival, MAP_LITTLEROOT_TOWN
	applymovement 6, Turpia_ProtaSquad_D_Tori, MAP_LITTLEROOT_TOWN
	waitmovement 6, MAP_LITTLEROOT_TOWN
	applymovement 2, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	playbgm MUS_BIRCH_LAB, TRUE
	msgbox Turpia_ProtaSquad_C_Text_27
	closemessage
	playfanfare MUS_OBTAIN_ITEM
	message Turpia_ProtaSquad_C_Text_28
	waitfanfare
	setvar VAR_GRC_TURPIA_INTRO_STATE, 6
	setvar VAR_GRC_ROUTE1_STATE, 1
	setflag FLAG_GRC_TURPIA_HIDE_RIVALS
	clearflag FLAG_GRC_R1_HIDE_RIVALS
	clearflag FLAG_DONT_TRANSITION_MUSIC
	special EnterSafariModeR1
	warpsilent MAP_ROUTE101, 255, 13, 3
	waitstate
	releaseall
	return

Turpia_ProtaSquad_C_2:
	msgbox Turpia_ProtaSquad_C_Text_0
	goto Turpia_ProtaSquad_C_1

Turpia_ProtaSquad_C_6:
	msgbox Turpia_ProtaSquad_C_Text_3
	goto Turpia_ProtaSquad_C_5

Turpia_ProtaSquad_C_10:
	msgbox Turpia_ProtaSquad_C_Text_6
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft, MAP_LITTLEROOT_TOWN
	applymovement 7, Common_Movement_WalkInPlaceFastestRight, MAP_LITTLEROOT_TOWN
	waitmovement 7, MAP_LITTLEROOT_TOWN
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Turpia_ProtaSquad_C_17
	msgbox Turpia_ProtaSquad_C_Text_8
	goto Turpia_ProtaSquad_C_9

Turpia_ProtaSquad_C_14:
	msgbox Turpia_ProtaSquad_C_Text_15
	goto Turpia_ProtaSquad_C_13

Turpia_ProtaSquad_C_17:
	msgbox Turpia_ProtaSquad_C_Text_7
	goto Turpia_ProtaSquad_C_9

Turpia_ProtaSquad_C_20:
	msgbox Turpia_ProtaSquad_C_Text_9
	goto Turpia_ProtaSquad_C_9

Turpia_ProtaSquad_C_24:
	msgbox Turpia_ProtaSquad_C_Text_18
	closemessage
	applymovement 6, Common_Movement_WalkInPlaceFastestUp, MAP_LITTLEROOT_TOWN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown, MAP_LITTLEROOT_TOWN
	waitmovement 6, MAP_LITTLEROOT_TOWN
	msgbox Turpia_ProtaSquad_C_Text_19
	closemessage
	applymovement 7, Common_Movement_WalkInPlaceFastestDown, MAP_LITTLEROOT_TOWN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp, MAP_LITTLEROOT_TOWN
	waitmovement 7, MAP_LITTLEROOT_TOWN
	msgbox Turpia_ProtaSquad_C_Text_20
	goto Turpia_ProtaSquad_C_23

Turpia_ProtaSquad_C_28:
	msgbox Turpia_ProtaSquad_C_Text_25
	goto Turpia_ProtaSquad_C_27


R1_Scientist_Save:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

R1_Scientist_BackOff:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Turpia_ProtaSquad_A_Player:
	walk_down
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Turpia_ProtaSquad_A_Rival:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Turpia_ProtaSquad_A_Tori:
	delay_16
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Turpia_ProtaSquad_B_Player:
	walk_left
	delay_16
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

Turpia_ProtaSquad_B_Rival:
	walk_left
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

Turpia_ProtaSquad_B_Tori:
	delay_16
	walk_up
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

Turpia_ProtaSquad_C_Player:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Turpia_ProtaSquad_C_Rival:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_right
	step_end

Turpia_ProtaSquad_C_Tori:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Turpia_ProtaSquad_D_Player:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_in_place_fastest_left
	step_end

Turpia_ProtaSquad_D_Rival:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_left
	step_end

Turpia_ProtaSquad_D_Tori:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_in_place_fastest_left
	step_end

Turpia_ProtaSquad_E_Player:
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_up
	walk_slow_up
	step_end

Turpia_ProtaSquad_E_Rival:
	walk_slow_left
	walk_slow_left
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end

Turpia_ProtaSquad_E_Tori:
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_up
	step_end

 
.set LOCALID_TWIN, 1
.set LOCALID_MOM, 4
.set LOCALID_RIVAL, 7
.set LOCALID_BIRCH, 8

@ LittlerootTown_MapScripts::
@	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_OnTransition
@	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_OnFrame
@	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_OnWarp
@	.byte 0

	@ State descriptions for VAR_LITTLEROOT_TOWN_STATE
	@ 1: Met Rival
	@ 2: Saving Birch
	@ 3: Received Pokedex
	@ 4: Received Running Shoes

	@ State descriptions for VAR_GRC_TURPIA_INTRO_STATE
	@ 1: In truck male
	@ 2: In truck female
	@ 3: Entered house
	@ 4: Told to go set clock
	@ 5: Entered 2F to set clock
	@ 6: Set clock
	@ 7: Told to go meet rival

	@ State descriptions for VAR_LITTLEROOT_HOUSES_STATE_MAY
	@                    and VAR_LITTLEROOT_HOUSES_STATE_BRENDAN
	@ 1: On Truck (and is corresponding gender)
	@ 2: Met Rival's Mom (and is corresponding gender)
	@ 3: Entered Hall of Fame
	@ 4: Completed Lati TV / SS Ticket event
	@ 5: Exited house after above event

	@ State descriptions for VAR_LITTLEROOT_RIVAL_STATE
	@ 1: Never occurs
	@ 2: Entered Rival's bedroom
	@ 3: Met Rival
	@ 4: Received Pokedex


LittlerootTown_OnTransition:
@	
@	call Common_EventScript_SetupRivalGfxId
@	compare VAR_GRC_TURPIA_INTRO_STATE, 2
@	call_if_eq LittlerootTown_EventScript_MoveMomToMaysDoor
@	call_if_unset FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_SetTwinPos
@	compare VAR_LITTLEROOT_TOWN_STATE, 3
@	call_if_eq LittlerootTown_EventScript_SetMomStandingInFrontOfDoorPos
@	compare VAR_LITTLEROOT_HOUSES_STATE_MAY, 4
@	call_if_eq LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent
@	compare VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 4
@	call_if_eq LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent
@	compare VAR_OLDALE_RIVAL_STATE, 1
@	call_if_eq LittlerootTown_EventScript_MoveRivalFromOldale
@	compare VAR_LITTLEROOT_RIVAL_STATE, 3
@	call_if_eq LittlerootTown_EventScript_SetRivalLeftForRoute103
@	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1
@	call_if_eq LittlerootTown_EventScript_HideMapNamePopup
@	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2
@	call_if_eq LittlerootTown_EventScript_LeftLabAfterDexUpgrade
@	end

LittlerootTown_EventScript_LeftLabAfterDexUpgrade::
@	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3
@	return

LittlerootTown_EventScript_HideMapNamePopup::
@	setflag FLAG_HIDE_MAP_NAME_POPUP
@	return

LittlerootTown_EventScript_SetRivalLeftForRoute103::
@	setflag FLAG_RIVAL_LEFT_FOR_ROUTE103
@	return

LittlerootTown_EventScript_MoveRivalFromOldale::
@	setvar VAR_OLDALE_RIVAL_STATE, 2
@	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
@	return

LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent::
@	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 5
@	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 5
@	return

LittlerootTown_EventScript_MoveMomToMaysDoor::
@	setobjectxyperm LOCALID_MOM, 14, 8
@	return

LittlerootTown_EventScript_SetTwinPos::
@	compare VAR_LITTLEROOT_TOWN_STATE, 0
@	goto_if_eq LittlerootTown_EventScript_SetTwinGuardingRoutePos
@	setobjectxyperm LOCALID_TWIN, 10, 1
@	setobjectmovementtype LOCALID_TWIN, MOVEMENT_TYPE_FACE_UP
@	return

LittlerootTown_EventScript_SetTwinGuardingRoutePos::
@	setobjectxyperm LOCALID_TWIN, 7, 2
@	setobjectmovementtype LOCALID_TWIN, MOVEMENT_TYPE_FACE_DOWN
@	return

LittlerootTown_EventScript_SetMomStandingInFrontOfDoorPos::
@	clearflag FLAG_GRC_HIDE_SIGURD_TURPIA
@	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_DOWN
@	checkplayergender
@	compare VAR_RESULT, MALE
@	call_if_eq LittlerootTown_EventScript_SetMomInFrontOfDoorMale
@	compare VAR_RESULT, FEMALE
@	call_if_eq LittlerootTown_EventScript_SetMomInFrontOfDoorFemale
@	return

LittlerootTown_EventScript_SetMomInFrontOfDoorMale::
@	setobjectxyperm LOCALID_MOM, 5, 9
@	return

LittlerootTown_EventScript_SetMomInFrontOfDoorFemale::
@	setobjectxyperm LOCALID_MOM, 14, 9
@	return

LittlerootTown_OnFrame:
@	map_script_2 VAR_GRC_TURPIA_INTRO_STATE, 1, LittlerootTown_EventScript_StepOffTruckMale
@	map_script_2 VAR_GRC_TURPIA_INTRO_STATE, 2, LittlerootTown_EventScript_StepOffTruckFemale
@	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_BeginDexUpgradeScene
@	.2byte 0

LittlerootTown_EventScript_StepOffTruckMale::
@	lockall
@	setvar VAR_0x8004, 5
@	setvar VAR_0x8005, 8
@	call LittlerootTown_EventScript_GoInsideWithMom
@	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
@	warpsilent MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F, 255, 8, 8
@	waitstate
@	releaseall
@	end

LittlerootTown_EventScript_StepOffTruckFemale::
@	lockall
@	setvar VAR_0x8004, 14
@	setvar VAR_0x8005, 8
@	call LittlerootTown_EventScript_GoInsideWithMom
@	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
@	warpsilent MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F, 255, 2, 8
@	waitstate
@	releaseall
@	end

LittlerootTown_EventScript_GoInsideWithMom::
@	delay 15
@	playse SE_LEDGE
@	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerStepOffTruck
@	waitmovement 0
@	opendoor VAR_0x8004, VAR_0x8005
@	waitdooranim
@	addobject LOCALID_MOM
@	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitHouse
@	waitmovement 0
@	closedoor VAR_0x8004, VAR_0x8005
@	waitdooranim
@	delay 10
@	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerAtTruck
@	waitmovement 0
@	msgbox LittlerootTown_Text_OurNewHomeLetsGoInside, MSGBOX_DEFAULT
@	closemessage
@	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachDoor
@	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerApproachDoor
@	waitmovement 0
@	opendoor VAR_0x8004, VAR_0x8005
@	waitdooranim
@	applymovement LOCALID_MOM, LittlerootTown_Movement_MomEnterHouse
@	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerEnterHouse
@	waitmovement 0
@	setflag FLAG_GRC_HIDE_SIGURD_TURPIA
@	setvar VAR_GRC_TURPIA_INTRO_STATE, 3
@	hideobjectat OBJ_EVENT_ID_PLAYER, 0
@	closedoor VAR_0x8004, VAR_0x8005
@	waitdooranim
@	clearflag FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN
@	clearflag FLAG_HIDE_MAP_NAME_POPUP
@	return

LittlerootTown_Movement_MomExitHouse:
@	walk_down
@	step_end

LittlerootTown_Movement_MomApproachPlayerAtTruck:
@	walk_down
@	walk_in_place_fastest_left
@	step_end

LittlerootTown_Movement_MomApproachDoor:
@	delay_16
@	delay_8
@	walk_up
@	step_end

LittlerootTown_Movement_MomEnterHouse:
@	walk_up
@	set_invisible
@	step_end

LittlerootTown_Movement_PlayerApproachDoor:
@	delay_16
@	delay_8
@	walk_right
@	walk_in_place_fastest_up
@	step_end

LittlerootTown_Movement_PlayerEnterHouse:
@	walk_up
@	walk_up
@	step_end

LittlerootTown_Movement_PlayerStepOffTruck:
@	jump_right
@	delay_16
@	delay_16
@	delay_16
@	step_end

LittlerootTown_EventScript_BeginDexUpgradeScene::
@	lockall
@	playse SE_PIN
@	applymovement LOCALID_BIRCH, Common_Movement_ExclamationMark
@	waitmovement 0
@	delay 80
@	msgbox LittlerootTown_Text_BirchSomethingToShowYouAtLab, MSGBOX_DEFAULT
@	closemessage
@	clearflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
@	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
@	delay 20
@	clearflag FLAG_HIDE_MAP_NAME_POPUP
@	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 255, 6, 5
@	waitstate
@	releaseall
@	end

LittlerootTown_OnWarp:
@	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade
@	.2byte 0

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade::
@	addobject LOCALID_BIRCH
@	addobject LOCALID_RIVAL
@	checkplayergender
@	compare VAR_RESULT, MALE
@	goto_if_eq LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeMale
@	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeFemale
@	end

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeMale::
@	setobjectxy LOCALID_RIVAL, 6, 10
@	setobjectxy LOCALID_BIRCH, 5, 10
@	end

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeFemale::
@	setobjectxy LOCALID_RIVAL, 13, 10
@	setobjectxy LOCALID_BIRCH, 14, 10
@	end

LittlerootTown_EventScript_FatMan::
@	msgbox LittlerootTown_Text_CanUsePCToStoreItems, MSGBOX_NPC
@	end

LittlerootTown_EventScript_Boy::
@	msgbox LittlerootTown_Text_BirchSpendsDaysInLab, MSGBOX_NPC
@	end

LittlerootTown_EventScript_Twin::
@	lock
@	faceplayer
@	goto_if_set FLAG_ADVENTURE_STARTED, LittlerootTown_EventScript_GoodLuck
@	goto_if_set FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_YouSavedBirch
@	compare VAR_LITTLEROOT_TOWN_STATE, 0
@	goto_if_ne LittlerootTown_EventScript_GoSaveBirch
@	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
@	release
@	end

LittlerootTown_EventScript_GoSaveBirch::
@	special GetPlayerBigGuyGirlString
@	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
@	closemessage
@	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
@	waitmovement 0
@	setvar VAR_LITTLEROOT_TOWN_STATE, 2
@	release
@	end

LittlerootTown_EventScript_YouSavedBirch::
@	special GetPlayerBigGuyGirlString
@	msgbox LittlerootTown_Text_YouSavedBirch, MSGBOX_DEFAULT
@	release
@	end

LittlerootTown_EventScript_GoodLuck::
@	msgbox LittlerootTown_Text_GoodLuckCatchingPokemon, MSGBOX_DEFAULT
@	release
@	end

LittlerootTown_EventScript_NeedPokemonTriggerLeft::
@	lockall
@	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinApproachPlayerLeft
@	waitmovement 0
@	call LittlerootTown_EventScript_DangerousWithoutPokemon
@	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinReturnLeft
@	waitmovement 0
@	releaseall
@	end

LittlerootTown_EventScript_DangerousWithoutPokemon::
@	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
@	closemessage
@	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinPushPlayerFromRoute
@	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PushPlayerBackFromRoute
@	waitmovement 0
@	msgbox LittlerootTown_Text_DangerousIfYouDontHavePokemon, MSGBOX_DEFAULT
@	closemessage
@	return

LittlerootTown_Movement_TwinApproachPlayerLeft:
@	face_right
@	delay_8
@	disable_jump_landing_ground_effect
@	jump_in_place_right
@	delay_8
@	walk_fast_right
@	walk_fast_right
@	walk_fast_right
@	walk_fast_right
@	walk_fast_up
@	walk_fast_up
@	walk_fast_left
@	face_down
@	step_end

LittlerootTown_Movement_TwinPushPlayerFromRoute:
@	walk_down
@	step_end

LittlerootTown_Movement_TwinReturnLeft:
@	walk_right
@	walk_down
@	walk_down
@	walk_left
@	walk_left
@	walk_left
@	walk_left
@	walk_up
@	walk_in_place_fastest_down
@	step_end

LittlerootTown_Movement_PushPlayerBackFromRoute:
@	lock_facing_direction
@	walk_down
@	unlock_facing_direction
@	step_end

LittlerootTown_EventScript_NeedPokemonTriggerRight::
@	lockall
@	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinApproachPlayerRight
@	waitmovement 0
@	call LittlerootTown_EventScript_DangerousWithoutPokemon
@	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinReturnRight
@	waitmovement 0
@	releaseall
@	end

LittlerootTown_Movement_TwinApproachPlayerRight:
@	face_right
@	delay_8
@	disable_jump_landing_ground_effect
@	jump_in_place_right
@	delay_8
@	walk_fast_right
@	walk_fast_right
@	walk_fast_right
@	walk_fast_up
@	walk_fast_up
@	walk_fast_right
@	face_down
@	step_end

LittlerootTown_Movement_TwinReturnRight:
@	walk_left
@	walk_down
@	walk_left
@	walk_left
@	walk_left
@	walk_in_place_fastest_down
@	step_end

LittlerootTown_EventScript_GoSaveBirchTrigger::
@	lockall
@	applymovement LOCALID_TWIN, Common_Movement_WalkInPlaceFastestRight
@	waitmovement 0
@	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
@	waitmovement 0
@	special GetPlayerBigGuyGirlString
@	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
@	closemessage
@	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
@	waitmovement 0
@	setvar VAR_LITTLEROOT_TOWN_STATE, 2
@	releaseall
@	end

LittlerootTown_EventScript_TownSign::
@	msgbox LittlerootTown_Text_TownSign, MSGBOX_SIGN
@	end

LittlerootTown_EventScript_BirchsLabSign::
@	msgbox LittlerootTown_Text_ProfBirchsLab, MSGBOX_SIGN
@	end

LittlerootTown_EventScript_BrendansHouseSign::
@	lockall
@	checkplayergender
@	compare VAR_RESULT, MALE
@	call_if_eq LittlerootTown_EventScript_PlayersHouseSignMale
@	compare VAR_RESULT, FEMALE
@	call_if_eq LittlerootTown_EventScript_BirchsHouseSignFemale
@	releaseall
@	end

LittlerootTown_EventScript_PlayersHouseSignMale::
@	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
@	return

LittlerootTown_EventScript_BirchsHouseSignFemale::
@	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
@	return

LittlerootTown_EventScript_MaysHouseSign::
@	lockall
@	checkplayergender
@	compare VAR_RESULT, MALE
@	call_if_eq LittlerootTown_EventScript_BirchsHouseSignMale
@	compare VAR_RESULT, FEMALE
@	call_if_eq LittlerootTown_EventScript_PlayersHouseSignFemale
@	releaseall
@	end

LittlerootTown_EventScript_BirchsHouseSignMale::
@	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
@	return

LittlerootTown_EventScript_PlayersHouseSignFemale::
@	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
@	return

LittlerootTown_EventScript_GiveRunningShoesTrigger0::
@	lockall
@	setvar VAR_0x8008, 0
@	setobjectxy LOCALID_MOM, 10, 9
@	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
@	end

LittlerootTown_EventScript_GiveRunningShoesTrigger1::
@	lockall
@	setvar VAR_0x8008, 1
@	setobjectxy LOCALID_MOM, 11, 9
@	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
@	end

LittlerootTown_EventScript_GiveRunningShoesTrigger2::
@	lockall
@	setvar VAR_0x8008, 2
@	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
@	end

LittlerootTown_EventScript_GiveRunningShoesTrigger3::
@	lockall
@	setvar VAR_0x8008, 3
@	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
@	end

LittlerootTown_EventScript_GiveRunningShoesTrigger4::
@	lockall
@	setvar VAR_0x8008, 4
@	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
@	end

LittlerootTown_EventScript_GiveRunningShoesTrigger5::
@	lockall
@	setvar VAR_0x8008, 5
@	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
@	end

LittlerootTown_EventScript_GiveRunningShoesTrigger::
@	checkplayergender
@	compare VAR_RESULT, MALE
@	call_if_eq LittlerootTown_EventScript_MomNoticePlayerMale
@	compare VAR_RESULT, FEMALE
@	call_if_eq LittlerootTown_EventScript_MomNoticePlayerFemale
@	checkplayergender
@	compare VAR_RESULT, MALE
@	call_if_eq LittlerootTown_EventScript_SetHomeDoorCoordsMale
@	compare VAR_RESULT, FEMALE
@	call_if_eq LittlerootTown_EventScript_SetHomeDoorCoordsFemale
@	msgbox LittlerootTown_Text_WaitPlayer, MSGBOX_DEFAULT
@	closemessage
@	checkplayergender
@	compare VAR_RESULT, MALE
@	call_if_eq LittlerootTown_EventScript_MomApproachPlayerMale
@	compare VAR_RESULT, FEMALE
@	call_if_eq LittlerootTown_EventScript_MomApproachPlayerFemale
@	call LittlerootTown_EventScript_GiveRunningShoes
@	checkplayergender
@	compare VAR_RESULT, MALE
@	call_if_eq LittlerootTown_EventScript_MomReturnHomeMale
@	compare VAR_RESULT, FEMALE
@	call_if_eq LittlerootTown_EventScript_MomReturnHomeFemale
@	goto LittlerootTown_EventScript_SetReceivedRunningShoes
@	end

LittlerootTown_EventScript_SetHomeDoorCoordsMale::
@	setvar VAR_0x8009, 5
@	setvar VAR_0x800A, 8
@	return

LittlerootTown_EventScript_SetHomeDoorCoordsFemale::
@	setvar VAR_0x8009, 14
@	setvar VAR_0x800A, 8
@	return

LittlerootTown_EventScript_MomNoticePlayerMale::
@	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFastestRight
@	waitmovement 0
@	return

LittlerootTown_EventScript_MomNoticePlayerFemale::
@	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFastestLeft
@	waitmovement 0
@	return

LittlerootTown_EventScript_MomApproachPlayerMale::
@	compare VAR_0x8008, 0
@	call_if_eq LittlerootTown_EventScript_MomApproachPlayer0
@	compare VAR_0x8008, 1
@	call_if_eq LittlerootTown_EventScript_MomApproachPlayer1
@	compare VAR_0x8008, 2
@	call_if_eq LittlerootTown_EventScript_MomApproachPlayerMale2
@	compare VAR_0x8008, 3
@	call_if_eq LittlerootTown_EventScript_MomApproachPlayerMale3
@	compare VAR_0x8008, 4
@	call_if_eq LittlerootTown_EventScript_MomApproachPlayerMale4
@	compare VAR_0x8008, 5
@	call_if_eq LittlerootTown_EventScript_MomApproachPlayerMale5
@	return

LittlerootTown_EventScript_MomApproachPlayerFemale::
@	compare VAR_0x8008, 0
@	call_if_eq LittlerootTown_EventScript_MomApproachPlayer0
@	compare VAR_0x8008, 1
@	call_if_eq LittlerootTown_EventScript_MomApproachPlayer1
@	compare VAR_0x8008, 2
@	call_if_eq LittlerootTown_EventScript_MomApproachPlayerFemale2
@	compare VAR_0x8008, 3
@	call_if_eq LittlerootTown_EventScript_MomApproachPlayerFemale3
@	compare VAR_0x8008, 4
@	call_if_eq LittlerootTown_EventScript_MomApproachPlayerFemale4
@	compare VAR_0x8008, 5
@	call_if_eq LittlerootTown_EventScript_MomApproachPlayerFemale5
@	return

LittlerootTown_EventScript_MomApproachPlayer0::
@	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
@	waitmovement 0
@	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayer0
@	waitmovement 0
@	return

LittlerootTown_EventScript_MomApproachPlayer1::
@	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
@	waitmovement 0
@	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayer1
@	waitmovement 0
@	return

LittlerootTown_EventScript_MomApproachPlayerMale2::
@	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
@	waitmovement 0
@	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale2
@	waitmovement 0
@	return

LittlerootTown_EventScript_MomApproachPlayerMale3::
@	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
@	waitmovement 0
@	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale3
@	waitmovement 0
@	return

LittlerootTown_EventScript_MomApproachPlayerMale4::
@	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
@	waitmovement 0
@	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale4
@	waitmovement 0
@	return

LittlerootTown_EventScript_MomApproachPlayerMale5::
@	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
@	waitmovement 0
@	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale5
@	waitmovement 0
@	return

LittlerootTown_EventScript_MomApproachPlayerFemale2::
@	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
@	waitmovement 0
@	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale2
@	waitmovement 0
@	return

LittlerootTown_EventScript_MomApproachPlayerFemale3::
@	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
@	waitmovement 0
@	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale3
@	waitmovement 0
@	return

LittlerootTown_EventScript_MomApproachPlayerFemale4::
@	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
@	waitmovement 0
@	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale4
@	waitmovement 0
@	return

LittlerootTown_EventScript_MomApproachPlayerFemale5::
@	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
@	waitmovement 0
@	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale5
@	waitmovement 0
@	return

LittlerootTown_EventScript_MomReturnHomeMale::
@	compare VAR_0x8008, 0
@	call_if_eq LittlerootTown_EventScript_MomReturnHome0
@	compare VAR_0x8008, 1
@	call_if_eq LittlerootTown_EventScript_MomReturnHome1
@	compare VAR_0x8008, 2
@	call_if_eq LittlerootTown_EventScript_MomReturnHomeMale2
@	compare VAR_0x8008, 3
@	call_if_eq LittlerootTown_EventScript_MomReturnHomeMale3
@	compare VAR_0x8008, 4
@	call_if_eq LittlerootTown_EventScript_MomReturnHomeMale4
@	compare VAR_0x8008, 5
@	call_if_eq LittlerootTown_EventScript_MomReturnHomeMale5
@	return

LittlerootTown_EventScript_MomReturnHomeFemale::
@	compare VAR_0x8008, 0
@	call_if_eq LittlerootTown_EventScript_MomReturnHome0
@	compare VAR_0x8008, 1
@	call_if_eq LittlerootTown_EventScript_MomReturnHome1
@	compare VAR_0x8008, 2
@	call_if_eq LittlerootTown_EventScript_MomReturnHomeFemale2
@	compare VAR_0x8008, 3
@	call_if_eq LittlerootTown_EventScript_MomReturnHomeFemale3
@	compare VAR_0x8008, 4
@	call_if_eq LittlerootTown_EventScript_MomReturnHomeFemale4
@	compare VAR_0x8008, 5
@	call_if_eq LittlerootTown_EventScript_MomReturnHomeFemale5
@	return

LittlerootTown_EventScript_MomReturnHome0::
@	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHome0
@	waitmovement 0
@	return

LittlerootTown_EventScript_MomReturnHome1::
@	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHome1
@	waitmovement 0
@	return

LittlerootTown_EventScript_MomReturnHomeMale2::
@	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale2
@	waitmovement 0
@	opendoor VAR_0x8009, VAR_0x800A
@	waitdooranim
@	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
@	waitmovement 0
@	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
@	closedoor VAR_0x8009, VAR_0x800A
@	waitdooranim
@	return

LittlerootTown_EventScript_MomReturnHomeMale3::
@	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale3
@	waitmovement 0
@	opendoor VAR_0x8009, VAR_0x800A
@	waitdooranim
@	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
@	waitmovement 0
@	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
@	closedoor VAR_0x8009, VAR_0x800A
@	waitdooranim
@	return

LittlerootTown_EventScript_MomReturnHomeMale4::
@	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale4
@	waitmovement 0
@	opendoor VAR_0x8009, VAR_0x800A
@	waitdooranim
@	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
@	waitmovement 0
@	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
@	closedoor VAR_0x8009, VAR_0x800A
@	waitdooranim
@	return

LittlerootTown_EventScript_MomReturnHomeMale5::
@	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale5
@	waitmovement 0
@	opendoor VAR_0x8009, VAR_0x800A
@	waitdooranim
@	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
@	waitmovement 0
@	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
@	closedoor VAR_0x8009, VAR_0x800A
@	waitdooranim
@	return

LittlerootTown_EventScript_MomReturnHomeFemale2::
@	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale2
@	waitmovement 0
@	opendoor VAR_0x8009, VAR_0x800A
@	waitdooranim
@	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
@	waitmovement 0
@	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
@	closedoor VAR_0x8009, VAR_0x800A
@	waitdooranim
@	return

LittlerootTown_EventScript_MomReturnHomeFemale3::
@	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale3
@	waitmovement 0
@	opendoor VAR_0x8009, VAR_0x800A
@	waitdooranim
@	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
@	waitmovement 0
@	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
@	closedoor VAR_0x8009, VAR_0x800A
@	waitdooranim
@	return

LittlerootTown_EventScript_MomReturnHomeFemale4::
@	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale4
@	waitmovement 0
@	opendoor VAR_0x8009, VAR_0x800A
@	waitdooranim
@	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
@	waitmovement 0
@	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
@	closedoor VAR_0x8009, VAR_0x800A
@	waitdooranim
@	return

LittlerootTown_EventScript_MomReturnHomeFemale5::
@	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale5
@	waitmovement 0
@	opendoor VAR_0x8009, VAR_0x800A
@	waitdooranim
@	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
@	waitmovement 0
@	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
@	closedoor VAR_0x8009, VAR_0x800A
@	waitdooranim
@	return

LittlerootTown_Movement_MomApproachPlayer0:
@	walk_up
@	walk_up
@	walk_up
@	walk_up
@	walk_up
@	walk_up
@	step_end

LittlerootTown_Movement_MomApproachPlayer1:
@	walk_up
@	walk_up
@	walk_up
@	walk_up
@	walk_up
@	walk_up
@	step_end

LittlerootTown_Movement_MomApproachPlayerMale2:
@	walk_right
@	walk_right
@	walk_right
@	walk_right
@	step_end

LittlerootTown_Movement_MomApproachPlayerMale3:
@	walk_right
@	walk_right
@	walk_right
@	walk_right
@	walk_right
@	step_end

LittlerootTown_Movement_MomApproachPlayerMale4:
@	walk_right
@	walk_right
@	step_end

LittlerootTown_Movement_MomApproachPlayerMale5:
@	walk_right
@	walk_right
@	walk_right
@	step_end

LittlerootTown_Movement_MomApproachPlayerFemale2:
@	walk_left
@	walk_left
@	walk_left
@	step_end

LittlerootTown_Movement_MomApproachPlayerFemale3:
@	walk_left
@	walk_left
@	step_end

LittlerootTown_Movement_MomApproachPlayerFemale4:
@	walk_left
@	walk_left
@	walk_left
@	walk_left
@	walk_left
@	step_end

LittlerootTown_Movement_MomApproachPlayerFemale5:
@	walk_left
@	walk_left
@	walk_left
@	walk_left
@	step_end

LittlerootTown_Movement_MomReturnHome0:
@	walk_down
@	walk_down
@	walk_down
@	walk_down
@	walk_down
@	step_end

LittlerootTown_Movement_MomReturnHome1:
@	walk_down
@	walk_down
@	walk_down
@	walk_down
@	walk_down
@	step_end

LittlerootTown_Movement_MomReturnHomeMale2:
@	walk_left
@	walk_left
@	walk_left
@	walk_left
@	walk_in_place_fastest_up
@	step_end

LittlerootTown_Movement_MomReturnHomeMale3:
@	walk_left
@	walk_left
@	walk_left
@	walk_left
@	walk_left
@	walk_in_place_fastest_up
@	step_end

LittlerootTown_Movement_MomReturnHomeMale4:
@	walk_left
@	walk_left
@	walk_in_place_fastest_up
@	step_end

LittlerootTown_Movement_MomReturnHomeMale5:
@	walk_left
@	walk_left
@	walk_left
@	walk_in_place_fastest_up
@	step_end

LittlerootTown_Movement_MomReturnHomeFemale2:
@	walk_right
@	walk_right
@	walk_right
@	walk_in_place_fastest_up
@	step_end

LittlerootTown_Movement_MomReturnHomeFemale3:
@	walk_right
@	walk_right
@	walk_in_place_fastest_up
@	step_end

LittlerootTown_Movement_MomReturnHomeFemale4:
@	walk_right
@	walk_right
@	walk_right
@	walk_right
@	walk_right
@	walk_in_place_fastest_up
@	step_end

LittlerootTown_Movement_MomReturnHomeFemale5:
@	walk_right
@	walk_right
@	walk_right
@	walk_right
@	walk_in_place_fastest_up
@	step_end

LittlerootTown_Movement_MomExitThroughDoor:
@	walk_up
@	step_end

LittlerootTown_EventScript_Mom::
@	lock
@	faceplayer
@	checkplayergender
@	compare VAR_RESULT, MALE
@	call_if_eq LittlerootTown_EventScript_SetHomeDoorCoordsMale
@	compare VAR_RESULT, FEMALE
@	call_if_eq LittlerootTown_EventScript_SetHomeDoorCoordsFemale
@	call LittlerootTown_EventScript_GiveRunningShoes
@	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFastestUp
@	waitmovement 0
@	opendoor VAR_0x8009, VAR_0x800A
@	waitdooranim
@	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
@	waitmovement 0
@	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
@	closedoor VAR_0x8009, VAR_0x800A
@	waitdooranim
@	goto LittlerootTown_EventScript_SetReceivedRunningShoes
@	end

LittlerootTown_EventScript_SetReceivedRunningShoes::
@	removeobject LOCALID_MOM
@	setflag FLAG_SYS_B_DASH
@	setvar VAR_LITTLEROOT_TOWN_STATE, 4
@	release
@	end

LittlerootTown_EventScript_GiveRunningShoes::
@	msgbox LittlerootTown_Text_WearTheseRunningShoes, MSGBOX_DEFAULT
@	playfanfare MUS_OBTAIN_ITEM
@	message LittlerootTown_Text_SwitchShoesWithRunningShoes
@	waitfanfare
@	setflag FLAG_RECEIVED_RUNNING_SHOES
@	msgbox LittlerootTown_Text_ExplainRunningShoes, MSGBOX_DEFAULT
@	msgbox LittlerootTown_Text_ComeHomeIfAnythingHappens, MSGBOX_DEFAULT
@	closemessage
@	delay 30
@	return

LittlerootTown_Text_OurNewHomeLetsGoInside:
@	.string "MOM: {PLAYER}, we're here, honey!\p"
@	.string "It must be tiring riding with our things\n"
@	.string "in the moving truck.\p"
@	.string "Well, this is LITTLEROOT TOWN.\p"
@	.string "How do you like it?\n"
@	.string "This is our new home!\p"
@	.string "It has a quaint feel, but it seems to be\n"
@	.string "an easy place to live, don't you think?\p"
@	.string "And, you get your own room, {PLAYER}!\n"
@	.string "Let's go inside.$"

LittlerootTown_Text_WaitPlayer:
@	.string "MOM: Wait, {PLAYER}!$"

LittlerootTown_Text_WearTheseRunningShoes:
@	.string "MOM: {PLAYER}! {PLAYER}! Did you\n"
@	.string "introduce yourself to PROF. BIRCH?\p"
@	.string "Oh! What an adorable POKéMON!\n"
@	.string "You got it from PROF. BIRCH. How nice!\p"
@	.string "You're your father's child, all right.\n"
@	.string "You look good together with POKéMON!\p"
@	.string "Here, honey! If you're going out on an\n"
@	.string "adventure, wear these RUNNING SHOES.\p"
@	.string "They'll put a zip in your step!$"

LittlerootTown_Text_SwitchShoesWithRunningShoes:
@	.string "{PLAYER} switched shoes with the\n"
@	.string "RUNNING SHOES.$"

LittlerootTown_Text_ExplainRunningShoes:
@	.string "MOM: {PLAYER}, those shoes came with\n"
@	.string "instructions.\p"
@	.string "“Press the B Button while wearing these\n"
@	.string "RUNNING SHOES to run extra-fast!\p"
@	.string "“Slip on these RUNNING SHOES and race\n"
@	.string "in the great outdoors!”$"

LittlerootTown_Text_ComeHomeIfAnythingHappens:
@	.string "… … … … … … … …\n"
@	.string "… … … … … … … …\p"
@	.string "To think that you have your very own\n"
@	.string "POKéMON now…\l"
@	.string "Your father will be overjoyed.\p"
@	.string "…But please be careful.\n"
@	.string "If anything happens, you can come home.\p"
@	.string "Go on, go get them, honey!$"

LittlerootTown_Text_CanUsePCToStoreItems:
@	.string "If you use a PC, you can store items\n"
@	.string "and POKéMON.\p"
@	.string "The power of science is staggering!$"

LittlerootTown_Text_BirchSpendsDaysInLab:
@	.string "PROF. BIRCH spends days in his LAB\n"
@	.string "studying, then he'll suddenly go out in\l"
@	.string "the wild to do more research…\p"
@	.string "When does PROF. BIRCH spend time\n"
@	.string "at home?$"

LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut:
@	.string "Um, um, um!\p"
@	.string "If you go outside and go in the grass,\n"
@	.string "wild POKéMON will jump out!$"

LittlerootTown_Text_DangerousIfYouDontHavePokemon:
@	.string "It's dangerous if you don't have\n"
@	.string "your own POKéMON.$"

LittlerootTown_Text_CanYouGoSeeWhatsHappening:
@	.string "Um, hi!\p"
@	.string "There are scary POKéMON outside!\n"
@	.string "I can hear their cries!\p"
@	.string "I want to go see what's going on,\n"
@	.string "but I don't have any POKéMON…\p"
@	.string "Can you go see what's happening\n"
@	.string "for me?$"

LittlerootTown_Text_YouSavedBirch:
@	.string "You saved PROF. BIRCH!\n"
@	.string "I'm so glad!$"

LittlerootTown_Text_GoodLuckCatchingPokemon:
@	.string "Are you going to catch POKéMON?\n"
@	.string "Good luck!$"

LittlerootTown_Text_TownSign:
@	.string "LITTLEROOT TOWN\n"
@	.string "“A town that can't be shaded any hue.”$"

LittlerootTown_Text_ProfBirchsLab:
@	.string "PROF. BIRCH'S POKéMON LAB$"

LittlerootTown_Text_PlayersHouse:
@	.string "{PLAYER}'s HOUSE$"

LittlerootTown_Text_ProfBirchsHouse:
@	.string "PROF. BIRCH'S HOUSE$"

LittlerootTown_Text_BirchSomethingToShowYouAtLab:
@	.string "PROF. BIRCH: Well, well, {PLAYER}{KUN}!\n"
@	.string "That was good work out there!\p"
@	.string "I knew there was something special\n"
@	.string "about you when I first saw you,\l"
@	.string "but I never expected this.\p"
@	.string "Oh, yes. Do you still have the POKéDEX\n"
@	.string "I gave you?\p"
@	.string "I have something to show you.\n"
@	.string "Let's go to my LAB.$"

EventScript_HMFlyPole_Text_0:
	.string "It's a bell.$"

Turpia_SloganBoard_Text_0:
	.string "Turpia Town\n“A Peaceful Passage”$"

Turpia_FulgurSign_Text_0:
	.string "“Fulgur”\nRowan family$"

Turpia_FulgurSign_Text_1:
	.string "“Fulgur”$"

Turpia_FlammaSign_Text_0:
	.string "“Flamma”\nLinnes family$"

Turpia_FlammaSign_Text_1:
	.string "“Flamma”$"

Turpia_LacusSign_Text_0:
	.string "“Lacus”\nCoriolis family$"

Turpia_LacusSign_Text_1:
	.string "“Lacus”$"

Turpia_FractalSign_Text_0:
	.string "“Fractal”\nFOR SALE!$"

Turpia_SpruceWhileBagPick_Text_0:
	.string "Prof. Spruce: Go ahead, {PLAYER}! I'm\n"
	.string "positively itching to see which\l"
	.string "Pokémon the three of you will be\l"
	.string "choosing.\p"
	.string "Just don't keep your pals waiting for\n"
	.string "too long, okay?$"

Turpia_DontRunAway_Text_0:
	.string "Prof. Spruce: Hey, where do you think\n"
	.string "you're scampering off to?\p"
	.string "Aren't you going to pick your first\n"
	.string "Pokémon?$"

Turpia_Celebration_Text_0:
	.string "Prof. Spruce: Thanks for coming here,\n"
	.string "you three. I've brought you here\l"
	.string "because you've reached a turning point\l"
	.string "in your lives.\p"
	.string "Now, I'd like you to take a good look at\n"
	.string "yourself. Gaze at your reflection in\l"
	.string "the water, and remember that sight.$"

Turpia_Celebration_Text_1:
	.string "Tori: …$"

Turpia_Celebration_Text_2:
	.string "{RIVAL}: Hmm…$"

Turpia_Celebration_Text_3:
	.string "Prof. Spruce: All set? Good.$"

Turpia_Celebration_Text_4:
	.string "Prof. Spruce: Inside this bag are three\n"
	.string "Pokémon.\p"
	.string "You can pick one each, and that Pokémon\n"
	.string "will be your first partner on the long\l"
	.string "journey ahead.\p"
	.string "Whoever gets to pick first, I'll leave to\n"
	.string "you.$"

Turpia_Celebration_Text_5:
	.string "Tori: Who should pick first?$"

Turpia_Celebration_Text_6:
	.string "Alyssa: I think it's fair if we let\n"
	.string "{PLAYER} pick first.\p"
	.string "After all, it wouldn't really be fair if\n"
	.string "we picked our Pokémon before him,\l"
	.string "right?$"

Turpia_Celebration_Text_7:
	.string "Basil: If you ask me, {PLAYER} should\n"
	.string "call dibs on the first.\p"
	.string "I don't exactly think it's fair for us to\n"
	.string "snatch away the Pokémon she might\l"
	.string "like.$"

Turpia_Celebration_Text_8:
	.string "Tori: Whichever works, really. For all I\n"
	.string "care, you can go first, {PLAYER}.$"

Turpia_Celebration_Text_9:
	.string "Alyssa: After you, {PLAYER}!$"

Turpia_Celebration_Text_10:
	.string "Basil: Go ahead, {PLAYER}!$"

Turpia_Celebration_Text_11:
	.string "Alyssa: We did tie as winners in the\n"
	.string "competition, so…\p"
	.string "How about we let {PLAYER} pick first?\n"
	.string "I don't mind a little challenge!$"

Turpia_Celebration_Text_12:
	.string "Basil: Y'know, the three of us all won,\n"
	.string "so…\p"
	.string "I'll let {PLAYER} pick before me. That\n"
	.string "kind of challenge is just what I want!$"

Turpia_Celebration_Text_13:
	.string "Tori: Fine by me. I don't care about the\n"
	.string "order myself, but if it makes you\l"
	.string "happy… Go ahead, {PLAYER}.$"

Turpia_Celebration_Text_14:
	.string "Alyssa: Oh, I'm excited now!$"

Turpia_Celebration_Text_15:
	.string "Basil: Can't wait to see what you pick!$"

Turpia_Celebration_Text_16:
	.string "Alyssa: The winner deserves to have the\n"
	.string "first say, in my opinion.\p"
	.string "Pick whichever one you'd like,\n"
	.string "{PLAYER}! I'll choose mine once\l"
	.string "you're done.$"

Turpia_Celebration_Text_17:
	.string "Basil: If you ask me, it's only right that\n"
	.string "the winner goes first.\p"
	.string "As far as I care, you can go ahead and\n"
	.string "pick one, {PLAYER}! I'll go after you.$"

Turpia_Celebration_Text_18:
	.string "Tori: Don't worry. I don't mind going\n"
	.string "last. You two are more excited about\l"
	.string "this than I am, anyhow.$"

Turpia_Celebration_Text_19:
	.string "Alyssa: Now I can feel the tension!\n"
	.string "Don't dawdle on it, {PLAYER}!$"

Turpia_Celebration_Text_20:
	.string "Basil: The suspense! C'mon, don't keep\n"
	.string "us waiting too long, {PLAYER}!$"

Turpia_BagPickStarter_Text_0:
	.string "Prof. Spruce: You've made up your mind,\n"
	.string "huh? Congrats on obtaining your first\l"
	.string "Pokémon!\p"
	.string "{PLAYER} received the\n"
	.string "{STR_VAR_1}!$"

Turpia_BagPickStarter_Text_1:
	.string "Prof. Spruce: Are you giving it a\n"
	.string "nickname? No one's stopping you, but\l"
	.string "no one's forcing you, either.$"

Turpia_BagPickStarter_Text_2:
	.string "Alyssa: Okay, then this one will be mine!\p"
	.string "Alyssa received the {STR_VAR_2}!$"

Turpia_BagPickStarter_Text_3:
	.string "Basil: Right, then I'll be taking this\n"
	.string "one!\p"
	.string "Basil received the {STR_VAR_2}!$"

Turpia_BagPickStarter_Text_4:
	.string "Tori: Yeah, okay, I'll have this one,\n"
	.string "then.\p"
	.string "Tori received the {STR_VAR_3}!$"

Turpia_BagPickStarter_Text_5:
	.string "Prof. Spruce: Whoops! Hahahaha… Seems\n"
	.string "I got an interview coming up over in\l"
	.string "Borago City.\p"
	.string "I'm sorry, but can you three come pick\n"
	.string "up your Pokédexes in my lab? It's in\l"
	.string "Borago City, right across Route 1.\p"
	.string "I need to hurry now, so I'll see you\n"
	.string "there!$"

Turpia_BagPickStarter_Text_6:
	.string "Alyssa: Now that we all have our first\n"
	.string "Pokémon… There's only one thing left\l"
	.string "to do!$"

Turpia_BagPickStarter_Text_7:
	.string "Basil: We all have our first Pokémon\n"
	.string "now… You know what that means, right?\l"
	.string "I bet you do!$"

Turpia_BagPickStarter_Text_8:
	.string "Tori: Oh. Right. {PLAYER}, let's get\n"
	.string "this over with, shall we? I'll take you\l"
	.string "on first.$"

Turpia_BagPickStarter_Text_9:
	.string "Alyssa: Aww…$"

Turpia_BagPickStarter_Text_10:
	.string "Basil: Aw…$"

Turpia_BagPickStarter_Text_11:
	.string "Tori: You can let loose once I'm done,\n"
	.string "{RIVAL}. Be patient.\p"
	.string "Anyway, let's do this.$"

Turpia_Celebration_Cont_A_Text_0:
	.string "Alyssa: That was the best! All right, you\n"
	.string "ready, {PLAYER}?\p"
	.string "You better be, because I'm not going\n"
	.string "easy on you!$"

Turpia_Celebration_Cont_A_Text_1:
	.string "Basil: That was awesome! Okay, now it's\n"
	.string "my turn!\p"
	.string "I'm not gonna hold anything back,\n"
	.string "{PLAYER}, so better give this your\l"
	.string "all!$"

Turia_Celebration_Cont_B_Text_0:
	.string "Alyssa: Whew! I'm going right ahead,\n"
	.string "since I don't plan on standing around\l"
	.string "all day! Catch you in Borago!$"

Turia_Celebration_Cont_B_Text_1:
	.string "Basil: Whew! I don't know about you, but\n"
	.string "I'm not gonna waste any more time! See\l"
	.string "you both in Borago!$"

Turia_Celebration_Cont_B_Text_2:
	.string "Tori: And there she goes. Sheesh, where\n"
	.string "does she get all that energy from?\p"
	.string "Oh, well… I guess I'd better get going,\n"
	.string "too. We'll see each other again in\l"
	.string "Borago.$"

Turia_Celebration_Cont_B_Text_3:
	.string "Tori: And there he goes. Sheesh, where\n"
	.string "does he get all that energy from?\p"
	.string "Oh, well… I guess I'd better get going,\n"
	.string "too. We'll see each other again in\l"
	.string "Borago.$"

Turpia_NoAccessR1_Text_0:
	.string "Aide Wicker: Oh, hey! The Professor is\n"
	.string "still getting things ready.\p"
	.string "Why don't you go look for your pals in\n"
	.string "the meantime?$"

Turpia_ScientistR1Block_Text_0:
	.string "Aide Wicker: The Professor is still\n"
	.string "getting things ready.\p"
	.string "Why don't you go look for your pals in\n"
	.string "the meantime?$"

Turpia_SigurdCameo_Text_0:
	.string "{PLAYER}, {RIVAL}, Tori… Something\n"
	.string "tells me I will hear from you again.$"

Turpia_SigurdCameo_Text_1:
	.string "Hmmm… Quite a fine piece of\n"
	.string "architecture, indeed…$"

Turpia_SigurdCameo_Text_2:
	.string "Ah, hello, young one. I see this villa has\n"
	.string "piqued your interest, too.\p"
	.string "Now that I take another look at you, I'm\n"
	.string "reminded…\p"
	.string "Isn't there some sort of competition\n"
	.string "going on?$"

Turpia_SigurdCameo_Text_3:
	.string "Now that I take another look at you, I'm\n"
	.string "reminded…\p"
	.string "Isn't there some sort of competition\n"
	.string "going on?$"

Turpia_BeachLady_Text_0:
	.string "Aaaah… Gentle waves, rustling grass, a\n"
	.string "pleasant breeze…\p"
	.string "This really is the place to be, holiday\n"
	.string "or not.$"

Turpia_LittleKiddo_Text_0:
	.string "I'd love to cross the sea someday. I\n"
	.string "want to know what lies on the other\l"
	.string "side of the water…\p"
	.string "Aw, I wish I had my own Pokémon!$"

Turpia_Fisherman_Text_0:
	.string "Always a fresh bite in Turpia!\p"
	.string "There's nothing the people of Borago\n"
	.string "won't do for some fresh fish, and I'm\l"
	.string "here to deliver!$"

Turpia_RealEstateGuy_Text_0:
	.string "Would you look at this, young man! This\n"
	.string "brand-new villa's construction\l"
	.string "finished mere weeks ago.\p"
	.string "It's the perfect vacation getaway,\n"
	.string "right by the quiet beach of Turpia…\l"
	.string "Isn't it just idyllic?\p"
	.string "And it can be yours for only ¥500,000!\n"
	.string "What do you say?$"

Turpia_RealEstateGuy_Text_1:
	.string "Would you look at this, young lady! This\n"
	.string "brand-new villa's construction\l"
	.string "finished mere weeks ago.\p"
	.string "It's the perfect vacation getaway,\n"
	.string "right by the quiet beach of Turpia…\l"
	.string "Isn't it just idyllic?\p"
	.string "And it can be yours for only ¥500,000!\n"
	.string "What do you say?$"

Turpia_RealEstateGuy_Text_2:
	.string "U have money but this dont work yet$"

Turpia_RealEstateGuy_Text_3:
	.string "Hmm, it seems you need to save up some\n"
	.string "more…$"

Turpia_RealEstateGuy_Text_4:
	.string "Ah… I see.$"

Turpia_ProtaSquad_C_Text_0:
	.string "Alyssa: There's the Professor!\p"
	.string "I think we can cut a path through the\n"
	.string "tall grass to reach him!\p"
	.string "I don't see any issues with that, at\n"
	.string "least.$"

Turpia_ProtaSquad_C_Text_1:
	.string "Basil: Hey, I can see the Professor,\n"
	.string "right there!\p"
	.string "We just gotta go through the grass to\n"
	.string "reach him.\p"
	.string "What's the worst that could happen?$"

Turpia_ProtaSquad_C_Text_2:
	.string "Tori: Are you sure about this? I mean,\n"
	.string "what if a wild Pokémon jumped at us?$"

Turpia_ProtaSquad_C_Text_3:
	.string "Alyssa: I know there's a chance we may\n"
	.string "get attacked, and that'd be pretty\l"
	.string "bad…\p"
	.string "But at the same time, I just can't\n"
	.string "resist the urge!$"

Turpia_ProtaSquad_C_Text_4:
	.string "Basil: I mean, yeah, there's a chance\n"
	.string "that may happen, and we'd be outta luck\l"
	.string "if it did…\p"
	.string "But you'll never know unless you chance\n"
	.string "it!$"

Turpia_ProtaSquad_C_Text_5:
	.string "Tori: Hmmmm… What do you think,\n"
	.string "{PLAYER}? I trust your judgment.$"

Turpia_ProtaSquad_C_Text_6:
	.string "Tori: Yeah, same here. I'd rather not\n"
	.string "risk doing anything stupid.$"

Turpia_ProtaSquad_C_Text_7:
	.string "Alyssa: I don't get why you're both\n"
	.string "being so cautious.\p"
	.string "Come on, let's just give this a shot!$"

Turpia_ProtaSquad_C_Text_8:
	.string "Basil: Aw, c'mon, do you really need to be\n"
	.string "such wimps?\p"
	.string "Let's just go already! You'll never know\n"
	.string "unless you try!$"

Turpia_ProtaSquad_C_Text_9:
	.string "Alyssa: See? No need to be such a\n"
	.string "worrywart, Tori!$"

Turpia_ProtaSquad_C_Text_10:
	.string "Basil: See? We're gonna be fine! C'mon,\n"
	.string "let's go!$"

Turpia_ProtaSquad_C_Text_11:
	.string "Tori: Hmm…$"

Turpia_ProtaSquad_C_Text_12:
	.string "Tori: Aaaaah! Help! P-Pokémon!$"

Turpia_ProtaSquad_C_Text_13:
	.string "Aide Wicker: Hold on, you three! Don't\n"
	.string "move! I've got you covered!$"

Turpia_ProtaSquad_C_Text_14:
	.string "Aide Wicker: Phew! That's been taken\n"
	.string "care of.\p"
	.string "I don't know what you three were\n"
	.string "thinking, going through the grass\l"
	.string "without your own Pokémon…\p"
	.string "Ah, well. At least you're safe and sound.$"

Turpia_ProtaSquad_C_Text_15:
	.string "Alyssa: Whew! That was pretty tense,\n"
	.string "huh?$"

Turpia_ProtaSquad_C_Text_16:
	.string "Basil: Phooey, hahahaha! Talk about a\n"
	.string "thrill, right?$"

Turpia_ProtaSquad_C_Text_17:
	.string "Tori: That was kinda scary, I won't lie…\n"
	.string "I'm glad the scientist guy could bail us\l"
	.string "out.$"

Turpia_ProtaSquad_C_Text_18:
	.string "Alyssa: Maybe I should've known that we\n"
	.string "could've gotten attacked…\p"
	.string "But hey, fortune favors the bold, as\n"
	.string "they say!$"

Turpia_ProtaSquad_C_Text_19:
	.string "Tori: Yeah, but a little caution goes a\n"
	.string "long way, Alyssa! We could've gotten\l"
	.string "hurt!$"

Turpia_ProtaSquad_C_Text_20:
	.string "Alyssa: No need to make a big fuss over\n"
	.string "it, Tori. All's well that ends well.$"

Turpia_ProtaSquad_C_Text_21:
	.string "Basil: Didn't think we'd get jumped by\n"
	.string "that Pokémon, but hey, guess that's\l"
	.string "what we signed up for!$"

Turpia_ProtaSquad_C_Text_22:
	.string "Tori: How can you be so relaxed about\n"
	.string "this, Basil? We could've gotten hurt!$"

Turpia_ProtaSquad_C_Text_23:
	.string "Basil: Yeah, but we didn't, so I wouldn't\n"
	.string "dwell on it.$"

Turpia_ProtaSquad_C_Text_24:
	.string "Tori: Hmph. I didn't feel good about it\n"
	.string "to begin with…$"

Turpia_ProtaSquad_C_Text_25:
	.string "Alyssa: Ah, well. Let's continue!$"

Turpia_ProtaSquad_C_Text_26:
	.string "Basil: Whatever, let's just move it.$"

Turpia_ProtaSquad_C_Text_27:
	.string "Prof. Spruce: Welcome, one and all, to\n"
	.string "the final round of the Pokémon\l"
	.string "Conservation Cup!\p"
	.string "For that, you already have my\n"
	.string "congratulations. I'd also like to thank\l"
	.string "all of you for participating so\l"
	.string "enthusiastically.\p"
	.string "Now, onto the main event! Your task is\n"
	.string "to capture as many Pokémon as you can\l"
	.string "with the Venture Balls you are given.\p"
	.string "The person who captures the most\n"
	.string "Pokémon wins the competition!\p"
	.string "That's easy enough, right? All right,\n"
	.string "off you go!$"

Turpia_ProtaSquad_C_Text_28:
	.string "{PLAYER} received 5 Venture Balls.$"

Turpia_Defeat_Tori::
	.string "Guess that's over and done with, then.$"

Turpia_Defeat_Basil::
	.string "That was a blast! I won't lose next\ntime, though!$"

Turpia_Defeat_Alyssa::
	.string "That was awesome! I'll come out on top\nnext time, though!$"
