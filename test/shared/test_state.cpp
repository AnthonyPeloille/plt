
#include <boost/test/unit_test.hpp>

#include "../../src/shared/state.h"

using namespace ::state;

BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
  BOOST_CHECK(1);
}

BOOST_AUTO_TEST_CASE(TestCoords)
{
    Coords c1 = Coords(10,15);
    Coords c2 = Coords(10,20);
    Coords c3 = c1;
    BOOST_CHECK_EQUAL(c1==c3,true);
    BOOST_CHECK_EQUAL(c1==c2,false);
    c2.setY(50);
    c2.setX(5);
    BOOST_CHECK_EQUAL(c2.getY(),50);
    BOOST_CHECK_EQUAL(c2.getX(),5);
}

BOOST_AUTO_TEST_CASE(TestDoor)
{
    {
        Door door {};
        BOOST_CHECK_EQUAL(door.getTypeId(), 5);
        BOOST_CHECK_EQUAL(door.isStatic(), true);
        BOOST_CHECK_EQUAL(door.getStatusDoor(), false);
        door.setStatusDoor(true);
        BOOST_CHECK_EQUAL(door.getStatusDoor(), true);
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
        BOOST_CHECK_EQUAL(wall.isStatic(), true);
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
        BOOST_CHECK_EQUAL(space.isStatic(), true);
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
        BOOST_CHECK_EQUAL(chest.isStatic(), true);
        BOOST_CHECK_EQUAL(chest.getChestContentId(), 1);
        chest.setChestContentId(PowerBoost);
        BOOST_CHECK_EQUAL(chest.getChestContentId(), 2);
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
        BOOST_CHECK_EQUAL(monster.isStatic(), false);
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
        Coords pos {10,5};
        monster.setPosition(pos);
        monster.setSpeed(50);
        BOOST_CHECK_EQUAL(monster.getPosition().getX(),10);
        BOOST_CHECK_EQUAL(monster.getPosition().getY(),5);
        BOOST_CHECK_EQUAL(monster.getSpeed(),50);
    }

}

BOOST_AUTO_TEST_CASE(TestMainCharacter)
{
    {
        MainCharacter link {};
        BOOST_CHECK_EQUAL(link.getTypeId(), 3);
        BOOST_CHECK_EQUAL(link.isStatic(), false);
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
        Coords pos {10,15};
        link.setPosition(pos);
        link.setSpeed(30);
        BOOST_CHECK_EQUAL(link.getPosition().getX(),10);
        BOOST_CHECK_EQUAL(link.getPosition().getY(),15);
        BOOST_CHECK_EQUAL(link.getSpeed(),30);
    }

    {
        MainCharacter link {};
        BOOST_CHECK_EQUAL(link.getPosition().getX(),0);
        BOOST_CHECK_EQUAL(link.getPosition().getY(),0);
        Coords pos {5,10};
        link.setPosition(pos);
        BOOST_CHECK_EQUAL(link.getPosition().getX(),5);
        BOOST_CHECK_EQUAL(link.getPosition().getY(),10);
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
