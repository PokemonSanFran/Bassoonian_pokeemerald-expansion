PetalburgWoods_MapScripts::
	.byte 0


BoragoGroveGruntFightA::
	call BoragoGroveGruntFight
	applymovement 3, BoragoGrove_GruntComeB
	waitmovement 0
	call BoragoGroveGruntFight_Part2
	applymovement 3, BoragoGrove_GruntGoB
	waitmovement 0
	applymovement 4, Common_Movement_WalkDown
	waitmovement 0
	call BoragoGroveGruntFight_Part3
	return


BoragoGroveGruntFightB::
	call BoragoGroveGruntFight
	applymovement 3, Common_Movement_WalkDown
	waitmovement 0
	call BoragoGroveGruntFight_Part2
	applymovement 3, BoragoGrove_GruntGoC
	waitmovement 0
	applymovement 4, BoragoGrove_ChefComingA
	waitmovement 0
	call BoragoGroveGruntFight_Part3
	return


BoragoGrove_ChefComingA:
	walk_down
	walk_right
	walk_in_place_fastest_down
	step_end

BoragoGrove_GruntComeB:
	walk_down
	walk_left
	walk_in_place_fastest_down
	step_end

BoragoGrove_GruntGoB:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

BoragoGrove_GruntGoC:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

BoragoGroveGruntFight::
	lockall
	applymovement 3, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox BoragoGroveGruntFight_Text_0
	closemessage
	applymovement 4, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox BoragoGroveGruntFight_Text_1
	closemessage
	applymovement 3, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox BoragoGroveGruntFight_Text_2
	closemessage
	applymovement 3, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	applymovement 3, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox BoragoGroveGruntFight_Text_3
	closemessage
	applymovement 4, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox BoragoGroveGruntFight_Text_4
	closemessage
	applymovement 3, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox BoragoGroveGruntFight_Text_5
	closemessage
	return


BoragoGroveGruntFight_Part2::
	msgbox BoragoGroveGruntFight_Part2_Text_0
	closemessage
	trainerbattle_no_intro TRAINER_GRC_GRUNT_BORAGO_GROVE, BoragoGroveGruntFight_Part2_Text_1
	applymovement 3, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox BoragoGroveGruntFight_Part2_Text_2
	closemessage
	return


BoragoGroveGruntFight_Part3::
	msgbox BoragoGroveGruntFight_Part3_Text_0
	closemessage
	giveitem ITEM_PONUT_CASE
	msgbox BoragoGroveGruntFight_Part3_Text_1
	closemessage
	applymovement 4, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox BoragoGroveGruntFight_Part3_Text_2
	closemessage
	applymovement 4, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox BoragoGroveGruntFight_Part3_Text_3
	closemessage
	applymovement 4, BoragoGrove_ChefLeaving
	waitmovement 0
	setvar VAR_PETALBURG_WOODS_STATE, 3
	setflag FLAG_GRC_HIDE_EVENT_BORAGO_GROVE
	setflag FLAG_GRC_TURPIA_HIDE_PARENTS
	clearflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	callnative Special_GiveFreePokeblocks
	removeobject 3
	removeobject 4
	releaseall
	return


BoragoGrove_ChefLeaving:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

BoragoGrove_TrainerTips1::
	msgbox BoragoGrove_TrainerTips1_Text_0, MSGBOX_SIGN
	return


BoragoGrove_TrainerTips2::
	msgbox BoragoGrove_TrainerTips2_Text_0, MSGBOX_SIGN
	return


BoragoGrove_EventScript_James::
	trainerbattle_single TRAINER_GRC_WAYNE_1, BoragoGrove_EventScript_James_Text_0, BoragoGrove_EventScript_James_Text_1, BoragoGrove_EventScript_TryRegisterJamesAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq BoragoGrove_EventScript_James_1
	setvar VAR_0x8004, TRAINER_GRC_WAYNE_1
	specialvar VAR_RESULT, IsTrainerRegistered
	compare VAR_RESULT, FALSE
	goto_if_eq BoragoGrove_EventScript_James_6
BoragoGrove_EventScript_James_5:
	msgbox BoragoGrove_EventScript_James_Text_5, MSGBOX_DEFAULT
	release
	return

BoragoGrove_EventScript_James_1:
	trainerbattle_rematch TRAINER_GRC_WAYNE_1, BoragoGrove_EventScript_James_Text_2, BoragoGrove_EventScript_James_Text_3
	msgbox BoragoGrove_EventScript_James_Text_4, MSGBOX_AUTOCLOSE
	return

BoragoGrove_EventScript_James_4:
	call BoragoGrove_EventScript_RegisterJames
	return

BoragoGrove_EventScript_James_6:
	goto_if_set FLAG_SYS_MATCH_CALL_GET, BoragoGrove_EventScript_James_4
	goto BoragoGrove_EventScript_James_5


BoragoGrove_EventScript_TryRegisterJamesAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_SYS_MATCH_CALL_GET, BoragoGrove_EventScript_TryRegisterJamesAfterBattle_2
BoragoGrove_EventScript_TryRegisterJamesAfterBattle_1:
	release
	return

BoragoGrove_EventScript_TryRegisterJamesAfterBattle_2:
	call BoragoGrove_EventScript_RegisterJames
	goto BoragoGrove_EventScript_TryRegisterJamesAfterBattle_1


BoragoGrove_EventScript_RegisterJames::
	msgbox BoragoGrove_EventScript_RegisterJames_Text_0, MSGBOX_DEFAULT
	register_matchcall TRAINER_GRC_WAYNE_1
	return


PetalburgWoods_EventScript_Lyle::
	trainerbattle_single TRAINER_GRC_MORRIS, PetalburgWoods_EventScript_Lyle_Text_0, PetalburgWoods_EventScript_Lyle_Text_1
	msgbox PetalburgWoods_EventScript_Lyle_Text_2, MSGBOX_AUTOCLOSE
	return


PetalburgWoods_KricketuneOrchestra::
	msgbox PetalburgWoods_KricketuneOrchestra_Text_0, MSGBOX_NPC
	return


PetalburgWoods_BraveGirl::
	msgbox PetalburgWoods_BraveGirl_Text_0, MSGBOX_NPC
	return


PetalburgWoods_BugManiacPowder::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_BugManiacPowder_2
PetalburgWoods_BugManiacPowder_1:
	msgbox PetalburgWoods_BugManiacPowder_Text_1, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_BugManiacPowder_2:
	msgbox PetalburgWoods_BugManiacPowder_Text_0, MSGBOX_DEFAULT
	giveitem ITEM_SILVER_POWDER
	compare VAR_RESULT, FALSE
	goto_if_eq PetalburgWoods_BugManiacPowder_5
PetalburgWoods_BugManiacPowder_4:
	setflag FLAG_RECEIVED_MIRACLE_SEED
	goto PetalburgWoods_BugManiacPowder_1

PetalburgWoods_BugManiacPowder_5:
	goto Common_EventScript_ShowBagIsFull
	goto PetalburgWoods_BugManiacPowder_4


.set LOCALID_GRUNT, 3
.set LOCALID_DEVON_EMPLOYEE, 4

@PetalburgWoods_MapScripts::
@	.byte 0

PetalburgWoods_EventScript_DevonResearcherLeft::
@	lockall
@	call PetalburgWoods_EventScript_DevonResearcherIntro
@	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
@	waitmovement 0
@	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
@	closemessage
@	playbgm MUS_ENCOUNTER_AQUA, FALSE
@	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
@	waitmovement 0
@	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
@	closemessage
@	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
@	waitmovement 0
@	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFastestUp
@	waitmovement 0
@	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
@	closemessage
@	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
@	waitmovement 0
@	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
@	closemessage
@	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
@	waitmovement 0
@	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
@	trainerbattle_no_intro TRAINER_GRC_GRUNT_BORAGO_GROVE, PetalburgWoods_Text_YoureKiddingMe
@	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
@	waitmovement 0
@	call PetalburgWoods_EventScript_DevonResearcherPostBattle
@	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
@	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
@	waitmovement 0
@	goto PetalburgWoods_EventScript_RemoveDevonResearcher
@	end

PetalburgWoods_EventScript_DevonResearcherRight::
@	lockall
@	call PetalburgWoods_EventScript_DevonResearcherIntro
@	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
@	waitmovement 0
@	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
@	waitmovement 0
@	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
@	closemessage
@	playbgm MUS_ENCOUNTER_AQUA, FALSE
@	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
@	waitmovement 0
@	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
@	closemessage
@	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
@	waitmovement 0
@	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFastestUp
@	waitmovement 0
@	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
@	closemessage
@	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
@	waitmovement 0
@	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
@	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
@	waitmovement 0
@	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
@	trainerbattle_no_intro TRAINER_GRC_GRUNT_BORAGO_GROVE, PetalburgWoods_Text_YoureKiddingMe
@	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
@	waitmovement 0
@	call PetalburgWoods_EventScript_DevonResearcherPostBattle
@	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
@	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
@	waitmovement 0
@	goto PetalburgWoods_EventScript_RemoveDevonResearcher
@	end

PetalburgWoods_EventScript_DevonResearcherIntro::
@	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
@	waitmovement 0
@	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
@	closemessage
@	return

PetalburgWoods_EventScript_DevonResearcherPostBattle::
@	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
@	closemessage
@	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaRunAway
@	waitmovement 0
@	removeobject LOCALID_GRUNT
@	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
@	waitmovement 0
@	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
@	giveitem ITEM_GREAT_BALL
@	compare VAR_RESULT, FALSE
@	goto_if_eq PetalburgWoods_EventScript_BagFull
@	goto PetalburgWoods_EventScript_DevonResearcherFinish
@	end

PetalburgWoods_EventScript_BagFull::
@	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
@	goto PetalburgWoods_EventScript_DevonResearcherFinish
@	end

PetalburgWoods_EventScript_DevonResearcherFinish::
@	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
@	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
@	waitmovement 0
@	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
@	closemessage
@	return

PetalburgWoods_EventScript_RemoveDevonResearcher::
@	removeobject LOCALID_DEVON_EMPLOYEE
@	setvar VAR_PETALBURG_WOODS_STATE, 3
@	releaseall
@	end

PetalburgWoods_Movement_DevonResearcherLookAround:
@	face_up
@	delay_16
@	delay_4
@	face_right
@	delay_16
@	delay_8
@	face_left
@	delay_16
@	delay_8
@	face_down
@	delay_16
@	face_right
@	delay_16
@	delay_8
@	face_up
@	delay_16
@	step_end

PetalburgWoods_Movement_DevonResearcherExitLeft:
@	walk_fast_right
@	walk_fast_up
@	walk_fast_up
@	walk_fast_up
@	walk_fast_up
@	walk_fast_up
@	walk_fast_up
@	walk_fast_up
@	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft:
@	delay_16
@	face_player
@	walk_down
@	walk_down
@	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
@	delay_16
@	face_player
@	walk_down
@	walk_down
@	walk_down
@	walk_in_place_fastest_right
@	step_end

PetalburgWoods_Movement_DevonResearcherExitRight:
@	walk_fast_left
@	walk_fast_up
@	walk_fast_up
@	walk_fast_up
@	walk_fast_up
@	walk_fast_up
@	walk_fast_up
@	walk_fast_up
@	step_end

PetalburgWoods_Movement_WatchResearcherLeave:
@	delay_16
@	delay_16
@	walk_in_place_fastest_up
@	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft:
@	walk_fast_right
@	walk_fast_down
@	walk_fast_down
@	walk_fast_left
@	walk_in_place_fastest_up
@	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
@	walk_fast_down
@	walk_fast_right
@	walk_in_place_fastest_up
@	step_end

PetalburgWoods_Movement_DevonResearcherStartExit:
@	walk_in_place_fastest_down
@	delay_16
@	delay_16
@	delay_16
@	delay_16
@	delay_16
@	face_up
@	step_end

PetalburgWoods_Movement_AquaApproachResearcherLeft:
@	walk_fast_down
@	walk_fast_down
@	step_end

PetalburgWoods_Movement_AquaBackOff:
@	lock_facing_direction
@	walk_up
@	unlock_facing_direction
@	step_end

PetalburgWoods_Movement_AquaRunAway:
@	walk_fast_up
@	walk_fast_up
@	walk_fast_up
@	walk_fast_up
@	walk_fast_up
@	delay_16
@	delay_16
@	step_end

PetalburgWoods_Movement_AquaApproachResearcherRight:
@	walk_fast_down
@	walk_fast_down
@	walk_fast_down
@	step_end

PetalburgWoods_Movement_AquaEntrance:
@	walk_down
@	walk_down
@	delay_16
@	delay_16
@	step_end

PetalburgWoods_Movement_AquaApproachPlayer:
@	walk_down
@	step_end

PetalburgWoods_EventScript_Boy1::
@	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
@	end

PetalburgWoods_EventScript_Boy2::
@	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
@	end

PetalburgWoods_EventScript_Girl::
@	lock
@	faceplayer
@	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
@	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
@	giveitem ITEM_MIRACLE_SEED
@	compare VAR_RESULT, FALSE
@	goto_if_eq Common_EventScript_ShowBagIsFull
@	setflag FLAG_RECEIVED_MIRACLE_SEED
@	release
@	end

PetalburgWoods_EventScript_ExplainMiracleSeed::
@	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
@	release
@	end

PetalburgWoods_EventScript_Sign1::
@	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
@	end

PetalburgWoods_EventScript_Sign2::
@	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
@	end

PetalburgWoods_Text_NotAOneToBeFound:
@	.string "Hmmm…\n"
@	.string "Not a one to be found…$"

PetalburgWoods_Text_HaveYouSeenShroomish:
@	.string "Hello, have you seen any POKéMON\n"
@	.string "called SHROOMISH around here?\p"
@	.string "I really love that POKéMON.$"

PetalburgWoods_Text_IWasGoingToAmbushYou:
@	.string "I was going to ambush you, but you\n"
@	.string "had to dawdle in PETALBURG WOODS\l"
@	.string "forever, didn't you?\p"
@	.string "I got sick of waiting, so here I am!$"

PetalburgWoods_Text_HandOverThosePapers:
@	.string "You! DEVON RESEARCHER!\p"
@	.string "Hand over those papers!$"

PetalburgWoods_Text_YouHaveToHelpMe:
@	.string "Aiyeeeh!\p"
@	.string "You're a POKéMON TRAINER, aren't you?\n"
@	.string "You've got to help me, please!$"

PetalburgWoods_Text_NoOneCrossesTeamAqua:
@	.string "Hunh? What do you think you're doing?\n"
@	.string "What, you're going to protect him?\p"
@	.string "No one who crosses TEAM AQUA\n"
@	.string "gets any mercy, not even a kid!\p"
@	.string "Come on and battle me!$"

PetalburgWoods_Text_YoureKiddingMe:
	.string "You're kidding me! You're tough!$"

PetalburgWoods_Text_YouveGotSomeNerve:
@	.string "Grrr… You've got some nerve\n"
@	.string "meddling with TEAM AQUA!\l"
@	.string "Come on and battle me again!\p"
@	.string "I wish I could say that, but I'm out of\n"
@	.string "POKéMON…\p"
@	.string "And, hey, we of TEAM AQUA are also\n"
@	.string "after something in RUSTBORO.\p"
@	.string "I'll let you go today!$"

PetalburgWoods_Text_ThatWasAwfullyClose:
@	.string "Whew…\n"
@	.string "That was awfully close!\p"
@	.string "Thanks to you, he didn't rob me of\n"
@	.string "these important papers.\p"
@	.string "I know, I'll give you a GREAT BALL as\n"
@	.string "my thanks!$"

PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
@	.string "Didn't that TEAM AQUA thug say\n"
@	.string "they were after something in\l"
@	.string "RUSTBORO, too?$"

PetalburgWoods_Text_ICantBeWastingTime:
@	.string "Uh-oh! It's a crisis!\n"
@	.string "I can't be wasting time!$"

PetalburgWoods_Text_YoureLoadedWithItems:
@	.string "You're loaded with items.\n"
@	.string "I can't give you this GREAT BALL.$"

PetalburgWoods_Text_GoBugPokemonTeam:
	.string "Morris intro$"

PetalburgWoods_Text_ICouldntWin:
	.string "Morris defeat$"

PetalburgWoods_Text_ImOutOfPokeBalls:
	.string "Morris post$"

PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
	.string "Wayne intro$"

PetalburgWoods_Text_CantBePopularIfILose:
	.string "Wayne defeat$"

PetalburgWoods_Text_PeopleRespectYou:
	.string "Wayne post$"

PetalburgWoods_Text_IWantRematch1:
	.string "Wayne register 1$"

PetalburgWoods_Text_IWantRematch2:
	.string "Wayne register 2$"

PetalburgWoods_Text_MyPokemonHaveGrown:
	.string "Wayne rematch intro$"

PetalburgWoods_Text_CantBePopularIfLose:
	.string "Wayne rematch defeat$"

PetalburgWoods_Text_IveBeenTrainingHard:
	.string "Wayne rematch post$"

PetalburgWoods_Text_StayOutOfTallGrass:
@	.string "Yo, there!\n"
@	.string "Your POKéMON doing okay?\p"
@	.string "If your POKéMON are weak and you want\n"
@	.string "to avoid battles, you should stay out\l"
@	.string "of tall grass.$"

PetalburgWoods_Text_HiddenItemsExplanation:
@	.string "Sometimes, there are things on the\n"
@	.string "ground even if you can't see them.\p"
@	.string "That's why I always check where I'm\n"
@	.string "walking.$"

PetalburgWoods_Text_TryUsingThisItem:
@	.string "Oh, neat!\n"
@	.string "That's the BADGE from RUSTBORO GYM!\p"
@	.string "You must be a TRAINER.\n"
@	.string "You should try using this item.$"

PetalburgWoods_Text_MiracleSeedExplanation:
@	.string "It's a MIRACLE SEED.\n"
@	.string "If a POKéMON holds that item, its\l"
@	.string "GRASS-type moves become stronger.\p"
@	.string "Besides MIRACLE SEED, I think there are\n"
@	.string "other convenient items for POKéMON\l"
@	.string "to hold.$"

PetalburgWoods_Text_TrainerTipsExperience:
@	.string "TRAINER TIPS\p"
@	.string "Any POKéMON that appears even once\n"
@	.string "in a battle is awarded EXP Points.\p"
@	.string "To raise a weak POKéMON, put it at the\n"
@	.string "left of the team list.\p"
@	.string "As soon as a battle starts, switch it\n"
@	.string "out. It will earn EXP Points without\l"
@	.string "being exposed to any harm.$"

PetalburgWoods_Text_TrainerTipsPP:
@	.string "TRAINER TIPS\p"
@	.string "In addition to Hit Points (HP), POKéMON\n"
@	.string "have Power Points (PP) that are used to\l"
@	.string "make moves during battle.\p"
@	.string "If a POKéMON runs out of PP, it must be\n"
@	.string "taken to a POKéMON CENTER.$"

BoragoGroveGruntFight_Text_0:
	.string "Stay here! Don't you dare try and\n"
	.string "weasel your way out!$"

BoragoGroveGruntFight_Text_1:
	.string "Aaaaah! Help meeeee!$"

BoragoGroveGruntFight_Text_2:
	.string "Shut up, or you'll leave me no choice!$"

BoragoGroveGruntFight_Text_3:
	.string "Grrr! Of course you had to go and cause\n"
	.string "a ruckus…$"

BoragoGroveGruntFight_Text_4:
	.string "Please! Help me! Save me from this\n"
	.string "scoundrel! I've done nothing wrong!$"

BoragoGroveGruntFight_Text_5:
	.string "You stay put! I'm gonna deal with this\n"
	.string "brat first!$"

BoragoGroveGruntFight_Part2_Text_0:
	.string "What's the big idea, huh? Think you can\n"
	.string "be the hero saving the innocent\l"
	.string "civilian, punk?\p"
	.string "That it?! Huh?! Well, you got a whole\n"
	.string "other thing coming your way!\p"
	.string "Prepare for pain!$"

BoragoGroveGruntFight_Part2_Text_1:
	.string "You gotta be kidding me!$"

BoragoGroveGruntFight_Part2_Text_2:
	.string "Okay, fine! I'll let him go! But don't you\n"
	.string "dare think I'm gonna let you off the\l"
	.string "hook, kid! Ugh, just my luck…$"

BoragoGroveGruntFight_Part3_Text_0:
	.string "I'm safe! Oh, thank you… a thousand\n"
	.string "times, thank you!\p"
	.string "And I just so happen to have something\n"
	.string "to repay you with for your kindness.\l"
	.string "Here, please take this!$"

BoragoGroveGruntFight_Part3_Text_1:
	.string "This Ponut Case here can store all the\n"
	.string "Ponuts you'll ever want!\p"
	.string "Pardon? Never heard of Ponuts? Well,\n"
	.string "fear not, my friend!\p"
	.string "They are a delicacy enjoyed by Pokémon\n"
	.string "across all Hanau.\p"
	.string "In fact, even people like you and I\n"
	.string "can't help themselves to some!\p"
	.string "Should you ever want to make Ponuts in\n"
	.string "the Contest Hall, this case will keep\l"
	.string "them safe and fresh.$"

BoragoGroveGruntFight_Part3_Text_2:
	.string "Oh! I should mention another important\n"
	.string "thing.\p"
	.string "You can use Ponuts to call upon\n"
	.string "Pokémon to use field moves for you!\p"
	.string "Let's say there's a tree in the way that\n"
	.string "can be cut, or a boulder that can be\l"
	.string "smashed…\p"
	.string "If you reward Pokémon with a Ponut\n"
	.string "after they help you, they'll leave\l"
	.string "happily.\p"
	.string "If you don't, though, they might attack\n"
	.string "you in disappointment.\p"
	.string "That is to say, it never hurts to have\n"
	.string "some Ponuts on hand!\p"
	.string "And the Case I've given you comes\n"
	.string "pre-packaged with three!$"

BoragoGroveGruntFight_Part3_Text_3:
	.string "Anyway, that's enough from me. I have\n"
	.string "more baking to take care of. Safe\l"
	.string "journeys, my friend!$"

BoragoGrove_TrainerTips1_Text_0:
	.string "Trainer Tips! Any Pokémon can use HM\n"
	.string "moves on the field as long as they're\l"
	.string "compatible with any moves. You don't\l"
	.string "need to teach HM moves to your\l"
	.string "Pokémon.$"

BoragoGrove_TrainerTips2_Text_0:
	.string "Trainer Tips! Berries are free\n"
	.string "resources for your Pokémon. As long as\l"
	.string "you plant them back and water them\l"
	.string "regularly, you'll save out on a lot of\l"
	.string "money!$"

BoragoGrove_EventScript_James_Text_0:
	.string "Behold, the mystery and intrigue of Bug\n"
	.string "Pokémon! Right before your very eyes!$"

BoragoGrove_EventScript_James_Text_1:
	.string "Uh... that was kind of underwhelming…$"

BoragoGrove_EventScript_James_Text_2:
	.string "Hey, Bug buddy! I've delved deeper into\n"
	.string "the mysteries of the Bug type… and I'll\l"
	.string "show you just what I mean!$"

BoragoGrove_EventScript_James_Text_3:
	.string "At least we gave it a good shot this\n"
	.string "time, right?$"

BoragoGrove_EventScript_James_Text_4:
	.string "I want to meet someone who's just as\n"
	.string "passionate about Bug Pokémon as me.\p"
	.string "I know they're out there somewhere! I\n"
	.string "just know it!$"

BoragoGrove_EventScript_James_Text_5:
	.string "Bug Pokémon are the best! It's just a\n"
	.string "shame nobody else seems to think that\l"
	.string "way.$"

BoragoGrove_EventScript_RegisterJames_Text_0:
	.string "Do my compound eyes detect a P-Drive?\n"
	.string "Care registering me?\p"
	.string "That way, we can be Bug buddies! You\n"
	.string "and me!$"

PetalburgWoods_EventScript_Lyle_Text_0:
	.string "The grove hides many surprises! And\n"
	.string "now, I found a Trainer! Let's battle!$"

PetalburgWoods_EventScript_Lyle_Text_1:
	.string "Oh, huh! Didn't see that one coming!$"

PetalburgWoods_EventScript_Lyle_Text_2:
	.string "I'm always looking for the next thrill.\n"
	.string "The grove's got a lot of 'em, though!$"

PetalburgWoods_KricketuneOrchestra_Text_0:
	.string "The word goes that deep in the night,\n"
	.string "Kricketune appear and conduct swarms\l"
	.string "of Kricketot.\p"
	.string "If you're a night owl, you might just\n"
	.string "hear them yourself… Hohohoho!$"

PetalburgWoods_BraveGirl_Text_0:
	.string "I'm not afraid of bugs. In fact, Bug\n"
	.string "Pokémon are cute!\p"
	.string "I don't know why so many girls are so\n"
	.string "squeamish about Bug Pokémon. I mean,\l"
	.string "what have they done wrong?$"

PetalburgWoods_BugManiacPowder_Text_0:
	.string "I've gathered a lot of precious\n"
	.string "materials from the forest. Here, I'll\l"
	.string "share some with you!$"

PetalburgWoods_BugManiacPowder_Text_1:
	.string "This is Silver Powder! It raises the\n"
	.string "power of Bug-type moves for the\l"
	.string "Pokémon that holds it.\p"
	.string "It's also just lovely to look at, don't\n"
	.string "you agree? That silvery gleam is so\l"
	.string "alluring, indeed…$"
