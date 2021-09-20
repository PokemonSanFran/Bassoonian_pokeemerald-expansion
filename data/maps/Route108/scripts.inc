Route108_EventScript_Matthew::
	trainerbattle_single TRAINER_GRC_MIKEY, Route108_EventScript_Matthew_Text_0, Route108_EventScript_Matthew_Text_1
	msgbox Route108_EventScript_Matthew_Text_2, MSGBOX_AUTOCLOSE
	return


Route108_CantSwim::
	msgbox Route108_CantSwim_Text_0, MSGBOX_NPC
	return


 
Route108_MapScripts::
	.byte 0

Route108_EventScript_Jerome::
	trainerbattle_single TRAINER_JEROME, Route108_Text_JeromeIntro, Route108_Text_JeromeDefeated
	msgbox Route108_Text_JeromePostBattle, MSGBOX_AUTOCLOSE
	end

Route108_EventScript_Tara::
	trainerbattle_single TRAINER_TARA, Route108_Text_TaraIntro, Route108_Text_TaraDefeated
	msgbox Route108_Text_TaraPostBattle, MSGBOX_AUTOCLOSE
	end

Route108_EventScript_Missy::
	trainerbattle_single TRAINER_MISSY, Route108_Text_MissyIntro, Route108_Text_MissyDefeated
	msgbox Route108_Text_MissyPostBattle, MSGBOX_AUTOCLOSE
	end

Route108_EventScript_Carolina::
	trainerbattle_single TRAINER_CAROLINA, Route108_Text_CarolinaIntro, Route108_Text_CarolinaDefeated
	msgbox Route108_Text_CarolinaPostBattle, MSGBOX_AUTOCLOSE
	end

Route108_EventScript_Cory::
	trainerbattle_single TRAINER_CORY_1, Route108_Text_CoryIntro, Route108_Text_CoryDefeated, Route108_EventScript_CoryRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route108_EventScript_CoryRematch
	msgbox Route108_Text_CoryPostBattle, MSGBOX_DEFAULT
	release
	end

Route108_EventScript_CoryRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route108_Text_CoryRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CORY_1
	release
	end

Route108_EventScript_CoryRematch::
	trainerbattle_rematch TRAINER_CORY_1, Route108_Text_CoryRematchIntro, Route108_Text_CoryRematchDefeated
	msgbox Route108_Text_CoryRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route108_EventScript_Matthew_Text_0:
	.string "I like building sand castles. I'm gonna\n"
	.string "be the king of this beach! Go, my\l"
	.string "squires!$"

Route108_EventScript_Matthew_Text_1:
	.string "We couldn't protect the fort!$"

Route108_EventScript_Matthew_Text_2:
	.string "I read a lot of stories about knights\n"
	.string "and kings. That's where I got the idea\l"
	.string "of becoming the king of the beach.$"

Route108_CantSwim_Text_0:
	.string "I wish I could join all the Swimmers in\n"
	.string "the water. So much to see, so much to\l"
	.string "look at! But I can't swim, so I'd just\l"
	.string "look like an idiot…$"
