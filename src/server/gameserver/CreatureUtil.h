////////////////////////////////////////////////////////////////////////////////
// Filename : CreatureUtil.h
// Written by : �輺��
// Description : 
// Slayer�� Vampire ������ ũ�⸦ �� �� �ִ� �� ���̱� ���ؼ� ���� ����Ǵ�
// �κ��� ������ �� ������ �����̴�.
// ���߿� PlayerCreature Ŭ������ ������, �� ������ ������ �� �ȿ��ٰ� 
// ���Խ�Ű�� ���� ���� ���̴�.
////////////////////////////////////////////////////////////////////////////////

#ifndef __CREATURE_UTIL_H__
#define __CREATURE_UTIL_H__

#include "Creature.h"
#include "Item.h"

class EffectObservingEye;
class EffectGnomesWhisper;
class Ousters;
class PlayerCreature;
class GamePlayer;

////////////////////////////////////////////////////////////////////////////////
// ���� ũ���� Ŭ�����ΰ�? 
////////////////////////////////////////////////////////////////////////////////
bool isSameRace(Creature* pCreature1, Creature* pCreature2) throw();

////////////////////////////////////////////////////////////////////////////////
// ObjectID�� ������ ã��
////////////////////////////////////////////////////////////////////////////////
Item* findItemOID(Creature* pCreature, ObjectID_t objectID) throw();
Item* findItemOID(Creature* pCreature, ObjectID_t objectID, Item::ItemClass IClass) throw();
Item* findItemOID(Creature* pCreature, ObjectID_t objectID, int& storage, int& x, int& y) throw();
Item* findItemOID(Creature* pCreature, ObjectID_t objectID, Item::ItemClass IClass, int& storage, int& x, int& y) throw();

////////////////////////////////////////////////////////////////////////////////
// ItemID�� ������ ã��
////////////////////////////////////////////////////////////////////////////////
Item* findItemIID(Creature* pCreature, ItemID_t itemID) throw();
Item* findItemIID(Creature* pCreature, ItemID_t itemID, Item::ItemClass IClass) throw();
Item* findItemIID(Creature* pCreature, ItemID_t itemID, int& storage, int& x, int& y) throw();
Item* findItemIID(Creature* pCreature, ItemID_t itemID, Item::ItemClass IClass, int& storage, int& x, int& y) throw();

////////////////////////////////////////////////////////////////////////////////
// ItemClass�� ������ �ִ��� Ȯ��
////////////////////////////////////////////////////////////////////////////////
bool hasItemWithItemClass(Creature* pCreature, Item::ItemClass ItemClass);

////////////////////////////////////////////////////////////////////////////////
// ����ġ ����ϱ�
// �����̾ � ũ���ĸ� �����ϰų�, �׿��� ��쿡 �ö󰡴� ����ġ��
// ����ϴ� �Լ�
////////////////////////////////////////////////////////////////////////////////

const int BLOODDRAIN_EXP = 70; // �������� ���� 70%
const int KILL_EXP       = 30; // �׿��� ���� 30%

int computeCreatureExp(Creature* pCreature, int percent, Ousters* pOusters = NULL) throw();
int computeBloodDrainHealPoint(Creature* pCreature, int percent) throw();

////////////////////////////////////////////////////////////////////////////////
// �̺�Ʈ�� ������ �˻��ϱ�...
////////////////////////////////////////////////////////////////////////////////
bool isEventMonster(Creature* pCreature) throw();

////////////////////////////////////////////////////////////////////////////////
// ������ ũ���İ� ���� ������ �� �ִ� �����ΰ��� �˻��ϴ� �Լ�
////////////////////////////////////////////////////////////////////////////////
bool isAbleToMove(Creature* pCreature);

////////////////////////////////////////////////////////////////////////////////
// ������ ũ���İ� ���� ����� ����� �� �ִ� �����ΰ��� �˻��ϴ� �Լ�
////////////////////////////////////////////////////////////////////////////////
bool isAbleToUseSelfSkill(Creature* pCreature, SkillType_t SkillType=0);
bool isAbleToUseObjectSkill(Creature* pCreature, SkillType_t SkillType=0);
bool isAbleToUseTileSkill(Creature* pCreature, SkillType_t SkillType=0);
bool isAbleToUseInventorySkill(Creature* pCreature, BYTE X, BYTE Y, BYTE TX, BYTE TY, SkillType_t SkillType=0);

////////////////////////////////////////////////////////////////////////////////
// ������ ũ���İ� �������� ���� �� �ִ� �����ΰ��� �˻��ϴ� �Լ�
////////////////////////////////////////////////////////////////////////////////
bool isAbleToPickupItem(Creature* pCreature, Item* pItem);
bool canDropToZone(Creature* pCreature, Item* pItem);

//void confirmGrandMaster(Creature* pCreature);

bool getRaceFromDB(const string& name, Race_t& race) throw(Error);
bool getGuildIDFromDB(const string& name, Race_t race, GuildID_t& guildID) throw(Error);

bool canSee(const Creature* pSource, Creature* pTarget, EffectObservingEye* pEffectObservingEye = NULL, EffectGnomesWhisper* pEffectGnomesWhisper = NULL);

int changeSexEx(PlayerCreature* pPC);
void initAllStatAndSendChange(PlayerCreature* pPC);

void addSimpleCreatureEffect(Creature* pCreature, Effect::EffectClass eClass, int time = -1, bool isSend = true);
void deleteCreatureEffect(Creature* pCreature, Effect::EffectClass eClass);
bool dropFlagToZone(Creature* pPC, bool bSendPacket = true);

void disableFlags(Creature *pCreature, Zone* pZone, SkillType_t SkillType);
bool canEnterBeginnerZone(Creature* pCreature);

#ifdef __UNDERWORLD__
void giveUnderworldGift(Creature* pCreature);
#endif

void disableFlags(Creature *pCreature, Zone* pZone, SkillType_t SkillType);
bool dropSweeperToZone(Creature* pPC, bool bSendPacket = true);

Level_t getPCLevel(PlayerCreature* pPC);
void sendPetInfo(GamePlayer* pGamePlayer, bool bBroadcast = false, bool bSummon = false);
void giveGoldMedal(PlayerCreature* pPC ) throw(Error);
void giveLotto(PlayerCreature* pPC, BYTE type, uint num ) throw(Error);

void addOlympicStat(PlayerCreature* pPC, BYTE type, uint num = 1 ) throw(Error);

void deletePC(PlayerCreature* pPC ) throw(Error);

bool isAffectExp2X();

#endif