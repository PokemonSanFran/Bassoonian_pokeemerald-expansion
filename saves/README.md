# Loading Saves

## Setup

From the root directory of this repo, run the following:

`chmod +x load_save.sh`

## Swapping Saves

To load a save, run the following from the root directory:

`./load_save.sh NUM_SAVE`

and then open the game. Replace `NUM_SAVE` with the save file you want to load. For example, `1` corresponds to `1_rival1`. 

# Save Descriptions

|NUM_SAVE|FOLDER_NAME|Description|
|---|---|---|
1 | 1_rival1 | Defeated Rival on Route 103 |
2 | 2_roxanne | Defeated Roxanne |
3 | 3_slateport | Arrived on Route 109 via Mr. Briney  |
4 | 4_rival2 | Defeated Rival on Route 111 |
5 | 5_wattson | Defeated Wattson |
6 | 6_maxie1 | Defeated Maxie on Mt. Chimmney |
7 | 7_flannery | Defeated Flannery |
8 | 8_brawly | Defeated Brawly |
9 | 9_norman | Defeated Norman |
10 | 10_rival3 | Defeated Rival on Route 119 |
11 | 11_winona | Defeated Winona |
12 | 12_maxie2 | Defeated Maxie in Magma Hideout|
13 | 13_tateandliza | Defeated Tate and Liza |
14 | 14_archie | Defeated Archie on Seafloor Cavern |
15 | 15_juan | Defeated Juan |
16 | 16_sidney | Defeated Sidney |
17 | 17_phoebe | Defeated Phoebe |
18 | 18_glacia | Defeated Glacia |
19 | 19_drake | Defeated Drake |
20 | 20_wallace | Defeated Wallace |

# Testing Process
1) Run make_release to create v0 of a project
2) Perform modifications to saveblocks
3) Run make_release to create v1 of a project
4) Play game to test if save data is correct
5) Perform additional modifications to saveblocks
6) Run make_release to create v2 of a project
7) Play game to test if save data is correct

## Modifications
There are 16 different branches to test different scenarios. 

branch name|first action|second action|tested 
|---|---|---|---|
`add_add`|Add new members to the saveblock|Add new members to the saveblock|6
`add_increase`|Add new members to the saveblock|Change the size of a member of the saveblock|11
`add_rearrange`|Add new members to the saveblock|Rearrange members of the saveblock|14
`add_remove`|Add new members to the saveblock|Remove members from the saveblock|19
`increase_add`|Change the size of a member of the saveblock|Add new members to the saveblock|16
`increase_increase`|Change the size of a member of the saveblock|Change the size of a member of the saveblock|7
`increase_rearrange`|Change the size of a member of the saveblock|Rearrange members of the saveblock|8
`increase_remove`|Change the size of a member of the saveblock|Remove members from the saveblock|18
`rearrange_add`|Rearrange members of the saveblock|Add new members to the saveblock|10
`rearrange_increase`|Rearrange members of the saveblock|Change the size of a member of the saveblock|12
`rearrange_rearrange`|Rearrange members of the saveblock|Rearrange members of the saveblock|3
`rearrange_remove`|Rearrange members of the saveblock|Remove members from the saveblock|15
`remove_add`|Remove members from the saveblock|Add new members to the saveblock|4
`remove_increase`|Remove members from the saveblock|Change the size of a member of the saveblock|1
`remove_rearrange`|Remove members from the saveblock|Rearrange members of the saveblock|2
`remove_remove`|Remove members from the saveblock|Remove members from the saveblock|17
