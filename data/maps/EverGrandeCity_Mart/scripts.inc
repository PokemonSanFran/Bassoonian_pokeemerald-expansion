EverGrandeCity_Mart_MapScripts::
	.byte 0


Borago_Mart_Employee_NPC::
	msgbox Borago_Mart_Employee_NPC_Text_0, MSGBOX_NPC
	return


Borago_Mart_MotherDaughter::
	lock
	applymovement 4, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox Borago_Mart_MotherDaughter_Text_0
	closemessage
	applymovement 3, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox Borago_Mart_MotherDaughter_Text_1
	closemessage
	release
	return


Borago_Mart_Employee_NPC_Text_0:
	.string "Welcome, welcome! We've got a nice array\n"
	.string "of products on sale! And here's\l"
	.string "another pro tip from your friendly\l"
	.string "neighborhood clerk!\p"
	.string "The more Badges you earn, the more our\n"
	.string "offers will expand to cover your\l"
	.string "ever-increasing needs. Isn't that\l"
	.string "great?$"

Borago_Mart_MotherDaughter_Text_0:
	.string "Mom! Mom! I wanna go home! Don't you\n"
	.string "have enough stuff already? Mom!$"

Borago_Mart_MotherDaughter_Text_1:
	.string "Shhh! I'm nearly done, sweetie.\p"
	.string "I just need a few more things, and then\n"
	.string "we can go back home.\p"
	.string "Now be a good child and stop yelling in\n"
	.string "the store, okay?$"
