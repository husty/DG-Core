/*
 * Copyright (C) 2013 BattleCore <https://github.com/Vitasic/Battle>
 * Copyright (C) 2013 Vitasic <https://github.com/Vitasic>
 * Copyright (C) 2013 Vitasic <http://vk.com/vit_pokataev>
 */

#include "ScriptPCH.h"
#include "Chat.h"
#include "../../shared/Configuration/Config.h"

/*
* Config!
###################################################################################################################
# Snacks Server :3
###################################################################################################################

Enable.Announce.On.Player.Start = 0
Enable.Mount.On.Start = 0
Enable.Fast.Mount.On.Start = 0
Enable.Cast.Spell.On.Login = 0
Enable.Cast.Spell.On.Login.In.City =0
Give.Gold.60lvl = 0
Give.Gold.80lvl = 0

###################################################################################################################
*/

class SnacksServer : public PlayerScript
{
public:
	SnacksServer() : PlayerScript("SnacksServer") {}
	void OnLogin(Player *player)
	{
		bool EnableAnnounceOnPlayerStart = ConfigMgr::GetBoolDefault("Enable.Announce.On.Player.Start", true);
		bool EnableMountOnStart = ConfigMgr::GetBoolDefault("Enable.Mount.On.Start", true);
		bool EnableFastMountOnStart = ConfigMgr::GetBoolDefault("Enable.Fast.Mount.On.Start", true);
		bool EnableCastSpellOnLogin = ConfigMgr::GetBoolDefault("Enable.Cast.Spell.On.Login", true);
		bool EnableCastSpellOnLoginInCity = ConfigMgr::GetBoolDefault("Enable.Cast.Spell.On.Login.In.City", true);

		// AnnounceOnPlayerStart 
		if (EnableAnnounceOnPlayerStart && player->getLevel() == 1)
		{
			std::string msg;
                        msg += " |cffff0000[Admin]:|r";
          		msg += "|cffFF8C00 Player|r |cffD63931";
          		msg += player->GetSession()->GetPlayerName();
          		msg += "|r |cffFF8C00joined us, and will now play on the server :3|r \n";
			sWorld->SendServerMessage(SERVER_MSG_STRING, msg.c_str());
		} // AnnounceOnPlayerStart

		// mount on start!
		if (EnableMountOnStart && player->getLevel() == 1)
                {
        		player->learnSpell(33388,0); // 1L
        		player->learnSpell(16056,0); // mount
		 }
		if (EnableFastMountOnStart && player->getLevel() == 1)
                {
        		player->learnSpell(33388,0); // 1L
        		player->learnSpell(33391,0); // 2L
        		player->learnSpell(16056,0); // mount
		 } // mount on start

		// CastSpellOnLogin
		if(EnableCastSpellOnLogin)
			player->CastSpell(player, 8358, true); // http://ru.wowhead.com/spell=8358

		if(EnableCastSpellOnLoginInCity)
		{
			switch(player->GetTeam())
                	{
				case ALLIANCE:
					if (player->GetZoneId() == 1519) // stormwind 
					{
						player->SetHealth(player->GetMaxHealth());
						player->CastSpell(player, 1126, true); // http://ru.wowhead.com/spell=1126
					}
					break;
				case HORDE:
					if (player->GetZoneId() == 1637) // orgrimmar
					{
						player->SetHealth(player->GetMaxHealth());
						player->CastSpell(player, 1126, true); // http://ru.wowhead.com/spell=1126
					}
					break;
			}
			if (player->GetZoneId() == 4395) // dalaran 
			{
				player->SetHealth(player->GetMaxHealth());
				player->CastSpell(player, 1126, true); // http://ru.wowhead.com/spell=1126
			}
			if (player->GetZoneId() == 3703) // shatrat
			{
				player->SetHealth(player->GetMaxHealth());
				player->CastSpell(player, 1126, true); // http://ru.wowhead.com/spell=1126
			}
		}
	}

	// Gold + Cast:3
	void OnLevelChanged(Player *player, uint8 newLevel)
	{
		std::string announce;
		bool GiveGold60lvl = ConfigMgr::GetBoolDefault("Give.Gold.60lvl", true);
		bool GiveGold80lvl = ConfigMgr::GetBoolDefault("Give.Gold.80lvl", true);

		if (GiveGold60lvl && player->getLevel() == 60)
                {
			player->ModifyMoney(5000000);
			player->CastSpell(player, 8358, true); // http://ru.wowhead.com/spell=8358
			player->CastSpell(player, 1126, true); // http://ru.wowhead.com/spell=1126
			announce += " |cffff0000[Admin]:|r";
          		announce = " |cffFF8C00 Player|r |cffD63931";
          		announce += player->GetSession()->GetPlayerName();
          		announce += "|r |cffFF8C00got 500 gold for level 60!|r \n";
          		sWorld->SendServerMessage(SERVER_MSG_STRING, announce.c_str());
		}
		if (GiveGold80lvl && player->getLevel() == 80)
                {
			player->ModifyMoney(10000000);
			player->CastSpell(player, 8358, true); // http://ru.wowhead.com/spell=8358
			player->CastSpell(player, 1126, true); // http://ru.wowhead.com/spell=1126
			announce += " |cffff0000[Admin]:|r";
          		announce = " |cffFF8C00 Player|r |cffD63931";
          		announce += player->GetSession()->GetPlayerName();
          		announce += "|r |cffFF8C00got 1000 gold for level 80!|r \n";
          		sWorld->SendServerMessage(SERVER_MSG_STRING, announce.c_str());
		}
	} // Gold + Cast

	void OnUpdateZone(Player* player, uint32 newZone, uint32 newArea) {}
};

void AddSC_SnacksServer()
{
    new SnacksServer();
}