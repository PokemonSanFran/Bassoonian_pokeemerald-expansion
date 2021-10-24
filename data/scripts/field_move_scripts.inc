EventScript_CutTree::
	lockall
	goto_if_unset FLAG_BADGE01_GET, EventScript_CutTree_2
EventScript_CutTree_1:
	checkitem ITEM_PONUT_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_CutTree_5
EventScript_CutTree_4:
	msgbox EventScript_CutTree_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CutTree_8
	fadescreen FADE_TO_BLACK
	special OpenPokeblockCaseOnFeeder
	waitstate
	compare VAR_RESULT, 0xFFFF
	goto_if_eq EventScript_CutTree_11
EventScript_CutTree_7:
	copyvar VAR_0x8006, VAR_RESULT
	setvar VAR_0x8004, ITEM_HM01_CUT
	setvar VAR_0x8005, MOVE_CUT
	call EventScript_FieldMove_DoCalcs
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
	call EventScript_CutTreeDown
	call EventScript_FieldMove_VerifyPonut
	releaseall
	return

EventScript_CutTree_2:
	goto EventScript_CheckTreeCantCut
	goto EventScript_CutTree_1

EventScript_CutTree_5:
	goto EventScript_CheckTreeCantCut
	goto EventScript_CutTree_4

EventScript_CutTree_8:
	setvar VAR_RESULT, 0xFFFF
	goto EventScript_CutTree_7

EventScript_CutTree_11:
	goto EventScript_CancelCut
	goto EventScript_CutTree_7


EventScript_CheckTreeCantCut::
	msgbox EventScript_CheckTreeCantCut_Text_0
	releaseall
	return


EventScript_RockSmash::
	lockall
	goto_if_unset FLAG_BADGE02_GET, EventScript_RockSmash_2
EventScript_RockSmash_1:
	checkitem ITEM_PONUT_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_RockSmash_5
EventScript_RockSmash_4:
	msgbox EventScript_RockSmash_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_RockSmash_8
	fadescreen FADE_TO_BLACK
	special OpenPokeblockCaseOnFeeder
	waitstate
	compare VAR_RESULT, 0xFFFF
	goto_if_eq EventScript_RockSmash_11
EventScript_RockSmash_7:
	copyvar VAR_0x8006, VAR_RESULT
	setvar VAR_0x8004, ITEM_HM06_ROCK_SMASH
	setvar VAR_0x8005, MOVE_ROCK_SMASH
	call EventScript_FieldMove_DoCalcs
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
	call EventScript_SmashRock
	call EventScript_FieldMove_VerifyPonut
	releaseall
	return

EventScript_RockSmash_2:
	goto EventScript_CantSmashRock
	goto EventScript_RockSmash_1

EventScript_RockSmash_5:
	goto EventScript_CantSmashRock
	goto EventScript_RockSmash_4

EventScript_RockSmash_8:
	setvar VAR_RESULT, 0xFFFF
	goto EventScript_RockSmash_7

EventScript_RockSmash_11:
	goto EventScript_CancelSmash
	goto EventScript_RockSmash_7


EventScript_CantSmashRock::
	msgbox EventScript_CantSmashRock_Text_0
	releaseall
	return


EventScript_FieldMove_DoCalcs::
	buffermovename 1, VAR_0x8005
	special Special_FindHMCapableWild
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_FieldMove_DoCalcs_2
EventScript_FieldMove_DoCalcs_1:
	bufferspeciesname 2, VAR_0x8004
	setfieldeffectargument 0, 0xFF
	msgbox EventScript_FieldMove_DoCalcs_Text_0, MSGBOX_DEFAULT
	closemessage
	return

EventScript_FieldMove_DoCalcs_2:
	goto EventScript_ButNoOneShowedUp
	goto EventScript_FieldMove_DoCalcs_1


EventScript_ButNoOneShowedUp::
	msgbox EventScript_ButNoOneShowedUp_Text_0
	releaseall
	return


EventScript_FieldMove_VerifyPonut::
	compare VAR_0x8006, 0xFFFF
	goto_if_ne EventScript_FieldMove_VerifyPonut_1
	msgbox EventScript_FieldMove_VerifyPonut_Text_1
	closemessage
	dowildbattle
	return

EventScript_FieldMove_VerifyPonut_1:
	msgbox EventScript_FieldMove_VerifyPonut_Text_0
	callnative ZeroEnemyPartyMons
	return


EventScript_SmashRock_GetItem::
	copyvar VAR_TEMP_0, VAR_0x8004
	copyvar VAR_TEMP_1, VAR_0x8005
	copyvar VAR_TEMP_2, VAR_0x8006
	finditem VAR_0x8000
	copyvar VAR_0x8004, VAR_TEMP_0
	copyvar VAR_0x8005, VAR_TEMP_1
	copyvar VAR_0x8006, VAR_TEMP_2
	bufferspeciesname 2, VAR_0x8004
	return


@ Interact with cuttable tree
@EventScript_CutTree:: @ 82906BB
@	lockall
@	goto_if_unset FLAG_BADGE01_GET, EventScript_CheckTreeCantCut
@	checkitem ITEM_PONUT_CASE, 1
@	compare VAR_RESULT, FALSE
@	goto_if_eq EventScript_CheckTreeCantCut
@	setfieldeffectargument 0, VAR_RESULT
@	bufferpartymonnick 0, VAR_RESULT
@	buffermovename 1, MOVE_CUT
@	msgbox Text_WantToCut, MSGBOX_YESNO
@	compare VAR_RESULT, NO
@	goto_if_eq EventScript_CancelCut
@	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
@	closemessage
@	dofieldeffect FLDEFF_USE_CUT_ON_TREE
@	waitstate
@	goto EventScript_CutTreeDown
@	end

@ Use cut from party menu
EventScript_UseCut:: @ 8290705
	lockall
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
	goto EventScript_CutTreeDown
	end

EventScript_CutTreeDown:: @ 8290710
	applymovement VAR_LAST_TALKED, Movement_CutTreeDown
	waitmovement 0
	removeobject VAR_LAST_TALKED
	return

Movement_CutTreeDown: @ 829071F
	cut_tree
	step_end

@EventScript_CheckTreeCantCut:: @ 8290721
@	msgbox Text_CantCut, MSGBOX_DEFAULT
@	releaseall
@	end

EventScript_CancelCut:: @ 829072B
	closemessage
	releaseall
	end

@Text_WantToCut: @ 829072E
@	.string "This tree looks like it can be\n"
@	.string "Cut down!\p"
@	.string "Would you like to Cut it?$"

Text_MonUsedFieldMove: @ 8290771
	.string "{STR_VAR_1} used {STR_VAR_2}!$"

@Text_CantCut: @ 829077D
@	.string "This tree looks like it can be\n"
@	.string "Cut down!$"

@ Interact with smashable rock
@EventScript_RockSmash:: @ 82907A6
@	lockall
@	goto_if_unset FLAG_BADGE02_GET, EventScript_CantSmashRock
@	checkitem ITEM_HM05, 1
@	compare VAR_RESULT, FALSE
@	goto_if_eq EventScript_CantSmashRock
@	checkpartyhmlearnable MOVE_ROCK_SMASH
@	compare VAR_RESULT, PARTY_SIZE
@	goto_if_eq EventScript_CantSmashRock
@	setfieldeffectargument 0, VAR_RESULT
@	bufferpartymonnick 0, VAR_RESULT
@	buffermovename 1, MOVE_ROCK_SMASH
@	msgbox Text_WantToSmash, MSGBOX_YESNO
@	compare VAR_RESULT, NO
@	goto_if_eq EventScript_CancelSmash
@	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
@	closemessage
@	dofieldeffect FLDEFF_USE_ROCK_SMASH
@	waitstate
@	goto EventScript_SmashRock
@	end

@ Use rock smash from party menu
EventScript_UseRockSmash:: @ 82907F0
	lockall
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
	goto EventScript_SmashRock
	end

EventScript_SmashRock:: @ 82907FB
	applymovement VAR_LAST_TALKED, Movement_SmashRock
	waitmovement 0
	removeobject VAR_LAST_TALKED
	//specialvar VAR_RESULT, TryUpdateRusturfTunnelState
	//compare VAR_RESULT, TRUE
	//goto_if_eq EventScript_EndSmash
	//special RockSmashWildEncounter
	special RockSmashFindItem
	compare VAR_RESULT, TRUE
	call_if_eq EventScript_SmashRock_GetItem
	//compare VAR_RESULT, FALSE
	//goto_if_eq EventScript_EndSmash
	//waitstate
	return

EventScript_EndSmash:: @ 8290829
	releaseall
	end

Movement_SmashRock: @ 829082B
	rock_smash_break
	step_end

@EventScript_CantSmashRock:: @ 829082D
@	msgbox Text_CantSmash, MSGBOX_DEFAULT
@	releaseall
@	end

EventScript_CancelSmash:: @ 8290837
	closemessage
	releaseall
	end

@Text_WantToSmash: @ 829083A
@	.string "This rock appears to be breakable.\n"
@	.string "Would you like to use Rock Smash?$"

@Text_CantSmash: @ 829087F
@	.string "It's a rugged rock, but a Pokémon\n"
@	.string "may be able to smash it.$"

EventScript_StrengthBoulder:: @ 82908BA
	lockall
	goto_if_unset FLAG_BADGE04_GET, EventScript_CantStrength
	goto_if_set FLAG_SYS_USE_STRENGTH, EventScript_CheckActivatedBoulder
	checkpartymove MOVE_STRENGTH
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_CantStrength
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_WantToStrength, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CancelStrength
	closemessage
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	goto EventScript_ActivateStrength
	end

EventScript_UseStrength:: @ 82908FD
	lockall
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	goto EventScript_ActivateStrength
	end

EventScript_ActivateStrength:: @ 8290908
	setflag FLAG_SYS_USE_STRENGTH
	msgbox Text_MonUsedStrength, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CantStrength:: @ 8290915
	msgbox Text_CantStrength, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CheckActivatedBoulder:: @ 829091F
	msgbox Text_StrengthActivated, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelStrength:: @ 8290929
	closemessage
	releaseall
	end

Text_WantToStrength: @ 829092C
	.string "It's a big boulder, but a Pokémon\n"
	.string "may be able to push it aside.\p"
	.string "Would you like to use Strength?$"

Text_MonUsedStrength: @ 829098C
	.string "{STR_VAR_1} used Strength!\p"
	.string "{STR_VAR_1}'s Strength made it\n"
	.string "possible to move boulders around!$"

Text_CantStrength: @ 82909D6
	.string "It's a big boulder, but a Pokémon\n"
	.string "may be able to push it aside.$"

Text_StrengthActivated: @ 8290A16
	.string "Strength made it possible to move\n"
	.string "boulders around.$"
	
EventScript_StrengthBoulder_SandBag:: @ 82908BA
	lockall
	goto_if_set FLAG_SYS_USE_STRENGTH, EventScript_CheckActivatedBoulder_SandBag
	msgbox Text_WantToStrength_SandBag, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CancelStrength
	closemessage
	goto EventScript_ActivateStrength_SandBag
	end

EventScript_ActivateStrength_SandBag:: @ 8290908
	setflag FLAG_SYS_USE_STRENGTH
	msgbox Text_MonUsedStrength_SandBag, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CheckActivatedBoulder_SandBag:: @ 829091F
	msgbox Text_StrengthActivated_SandBag, MSGBOX_DEFAULT
	releaseall
	end

Text_WantToStrength_SandBag: @ 829092C
	.string "It's a sand bag shaped like\n"
	.string "a Pokémon.\p"
	.string "Would you like to push it around?$"

Text_MonUsedStrength_SandBag: @ 829098C
	.string "{PLAYER} started pushing\nthe sand bags around.$"

Text_StrengthActivated_SandBag: @ 8290A16
	.string "The sand bags may be pushed around.$"

EventScript_UseWaterfall:: @ 8290A49
	lockall
	checkpartymove MOVE_WATERFALL
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_CantWaterfall
	bufferpartymonnick 0, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_WantToWaterfall, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_EndWaterfall
	msgbox Text_MonUsedWaterfall, MSGBOX_DEFAULT
    call FollowerIntoPlayerScript
    callnative HideFollower
	dofieldeffect FLDEFF_USE_WATERFALL
    callnative FollowMe_WarpSetEnd
	goto EventScript_EndWaterfall

EventScript_CannotUseWaterfall:: @ 8290A83
	lockall

EventScript_CantWaterfall:: @ 8290A84
	msgbox Text_CantWaterfall, MSGBOX_DEFAULT

EventScript_EndWaterfall:: @ 8290A8C
	releaseall
	end

Text_CantWaterfall: @ 8290A8E
	.string "A wall of water is crashing down with\n"
	.string "a mighty roar.$"

Text_WantToWaterfall: @ 8290AC3
	.string "It's a large waterfall.\n"
	.string "Would you like to use Waterfall?$"

Text_MonUsedWaterfall: @ 8290AFC
	.string "{STR_VAR_1} used Waterfall.$"

EventScript_UseDive:: @ 8290B0F
	lockall
	checkpartymove MOVE_DIVE
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_CantDive
    copyvar 0x8004 VAR_RESULT
	bufferpartymonnick 0, VAR_RESULT
	msgbox Text_WantToDive, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_EndDive
	msgbox Text_MonUsedDive, MSGBOX_DEFAULT
	call FollowerIntoPlayerScript
	callnative HideFollower
	setfieldeffectargument 0, VAR_0x8004
	setfieldeffectargument 1, 1
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndDive
	end

EventScript_CantDive:: @ 8290B4E
	msgbox Text_CantDive, MSGBOX_DEFAULT
	releaseall
	end

EventScript_EndDive:: @ 8290B58
	releaseall
	end

EventScript_UseDiveUnderwater:: @ 8290B5A
	lockall
	checkpartymove MOVE_DIVE
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_CantSurface
	bufferpartymonnick 0, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	setfieldeffectargument 1, 1
	msgbox Text_WantToSurface, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_EndSurface
	msgbox Text_MonUsedDive, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndSurface
	end

EventScript_CantSurface:: @ 8290B99
	lockall
	msgbox Text_CantSurface, MSGBOX_DEFAULT
	goto EventScript_EndSurface
	end

EventScript_EndSurface:: @ 8290BA8
	releaseall
	end

Text_CantDive: @ 8290BAA
	.string "The sea is deep here. A Pokémon\n"
	.string "may be able to go underwater.$"

Text_WantToDive: @ 8290BE8
	.string "The sea is deep here.\n"
	.string "Would you like to use Dive?$"

Text_MonUsedDive: @ 8290C1A
	.string "{STR_VAR_1} used Dive.$"

Text_CantSurface: @ 8290C28
	.string "Light is filtering down from above.\n"
	.string "A Pokémon may be able to surface.$"

Text_WantToSurface: @ 8290C6E
	.string "Light is filtering down from above.\n"
	.string "Would you like to use Dive?$"

EventScript_FailSweetScent:: @ 8290CAE
	msgbox Text_FailSweetScent, MSGBOX_SIGN
	end

Text_FailSweetScent: @ 8290CB7
	.string "Looks like there's nothing here…$"
    
FollowerPositionFixScript::
	setvar 0x8000 0x0
	callnative FollowerTrainerSightingPositionFix
	compare VAR_RESULT 0xFFFF
	goto_if_eq FollowerPositionFixScriptReturn
	call WalkCall
	setvar 0x8000 0x1
	callnative FollowerTrainerSightingPositionFix
FollowerPositionFixScriptReturn:
	return
    
FollowerIntoPlayerScript::
	setvar 0x8000 0x0
	callnative FollowerIntoPlayer
	compare VAR_RESULT 0xFFFF
	goto_if_eq FollowerPositionFixScriptReturn
	setvar 0x8005 0xFE  @ follower
	call WalkCall
	setvar 0x8000 0x1
	callnative FollowerIntoPlayer
	return
    
WalkCall:
	compare VAR_RESULT 0x0
	call_if_eq WalkDownCall
	compare VAR_RESULT 0x1
	call_if_eq WalkUpCall
	compare VAR_RESULT 0x2
	call_if_eq WalkLeftCall
	compare VAR_RESULT 0x3
	call_if_eq WalkRightCall
	waitmovement 0x8005
	return
	
WalkDownCall:
	applymovement 0x8005 WalkDown
	return

WalkUpCall:
	applymovement 0x8005 WalkUp
	return

WalkLeftCall:
	applymovement 0x8005 WalkLeft
	return

WalkRightCall:
	applymovement 0x8005 WalkRight
	return
    
WalkDown:
    walk_down
    step_end 

WalkUp:
    walk_up
    step_end

WalkLeft:
    walk_left
    step_end

WalkRight:
    walk_right
    step_end

EventScript_CutTree_Text_0:
	.string "This tree looks like it can be cut down!\n"
	.string "Would you like to leave a Ponut?$"

EventScript_CheckTreeCantCut_Text_0:
	.string "This tree looks like it can be cut down!$"

EventScript_RockSmash_Text_0:
	.string "This rock appears to be breakable.\n"
	.string "Would you like to leave a Ponut?$"

EventScript_CantSmashRock_Text_0:
	.string "It's a rugged rock, but a Pokémon may be\n"
	.string "able to smash it.$"

EventScript_FieldMove_DoCalcs_Text_0:
	.string "{STR_VAR_3} appeared and used\n"
	.string "{STR_VAR_2}!$"

EventScript_ButNoOneShowedUp_Text_0:
	.string "But no one showed up…$"

EventScript_FieldMove_VerifyPonut_Text_0:
	.string "{STR_VAR_3} happily ran off with its\n"
	.string "treat!$"

EventScript_FieldMove_VerifyPonut_Text_1:
	.string "{STR_VAR_3} was angry at the lack\n"
	.string "of Ponut and attacked!$"
