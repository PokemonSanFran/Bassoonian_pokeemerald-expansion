DrivesLab_NotAllowedBasement::
	lockall
	applymovement 3, Common_Movement_WalkInPlaceFastestLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox DrivesLab_NotAllowedBasement_Text_0
	closemessage
	applymovement 3, Common_Movement_WalkInPlaceFastestDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	releaseall
	return


DrivesLab_Desk_Woman::
	goto_if_set FLAG_GRC_HIDE_POLLOCK_LABS, DrivesLab_Desk_Woman_1
	msgbox DrivesLab_Desk_Woman_Text_1, MSGBOX_NPC
	return

DrivesLab_Desk_Woman_1:
	msgbox DrivesLab_Desk_Woman_Text_0, MSGBOX_NPC
	return


DrivesLab_Desk_Economic::
	msgbox DrivesLab_Desk_Economic_Text_0, MSGBOX_NPC
	return


DrivesLab_ForcePlayerGoA::
	call DrivesLab_HeyKiddoComeBack
	applymovement OBJ_EVENT_ID_PLAYER, DrivesLab_Movement_PlayerGoBackA
	waitmovement 0
	goto DrivesLab_Desk_Pollock
	return


DrivesLab_Movement_PlayerGoBackA:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

DrivesLab_ForcePlayerGoB::
	call DrivesLab_HeyKiddoComeBack
	applymovement OBJ_EVENT_ID_PLAYER, DrivesLab_Movement_PlayerGoBackB
	waitmovement 0
	goto DrivesLab_Desk_Pollock
	return


DrivesLab_Movement_PlayerGoBackB:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

DrivesLab_ForcePlayerGoC::
	call DrivesLab_HeyKiddoComeBack
	applymovement OBJ_EVENT_ID_PLAYER, DrivesLab_Movement_PlayerGoBackC
	waitmovement 0
	goto DrivesLab_Desk_Pollock
	return


DrivesLab_Movement_PlayerGoBackC:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

DrivesLab_ForcePlayerGoD::
	call DrivesLab_HeyKiddoComeBack
	applymovement OBJ_EVENT_ID_PLAYER, DrivesLab_Movement_PlayerGoBackD
	waitmovement 0
	goto DrivesLab_Desk_Pollock
	return


DrivesLab_Movement_PlayerGoBackD:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

DrivesLab_HeyKiddoComeBack::
	lockall
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox DrivesLab_HeyKiddoComeBack_Text_0
	closemessage
	return


DrivesLab_Desk_Pollock::
	lock
	goto_if_set FLAG_SYS_POKENAV_GET, DrivesLab_Desk_Pollock_2
	msgbox DrivesLab_Desk_Pollock_Text_9
	closemessage
	playfanfare MUS_OBTAIN_ITEM
	message DrivesLab_Desk_Pollock_Text_10
	waitfanfare
	msgbox DrivesLab_Desk_Pollock_Text_11
	closemessage
	setflag FLAG_SYS_POKENAV_GET
	goto DrivesLab_Desk_PollockTutorial
DrivesLab_Desk_Pollock_1:
	releaseall
	return

DrivesLab_Desk_Pollock_2:
	message DrivesLab_Desk_Pollock_Text_0
	waitmessage
	setvar VAR_0x8004, 0
	special ScriptMenu_CreateDriveLabsPollockMultichoice
	waitstate
	special GetDriveLabsPollockSelection
	switch VAR_RESULT
	case 0, DrivesLab_Desk_Pollock_7
	case 1, DrivesLab_Desk_Pollock_8
	case 2, DrivesLab_Desk_Pollock_9
	case 3, DrivesLab_Desk_Pollock_10
	case 4, DrivesLab_Desk_Pollock_11
	case 5, DrivesLab_Desk_Pollock_12
	case 6, DrivesLab_Desk_Pollock_13
	case 7, DrivesLab_Desk_Pollock_14
	case MULTI_B_PRESSED, DrivesLab_Desk_Pollock_14
DrivesLab_Desk_Pollock_5:
	closemessage
	goto DrivesLab_Desk_Pollock_1

DrivesLab_Desk_Pollock_7:
	msgbox DrivesLab_Desk_Pollock_Text_1
	goto DrivesLab_Desk_Pollock_5

DrivesLab_Desk_Pollock_8:
	msgbox DrivesLab_Desk_Pollock_Text_2
	goto DrivesLab_Desk_Pollock_5

DrivesLab_Desk_Pollock_9:
	msgbox DrivesLab_Desk_Pollock_Text_3
	goto DrivesLab_Desk_Pollock_5

DrivesLab_Desk_Pollock_10:
	msgbox DrivesLab_Desk_Pollock_Text_4
	goto DrivesLab_Desk_Pollock_5

DrivesLab_Desk_Pollock_11:
	msgbox DrivesLab_Desk_Pollock_Text_5
	goto DrivesLab_Desk_Pollock_5

DrivesLab_Desk_Pollock_12:
	msgbox DrivesLab_Desk_Pollock_Text_6
	goto DrivesLab_Desk_Pollock_5

DrivesLab_Desk_Pollock_13:
	msgbox DrivesLab_Desk_Pollock_Text_7
	goto DrivesLab_Desk_Pollock_5

DrivesLab_Desk_Pollock_14:
	msgbox DrivesLab_Desk_Pollock_Text_8
	goto DrivesLab_Desk_Pollock_5


DrivesLab_Desk_PollockTutorial::
	special ScriptMenu_CreateStartMenuForPokenavTutorial
	waitstate
	switch VAR_RESULT
	case 0, DrivesLab_Desk_PollockTutorial_PleaseSelect
	case 1, DrivesLab_Desk_PollockTutorial_PleaseSelect
	case 3, DrivesLab_Desk_PollockTutorial_PleaseSelect
	case 4, DrivesLab_Desk_PollockTutorial_PleaseSelect
	case 5, DrivesLab_Desk_PollockTutorial_PleaseSelect
	case 6, DrivesLab_Desk_PollockTutorial_PleaseSelect
	case MULTI_B_PRESSED, DrivesLab_Desk_PollockTutorial_PleaseSelect
	special OpenPokenavForTutorial2
	waitstate
	delay 20
	goto DrivesLab_Desk_PollockTutorial_End

DrivesLab_Desk_PollockTutorial_PleaseSelect::
	msgbox DrivesLab_Desk_PollockTutorial_PleaseSelect_Text_0, MSGBOX_DEFAULT
	closemessage
	delay 10
	goto DrivesLab_Desk_PollockTutorial
	return


DrivesLab_Desk_PollockTutorial_End::
	msgbox DrivesLab_Desk_PollockTutorial_End_Text_0
	closemessage
	setvar VAR_BIRCH_LAB_STATE, 1
	releaseall
	return


.set LOCALID_STAIR_GUARD, 2

RustboroCity_DevonCorp_1F_MapScripts::
@	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_1F_OnTransition
	.byte 0

RustboroCity_DevonCorp_1F_OnTransition:
@	call_if_unset FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_BlockStairs
@	end

RustboroCity_DevonCorp_1F_EventScript_BlockStairs::
@	setobjectxyperm LOCALID_STAIR_GUARD, 14, 2
@	setobjectmovementtype LOCALID_STAIR_GUARD, MOVEMENT_TYPE_FACE_DOWN
@	return

RustboroCity_DevonCorp_1F_EventScript_Employee::
@	lock
@	faceplayer
@	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered
@	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright
@	msgbox RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct, MSGBOX_DEFAULT
@	release
@	end

RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright::
@	msgbox RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright, MSGBOX_DEFAULT
@	release
@	end

RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered::
@	msgbox RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered, MSGBOX_DEFAULT
@	release
@	end

RustboroCity_DevonCorp_1F_EventScript_StairGuard::
@	lock
@	faceplayer
@	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome
@	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
@	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
@	msgbox RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter, MSGBOX_DEFAULT
@	release
@	end

RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome::
@	msgbox RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere, MSGBOX_DEFAULT
@	release
@	end

RustboroCity_DevonCorp_1F_EventScript_GotRobbed::
@	msgbox RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed, MSGBOX_DEFAULT
@	release
@	end

RustboroCity_DevonCorp_1F_EventScript_Greeter::
@	lock
@	faceplayer
@	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp
@	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
@	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
@	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
@	release
@	end

RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp::
@	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
@	release
@	end

RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed::
@	msgbox RustboroCity_DevonCorp_1F_Text_StaffGotRobbed, MSGBOX_DEFAULT
@	release
@	end

RustboroCity_DevonCorp_1F_EventScript_RocksMetalDisplay::
@	msgbox RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay, MSGBOX_SIGN
@	end

RustboroCity_DevonCorp_1F_EventScript_ProductsDisplay::
@	msgbox RustboroCity_DevonCorp_1F_Text_ProductDisplay, MSGBOX_SIGN
@	end

RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp:
@	.string "Hello and welcome to the DEVON\n"
@	.string "CORPORATION.\p"
@	.string "We're proud producers of items and\n"
@	.string "medicine that enhance your life.$"

RustboroCity_DevonCorp_1F_Text_StaffGotRobbed:
@	.string "One of our research staff stupidly\n"
@	.string "got robbed of an important parcel.$"

RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct:
@	.string "Hey, those RUNNING SHOES!\n"
@	.string "They're one of our products!\p"
@	.string "It makes me happy when I see someone\n"
@	.string "using something we made.$"

RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright:
@	.string "That stolen parcel…\p"
@	.string "Well, sure it's important, but it's not\n"
@	.string "anything that anyone can use.\p"
@	.string "In my estimation, that robber must not\n"
@	.string "have been very bright.$"

RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered:
@	.string "It sounds like they've recovered\n"
@	.string "the ripped-off DEVON GOODS.$"

RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter:
@	.string "I'm sorry, only authorized people\n"
@	.string "are allowed to enter here.$"

RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed:
@	.string "It's beyond stupid.\n"
@	.string "How could we get robbed?$"

RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere:
@	.string "Hi, there!\n"
@	.string "You're always welcome here!$"

RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay:
@	.string "Samples of rocks and metal are\n"
@	.string "displayed in the glass case.\p"
@	.string "There's a panel with some writing\n"
@	.string "on it…\p"
@	.string "“DEVON CORPORATION got its start as\n"
@	.string "a producer of stones from quarries.\p"
@	.string "“The company also produced iron from\n"
@	.string "filings in the sand.\p"
@	.string "“From that humble start as a producer\n"
@	.string "of raw materials, DEVON developed.\p"
@	.string "“DEVON is now a manufacturer of a wide\n"
@	.string "range of industrial products.”$"

RustboroCity_DevonCorp_1F_Text_ProductDisplay:
	.string "Prototypes and test products fill\n"
	.string "the glass display case.\p"
	.string "There's a panel with a description…\p"
	.string "“In addition to industrial products,\n"
	.string "DEVON now markets sundries and\l"
	.string "pharmaceuticals for better lifestyles.\p"
	.string "“Recently, DEVON has begun marketing\n"
	.string "tools for POKéMON TRAINERS, including\l"
	.string "POKé BALLS and POKéNAV systems.”$"

DrivesLab_NotAllowedBasement_Text_0:
	.string "Oh, sorry, the basement's off-limits.\n"
	.string "Registered personnel only!$"

DrivesLab_Desk_Woman_Text_0:
	.string "Welcome! I do believe Mr. Pollock is\n"
	.string "looking for you.\p"
	.string "He hasn't briefed us on where he'd be,\n"
	.string "but you shouldn't keep him waiting.$"

DrivesLab_Desk_Woman_Text_1:
	.string "Welcome to Drive Labs, home of the\n"
	.string "P-Drive!\p"
	.string "If you have any questions on the\n"
	.string "P-Drive and its functions, my colleague\l"
	.string "next to me will be your guide.\p"
	.string "Have a good day!$"

DrivesLab_Desk_Economic_Text_0:
	.string "Silph Co. and Devon have both invested\n"
	.string "in Drive Labs. It's thanks to their\l"
	.string "backing that we could truly get off\l"
	.string "the ground as a company.\p"
	.string "Now, we're making quite a solid buck, but\n"
	.string "there's always a bigger profit to turn!$"

DrivesLab_HeyKiddoComeBack_Text_0:
	.string "Hey, kid! Got a second?$"

DrivesLab_Desk_Pollock_Text_0:
	.string "Hey, {PLAYER}! Any Drives you want to\n"
	.string "know more about?$"

DrivesLab_Desk_Pollock_Text_1:
	.string "AreaDrive is your go-to map of the\n"
	.string "entire Hanau region!\p"
	.string "You can also take a closer look at the\n"
	.string "layout of towns and cities by zooming\l"
	.string "in.$"

DrivesLab_Desk_Pollock_Text_2:
	.string "DexDrive allows you to chase for\n"
	.string "specific Pokémon.\p"
	.string "As you keep encountering the same kind\n"
	.string "of Pokémon, you may find stronger\l"
	.string "specimens with unique moves!$"

DrivesLab_Desk_Pollock_Text_3:
	.string "TeleDrive lets you call anyone you've\n"
	.string "registered, no matter how near or far.\p"
	.string "Trainers you've fought before may call\n"
	.string "you whenever they feel like battling\l"
	.string "again!$"

DrivesLab_Desk_Pollock_Text_4:
	.string "SheenDrive lets you check on the\n"
	.string "Condition of your party!\p"
	.string "Useful if you want to know how far you\n"
	.string "can still add to a Pokémon's Condition\l"
	.string "when feeding them Ponuts.$"

DrivesLab_Desk_Pollock_Text_5:
	.string "BerryDrive is a special map for all your\n"
	.string "Berry needs!\p"
	.string "It'll display where you've planted\n"
	.string "Berries all across the region.$"

DrivesLab_Desk_Pollock_Text_6:
	.string "StatDrive is an in-depth look at the\n"
	.string "stats and potential of your party!\p"
	.string "You'll also be able to check how much\n"
	.string "your Pokémon have grown on you.$"

DrivesLab_Desk_Pollock_Text_7:
	.string "ForceDrive contains all kinds of\n"
	.string "special powers to make your life just\l"
	.string "that extra bit more convenient!$"

DrivesLab_Desk_Pollock_Text_8:
	.string "Right, then. That's good! If you need\n"
	.string "something, you know where to find me!$"

DrivesLab_Desk_Pollock_Text_9:
	.string "Hello there! I'm Pollock, one of the\n"
	.string "designers of the P-Drive.\p"
	.string "I see this is your first time in here!\n"
	.string "Well, in that case, why don't we\l"
	.string "commemorate the occasion?\p"
	.string "Here you go, my friend: a brand-new\n"
	.string "P-Drive! All yours!$"

DrivesLab_Desk_Pollock_Text_10:
	.string "{PLAYER} received a P-Drive.$"

DrivesLab_Desk_Pollock_Text_11:
	.string "The P-Drive is quite the nifty little\n"
	.string "gadget, if I do say so myself!\p"
	.string "We're currently still developing\n"
	.string "additional functions for it, but we've\l"
	.string "already built in a map version.\p"
	.string "Why don't you check out AreaDrive for\n"
	.string "now? It's got all the latest info on\l"
	.string "where you are and where you need to go.$"

DrivesLab_Desk_PollockTutorial_PleaseSelect_Text_0:
	.string "Hey, mind checking out your P-Drive for\n"
	.string "a sec?$"

DrivesLab_Desk_PollockTutorial_End_Text_0:
	.string "Marvelous! We'll be installing new Drives\n"
	.string "along the way, so be sure to keep an\l"
	.string "eye out for those.\p"
	.string "Enjoy your new P-Drive, {PLAYER}! If\n"
	.string "you have any further questions, you\l"
	.string "know where to find me. Old man Pollock's\l"
	.string "always ready to give you a hand.\p"
	.string "Safe journeys!$"
