#include "constants/species.h"
#include "constants/moves.h"
	.include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata
    .align 2, 0

@ 8587C50
	.include "data/text/contest_text_pointers.inc"

	.align 2
gUnknown_08587D5C:: @ 8587D5C
	.4byte gText_0827D5C1
	.4byte gText_0827D5DC
	.4byte gText_0827D600
	.4byte gText_0827D612
	.4byte gText_0827D612
	.4byte gText_0827D62D
	.4byte gText_0827D654
	.4byte gText_0827D67E
	.4byte gText_0827D69C
	.4byte gText_0827D6BA
	.4byte gText_0827D6E5
	.4byte gText_0827D706
	.4byte gText_0827D71D

	.align 2
gUnknown_08587D90:: @ 8587D90
	.4byte gText_0827D743
	.4byte gText_0827D764
	.4byte gText_0827D785
	.4byte gText_0827D7A5
	.4byte gText_0827D7C8
	.4byte gText_0827D7E8
	.4byte gText_0827D831
	.4byte gText_0827D855
	.4byte gText_0827D830
	.4byte gText_0827D872
	.4byte gText_0827D88F
	.4byte gText_0827D8B5
	.4byte gText_0827D8E4
	.4byte gText_0827D8FE
	.4byte gText_0827D926
	.4byte gText_0827D947
	.4byte gText_0827D961
	.4byte gText_0827D986
	.4byte gText_0827D9B1
	.4byte gText_0827D9D9
	.4byte gText_0827DA03
	.4byte gText_0827DA31
	.4byte gText_0827DA5B
	.4byte gText_0827DA85
	.4byte gText_0827DAB2
	.4byte gText_0827DADA
	.4byte gText_0827DB03
	.4byte gText_0827D830
	.4byte gText_0827D830
	.4byte gText_0827D830
	.4byte gText_0827DB1F
	.4byte gText_0827DB4E

	.align 2
gUnknown_08587E10:: @ 8587E10
	.4byte gText_827DB75
	.4byte gText_827DBB0
	.4byte gText_827DBE0
	.4byte gText_827DC0F
	.4byte gText_827DC45
	.4byte gText_827DC7C
	.4byte gText_827DCB4
	.4byte gText_827DCE7
	.4byte gText_827DD12
	.4byte gText_827DD3D
	.4byte gText_827DD6F
	.4byte gText_827DD8E
	.4byte gText_827DDC7
	.4byte gText_827DDF2
	.4byte gText_827DE14
	.4byte gText_827DE44
	.4byte gText_827DE73
	.4byte gText_827DEA5
	.4byte gText_827DED9
	.4byte gText_827DF02
	.4byte gText_827DF3A
	.4byte gText_827DF63
	.4byte gText_827DF8C
	.4byte gText_827DFB8
	.4byte gText_827DFE2
	.4byte gText_827E00C
	.4byte gText_827E02F
	.4byte gText_827E05F
	.4byte gText_827E08B
	.4byte gText_827E0B5
	.4byte gText_827E0DD
	.4byte gText_827E107
	.4byte gText_827E143
	.4byte gText_827E17F
	.4byte gText_827E1BB
	.4byte gText_827E1F3
	.4byte gText_827E220
	.4byte gText_827E254
	.4byte gText_827E289
	.4byte gText_827E2C5
	.4byte gText_0827E2FE
	.4byte gText_0827E32E
	.4byte gText_0827E35B
	.4byte gText_0827E38D
	.4byte gText_0827E3C1
	.4byte gText_0827E3EB
	.4byte gText_0827E416
	.4byte gText_0827E448
	.4byte gText_0827E473
	.4byte gText_0827E4A6
	.4byte gText_0827E4D5
	.4byte gText_0827E504
	.4byte gText_0827E531
	.4byte gText_0827E55A
	.4byte gText_0827E5B2
	.4byte gText_0827E5D0
	.4byte gText_0827E606
	.4byte gText_0827E638
	.4byte gText_0827E658
	.4byte gText_0827E68B
	.4byte gText_0827E6C4
	.4byte gText_0827E7BA

	.align 2
gUnknown_08587F08:: @ 8587F08
	.4byte gText_0827E85F
	.4byte gText_0827E868
	.4byte gText_0827E86F
	.4byte gText_0827E878
	.4byte gText_0827E882

	.align 2
gUnknown_08587F1C:: @ 8587F1C
	.4byte gText_0827E894
	.4byte gText_0827E89E
	.4byte gText_0827E8AA
	.4byte gText_0827E8B4
	.4byte gText_0827E8BF
	.4byte gText_0827E8CA

	.align 2
gUnknown_08587F34:: @ 8587F34
	.4byte 0x00000580, 0x000015e9, 0x000005c2, 0x000031a3

	.align 2
gUnknown_08587F44:: @ 8587F44
	window_template 0x00, 0x12, 0x00, 0x0c, 0x02, 0x0f, 0x0200
	window_template 0x00, 0x12, 0x05, 0x0c, 0x02, 0x0f, 0x0218
	window_template 0x00, 0x12, 0x0a, 0x0c, 0x02, 0x0f, 0x0230
	window_template 0x00, 0x12, 0x0f, 0x0c, 0x02, 0x0f, 0x0248
	window_template 0x00, 0x01, 0x0f, 0x11, 0x04, 0x0f, 0x0260
	window_template 0x00, 0x01, 0x1f, 0x09, 0x02, 0x0f, 0x02a4
	window_template 0x00, 0x01, 0x21, 0x09, 0x02, 0x0f, 0x02b6
	window_template 0x00, 0x01, 0x23, 0x09, 0x02, 0x0f, 0x02c8
	window_template 0x00, 0x01, 0x25, 0x09, 0x02, 0x0f, 0x02da
	window_template 0x00, 0x10, 0x1f, 0x01, 0x02, 0x0f, 0x02ec
	window_template 0x00, 0x0b, 0x23, 0x12, 0x04, 0x0f, 0x02ee
	null_window_template

	.align 2
gUnknown_08587FA4:: @ 8587FA4
	.4byte NULL, 0xFFFF
	.2byte SPECIES_ELECTRIKE
	.byte 2
	.string "ELECTER$", 11
	.string "EZRA$", 8
	.2byte 0
	.4byte NULL, 0xFFFF
	.2byte SPECIES_TROPIUS
	.byte 0
	.string "TROPO$", 11
	.string "ALLAN$", 8
	.2byte 2
	.4byte NULL, 0xFFFF
	.2byte SPECIES_XATU
	.byte 1
	.string "TUXA$", 11
	.string "JULIET$", 8
	.2byte 0
	.4byte NULL, 0xFFFF
	.2byte SPECIES_PLUSLE
	.byte 4
	.string "PULSE$", 11
	.string "BAILY$", 8
	.2byte 3
	.4byte NULL, 0xFFFF
	.2byte SPECIES_SHUPPET
	.byte 3
	.string "SHUPUP$", 11
	.string "MELANY$", 8
	.2byte 1
	.4byte NULL, 0xFFFF
	.2byte SPECIES_ZANGOOSE
	.byte 0
	.string "GOOZAN$", 11
	.string "HANA$", 8
	.2byte 2
	.4byte NULL, 0xFFFF
	.2byte SPECIES_LOUDRED
	.byte 1
	.string "LOUDED$", 11
	.string "BRYANT$", 8
	.2byte 2
	.4byte NULL, 0xFFFF
	.2byte SPECIES_DELCATTY
	.byte 2
	.string "KITSY$", 11
	.string "OMAR$", 8
	.2byte 3
	

	.align 2
gContestOpponents:: @ 85880A4
	.include "data/contest_opponents.inc"

gUnknown_085898A4:: @ 85898A4
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02
	.byte 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02

	.align 2
gUnknown_08589904:: @ 8589904
	obj_tiles gBlankGfxCompressed, 0x1000, 0x80e8
	obj_tiles gBlankGfxCompressed, 0x1000, 0x80e9
	obj_tiles gBlankGfxCompressed, 0x1000, 0x80ea
	obj_tiles gBlankGfxCompressed, 0x1000, 0x80eb

	.align 2
gUnknown_08589924:: @ 8589924 Yup this is super dangerous but that's how it is here
	obj_pal gHeap + 0x1A0A4, 0x80e8
	obj_pal gHeap + 0x1A0C4, 0x80e9
	obj_pal gHeap + 0x1A0E4, 0x80ea
	obj_pal gHeap + 0x1A104, 0x80eb

	.align 2
gOamData_8589944:: @ 8589944
	.2byte 0x0700
	.2byte 0xC000
	.2byte 0x0000

	.align 2
gSpriteAffineAnim_858994C:: @ 858994C
	obj_rot_scal_anim_frame 0x100, 0x100, 0, 0
	obj_rot_scal_anim_end

	.align 2
gSpriteAffineAnim_858995C:: @ 858995C
	obj_rot_scal_anim_frame 0x3, 0x3, 0, 15
	obj_rot_scal_anim_frame 0xFFFD, 0xFFFD, 0, 15
	obj_rot_scal_anim_frame 0x3, 0x3, 0, 15
	obj_rot_scal_anim_frame 0xFFFD, 0xFFFD, 0, 15
	obj_rot_scal_anim_end

	.align 2
gSpriteAffineAnimTable_8589984:: @ 8589984
	.4byte gSpriteAffineAnim_858994C
	.4byte gSpriteAffineAnim_858995C

	.align 2
gSpriteTemplate_858998C:: @ 858998C
	spr_template 0x80e8, 0x80e8, gOamData_8589944, gDummySpriteAnimTable, NULL, gSpriteAffineAnimTable_8589984, SpriteCallbackDummy
	spr_template 0x80e9, 0x80e9, gOamData_8589944, gDummySpriteAnimTable, NULL, gSpriteAffineAnimTable_8589984, SpriteCallbackDummy
	spr_template 0x80ea, 0x80ea, gOamData_8589944, gDummySpriteAnimTable, NULL, gSpriteAffineAnimTable_8589984, SpriteCallbackDummy
	spr_template 0x80eb, 0x80eb, gOamData_8589944, gDummySpriteAnimTable, NULL, gSpriteAffineAnimTable_8589984, SpriteCallbackDummy

	.align 2
gContestExcitementTable:: @ 85899EC
	.2byte 0x0001, 0xffff, 0x0000, 0x0001, 0xffff, 0x00ff, 0x0001, 0xffff, 0x00ff, 0x0001, 0xff00, 0x00ff, 0x0001, 0x0000


