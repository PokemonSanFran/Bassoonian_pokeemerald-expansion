EverGrandeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Borago_Outside_OnTransition
	.byte 0


Borago_POT_Keeper::
	lock
	faceplayer
	msgbox Borago_POT_Keeper_Text_0
	closemessage
	goto_if_set FLAG_BADGE03_GET, Borago_POT_Keeper_2
	msgbox Borago_POT_Keeper_Text_3
	closemessage
Borago_POT_Keeper_1:
	release
	return

Borago_POT_Keeper_2:
	msgbox Borago_POT_Keeper_Text_1
	closemessage
	msgbox Borago_POT_Keeper_Text_2
	goto Borago_POT_Keeper_1


Borago_TownSign::
	msgbox Borago_TownSign_Text_0, MSGBOX_SIGN
	return


Borago_Psychic::
	msgbox Borago_Psychic_Text_0, MSGBOX_NPC
	return


Borago_Gentleman::
	msgbox Borago_Gentleman_Text_0, MSGBOX_NPC
	return


Borago_ContestDuo::
	lock
	applymovement 13, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox Borago_ContestDuo_Text_0
	closemessage
	applymovement 14, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox Borago_ContestDuo_Text_1
	closemessage
	applymovement 13, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox Borago_ContestDuo_Text_2
	closemessage
	applymovement 14, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox Borago_ContestDuo_Text_3
	closemessage
	release
	return


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

Borago_POT_Keeper_Text_0:
	.string "Whoa, buster! I don't think it's a good\n"
	.string "idea for you to come here just yet.\p"
	.string "Let's see, how many Badges have you\n"
	.string "earned?$"

Borago_POT_Keeper_Text_1:
	.string "Impressive stuff! Now, I'll just have to\n"
	.string "test you in person.\p"
	.string "I'm not going easy on you, so you better\n"
	.string "give this your all!$"

Borago_POT_Keeper_Text_2:
	.string "Whew! Been a while since I've last had a\n"
	.string "fight like that. About time I get back\l"
	.string "to the old schedule, too…\p"
	.string "Anyway, I'm not gonna keep you any\n"
	.string "more. Stay safe, and enjoy the road\l"
	.string "ahead, Trainer!$"

Borago_POT_Keeper_Text_3:
	.string "Nope, you're not strong enough yet.\n"
	.string "You'll need three Badges to earn the\l"
	.string "right to pass through.\p"
	.string "Just keep at it, Trainer!$"

Borago_TownSign_Text_0:
	.string "Borago City\n"
	.string "“The First and Last Destination”$"

Borago_Psychic_Text_0:
	.string "This place really has everything a city\n"
	.string "could offer.\p"
	.string "From entertainment to daily needs,\n"
	.string "Borago just has it all. Don't you agree?$"

Borago_Gentleman_Text_0:
	.string "May I indulge you, young one?\p"
	.string "Hanau has quite a number of nice cities,\n"
	.string "and this is the most renowned of them\l"
	.string "all.\p"
	.string "However, if you truly wish to experience\n"
	.string "fine culture, then this is not the place\l"
	.string "to be.$"

Borago_ContestDuo_Text_0:
	.string "Yay, Contests! Glitz and spectacle!\n"
	.string "Ohhh, seeing the Contest Hall makes me\l"
	.string "feel all giddy inside!$"

Borago_ContestDuo_Text_1:
	.string "You've got that right! There's nothing\n"
	.string "beating the excitement and thrill of\l"
	.string "Pokémon Contests! Not to mention all\l"
	.string "those adorable Pokémon on the stage!$"

Borago_ContestDuo_Text_2:
	.string "Ohhhh… I'm growing emotional again…$"

Borago_ContestDuo_Text_3:
	.string "Oh, hubby…$"

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
