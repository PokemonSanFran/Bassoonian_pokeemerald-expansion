EverGrandeCity_House1_UpperFloor_MapScripts::
	.byte 0


Borago_H1_BabyBoy::
	msgbox Borago_H1_BabyBoy_Text_0, MSGBOX_NPC
	return


Borago_H1_BabyGirl::
	msgbox Borago_H1_BabyGirl_Text_0, MSGBOX_NPC
	return


Borago_H1_SuperPotionGirl::
	lock
	goto_if_unset FLAG_GRC_BORAGO_SUPERPOTION, Borago_H1_SuperPotionGirl_2
Borago_H1_SuperPotionGirl_1:
	msgbox Borago_H1_SuperPotionGirl_Text_1, MSGBOX_NPC
	release
	return

Borago_H1_SuperPotionGirl_2:
	faceplayer
	msgbox Borago_H1_SuperPotionGirl_Text_0, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_POTION
	setflag FLAG_GRC_BORAGO_SUPERPOTION
	goto Borago_H1_SuperPotionGirl_1


Borago_H1_BabyBoy_Text_0:
	.string "Trainer! Trainer! Can I see your\n"
	.string "Pokémon? Please?$"

Borago_H1_BabyGirl_Text_0:
	.string "My mommy told me to be a Coordinator,\n"
	.string "but I wanna be a Trainer like my big sis!\p"
	.string "I'm gonna train the coolest Pokémon out\n"
	.string "there, just like her!$"

Borago_H1_SuperPotionGirl_Text_0:
	.string "Hey, you look like you're off to a good\n"
	.string "start. Nice going!\p"
	.string "Here's a little something that might\n"
	.string "help you.$"

Borago_H1_SuperPotionGirl_Text_1:
	.string "This one's more effective than your\n"
	.string "average Potion: it's a Super Potion!\p"
	.string "Use it wisely, since these are more\n"
	.string "pricey than ordinary Potions.\p"
	.string "Good luck out there!$"
