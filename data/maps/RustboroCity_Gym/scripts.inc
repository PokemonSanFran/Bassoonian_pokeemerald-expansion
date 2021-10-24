RustboroCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RustboroCityGym_MoveWhenDone
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCityGym_MoveWhenDone2
	.byte 0


RustboroCityGym_MoveWhenDone::
	goto_if_set FLAG_BADGE01_GET, RustboroCityGym_MoveWhenDone_1
	return

RustboroCityGym_MoveWhenDone_1:
	call PoppyGym_Trigger1
	call PoppyGym_Trigger2
	setobjectxyperm 7, 1, 15
	setobjectxyperm 8, 9, 4
	return


RustboroCityGym_MoveWhenDone2::
	goto_if_set FLAG_BADGE01_GET, RustboroCityGym_MoveWhenDone2_1
	return

RustboroCityGym_MoveWhenDone2_1:
	return


PoppyGym_Trigger1::
	setvar VAR_TEMP_0, 1
	setmetatile 9, 11, 0x209, 0
	setmetatile 9, 12, 0x209, 0
	return


PoppyGym_Trigger2::
	setvar VAR_TEMP_1, 1
	setmetatile 1, 6, 0x209, 0
	setmetatile 1, 7, 0x209, 0
	return


RustboroCity_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_Gym_EventScript_Roxanne_Text_0, RustboroCity_Gym_EventScript_Roxanne_Text_1, RustboroCity_Gym_EventScript_RoxanneDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq RustboroCity_Gym_EventScript_Roxanne_2
RustboroCity_Gym_EventScript_Roxanne_1:
	goto_if_unset FLAG_RECEIVED_TM39, RustboroCity_Gym_EventScript_Roxanne_5
RustboroCity_Gym_EventScript_Roxanne_4:
	msgbox RustboroCity_Gym_EventScript_Roxanne_Text_2, MSGBOX_DEFAULT
	release
	return

RustboroCity_Gym_EventScript_Roxanne_2:
	goto RustboroCity_Gym_EventScript_RoxanneRematch
	goto RustboroCity_Gym_EventScript_Roxanne_1

RustboroCity_Gym_EventScript_Roxanne_5:
	goto RustboroCity_Gym_EventScript_GiveRockTomb
	goto RustboroCity_Gym_EventScript_Roxanne_4


RustboroCity_Gym_EventScript_RoxanneDefeated::
	message RustboroCity_Gym_EventScript_RoxanneDefeated_Text_0
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RustboroCity_Gym_EventScript_RoxanneDefeated_Text_1, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	clearflag FLAG_GRC_HIDE_RIVAL_POPPY
	setvar VAR_PETALBURG_WOODS_STATE, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	goto RustboroCity_Gym_EventScript_GiveRockTomb
	end


RustboroCity_Gym_EventScript_GiveRockTomb::
	giveitem ITEM_TM08
	setflag FLAG_RECEIVED_TM39
	msgbox RustboroCity_Gym_EventScript_GiveRockTomb_Text_0, MSGBOX_DEFAULT
	release
	end


RustboroCity_Gym_EventScript_Josh::
	trainerbattle_single TRAINER_GRC_LI, RustboroCity_Gym_EventScript_Josh_Text_0, RustboroCity_Gym_EventScript_Josh_Text_1
	msgbox RustboroCity_Gym_EventScript_Josh_Text_2, MSGBOX_AUTOCLOSE
	return


RustboroCity_Gym_EventScript_Tommy::
	trainerbattle_single TRAINER_GRC_KEN, RustboroCity_Gym_EventScript_Tommy_Text_0, RustboroCity_Gym_EventScript_Tommy_Text_1
	msgbox RustboroCity_Gym_EventScript_Tommy_Text_2, MSGBOX_AUTOCLOSE
	return


RustboroCity_Gym_EventScript_Marc::
	trainerbattle_double TRAINER_GRC_ANDI_AND_MAI, RustboroCity_Gym_EventScript_Marc_Text_0, RustboroCity_Gym_EventScript_Marc_Text_1, RustboroCity_Gym_EventScript_Marc_Text_2
	msgbox RustboroCity_Gym_EventScript_Marc_Text_3, MSGBOX_AUTOCLOSE
	return


RustboroCity_Gym_EventScript_Marc2::
	trainerbattle_double TRAINER_GRC_ANDI_AND_MAI, RustboroCity_Gym_EventScript_Marc2_Text_0, RustboroCity_Gym_EventScript_Marc2_Text_1, RustboroCity_Gym_EventScript_Marc2_Text_2
	msgbox RustboroCity_Gym_EventScript_Marc2_Text_3, MSGBOX_AUTOCLOSE
	return


RustboroCity_Gym_EventScript_RoxanneRematch::
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
	end


RustboroCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymGuide_2
	goto_if_unset FLAG_GRC_GYM1_FRESHWATER, RustboroCity_Gym_EventScript_GymGuide_6
RustboroCity_Gym_EventScript_GymGuide_5:
	msgbox RustboroCity_Gym_EventScript_GymGuide_Text_2
RustboroCity_Gym_EventScript_GymGuide_1:
	closemessage
	release
	return

RustboroCity_Gym_EventScript_GymGuide_2:
	msgbox RustboroCity_Gym_EventScript_GymGuide_Text_0
	goto RustboroCity_Gym_EventScript_GymGuide_1

RustboroCity_Gym_EventScript_GymGuide_6:
	msgbox RustboroCity_Gym_EventScript_GymGuide_Text_1
	giveitem ITEM_FRESH_WATER
	setflag FLAG_GRC_GYM1_FRESHWATER
	goto RustboroCity_Gym_EventScript_GymGuide_5


RustboroCity_Gym_Statue::
	msgbox RustboroCity_Gym_Statue_Text_0, MSGBOX_SIGN
	return


@RustboroCity_Gym_EventScript_GymGuide::
@	lock
@	faceplayer
@	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
@	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
@	release
@	end

RustboroCity_Gym_EventScript_GymGuidePostVictory::
@	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
@	release
@	end

RustboroCity_Gym_EventScript_LeftGymStatue::
@	lockall
@	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
@	goto RustboroCity_Gym_EventScript_GymStatue
@	end

RustboroCity_Gym_EventScript_RightGymStatue::
@	lockall
@	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
@	goto RustboroCity_Gym_EventScript_GymStatue
@	end

RustboroCity_Gym_EventScript_GymStatueCertified::
@	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
@	releaseall
@	end

RustboroCity_Gym_EventScript_GymStatue::
@	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
@	releaseall
@	end

RustboroCity_Gym_EventScript_RegisterRoxanne::
@	lockall
@	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
@	waitmessage
@	delay 30
@	playfanfare MUS_REGISTER_MATCH_CALL
@	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
@	waitfanfare
@	closemessage
@	delay 30
@	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
@	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
@	releaseall
@	end

RustboroCity_Gym_Text_GymGuideAdvice:
@	.string "Yo, how's it going?\p"
@	.string "Listen, my friend!\n"
@	.string "Would you like to become the CHAMPION?\p"
@	.string "I'm no TRAINER, not me, but I can\n"
@	.string "sure give you winning advice.\p"
@	.string "That's settled, then! We'll aim for the\n"
@	.string "POKéMON CHAMPIONSHIP together!\p"
@	.string "It's your job as a TRAINER to collect\n"
@	.string "GYM BADGES, am I right?\p"
@	.string "But GYM LEADERS aren't pushovers!\p"
@	.string "And that's where I come in!\n"
@	.string "I'm here to provide expert advice!\p"
@	.string "ROXANNE, the GYM LEADER, is a user\n"
@	.string "of ROCK-type POKéMON.\p"
@	.string "The ROCK type is very durable, but\n"
@	.string "it can't stand WATER-type and\l"
@	.string "GRASS-type moves.\p"
@	.string "Come see me afterwards, if you beat\n"
@	.string "the GYM LEADER.\p"
@	.string "Well, go for it!$"

RustboroCity_Gym_Text_GymGuidePostVictory:
@	.string "Whoa! What a breathtaking victory!\n"
@	.string "My cheering must've worked!\p"
@	.string "Great!\n"
@	.string "Check your TRAINER CARD.\p"
@	.string "The STONE BADGE you got should be\n"
@	.string "properly recorded on it.\p"
@	.string "In other words…\p"
@	.string "You've climbed the first step on\n"
@	.string "the stairs to the CHAMPIONSHIP!\p"
@	.string "That's got to feel awesome!$"

RustboroCity_Gym_Text_JoshIntro:
@	.string "Don't take us GYM TRAINERS lightly!\n"
@	.string "I'll show you why we're better!$"

RustboroCity_Gym_Text_JoshDefeat:
@	.string "You were too good for me…$"

RustboroCity_Gym_Text_JoshPostBattle:
@	.string "You haven't seen anything of the ROCK\n"
@	.string "type's terrifying power!$"

RustboroCity_Gym_Text_TommyIntro:
@	.string "If you can't beat me, you won't stand\n"
@	.string "a chance against ROXANNE!$"

RustboroCity_Gym_Text_TommyDefeat:
@	.string "Wow! You've got some potential!$"

RustboroCity_Gym_Text_TommyPostBattle:
@	.string "ROXANNE is stronger than me by\n"
@	.string "several times.\p"
@	.string "You'd better be on your guard!$"

RustboroCity_Gym_Text_MarcIntro:
@	.string "We might be in the middle of town,\n"
@	.string "but so what?\p"
@	.string "My ROCK POKéMON need room to\n"
@	.string "rampage!$"

RustboroCity_Gym_Text_MarcDefeat:
@	.string "Oh, man oh man!\n"
@	.string "Our challenger is one feisty customer!$"

RustboroCity_Gym_Text_MarcPostBattle:
@	.string "I have to hand it to our LEADER.\p"
@	.string "It took smarts and sense for her to\n"
@	.string "pick the ROCK type at her young age.$"

RustboroCity_Gym_Text_RoxanneIntro:
@	.string "Hello, I am ROXANNE, the RUSTBORO\n"
@	.string "POKéMON GYM LEADER.\p"
@	.string "I became a GYM LEADER so that I might\n"
@	.string "apply what I learned at the POKéMON\l"
@	.string "TRAINER'S SCHOOL in battle.\p"
@	.string "Would you kindly demonstrate how you\n"
@	.string "battle, and with which POKéMON?$"

RustboroCity_Gym_Text_RoxanneDefeat:
@	.string "So…\n"
@	.string "I lost…\p"
@	.string "It seems that I still have much more\n"
@	.string "to learn…\p"
@	.string "I understand.\p"
@	.string "The POKéMON LEAGUE's rules state\n"
@	.string "that TRAINERS are to be given this\l"
@	.string "if they defeat a GYM LEADER.\p"
@	.string "Please accept the official POKéMON\n"
@	.string "LEAGUE STONE BADGE.$"

RustboroCity_Gym_Text_ReceivedStoneBadge:
@	.string "{PLAYER} received the STONE BADGE\n"
@	.string "from ROXANNE.$"

RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
@	.string "The STONE BADGE heightens the ATTACK\n"
@	.string "power of your POKéMON.\p"
@	.string "It also enables them to use the HM move\n"
@	.string "CUT outside of battle.\p"
@	.string "Please take this with you, too.$"

RustboroCity_Gym_Text_ExplainRockTomb:
@	.string "That TECHNICAL MACHINE, TM39,\n"
@	.string "contains ROCK TOMB.\p"
@	.string "It not only inflicts damage by dropping\n"
@	.string "rocks, it also lowers SPEED.\p"
@	.string "If you use a TM, it instantly teaches\n"
@	.string "the move to a POKéMON.\p"
@	.string "Remember, a TM can be used only once,\n"
@	.string "so think before you use it.$"

RustboroCity_Gym_Text_RoxannePostBattle:
@	.string "Since you are so strong, you should\n"
@	.string "challenge other GYM LEADERS.\p"
@	.string "By battling many TRAINERS, you should\n"
@	.string "learn many things.$"

RustboroCity_Gym_Text_GymStatue:
@	.string "RUSTBORO CITY POKéMON GYM$"

RustboroCity_Gym_Text_GymStatueCertified:
@	.string "RUSTBORO CITY POKéMON GYM\p"
@	.string "ROXANNE'S CERTIFIED TRAINERS:\n"
@	.string "{PLAYER}$"

RustboroCity_Gym_Text_RoxanneRegisterCall:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "ROXANNE: Oh, hello, {PLAYER}?\n"
	.string "This is ROXANNE of RUSTBORO CITY.\p"
	.string "I heard from BRAWLY that you're\n"
	.string "moving up through the ranks of\l"
	.string "TRAINERS at an incredible clip.\p"
	.string "Well, I'd rather not think that\n"
	.string "I can't beat you.\p"
	.string "I promise, I will shape up my GYM\n"
	.string "so that you may challenge us again.\p"
	.string "I hope you'll be looking forward to\n"
	.string "that occasion as much as me!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

RustboroCity_Gym_Text_RegisteredRoxanne:
	.string "Registered GYM LEADER ROXANNE\n"
	.string "in the POKéNAV.$"

RustboroCity_Gym_Text_RoxannePreRematch:
	.string "ROXANNE: I'm so glad to see you again.\n"
	.string "I'm ROXANNE, the GYM LEADER here.\p"
	.string "I'm sure we've both experienced many\n"
	.string "battles since we last met.\p"
	.string "I would like to see how much better\n"
	.string "we've become. Let us battle!$"

RustboroCity_Gym_Text_RoxanneRematchDefeat:
	.string "Grr…\n"
	.string "Again, I have lost…$"

RustboroCity_Gym_Text_RoxannePostRematch:
	.string "ROXANNE: I still have much to learn\n"
	.string "when it comes to battling POKéMON.\p"
	.string "That awareness makes me love battling\n"
	.string "all that much more!$"

RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons:
	.string "ROXANNE: I'm so glad to see you again.\n"
	.string "I'm ROXANNE, the GYM LEADER here.\p"
	.string "I'm sure we've both experienced many\n"
	.string "battles since we last met.\p"
	.string "I would like to see how much better\n"
	.string "we've become…\p"
	.string "Oh, no…\n"
	.string "You only have one POKéMON with you?\p"
	.string "Please return with at least one more\n"
	.string "POKéMON.$"

RustboroCity_Gym_EventScript_Roxanne_Text_0:
	.string "Hey there, challenger! I'm Talia, the Gym\n"
	.string "Leader of this town.\p"
	.string "What did you think of my Dollbags?\n"
	.string "Weren't they just the cutest darlings?\l"
	.string "You bet they were!\p"
	.string "What, did you think a girl couldn't be\n"
	.string "both cute and strong? Well, that's\l"
	.string "where you're wrong!\p"
	.string "I'll prove it to you right here, right\n"
	.string "now! Give me your best shot!$"

RustboroCity_Gym_EventScript_Roxanne_Text_1:
	.string "Wow… That was impressive! That really\n"
	.string "got my pulse racing, you know?\p"
	.string "Anyway, you've beaten me fair and\n"
	.string "square, so you've earned the Effort\l"
	.string "Badge!$"

RustboroCity_Gym_EventScript_Roxanne_Text_2:
	.string "Why do I love dolls so much? Well, I've\n"
	.string "grown up with them!\p"
	.string "My granny is a renowned doll artist, and\n"
	.string "I've been studying to become her\l"
	.string "successor.\p"
	.string "I love working out just as much, so I've\n"
	.string "combined my two passions here! Pretty\l"
	.string "nice, huh?$"

RustboroCity_Gym_EventScript_RoxanneDefeated_Text_0:
	.string "{PLAYER} received the Effort Badge\n"
	.string "from Talia!$"

RustboroCity_Gym_EventScript_RoxanneDefeated_Text_1:
	.string "Oh, I want you to have this, too!$"

RustboroCity_Gym_EventScript_GiveRockTomb_Text_0:
	.string "TM08 contains Bulk Up! It's a real nifty\n"
	.string "move that raises your Pokémon's\l"
	.string "Attack and Defense stats!\p"
	.string "I'm sure you'll be able to take\n"
	.string "advantage of it just fine, knowing how\l"
	.string "skilled you are.$"

RustboroCity_Gym_EventScript_Josh_Text_0:
	.string "Hold it, Trainer! Don't think you can\n"
	.string "just barge through and challenge the\l"
	.string "Gym Leader! You'll have to go through\l"
	.string "me first!$"

RustboroCity_Gym_EventScript_Josh_Text_1:
	.string "Ow, ow, ow… I pulled a muscle…$"

RustboroCity_Gym_EventScript_Josh_Text_2:
	.string "You're free to go on through. Oww… I\n"
	.string "really shouldn't have done that…$"

RustboroCity_Gym_EventScript_Tommy_Text_0:
	.string "Dollbags! We push them! We lift them!\n"
	.string "They guide us to our inner strength!$"

RustboroCity_Gym_EventScript_Tommy_Text_1:
	.string "Dollbaaaaaags!$"

RustboroCity_Gym_EventScript_Tommy_Text_2:
	.string "Talia's a genius! Who else would've\n"
	.string "thought of combining aesthetics and\l"
	.string "practicality like that? Right, time to\l"
	.string "lift some more!$"

RustboroCity_Gym_EventScript_Marc_Text_0:
	.string "I've been training with Mai to improve\n"
	.string "our focus. Let's see if that's paid off!$"

RustboroCity_Gym_EventScript_Marc_Text_1:
	.string "Ah, well. We've tried our hardest.$"

RustboroCity_Gym_EventScript_Marc_Text_2:
	.string "We will not fight anyone with fewer than\n"
	.string "two Pokémon. Come back and fight us\l"
	.string "once you're ready.$"

RustboroCity_Gym_EventScript_Marc_Text_3:
	.string "It seems we both have so much more to\n"
	.string "learn. But that's why we stick\l"
	.string "together.$"

RustboroCity_Gym_EventScript_Marc2_Text_0:
	.string "Andy and I have been training together.\n"
	.string "We're gonna give this our all!$"

RustboroCity_Gym_EventScript_Marc2_Text_1:
	.string "Oh, no… I flubbed it…$"

RustboroCity_Gym_EventScript_Marc2_Text_2:
	.string "Um… aren't you missing a Pokémon? We\n"
	.string "stand by fair play, so we'll wait for you\l"
	.string "to bring another.$"

RustboroCity_Gym_EventScript_Marc2_Text_3:
	.string "We might've been beaten, but I'm not\n"
	.string "gonna let one bad fight ruin my mood.\l"
	.string "Let's keep pushing on!$"

RustboroCity_Gym_EventScript_GymGuide_Text_0:
	.string "Woo! You've done it, Challenger! That's\n"
	.string "your first Gym Badge!\p"
	.string "Of course, that's no time to rest on\n"
	.string "your laurels, but I'm sure you know\l"
	.string "that well enough.\p"
	.string "Keep up the hard work!$"

RustboroCity_Gym_EventScript_GymGuide_Text_1:
	.string "Welcome, Challenger! This is your first\n"
	.string "Gym Challenge, so allow me to explain a\l"
	.string "few things.\p"
	.string "I'm Argus, though people call me the\n"
	.string "Guide! I'm the guy who'll be checking up\l"
	.string "on you as you take your Gym Challenges.\p"
	.string "If you have any questions about this\n"
	.string "place, just say the word, and I'll\l"
	.string "answer 'em all. Capisce?\p"
	.string "Now, have some Fresh Water. On the\n"
	.string "house!$"

RustboroCity_Gym_EventScript_GymGuide_Text_2:
	.string "Your first Gym Challenge will see you\n"
	.string "face off against Talia!\p"
	.string "She's a hardworking girl with an\n"
	.string "appetite for battle… and dolls!\p"
	.string "Her taste's a little eclectic to some,\n"
	.string "but she's really living her best life.\l"
	.string "Best of luck!$"

RustboroCity_Gym_Statue_Text_0:
	.string "Poppy Town Pokémon Gym$"
