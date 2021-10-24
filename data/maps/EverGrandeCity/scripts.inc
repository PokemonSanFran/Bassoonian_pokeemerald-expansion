EverGrandeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Borago_Outside_OnTransition
	.byte 0


DebugTestScript::
	msgbox DebugTestScript_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, TRUE
	goto_if_eq DebugTestScript_1
	message DebugTestScript_Text_3
	waitmessage
	givemon SPECIES_PSYDUCK_HANAUAN, 50, ITEM_NONE
	givemon SPECIES_GOLDUCK_HANAUAN, 50, ITEM_NONE
	givemon SPECIES_FINNEON_HANAUAN, 50, ITEM_NONE
	givemon SPECIES_LUMINEON_HANAUAN, 50, ITEM_NONE
	givemon SPECIES_GULPIN_HANAUAN, 50, ITEM_NONE
	givemon SPECIES_SWALOT_HANAUAN, 50, ITEM_NONE
	givemon SPECIES_WHISMUR_HANAUAN, 50, ITEM_NONE
	givemon SPECIES_LOUDRED_HANAUAN, 50, ITEM_NONE
	givemon SPECIES_EXPLOUD_HANAUAN, 50, ITEM_NONE
	givemon SPECIES_CROAGUNK_HANAUAN, 50, ITEM_NONE
	givemon SPECIES_TOXICROAK_HANAUAN, 50, ITEM_NONE
	additem ITEM_MASTER_BALL
	additem ITEM_ULTRA_BALL
	additem ITEM_GREAT_BALL
	additem ITEM_POKE_BALL
	additem ITEM_NET_BALL
	additem ITEM_DIVE_BALL
	additem ITEM_NEST_BALL
	additem ITEM_REPEAT_BALL
	additem ITEM_LUXURY_BALL
	additem ITEM_TIMER_BALL
	additem ITEM_PREMIER_BALL
	additem ITEM_LEVEL_BALL
	additem ITEM_LURE_BALL
	additem ITEM_MOON_BALL
	additem ITEM_FRIEND_BALL
	additem ITEM_LOVE_BALL
	additem ITEM_HEAVY_BALL
	additem ITEM_FAST_BALL
	additem ITEM_HEAL_BALL
	additem ITEM_QUICK_BALL
	additem ITEM_DUSK_BALL
	additem ITEM_DREAM_BALL
	additem ITEM_BEAST_BALL
	additem ITEM_POTION
	additem ITEM_ANTIDOTE
	additem ITEM_BURN_HEAL
	additem ITEM_ICE_HEAL
	additem ITEM_AWAKENING
	additem ITEM_PARALYZE_HEAL
	additem ITEM_FULL_RESTORE
	additem ITEM_MAX_POTION
	additem ITEM_HYPER_POTION
	additem ITEM_SUPER_POTION
	additem ITEM_FULL_HEAL
	additem ITEM_REVIVE
	additem ITEM_MAX_REVIVE
	additem ITEM_FRESH_WATER
	additem ITEM_LEMONADE
	additem ITEM_SODA_POP
	additem ITEM_MOOMOO_MILK
	additem ITEM_ENERGY_POWDER
	additem ITEM_ENERGY_ROOT
	additem ITEM_HEAL_POWDER
	additem ITEM_REVIVAL_HERB
	additem ITEM_ETHER
	additem ITEM_MAX_ETHER
	additem ITEM_ELIXIR
	additem ITEM_MAX_ELIXIR
	additem ITEM_LAVA_COOKIE
	additem ITEM_BERRY_JUICE
	additem ITEM_SWEET_HEART
	additem ITEM_BIG_MALASADA
	additem ITEM_OLD_GATEAU
	additem ITEM_SACRED_ASH
	additem ITEM_SHOAL_SALT
	additem ITEM_SHOAL_SHELL
	additem ITEM_RED_SHARD
	additem ITEM_YELLOW_SHARD
	additem ITEM_BLUE_SHARD
	additem ITEM_GREEN_SHARD
	additem ITEM_HP_UP
	additem ITEM_CARBOS
	additem ITEM_PROTEIN
	additem ITEM_CALCIUM
	additem ITEM_ZINC
	additem ITEM_IRON
	additem ITEM_RARE_CANDY
	additem ITEM_PP_UP
	additem ITEM_PP_MAX
	additem ITEM_GUARD_SPEC
	additem ITEM_DIRE_HIT
	additem ITEM_X_ATTACK
	additem ITEM_X_DEFENSE
	additem ITEM_X_SP_ATK
	additem ITEM_X_SP_DEF
	additem ITEM_X_SPEED
	additem ITEM_X_ACCURACY
	additem ITEM_POKE_DOLL
	additem ITEM_FLUFFY_TAIL
	additem ITEM_REPEL
	additem ITEM_SUPER_REPEL
	additem ITEM_MAX_REPEL
	additem ITEM_ESCAPE_ROPE
	additem ITEM_ABILITY_CAPSULE
	additem ITEM_SUN_STONE
	additem ITEM_MOON_STONE
	additem ITEM_FIRE_STONE
	additem ITEM_THUNDER_STONE
	additem ITEM_WATER_STONE
	additem ITEM_LEAF_STONE
	additem ITEM_DAWN_STONE
	additem ITEM_DUSK_STONE
	additem ITEM_SHINY_STONE
	additem ITEM_ICE_STONE
	additem ITEM_RED_APRICORN
	additem ITEM_BLUE_APRICORN
	additem ITEM_YELLOW_APRICORN
	additem ITEM_GREEN_APRICORN
	additem ITEM_PINK_APRICORN
	additem ITEM_WHITE_APRICORN
	additem ITEM_BLACK_APRICORN
	additem ITEM_TINY_MUSHROOM
	additem ITEM_BIG_MUSHROOM
	additem ITEM_PEARL
	additem ITEM_BIG_PEARL
	additem ITEM_STARDUST
	additem ITEM_STAR_PIECE
	additem ITEM_NUGGET
	additem ITEM_HEART_SCALE
	additem ITEM_RED_NECTAR
	additem ITEM_PINK_NECTAR
	additem ITEM_PURPLE_NECTAR
	additem ITEM_YELLOW_NECTAR
	additem ITEM_RARE_BONE
	additem ITEM_CHERI_BERRY
	additem ITEM_CHESTO_BERRY
	additem ITEM_PECHA_BERRY
	additem ITEM_RAWST_BERRY
	additem ITEM_ASPEAR_BERRY
	additem ITEM_LEPPA_BERRY
	additem ITEM_ORAN_BERRY
	additem ITEM_PERSIM_BERRY
	additem ITEM_LUM_BERRY
	additem ITEM_SITRUS_BERRY
	additem ITEM_FIGY_BERRY
	additem ITEM_WIKI_BERRY
	additem ITEM_MAGO_BERRY
	additem ITEM_AGUAV_BERRY
	additem ITEM_IAPAPA_BERRY
	additem ITEM_RAZZ_BERRY
	additem ITEM_BLUK_BERRY
	additem ITEM_NANAB_BERRY
	additem ITEM_WEPEAR_BERRY
	additem ITEM_PINAP_BERRY
	additem ITEM_POMEG_BERRY
	additem ITEM_KELPSY_BERRY
	additem ITEM_QUALOT_BERRY
	additem ITEM_HONDEW_BERRY
	additem ITEM_GREPA_BERRY
	additem ITEM_TAMATO_BERRY
	additem ITEM_CORNN_BERRY
	additem ITEM_MAGOST_BERRY
	additem ITEM_RABUTA_BERRY
	additem ITEM_NOMEL_BERRY
	additem ITEM_SPELON_BERRY
	additem ITEM_PAMTRE_BERRY
	additem ITEM_WATMEL_BERRY
	additem ITEM_DURIN_BERRY
	additem ITEM_BELUE_BERRY
	additem ITEM_OCCA_BERRY
	additem ITEM_PASSHO_BERRY
	additem ITEM_WACAN_BERRY
	additem ITEM_RINDO_BERRY
	additem ITEM_YACHE_BERRY
	additem ITEM_CHOPLE_BERRY
	additem ITEM_KEBIA_BERRY
	additem ITEM_SHUCA_BERRY
	additem ITEM_COBA_BERRY
	additem ITEM_PAYAPA_BERRY
	additem ITEM_TANGA_BERRY
	additem ITEM_CHARTI_BERRY
	additem ITEM_KASIB_BERRY
	additem ITEM_HABAN_BERRY
	additem ITEM_COLBUR_BERRY
	additem ITEM_BABIRI_BERRY
	additem ITEM_CHILAN_BERRY
	additem ITEM_LIECHI_BERRY
	additem ITEM_GANLON_BERRY
	additem ITEM_SALAC_BERRY
	additem ITEM_PETAYA_BERRY
	additem ITEM_APICOT_BERRY
	additem ITEM_LANSAT_BERRY
	additem ITEM_STARF_BERRY
	additem ITEM_ENIGMA_BERRY
	additem ITEM_MICLE_BERRY
	additem ITEM_CUSTAP_BERRY
	additem ITEM_JABOCA_BERRY
	additem ITEM_ROWAP_BERRY
	additem ITEM_ROSELI_BERRY
	additem ITEM_KEE_BERRY
	additem ITEM_MARANGA_BERRY
	additem ITEM_BRIGHT_POWDER
	additem ITEM_WHITE_HERB
	additem ITEM_MACHO_BRACE
	additem ITEM_QUICK_CLAW
	additem ITEM_SOOTHE_BELL
	additem ITEM_MENTAL_HERB
	additem ITEM_CHOICE_BAND
	additem ITEM_CHOICE_SCARF
	additem ITEM_CHOICE_SPECS
	additem ITEM_KINGS_ROCK
	additem ITEM_SILVER_POWDER
	additem ITEM_AMULET_COIN
	additem ITEM_CLEANSE_TAG
	additem ITEM_SOUL_DEW
	additem ITEM_DEEP_SEA_TOOTH
	additem ITEM_DEEP_SEA_SCALE
	additem ITEM_SMOKE_BALL
	additem ITEM_EVERSTONE
	additem ITEM_FOCUS_BAND
	additem ITEM_LUCKY_EGG
	additem ITEM_SCOPE_LENS
	additem ITEM_METAL_COAT
	additem ITEM_LEFTOVERS
	additem ITEM_DRAGON_SCALE
	additem ITEM_OVAL_STONE
	additem ITEM_PROTECTOR
	additem ITEM_ELECTIRIZER
	additem ITEM_MAGMARIZER
	additem ITEM_DUBIOUS_DISC
	additem ITEM_REAPER_CLOTH
	additem ITEM_RAZOR_CLAW
	additem ITEM_RAZOR_FANG
	additem ITEM_PRISM_SCALE
	additem ITEM_WHIPPED_DREAM
	additem ITEM_SACHET
	additem ITEM_LIGHT_BALL
	additem ITEM_SOFT_SAND
	additem ITEM_HARD_STONE
	additem ITEM_MIRACLE_SEED
	additem ITEM_BLACK_GLASSES
	additem ITEM_BLACK_BELT
	additem ITEM_MAGNET
	additem ITEM_MYSTIC_WATER
	additem ITEM_SHARP_BEAK
	additem ITEM_POISON_BARB
	additem ITEM_NEVER_MELT_ICE
	additem ITEM_SPELL_TAG
	additem ITEM_TWISTED_SPOON
	additem ITEM_CHARCOAL
	additem ITEM_DRAGON_FANG
	additem ITEM_SILK_SCARF
	additem ITEM_UP_GRADE
	additem ITEM_SHELL_BELL
	additem ITEM_POWER_BRACER
	additem ITEM_POWER_BELT
	additem ITEM_POWER_LENS
	additem ITEM_POWER_BAND
	additem ITEM_POWER_ANKLET
	additem ITEM_POWER_WEIGHT
	additem ITEM_SEA_INCENSE
	additem ITEM_LAX_INCENSE
	additem ITEM_ODD_INCENSE
	additem ITEM_ROCK_INCENSE
	additem ITEM_FULL_INCENSE
	additem ITEM_WAVE_INCENSE
	additem ITEM_ROSE_INCENSE
	additem ITEM_LUCK_INCENSE
	additem ITEM_PURE_INCENSE
	additem ITEM_LUCKY_PUNCH
	additem ITEM_METAL_POWDER
	additem ITEM_THICK_CLUB
	additem ITEM_STICK
	additem ITEM_RED_SCARF
	additem ITEM_BLUE_SCARF
	additem ITEM_PINK_SCARF
	additem ITEM_GREEN_SCARF
	additem ITEM_YELLOW_SCARF
	additem ITEM_ITEMFINDER
	additem ITEM_OLD_ROD
	additem ITEM_GOOD_ROD
	additem ITEM_SUPER_ROD
	additem ITEM_PONUT_CASE
	additem ITEM_GO_GOGGLES
	additem ITEM_ROOT_FOSSIL
	additem ITEM_CLAW_FOSSIL
	additem ITEM_ARMOR_FOSSIL
	additem ITEM_SKULL_FOSSIL
	additem ITEM_HELIX_FOSSIL
	additem ITEM_DOME_FOSSIL
	additem ITEM_COVER_FOSSIL
	additem ITEM_PLUME_FOSSIL
	additem ITEM_JAW_FOSSIL
	additem ITEM_SAIL_FOSSIL
	additem ITEM_OLD_AMBER
	additem ITEM_WIDE_LENS
	additem ITEM_MUSCLE_BAND
	additem ITEM_WISE_GLASSES
	additem ITEM_EXPERT_BELT
	additem ITEM_LIGHT_CLAY
	additem ITEM_LIFE_ORB
	additem ITEM_POWER_HERB
	additem ITEM_TOXIC_ORB
	additem ITEM_FLAME_ORB
	additem ITEM_QUICK_POWDER
	additem ITEM_FOCUS_SASH
	additem ITEM_ZOOM_LENS
	additem ITEM_METRONOME
	additem ITEM_IRON_BALL
	additem ITEM_LAGGING_TAIL
	additem ITEM_DESTINY_KNOT
	additem ITEM_BLACK_SLUDGE
	additem ITEM_ICY_ROCK
	additem ITEM_SMOOTH_ROCK
	additem ITEM_HEAT_ROCK
	additem ITEM_DAMP_ROCK
	additem ITEM_GRIP_CLAW
	additem ITEM_STICKY_BARB
	additem ITEM_SHED_SHELL
	additem ITEM_BIG_ROOT
	additem ITEM_ODD_KEYSTONE
	additem ITEM_ADAMANT_ORB
	additem ITEM_LUSTROUS_ORB
	additem ITEM_GRISEOUS_ORB
	additem ITEM_GRACIDEA
	additem ITEM_BUG_MEMORY
	additem ITEM_DARK_MEMORY
	additem ITEM_DRAGON_MEMORY
	additem ITEM_ELECTRIC_MEMORY
	additem ITEM_FIRE_MEMORY
	additem ITEM_FIGHTING_MEMORY
	additem ITEM_FAIRY_MEMORY
	additem ITEM_FLYING_MEMORY
	additem ITEM_GHOST_MEMORY
	additem ITEM_GRASS_MEMORY
	additem ITEM_GROUND_MEMORY
	additem ITEM_ICE_MEMORY
	additem ITEM_POISON_MEMORY
	additem ITEM_PSYCHIC_MEMORY
	additem ITEM_ROCK_MEMORY
	additem ITEM_STEEL_MEMORY
	additem ITEM_WATER_MEMORY
	additem ITEM_FLAME_PLATE
	additem ITEM_SPLASH_PLATE
	additem ITEM_ZAP_PLATE
	additem ITEM_MEADOW_PLATE
	additem ITEM_ICICLE_PLATE
	additem ITEM_FIST_PLATE
	additem ITEM_TOXIC_PLATE
	additem ITEM_EARTH_PLATE
	additem ITEM_SKY_PLATE
	additem ITEM_MIND_PLATE
	additem ITEM_INSECT_PLATE
	additem ITEM_STONE_PLATE
	additem ITEM_SPOOKY_PLATE
	additem ITEM_DRACO_PLATE
	additem ITEM_DREAD_PLATE
	additem ITEM_IRON_PLATE
	additem ITEM_PIXIE_PLATE
	additem ITEM_EVIOLITE
	additem ITEM_FLOAT_STONE
	additem ITEM_ROCKY_HELMET
	additem ITEM_AIR_BALLOON
	additem ITEM_RED_CARD
	additem ITEM_RING_TARGET
	additem ITEM_BINDING_BAND
	additem ITEM_EJECT_BUTTON
	additem ITEM_ABSORB_BULB
	additem ITEM_CELL_BATTERY
	additem ITEM_LUMINOUS_MOSS
	additem ITEM_SNOWBALL
	additem ITEM_WEAKNESS_POLICY
	additem ITEM_DOUSE_DRIVE
	additem ITEM_SHOCK_DRIVE
	additem ITEM_BURN_DRIVE
	additem ITEM_CHILL_DRIVE
	additem ITEM_FIRE_GEM
	additem ITEM_WATER_GEM
	additem ITEM_ELECTRIC_GEM
	additem ITEM_GRASS_GEM
	additem ITEM_ICE_GEM
	additem ITEM_FIGHTING_GEM
	additem ITEM_POISON_GEM
	additem ITEM_GROUND_GEM
	additem ITEM_FLYING_GEM
	additem ITEM_PSYCHIC_GEM
	additem ITEM_BUG_GEM
	additem ITEM_ROCK_GEM
	additem ITEM_GHOST_GEM
	additem ITEM_DRAGON_GEM
	additem ITEM_DARK_GEM
	additem ITEM_STEEL_GEM
	additem ITEM_NORMAL_GEM
	additem ITEM_FAIRY_GEM
	additem ITEM_ASSAULT_VEST
	additem ITEM_SAFETY_GOGGLES
	additem ITEM_GENGARITE
	additem ITEM_GARDEVOIRITE
	additem ITEM_AMPHAROSITE
	additem ITEM_VENUSAURITE
	additem ITEM_CHARIZARDITE_X
	additem ITEM_CHARIZARDITE_Y
	additem ITEM_BLASTOISINITE
	additem ITEM_MEWTWONITE_X
	additem ITEM_MEWTWONITE_Y
	additem ITEM_BLAZIKENITE
	additem ITEM_MEDICHAMITE
	additem ITEM_HOUNDOOMINITE
	additem ITEM_AGGRONITE
	additem ITEM_BANETTITE
	additem ITEM_TYRANITARITE
	additem ITEM_SCIZORITE
	additem ITEM_PINSIRITE
	additem ITEM_AERODACTYLITE
	additem ITEM_LUCARIONITE
	additem ITEM_ABOMASITE
	additem ITEM_KANGASKHANITE
	additem ITEM_GYARADOSITE
	additem ITEM_ABSOLITE
	additem ITEM_ALAKAZITE
	additem ITEM_HERACRONITE
	additem ITEM_MAWILITE
	additem ITEM_MANECTITE
	additem ITEM_GARCHOMPITE
	additem ITEM_LATIASITE
	additem ITEM_LATIOSITE
	additem ITEM_SWAMPERTITE
	additem ITEM_SCEPTILITE
	additem ITEM_SABLENITE
	additem ITEM_ALTARIANITE
	additem ITEM_GALLADITE
	additem ITEM_AUDINITE
	additem ITEM_METAGROSSITE
	additem ITEM_SHARPEDONITE
	additem ITEM_SLOWBRONITE
	additem ITEM_STEELIXITE
	additem ITEM_PIDGEOTITE
	additem ITEM_GLALITITE
	additem ITEM_DIANCITE
	additem ITEM_CAMERUPTITE
	additem ITEM_LOPUNNITE
	additem ITEM_SALAMENCITE
	additem ITEM_BEEDRILLITE
	additem ITEM_MEGA_BRACELET
	additem ITEM_PROTECTIVE_PADS
	additem ITEM_TERRAIN_EXTENDER
	additem ITEM_ELECTRIC_SEED
	additem ITEM_GRASSY_SEED
	additem ITEM_MISTY_SEED
	additem ITEM_PSYCHIC_SEED
	additem ITEM_ADRENALINE_ORB
	additem ITEM_HONEY
	additem ITEM_HEALTH_FEATHER
	additem ITEM_MUSCLE_FEATHER
	additem ITEM_RESIST_FEATHER
	additem ITEM_GENIUS_FEATHER
	additem ITEM_CLEVER_FEATHER
	additem ITEM_SWIFT_FEATHER
	additem ITEM_PRETTY_FEATHER
	additem ITEM_SHINY_CHARM
	additem ITEM_OVAL_CHARM
	callnative Special_GiveFreePokeblocks
	msgbox DebugTestScript_Text_4
	closemessage
	special Debug_SaveBlockSize
	msgbox DebugTestScript_Text_5
	closemessage
	return

DebugTestScript_1:
	trainerbattle_single TRAINER_DEBUG, DebugTestScript_Text_1, DebugTestScript_Text_2
	return


Borago_PushAwayPlayerWithoutDrive::
	lockall
	applymovement 2, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox Borago_PushAwayPlayerWithoutDrive_Text_0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	releaseall
	return


Borago_MoveAideIfNecessary::
	compare VAR_BIRCH_LAB_STATE, 0
	goto_if_eq Borago_MoveAideIfNecessary_1
	return

Borago_MoveAideIfNecessary_1:
	setobjectxyperm 2, 18, 62
	return


Borago_POT_Keeper::
	lock
	faceplayer
	msgbox Borago_POT_Keeper_Text_0
	closemessage
	goto_if_set FLAG_BADGE03_GET, Borago_POT_Keeper_2
	msgbox Borago_POT_Keeper_Text_3
	closemessage
Borago_POT_Keeper_1:
	release
	return

Borago_POT_Keeper_2:
	msgbox Borago_POT_Keeper_Text_1
	closemessage
	msgbox Borago_POT_Keeper_Text_2
	goto Borago_POT_Keeper_1


Borago_TownSign::
	msgbox Borago_TownSign_Text_0, MSGBOX_SIGN
	return


Borago_POTSign::
	msgbox Borago_POTSign_Text_0, MSGBOX_SIGN
	return


Borago_NameRaterSign::
	msgbox Borago_NameRaterSign_Text_0, MSGBOX_SIGN
	return


Borago_ContestHallSign::
	msgbox Borago_ContestHallSign_Text_0, MSGBOX_SIGN
	return


Borago_LabSign::
	msgbox Borago_LabSign_Text_0, MSGBOX_SIGN
	return


Borago_DriveLabsSign::
	msgbox Borago_DriveLabsSign_Text_0, MSGBOX_SIGN
	return


Borago_Psychic::
	msgbox Borago_Psychic_Text_0, MSGBOX_NPC
	return


Borago_Gentleman::
	msgbox Borago_Gentleman_Text_0, MSGBOX_NPC
	return


Borago_ContestDuo::
	lock
	applymovement 13, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox Borago_ContestDuo_Text_0
	closemessage
	applymovement 14, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox Borago_ContestDuo_Text_1
	closemessage
	applymovement 13, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox Borago_ContestDuo_Text_2
	closemessage
	applymovement 14, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox Borago_ContestDuo_Text_3
	closemessage
	release
	return


FamilyEventA::
	lockall
	applymovement 5, Common_Movement_ExclamationMark
	applymovement 6, Common_Movement_ExclamationMark
	waitmovement 0
	goto FamilyEventC
	return


FamilyEventB::
	lockall
	applymovement 5, Common_Movement_ExclamationMark
	applymovement 6, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	goto FamilyEventC
	return


FamilyEventC::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement 6, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox FamilyEventC_Text_0
	closemessage
	applymovement 5, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox FamilyEventC_Text_1
	closemessage
	applymovement 6, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox FamilyEventC_Text_2
	closemessage
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 20
	playfanfare MUS_OBTAIN_ITEM
	message FamilyEventC_Text_3
	setflag FLAG_SYS_MATCH_CALL_GET
	waitfanfare
	applymovement 6, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox FamilyEventC_Text_4
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox FamilyEventC_Text_5, MSGBOX_DEFAULT
	waitfanfare
	delay 30
	applymovement 5, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox FamilyEventC_Text_6
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox FamilyEventC_Text_7, MSGBOX_DEFAULT
	waitfanfare
	delay 30
	applymovement 6, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox FamilyEventC_Text_8
	closemessage
	delay 20
	special OpenPokenavForTutorial
	waitstate
	delay 20
	applymovement 6, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox FamilyEventC_Text_9
	closemessage
	applymovement 3, FamilyEvent_RivalMove1
	applymovement 4, FamilyEvent_ToriMove1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq FamilyEventC_2
	msgbox FamilyEventC_Text_11
FamilyEventC_1:
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox FamilyEventC_Text_12, MSGBOX_DEFAULT
	waitfanfare
	delay 30
	applymovement 4, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox FamilyEventC_Text_13
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox FamilyEventC_Text_14, MSGBOX_DEFAULT
	waitfanfare
	delay 30
	closemessage
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, Family_Event_CameraMoveA
	waitmovement 0
	applymovement 8, Common_Movement_WalkLeft
	waitmovement 0
	removeobject 8
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject 7
	waitfieldeffect FLDEFF_NPCFLY_OUT
	applymovement OBJ_EVENT_ID_CAMERA, Family_Event_CameraMoveB
	waitmovement 0
	applymovement 10, Common_Movement_WalkUp
	waitmovement 0
	removeobject 10
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject 9
	waitfieldeffect FLDEFF_NPCFLY_OUT
	applymovement OBJ_EVENT_ID_CAMERA, Family_Event_CameraMoveC
	waitmovement 0
	applymovement 5, Common_Movement_WalkInPlaceFastestDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox FamilyEventC_Text_15
	closemessage
	applymovement 6, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox FamilyEventC_Text_16
	closemessage
	applymovement 5, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox FamilyEventC_Text_17
	closemessage
	applymovement 6, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox FamilyEventC_Text_18
	closemessage
	applymovement 6, Common_Movement_WalkInPlaceFastestDown
	applymovement 5, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox FamilyEventC_Text_19
	closemessage
	applymovement 5, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox FamilyEventC_Text_20
	closemessage
	applymovement 6, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox FamilyEventC_Text_21
	closemessage
	applymovement OBJ_EVENT_ID_CAMERA, Family_Event_CameraMoveD
	waitmovement 0
	applymovement 5, Common_Movement_WalkLeft
	waitmovement 0
	removeobject 5
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject 6
	waitfieldeffect FLDEFF_NPCFLY_OUT
	applymovement OBJ_EVENT_ID_CAMERA, Family_Event_CameraMoveE
	waitmovement 0
	special RemoveCameraObject
	msgbox FamilyEventC_Text_22
	closemessage
	setvar VAR_PETALBURG_WOODS_STATE, 4
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
	setflag FLAG_ENABLE_WALLY_MATCH_CALL
	setflag FLAG_GRC_HIDE_FAMILY_BORAGO
	releaseall
	return

FamilyEventC_2:
	msgbox FamilyEventC_Text_10
	goto FamilyEventC_1


Family_Event_CameraMoveA:
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end

Family_Event_CameraMoveB:
	walk_slow_left
	walk_slow_left
	walk_slow_diag_southwest
	step_end

Family_Event_CameraMoveC:
	walk_slow_diag_southeast
	walk_slow_diag_southeast
	walk_slow_diag_southeast
	step_end

Family_Event_CameraMoveD:
	walk_slow_up
	step_end

Family_Event_CameraMoveE:
	walk_slow_down
	step_end

FamilyEvent_RivalMove1:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_in_place_fastest_right
	step_end

FamilyEvent_ToriMove1:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_in_place_fastest_right
	step_end

SpotByAide1::
	call SpotByAide_PartA
	applymovement 2, SpotByAide_MoveFastLeft
	waitmovement 0
	call SpotByAide_PartB
	applymovement OBJ_EVENT_ID_PLAYER, SpotByAide_Player_MovLeft
	applymovement 2, SpotByAide_Aide_MovLeft
	call SpotByAide_PartC
	return


SpotByAide2::
	call SpotByAide_PartA
	call SpotByAide_PartB
	applymovement OBJ_EVENT_ID_PLAYER, SpotByAide_Player_MovRight
	applymovement 2, SpotByAide_Aide_MovRight
	call SpotByAide_PartC
	return


SpotByAide_PartA::
	lockall
	setvar VAR_BIRCH_LAB_STATE, 2
	applymovement 2, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	return


SpotByAide_PartB::
	applymovement 2, SpotByAideMovementA
	waitmovement 0
	msgbox SpotByAide_PartB_Text_0
	closemessage
	return


SpotByAide_PartC::
	waitmovement 0
	msgbox SpotByAide_PartC_Text_0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	opendoor 21, 69
	waitdooranim
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	applymovement 2, SpotByAide_Aide_MoveInside
	waitmovement 0
	closedoor 21, 69
	waitdooranim
	setflag FLAG_GRC_HIDE_AIDE_BORAGO
	setflag FLAG_GRC_HIDE_SIGURD_TURPIA
	warpsilent MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 0, 0, 0
	waitstate
	releaseall
	return


SpotByAide_Aide_MoveInside:
	walk_left
	walk_up
	set_invisible
	step_end

SpotByAide_MoveFastLeft:
	walk_left
	step_end

SpotByAideMovementA:
	walk_up
	walk_up
	step_end

SpotByAide_Aide_MovRight:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fast_left
	step_end

SpotByAide_Aide_MovLeft:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fast_left
	step_end

SpotByAide_Player_MovRight:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SpotByAide_Player_MovLeft:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Borago_Outside_OnTransition:
	setflag FLAG_VISITED_EVER_GRANDE_CITY
	call Common_EventScript_SetupRivalGfxId
	call Borago_MoveAideIfNecessary
	end

@EverGrandeCity_MapScripts::
@	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_OnTransition
@	.byte 0

EverGrandeCity_OnTransition:
@	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
@	end

EverGrandeCity_EventScript_VictoryRoadSign::
@	msgbox EverGrandeCity_Text_EnteringVictoryRoad, MSGBOX_SIGN
@	end

EverGrandeCity_EventScript_CitySign::
@	msgbox EverGrandeCity_Text_CitySign, MSGBOX_SIGN
@	end

EverGrandeCity_EventScript_PokemonLeagueSign::
@	msgbox EverGrandeCity_Text_EnteringPokemonLeague, MSGBOX_SIGN
@	end

EverGrandeCity_EventScript_SetVisitedEverGrande::
@	setflag FLAG_VISITED_EVER_GRANDE_CITY
@	setvar VAR_TEMP_1, 1
@	end

EverGrandeCity_Text_EnteringVictoryRoad:
@	.string "ENTERING VICTORY ROAD$"

EverGrandeCity_Text_EnteringPokemonLeague:
@	.string "ENTERING POKéMON LEAGUE\n"
@	.string "CENTER GATE$"

EverGrandeCity_Text_CitySign:
@	.string "EVER GRANDE CITY\p"
@	.string "“The paradise of flowers, the sea,\n"
@	.string "and POKéMON.”$"

DebugTestScript_Text_0:
	.string "fight shiny?$"

DebugTestScript_Text_1:
	.string "here go$"

DebugTestScript_Text_2:
	.string "nice$"

DebugTestScript_Text_3:
	.string "this may take a while...$"

DebugTestScript_Text_4:
	.string "done$"

DebugTestScript_Text_5:
	.string "SaveBlock1 is {STR_VAR_1} bytes long.\nMax size is 15872 bytes.\pSaveBlock2 is {STR_VAR_2} bytes long.\nMax size is 3968 bytes.$"

Borago_PushAwayPlayerWithoutDrive_Text_0:
	.string "Aide Wicker: Oh, {PLAYER}! You're\n"
	.string "early! Sorry, the Professor and I still\l"
	.string "have a few things to take care of.\p"
	.string "How about you pay Drive Labs a visit?\n"
	.string "It's the tall building to the\l"
	.string "southeast.\p"
	.string "They might just give you something\n"
	.string "nifty there!\p"
	.string "Okay, see you soon!$"

Borago_POT_Keeper_Text_0:
	.string "Whoa, buster! I don't think it's a good\n"
	.string "idea for you to come here just yet.\p"
	.string "Let's see, how many Badges have you\n"
	.string "earned?$"

Borago_POT_Keeper_Text_1:
	.string "Impressive stuff! Now, I'll just have to\n"
	.string "test you in person.\p"
	.string "I'm not going easy on you, so you better\n"
	.string "give this your all!$"

Borago_POT_Keeper_Text_2:
	.string "Whew! Been a while since I've last had a\n"
	.string "fight like that. About time I get back\l"
	.string "to the old schedule, too…\p"
	.string "Anyway, I'm not gonna keep you any\n"
	.string "more. Stay safe, and enjoy the road\l"
	.string "ahead, Trainer!$"

Borago_POT_Keeper_Text_3:
	.string "Nope, you're not strong enough yet.\n"
	.string "You'll need three Badges to earn the\l"
	.string "right to pass through.\p"
	.string "Just keep at it, Trainer!$"

Borago_TownSign_Text_0:
	.string "Borago City\n"
	.string "“The First and Last Destination”$"

Borago_POTSign_Text_0:
	.string "{UP_ARROW} Pass of Trials$"

Borago_NameRaterSign_Text_0:
	.string "Name Rater's House\n"
	.string "“Pokémon nicknames rated.”$"

Borago_ContestHallSign_Text_0:
	.string "Pokémon Contest Hall\n"
	.string "“The gathering place for Trainers!”$"

Borago_LabSign_Text_0:
	.string "Prof. Spruce's Pokémon Lab\n"
	.string "“The authority on conservation!”$"

Borago_DriveLabsSign_Text_0:
	.string "Drive Labs\n"
	.string "“We make your future.”$"

Borago_Psychic_Text_0:
	.string "This place really has everything a city\n"
	.string "could offer.\p"
	.string "From entertainment to daily needs,\n"
	.string "Borago just has it all. Don't you agree?$"

Borago_Gentleman_Text_0:
	.string "May I indulge you, young one?\p"
	.string "Hanau has quite a number of nice cities,\n"
	.string "and this is the most renowned of them\l"
	.string "all.\p"
	.string "However, if you truly wish to experience\n"
	.string "fine culture, then this is not the place\l"
	.string "to be.$"

Borago_ContestDuo_Text_0:
	.string "Yay, Contests! Glitz and spectacle!\n"
	.string "Ohhh, seeing the Contest Hall makes me\l"
	.string "feel all giddy inside!$"

Borago_ContestDuo_Text_1:
	.string "You've got that right! There's nothing\n"
	.string "beating the excitement and thrill of\l"
	.string "Pokémon Contests! Not to mention all\l"
	.string "those adorable Pokémon on the stage!$"

Borago_ContestDuo_Text_2:
	.string "Ohhhh… I'm growing emotional again…$"

Borago_ContestDuo_Text_3:
	.string "Oh, hubby…$"

FamilyEventC_Text_0:
	.string "Dad: Hey, {PLAYER}! Good to see you\n"
	.string "here!$"

FamilyEventC_Text_1:
	.string "Mom: A little birdie told us you've\n"
	.string "obtained your first Gym Badge.\l"
	.string "Congratulations, honey!$"

FamilyEventC_Text_2:
	.string "Dad: There's one little thing we need to\n"
	.string "do before we go back home.\p"
	.string "Mind giving me your P-Drive for a\n"
	.string "second?$"

FamilyEventC_Text_3:
	.string "{PLAYER}'s P-Drive was upgraded\nwith the TeleDrive!$"

FamilyEventC_Text_4:
	.string "Dad: With TeleDrive, you can register\n"
	.string "people you've met and call them\l"
	.string "whenever! And on that note…$"

FamilyEventC_Text_5:
	.string "Registered Dad in the P-Drive.$"

FamilyEventC_Text_6:
	.string "Mom: You'll call your dear old mom from\n"
	.string "time to time, won't you?$"

FamilyEventC_Text_7:
	.string "Registered Mom in the P-Drive.$"

FamilyEventC_Text_8:
	.string "Dad: Oh, could you make a quick test\n"
	.string "call, {PLAYER}? I'd just like to make\l"
	.string "sure everything's all functional.$"

FamilyEventC_Text_9:
	.string "Dad: Looks like it's all working just\n"
	.string "fine! Excellent!$"

FamilyEventC_Text_10:
	.string "Alyssa: Hi, {PLAYER}! You're here!\p"
	.string "You've got TeleDrive now, don't you?\n"
	.string "Then let's add each other!$"

FamilyEventC_Text_11:
	.string "Basil: Hey, {PLAYER}! There you are!\p"
	.string "Now that you have TeleDrive as well,\n"
	.string "let's register each other!$"

FamilyEventC_Text_12:
	.string "Registered {RIVAL} in the P-Drive.$"

FamilyEventC_Text_13:
	.string "Tori: Oh, hi, {PLAYER}. Can you add me\n"
	.string "to your contacts? I'll add you in\l"
	.string "return.$"

FamilyEventC_Text_14:
	.string "Registered Tori in the P-Drive.$"

FamilyEventC_Text_15:
	.string "Mom: {PLAYER}, if you're ever feeling\n"
	.string "down in the dumps or just need someone\l"
	.string "to talk to…\p"
	.string "Just call us! We'll be right there to\n"
	.string "listen.$"

FamilyEventC_Text_16:
	.string "Dad: Of course! I might be busy with my\n"
	.string "research, but I'll always be ready to\l"
	.string "talk with you.$"

FamilyEventC_Text_17:
	.string "Mom: He never wanted to miss a thing,\n"
	.string "and that hasn't changed at all! Isn't\l"
	.string "that right, darling? Hehehe…$"

FamilyEventC_Text_18:
	.string "Dad: Please, dear, not in front of our\n"
	.string "teenage child…$"

FamilyEventC_Text_19:
	.string "Dad: A-anyway, {PLAYER}! We'll be\n"
	.string "going home again.$"

FamilyEventC_Text_20:
	.string "Mom: I'm sure you'll drop by your old\n"
	.string "place as you go, so we'll see you soon,\l"
	.string "honey!$"

FamilyEventC_Text_21:
	.string "Dad: Take care and have fun,\n"
	.string "{PLAYER}!$"

FamilyEventC_Text_22:
	.string "end$"

SpotByAide_PartB_Text_0:
	.string "Aide Wicker: Hello, {PLAYER}! I see\n"
	.string "you've obtained a P-Drive.\p"
	.string "Good, good! The color goes well with you,\n"
	.string "I must say!\p"
	.string "Anyway, the Professor happens to have\n"
	.string "finished his affairs, so I thought to\l"
	.string "pick you up here. Shall we?$"

SpotByAide_PartC_Text_0:
	.string "Aide Wicker: Right this way, please.\n"
	.string "After you!$"
