BoragoGate_MapScripts::
	.byte 0


BoragoGate_Operator::
	msgbox BoragoGate_Operator_Text_0, MSGBOX_NPC
	return


BoragoGate_YoungLady::
	msgbox BoragoGate_YoungLady_Text_0, MSGBOX_NPC
	return


BoragoGate_Man::
	msgbox BoragoGate_Man_Text_0, MSGBOX_NPC
	return


BoragoGate_Musketeers::
	lock
	applymovement 5, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox BoragoGate_Musketeers_Text_0
	closemessage
	applymovement 4, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox BoragoGate_Musketeers_Text_1
	closemessage
	applymovement 6, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 6, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox BoragoGate_Musketeers_Text_2
	closemessage
	applymovement 4, Common_Movement_WalkInPlaceFastestUp
	applymovement 5, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	applymovement 4, Common_Movement_ExclamationMark
	applymovement 5, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 5, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox BoragoGate_Musketeers_Text_3
	closemessage
	applymovement 6, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox BoragoGate_Musketeers_Text_4
	closemessage
	applymovement 5, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox BoragoGate_Musketeers_Text_5
	closemessage
	applymovement 4, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox BoragoGate_Musketeers_Text_6
	closemessage
	applymovement 4, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	release
	return


BoragoGate_Operator_Text_0:
	.string "Are you heading into the big, bustling\n"
	.string "city? Or are you going out into the\l"
	.string "wild?\p"
	.string "Either way, with this gate, you can stop\n"
	.string "to take a break in all the peace and\l"
	.string "quiet you need.$"

BoragoGate_YoungLady_Text_0:
	.string "Bag, check… Pokémon, check… P-Drive,\n"
	.string "check…\l"
	.string "Okay! I'm good to go!$"

BoragoGate_Man_Text_0:
	.string "It's nice to take a breather after a\n"
	.string "long day. Within these gates, you can\l"
	.string "just sit down and clear your mind.\l"
	.string "Whoever invented them deserves a\l"
	.string "raise!$"

BoragoGate_Musketeers_Text_0:
	.string "Nicholas: All that talk the Professor\n"
	.string "gave about missions… Hah!\p"
	.string "Little do those three rich kids know WE\n"
	.string "are the ones with a real mission!$"

BoragoGate_Musketeers_Text_1:
	.string "Jack: Pipe it down, Nick. Don't raise\n"
	.string "suspicion.$"

BoragoGate_Musketeers_Text_2:
	.string "Robin: Case in point, boys.$"

BoragoGate_Musketeers_Text_3:
	.string "Nicholas: Khh…! It's you! Ugh, why do you\n"
	.string "have to be here?!$"

BoragoGate_Musketeers_Text_4:
	.string "Robin: Yeah, we're kinda in the middle of\n"
	.string "something, and we're not gonna move\l"
	.string "until we've finished our business here.$"

BoragoGate_Musketeers_Text_5:
	.string "Nicholas: Or, y'know, scram!$"

BoragoGate_Musketeers_Text_6:
	.string "Jack: Ugh... Make this easy on yourself\n"
	.string "and leave us be, {PLAYER}.$"
