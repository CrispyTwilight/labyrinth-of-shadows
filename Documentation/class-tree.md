<!-- Auth: John O'Neal -->
<!-- This is a class  hierarchy tree -->
GameManager(super) - John

SaveGame (super) - Will

LoadGame (super) - Will

Shop (super) - John

RNG_Dice (super) - Hunter

Map (super) - Christian

Movement (super) - Christian
- Sub enemyMvmt

MapManager (super) - Christian

Helper_Utilities (super) - All Team
- EnemyName (arr)
- PlayerName (arr)

Character (super) - Will
- Player (super/sub)
    - Ranger (sub)
    - Wizard (sub)
    - Rogue (sub)
- Enemy (super/sub)
    - EnemyEasy (sub)
    - EnemyMedium (sub)
    - EnemyBoss (sub)
- NPC (super/sub)
    - ShopOwner (sub)
    - Other (sub)

Inventory (super) - CAB

CAB:
- Loot (struct)
- Weapon (struct)
- Armor (struct)
- Potion (struct)