EverGrandeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Borago_Outside_OnTransition
	.byte 0


FamilyEventA::
	lockall
	applymovement 5, Common_Movement_ExclamationMark
	applymovement 6, Common_Movement_ExclamationMark
	waitmovement 0
	goto FamilyEventC
	return


FamilyEventB::
	lockall
	applymovement 5, Common_Movement_ExclamationMark
	applymovement 6, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	goto FamilyEventC
	return


FamilyEventC::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	msgbox FamilyEventC_Text_0
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
	message FamilyEventC_Text_1
	setflag FLAG_SYS_MATCH_CALL_GET
	waitfanfare
	msgbox FamilyEventC_Text_2
	closemessage
	delay 20
	special OpenPokenavForTutorial
	waitstate
	delay 20
	applymovement 3, FamilyEvent_RivalMove1
	applymovement 4, FamilyEvent_ToriMove1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox FamilyEventC_Text_3
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox FamilyEventC_Text_4, MSGBOX_DEFAULT
	waitfanfare
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox FamilyEventC_Text_5, MSGBOX_DEFAULT
	waitfanfare
	delay 30
	closemessage
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, Family_Event_CameraMoveA
	waitmovement 0
	applymovement 8, Common_Movement_WalkLeft
	waitmovement 0
	removeobject 8
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject 7
	waitfieldeffect FLDEFF_NPCFLY_OUT
	applymovement OBJ_EVENT_ID_CAMERA, Family_Event_CameraMoveB
	waitmovement 0
	applymovement 10, Common_Movement_WalkUp
	waitmovement 0
	removeobject 10
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject 9
	waitfieldeffect FLDEFF_NPCFLY_OUT
	applymovement OBJ_EVENT_ID_CAMERA, Family_Event_CameraMoveC
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox FamilyEventC_Text_6
	closemessage
	applymovement OBJ_EVENT_ID_CAMERA, Family_Event_CameraMoveD
	waitmovement 0
	applymovement 5, Common_Movement_WalkLeft
	waitmovement 0
	removeobject 5
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject 6
	waitfieldeffect FLDEFF_NPCFLY_OUT
	applymovement OBJ_EVENT_ID_CAMERA, Family_Event_CameraMoveE
	waitmovement 0
	special RemoveCameraObject
	msgbox FamilyEventC_Text_7
	closemessage
	setvar VAR_PETALBURG_WOODS_STATE, 4
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
	setflag FLAG_ENABLE_WALLY_MATCH_CALL
	setflag FLAG_GRC_HIDE_FAMILY_BORAGO
	releaseall
	return


Family_Event_CameraMoveA:
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end

Family_Event_CameraMoveB:
	walk_slow_left
	walk_slow_left
	walk_slow_diag_southwest
	step_end

Family_Event_CameraMoveC:
	walk_slow_diag_southeast
	walk_slow_diag_southeast
	walk_slow_diag_southeast
	step_end

Family_Event_CameraMoveD:
	walk_slow_up
	step_end

Family_Event_CameraMoveE:
	walk_slow_down
	step_end

FamilyEvent_RivalMove1:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_in_place_fastest_right
	step_end

FamilyEvent_ToriMove1:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_in_place_fastest_right
	step_end

SpotByAide1::
	call SpotByAide_PartA
	applymovement 2, SpotByAide_MoveFastLeft
	waitmovement 0
	call SpotByAide_PartB
	applymovement OBJ_EVENT_ID_PLAYER, SpotByAide_Player_MovLeft
	applymovement 2, SpotByAide_Aide_MovLeft
	call SpotByAide_PartC
	return


SpotByAide2::
	call SpotByAide_PartA
	call SpotByAide_PartB
	applymovement OBJ_EVENT_ID_PLAYER, SpotByAide_Player_MovRight
	applymovement 2, SpotByAide_Aide_MovRight
	call SpotByAide_PartC
	return


SpotByAide_PartA::
	lockall
	setvar VAR_BIRCH_LAB_STATE, 1
	applymovement 2, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	return


SpotByAide_PartB::
	applymovement 2, SpotByAideMovementA
	waitmovement 0
	msgbox SpotByAide_PartB_Text_0
	closemessage
	return


SpotByAide_PartC::
	waitmovement 0
	opendoor 21, 69
	waitdooranim
	applymovement 2, SpotByAide_Aide_MoveInside
	applymovement OBJ_EVENT_ID_PLAYER, SpotByAide_Player_MoveInside
	waitmovement 0
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	closedoor 21, 69
	waitdooranim
	setflag FLAG_GRC_HIDE_AIDE_BORAGO
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
	warpsilent MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 0, 0, 0
	waitstate
	releaseall
	return


SpotByAide_Aide_MoveInside:
	walk_up
	set_invisible
	step_end

SpotByAide_Player_MoveInside:
	walk_right
	walk_up
	step_end

SpotByAide_MoveFastLeft:
	walk_fast_left
	step_end

SpotByAideMovementA:
	walk_fast_up
	walk_fast_up
	step_end

SpotByAide_Aide_MovRight:
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_in_place_fast_up
	step_end

SpotByAide_Aide_MovLeft:
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_in_place_fast_up
	step_end

SpotByAide_Player_MovRight:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SpotByAide_Player_MovLeft:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

Borago_Outside_OnTransition:
	setflag FLAG_VISITED_EVER_GRANDE_CITY
	call Common_EventScript_SetupRivalGfxId
	end

@EverGrandeCity_MapScripts::
@	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_OnTransition
@	.byte 0

EverGrandeCity_OnTransition:
@	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
@	end

EverGrandeCity_EventScript_VictoryRoadSign::
@	msgbox EverGrandeCity_Text_EnteringVictoryRoad, MSGBOX_SIGN
@	end

EverGrandeCity_EventScript_CitySign::
@	msgbox EverGrandeCity_Text_CitySign, MSGBOX_SIGN
@	end

EverGrandeCity_EventScript_PokemonLeagueSign::
@	msgbox EverGrandeCity_Text_EnteringPokemonLeague, MSGBOX_SIGN
@	end

EverGrandeCity_EventScript_SetVisitedEverGrande::
@	setflag FLAG_VISITED_EVER_GRANDE_CITY
@	setvar VAR_TEMP_1, 1
@	end

EverGrandeCity_Text_EnteringVictoryRoad:
@	.string "ENTERING VICTORY ROAD$"

EverGrandeCity_Text_EnteringPokemonLeague:
@	.string "ENTERING POKéMON LEAGUE\n"
@	.string "CENTER GATE$"

EverGrandeCity_Text_CitySign:
@	.string "EVER GRANDE CITY\p"
@	.string "“The paradise of flowers, the sea,\n"
@	.string "and POKéMON.”$"

FamilyEventC_Text_0:
	.string "hey here's a match call$"

FamilyEventC_Text_1:
	.string "{PLAYER} received the Match Call Drive!$"

FamilyEventC_Text_2:
	.string "please call either of us to try it$"

FamilyEventC_Text_3:
	.string "oy we should register too$"

FamilyEventC_Text_4:
	.string "Registered {RIVAL} in the P-Drive.$"

FamilyEventC_Text_5:
	.string "Registered Tori in the P-Drive.$"

FamilyEventC_Text_6:
	.string "aye we be off too$"

FamilyEventC_Text_7:
	.string "end$"

SpotByAide_PartB_Text_0:
	.string "omg u so late hurry up already$"
