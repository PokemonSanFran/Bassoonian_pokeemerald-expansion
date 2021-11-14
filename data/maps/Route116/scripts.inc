Route116_EventScript_Karen::
	trainerbattle_single TRAINER_GRC_HELEN_1, Route116_EventScript_Karen_Text_0, Route116_EventScript_Karen_Text_1, Route116_EventScript_RegisterKarenAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route116_EventScript_Karen_1
	msgbox Route116_EventScript_Karen_Text_5, MSGBOX_DEFAULT
	release
	return

Route116_EventScript_Karen_1:
	trainerbattle_rematch TRAINER_GRC_HELEN_1, Route116_EventScript_Karen_Text_2, Route116_EventScript_Karen_Text_3
	msgbox Route116_EventScript_Karen_Text_4, MSGBOX_AUTOCLOSE
	return


Route116_EventScript_RegisterKarenAfterBattle::
	msgbox Route116_EventScript_RegisterKarenAfterBattle_Text_0, MSGBOX_DEFAULT
	register_matchcall TRAINER_GRC_HELEN_1
	release
	return


Route116_EventScript_Joey::
	trainerbattle_single TRAINER_GRC_ZHEN, Route116_EventScript_Joey_Text_0, Route116_EventScript_Joey_Text_1
	msgbox Route116_EventScript_Joey_Text_2, MSGBOX_AUTOCLOSE
	return


Route116_EventScript_Jose::
	trainerbattle_single TRAINER_GRC_COREY, Route116_EventScript_Jose_Text_0, Route116_EventScript_Jose_Text_1
	msgbox Route116_EventScript_Jose_Text_2, MSGBOX_AUTOCLOSE
	return


Route116_EventScript_Clark::
	trainerbattle_single TRAINER_GRC_GABRIEL, Route116_EventScript_Clark_Text_0, Route116_EventScript_Clark_Text_1
	msgbox Route116_EventScript_Clark_Text_2, MSGBOX_AUTOCLOSE
	return


Route116_EventScript_Janice::
	trainerbattle_single TRAINER_GRC_BENNY, Route116_EventScript_Janice_Text_0, Route116_EventScript_Janice_Text_1
	msgbox Route116_EventScript_Janice_Text_2, MSGBOX_AUTOCLOSE
	return


Route116_EventScript_Dawson::
	trainerbattle_single TRAINER_GRC_RUDY, Route116_EventScript_Dawson_Text_0, Route116_EventScript_Dawson_Text_1
	msgbox Route116_EventScript_Dawson_Text_2, MSGBOX_AUTOCLOSE
	return


Route116_EventScript_Devan::
	trainerbattle_single TRAINER_GRC_PETE, Route116_EventScript_Devan_Text_0, Route116_EventScript_Devan_Text_1
	msgbox Route116_EventScript_Devan_Text_2, MSGBOX_AUTOCLOSE
	return


Route116_EventScript_Sarah::
	trainerbattle_single TRAINER_GRC_VERA, Route116_EventScript_Sarah_Text_0, Route116_EventScript_Sarah_Text_1
	msgbox Route116_EventScript_Sarah_Text_2, MSGBOX_AUTOCLOSE
	return


Route116_EventScript_Jerry::
	trainerbattle_single TRAINER_GRC_JOHNNY_1, Route116_EventScript_Jerry_Text_0, Route116_EventScript_Jerry_Text_1, Route116_EventScript_RegisterJerryAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route116_EventScript_Jerry_1
	msgbox Route116_EventScript_Jerry_Text_5, MSGBOX_DEFAULT
	release
	return

Route116_EventScript_Jerry_1:
	trainerbattle_rematch TRAINER_GRC_JOHNNY_1, Route116_EventScript_Jerry_Text_2, Route116_EventScript_Jerry_Text_3
	msgbox Route116_EventScript_Jerry_Text_4, MSGBOX_AUTOCLOSE
	return


Route116_EventScript_RegisterJerryAfterBattle::
	msgbox Route116_EventScript_RegisterJerryAfterBattle_Text_0, MSGBOX_DEFAULT
	register_matchcall TRAINER_GRC_JOHNNY_1
	release
	return


.set LOCALID_BRINEY, 11
.set LOCALID_WANDAS_BF_OUTSIDE, 21

Route116_MapScripts::
@	map_script MAP_SCRIPT_ON_TRANSITION, Route116_OnTransition
@	map_script MAP_SCRIPT_ON_LOAD, Route116_OnLoad
@	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route116_OnFrame
	.byte 0

Route116_OnTransition:
@	call_if_set FLAG_RECOVERED_DEVON_GOODS, Route116_EventScript_SetWandasBoyfriendPos
@	compare VAR_SHOULD_END_ABNORMAL_WEATHER, 1
@	call_if_eq AbnormalWeather_EventScript_HideMapNamePopup
@	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_NORTH
@	call_if_eq AbnormalWeather_StartGroudonWeather
@	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_SOUTH
@	call_if_eq AbnormalWeather_StartGroudonWeather
	end

Route116_EventScript_SetWandasBoyfriendPos::
@	setobjectxyperm LOCALID_WANDAS_BF_OUTSIDE, 38, 10
	return

Route116_OnLoad:
@	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_NORTH
@	call_if_eq AbnormalWeather_EventScript_PlaceTilesRoute116North
@	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_SOUTH
@	call_if_eq AbnormalWeather_EventScript_PlaceTilesRoute116South
	end

Route116_OnFrame:
@	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route116_EventScript_WandasBoyfriend::
@	lock
@	faceplayer
@	goto_if_set FLAG_RECOVERED_DEVON_GOODS, Route116_EventScript_BoyfriendGruntLeftTunnel
@	goto_if_set FLAG_DEVON_GOODS_STOLEN, Route116_EventScript_BoyfriendGruntInTunnel
@	msgbox Route116_Text_WantToDigTunnel, MSGBOX_DEFAULT
@	release
@	end

Route116_EventScript_BoyfriendGruntLeftTunnel::
@	msgbox Route116_Text_GoonHightailedItOutOfTunnel, MSGBOX_DEFAULT
@	release
@	end

Route116_EventScript_BoyfriendGruntInTunnel::
@	msgbox Route116_Text_DiggingTunnelWhenGoonOrderedMeOut, MSGBOX_DEFAULT
@	release
@	end

Route116_EventScript_DevonEmployee::
@	lock
@	faceplayer
@	goto_if_set FLAG_MET_DEVON_EMPLOYEE, Route116_EventScript_TryGiveRepeatBallAgain
@	msgbox Route116_Text_ThankYouTokenOfAppreciation, MSGBOX_DEFAULT
@	goto Route116_EventScript_GiveRepeatBall
@	end

Route116_EventScript_GiveRepeatBall::
@	setflag FLAG_MET_DEVON_EMPLOYEE
@	giveitem ITEM_REPEAT_BALL
@	compare VAR_RESULT, FALSE
@	goto_if_eq Route116_EventScript_NoRoomForRepeatBall
@	msgbox Route116_Text_NewBallAvailableAtMart, MSGBOX_DEFAULT
@	closemessage
@	compare VAR_FACING, DIR_NORTH
@	call_if_eq Route116_EventScript_DevonEmployeeExit
@	compare VAR_FACING, DIR_SOUTH
@	call_if_eq Route116_EventScript_DevonEmployeeExit
@	compare VAR_FACING, DIR_WEST
@	call_if_eq Route116_EventScript_DevonEmployeeExit
@	compare VAR_FACING, DIR_EAST
@	call_if_eq Route116_EventScript_DevonEmployeeExitEast
@	removeobject VAR_LAST_TALKED
@	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
@	setflag FLAG_RECEIVED_REPEAT_BALL
@	release
@	end

Route116_EventScript_DevonEmployeeExit::
@	applymovement VAR_LAST_TALKED, Route116_Movement_DevonEmployeeExit
@	waitmovement 0
@	return

Route116_EventScript_DevonEmployeeExitEast::
@	applymovement VAR_LAST_TALKED, Route116_Movement_DevonEmployeeExitEast
@	waitmovement 0
@	return

Route116_EventScript_TryGiveRepeatBallAgain::
@	msgbox Route116_Text_TokenOfAppreciation, MSGBOX_DEFAULT
@	goto Route116_EventScript_GiveRepeatBall
@	end

Route116_EventScript_NoRoomForRepeatBall::
@	msgbox Route116_Text_BagIsJamPacked, MSGBOX_DEFAULT
@	release
@	end

Route116_Movement_DevonEmployeeExit:
@	walk_left
@	walk_left
@	walk_left
@	walk_left
@	walk_left
@	walk_left
@	walk_left
@	walk_left
@	step_end

Route116_Movement_DevonEmployeeExitEast:
@	walk_down
@	walk_left
@	walk_left
@	walk_left
@	walk_left
@	walk_left
@	walk_left
@	walk_left
@	walk_left
@	walk_left
@	step_end

Route116_EventScript_RouteSignRustboro::
@	msgbox Route116_Text_RouteSignRustboro, MSGBOX_SIGN
@	end

Route116_EventScript_RusturfTunnelSign::
@	msgbox Route116_Text_RusturfTunnelSign, MSGBOX_SIGN
@	end

Route116_EventScript_TunnelersRestHouseSign::
@	msgbox Route116_Text_TunnelersRestHouse, MSGBOX_SIGN
@	end

Route116_EventScript_TrainerTipsBToStopEvolution::
@	msgbox Route116_Text_TrainerTipsBToStopEvolution, MSGBOX_SIGN
@	end

Route116_EventScript_TrainerTipsBagHasPockets::
@	msgbox Route116_Text_TrainerTipsBagHasPockets, MSGBOX_SIGN
@	end

Route116_EventScript_Briney::
@	lock
@	faceplayer
@	msgbox Route116_Text_ScoundrelMadeOffWithPeeko, MSGBOX_DEFAULT
@	setvar VAR_ROUTE116_STATE, 2
@	release
@	end

Route116_EventScript_BrineyTrigger::
@	lockall
@	applymovement LOCALID_BRINEY, Common_Movement_WalkInPlaceFastestRight
@	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
@	waitmovement 0
@	msgbox Route116_Text_ScoundrelMadeOffWithPeeko, MSGBOX_DEFAULT
@	setvar VAR_ROUTE116_STATE, 2
@	releaseall
@	end

Route116_EventScript_GlassesMan::
@	lock
@	faceplayer
@	checkitem ITEM_BLACK_GLASSES, 1
@	compare VAR_RESULT, TRUE
@	goto_if_eq Route116_EventScript_PlayerHasGlasses
@	specialvar VAR_RESULT, FoundBlackGlasses
@	compare VAR_RESULT, TRUE
@	goto_if_eq Route116_EventScript_FoundGlassesNotOnPlayer
@	msgbox Route116_Text_CanYouHelpMeFindGlasses, MSGBOX_DEFAULT
@	release
@	end

Route116_EventScript_FoundGlassesNotOnPlayer::
@	msgbox Route116_Text_CantFindGlassesNotHere, MSGBOX_DEFAULT
@	closemessage
@	goto Route116_EventScript_GlassesManExit
@	end

Route116_EventScript_PlayerHasGlasses::
@	msgbox Route116_Text_CanYouHelpMeFindGlasses, MSGBOX_DEFAULT
@	msgbox Route116_Text_MayISeeThoseGlasses, MSGBOX_DEFAULT
@	specialvar VAR_RESULT, FoundBlackGlasses
@	compare VAR_RESULT, TRUE
@	goto_if_eq Route116_EventScript_FoundGlassesOnPlayer
@	msgbox Route116_Text_NotWhatImLookingFor, MSGBOX_DEFAULT
@	release
@	end

Route116_EventScript_FoundGlassesOnPlayer::
@	msgbox Route116_Text_NotWhatImLookingForMaybeTheyArentHere, MSGBOX_DEFAULT
@	closemessage
@	goto Route116_EventScript_GlassesManExit
@	end

Route116_EventScript_GlassesManExit::
@	delay 20
@	compare VAR_FACING, DIR_NORTH
@	call_if_eq Route116_EventScript_GlassesManExitNormal
@	compare VAR_FACING, DIR_SOUTH
@	call_if_eq Route116_EventScript_GlassesManExitNormal
@	compare VAR_FACING, DIR_WEST
@	call_if_eq Route116_EventScript_GlassesManExitNormal
@	compare VAR_FACING, DIR_EAST
@	call_if_eq Route116_EventScript_GlassesManExitEast
@	removeobject VAR_LAST_TALKED
@	release
@	end

Route116_EventScript_GlassesManExitNormal::
@	applymovement VAR_LAST_TALKED, Route116_Movement_GlassesManExit
@	waitmovement 0
@	return

Route116_EventScript_GlassesManExitEast::
@	applymovement VAR_LAST_TALKED, Route116_Movement_GlassesManExitEast
@	waitmovement 0
@	return

Route116_Movement_GlassesManExit:
@	walk_left
@	walk_left
@	walk_left
@	walk_left
@	walk_left
@	walk_left
@	walk_left
@	walk_left
@	walk_left
@	step_end

Route116_Movement_GlassesManExitEast:
@	walk_up
@	walk_left
@	walk_left
@	walk_left
@	walk_left
@	walk_left
@	walk_left
@	walk_left
@	walk_left
@	walk_left
@	step_end

Route116_Text_ScoundrelMadeOffWithPeeko:
@	.string "Ohhh, what am I to do?\p"
@	.string "We were on our walk, PEEKO and I, when\n"
@	.string "we were jumped by an odd thug…\p"
@	.string "The scoundrel made off with my\n"
@	.string "darling PEEKO!\p"
@	.string "Wrrrooooooaaaar! PEEKO!$"

Route116_Text_WantToDigTunnel:
@	.string "Nnn… Roar!\p"
@	.string "I want to dig that tunnel!$"

Route116_Text_DiggingTunnelWhenGoonOrderedMeOut:
@	.string "Nnn… Roar!\n"
@	.string "What's going on?\p"
@	.string "I was digging the tunnel without any\n"
@	.string "tools when some goon ordered me out!\p"
@	.string "That tunnel's filled with POKéMON\n"
@	.string "that react badly to loud noises.\l"
@	.string "They could cause an uproar.\p"
@	.string "That's why we stopped using heavy\n"
@	.string "equipment for tunneling…\p"
@	.string "I'm worried that the goon will do\n"
@	.string "something stupid and startle the\l"
@	.string "POKéMON into an uproar.$"

Route116_Text_GoonHightailedItOutOfTunnel:
@	.string "Nnn… Roar!\p"
@	.string "That goofy goon hightailed it out of\n"
@	.string "the tunnel! I can go back to digging!$"

Route116_Text_ThankYouTokenOfAppreciation:
@	.string "Oh! It's you!\p"
@	.string "You're that person who not only helped\n"
@	.string "me in PETALBURG WOODS, but also got\l"
@	.string "back my stolen package and then even\l"
@	.string "graciously delivered it to SLATEPORT!\p"
@	.string "CAPT. STERN informed us that the\n"
@	.string "package arrived, too!\p"
@	.string "I thank you very, very much!\p"
@	.string "Why, if I were a rain cloud, I would\n"
@	.string "shower you with gratitude and hail\l"
@	.string "you as a hero!\p"
@	.string "For you, the most wonderful TRAINER,\n"
@	.string "I bear good news!\p"
@	.string "Recently, our company developed\n"
@	.string "a new kind of POKé BALL.\p"
@	.string "As a token of our appreciation, this\n"
@	.string "is our gift to our wonderful TRAINER!$"

Route116_Text_NewBallAvailableAtMart:
@	.string "Our new POKé BALL will be available\n"
@	.string "at the POKéMON MART in RUSTBORO.\p"
@	.string "Please do try it out!\n"
@	.string "Thank you and bye-bye!$"

Route116_Text_BagIsJamPacked:
@	.string "Your BAG is jam-packed.\n"
@	.string "I can't give you this REPEAT BALL.$"

Route116_Text_TokenOfAppreciation:
@	.string "As a token of our appreciation for\n"
@	.string "your delivering our package, I have\l"
@	.string "a gift of a new kind of POKé BALL\l"
@	.string "for our most wonderful TRAINER!$"

Route116_Text_CanYouHelpMeFindGlasses:
@	.string "I dropped my glasses…\n"
@	.string "Can you help me find them?$"

Route116_Text_MayISeeThoseGlasses:
@	.string "Those glasses!\n"
@	.string "May I see them for a second?$"

Route116_Text_NotWhatImLookingForMaybeTheyArentHere:
@	.string "Hmm…\n"
@	.string "These are BLACKGLASSES.\l"
@	.string "They're not what I'm looking for…\p"
@	.string "Maybe my glasses aren't around\n"
@	.string "here…$"

Route116_Text_CantFindGlassesNotHere:
@	.string "Hmm…\n"
@	.string "I can't find my glasses anywhere…\l"
@	.string "Maybe they're not around here…$"

Route116_Text_NotWhatImLookingFor:
@	.string "Hmm…\n"
@	.string "These are BLACKGLASSES.\l"
@	.string "They're not what I'm looking for…$"

Route116_Text_RouteSignRustboro:
@	.string "ROUTE 116\n"
@	.string "{LEFT_ARROW} RUSTBORO CITY$"

Route116_Text_RusturfTunnelSign:
@	.string "RUSTURF TUNNEL\n"
@	.string "“Linking RUSTBORO and VERDANTURF\p"
@	.string "“The tunnel project has been\n"
@	.string "canceled.”$"

Route116_Text_TunnelersRestHouse:
@	.string "TUNNELER'S REST HOUSE$"

Route116_Text_TrainerTipsBToStopEvolution:
@	.string "TRAINER TIPS\p"
@	.string "If you want to stop a POKéMON from\n"
@	.string "evolving, press the B Button while it\l"
@	.string "is trying to evolve.\l"
@	.string "The startled POKéMON will stop.\p"
@	.string "This is called an evolution cancel.$"

Route116_Text_TrainerTipsBagHasPockets:
@	.string "TRAINER TIPS\p"
@	.string "Your BAG has several POCKETS.\p"
@	.string "Items you obtain are automatically\n"
@	.string "placed in the appropriate POCKETS.\p"
@	.string "No TRAINER can afford to be without\n"
@	.string "a BAG of their own.$"

Route116_EventScript_Karen_Text_0:
	.string "Oh, such a feisty Trainer. Would you\n"
	.string "care to lift my boredom for a spell?$"

Route116_EventScript_Karen_Text_1:
	.string "Oh, my! How refreshing. Thank you.$"

Route116_EventScript_Karen_Text_2:
	.string "Ah, how wonderful to see you again.\n"
	.string "Would you mind lifting the veil of\l"
	.string "boredom once more?$"

Route116_EventScript_Karen_Text_3:
	.string "Ahahahaha! Such a refreshing feeling.\n"
	.string "Thank you so much!$"

Route116_EventScript_Karen_Text_4:
	.string "I was raised in a sheltered environment\n"
	.string "without much freedom. I was envious of\l"
	.string "all my less-endowed peers, for they\l"
	.string "enjoyed what I could not: freedom.\l"
	.string "Seeing Trainers such as you reminds me\l"
	.string "of those memories.$"

Route116_EventScript_Karen_Text_5:
	.string "When money is abundant, there is much\n"
	.string "that lies at your fingertips, but\l"
	.string "excitement can be hard to find…$"

Route116_EventScript_RegisterKarenAfterBattle_Text_0:
	.string "I would enjoy a little distraction from\n"
	.string "the mundane things in life now and\l"
	.string "again. Would you care to add me as a\l"
	.string "contact?$"

Route116_EventScript_Joey_Text_0:
	.string "My partner has taught me a new way of\n"
	.string "training: lifting logs! Allow me to\l"
	.string "demonstrate!$"

Route116_EventScript_Joey_Text_1:
	.string "Oww… Pulled a muscle…$"

Route116_EventScript_Joey_Text_2:
	.string "The best part about log lifting: Timburr\n"
	.string "and I can be one with nature as we\l"
	.string "train! Isn't that fantastic?$"

Route116_EventScript_Jose_Text_0:
	.string "When I was little, I loved playing by the\n"
	.string "waterside. That's how I met my Bug\l"
	.string "Pokémon!$"

Route116_EventScript_Jose_Text_1:
	.string "Sure made a splash, huh?$"

Route116_EventScript_Jose_Text_2:
	.string "Me, Surskit and Dewpider are the best\n"
	.string "of pals! I wonder if we can cross the\l"
	.string "ocean someday…$"

Route116_EventScript_Clark_Text_0:
	.string "I can meditate for hours, but then I\n"
	.string "forget to eat…$"

Route116_EventScript_Clark_Text_1:
	.string "Ugh, I'm starving!$"

Route116_EventScript_Clark_Text_2:
	.string "To meditate is to let go of concerns…\n"
	.string "although I suppose there's no way\l"
	.string "around physiological needs.$"

Route116_EventScript_Janice_Text_0:
	.string "Caves, chasms, cliffs and mountains!\n"
	.string "Those are the thrills we Hikers live\l"
	.string "for!$"

Route116_EventScript_Janice_Text_1:
	.string "Battles? Not so much our thing.$"

Route116_EventScript_Janice_Text_2:
	.string "You're aiming to get all the Badges,\n"
	.string "aren't you? Good luck on the climb, my\l"
	.string "friend!$"

Route116_EventScript_Dawson_Text_0:
	.string "I can't really let my iron steed rip here.\n"
	.string "Guess I'll compensate by going full\l"
	.string "throttle this fight!$"

Route116_EventScript_Dawson_Text_1:
	.string "Whoa, whoa! Easy there!$"

Route116_EventScript_Dawson_Text_2:
	.string "I've heard there's a biker's road not\n"
	.string "too far from here. I'm gonna check that\l"
	.string "place out soon!$"

Route116_EventScript_Devan_Text_0:
	.string "I'm about to graduate from the\n"
	.string "Trainer's School in Poppy Town. I'll\l"
	.string "show you what I've learned there!$"

Route116_EventScript_Devan_Text_1:
	.string "Guess I still have a long way to go.$"

Route116_EventScript_Devan_Text_2:
	.string "Win or lose, what matters is what you\n"
	.string "learn from every encounter. That's why\l"
	.string "I'll never be mad about losing.$"

Route116_EventScript_Sarah_Text_0:
	.string "My mommy and daddy bought me the best\n"
	.string "schoolbooks. I've gathered so much\l"
	.string "knowledge from reading them! Time to\l"
	.string "test that!$"

Route116_EventScript_Sarah_Text_1:
	.string "No! Where did I go wrong?$"

Route116_EventScript_Sarah_Text_2:
	.string "I guess there are things books can't\n"
	.string "teach you… I'll still keep reading them,\l"
	.string "though!$"

Route116_EventScript_Jerry_Text_0:
	.string "Today's a good day! Hehe, I'm feeling\n"
	.string "good about this! Let's roll!$"

Route116_EventScript_Jerry_Text_1:
	.string "Ah well! Not gonna let that get me down!$"

Route116_EventScript_Jerry_Text_2:
	.string "Guess what?! I got even more energy\n"
	.string "now than last time! Let's DO this!$"

Route116_EventScript_Jerry_Text_3:
	.string "Hahahahaha! Great show!$"

Route116_EventScript_Jerry_Text_4:
	.string "Yeah, I prefer to look on the bright\n"
	.string "side of things! When my spirit's up,\l"
	.string "there's nothing that can stand in my\l"
	.string "way!$"

Route116_EventScript_Jerry_Text_5:
	.string "People tell me I have a lot of energy.\n"
	.string "And that's all energy I invest into my\l"
	.string "training!$"

Route116_EventScript_RegisterJerryAfterBattle_Text_0:
	.string "It's good to have someone who can keep\n"
	.string "me on my toes! Let's exchange numbers!$"
