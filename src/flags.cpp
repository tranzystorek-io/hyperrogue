// Hyperbolic Rogue - Flags

// Copyright (C) 2011-2019 Zeno Rogue, see 'hyper.cpp' for details

/** \file flags.cpp
 *  \brief Implementation of various simple flags for lands, items, monsters, and walls.
 */

#include "hyper.h"
namespace hr {

#if HDR
const inline flagtype& classflag(eItem it) { return iinf[it].flags; }
const inline flagtype& classflag(eWall w) { return winf[w].flags; }
const inline flagtype& classflag(eMonster m) { return minf[m].flags; }
const inline flagtype& classflag(eLand l) { return linf[l].flags; }

#define ANYFLAGCHECK(name, cond, field, enum) inline bool name(enum w) { flagtype flag = classflag(w); return cond; } inline bool name(cell *c) { return name(c->field); }

#define MONFLAGCHECK(name, cond) ANYFLAGCHECK(name, cond, monst, eMonster)
#define WALLFLAGCHECK(name, cond) ANYFLAGCHECK(name, cond, wall, eWall)
#define ITEMFLAGCHECK(name, cond) ANYFLAGCHECK(name, cond, item, eItem)
#define LANDFLAGCHECK(name, cond) ANYFLAGCHECK(name, cond, land, eLand)

WALLFLAGCHECK(isWatery, flag & WF_WATER)
WALLFLAGCHECK(isBoat, flag & WF_BOAT)
WALLFLAGCHECK(isChasmy, flag & WF_CHASM)
WALLFLAGCHECK(isWateryOrBoat, (flag & WF_WATER) || w == waBoat)
WALLFLAGCHECK(isNoFlight, flag & WF_NOFLIGHT)
WALLFLAGCHECK(isFire, flag & WF_FIRE)
WALLFLAGCHECK(isThumper, flag & WF_THUMPER)
WALLFLAGCHECK(isActivable, flag & WF_ACTIVABLE)
WALLFLAGCHECK(hasTimeout, flag & WF_TIMEOUT)
WALLFLAGCHECK(isOnCIsland, flag & WF_CISLAND)
WALLFLAGCHECK(cellHalfvine, flag & WF_HALFVINE)
WALLFLAGCHECK(isAlch, flag & WF_ALCHEMY)
WALLFLAGCHECK(isAlchAny, flag & WF_ALCHEMY)
WALLFLAGCHECK(realred, flag & WF_RED)
WALLFLAGCHECK(isWall, flag & WF_WALL)
WALLFLAGCHECK(isPushable, flag & WF_PUSHABLE)
WALLFLAGCHECK(conegraphtype, flag & WF_CONE)
WALLFLAGCHECK(isStandardTree, flag & WF_STDTREE)
WALLFLAGCHECK(isGrave, flag & WF_GRAVE)
WALLFLAGCHECK(isReptile, flag & WF_REPTILE)
WALLFLAGCHECK(useHeatColoring, flag & WF_HEATCOLOR)
WALLFLAGCHECK(isThorny, flag & WF_THORNY)

LANDFLAGCHECK(generateAll, flag & LF_GENERATE_ALL)
LANDFLAGCHECK(isIcyLand, flag & LF_ICY)
LANDFLAGCHECK(isGravityLand, flag & LF_GRAVITY)
LANDFLAGCHECK(isEquidLand, flag & LF_EQUI)
LANDFLAGCHECK(isWarpedType, flag & LF_WARPED)
LANDFLAGCHECK(isCyclic, flag & LF_CYCLIC)
LANDFLAGCHECK(isTechnicalLand, flag & LF_TECHNICAL)
LANDFLAGCHECK(is_mirrorland, flag & LF_MIRROR)
LANDFLAGCHECK(isSealand, flag & LF_SEA)
LANDFLAGCHECK(isCoastal, flag & LF_COASTAL)
LANDFLAGCHECK(isPureSealand, flag & LF_PURESEA)
LANDFLAGCHECK(isElemental, flag & LF_ELEMENTAL)
LANDFLAGCHECK(isHaunted, flag & LF_HAUNTED)
LANDFLAGCHECK(isTrollLand, flag & LF_TROLL)
LANDFLAGCHECK(inmirror, flag & LF_INMIRROR)
LANDFLAGCHECK(inmirrororwall, flag & LF_INMIRRORORWALL)
LANDFLAGCHECK(isElectricLand, flag & LF_ELECTRIC)

MONFLAGCHECK(isGhostable, !(flag & CF_NOGHOST))
MONFLAGCHECK(isRaider, flag & CF_RAIDER)
MONFLAGCHECK(isMimic, flag & CF_MIMIC)
MONFLAGCHECK(isPrincess, flag & CF_PRINCESS)
MONFLAGCHECK(isGolemOrKnight, flag & CF_GOK)
MONFLAGCHECK(isNonliving, flag & CF_NONLIVING)
MONFLAGCHECK(isMetalBeast, flag & CF_METAL)
MONFLAGCHECK(isStunnable, flag & CF_STUNNABLE)
MONFLAGCHECK(hasHitpoints, flag & CF_HP)
MONFLAGCHECK(isMountable, flag & CF_MOUNTABLE)
MONFLAGCHECK(isFriendlyType, flag & CF_FRIENDLY)
MONFLAGCHECK(isFriendlyOrPlayer, flag & (CF_FRIENDLY | CF_PLAYER))
MONFLAGCHECK(isBug, flag & CF_BUG)
MONFLAGCHECK(isIvy, flag & CF_IVY)
MONFLAGCHECK(isMonsterPart, flag & CF_PART)
MONFLAGCHECK(isMutantIvy, flag & CF_MUTANTIVY)
MONFLAGCHECK(isAnyIvy, flag & CF_ANYIVY)
MONFLAGCHECK(isBulletType, flag & CF_BULLET)
MONFLAGCHECK(isDemon, flag & CF_DEMON)
MONFLAGCHECK(isWorm, flag & CF_WORM)
MONFLAGCHECK(isWitch, flag & CF_WITCH)
MONFLAGCHECK(isAngryBird, (flag & CF_BIRD) && !(flag & CF_FRIENDLY))
MONFLAGCHECK(isBird, flag & CF_BIRD)
MONFLAGCHECK(slowMover, flag & CF_SLOWMOVER)
MONFLAGCHECK(isMagneticPole, flag & CF_MAGNETIC)
MONFLAGCHECK(isSwitch, flag & CF_SWITCH)
MONFLAGCHECK(isGhost, flag & CF_GHOST)
MONFLAGCHECK(isShark, flag & CF_SHARK)
MONFLAGCHECK(isSlimeMover, flag & CF_SLIME)
MONFLAGCHECK(isDragon, flag & CF_DRAGON)
MONFLAGCHECK(isKraken, flag & CF_KRAKEN)
MONFLAGCHECK(isBlowableMonster, !(flag & CF_NOBLOW))
MONFLAGCHECK(isMultitile, flag & CF_MULTITILE)
MONFLAGCHECK(isLeader, flag & CF_LEADER)
MONFLAGCHECK(isFlyingType, flag & CF_FLYING)
MONFLAGCHECK(attackThruVine, flag & CF_ATTACK_THRU_VINE)
MONFLAGCHECK(attackNonAdjacent, flag & CF_ATTACK_NONADJACENT)
MONFLAGCHECK(noHighlight, flag & CF_NOHIGHLIGHT)
MONFLAGCHECK(isInactiveEnemyType, flag & CF_INACTIVE)
MONFLAGCHECK(isUnarmed, flag & CF_UNARMED)
MONFLAGCHECK(ignoresPlatesType, flag & CF_IGNORE_PLATE)
MONFLAGCHECK(isBull, flag & CF_BULL)
MONFLAGCHECK(isTroll, flag & CF_TROLL)
MONFLAGCHECK(ignoresSmellType, flag & CF_IGNORE_SMELL)
MONFLAGCHECK(isRatling, flag & CF_RATLING)
MONFLAGCHECK(isGhostMover, flag & CF_GHOSTMOVER)
MONFLAGCHECK(isPowerMonster, flag & CF_POWER)
MONFLAGCHECK(hasFacing, flag & CF_FACING)

ITEMFLAGCHECK(isElementalShard, flag & IF_SHARD)
ITEMFLAGCHECK(itemBurns, !(flag & IF_FIREPROOF))
ITEMFLAGCHECK(isProtectionOrb, flag & IF_PROTECTION)
ITEMFLAGCHECK(isEmpathyOrb, flag & IF_EMPATHY)
ITEMFLAGCHECK(isRangedOrb, flag & IF_RANGED)
ITEMFLAGCHECK(isRevivalOrb, flag & IF_REVIVAL)
#endif

eMonster movegroup(eMonster m);

// watery

EX bool boatStrandable(cell *c) {
  return c->wall == waNone && (c->land == laLivefjord || c->land == laOcean);
  }

// monster/wall types

EX bool isFireOrMagma(cell *w) {
  return isFire(w) || w->wall == waMagma;
  }

EX int mirrorcolor(bool mirrored) {
  return winf[mirrored ? waMirror : waCloud].color;
  }

EX bool isMounted(cell *c) {
  if(c && c->monst && c->monst != moTentacleGhost && isMountable(c->monst)) {
    for(int i: player_indices()) {
      if(playerpos(i)->monst && sameMonster(c, playerpos(i))) 
        return true;
      if(lastmountpos[i] && lastmountpos[i]->monst && sameMonster(c, lastmountpos[i]))
        return true;
      }
    }
  return false;
  }

EX int itemclass(eItem it) { return iinf[it].itemclass; }

EX bool isFriendly(eMonster m) { return isFriendlyType(m); }

EX bool isFriendly(cell *c) { 
  return isMounted(c) || isFriendly(c->monst); 
  }

EX eThreatLevel get_threat_level(cell *c) { 
  if(!c->monst) return tlNoThreat;
  if(isFriendly(c)) return tlNoThreat;
  if(classflag(c->monst) & CF_HIGH_THREAT) return tlHighThreat;
  if(classflag(c->monst) & CF_SPAM) return tlSpam;
  return tlNormal;
  }

EX bool isFriendlyOrBug(cell *c) { // or killable discord!
  // do not attack the stunned Princess
  if(isPrincess(c->monst) && c->stuntime) return false;
  return isFriendly(c) || isBug(c) || (c->monst && markOrb(itOrbDiscord) && !c->stuntime);
  }

EX bool cellUnstable(cell *c) {
  return (c->land == laMotion && c->wall == waNone) || c->wall == waTrapdoor;
  }

EX bool cellUnstableOrChasm(cell *c) {
  return 
    (c->land == laMotion && c->wall == waNone) || 
    c->wall == waChasm || c->wall == waTrapdoor;
  }

EX eMonster elementalOf(eLand l) {
  if(l == laEFire) return moFireElemental;
  if(l == laEWater) return moWaterElemental;
  if(l == laEAir) return moAirElemental;
  if(l == laEEarth) return moEarthElemental;
  return moNone;
  }

EX eItem localshardof(eLand l) {
  return eItem(itFireShard + (l - laEFire));
  }

EX int snakelevel(cell *c) { 
#if CAP_COMPLEX2
  if(c->land == laBrownian && among(c->wall, waNone, waMineMine, waFire)) return min(c->landparam / brownian::level, 3);
#endif
  return winf[c->wall].snakelevel;
  }

// from-to

EX eSlimegroup slimegroup(cell *c) {
  return winf[c->wall].sg;
  }

EX bool isFlying(eMonster m) {
  return isFlyingType(m) || checkOrb(m, itOrbAether);
  }

EX bool survivesChasm(eMonster m) {
  return isFlying(m);
  }

EX bool ignoresPlates(eMonster m) {
  return ignoresPlatesType(m) || isFlying(m);
  }

EX bool isInactiveEnemy(cell *w, eMonster forwho) {
  if(forwho != moPlayer) {
    if(w->monst == moGreaterM || w->monst == moLesserM) return false;
    if(w->monst == moGreater || w->monst == moLesser) return true;
    }
  if(isInactiveEnemyType(w->monst)) return true;
  if(w->monst && ((forwho == moPlayer) ? realstuntime(w) : realstuntime(w) > 1) && !isFriendly(w))
    return true;
  return false;
  }

// forpc = true (for PC), false (for golems)
EX bool isActiveEnemy(cell *w, eMonster forwho) {
  if(((forwho == moPlayer) ? realstuntime(w) : realstuntime(w) > 1))
    return false;
  if(w->monst == passive_switch) return false;
  if(w->monst == moNone) return false;
  if(isFriendly(w)) return false;
  if(isInactiveEnemy(w, forwho)) return false;
  return true;
  }

EX bool isArmedEnemy(cell *w, eMonster forwho) {
  return w->monst != moCrystalSage && w->monst != moCrusher && isActiveEnemy(w, forwho);
  }

EX bool eternalFire(cell *c) {
  return c->land == laDryForest || (c->land == laPower && !smallbounded) || c->land == laMinefield ||
    c->land == laEFire || c->land == laElementalWall;
  }
  
EX bool haveRangedOrb() {
  return 
    items[itOrbPsi] || items[itOrbDragon] || items[itOrbTeleport] ||
    items[itOrbIllusion] || items[itOrbSpace] || items[itOrbAir] ||
    items[itOrbFrog] || items[itOrbSummon] || items[itOrbMatter] ||
    items[itRevolver] || items[itOrbStunning] || items[itStrongWind] ||
    items[itOrbDomination] || items[itOrbNature] || items[itOrbDash] ||
    items[itOrbMorph] || items[itOrbPhasing];
  }

EX bool isFriendlyGhost(eMonster m) {
  return m == moFriendlyGhost || (markEmpathy(itOrbAether) && isFriendly(m));
  }

EX bool isGhostAether(eMonster m) {
  return isGhost(m) || checkOrb(m, itOrbAether);
  }

EX bool survivesWater(eMonster m) {
  return 
    m == moShark || m == moGreaterShark || m == moCShark || 
    isGhostAether(m) || m == moWitchGhost || m == moShadow ||
    isBird(m) || m == moWaterElemental || m == moAirElemental ||
    isWorm(m) || isIvy(m) || isDragon(m) || isKraken(m) ||
    m == moMutant || m == moFriendlyIvy || 
    checkOrb(m, itOrbFish) ||
    among(m, moPike, moRusalka) ||
    m == moTortoise; // Tortoises and Ivies survive, but don't go through water
  }

// survives Mercury or Sulphur or Lava
EX bool survivesPoison(eMonster m, eWall p) {
  return
    isGhostAether(m) || m == moWitchGhost || m == moShadow ||
    isBird(m) || m == moAirElemental || isDragon(m) || isWorm(m);
  }

// flying even if stunned
EX bool isPermanentFlying(eMonster m) {
  return m == moAirElemental || isGhostAether(m);
  }

EX bool isLuckyLand(eLand l) {
  return among(l, laIce, laDesert, laDeadCaves, laOvergrown, laDice);
  }

EX bool survivesFire(eMonster m) {
  return
    isGhostAether(m) || m == moWitchWinter || m == moWitchGhost ||
    m == moBomberbird || m == moTameBomberbird || m == moTameBomberbirdMoved ||
    checkOrb(m, itOrbWinter) || m == moFireElemental ||
    isDragon(m) || m == moShadow;
  }

EX bool survivesWall(eMonster m) {
  return isGhostAether(m);
  }

EX bool survivesThorns(eMonster m) {
  return isGhostAether(m) || m == moSkeleton || m == moDraugr;
  }

EX bool survivesFall(eMonster m) {
  return isBird(m) || m == moAirElemental || m == moSkeleton || isDragon(m) || m == moShadow || isGhostAether(m);
  }

EX bool checkOrb(eMonster m1, eItem orb) {
  if(m1 == moPlayer) return markOrb(orb);
  if(isFriendly(m1)) return markEmpathy(orb);
  return false;
  }

EX bool checkOrb2(eMonster m1, eItem orb) {
  if(m1 == moPlayer) return markOrb2(orb);
  if(isFriendly(m1)) return markEmpathy2(orb);
  return false;
  }

EX bool ignoresSmell(eMonster m) {
  return ignoresSmellType(m) || checkOrb(m, itOrbBeauty) || checkOrb(m, itOrbAether) || checkOrb(m, itOrbShield);
  }

EX bool highwall(cell *c) {
  if(c->wall == waGlass) return false;
  if(wmescher && wmspatial && c->wall == waBarrier && c->land == laOceanWall)
    return false;
  // if(wmspatial && isTree(c)) return false;
  if(isGrave(c->wall)) return true;
  if(c->wall == waMirrorWall) return false;
  if(c->wall == waEditStatue) return false;
  return winf[c->wall].glyph == '#' || c->wall == waClosedGate;
  }

EX int chasmgraph(cell *c) {
  if(c->wall == waChasm || c->wall == waInvisibleFloor) return 2;
  if(isChasmy(c)) return 1;
  if(isWateryOrBoat(c)) return 1;
  if(c->wall == waShallow) return 1;
  if(wmescher && c->wall == waBarrier && c->land == laOceanWall) return 1;
  if(c->wall == waReptileBridge) return 1;
  return 0;
  }

EX bool conegraph(cell *c) {
  return ((wmescher && wmspatial) || wmascii3) && (conegraphtype(c) || (c->wall == waBarrier && c->land == laOceanWall));
  }

/** Determine the power of a frog monster. Also used to determine whether monster is a frog. */
EX eItem frog_power(eMonster m) {
  if(m == moFrog) return itOrbFrog;
  if(m == moPhaser) return itOrbPhasing;
  if(m == moVaulter) return itOrbDash;
  return itNone;
  }

EX bool hornStuns(cell *c) {
  eMonster m = c->monst;
  return 
    m == moRagingBull || m == moSleepBull || m == moHerdBull ||
    m == moButterfly || m == moGreater || m == moGreaterM || m == moDraugr ||
    m == moHedge || m == moFlailer || m == moVizier || m == moReptile || m == moSalamander || 
    m == moPair || m == moAltDemon || m == moHexDemon || m == moMonk || m == moCrusher ||
    attackJustStuns(c, AF_NORMAL, moNone);
  }

/** changing this wall for whatever reason may cause the game to crash */
EX bool do_not_touch_this_wall(cell *c) {
  return among(c->wall, waMirrorWall, waBarrier, waRoundTable, waWarpGate);
  }

EX bool is_paired(eMonster m) {
  return among(m, moPair, moNorthPole, moSouthPole);
  }

EX bool isDie(eMonster m) {
  return among(m, moAnimatedDie, moAngryDie);
  }

EX bool isDie(eWall w) {
  return among(w, waRichDie, waHappyDie);
  }

}
