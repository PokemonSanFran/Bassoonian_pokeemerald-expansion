PoppyPC_YoungWoman::
	msgbox PoppyPC_YoungWoman_Text_0, MSGBOX_NPC
	return


PoppyPC_OldMan::
	msgbox PoppyPC_OldMan_Text_0, MSGBOX_NPC
	return


.set LOCALID_NURSE, 1

DewfordTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_PokemonCenter_1F_OnTransition
	@ map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

DewfordTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_DEWFORD_TOWN
	@ call Common_EventScript_UpdateBrineyLocation
	end

DewfordTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

DewfordTown_PokemonCenter_1F_EventScript_PokefanF::
@	msgbox DewfordTown_PokemonCenter_1F_Text_StoneCavern, MSGBOX_NPC
@	end

DewfordTown_PokemonCenter_1F_EventScript_Man::
@	msgbox DewfordTown_PokemonCenter_1F_Text_FaintedMonCanUseHM, MSGBOX_NPC
@	end

DewfordTown_PokemonCenter_1F_Text_StoneCavern:
@	.string "There's a stone cavern at the edge\n"
@	.string "of town.\p"
@	.string "I've heard you can find rare stones\n"
@	.string "there.$"

DewfordTown_PokemonCenter_1F_Text_FaintedMonCanUseHM:
@	.string "Even if a POKéMON faints and can't\n"
@	.string "battle, it can still use a move learned\l"
@	.string "from a HIDDEN MACHINE (HM).$"

PoppyPC_YoungWoman_Text_0:
	.string "You'll need a fair number of Gym Badges\n"
	.string "if you want to head southwest. The\l"
	.string "Pokémon there are much tougher, and\l"
	.string "the climate is harsh.\p"
	.string "It does seem like a wonderful place to\n"
	.string "visit, though!$"

PoppyPC_OldMan_Text_0:
	.string "You would do well to hold on to some\n"
	.string "Poké Balls. Who knows, you may find the\l"
	.string "glimmer of fortune one day.\l"
	.string "Hohohohoho!$"
