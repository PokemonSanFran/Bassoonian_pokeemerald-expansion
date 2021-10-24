Route101_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route1_FacePlayer
	map_script MAP_SCRIPT_ON_TRANSITION, Route1_onTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route1_onFrame
	map_script MAP_SCRIPT_ON_RESUME, Route1_onResume
	.byte 0


Route1_onTransition:
	call Common_EventScript_SetupRivalGfxId
	call Route1_GatherPeeps
	call ProfBirch_EventScript_UpdateLocation
	end
	
Route1_onFrame:
	map_script_2 VAR_GRC_ROUTE1_STATE, 2, Route1_finalisetutorial
	.2byte 0

Route1_FacePlayer:
	map_script_2 VAR_GRC_ROUTE1_STATE, 2, Route1_FacePlayerOccur
	.2byte 0

Route1_onResume::
	compare VAR_GRC_ROUTE1_STATE, 1
	goto_if_eq Route1_onResume_1
	return

Route1_onResume_1:
	setvar VAR_TEMP_1, 0
	special SafariBallsLeft
	compare VAR_RESULT, 5
	goto_if_eq Route1_onResume_4
	compare VAR_RESULT, 3
	goto_if_gt Route1_onResume_8
Route1_onResume_6:
	compare VAR_RESULT, 2
	goto_if_gt Route1_onResume_13
Route1_onResume_11:
	compare VAR_RESULT, 1
	goto_if_gt Route1_onResume_18
Route1_onResume_16:
	compare VAR_RESULT, 1
	goto_if_eq Route1_onResume_22
	return

Route1_onResume_4:
	end

Route1_onResume_7:
	setobjectxyperm 11, 1, 5
	setobjectxyperm 12, 1, 4
	setobjectmovementtype 11, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype 12, MOVEMENT_TYPE_FACE_LEFT
	setvar VAR_TEMP_1, 1
	end

Route1_onResume_8:
	compare VAR_TEMP_0, 1
	goto_if_ne Route1_onResume_7
	goto Route1_onResume_6

Route1_onResume_12:
	setobjectxyperm 11, 9, 6
	setobjectxyperm 12, 8, 6
	setobjectmovementtype 11, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype 12, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype 10, MOVEMENT_TYPE_FACE_DOWN
	setvar VAR_TEMP_1, 2
	end

Route1_onResume_13:
	compare VAR_TEMP_0, 2
	goto_if_ne Route1_onResume_12
	goto Route1_onResume_11

Route1_onResume_17:
	setobjectxyperm 11, 14, 10
	setobjectxyperm 12, 14, 9
	setobjectmovementtype 11, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype 12, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype 3, MOVEMENT_TYPE_FACE_LEFT
	setvar VAR_TEMP_1, 3
	end

Route1_onResume_18:
	compare VAR_TEMP_0, 3
	goto_if_ne Route1_onResume_17
	goto Route1_onResume_16

Route1_onResume_21:
	setobjectxyperm 11, 13, 19
	setobjectxyperm 12, 12, 19
	setobjectmovementtype 11, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype 12, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype 7, MOVEMENT_TYPE_FACE_DOWN
	setvar VAR_TEMP_1, 4
	end

Route1_onResume_22:
	compare VAR_TEMP_0, 4
	goto_if_ne Route1_onResume_21
	return


Route1_ResetGrassPatch::
	setvar VAR_TEMP_0, 0
	return


Route1_SetGrassPatchA::
	setvar VAR_TEMP_0, 1
	return


Route1_SetGrassPatchB::
	setvar VAR_TEMP_0, 2
	return


Route1_SetGrassPatchC::
	setvar VAR_TEMP_0, 3
	return


Route1_SetGrassPatchD::
	setvar VAR_TEMP_0, 4
	return


Route1_FacePlayerOccur::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	end


Route1_finalisetutorial::
	lockall
	msgbox Route1_finalisetutorial_Text_0
	closemessage
	getpartysize
	compare VAR_RESULT, 0
	goto_if_eq Route1_finalisetutorial_2
	compare VAR_RESULT, 1
	goto_if_eq Route1_finalisetutorial_3
	msgbox Route1_finalisetutorial_Text_13
	closemessage
	applymovement 7, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox Route1_finalisetutorial_Text_14
	closemessage
	applymovement 2, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox Route1_finalisetutorial_Text_15
	closemessage
	applymovement 3, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route1_finalisetutorial_16
	msgbox Route1_finalisetutorial_Text_17
Route1_finalisetutorial_15:
	closemessage
	applymovement 2, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox Route1_finalisetutorial_Text_18
	closemessage
	applymovement 7, Common_Movement_WalkInPlaceFastestUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox Route1_finalisetutorial_Text_19
	closemessage
	applymovement 3, Common_Movement_WalkInPlaceFastestDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	compare VAR_RESULT, MALE
	goto_if_eq Route1_finalisetutorial_24
	msgbox Route1_finalisetutorial_Text_21
Route1_finalisetutorial_23:
	closemessage
	applymovement 7, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox Route1_finalisetutorial_Text_22
	closemessage
	applymovement 7, Common_Movement_WalkInPlaceFastestLeft
	applymovement 3, Common_Movement_WalkInPlaceFastestLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
Route1_finalisetutorial_1:
	applymovement 10, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox Route1_finalisetutorial_Text_23
	closemessage
	applymovement 8, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox Route1_finalisetutorial_Text_24
	closemessage
	applymovement 10, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox Route1_finalisetutorial_Text_25
	closemessage
	applymovement 9, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox Route1_finalisetutorial_Text_26
	closemessage
	applymovement 10, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox Route1_finalisetutorial_Text_27
	closemessage
	applymovement 12, Route1_AngryDeparture_Interviewer
	applymovement 10, Route1_AngryDeparture_Nicholas
	applymovement 9, Route1_AngryDeparture_Robin
	applymovement 8, Route1_AngryDeparture_Jack
	waitmovement 0
	msgbox Route1_finalisetutorial_Text_28
	closemessage
	setvar VAR_GRC_ROUTE1_STATE, 3
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	setflag FLAG_GRC_HIDE_TURPIA_SCIENTIST
	clearflag FLAG_GRC_HIDE_PROF_TURPIA
	clearflag FLAG_GRC_TURPIA_HIDE_RIVALS
	warp MAP_LITTLEROOT_TOWN, 255, 4, 14
	waitstate
	releaseall
	return

Route1_finalisetutorial_2:
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route1_finalisetutorial_8
	msgbox Route1_finalisetutorial_Text_2
Route1_finalisetutorial_7:
	closemessage
	msgbox Route1_finalisetutorial_Text_3
	closemessage
	applymovement 7, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox Route1_finalisetutorial_Text_4
	applymovement 2, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox Route1_finalisetutorial_Text_5
	closemessage
	applymovement 3, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	compare VAR_RESULT, MALE
	goto_if_eq Route1_finalisetutorial_20
	msgbox Route1_finalisetutorial_Text_7
Route1_finalisetutorial_19:
	closemessage
	goto Route1_finalisetutorial_1

Route1_finalisetutorial_3:
	msgbox Route1_finalisetutorial_Text_8
	closemessage
	applymovement 7, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox Route1_finalisetutorial_Text_9
	closemessage
	applymovement 3, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route1_finalisetutorial_12
	msgbox Route1_finalisetutorial_Text_11
Route1_finalisetutorial_11:
	closemessage
	applymovement 7, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox Route1_finalisetutorial_Text_12
	closemessage
	applymovement 3, Common_Movement_WalkInPlaceFastestLeft
	applymovement 7, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	goto Route1_finalisetutorial_1

Route1_finalisetutorial_8:
	msgbox Route1_finalisetutorial_Text_1
	goto Route1_finalisetutorial_7

Route1_finalisetutorial_12:
	msgbox Route1_finalisetutorial_Text_10
	goto Route1_finalisetutorial_11

Route1_finalisetutorial_16:
	msgbox Route1_finalisetutorial_Text_16
	goto Route1_finalisetutorial_15

Route1_finalisetutorial_20:
	msgbox Route1_finalisetutorial_Text_6
	goto Route1_finalisetutorial_19

Route1_finalisetutorial_24:
	msgbox Route1_finalisetutorial_Text_20
	goto Route1_finalisetutorial_23


Route1_AngryDeparture_Nicholas:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route1_AngryDeparture_Jack:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route1_AngryDeparture_Robin:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route1_AngryDeparture_Interviewer:
	walk_left
	walk_left
	walk_in_place_fastest_right
	step_end

Route1_GatherPeeps::
	compare VAR_GRC_ROUTE1_STATE, 0
	goto_if_eq Route1_GatherPeeps_2
	compare VAR_GRC_ROUTE1_STATE, 2
	goto_if_eq Route1_GatherPeeps_2
Route1_GatherPeeps_1:
	compare VAR_GRC_ROUTE1_STATE, 2
	goto_if_eq Route1_GatherPeeps_7
Route1_GatherPeeps_6:
	compare VAR_BIRCH_LAB_STATE, 5
	goto_if_eq Route1_GatherPeeps_9
	return

Route1_GatherPeeps_2:
	setobjectxyperm 2, 10, 3
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm 8, 12, 3
	setobjectmovementtype 8, MOVEMENT_TYPE_FACE_LEFT
	setobjectxyperm 9, 12, 2
	setobjectmovementtype 9, MOVEMENT_TYPE_FACE_LEFT
	setobjectxyperm 10, 12, 4
	setobjectmovementtype 10, MOVEMENT_TYPE_FACE_LEFT
	setobjectxyperm 11, 11, 2
	setobjectxyperm 12, 10, 4
	setobjectmovementtype 12, MOVEMENT_TYPE_FACE_RIGHT
	goto Route1_GatherPeeps_1

Route1_GatherPeeps_7:
	setobjectxyperm 3, 13, 2
	setobjectmovementtype 3, MOVEMENT_TYPE_FACE_LEFT
	setobjectxyperm 7, 13, 4
	setobjectmovementtype 7, MOVEMENT_TYPE_FACE_LEFT
	goto Route1_GatherPeeps_6

Route1_GatherPeeps_9:
	setobjectxyperm 4, 4, 14
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype 13, MOVEMENT_TYPE_FACE_LEFT
	return


R1_NoAccess_City::
	lockall
	applymovement 4, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	applymovement 4, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox R1_NoAccess_City_Text_0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	releaseall
	return


R1_ScientistCityBlock::
	msgbox R1_ScientistCityBlock_Text_0, MSGBOX_NPC
	return


R1_NoAccess_Home::
	lockall
	applymovement 2, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	applymovement 2, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox R1_NoAccess_Home_Text_0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	releaseall
	return


R1_ProfHomeBlock::
	msgbox R1_ProfHomeBlock_Text_0, MSGBOX_NPC
	return


R1_Event_Tori::
	msgbox R1_Event_Tori_Text_0, MSGBOX_NPC
	return


R1_Event_Nicholas::
	msgbox R1_Event_Nicholas_Text_0, MSGBOX_NPC
	return


R1_Event_Robin::
	msgbox R1_Event_Robin_Text_0, MSGBOX_NPC
	return


R1_Event_Jack::
	msgbox R1_Event_Jack_Text_0, MSGBOX_NPC
	return


R1_Event_Pam::
	msgbox R1_Event_Pam_Text_0, MSGBOX_NPC
	return


R1_Event_Mike::
	msgbox R1_Event_Mike_Text_0, MSGBOX_NPC
	return


R1_Event_Rival::
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq R1_Event_Rival_1
	msgbox R1_Event_Rival_Text_1, MSGBOX_NPC
	return

R1_Event_Rival_1:
	msgbox R1_Event_Rival_Text_0, MSGBOX_NPC
	return


Route101_EventScript_Youngster::
	msgbox Route101_EventScript_Youngster_Text_0, MSGBOX_NPC
	return


Route101_EventScript_Boy::
	msgbox Route101_EventScript_Boy_Text_0, MSGBOX_NPC
	return


Route101_Trigger_DexDrive_A::
	call Route101_Trigger_DexDrive_both_A
	clearflag FLAG_RECEIVED_RUNNING_SHOES
	addobject 4
	destroyfollower
	setobjectxy 4, 1, 15
	applymovement 4, R1_movement_player_threeright
	applymovement OBJ_EVENT_ID_PLAYER, R1_movement_player_threeright
	waitmovement 0
	call Route101_Trigger_DexDrive_both_B
	return


Route101_Trigger_DexDrive_B::
	call Route101_Trigger_DexDrive_both_A
	clearflag FLAG_RECEIVED_RUNNING_SHOES
	addobject 4
	destroyfollower
	setobjectxy 4, 1, 16
	applymovement 4, R1_movement_player_threerightB_aide
	applymovement OBJ_EVENT_ID_PLAYER, R1_movement_player_threerightB
	waitmovement 0
	call Route101_Trigger_DexDrive_both_B
	return


Route101_Trigger_DexDrive_both_A::
	lockall
	setvar VAR_BIRCH_LAB_STATE, 5
	applymovement 13, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	applymovement 13, Common_Movement_ExclamationMark
	waitmovement 0
	return


Route101_Trigger_DexDrive_both_B::
	applymovement 13, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox Route101_Trigger_DexDrive_both_B_Text_0
	closemessage
	applymovement 4, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox Route101_Trigger_DexDrive_both_B_Text_1
	closemessage
	applymovement 13, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox Route101_Trigger_DexDrive_both_B_Text_2
	closemessage
	applymovement 4, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox Route101_Trigger_DexDrive_both_B_Text_3
	closemessage
	applymovement 13, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox Route101_Trigger_DexDrive_both_B_Text_4
	closemessage
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 20
	playfanfare MUS_OBTAIN_ITEM
	message Route101_Trigger_DexDrive_both_B_Text_5
	setflag FLAG_SYS_DEXNAV_GET
	waitfanfare
	applymovement 13, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox Route101_Trigger_DexDrive_both_B_Text_6, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route101_Trigger_DexDrive_both_B_2
	call Route101_DexDrive_Tutorial_Accept
Route101_Trigger_DexDrive_both_B_1:
	call Route101_DexDriveTutorial_CleanUp
	return

Route101_Trigger_DexDrive_both_B_2:
	msgbox Route101_Trigger_DexDrive_both_B_Text_7
	closemessage
	applymovement 4, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox Route101_Trigger_DexDrive_both_B_Text_8
	closemessage
	applymovement 13, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox Route101_Trigger_DexDrive_both_B_Text_9
	closemessage
	applymovement 4, Common_Movement_WalkInPlaceFastestRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox Route101_Trigger_DexDrive_both_B_Text_10
	closemessage
	goto Route101_Trigger_DexDrive_both_B_1


Route101_DexDriveTutorial_CleanUp::
	applymovement 4, movement_R1_aide_leavestage
	applymovement 13, movement_R1_pollock_leavestage
	waitmovement 0
	removeobject 4
	applymovement 13, Common_Movement_WalkLeft
	waitmovement 0
	removeobject 13
	setflag FLAG_GRC_HIDE_POLLOCK_R1
	clearflag FLAG_GRC_HIDE_POLLOCK_LABS
	setflag FLAG_GRC_HIDE_MUSKETEERS_BORAGO_GATE
	setflag FLAG_GRC_HIDE_RIVALS_LAB
	setflag FLAG_RECEIVED_RUNNING_SHOES
	clearflag FLAG_HIDE_SAFARI_ZONE_SOUTH_CONSTRUCTION_WORKERS
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setvar VAR_BIRCH_LAB_STATE, 6
	releaseall
	return


Route101_DexDrive_Tutorial_Accept::
	msgbox Route101_DexDrive_Tutorial_Accept_Text_0
	closemessage
	msgbox Route101_DexDrive_Tutorial_Accept_Text_1
	closemessage
	special DexDriveTutorialR1_setfieldeffect
	applymovement 4, Common_Movement_WalkInPlaceFastestRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox Route101_DexDrive_Tutorial_Accept_Text_2
	closemessage
	applymovement 13, Common_Movement_WalkInPlaceFastestDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox Route101_DexDrive_Tutorial_Accept_Text_3
	closemessage
	applymovement 4, Common_Movement_WalkInPlaceFastestRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox Route101_DexDrive_Tutorial_Accept_Text_4
	closemessage
	giveitem ITEM_POKE_BALL, 5
	applymovement 4, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox Route101_DexDrive_Tutorial_Accept_Text_5
	closemessage
	applymovement 13, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox Route101_DexDrive_Tutorial_Accept_Text_6
	closemessage
	applymovement 4, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox Route101_DexDrive_Tutorial_Accept_Text_7
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, R1_movement_player_approachbush
	waitmovement 0
	setwildbattle SPECIES_SENTRET, 5, ITEM_ORAN_BERRY
	special DexDriveTutorialR1_setopponent
	dowildbattle
	applymovement OBJ_EVENT_ID_PLAYER, R1_movement_player_leavebush
	waitmovement 0
	applymovement 13, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Route101_DexDrive_Tutorial_Accept_2
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Route101_DexDrive_Tutorial_Accept_3
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq Route101_DexDrive_Tutorial_Accept_4
Route101_DexDrive_Tutorial_Accept_1:
	applymovement 13, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox Route101_DexDrive_Tutorial_Accept_Text_15
	closemessage
	applymovement 4, Common_Movement_WalkInPlaceFastestRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox Route101_DexDrive_Tutorial_Accept_Text_16
	closemessage
	applymovement 13, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox Route101_DexDrive_Tutorial_Accept_Text_17
	closemessage
	applymovement 4, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox Route101_DexDrive_Tutorial_Accept_Text_18
	closemessage
	applymovement 4, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox Route101_DexDrive_Tutorial_Accept_Text_19
	closemessage
	applymovement 13, Common_Movement_WalkInPlaceFastestDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox Route101_DexDrive_Tutorial_Accept_Text_20
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	return

Route101_DexDrive_Tutorial_Accept_2:
	msgbox Route101_DexDrive_Tutorial_Accept_Text_8
	closemessage
	applymovement 4, Common_Movement_WalkInPlaceFastestRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox Route101_DexDrive_Tutorial_Accept_Text_9
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	goto Route101_DexDrive_Tutorial_Accept_1

Route101_DexDrive_Tutorial_Accept_3:
	msgbox Route101_DexDrive_Tutorial_Accept_Text_10
	closemessage
	applymovement 4, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route101_DexDrive_Tutorial_Accept_9
	msgbox Route101_DexDrive_Tutorial_Accept_Text_12
Route101_DexDrive_Tutorial_Accept_8:
	closemessage
	goto Route101_DexDrive_Tutorial_Accept_1

Route101_DexDrive_Tutorial_Accept_4:
	msgbox Route101_DexDrive_Tutorial_Accept_Text_13
	closemessage
	applymovement 4, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox Route101_DexDrive_Tutorial_Accept_Text_14
	closemessage
	goto Route101_DexDrive_Tutorial_Accept_1

Route101_DexDrive_Tutorial_Accept_9:
	msgbox Route101_DexDrive_Tutorial_Accept_Text_11
	goto Route101_DexDrive_Tutorial_Accept_8


Route101_Trigger_DexDrive_C::
	call Route101_Trigger_DexDrive_both_C
	applymovement OBJ_EVENT_ID_PLAYER, R1_movement_player_threeright
	waitmovement 0
	call Route101_Trigger_DexDrive_both_D
	return


Route101_Trigger_DexDrive_D::
	call Route101_Trigger_DexDrive_both_C
	applymovement OBJ_EVENT_ID_PLAYER, R1_movement_player_threerightB
	waitmovement 0
	call Route101_Trigger_DexDrive_both_D
	return


Route101_Trigger_DexDrive_both_C::
	lockall
	applymovement 13, Common_Movement_WalkInPlaceFastestLeft
	applymovement 4, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	applymovement 13, Common_Movement_ExclamationMark
	applymovement 4, Common_Movement_ExclamationMark
	waitmovement 0
	return


Route101_Trigger_DexDrive_both_D::
	applymovement 4, Common_Movement_WalkDown
	waitmovement 0
	applymovement 4, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	applymovement 13, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox Route101_Trigger_DexDrive_both_D_Text_0
	closemessage
	applymovement 4, Common_Movement_WalkInPlaceFastestRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox Route101_Trigger_DexDrive_both_D_Text_1
	closemessage
	applymovement 13, Common_Movement_WalkInPlaceFastestDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	call Route101_DexDrive_Tutorial_Accept
	call Route101_DexDriveTutorial_CleanUp
	return


movement_R1_aide_leavestage:
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

movement_R1_pollock_leavestage:
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

R1_movement_player_threeright:
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

R1_movement_player_threerightB:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

R1_movement_player_threerightB_aide:
	walk_right
	walk_up
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

R1_movement_player_approachbush:
	walk_slow_down
	walk_slow_right
	walk_slow_right
	step_end

R1_movement_player_leavebush:
	walk_left
	walk_left
	walk_up
	step_end

.set LOCALID_BIRCH, 2
.set LOCALID_ZIGZAGOON, 4

@ Route101_MapScripts::
@	map_script MAP_SCRIPT_ON_TRANSITION, Route101_OnTransition
@	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route101_OnFrame
@	.byte 0

Route101_OnTransition:
@	call ProfBirch_EventScript_UpdateLocation
@	end

Route101_OnFrame:
@	map_script_2 VAR_GRC_ROUTE1_STATE, 0, Route101_EventScript_HideMapNamePopup
@	.2byte 0

Route101_EventScript_HideMapNamePopup::
@	setflag FLAG_HIDE_MAP_NAME_POPUP
@	setvar VAR_GRC_ROUTE1_STATE, 1
@	end

Route101_EventScript_StartBirchRescue::
@	lockall
@	playbgm MUS_HELP, TRUE
@	msgbox Route101_Text_HelpMe, MSGBOX_DEFAULT
@	closemessage
@	setobjectxy LOCALID_BIRCH, 0, 15
@	setobjectxy LOCALID_ZIGZAGOON, 0, 16
@	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_EnterScene
@	applymovement LOCALID_BIRCH, Route101_Movement_BirchRunAway1
@	applymovement LOCALID_ZIGZAGOON, Route101_Movement_ZigzagoonChase1
@	waitmovement 0
@	applymovement LOCALID_ZIGZAGOON, Route101_Movement_ZigzagoonChaseInCircles
@	applymovement LOCALID_BIRCH, Route101_Movement_BirchRunInCircles
@	waitmovement 0
@	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFastestRight
@	waitmovement 0
@	applymovement LOCALID_ZIGZAGOON, Route101_Movement_ZigzagoonFaceBirch
@	applymovement LOCALID_BIRCH, Route101_Movement_BirchFaceZigzagoon
@	waitmovement 0
@	msgbox Route101_Text_PleaseHelp, MSGBOX_DEFAULT
@	closemessage
@	setvar VAR_GRC_ROUTE1_STATE, 2
@	releaseall
@	end

Route101_EventScript_PreventExitSouth::
@	lockall
@	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
@	closemessage
@	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitSouth
@	waitmovement 0
@	releaseall
@	end

Route101_EventScript_PreventExitWest::
@	lockall
@	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
@	closemessage
@	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitWest
@	waitmovement 0
@	releaseall
@	end

Route101_EventScript_PreventExitNorth::
@	lockall
@	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
@	closemessage
@	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitNorth
@	waitmovement 0
@	releaseall
@	end

Route101_Movement_PreventExitSouth:
@	walk_up
@	step_end

Route101_Movement_PreventExitWest:
@	walk_right
@	step_end

Route101_Movement_PreventExitNorth:
@	walk_down
@	step_end

Route101_Movement_ZigzagoonChaseInCircles:
@	walk_fast_up
@	walk_fast_up
@	walk_fast_up
@	walk_fast_right
@	walk_fast_right
@	walk_fast_right
@	walk_fast_down
@	walk_fast_down
@	walk_fast_left
@	walk_fast_left
@	walk_fast_left
@	walk_fast_up
@	walk_fast_up
@	walk_fast_right
@	walk_fast_right
@	walk_fast_right
@	walk_fast_down
@	walk_fast_down
@	walk_fast_left
@	walk_fast_left
@	walk_fast_left
@	walk_fast_up
@	walk_fast_up
@	walk_fast_right
@	walk_fast_right
@	walk_fast_right
@	walk_fast_down
@	walk_fast_down
@	walk_fast_left
@	walk_fast_left
@	step_end

Route101_Movement_ZigzagoonChase1:
@	walk_fast_up
@	walk_fast_right
@	walk_fast_right
@	walk_fast_right
@	walk_fast_right
@	walk_fast_up
@	step_end

@ Leftover data? This command is unused.
@	step_end

Route101_Movement_ZigzagoonFaceBirch:
@	walk_in_place_fast_left
@	walk_in_place_fast_left
@	walk_in_place_fast_left
@	walk_in_place_fast_left
@	step_end

Route101_Movement_EnterScene:
@	walk_fast_up
@	walk_fast_up
@	walk_fast_up
@	walk_fast_up
@	walk_in_place_fastest_left
@	step_end

Route101_Movement_BirchRunInCircles:
@	walk_fast_up
@	walk_fast_up
@	walk_fast_right
@	walk_fast_right
@	walk_fast_right
@	walk_fast_down
@	walk_fast_down
@	walk_fast_left
@	walk_fast_left
@	walk_fast_left
@	walk_fast_up
@	walk_fast_up
@	walk_fast_right
@	walk_fast_right
@	walk_fast_right
@	walk_fast_down
@	walk_fast_down
@	walk_fast_left
@	walk_fast_left
@	walk_fast_left
@	walk_fast_up
@	walk_fast_up
@	walk_fast_right
@	walk_fast_right
@	walk_fast_right
@	walk_fast_down
@	walk_fast_down
@	walk_fast_left
@	walk_fast_left
@	walk_fast_left
@	step_end

Route101_Movement_BirchRunAway1:
@	walk_fast_right
@	walk_fast_right
@	walk_fast_right
@	walk_fast_right
@	walk_fast_up
@	walk_fast_up
@	step_end

@ Leftover data? This command is unused.
@	step_end

Route101_Movement_BirchFaceZigzagoon:
@	walk_in_place_fast_right
@	walk_in_place_fast_right
@	walk_in_place_fast_right
@	walk_in_place_fast_right
@	step_end

Route101_Movement_Unused1:
@	walk_up
@	walk_up
@	step_end

Route101_Movement_Unused2:
@	walk_up
@	walk_left
@	walk_up
@	step_end

Route101_EventScript_RouteSign::
	msgbox Route101_Text_RouteSign, MSGBOX_SIGN
	end

Route101_EventScript_BirchsBag::
@	lock
@	faceplayer
@	setflag FLAG_SYS_POKEMON_GET
@	setflag FLAG_RESCUED_BIRCH
@	fadescreen FADE_TO_BLACK
@	removeobject LOCALID_ZIGZAGOON
@	setobjectxy OBJ_EVENT_ID_PLAYER, 6, 13
@	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
@	waitmovement 0
@	special ChooseStarter
@	waitstate
@	applymovement LOCALID_BIRCH, Route101_Movement_BirchApproachPlayer
@	waitmovement 0
@	msgbox Route101_Text_YouSavedMe, MSGBOX_DEFAULT
@	special HealPlayerParty
@	setflag FLAG_GRC_R1_HIDE_BADDIES
@	clearflag FLAG_GRC_HIDE_PROF_TURPIA
@	setflag FLAG_GRC_HIDE_TURPIA_SCIENTIST
@	setvar VAR_BIRCH_LAB_STATE, 2
@	setvar VAR_GRC_ROUTE1_STATE, 3
@	clearflag FLAG_HIDE_MAP_NAME_POPUP
@	checkplayergender
@	compare VAR_RESULT, MALE
@	call_if_eq Route101_EventScript_HideMayInBedroom
@	compare VAR_RESULT, FEMALE
@	call_if_eq Route101_EventScript_HideBrendanInBedroom
@	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 255, 6, 5
@	waitstate
@	release
@	end

Route101_EventScript_HideMayInBedroom::
@	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
@	return

Route101_EventScript_HideBrendanInBedroom::
@	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
@	return

Route101_Movement_BirchApproachPlayer:
@	walk_right
@	step_end

Route101_Text_HelpMe:
@	.string "H-help me!$"

Route101_Text_PleaseHelp:
@	.string "Hello! You over there!\n"
@	.string "Please! Help!\p"
@	.string "In my BAG!\n"
@	.string "There's a POKé BALL!$"

Route101_Text_DontLeaveMe:
@	.string "Wh-Where are you going?!\n"
@	.string "Don't leave me like this!$"

Route101_Text_YouSavedMe:
@	.string "PROF. BIRCH: Whew…\p"
@	.string "I was in the tall grass studying wild\n"
@	.string "POKéMON when I was jumped.\p"
@	.string "You saved me.\n"
@	.string "Thanks a lot!\p"
@	.string "Oh?\p"
@	.string "Hi, you're {PLAYER}{KUN}!\p"
@	.string "This is not the place to chat, so come\n"
@	.string "by my POKéMON LAB later, okay?$"

Route101_Text_TakeTiredPokemonToPokeCenter:
@	.string "If POKéMON get tired, take them to\n"
@	.string "a POKéMON CENTER.\p"
@	.string "There's a POKéMON CENTER in OLDALE\n"
@	.string "TOWN right close by.$"

Route101_Text_WildPokemonInTallGrass:
@	.string "Wild POKéMON will jump out at you in\n"
@	.string "tall grass.\p"
@	.string "If you want to catch POKéMON, you have\n"
@	.string "to go into the tall grass and search.$"

Route101_Text_RouteSign:
	.string "Route 1\n"
	.string "{LEFT_ARROW} Borago City$"

Route1_finalisetutorial_Text_0:
	.string "Prof. Spruce: Alright, folks, here are\n"
	.string "the final results of the competition!$"

Route1_finalisetutorial_Text_1:
	.string "In third place is {PLAYER}! He failed\n"
	.string "to catch any Pokémon, but they scored\l"
	.string "well enough in the previous rounds to\l"
	.string "earn third place overall!$"

Route1_finalisetutorial_Text_2:
	.string "In third place is {PLAYER}! She failed\n"
	.string "to catch any Pokémon, but they scored\l"
	.string "well enough in the previous rounds to\l"
	.string "earn third place overall!$"

Route1_finalisetutorial_Text_3:
	.string "In second place is Tori!$"

Route1_finalisetutorial_Text_4:
	.string "Tori: Hm. Okay.$"

Route1_finalisetutorial_Text_5:
	.string "Prof. Spruce: And the winner is…\n"
	.string "{RIVAL}!$"

Route1_finalisetutorial_Text_6:
	.string "Alyssa: R-really? I'm the winner?!\p"
	.string "Hehehe, that's great! Ma and Pa will be\n"
	.string "so happy to hear it!$"

Route1_finalisetutorial_Text_7:
	.string "Basil: Whoa, what? I've won?! Hahahaha!\p"
	.string "Awesome! Can't wait to tell my old folks\n"
	.string "about it!$"

Route1_finalisetutorial_Text_8:
	.string "In third place is… No, wait! Let me get\n"
	.string "this right… We have three winners!\p"
	.string "It's a three-way tie between\n"
	.string "{PLAYER}, {RIVAL} and Tori!$"

Route1_finalisetutorial_Text_9:
	.string "Tori: Huh, what do you know. Neat, I\n"
	.string "guess.$"

Route1_finalisetutorial_Text_10:
	.string "Basil: Neat? That's rad! I can share my\n"
	.string "victory with both of you!$"

Route1_finalisetutorial_Text_11:
	.string "Alyssa: Neat? Now the three of us can\n"
	.string "cheer to our victory together!$"

Route1_finalisetutorial_Text_12:
	.string "Tori: I suppose so.$"

Route1_finalisetutorial_Text_13:
	.string "In third place is Tori!$"

Route1_finalisetutorial_Text_14:
	.string "Tori: Hm, okay.$"

Route1_finalisetutorial_Text_15:
	.string "Prof. Spruce: In second place is\n"
	.string "{RIVAL}!$"

Route1_finalisetutorial_Text_16:
	.string "Alyssa: Hey, that's not bad at all!\n"
	.string "Second place is not a bad place to be\l"
	.string "in.$"

Route1_finalisetutorial_Text_17:
	.string "Basil: Oh, hey, that's pretty good! It\n"
	.string "ain't first, but I'll gladly take second.$"

Route1_finalisetutorial_Text_18:
	.string "Prof. Spruce: And the winner of the CCP\n"
	.string "is {PLAYER}! Congratulations!$"

Route1_finalisetutorial_Text_19:
	.string "Tori: Grats.$"

Route1_finalisetutorial_Text_20:
	.string "Alyssa: Congrats, {PLAYER}! A\n"
	.string "well-earned victory! Oh, no offense,\l"
	.string "Tori…$"

Route1_finalisetutorial_Text_21:
	.string "Basil: Congrats, {PLAYER}! You\n"
	.string "deserve that win. No offense to you,\l"
	.string "Tori!$"

Route1_finalisetutorial_Text_22:
	.string "Tori: None taken.$"

Route1_finalisetutorial_Text_23:
	.string "Nicholas: Of course those pampered\n"
	.string "westerners have to come out on top…\p"
	.string "Ugh, I can't stand this! This whole\n"
	.string "thing feels rigged against our favor!\p"
	.string "And for what, just because we're from\n"
	.string "the east of the region?!$"

Route1_finalisetutorial_Text_24:
	.string "Jack: Pipe it down, Nicholas. Nothing\n"
	.string "good will come of such fury.$"

Route1_finalisetutorial_Text_25:
	.string "Nicholas: Grrr…$"

Route1_finalisetutorial_Text_26:
	.string "Robin: Look, Jack and I are just as\n"
	.string "upset as you, but we're fuming\l"
	.string "internally, not externally.\p"
	.string "Either way, I'm not gonna waste any\n"
	.string "more time here. These rich kids are\l"
	.string "making me sick to my stomach.$"

Route1_finalisetutorial_Text_27:
	.string "Nicholas: Right you are. Let's get outta\n"
	.string "here.$"

Route1_finalisetutorial_Text_28:
	.string "Prof. Spruce: What was that all about?\n"
	.string "Anyway, you three shouldn't be\l"
	.string "worrying about any of that.\p"
	.string "I'd like to meet you by the pond back in\n"
	.string "Turpia, in fact. I'll see you there!$"

R1_NoAccess_City_Text_0:
	.string "Aide Wicker: Uh, I don't think that's a\n"
	.string "good idea, {PLAYER}. The\l"
	.string "competition's still under way, you\l"
	.string "know?$"

R1_ScientistCityBlock_Text_0:
	.string "Aide Wicker: Hey, {PLAYER}! You look\n"
	.string "like you've bounced right back from the\l"
	.string "incident earlier.\p"
	.string "That's great! Best of luck with the\n"
	.string "competition!$"

R1_NoAccess_Home_Text_0:
	.string "Prof. Spruce: We're not done with the\n"
	.string "competition yet, {PLAYER}. Capisce?\l"
	.string "Off you go, then.$"

R1_ProfHomeBlock_Text_0:
	.string "Prof. Spruce: {PLAYER}! I can see the\n"
	.string "fire in your eyes.\p"
	.string "It's that kind of passion that makes\n"
	.string "the world go round. Can't wait to see\l"
	.string "what you've got!$"

R1_Event_Tori_Text_0:
	.string "Tori: Hmph. I'm not doing this for fun,\n"
	.string "you know. I'd rather just get this over\l"
	.string "with as quick as I can.$"

R1_Event_Nicholas_Text_0:
	.string "Nicholas: Don't get in my way. You're\n"
	.string "only gonna scare away the Pokémon like\l"
	.string "that. Hey, I said scram! Now!$"

R1_Event_Robin_Text_0:
	.string "Robin: What's your problem? Can't you go\n"
	.string "bother your little friends? Sheesh.$"

R1_Event_Jack_Text_0:
	.string "Jack: Leave.$"

R1_Event_Pam_Text_0:
	.string "Pam: Oh, it's {PLAYER}! Can't say I\n"
	.string "expected you to drop by like this!\p"
	.string "I see you're hard at work trying to win\n"
	.string "this challenge, but thanks for\l"
	.string "stopping by!\p"
	.string "We're rooting for all of you!$"

R1_Event_Mike_Text_0:
	.string "Cam: You got this, buster! I'll secure\n"
	.string "some awesome action shots!$"

R1_Event_Rival_Text_0:
	.string "Alyssa: I didn't it'd be this thrilling\n"
	.string "just to catch Pokémon!\p"
	.string "Not to mention this is going to help the\n"
	.string "Professor's research!\p"
	.string "Are you having fun, too, {PLAYER}?$"

R1_Event_Rival_Text_1:
	.string "Basil: Who knew just catching Pokémon\n"
	.string "was this exciting?\p"
	.string "And we're giving the Professor a hand\n"
	.string "all the while!\p"
	.string "Good luck out there, {PLAYER}!$"

Route101_EventScript_Youngster_Text_0:
	.string "Professor Spruce sure has a lot of\n"
	.string "energy… I guess he's just a really busy\l"
	.string "man!$"

Route101_EventScript_Boy_Text_0:
	.string "I tend to use a lot of Repels so I don't\n"
	.string "encounter wild Pokémon. I don't have\l"
	.string "any of my own, you see.$"

Route101_Trigger_DexDrive_both_B_Text_0:
	.string "Pollock: There you are, {PLAYER}! Good\n"
	.string "to see you.\p"
	.string "And I see a certain someone has tagged\n"
	.string "along…$"

Route101_Trigger_DexDrive_both_B_Text_1:
	.string "Aide Wicker: What's on the menu, old\n"
	.string "friend?$"

Route101_Trigger_DexDrive_both_B_Text_2:
	.string "Pollock: I'm glad you ask! I'd like to\n"
	.string "show {PLAYER} one of their most\l"
	.string "crucial P-Drive features: DexDrive!$"

Route101_Trigger_DexDrive_both_B_Text_3:
	.string "Aide Wicker: Ohhh, is it time?$"

Route101_Trigger_DexDrive_both_B_Text_4:
	.string "Pollock: Yes, it is! All righty,\n"
	.string "{PLAYER}, hand me your P-Drive for a\l"
	.string "moment.$"

Route101_Trigger_DexDrive_both_B_Text_5:
	.string "{PLAYER}'s P-Drive was upgraded\nwith the DexDrive!$"

Route101_Trigger_DexDrive_both_B_Text_6:
	.string "Pollock: All set! Now, do you know how to\n"
	.string "operate DexDrive?$"

Route101_Trigger_DexDrive_both_B_Text_7:
	.string "Pollock: Excellent! Then we won't be\n"
	.string "keeping you any longer, {PLAYER}.\p"
	.string "We hope you'll enjoy using DexDrive to\n"
	.string "the max!$"

Route101_Trigger_DexDrive_both_B_Text_8:
	.string "Aide Wicker: To the max? Pollock, don't\n"
	.string "embarrass yourself in front of\l"
	.string "teenagers.$"

Route101_Trigger_DexDrive_both_B_Text_9:
	.string "Pollock: Oh, come on! Anyway,\n"
	.string "{PLAYER}, thank you for your time.\p"
	.string "I'll be sure to call you for future\n"
	.string "updates to your P-Drive!$"

Route101_Trigger_DexDrive_both_B_Text_10:
	.string "Aide Wicker: Until next time, {PLAYER}!\n"
	.string "Best of luck!$"

Route101_DexDrive_Tutorial_Accept_Text_0:
	.string "All righty, {PLAYER}, could you\n"
	.string "activate the DexDrive feature?$"

Route101_DexDrive_Tutorial_Accept_Text_1:
	.string "(to be added)$"

Route101_DexDrive_Tutorial_Accept_Text_2:
	.string "Aide Wicker: Rustling grass?$"

Route101_DexDrive_Tutorial_Accept_Text_3:
	.string "Pollock: Yes, exactly! Now, approach the\n"
	.string "rustling grass quietly by holding {A_BUTTON}.\p"
	.string "Too much noise, and the Pokémon will\n"
	.string "flee.$"

Route101_DexDrive_Tutorial_Accept_Text_4:
	.string "Aide Wicker: Oh, do take these Poké\n"
	.string "Balls, {PLAYER}. You can never have\l"
	.string "enough, after all.$"

Route101_DexDrive_Tutorial_Accept_Text_5:
	.string "Aide Wicker: Do we watch now, old\n"
	.string "friend?$"

Route101_DexDrive_Tutorial_Accept_Text_6:
	.string "Pollock: We've got front-row seats, old\n"
	.string "pal.\p"
	.string "Right, let's keep our voices down now.$"

Route101_DexDrive_Tutorial_Accept_Text_7:
	.string "Aide Wicker: Remember, {PLAYER}…\p"
	.string "Hold {A_BUTTON}. Nice and slowly.$"

Route101_DexDrive_Tutorial_Accept_Text_8:
	.string "Pollock: An astounding performance! I\n"
	.string "knew you could do it.$"

Route101_DexDrive_Tutorial_Accept_Text_9:
	.string "Aide Wicker: Agreed! It seems you've\n"
	.string "more than gotten the hang of it,\l"
	.string "{PLAYER}.$"

Route101_DexDrive_Tutorial_Accept_Text_10:
	.string "Pollock: Well, I'll be. I didn't expect you\n"
	.string "to defeat it.$"

Route101_DexDrive_Tutorial_Accept_Text_11:
	.string "Aide Wicker: {PLAYER} might have\n"
	.string "caught this kind of Pokémon before.\p"
	.string "All good, though! It's his choice.$"

Route101_DexDrive_Tutorial_Accept_Text_12:
	.string "Aide Wicker: {PLAYER} might have\n"
	.string "caught this kind of Pokémon before.\p"
	.string "All good, though! It's her choice.$"

Route101_DexDrive_Tutorial_Accept_Text_13:
	.string "Pollock: Oh, you ran away from it?$"

Route101_DexDrive_Tutorial_Accept_Text_14:
	.string "Aide Wicker: Perhaps {PLAYER} simply\n"
	.string "wanted to let the Pokémon roam free.\p"
	.string "Either way, that's fine! Not to worry.$"

Route101_DexDrive_Tutorial_Accept_Text_15:
	.string "Pollock: Oh, that reminds me! Pokémon\n"
	.string "found with DexDrive tend to be a little\l"
	.string "different from any ordinary specimen.$"

Route101_DexDrive_Tutorial_Accept_Text_16:
	.string "Aide Wicker: Indeed! They're quicker to\n"
	.string "hold items than average.\p"
	.string "What's more, they may have a special\n"
	.string "Ability or a unique move!\p"
	.string "If you use DexDrive enough, you'll find\n"
	.string "just the right Pokémon for your team.$"

Route101_DexDrive_Tutorial_Accept_Text_17:
	.string "Pollock: That should wrap things up,\n"
	.string "then.\p"
	.string "Mind tagging along with me, old friend?\n"
	.string "Just be sure not to lag too far behind.$"

Route101_DexDrive_Tutorial_Accept_Text_18:
	.string "Aide Wicker: H-hey, come on! I've gotten\n"
	.string "a little faster compared to 20 years\l"
	.string "ago!$"

Route101_DexDrive_Tutorial_Accept_Text_19:
	.string "Aide Wicker: Anyway, {PLAYER}, thank\n"
	.string "you so much for your time. Be seeing\l"
	.string "you!$"

Route101_DexDrive_Tutorial_Accept_Text_20:
	.string "Pollock: If you need some advice from\n"
	.string "old man Pollock, you know where to find\l"
	.string "me! Till next time!$"

Route101_Trigger_DexDrive_both_D_Text_0:
	.string "Pollock: Ah, you're back! Can't win every\n"
	.string "fight in your life, so don't sweat it.$"

Route101_Trigger_DexDrive_both_D_Text_1:
	.string "Aide Wicker: Are you all set? Then let's\n"
	.string "try this again.$"
