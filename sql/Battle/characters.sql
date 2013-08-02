﻿/*
 * Copyright (C) 2013 BattleCore <https://github.com/Vitasic/Battle>
 * Copyright (C) 2013 Vitasic <https://github.com/Vitasic>
 * Copyright (C) 2013 Vitasic <http://vk.com/vit_pokataev>
 */

set names utf8;

-- fix https://github.com/Vitasic/Battle/commit/65584a98e6b4a9fcd48664df9eaaa5295de8c031
DROP TABLE IF EXISTS `arena_logs`;
CREATE TABLE `arena_logs` (
  `team1` int(10) unsigned NOT NULL DEFAULT '0',
  `team1_members` varchar(60) CHARACTER SET latin1 NOT NULL DEFAULT '',
  `team1_rating_change` int(11) NOT NULL DEFAULT '0',
  `team2` int(10) unsigned NOT NULL DEFAULT '0',
  `team2_members` varchar(60) CHARACTER SET latin1 NOT NULL DEFAULT '',
  `team2_rating_change` int(11) NOT NULL DEFAULT '0',
  `winner` int(10) unsigned NOT NULL DEFAULT '0',
  `timestamp` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`team1`,`team2`,`timestamp`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Зарезервировал некоторые имена, присущие административному составу.
REPLACE INTO `reserved_name` (`name`) VALUES
('Разработчик'),
('Гм'),
('Gm'),
('Администратор'),
('Админ'),
('Куратор'),
('Admin'),
('Administrator'),
('Gamemaster'),
('Гейммастер'),
('Разраб'),
('Developer'),
('Модератор'),
('Moderator'),
('Moder'),
('Модер');

/* ============== characters ==============  */
-- ----------------------------
-- Table structure for `account_rate`
-- ----------------------------
DROP TABLE IF EXISTS `account_rate`;
CREATE TABLE `account_rate` (
  `id` int(10) unsigned NOT NULL,
  `rate` float unsigned NOT NULL DEFAULT '1',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for `character_rate`
-- ----------------------------
DROP TABLE IF EXISTS `character_rate`;
CREATE TABLE `character_rate` (
  `guid` int(11) NOT NULL,
  `rate` float NOT NULL DEFAULT '1',
  `insert` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`guid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
