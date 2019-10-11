
#include <boost/test/unit_test.hpp>

#include "../../src/shared/state/Exemple.h"

#include "../../src/shared/state.h"

using namespace ::state;

BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
  BOOST_CHECK(1);
}

BOOST_AUTO_TEST_CASE(TestExemple)
{
  {
    Exemple ex {};
    BOOST_CHECK_EQUAL(ex.x, 0);
    ex.setX(21);
    BOOST_CHECK_EQUAL(ex.x, 21);
  }

  {
    Exemple ex {};
    ex.setX(21);
    BOOST_CHECK_LE(ex.x, 32); // Less than equal
    BOOST_CHECK_GT(ex.x, 11); // Greater than equl
  }
}

/*
BOOST_AUTO_TEST_CASE(TestDoor)
{
    {
        Door door {};
        BOOST_CHECK_EQUAL(door.getTypeId(), 5);
        BOOST_CHECK_EQUAL(door.isSpace(), false);
    }

    {
        Door door {};
        BOOST_CHECK_EQUAL(door.getStatusDoor(), false);
        door.setStatusDoor(true);
        BOOST_CHECK_EQUAL(door.getStatusDoor(), true);
    }
}

BOOST_AUTO_TEST_CASE(TestWall)
{
    {
        Wall wall {TOPLEFT};
        BOOST_CHECK_EQUAL(wall.getTypeId(), 1);
        BOOST_CHECK_EQUAL(wall.isSpace(), false);
        BOOST_CHECK_EQUAL(wall.getWallTypeId(), 1);
        wall.setWallTypeId(TOPRIGHT);
        BOOST_CHECK_EQUAL(wall.getWallTypeId(), 2);
    }
}

BOOST_AUTO_TEST_CASE(TestSpace)
{
    {
        Space space {START};
        BOOST_CHECK_EQUAL(space.getTypeId(), 2);
        BOOST_CHECK_EQUAL(space.isSpace(), true);
        BOOST_CHECK_EQUAL(space.getSpaceTypeId(), 2);
        space.setSpaceTypeId(END);
        BOOST_CHECK_EQUAL(space.getSpaceTypeId(), 3);
    }
}

BOOST_AUTO_TEST_CASE(TestChest)
{
    {
        Chest chest {HealthPoints};
        BOOST_CHECK_EQUAL(chest.getTypeId(), 6);
        BOOST_CHECK_EQUAL(chest.isSpace(), false);
        BOOST_CHECK_EQUAL(chest.getChestContentId(), 1);
        chest.setChestContentId(PowerBoost);
        BOOST_CHECK_EQUAL(chest.getChestContentId(), 2);
    }

    {
        Chest chest {PowerBoost};
        BOOST_CHECK_EQUAL(chest.getX(), 0);
        BOOST_CHECK_EQUAL(chest.getY(), 0);
        chest.setX(45);
        chest.setY(13);
        BOOST_CHECK_EQUAL(chest.getX(), 45);
        BOOST_CHECK_EQUAL(chest.getY(), 13);
    }

    {
        Chest chest {DefenseBoost};
        chest.setX(75);
        chest.setY(23);
        BOOST_CHECK_LE(chest.getX(), 90); // Less than equal
        BOOST_CHECK_GT(chest.getY(), 11); // Greater than equal
    }
}

BOOST_AUTO_TEST_CASE(TestMonster)
{
    {
        Monster monster {GHOST};
        BOOST_CHECK_EQUAL(monster.getTypeId(), 4);
        BOOST_CHECK_EQUAL(monster.isMC(), false);
        BOOST_CHECK_EQUAL(monster.getMonsterStatus(), 1);
        monster.setStatus(DEAD);
        BOOST_CHECK_EQUAL(monster.getMonsterStatus(), 2);
        BOOST_CHECK_EQUAL(monster.getMonsterTypeId(), 1);
        monster.setMonsterTypeId(BOSS);
        BOOST_CHECK_EQUAL(monster.getMonsterTypeId(), 2);
    }

    {
        Monster monster {BOSS};
        monster.setAttack(120);
        monster.setDefense(150);
        monster.setHealthPoints(70);
        BOOST_CHECK_EQUAL(monster.getAttack(), 120);
        BOOST_CHECK_EQUAL(monster.getDefense(), 150);
        BOOST_CHECK_EQUAL(monster.getHealthPoints(), 70);
    }

    {
        Monster monster {GHOST};
        BOOST_CHECK_EQUAL(monster.getDirection(), 0);
        monster.setDirection(EAST);
        BOOST_CHECK_EQUAL(monster.getDirection(), 1);
    }

    {
        Monster monster {GHOST};
        monster.setPosition(10);
        monster.setSpeed(50);
        BOOST_CHECK_EQUAL(monster.getPosition(),10);
        BOOST_CHECK_EQUAL(monster.getSpeed(),50);
    }
}

BOOST_AUTO_TEST_CASE(TestMainCharacter)
{
    {
        MainCharacter link {};
        BOOST_CHECK_EQUAL(link.getTypeId(), 3);
        BOOST_CHECK_EQUAL(link.isMC(), true);
        BOOST_CHECK_EQUAL(link.getMCStatus(), 1);
        link.setStatus(MC_DEAD);
        BOOST_CHECK_EQUAL(link.getMCStatus(), 2);
    }

    {
        MainCharacter link {};
        link.setAttack(120);
        link.setDefense(150);
        link.setHealthPoints(70);
        BOOST_CHECK_EQUAL(link.getAttack(), 120);
        BOOST_CHECK_EQUAL(link.getDefense(), 150);
        BOOST_CHECK_EQUAL(link.getHealthPoints(), 70);
    }

    {
        MainCharacter link {};
        BOOST_CHECK_EQUAL(link.getDirection(), 0);
        link.setDirection(EAST);
        BOOST_CHECK_EQUAL(link.getDirection(), 1);
    }

    {
        Monster monster {GHOST};
        monster.setPosition(10);
        monster.setSpeed(50);
        BOOST_CHECK_EQUAL(monster.getPosition(),10);
        BOOST_CHECK_EQUAL(monster.getSpeed(),50);
    }
}
*/

/* vim: set sw=2 sts=2 et : */
