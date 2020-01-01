#include <boost/test/unit_test.hpp>

#include "../../src/shared/engine.h"
#include "../../src/shared/state.h"

using namespace ::engine;

BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
    BOOST_CHECK(1);
}

BOOST_AUTO_TEST_CASE(TestEngine) {
    auto* engine = new Engine();
    engine->init("../../../res/map.txt","../../../res/wall.txt");
    state::MainCharacter* mc = dynamic_cast<state::MainCharacter*>(engine->getState().getChars()[0].get());
    BOOST_CHECK_EQUAL(mc->getHealthPoints(),6);
    BOOST_CHECK_EQUAL(mc->getAttack(),1);
    BOOST_CHECK_EQUAL(mc->getDefense(),0);
    BOOST_CHECK_EQUAL(mc->getTypeId(),3);
    auto* mc_pos = new state::Coords(mc->getPosition());
    auto* pos = new state::Coords(mc_pos->getX()+10,mc_pos->getY());
    auto* move = new engine::MoveCommand(dynamic_cast<state::MainCharacter*>(engine->getState().getChars()[0].get()),pos);
    engine->addCommand(1,move);
    engine->update();
    mc = dynamic_cast<state::MainCharacter*>(engine->getState().getChars()[0].get());
    mc_pos = new state::Coords(mc->getPosition());
    BOOST_CHECK_EQUAL(*mc_pos==*pos,false);
    pos = new state::Coords(mc_pos->getX(),mc_pos->getY()+1);
    move = new engine::MoveCommand(dynamic_cast<state::MainCharacter*>(engine->getState().getChars()[0].get()),pos);
    engine->addCommand(1,move);
    engine->update();
    mc = dynamic_cast<state::MainCharacter*>(engine->getState().getChars()[0].get());
    mc_pos = new state::Coords(mc->getPosition());
    BOOST_CHECK_EQUAL(*mc_pos==*pos,true);
    pos = new state::Coords(mc_pos->getX(),mc_pos->getY()+1);
    move = new engine::MoveCommand(dynamic_cast<state::MainCharacter*>(engine->getState().getChars()[0].get()),pos);
    engine->addCommand(1,move);
    engine->update();
    mc = dynamic_cast<state::MainCharacter*>(engine->getState().getChars()[0].get());
    mc_pos = new state::Coords(mc->getPosition());
    pos = new state::Coords(mc_pos->getX(),mc_pos->getY()+1);
    move = new engine::MoveCommand(dynamic_cast<state::MainCharacter*>(engine->getState().getChars()[0].get()),pos);
    engine->addCommand(1,move);
    engine->update();
    mc = dynamic_cast<state::MainCharacter*>(engine->getState().getChars()[0].get());
    mc_pos = new state::Coords(mc->getPosition());
    pos = new state::Coords(mc_pos->getX(),mc_pos->getY()+1);
    move = new engine::MoveCommand(dynamic_cast<state::MainCharacter*>(engine->getState().getChars()[0].get()),pos);
    engine->addCommand(1,move);
    engine->update();
    mc = dynamic_cast<state::MainCharacter*>(engine->getState().getChars()[0].get());
    mc_pos = new state::Coords(mc->getPosition());
    pos = new state::Coords(mc_pos->getX()+1,mc_pos->getY());
    move = new engine::MoveCommand(dynamic_cast<state::MainCharacter*>(engine->getState().getChars()[0].get()),pos);
    engine->addCommand(1,move);
    engine->update();
    mc = dynamic_cast<state::MainCharacter*>(engine->getState().getChars()[0].get());
    mc_pos = new state::Coords(mc->getPosition());
    pos = new state::Coords(mc_pos->getX()+1,mc_pos->getY());
    move = new engine::MoveCommand(dynamic_cast<state::MainCharacter*>(engine->getState().getChars()[0].get()),pos);
    engine->addCommand(1,move);
    engine->update();
    mc = dynamic_cast<state::MainCharacter*>(engine->getState().getChars()[0].get());
    mc_pos = new state::Coords(mc->getPosition());
    //BOOST_CHECK_EQUAL(*mc_pos==*pos,false);
    auto* attack = new engine::AttackCommand(dynamic_cast<state::MainCharacter*>(engine->getState().getChars()[0].get()));
    engine->addCommand(0,attack);
    engine->update();
    state::Monster* mons = dynamic_cast<state::Monster*>(engine->getState().getMonsters()[0].get());
    //BOOST_CHECK_EQUAL(mons->getHealthPoints(),2);
    attack = new engine::AttackCommand(dynamic_cast<state::MainCharacter*>(engine->getState().getChars()[0].get()));
    engine->addCommand(0,attack);
    engine->update();
    attack = new engine::AttackCommand(dynamic_cast<state::MainCharacter*>(engine->getState().getChars()[0].get()));
    engine->addCommand(0,attack);
    engine->update();
    //monstre tué
    pos = new state::Coords(engine->getState().getChars()[0]->getPosition());
    auto* path = new engine::PathCommand(pos);
    engine->addCommand(2, path);
    engine->update();
    BOOST_CHECK_EQUAL(dynamic_cast<state::Space *>(engine->getState().getFloor().get(pos->getY()-1,pos->getX()))->getColored(),true);
}