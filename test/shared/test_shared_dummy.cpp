
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


BOOST_AUTO_TEST_CASE(TestDoor)
{
    {
        Door door {};
        BOOST_CHECK_EQUAL(door.getTypeId(), 5);
        BOOST_CHECK_EQUAL(door.isSpace(), false);
        BOOST_CHECK_EQUAL(door.isStatic(), true);
        BOOST_CHECK_EQUAL(door.getStatusDoor(), false);
        door.setStatusDoor(true);
        BOOST_CHECK_EQUAL(door.getStatusDoor(), true);
    }

    {
        Door door {};
        BOOST_CHECK_EQUAL(door.getX(), 0);
        BOOST_CHECK_EQUAL(door.getY(), 0);
        door.setX(23);
        door.setY(32);
        BOOST_CHECK_EQUAL(door.getX(), 23);
        BOOST_CHECK_EQUAL(door.getY(), 32);
    }

    {
        Door door {};
        BOOST_CHECK_EQUAL(door.isOpened(), false);
    }

}

BOOST_AUTO_TEST_CASE(TestWall)
{
    {
        Wall wall {TOPLEFT};
        BOOST_CHECK_EQUAL(wall.getTypeId(), 1);
        BOOST_CHECK_EQUAL(wall.isSpace(), false);
        BOOST_CHECK_EQUAL(wall.isStatic(), true);
        BOOST_CHECK_EQUAL(wall.getWallTypeId(), 1);
        wall.setWallTypeId(TOPRIGHT);
        BOOST_CHECK_EQUAL(wall.getWallTypeId(), 2);
    }

    {
        Wall wall {BOTTOMLEFT};
        BOOST_CHECK_EQUAL(wall.getX(), 0);
        BOOST_CHECK_EQUAL(wall.getY(), 0);
        wall.setX(34);
        wall.setY(43);
        BOOST_CHECK_EQUAL(wall.getX(), 34);
        BOOST_CHECK_EQUAL(wall.getY(), 43);
    }

}

BOOST_AUTO_TEST_CASE(TestSpace)
{
    {
        Space space {START};
        BOOST_CHECK_EQUAL(space.getTypeId(), 2);
        BOOST_CHECK_EQUAL(space.isSpace(), true);
        BOOST_CHECK_EQUAL(space.isStatic(), true);
        BOOST_CHECK_EQUAL(space.getSpaceTypeId(), 2);
        space.setSpaceTypeId(END);
        BOOST_CHECK_EQUAL(space.getSpaceTypeId(), 3);
    }

    {
        Space space {EMPTY};
        BOOST_CHECK_EQUAL(space.getX(), 0);
        BOOST_CHECK_EQUAL(space.getY(), 0);
        space.setX(45);
        space.setY(54);
        BOOST_CHECK_EQUAL(space.getX(), 45);
        BOOST_CHECK_EQUAL(space.getY(), 54);
    }

}

BOOST_AUTO_TEST_CASE(TestChest)
{
    {
        Chest chest {HealthPoints};
        BOOST_CHECK_EQUAL(chest.getTypeId(), 6);
        BOOST_CHECK_EQUAL(chest.isSpace(), false);
        BOOST_CHECK_EQUAL(chest.isStatic(), true);
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

    {
        Chest chest {HealthPoints};
        BOOST_CHECK_EQUAL(chest.isOpened(), false);
        chest.setStatusChest(true);
        BOOST_CHECK_EQUAL(chest.getStatusChest(), true);
    }
}

BOOST_AUTO_TEST_CASE(TestMonster)
{
    {
        Monster monster {GHOST};
        BOOST_CHECK_EQUAL(monster.getTypeId(), 4);
        BOOST_CHECK_EQUAL(monster.isMC(), false);
        BOOST_CHECK_EQUAL(monster.isStatic(), false);
        BOOST_CHECK_EQUAL(monster.getStatus(), 1);
        monster.setStatus(DEAD);
        BOOST_CHECK_EQUAL(monster.getStatus(), 2);
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

    {
        Monster monster {GHOST};
        BOOST_CHECK_EQUAL(monster.getX(),0);
        BOOST_CHECK_EQUAL(monster.getY(),0);
        monster.setX(1);
        monster.setY(11);
        BOOST_CHECK_EQUAL(monster.getX(),1);
        BOOST_CHECK_EQUAL(monster.getY(),11);
    }
}

BOOST_AUTO_TEST_CASE(TestMainCharacter)
{
    {
        MainCharacter link {};
        BOOST_CHECK_EQUAL(link.getTypeId(), 3);
        BOOST_CHECK_EQUAL(link.isMC(), true);
        BOOST_CHECK_EQUAL(link.isStatic(), false);
        BOOST_CHECK_EQUAL(link.getStatus(), 1);
        link.setStatus(MC_DEAD);
        BOOST_CHECK_EQUAL(link.getStatus(), 2);
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
        MainCharacter link {};
        link.setPosition(20);
        link.setSpeed(30);
        BOOST_CHECK_EQUAL(link.getPosition(),20);
        BOOST_CHECK_EQUAL(link.getSpeed(),30);
    }

    {
        MainCharacter link {};
        BOOST_CHECK_EQUAL(link.getX(),0);
        BOOST_CHECK_EQUAL(link.getY(),0);
        link.setX(2);
        link.setY(22);
        BOOST_CHECK_EQUAL(link.getX(),2);
        BOOST_CHECK_EQUAL(link.getY(),22);
    }

}

BOOST_AUTO_TEST_CASE(TestElementTab)
{

    {
        ElementTab grid {};
        BOOST_CHECK_EQUAL(grid.getHeight(),1);
        BOOST_CHECK_EQUAL(grid.getWidth(),0);
        grid.resize(10,8);
        BOOST_CHECK_EQUAL(grid.getHeight(),8);
        BOOST_CHECK_EQUAL(grid.getWidth(),10);
    }

    {
        ElementTab grid {};
        grid.resize(10,8);
        MainCharacter link {};
        link.setAttack(120);
        link.setDefense(150);
        link.setHealthPoints(70);
        grid.set(4,4,&link);
        BOOST_CHECK_EQUAL(grid.get(4,4)->getTypeId(),link.getTypeId());
    }

}

BOOST_AUTO_TEST_CASE(TestState)
{

    {
        State state1{};
        state1.setEpoch(10);
        BOOST_CHECK_EQUAL(state1.getEpoch(), 10);
    }

    {
        State state1{};
        state1.setEpochRate(50);
        BOOST_CHECK_EQUAL(state1.getEpochRate(), 50);
    }

}
/* vim: set sw=2 sts=2 et : */
