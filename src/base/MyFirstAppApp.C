#include "MyFirstAppApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
MyFirstAppApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

MyFirstAppApp::MyFirstAppApp(InputParameters parameters) : MooseApp(parameters)
{
  MyFirstAppApp::registerAll(_factory, _action_factory, _syntax);
}

MyFirstAppApp::~MyFirstAppApp() {}

void
MyFirstAppApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAllObjects<MyFirstAppApp>(f, af, syntax);
  Registry::registerObjectsTo(f, {"MyFirstAppApp"});
  Registry::registerActionsTo(af, {"MyFirstAppApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
MyFirstAppApp::registerApps()
{
  registerApp(MyFirstAppApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
MyFirstAppApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  MyFirstAppApp::registerAll(f, af, s);
}
extern "C" void
MyFirstAppApp__registerApps()
{
  MyFirstAppApp::registerApps();
}
