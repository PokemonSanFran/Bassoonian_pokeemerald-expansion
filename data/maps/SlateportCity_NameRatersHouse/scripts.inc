SlateportCity_NameRatersHouse_EventScript_NameRater::
	lock
	faceplayer
	msgbox SlateportCity_NameRatersHouse_EventScript_NameRater_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SlateportCity_NameRatersHouse_EventScript_NameRater_2
	call NameRaterDecline
SlateportCity_NameRatersHouse_EventScript_NameRater_1:
	release
	return

SlateportCity_NameRatersHouse_EventScript_NameRater_2:
	msgbox SlateportCity_NameRatersHouse_EventScript_NameRater_Text_1, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_ne SlateportCity_NameRatersHouse_EventScript_NameRater_5
	call NameRaterDecline
	goto SlateportCity_NameRatersHouse_EventScript_NameRater_1

SlateportCity_NameRatersHouse_EventScript_NameRater_5:
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq SlateportCity_NameRatersHouse_EventScript_NameRater_8
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	compare VAR_RESULT, TRUE
	goto_if_eq SlateportCity_NameRatersHouse_EventScript_NameRater_11
	specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	compare VAR_RESULT, TRUE
	goto_if_eq SlateportCity_NameRatersHouse_EventScript_NameRater_14
	msgbox SlateportCity_NameRatersHouse_EventScript_NameRater_Text_3, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SlateportCity_NameRatersHouse_EventScript_NameRater_17
	call NameRaterDecline
	goto SlateportCity_NameRatersHouse_EventScript_NameRater_1

SlateportCity_NameRatersHouse_EventScript_NameRater_8:
	msgbox SlateportCity_NameRatersHouse_EventScript_NameRater_Text_2, MSGBOX_DEFAULT
	goto SlateportCity_NameRatersHouse_EventScript_NameRater_1

SlateportCity_NameRatersHouse_EventScript_NameRater_11:
	call NameRaterOutsider
	goto SlateportCity_NameRatersHouse_EventScript_NameRater_1

SlateportCity_NameRatersHouse_EventScript_NameRater_14:
	call NameRaterOutsider
	goto SlateportCity_NameRatersHouse_EventScript_NameRater_1

SlateportCity_NameRatersHouse_EventScript_NameRater_17:
	msgbox SlateportCity_NameRatersHouse_EventScript_NameRater_Text_4, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	compare VAR_RESULT, TRUE
	goto_if_eq SlateportCity_NameRatersHouse_EventScript_NameRater_20
	msgbox SlateportCity_NameRatersHouse_EventScript_NameRater_Text_6, MSGBOX_DEFAULT
	goto SlateportCity_NameRatersHouse_EventScript_NameRater_1

SlateportCity_NameRatersHouse_EventScript_NameRater_20:
	msgbox SlateportCity_NameRatersHouse_EventScript_NameRater_Text_5, MSGBOX_DEFAULT
	goto SlateportCity_NameRatersHouse_EventScript_NameRater_1


NameRaterDecline::
	msgbox NameRaterDecline_Text_0, MSGBOX_DEFAULT
	return


NameRaterOutsider::
	msgbox NameRaterOutsider_Text_0, MSGBOX_DEFAULT
	return


 
SlateportCity_NameRatersHouse_MapScripts::
	.byte 0

@SlateportCity_NameRatersHouse_EventScript_NameRater::
@	lock
@	faceplayer
@	msgbox SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
@	compare VAR_RESULT, YES
@	goto_if_eq SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate
@	compare VAR_RESULT, NO
@	goto_if_eq SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
@	end

SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate::
@	msgbox SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
@	special ChoosePartyMon
@	waitstate
@	compare VAR_0x8004, 255
@	goto_if_ne SlateportCity_NameRatersHouse_EventScript_RateMonNickname
@	compare VAR_0x8004, 255
@	goto_if_eq SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
@	end

SlateportCity_NameRatersHouse_EventScript_DeclineNameRate::
@	msgbox SlateportCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
@	release
@	end

SlateportCity_NameRatersHouse_EventScript_RateMonNickname::
@	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
@	compare VAR_RESULT, SPECIES_EGG
@	goto_if_eq SlateportCity_NameRatersHouse_EventScript_CantRateEgg
@	special BufferMonNickname
@	special IsMonOTIDNotPlayers
@	compare VAR_RESULT, TRUE
@	goto_if_eq SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
@	specialvar VAR_RESULT, MonOTNameNotPlayer
@	special BufferMonNickname
@	compare VAR_RESULT, TRUE
@	goto_if_eq SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
@	msgbox SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
@	compare VAR_RESULT, YES
@	goto_if_eq SlateportCity_NameRatersHouse_EventScript_ChangeNickname
@	compare VAR_RESULT, NO
@	goto_if_eq SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
@	end

SlateportCity_NameRatersHouse_EventScript_CantRateEgg::
@	msgbox SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
@	release
@	end

SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT::
@	msgbox SlateportCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
@	release
@	end

SlateportCity_NameRatersHouse_EventScript_ChangeNickname::
@	msgbox SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
@	call Common_EventScript_NameReceivedPartyMon
@	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
@	special BufferMonNickname
@	compare VAR_RESULT, TRUE
@	goto_if_eq SlateportCity_NameRatersHouse_EventScript_NewNameDifferent
@	msgbox SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
@	release
@	end

SlateportCity_NameRatersHouse_EventScript_NewNameDifferent::
@	msgbox SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
@	release
@	end

SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname:
@	.string "Hi, hi! I'm the Name Rater!\n"
@	.string "I'm the fortune-teller of names!\p"
@	.string "I shall be pleased to rate your\n"
@	.string "Pokémon's nickname.$"

SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname:
@	.string "Which Pokémon's nickname should\n"
@	.string "I critique?$"

SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne:
@	.string "Hmmm… {STR_VAR_1}, is it? That is\n"
@	.string "quite a fine name you bestowed.\p"
@	.string "But! What say you, if I were to\n"
@	.string "suggest a slightly better name?$"

SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe:
@	.string "Ah, good. Then, what shall the new\n"
@	.string "nickname be?$"

SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName:
@	.string "Done! From now on, this Pokémon\n"
@	.string "shall be known as {STR_VAR_1}!\p"
@	.string "It is a better name than before!\n"
@	.string "How fortunate for you!$"

SlateportCity_NameRatersHouse_Text_DoVisitAgain:
@	.string "I see.\n"
@	.string "Do come visit again.$"

SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior:
@	.string "Done! From now on, this Pokémon\n"
@	.string "shall be known as {STR_VAR_1}!\p"
@	.string "It looks no different from before,\n"
@	.string "and yet, this is vastly superior!\p"
@	.string "How fortunate for you!$"

SlateportCity_NameRatersHouse_Text_MagnificentName:
@	.string "Hmmm… {STR_VAR_1} it is!\p"
@	.string "This is a magnificent nickname!\n"
@	.string "It is impeccably beyond reproach!\p"
@	.string "You'll do well to cherish your\n"
@	.string "{STR_VAR_1} now and beyond.$"

SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg:
@	.string "Now, now.\n"
@	.string "That is merely an Egg!$"

SlateportCity_NameRatersHouse_EventScript_NameRater_Text_0:
	.string "Hello, hello! I am the official Name\n"
	.string "Rater! I can more or less tell your\l"
	.string "Pokémon's fortune by its name.\p"
	.string "Want me to rate the nicknames of your\n"
	.string "Pokémon?$"

SlateportCity_NameRatersHouse_EventScript_NameRater_Text_1:
	.string "Which Pokémon's nickname should I rate\n"
	.string "for you?$"

SlateportCity_NameRatersHouse_EventScript_NameRater_Text_2:
	.string "Now, now. That is merely an Egg! An Egg\n"
	.string "can go by no other name!$"

SlateportCity_NameRatersHouse_EventScript_NameRater_Text_3:
	.string "Hmmm. {STR_VAR_1}, is it? You picked\n"
	.string "quite a fine nickname.\p"
	.string "But I think we could give it something\n"
	.string "even better. What do you say?$"

SlateportCity_NameRatersHouse_EventScript_NameRater_Text_4:
	.string "I see! What would you like the new\n"
	.string "nickname to be?$"

SlateportCity_NameRatersHouse_EventScript_NameRater_Text_5:
	.string "Done! From now on, this Pokémon will be\n"
	.string "known as {STR_VAR_1}!\p"
	.string "You're right, that does seem to fit it\n"
	.string "better. Nicely done!$"

SlateportCity_NameRatersHouse_EventScript_NameRater_Text_6:
	.string "Done! From now on, this Pokémon will be\n"
	.string "known as {STR_VAR_1}!\p"
	.string "It looks no different from before, but\n"
	.string "we both know this name is vastly\l"
	.string "superior! How fortunate for you!$"

NameRaterDecline_Text_0:
	.string "OK! Come see me again if you change\n"
	.string "your mind.$"

NameRaterOutsider_Text_0:
	.string "Hmmm. {STR_VAR_1}! That is a truly\n"
	.string "impeccable nickname! I can't say\l"
	.string "anything bad about it!\p"
	.string "Take good care of {STR_VAR_1}!$"
