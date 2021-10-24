Route103_EventScript_Daisy::
	trainerbattle_single TRAINER_GRC_KAYLA, Route103_EventScript_Daisy_Text_0, Route103_EventScript_Daisy_Text_1
	msgbox Route103_EventScript_Daisy_Text_2, MSGBOX_AUTOCLOSE
	return


Route103_EventScript_Andrew::
	trainerbattle_single TRAINER_GRC_JENNIFER, Route103_EventScript_Andrew_Text_0, Route103_EventScript_Andrew_Text_1
	msgbox Route103_EventScript_Andrew_Text_2, MSGBOX_AUTOCLOSE
	return


Route103_EventScript_Marcos::
	trainerbattle_single TRAINER_GRC_RODD, Route103_EventScript_Marcos_Text_0, Route103_EventScript_Marcos_Text_1
	msgbox Route103_EventScript_Marcos_Text_2, MSGBOX_AUTOCLOSE
	return


Route103_EventScript_Pete::
	trainerbattle_single TRAINER_GRC_ALLIAH, Route103_EventScript_Pete_Text_0, Route103_EventScript_Pete_Text_1
	msgbox Route103_EventScript_Pete_Text_2, MSGBOX_AUTOCLOSE
	return


Route103_EventScript_Rhett::
	trainerbattle_single TRAINER_GRC_SALLY, Route103_EventScript_Rhett_Text_0, Route103_EventScript_Rhett_Text_1
	msgbox Route103_EventScript_Rhett_Text_2, MSGBOX_AUTOCLOSE
	return


Route103_EventScript_Isabelle::
	trainerbattle_single TRAINER_GRC_KWOK, Route103_EventScript_Isabelle_Text_0, Route103_EventScript_Isabelle_Text_1
	msgbox Route103_EventScript_Isabelle_Text_2, MSGBOX_AUTOCLOSE
	return


Route103_EventScript_Amy::
	trainerbattle_double TRAINER_GRC_JIM_AND_JO_1, Route103_EventScript_Amy_Text_0, Route103_EventScript_Amy_Text_1, Route103_EventScript_Amy_Text_2, Route103_EventScript_RegisterAmyAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route103_EventScript_Amy_1
	msgbox Route103_EventScript_Amy_Text_7, MSGBOX_DEFAULT
	release
	return

Route103_EventScript_Amy_1:
	trainerbattle_rematch_double TRAINER_GRC_JIM_AND_JO_1, Route103_EventScript_Amy_Text_3, Route103_EventScript_Amy_Text_4, Route103_EventScript_Amy_Text_5
	msgbox Route103_EventScript_Amy_Text_6, MSGBOX_AUTOCLOSE
	return


Route103_EventScript_RegisterAmyAfterBattle::
	msgbox Route103_EventScript_RegisterAmyAfterBattle_Text_0, MSGBOX_DEFAULT
	register_matchcall TRAINER_GRC_JIM_AND_JO_1
	release
	return


Route103_EventScript_Liv::
	trainerbattle_double TRAINER_GRC_JIM_AND_JO_1, Route103_EventScript_Liv_Text_0, Route103_EventScript_Liv_Text_1, Route103_EventScript_Liv_Text_2, Route103_EventScript_RegisterLivAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route103_EventScript_Liv_1
	msgbox Route103_EventScript_Liv_Text_7, MSGBOX_DEFAULT
	release
	return

Route103_EventScript_Liv_1:
	trainerbattle_rematch_double TRAINER_GRC_JIM_AND_JO_1, Route103_EventScript_Liv_Text_3, Route103_EventScript_Liv_Text_4, Route103_EventScript_Liv_Text_5
	msgbox Route103_EventScript_Liv_Text_6, MSGBOX_AUTOCLOSE
	return


Route103_EventScript_RegisterLivAfterBattle::
	msgbox Route103_EventScript_RegisterLivAfterBattle_Text_0, MSGBOX_DEFAULT
	register_matchcall TRAINER_GRC_JIM_AND_JO_1
	release
	return


Route103_EventScript_Miguel::
	trainerbattle_single TRAINER_GRC_HAROLD_1, Route103_EventScript_Miguel_Text_0, Route103_EventScript_Miguel_Text_1, Route103_EventScript_RegisterMiguelAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route103_EventScript_Miguel_1
	msgbox Route103_EventScript_Miguel_Text_5, MSGBOX_DEFAULT
	release
	return

Route103_EventScript_Miguel_1:
	trainerbattle_rematch TRAINER_GRC_HAROLD_1, Route103_EventScript_Miguel_Text_2, Route103_EventScript_Miguel_Text_3
	msgbox Route103_EventScript_Miguel_Text_4, MSGBOX_AUTOCLOSE
	return


Route103_EventScript_RegisterMiguelAfterBattle::
	msgbox Route103_EventScript_RegisterMiguelAfterBattle_Text_0, MSGBOX_DEFAULT
	register_matchcall TRAINER_GRC_HAROLD_1
	release
	return


Route103_EventScript_CutGuy::
	goto_if_set FLAG_SYS_DEXNAV_GET, Route103_EventScript_CutGuy_1
	lock
	msgbox Route103_EventScript_CutGuy_Text_1
	release
	return

Route103_EventScript_CutGuy_1:
	msgbox Route103_EventScript_CutGuy_Text_0, MSGBOX_NPC
	return


Route103_EventScript_SneyderBlock::
	msgbox Route103_EventScript_SneyderBlock_Text_0, MSGBOX_NPC
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestUp
	return


Route103_EventScript_SurskitGal::
	msgbox Route103_EventScript_SurskitGal_Text_0, MSGBOX_NPC
	return


Route103_MoveStarlyPhotographer::
	goto_if_unset FLAG_SYS_DEXNAV_GET, Route103_MoveStarlyPhotographer_1
	return

Route103_MoveStarlyPhotographer_1:
	setobjectxyperm 10, 70, 14
	setobjectmovementtype 10, MOVEMENT_TYPE_FACE_UP
	return


 
.set LOCALID_RIVAL, 2

Route103_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route103_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route103_OnLoad
	.byte 0

Route103_OnTransition:
@	call Common_EventScript_SetupRivalGfxId
@	call ProfBirch_EventScript_UpdateLocation
	call Route103_MoveStarlyPhotographer
	end

Route103_OnLoad:
@	call_if_set FLAG_SYS_GAME_CLEAR, Route103_EventScript_OpenAlteringCave
	end

Route103_EventScript_OpenAlteringCave::
@	setmetatile 45, 5, METATILE_General_CaveEntrance_Top, 1
@	setmetatile 45, 6, METATILE_General_CaveEntrance_Bottom, 0
@	return

Route103_EventScript_Rival::
@	lockall
@	checkplayergender
@	compare VAR_RESULT, MALE
@	goto_if_eq Route103_EventScript_RivalMay
@	compare VAR_RESULT, FEMALE
@	goto_if_eq Route103_EventScript_RivalBrendan
@	end

Route103_EventScript_RivalMay::
@	msgbox Route103_Text_MayRoute103Pokemon, MSGBOX_DEFAULT
@	closemessage
@	playbgm MUS_ENCOUNTER_MAY, TRUE
@	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
@	waitmovement 0
@	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
@	waitmovement 0
@	applymovement LOCALID_RIVAL, Common_Movement_Delay48
@	waitmovement 0
@	msgbox Route103_Text_MayLetsBattle, MSGBOX_DEFAULT
@	switch VAR_STARTER_MON
@	case 0, Route103_EventScript_StartMayBattleTreecko
@	case 1, Route103_EventScript_StartMayBattleTorchic
@	case 2, Route103_EventScript_StartMayBattleMudkip
@	end

Route103_EventScript_RivalBrendan::
@	msgbox Route103_Text_BrendanRoute103Pokemon, MSGBOX_DEFAULT
@	closemessage
@	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
@	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
@	waitmovement 0
@	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
@	waitmovement 0
@	applymovement LOCALID_RIVAL, Common_Movement_Delay48
@	waitmovement 0
@	msgbox Route103_Text_BrendanLetsBattle, MSGBOX_DEFAULT
@	switch VAR_STARTER_MON
@	case 0, Route103_EventScript_StartBrendanBattleTreecko
@	case 1, Route103_EventScript_StartBrendanBattleTorchic
@	case 2, Route103_EventScript_StartBrendanBattleMudkip
@	end

Route103_EventScript_StartMayBattleTreecko::
@	trainerbattle_no_intro TRAINER_GRC_ALYSSA_TURPIA_TREECKO, Route103_Text_MayDefeated
@	goto Route103_EventScript_AfterMayBattle
@	end

Route103_EventScript_StartMayBattleTorchic::
@	trainerbattle_no_intro TRAINER_GRC_ALYSSA_TURPIA_TORCHIC, Route103_Text_MayDefeated
@	goto Route103_EventScript_AfterMayBattle
@	end

Route103_EventScript_StartMayBattleMudkip::
@	trainerbattle_no_intro TRAINER_GRC_ALYSSA_TURPIA_MUDKIP, Route103_Text_MayDefeated
@	goto Route103_EventScript_AfterMayBattle
@	end

Route103_EventScript_StartBrendanBattleTreecko::
@	trainerbattle_no_intro TRAINER_GRC_BASIL_TURPIA_TREECKO, Route103_Text_BrendanDefeated
@	goto Route103_EventScript_AfterBrendanBattle
@	end

Route103_EventScript_StartBrendanBattleTorchic::
@	trainerbattle_no_intro TRAINER_GRC_BASIL_TURPIA_TORCHIC, Route103_Text_BrendanDefeated
@	goto Route103_EventScript_AfterBrendanBattle
@	end

Route103_EventScript_StartBrendanBattleMudkip::
@	trainerbattle_no_intro TRAINER_GRC_BASIL_TURPIA_MUDKIP, Route103_Text_BrendanDefeated
@	goto Route103_EventScript_AfterBrendanBattle
@	end

Route103_EventScript_AfterMayBattle::
@	msgbox Route103_Text_MayTimeToHeadBack, MSGBOX_DEFAULT
@	goto Route103_EventScript_RivalExit
@	end

Route103_EventScript_AfterBrendanBattle::
@	msgbox Route103_Text_BrendanTimeToHeadBack, MSGBOX_DEFAULT
@	goto Route103_EventScript_RivalExit
@	end

Route103_EventScript_RivalExit::
@	closemessage
@	switch VAR_FACING
@	case DIR_SOUTH, Route103_EventScript_RivalExitFacingSouth
@	case DIR_NORTH, Route103_EventScript_RivalExitFacingNorth
@	case DIR_WEST, Route103_EventScript_RivalExitFacingEastOrWest
@	case DIR_EAST, Route103_EventScript_RivalExitFacingEastOrWest
@	end

Route103_EventScript_RivalExitFacingNorth::
@	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_WatchRivalExitFacingNorth
@	applymovement LOCALID_RIVAL, Route103_Movement_RivalExitFacingNorth1
@	waitmovement 0
@	playse SE_LEDGE
@	applymovement LOCALID_RIVAL, Route103_EventScript_RivalExitFacingNorth2
@	waitmovement 0
@	goto Route103_EventScript_RivalEnd
@	end

Route103_EventScript_RivalExitFacingEastOrWest::
@	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_WatchRivalExitFacingEastOrWest
@	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit1
@	waitmovement 0
@	playse SE_LEDGE
@	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit2
@	waitmovement 0
@	goto Route103_EventScript_RivalEnd
@	end

Route103_EventScript_RivalExitFacingSouth::
@	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit1
@	waitmovement 0
@	playse SE_LEDGE
@	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit2
@	waitmovement 0
@	goto Route103_EventScript_RivalEnd
@	end

Route103_EventScript_RivalEnd::
@	removeobject LOCALID_RIVAL
@	setvar VAR_BIRCH_LAB_STATE, 4
@	clearflag FLAG_GRC_HIDE_RIVALS_LAB
@	setflag FLAG_DEFEATED_RIVAL_ROUTE103
@	setvar VAR_OLDALE_RIVAL_STATE, 1
@	clearflag FLAG_HIDE_OLDALE_TOWN_RIVAL
@	savebgm MUS_DUMMY
@	fadedefaultbgm
@	releaseall
@	end

Route103_Movement_RivalExitFacingNorth1:
@	walk_left
@	walk_down
@	step_end

Route103_EventScript_RivalExitFacingNorth2:
@	jump_2_down
@	delay_16
@	walk_down
@	walk_down
@	walk_down
@	walk_down
@	step_end

Route103_Movement_WatchRivalExitFacingNorth:
@	delay_16
@	delay_4
@	walk_in_place_fastest_left
@	delay_16
@	walk_in_place_fastest_down
@	step_end

Route103_Movement_RivalExit1:
@	walk_down
@	step_end

Route103_Movement_RivalExit2:
@	jump_2_down
@	delay_16
@	walk_down
@	walk_down
@	walk_down
@	step_end

Route103_Movement_WatchRivalExitFacingEastOrWest:
@	delay_16
@	walk_in_place_fastest_down
@	step_end

Route103_EventScript_Boy::
@	msgbox Route103_Text_ShouldHaveBroughtPotion, MSGBOX_NPC
@	end

Route103_EventScript_Man::
@	msgbox Route103_Text_ShortcutToOldale, MSGBOX_NPC
@	end

Route103_EventScript_RouteSign::
@	msgbox Route103_Text_RouteSign, MSGBOX_SIGN
@	end

Route103_Text_MayRoute103Pokemon:
@	.string "MAY: Let's see… The POKéMON found\n"
@	.string "on ROUTE 103 include…$"

Route103_Text_MayLetsBattle:
@	.string "Oh, hi, {PLAYER}{KUN}!\p"
@	.string "…Oh, I see, my dad gave you\n"
@	.string "a POKéMON as a gift.\p"
@	.string "Since we're here, let's have a quick\n"
@	.string "battle!\p"
@	.string "I'll give you a taste of what being\n"
@	.string "a TRAINER is like.$"

Route103_Text_MayDefeated:
@	.string "Wow! That's great!\n"
@	.string "{PLAYER}{KUN}, you're pretty good!$"

Route103_Text_MayTimeToHeadBack:
@	.string "MAY: I think I know why my dad has\n"
@	.string "an eye out for you now.\p"
@	.string "I mean, you just got that POKéMON,\n"
@	.string "but it already likes you.\p"
@	.string "You might be able to befriend any\n"
@	.string "kind of POKéMON easily.\p"
@	.string "Well, it's time to head back to\n"
@	.string "the LAB.$"

Route103_Text_BrendanRoute103Pokemon:
@	.string "BRENDAN: Okay, so it's this one and\n"
@	.string "that one that live on ROUTE 103…$"

Route103_Text_BrendanLetsBattle:
@	.string "Hey, it's {PLAYER}!\p"
@	.string "…Oh, yeah, Dad gave you a POKéMON.\p"
@	.string "Since we're here, how about a little\n"
@	.string "battle?\p"
@	.string "I'll teach you what being a TRAINER's\n"
@	.string "about!$"

Route103_Text_BrendanDefeated:
@	.string "Huh, {PLAYER}, you're not too shabby.$"

Route103_Text_BrendanTimeToHeadBack:
@	.string "BRENDAN: I think I get it.\n"
@	.string "I think I know why my dad has his eye\l"
@	.string "out for you now.\p"
@	.string "Look, your POKéMON already likes you,\n"
@	.string "even though you just got it.\p"
@	.string "{PLAYER}, I get the feeling that you\n"
@	.string "could befriend any POKéMON with ease.\p"
@	.string "We should head back to the LAB.$"

Route103_Text_ShouldHaveBroughtPotion:
@	.string "My POKéMON is staggeringly tired…\n"
@	.string "I should have brought a POTION…$"

Route103_Text_ShortcutToOldale:
@	.string "If you cross the sea from here,\n"
@	.string "it'll be a shortcut to OLDALE TOWN.\p"
@	.string "Fufufu, that's useful, isn't it?$"

Route103_Text_RouteSign:
@	.string "ROUTE 103\n"
@	.string "{DOWN_ARROW} OLDALE TOWN$"

Route103_EventScript_Daisy_Text_0:
	.string "My little fluffy pal evolved! Now it's my\n"
	.string "big, super-fluffy pal!$"

Route103_EventScript_Daisy_Text_1:
	.string "At least Furret will always be the\n"
	.string "fluffiest! That's what matters.$"

Route103_EventScript_Daisy_Text_2:
	.string "We're not really battlers, but that's\n"
	.string "okay. What matters is that Furret and I\l"
	.string "are the best of pals!$"

Route103_EventScript_Andrew_Text_0:
	.string "Oh, I was just about to go for tea. But I\n"
	.string "can't refuse a Trainer's challenge, can\l"
	.string "I?$"

Route103_EventScript_Andrew_Text_1:
	.string "Now I could really use a nice brew…$"

Route103_EventScript_Andrew_Text_2:
	.string "I'm rather particular when it comes to\n"
	.string "my tea preferences. Even my Pokémon\l"
	.string "have their own tastes. Isn't that\l"
	.string "lovely?$"

Route103_EventScript_Marcos_Text_0:
	.string "I caught most of my Bug Pokémon in\n"
	.string "Borago Grove. I like the waterside\l"
	.string "more, though.$"

Route103_EventScript_Marcos_Text_1:
	.string "If only my Pokémon could swim…$"

Route103_EventScript_Marcos_Text_2:
	.string "They say Bug Pokémon live out here as\n"
	.string "well, but they must be super rare. I've\l"
	.string "never seen any here…$"

Route103_EventScript_Pete_Text_0:
	.string "I'm a little reclusive, but I love\n"
	.string "reading others' emotions. And right\l"
	.string "now, I can tell you are looking forward\l"
	.string "to challenging me. Very well!$"

Route103_EventScript_Pete_Text_1:
	.string "Such focus…!$"

Route103_EventScript_Pete_Text_2:
	.string "I've always been so fascinated by\n"
	.string "others' thoughts, but I find it hard to\l"
	.string "open my own heart. Perhaps that Black\l"
	.string "Belt over there…$"

Route103_EventScript_Rhett_Text_0:
	.string "I've learned a lot at school about how\n"
	.string "types interact. It's important to\l"
	.string "cover all your bases!$"

Route103_EventScript_Rhett_Text_1:
	.string "Seems you hit a blind spot…$"

Route103_EventScript_Rhett_Text_2:
	.string "I need to learn even more about\n"
	.string "Pokémon types. There's a lot of\l"
	.string "Pokémon with two types, too, so that\l"
	.string "makes it all the more interesting!$"

Route103_EventScript_Isabelle_Text_0:
	.string "To truly elevate your strength, your\n"
	.string "mind must be as strong as your body.\l"
	.string "That is why I try to stay calm at all\l"
	.string "times.$"

Route103_EventScript_Isabelle_Text_1:
	.string "This, too, is no reason to get worked up.$"

Route103_EventScript_Isabelle_Text_2:
	.string "A strong body without a strong spirit\n"
	.string "will crumble just as easily as weak\l"
	.string "body. Find your peace of mind, for that\l"
	.string "is the wellspring of true strength.$"

Route103_EventScript_Amy_Text_0:
	.string "Oh, what a darling Trainer we have here!\n"
	.string "Are your Pokémon just as precious?$"

Route103_EventScript_Amy_Text_1:
	.string "Ohhh, how charming!$"

Route103_EventScript_Amy_Text_2:
	.string "Oh, dearie me. One Pokémon? If you bring\n"
	.string "another, we can let our darlings out!$"

Route103_EventScript_Amy_Text_3:
	.string "Hello, hello, {PLAYER}! Would you look\n"
	.string "at our darling Pokémon once again?$"

Route103_EventScript_Amy_Text_4:
	.string "So strong, and yet so cute!$"

Route103_EventScript_Amy_Text_5:
	.string "You haven't forgotten about Double\n"
	.string "Battles, have you now, dear? We'll wait\l"
	.string "for you, don't worry!$"

Route103_EventScript_Amy_Text_6:
	.string "The love that Jim and I share extends\n"
	.string "to our Pokémon. I believe that's why\l"
	.string "they've grown so strong.$"

Route103_EventScript_Amy_Text_7:
	.string "I met my husband when my Hoothoot\n"
	.string "stumbled across his Psyduck. We've\l"
	.string "never been apart since!$"

Route103_EventScript_RegisterAmyAfterBattle_Text_0:
	.string "I think we'll be seeing many more\n"
	.string "delightful Pokémon from you. Care to\l"
	.string "register us?$"

Route103_EventScript_Liv_Text_0:
	.string "Trainer! Trainer! Behold our adorable\n"
	.string "Pokémon!$"

Route103_EventScript_Liv_Text_1:
	.string "Weren't they just delightful?$"

Route103_EventScript_Liv_Text_2:
	.string "Hello, Trainer! Could you bring another\n"
	.string "Pokémon? We'd love to show off our own!$"

Route103_EventScript_Liv_Text_3:
	.string "{PLAYER}! {PLAYER}! Our Pokémon\n"
	.string "have grown even more adorable than\l"
	.string "last time!$"

Route103_EventScript_Liv_Text_4:
	.string "They truly are such lovely little\n"
	.string "things…$"

Route103_EventScript_Liv_Text_5:
	.string "{PLAYER}! So good to see you! You're\n"
	.string "just a Pokémon short, though…$"

Route103_EventScript_Liv_Text_6:
	.string "No matter how big and strong, our\n"
	.string "Pokémon will always be our little\l"
	.string "darlings. They're our babies.$"

Route103_EventScript_Liv_Text_7:
	.string "My wife and I bonded over our shared\n"
	.string "love for Pokémon. It was love at first\l"
	.string "sight…$"

Route103_EventScript_RegisterLivAfterBattle_Text_0:
	.string "Please register us! We'd love to see\n"
	.string "what other kinds of adorable Pokémon\l"
	.string "you'll bring next time!$"

Route103_EventScript_Miguel_Text_0:
	.string "Heave-ho! Heave… HO! And that's how\n"
	.string "you catch a fish, young one!\p"
	.string "Now, I'll show you what my strength has\n"
	.string "earned me!$"

Route103_EventScript_Miguel_Text_1:
	.string "Hm… Seems I'll have to bulk up some\n"
	.string "more.$"

Route103_EventScript_Miguel_Text_2:
	.string "Heave-ho! Heave, heave, heave… HO! Care\n"
	.string "to join me, {PLAYER}?$"

Route103_EventScript_Miguel_Text_3:
	.string "Heave… HO!$"

Route103_EventScript_Miguel_Text_4:
	.string "I think I could defeat a sailor with\n"
	.string "these sculpted arms of mine! If you\l"
	.string "wish to know the secrets of fishing,\l"
	.string "then say it with me: Heave… HO!$"

Route103_EventScript_Miguel_Text_5:
	.string "It takes quite some strength to haul in\n"
	.string "the big fish. I do this every day, so my\l"
	.string "body is in tip-top shape!$"

Route103_EventScript_RegisterMiguelAfterBattle_Text_0:
	.string "I think we'll be seeing each other again.\n"
	.string "If you want to heave some fish with me,\l"
	.string "just give me a holler!$"

Route103_EventScript_CutGuy_Text_0:
	.string "Oh, hello! Sorry for blocking the road\n"
	.string "earlier. I'm a really passionate\l"
	.string "photographer, you see.\p"
	.string "I really wanted to take some nice shots\n"
	.string "of Starly, since they're just such\l"
	.string "darlings. Don't you agree?$"

Route103_EventScript_CutGuy_Text_1:
	.string "Okay, now to wait for just the right\n"
	.string "moment… Almost…\l"
	.string "Agh, it just flew away!\p"
	.string "Now I'll have to wait for another to\n"
	.string "stop by…$"

Route103_EventScript_SneyderBlock_Text_0:
	.string "Sneyder: Hey there, pal! We're real busy\n"
	.string "shooting another documentary with\l"
	.string "Professor Spruce.\p"
	.string "Can't really let you through right now.\n"
	.string "Sorry for stalling you!$"

Route103_EventScript_SurskitGal_Text_0:
	.string "There might be Bug Pokémon on this\n"
	.string "route, but I'd lie if I said I didn't want\l"
	.string "fifty Surskit!\p"
	.string "My word, they're just the most precious\n"
	.string "little things!$"
