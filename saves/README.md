# Testing Process
0) Play through game, make a save
1) Run `make release` to create v1 
2) Run [`oldSaveGet`](https://github.com/PokemonSanFran/Bassoonian_pokeemerald-expansion/blob/psf_tests/saves/1_rival1/oldSaveGet) from gdb to get the saveblock as [`oldSave.txt`](https://github.com/PokemonSanFran/Bassoonian_pokeemerald-expansion/blob/psf_tests/saves/1_rival1/oldSave.txt).
3) Perform first [modification](https://github.com/PokemonSanFran/Bassoonian_pokeemerald-expansion/tree/psf_tests/saves#modifications) to saveblocks
4) Run `make release` to create v2
5) Run [`newSaveGet`](https://github.com/PokemonSanFran/Bassoonian_pokeemerald-expansion/blob/psf_tests/saves/1_rival1/newSaveGet) from gdb to get the saveblock as `newSave.txt`.
6) Compare `oldSave.txt` and `newSavetxt`, then proceed if matching as expected
7) Perform second [modification](https://github.com/PokemonSanFran/Bassoonian_pokeemerald-expansion/tree/psf_tests/saves#modifications) to saveblocks
8) Run `make release` to create v3
9) Compare `oldSave.txt` and `newSavetxt`, then proceed if matching as expected

## Modifications
There are 16 different branches to test different scenarios. 

branch name|first action|second action|save tested|status
|---|---|---|---|---|
[`add_add`](https://github.com/PokemonSanFran/Bassoonian_pokeemerald-expansion/commits/add_add/include/global.h)|Add new members to the saveblock|Add new members to the saveblock|[18_glacia](18_glacia)| ❌
[`add_increase`](https://github.com/PokemonSanFran/Bassoonian_pokeemerald-expansion/commits/add_increase/include/global.h)|Add new members to the saveblock|Change the size of a member of the saveblock|[13_tateandliza](13_tateandliza)| n/a
[`add_rearrange`](https://github.com/PokemonSanFran/Bassoonian_pokeemerald-expansion/commits/add_rearrange/include/global.h)|Add new members to the saveblock|Rearrange members of the saveblock|[19_drake](19_drake)| n/a
[`add_remove`](https://github.com/PokemonSanFran/Bassoonian_pokeemerald-expansion/commits/add_remove/include/global.h)|Add new members to the saveblock|Remove members from the saveblock|[1_rival1](1_rival1)| n/a
[`increase_add`](https://github.com/PokemonSanFran/Bassoonian_pokeemerald-expansion/commits/increase_add/include/global.h)|Change the size of a member of the saveblock|Add new members to the saveblock|[6_maxie1](6_maxie1)| n/a
[`increase_increase`](https://github.com/PokemonSanFran/Bassoonian_pokeemerald-expansion/commits/increase_increase/include/global.h)|Change the size of a member of the saveblock|Change the size of a member of the saveblock|[2_roxanne](2_roxanne)| n/a
[`increase_rearrange`](https://github.com/PokemonSanFran/Bassoonian_pokeemerald-expansion/commits/increase_rearrange/include/global.h)|Change the size of a member of the saveblock|Rearrange members of the saveblock|[14_archie](14_archie)| n/a
[`increase_remove`](https://github.com/PokemonSanFran/Bassoonian_pokeemerald-expansion/commits/increase_remove/include/global.h)|Change the size of a member of the saveblock|Remove members from the saveblock|[17_phoebe](17_phoebe)| n/a
[`rearrange_add`](https://github.com/PokemonSanFran/Bassoonian_pokeemerald-expansion/commits/rearrange_add/include/global.h)|Rearrange members of the saveblock|Add new members to the saveblock|[9_norman](9_norman)| n/a
[`rearrange_increase`](https://github.com/PokemonSanFran/Bassoonian_pokeemerald-expansion/commits/rearrange_increase/include/global.h)|Rearrange members of the saveblock|Change the size of a member of the saveblock|[15_juan](15_juan)| n/a
[`rearrange_rearrange`](https://github.com/PokemonSanFran/Bassoonian_pokeemerald-expansion/commits/rearrange_rearrange/include/global.h)|Rearrange members of the saveblock|Rearrange members of the saveblock|[3_slateport](3_slateport)| n/a
[`rearrange_remove`](https://github.com/PokemonSanFran/Bassoonian_pokeemerald-expansion/commits/rearrange_remove/include/global.h)|Rearrange members of the saveblock|Remove members from the saveblock|[10_rival3](10_rival3)| n/a
[`remove_add`](https://github.com/PokemonSanFran/Bassoonian_pokeemerald-expansion/commits/remove_add/include/global.h)|Remove members from the saveblock|Add new members to the saveblock|[11_winona](11_winona)| n/a
[`remove_increase`](https://github.com/PokemonSanFran/Bassoonian_pokeemerald-expansion/commits/remove_increase/include/global.h)|Remove members from the saveblock|Change the size of a member of the saveblock|[5_wattson](5_wattson)| n/a
[`remove_rearrange`](https://github.com/PokemonSanFran/Bassoonian_pokeemerald-expansion/commits/remove_rearrange/include/global.h)|Remove members from the saveblock|Rearrange members of the saveblock|[12_maxie2](12_maxie2)| n/a
[`remove_remove`](https://github.com/PokemonSanFran/Bassoonian_pokeemerald-expansion/commits/remove_remove/include/global.h)|Remove members from the saveblock|Remove members from the saveblock|[20_wallace](20_wallace)| n/a

## Test Status
### [`add_add`](https://github.com/PokemonSanFran/Bassoonian_pokeemerald-expansion/commits/add_add/include/global.h)

This diff [compares](https://www.diffchecker.com/nGlrzt99/) v1 saveblock and v2 saveblock. When resuming the game, things seem fine, but when directly printing the saveblock, it appears to be corrupted.

# Testing Different Saves

## Setup

From the root directory of this repo, run the following:

`chmod +x load_save.sh`

## Swapping Saves

To load a save, run the following from the root directory:

`./load_save.sh NUM_SAVE`

and then open the game. Replace `NUM_SAVE` with the save file you want to load. For example, `1` corresponds to `1_rival1`. 

# Save Descriptions

|NUM_SAVE|save directory|Description|
|---|---|---|
1 | [1_rival1](1_rival1) | Defeated Rival on Route 103 |
2 | [2_roxanne](2_roxanne) | Defeated Roxanne |
3 | [3_slateport](3_slateport) | Arrived on Route 109 via Mr. Briney  |
4 | [4_rival2](4_rival2) | Defeated Rival on Route 111 |
5 | [5_wattson](5_wattson) | Defeated Wattson |
6 | [6_maxie1](6_maxie1) | Defeated Maxie on Mt. Chimmney |
7 | [7_flannery](7_flannery) | Defeated Flannery |
8 | [8_brawly](8_brawly) | Defeated Brawly |
9 | [9_norman](9_norman) | Defeated Norman |
10 | [10_rival3](10_rival3) | Defeated Rival on Route 119 |
11 | [11_winona](11_winona) | Defeated Winona |
12 | [12_maxie2](12_maxie2) | Defeated Maxie in Magma Hideout|
13 | [13_tateandliza](13_tateandliza) | Defeated Tate and Liza |
14 | [14_archie](14_archie) | Defeated Archie on Seafloor Cavern |
15 | [15_juan](15_juan) | Defeated Juan |
16 | [16_sidney](16_sidney) | Defeated Sidney |
17 | [17_phoebe](17_phoebe) | Defeated Phoebe |
18 | [18_glacia](18_glacia) | Defeated Glacia |
19 | [19_drake](19_drake) | Defeated Drake |
20 | [20_wallace](20_wallace) | Defeated Wallace |
