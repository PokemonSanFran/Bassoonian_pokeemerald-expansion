PoppyHouse1_Man::
	msgbox PoppyHouse1_Man_Text_0, MSGBOX_NPC
	return


PoppyHouse1_Woman::
	msgbox PoppyHouse1_Woman_Text_0, MSGBOX_NPC
	return


 
DewfordTown_House1_MapScripts::
	.byte 0

DewfordTown_House1_EventScript_Man::
@	msgbox DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland, MSGBOX_NPC
@	end

DewfordTown_House1_EventScript_Woman::
@	msgbox DewfordTown_House1_Text_LifeGoesSlowlyOnIsland, MSGBOX_NPC
@	end

DewfordTown_House1_EventScript_Zigzagoon::
@	lock
@	faceplayer
@	waitse
@	playmoncry SPECIES_ZIGZAGOON, 0
@	msgbox DewfordTown_House1_Text_Zigzagoon, MSGBOX_DEFAULT
@	waitmoncry
@	release
@	end

DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland:
@	.string "There's a lot to be said for living on\n"
@	.string "a small island like this in harmony with\l"
@	.string "POKéMON and the family.$"

DewfordTown_House1_Text_LifeGoesSlowlyOnIsland:
@	.string "I left the major port of SLATEPORT\n"
@	.string "CITY when I married my husband here.\p"
@	.string "Life goes by slowly on this little\n"
@	.string "island. But being surrounded by the\l"
@	.string "beautiful sea--that's happiness, too.$"

DewfordTown_House1_Text_Zigzagoon:
@	.string "ZIGZAGOON: Guguuh!$"

PoppyHouse1_Man_Text_0:
	.string "We've sent our children to the Trainer's\n"
	.string "School.\p"
	.string "We couldn't become Trainers ourselves,\n"
	.string "but we don't want to force our kids,\l"
	.string "either.\p"
	.string "We're letting them test the waters, you\n"
	.string "could say.$"

PoppyHouse1_Woman_Text_0:
	.string "Whether my children want to become\n"
	.string "Trainers, Coordinators or something\l"
	.string "entirely different…\p"
	.string "What matters to me is that they can\n"
	.string "pursue their own happiness.\p"
	.string "Happy children make a happy mother.$"
