PoppyHouse2_SmallKid::
	msgbox PoppyHouse2_SmallKid_Text_0, MSGBOX_NPC
	return


PoppyHouse2_LolaTrade::
	lock
	faceplayer
	goto_if_set FLAG_RUSTBORO_NPC_TRADE_COMPLETED, PoppyHouse2_LolaTrade_2
	setvar VAR_0x8008, INGAME_TRADE_KRABBY
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox PoppyHouse2_LolaTrade_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PoppyHouse2_LolaTrade_5
	goto PoppyHouse2_LolaTrade_Decline
PoppyHouse2_LolaTrade_1:
	release
	return

PoppyHouse2_LolaTrade_2:
	msgbox PoppyHouse2_LolaTrade_Text_0, MSGBOX_DEFAULT
	goto PoppyHouse2_LolaTrade_1

PoppyHouse2_LolaTrade_5:
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, 255
	goto_if_eq PoppyHouse2_LolaTrade_9
PoppyHouse2_LolaTrade_8:
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne PoppyHouse2_LolaTrade_11
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	setflag FLAG_RUSTBORO_NPC_TRADE_COMPLETED
	msgbox PoppyHouse2_LolaTrade_Text_3, MSGBOX_DEFAULT
	goto PoppyHouse2_LolaTrade_1

PoppyHouse2_LolaTrade_9:
	goto PoppyHouse2_LolaTrade_Decline
	goto PoppyHouse2_LolaTrade_8

PoppyHouse2_LolaTrade_11:
	msgbox PoppyHouse2_LolaTrade_Text_2, MSGBOX_DEFAULT
	goto PoppyHouse2_LolaTrade_1


PoppyHouse2_LolaTrade_Decline::
	msgbox PoppyHouse2_LolaTrade_Decline_Text_0, MSGBOX_DEFAULT
	release
	return


 
DewfordTown_House2_MapScripts::
	.byte 0

DewfordTown_House2_EventScript_Man::
@	lock
@	faceplayer
@	goto_if_set FLAG_RECEIVED_SILK_SCARF, DewfordTown_House2_EventScript_ExplainSilkScarf
@	msgbox DewfordTown_House2_Text_WantYouToHaveSilkScarf, MSGBOX_DEFAULT
@	giveitem ITEM_SILK_SCARF
@	compare VAR_RESULT, FALSE
@	goto_if_eq DewfordTown_House2_EventScript_NoRoomForScarf
@	setflag FLAG_RECEIVED_SILK_SCARF
@	release
@	end

DewfordTown_House2_EventScript_NoRoomForScarf::
@	msgbox DewfordTown_House2_Text_NoRoom, MSGBOX_DEFAULT
@	release
@	end

DewfordTown_House2_EventScript_ExplainSilkScarf::
@	msgbox DewfordTown_House2_Text_ExplainSilkScarf, MSGBOX_DEFAULT
@	release
@	end

DewfordTown_House2_EventScript_Boy::
@	msgbox DewfordTown_House2_Text_BrawlySoCool, MSGBOX_NPC
@	end

DewfordTown_House2_Text_WantYouToHaveSilkScarf:
@	.string "Gorge your eyes on this!\p"
@	.string "It's a SILK SCARF. It's right at the\n"
@	.string "cutting edge of fashion, yeah!\p"
@	.string "Oh, I can see your eyes twinkling!\n"
@	.string "You appreciate my dazzling style!\p"
@	.string "Oh, you're a delight!\n"
@	.string "Here you go. I want you to have it!$"

DewfordTown_House2_Text_NoRoom:
@	.string "Oh, you don't have room?\p"
@	.string "Now, listen tight, this SCARF is a must-\n"
@	.string "have! Why, I would sell all my items\l"
@	.string "in order to get it!$"

DewfordTown_House2_Text_ExplainSilkScarf:
@	.string "The SILK SCARF raises the power of\n"
@	.string "NORMAL-type moves.\p"
@	.string "It's a marvelous SCARF that will go\n"
@	.string "with almost all POKéMON!$"

DewfordTown_House2_Text_BrawlySoCool:
@	.string "Wow, you bothered to cross the sea\n"
@	.string "to visit DEWFORD?\p"
@	.string "Did you maybe come here because you\n"
@	.string "heard about BRAWLY?\p"
@	.string "He's so cool…\n"
@	.string "Everyone idolizes him.$"

PoppyHouse2_SmallKid_Text_0:
	.string "My sister's always frolicking on the\n"
	.string "beach. She wants Pokémon to play with,\l"
	.string "so I try and catch some for her.\p"
	.string "I've been out of luck with Dwebble,\n"
	.string "though…$"

PoppyHouse2_LolaTrade_Text_0:
	.string "I'm having so much fun with Dwebble! I\n"
	.string "hope Kookie is having a good time with\l"
	.string "you, too!$"

PoppyHouse2_LolaTrade_Text_1:
	.string "Hi! Do you have a Dwebble? Wanna trade\n"
	.string "it for my Krabby?$"

PoppyHouse2_LolaTrade_Text_2:
	.string "Wait, that's not a Dwebble… Can you\n"
	.string "bring me a Dwebble next time?$"

PoppyHouse2_LolaTrade_Text_3:
	.string "Yay! Take good care of Kookie, okay?\n"
	.string "I'll treat your Dwebble super duper\l"
	.string "good!$"

PoppyHouse2_LolaTrade_Decline_Text_0:
	.string "Okay! You can always come back if\n"
	.string "you've changed your mind!$"
