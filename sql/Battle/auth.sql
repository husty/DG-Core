/*
 * Copyright (C) 2013 BattleCore <https://github.com/Vitasic/Battle>
 * Copyright (C) 2013 Vitasic <https://github.com/Vitasic>
 * Copyright (C) 2013 Vitasic <http://vk.com/vit_pokataev>
 */

-- Отображать заселённость реалма как "Новые игроки".
UPDATE `realmlist` SET `flag` = 40;

-- Общий чат, и что то там ещё :D 
REPLACE INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES 
(1, 1), 
(1, 6), 
(1, 7), 
(1, 13), 
(1, 19), 
(1, 28), 
(1, 30), 
(1, 35), 
(1, 36);